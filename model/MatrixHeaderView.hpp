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

#ifndef MATRIX_HEADER_VIEW_H
#define MATRIX_HEADER_VIEW_H

#include <QHeaderView>
#include <QAbstractTableModel>

class MatrixHeaderView : public QHeaderView
{
    Q_OBJECT
    
public:
    MatrixHeaderView(MatrixView *parent);
    virtual ~MatrixHeaderView();
    
private:
    QAbstractTableModel *m_model;
    QFormLayout *m_layout;
    QList<QPushButton *> m_selectors;
    QList<QPushButton *> m_edit_names;
    QList<QPushButton *> m_removes;
};

#endif
