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

#include "MatrixRemoveColumnCommand.hpp"

#include <QModelIndex>

MatrixRemoveColumnCommand::MatrixRemoveColumnCommand(MatrixModel* model, int column)
    : QUndoCommand()
    , m_model(model)
    , m_column_index(column)
{
    setText(QString("Remove column %1").arg(m_column_index));
    for(int i=0; i<m_model->matrix()->rowCount(); ++i)
        m_data.push_back(m_model->matrix()->value(i, m_column_index));
}

void MatrixRemoveColumnCommand::redo()
{
    m_model->beginRemoveColumns(QModelIndex(), m_column_index, m_column_index);
    m_model->matrix()->removeColumns(1);
    m_model->endRemoveColumns();
    m_model->updateAll();
}

void MatrixRemoveColumnCommand::undo()
{
    m_model->beginInsertColumns(QModelIndex(), m_column_index, m_column_index);
    m_model->matrix()->addColumns(1);
    for(int i=0; i<m_data.length(); ++i)
        m_model->matrix()->setValue(i, m_column_index, m_data[i]);
    m_model->endInsertColumns();
    m_model->updateAll();
}

MatrixRemoveColumnCommand::~MatrixRemoveColumnCommand()
{
}
