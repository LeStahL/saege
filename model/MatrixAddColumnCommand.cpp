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

#include "MatrixAddColumnCommand.hpp"

#include <QModelIndex>

MatrixAddColumnCommand::MatrixAddColumnCommand(MatrixModel *model)
    : QUndoCommand()
    , m_model(model)
    , m_column_id(COLUMNCMD_ID)
{
    setText(QString("Add column %1").arg(m_column_id));
    ++COLUMNCMD_ID;
    m_column_index = m_model->matrix()->columnCount();
}

void MatrixAddColumnCommand::redo()
{
    m_model->beginInsertColumns(QModelIndex(), m_column_index, m_column_index);
    m_model->matrix()->addColumns(1);
    m_model->endInsertColumns();
    m_model->updateAll();
}

void MatrixAddColumnCommand::undo()
{
    m_model->beginRemoveColumns(QModelIndex(), m_column_index, m_column_index);
    m_model->matrix()->removeColumns(1);
    m_model->endRemoveColumns();
    m_model->updateAll();
}

MatrixAddColumnCommand::~MatrixAddColumnCommand()
{
}
