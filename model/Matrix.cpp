/* SAEGE - ShAdEr Graph Editor v1.57 "BINGE" 
 * Copyright (C) 2019  Alexander Kraus <nr4@z10.info>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "Matrix.hpp"

#include <QtGlobal>
#include <QDebug>

void * Matrix::data(int row, int column)
{
    if(m_data.size() <= row || row < 0) return false;
    if(m_cols <= column || column < 0) return false;

    return m_data[row][column];
}

bool Matrix::addColumns(int ncolumns)
{
    if(ncolumns < 0) return false;
    
    m_cols += ncolumns;
    
    for(int i=0; i<m_data.size(); ++i)
    {
        for(int j=0; j<ncolumns; ++j)
        {
            m_on[i].push_back(0);
            m_data[i].push_back(0);
        }
    }
    
    return true;
}

bool Matrix::removeColumns(int ncolumns)
{
    if(ncolumns < 0) return false;
    
    m_cols -= ncolumns;
    for(int i=0; i<m_data.size(); ++i)
    {
        for(int j=0; j<ncolumns; ++j)
        {
            m_on[i].pop_back();
            m_data[i].pop_back();
        }
    }
    return true;
}

bool Matrix::addRow(QString name)
{
    m_row_names.push_back(name);
    
    QList<void *> lv;
    QList<int> li;
    for(int i=0; i<m_cols; ++i)
    {
        lv.push_back(0);
        li.push_back(0);
    }
    m_data.push_back(lv);
    m_on.push_back(li);
    
    return true;
}

bool Matrix::addRow(int index, QString name)
{
    m_row_names.insert(index, name);
    
    QList<void *> lv;
    QList<int> li;
    for(int i=0; i<m_cols; ++i)
    {
        lv.push_back(0);
        li.push_back(0);
    }
    m_data.insert(index, lv);
    m_on.insert(index, li);
    
    return true;
}

bool Matrix::removeRow(QString name)
{
    if(!m_row_names.contains(name)) return false;
    
    int index = m_row_names.indexOf(name);
    m_row_names.removeAt(index);
    m_data.removeAt(index);
    m_on.removeAt(index);
    
    return true;
}

bool Matrix::removeRow(int index)
{
    if(index >= m_row_names.size() || index < 0) return false;
    
    m_row_names.removeAt(index);
    m_data.removeAt(index);
    m_on.removeAt(index);
    
    return true;
}

Matrix::Matrix(QString name)
    : m_cols(0)
    , m_name(name)
    , m_time_step(QTime(0,0,1,0))
{
}

Matrix::~Matrix()
{
}

void Matrix::setTimeStep(QTime step)
{
    m_time_step = step;
}

bool Matrix::setData(int row, int column, void* data)
{
    if(m_data.size() <= row || row < 0) return false;
    if(m_cols <= column || column < 0) return false;
    
    m_data[row][column] = data;
    return true;
}

bool Matrix::setValue(int row, int column, int value)
{
    if(m_data.size() <= row || row < 0) return false;
    if(m_cols <= column || column < 0) return false;
    
    m_on[row][column] = value;
    return true;
}

int Matrix::value(int row, int column)
{
    if(m_data.size() <= row || row < 0) return -1;
    if(m_cols <= column || column < 0) return -1;
    
    return m_on[row][column];
}

QTime Matrix::time(int column)
{
    int step_msecs = m_time_step.msecsSinceStartOfDay();
    QTime ret(0,0,0,0);
    ret = ret.addMSecs(step_msecs * column);
    return ret;
}

QTime Matrix::timeStep()
{
    return m_time_step;
}

QString Matrix::rowName(int row)
{
    if(row < 0 || m_row_names.size() <= row) return "Error";
    return m_row_names[row];
}

bool Matrix::setRowName(int row, QString name)
{
    if(row < 0 || m_row_names.size() <= row) return false;
    m_row_names[row] = name;
    return true;
}

QString Matrix::toString()
{
    QString ret = m_name + "\n";
    for(int i=0; i<m_on.size(); ++i)
    {
        ret += m_row_names[i] + " ";
        for(int j=0; j<m_cols; ++j)
            ret += QString::number(m_on[i][j])+ " ";
        ret += "\n";
    }
    return ret;
}

void Matrix::fromString(QString str)
{
    m_row_names.clear();
    m_on.clear();
    m_cols = 0;
    
    QStringList lines = str.split('\n');
    if(lines.count() == 0) return;
    m_name = lines[0];
    for(int i=1; i<lines.count(); ++i)
    {
        QString line = lines[i];
        QStringList cols = line.split(' ');
        qDebug() << cols;
        if(cols.count() == 0) return;
        QString rowname = cols[0];
        addRow(rowname);
        addColumns(cols.count()-1);
        for(int j=1; j<cols.count(); ++j)
        {
            int value = cols[i].toInt();
            setValue(i-1,j-1,value);
        }
    }
}


void Matrix::setName(QString name)
{
    m_name = name;
}

QString Matrix::name()
{
    return m_name;
}

int Matrix::columnCount() const
{
    return m_cols;
}

int Matrix::rowCount() const
{
    return m_row_names.size();
}



