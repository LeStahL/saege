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

#include "MatrixRemoveRowCommand.hpp"

#include <QModelIndex>

MatrixRemoveRowCommand::MatrixRemoveRowCommand(MatrixModel* model, int row)
    : QUndoCommand()
    , m_model(model)
    , m_row_index(row)
    , m_name(model->matrix()->rowName(row))
{
    setText(QString("Remove row %1").arg(m_row_index));
    for(int i=0; i<m_model->matrix()->columnCount(); ++i)
        m_data.push_back(m_model->matrix()->value(m_row_index, i));
}

void MatrixRemoveRowCommand::redo()
{
    m_model->beginRemoveRows(QModelIndex(), m_row_index, m_row_index);
    m_model->matrix()->removeRow(m_row_index);
    m_model->endRemoveRows();
    m_model->updateAll();
}

void MatrixRemoveRowCommand::undo()
{
    m_model->beginInsertRows(QModelIndex(), m_row_index, m_row_index);
    m_model->matrix()->addRow(m_row_index, m_name);
    for(int i=0; i<m_data.length(); ++i)
        m_model->matrix()->setValue(m_row_index, i, m_data[i]);
    m_model->endInsertRows();
    m_model->updateAll();
}

MatrixRemoveRowCommand::~MatrixRemoveRowCommand()
{
}
