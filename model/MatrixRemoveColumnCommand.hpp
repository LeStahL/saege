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

#ifndef MATRIX_REMOVE_COLUMN_COMMAND
#define MATRIX_REMOVE_COLUMN_COMMAND

#include <QUndoCommand>
#include <QModelIndex>
#include <QString>

#include "MatrixModel.hpp"
#include "Matrix.hpp"

class MatrixRemoveColumnCommand : public QUndoCommand
{
public:
    MatrixRemoveColumnCommand(MatrixModel *model, int row);
    virtual ~MatrixRemoveColumnCommand();

    void redo() override;
    void undo() override;

private:
    MatrixModel *m_model;
    int m_column_index;
    QList<int> m_data;
};

#endif
