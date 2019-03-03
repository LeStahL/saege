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

#ifndef MATRIX_H
#define MATRIX_H

#include <QString>
#include <QList>
#include <QVariant>
#include <QTime>

class Matrix 
{
public:
    Matrix(QString name);
    virtual ~Matrix();
    
    //TODO: add toxml, fromxml for serialization
//     QString toXml();
//     void fromXml(QString source);
    
    QString toString();
    
    bool addRow(QString name);
    bool addRow(int index, QString name);
    bool removeRow(QString name);
    bool removeRow(int index);
    
    bool addColumns(int ncolumns);
    bool removeColumns(int ncolumns);
    
    QString rowName(int row);
    void *data(int row, int column);
    int value(int row, int column);
    bool setData(int row, int column, void *data);
    bool setValue(int row, int column, int value);
    QTime time(int column);
    QTime timeStep();
    void setTimeStep(QTime step);
    
    QString name();
    void setName(QString name);
    
    int columnCount() const;
    int rowCount() const;
    
private:
    QTime m_time_step;
    QList<QString> m_row_names;
    QList<QList<int> > m_on;
    QList<QList<void *> > m_data;
    QString m_name;
    int m_cols;
};

#endif
