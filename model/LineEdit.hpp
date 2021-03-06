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

#ifndef LINE_EDIT_H
#define LINE_EDIT_H

#include <QLineEdit>
#include <QFocusEvent>
#include <QKeyEvent>

class LineEdit : public QLineEdit
{
    Q_OBJECT
    
public:
    LineEdit(QWidget *parent = 0);
    virtual ~LineEdit();
    
signals:
    void focusLost();
    void editingCancelled();
    
protected:
    void focusOutEvent(QFocusEvent *e);
    void keyPressEvent(QKeyEvent *e);
};

#endif
