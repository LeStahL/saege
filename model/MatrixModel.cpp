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
#include "ColorProvider.hpp"
#include "MatrixValueChangeCommand.hpp"
#include "MatrixAddRowCommand.hpp"

#include <QFont>

MatrixModel::MatrixModel(Matrix* m, QObject* parent)
    : QAbstractTableModel(parent)
    , m_matrix(m)
{
    updateColorScheme();
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
    else if(role == Qt::BackgroundColorRole)
    {
        if(m_matrix->value(index.row(), index.column())!=0)
        {
            if(index.row() % 2 == 0)
                return QVariant(m_foreground_scheme[8]);
            else
                return QVariant(m_foreground_scheme[9]);
        }
        else 
        {
            if(index.row() % 2 == 0)
                return QVariant(m_color_scheme[2]);
            else
                return QVariant(m_color_scheme[3]);
        }
    }
    else if(role == Qt::TextColorRole)
    {
        if(m_matrix->value(index.row(), index.column())!=0)
        {
            return QVariant(m_foreground_scheme[1]);
        }
        else
            return QVariant(m_color_scheme[9]);
    }
    else if(role == Qt::FontRole)
    {
        QFont font;
        font.setBold(true);
        font.setPointSize(14.);
        return QVariant(font);
    }
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
        m_undo_stack.push(new MatrixValueChangeCommand(index, value, this));
        return true;
    }
    return false;
}

bool MatrixModel::insertRows(int row, int count, const QModelIndex& parent)
{
    if(row != m_matrix->rowCount()) return false;
    if(count != 1) return false;
    m_undo_stack.push(new MatrixAddRowCommand(this));
    return true;
}

bool MatrixModel::insertColumns(int column, int count, const QModelIndex& parent)
{
    beginInsertColumns(parent, column, column+count);
    bool success = m_matrix->addColumns(count);
    endInsertColumns();
    return success;
}

bool MatrixModel::removeRows(int row, int count, const QModelIndex& parent)
{
    beginRemoveRows(parent, row, row+count);
    bool success = m_matrix->removeRow(row);
    endRemoveRows();
    return success;
}

bool MatrixModel::removeColumns(int column, int count, const QModelIndex& parent)
{
    beginRemoveColumns(parent, column-count, column);
    bool success = m_matrix->removeColumns(count);
    endRemoveColumns();
    return success;
}

void MatrixModel::updateColorScheme()
{
    m_color_scheme = ColorProvider().provide();
    m_foreground_scheme = ColorProvider().provide();
    emit dataChanged(index(0,0), index(rowCount(), columnCount()));
}

QList<QColor> MatrixModel::colorScheme()
{
    return m_color_scheme;
}

void MatrixModel::updateAll()
{
    emit dataChanged(index(0,0), index(rowCount(), columnCount()));
}

void MatrixModel::update(int row, int column)
{
    emit dataChanged(index(row,column), index(row, column));
}

Matrix *MatrixModel::matrix()
{
    return m_matrix;
}

void MatrixModel::beginInsertRows(const QModelIndex& m, int row, int col)
{
    QAbstractTableModel::beginInsertRows(m, row, col);
}

void MatrixModel::beginRemoveRows(const QModelIndex& m, int row, int col)
{
    QAbstractTableModel::beginRemoveRows(m, row, col);
}

void MatrixModel::endInsertRows()
{
    QAbstractTableModel::endInsertRows();
}

void MatrixModel::endRemoveRows()
{
    QAbstractTableModel::endRemoveRows();
}

void MatrixModel::undo()
{
    if(m_undo_stack.canUndo()) m_undo_stack.undo();
}

void MatrixModel::redo()
{
    if(m_undo_stack.canRedo()) m_undo_stack.redo();
}
