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

#include "model/Matrix.hpp"
#include "model/MatrixModel.hpp"
#include "model/MatrixView.hpp"

#include <QApplication>

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    MatrixView matrixView;
    Matrix m("Test matrix");
    m.addRow("Test 1");
    m.addRow("Test 2");
    m.addRow("Test 3");
    m.addRow("Test 4");
    m.addRow("Test 5");
    m.addColumns(12);
    
    MatrixModel model(&m);
    matrixView.setModel(&model);
    matrixView.setColumnWidth(20);
    matrixView.show();
    return a.exec();
}
