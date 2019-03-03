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

#include "MatrixValueChangeCommand.hpp"

MatrixValueChangeCommand::MatrixValueChangeCommand(const QModelIndex &index, const QVariant &value, MatrixModel *model)
    : QUndoCommand()
    , m_model(model)
{
    m_old = index.data(Qt::DisplayRole);
    m_new = value;
    m_row = index.row();
    m_col = index.column();
    setText(QString("Value change at (%1, %2) from %3 to %4").arg(m_row).arg(m_col).arg(m_old.toInt()).arg(m_new.toInt()));
}

void MatrixValueChangeCommand::redo()
{
    m_model->matrix()->setValue(m_row, m_col, m_new.toInt());
    m_model->update(m_row, m_col);
}

void MatrixValueChangeCommand::undo()
{
    m_model->matrix()->setValue(m_row, m_col, m_old.toInt());
    m_model->update(m_row, m_col);
}

MatrixValueChangeCommand::~MatrixValueChangeCommand()
{
}
