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

#ifndef EDITORPAGE2D_H
#define EDITORPAGE2D_H

#include <QWidget>
#include <QTabWidget>

#include "ui/MainWindow.hpp"

namespace Ui { class EditorPage2D; }

class EditorPage2D : public QWidget
{
    Q_OBJECT
    
public:
    EditorPage2D(QTabWidget *parent, MainWindow *mainWindow);
    virtual ~EditorPage2D();
    
private:
    MainWindow *m_main_window;
    Ui::EditorPage2D *m_ui;
};

#endif
