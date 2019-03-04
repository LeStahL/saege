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

class MatrixView;

#include <QHeaderView>
#include <QAbstractTableModel>
#include <QPainter>
#include <QPaintEvent>
#include <QRect>
#include <QWidget>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPushButton>

class MatrixHeaderView : public QHeaderView
{
    Q_OBJECT
    
public:
    explicit MatrixHeaderView(Qt::Orientation orientation, QWidget *parent = nullptr);
    virtual ~MatrixHeaderView();
    
private slots:
    void finishEditing();
    void cancelEditing();
    
protected:
    void paintEvent(QPaintEvent *e) override;
    void paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const;
    void mouseDoubleClickEvent(QMouseEvent *e);
    
private:
    MatrixView *m_view;
    QLineEdit *m_editor;
    int m_index;
    QPushButton *m_remove_button;
};

#endif
