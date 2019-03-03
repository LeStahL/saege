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

#include "MatrixAddRowCommand.hpp"

#include <QModelIndex>

MatrixAddRowCommand::MatrixAddRowCommand(MatrixModel *model)
    : QUndoCommand()
    , m_model(model)
    , m_row_id(ROWCMD_ID)
{
    setText(QString("Add row %1").arg(m_row_id));
    ++ROWCMD_ID;
    m_row_index = m_model->matrix()->rowCount();
}

void MatrixAddRowCommand::redo()
{
    m_model->beginInsertRows(QModelIndex(), m_row_index, m_row_index);
    m_model->matrix()->addRow(QString("Track %1").arg(m_row_id));
    m_model->endInsertRows();
    m_model->updateAll();
}

void MatrixAddRowCommand::undo()
{
    m_model->beginRemoveRows(QModelIndex(), m_row_index, m_row_index);
    m_model->matrix()->removeRow(m_row_index);
    m_model->endRemoveRows();
    m_model->updateAll();
}

MatrixAddRowCommand::~MatrixAddRowCommand()
{
}
