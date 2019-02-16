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

#include "ui/EditorPage/EditorPage2D/EditorPage2D.hpp"
#include "ui/EditorPage/EditorPage2D/EditorScene2D.hpp"
#include "ui_EditorPage2D.h"

EditorPage2D::EditorPage2D(QTabWidget *parent, MainWindow *mainWindow)
    : QWidget(parent)
    , m_main_window(mainWindow)
    , m_ui(new Ui::EditorPage2D)
{
    m_ui->setupUi(this);
    m_ui->graphicsView->setScene(new EditorScene2D(m_ui->graphicsView));
}

EditorPage2D::~EditorPage2D()
{
    delete m_ui;
}
