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

#include "MatrixModel.hpp"

MatrixModel::MatrixModel(Matrix* m, QObject* parent)
    : QAbstractTableModel(parent)
    , m_matrix(m)
{
}

MatrixModel::~MatrixModel()
{
}

int MatrixModel::rowCount(const QModelIndex& parent) const
{
    return m_matrix->rowCount();
}

int MatrixModel::columnCount(const QModelIndex& parent) const
{
    return m_matrix->columnCount();
}

QVariant MatrixModel::data(const QModelIndex& index, int role) const
{
    if(role == Qt::DisplayRole)
        return QVariant(m_matrix->value(index.row(), index.column()));
    return QVariant();
}

QVariant MatrixModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole)
    {
        if(orientation == Qt::Horizontal)
            return QVariant(m_matrix->time(section).toString("mm:ss.zzz"));
        else if(orientation == Qt::Vertical)
            return QVariant(m_matrix->rowName(section));
    }
    return QVariant();
}

Qt::ItemFlags MatrixModel::flags(const QModelIndex& index) const
{
    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}

bool MatrixModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(role == Qt::EditRole)
    {
        bool success = m_matrix->setValue(index.row(), index.column(), value.toInt());
        if(success)
            emit dataChanged(index,index);
        return success;
    }
    return false;
}

bool MatrixModel::insertRows(int row, int count, const QModelIndex& parent)
{
    beginInsertRows(parent, row, row+count);
    bool success = m_matrix->addRow("unnamed");
    endInsertRows();
    return success;
}

bool MatrixModel::insertColumns(int column, int count, const QModelIndex& parent)
{
    beginInsertColumns(parent, column, column+count);
    bool success = m_matrix->addColumns(count);
    endInsertColumns();
    return success;
}