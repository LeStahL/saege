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

#ifndef MATRIX_VIEW_H
#define MATRIX_VIEW_H

#include <QTableView>
#include <QObject>

#include <QPushButton>

class MatrixView : public QTableView
{
    Q_OBJECT
    
public:
    MatrixView(QWidget *parent = 0);
    virtual ~MatrixView();
    
private slots:
    void addColumnSlot();
    void addRowSlot();
    void changeSchemeSlot();
    
private:
    QPushButton *m_add_row_button, *m_add_column_button, *m_change_scheme_button;
};

#endif
