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

#include "MatrixChangeRowNameCommand.hpp"

MatrixChangeRowNameCommand::MatrixChangeRowNameCommand(int index, const QVariant& value, MatrixModel* model)
    : QUndoCommand()
    , m_model(model)
    , m_row(index)
    , m_old(QVariant(model->matrix()->rowName(index)))
    , m_new(value)
{
}

MatrixChangeRowNameCommand::~MatrixChangeRowNameCommand()
{
}

void MatrixChangeRowNameCommand::redo()
{
    m_model->matrix()->setRowName(m_row, m_new.toString());
    m_model->updateAll();
}

void MatrixChangeRowNameCommand::undo()
{
    m_model->matrix()->setRowName(m_row, m_old.toString());
    m_model->updateAll();
}
