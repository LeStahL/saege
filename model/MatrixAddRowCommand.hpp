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

#ifndef MATRIX_ADD_ROW_COMMAND
#define MATRIX_ADD_ROW_COMMAND

#include <QUndoCommand>

#include "MatrixModel.hpp"
#include "Matrix.hpp"

static int ROWCMD_ID = 0;

class MatrixAddRowCommand : public QUndoCommand
{
public:
    MatrixAddRowCommand(MatrixModel *model);
    virtual ~MatrixAddRowCommand();

    void redo() override;
    void undo() override;
    
private:
    MatrixModel *m_model;
    int m_row_index;
};

#endif
