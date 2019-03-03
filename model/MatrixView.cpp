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

#include "MatrixView.hpp"
#include "ColorProvider.hpp"

#include <QDebug>
#include <QHeaderView>

MatrixView::MatrixView(QWidget *parent)
    : QTableView(parent)
    , m_add_row_button(new QPushButton("+r", this))
    , m_add_column_button(new QPushButton("+c", this))
    , m_change_scheme_button(new QPushButton("S", this))
    , m_row_color_scheme(ColorProvider().provide())
{
    verticalHeader()->setMinimumSize(QSize(60,20));
    setAlternatingRowColors(true);
    changeSchemeSlot();
    
    m_add_column_button->move(20.,0);
    m_add_column_button->resize(20.,20.);
    m_add_column_button->show();
    connect(m_add_column_button, SIGNAL(clicked()), this, SLOT(addColumnSlot()));
    
    m_add_row_button->move(0.,0);
    m_add_row_button->resize(20.,20.);
    m_add_row_button->show();
    connect(m_add_row_button, SIGNAL(clicked()), this, SLOT(addRowSlot()));
    
    m_change_scheme_button->move(40.,0);
    m_change_scheme_button->resize(20.,20.);
    m_change_scheme_button->show();
    connect(m_change_scheme_button, SIGNAL(clicked()), this, SLOT(changeSchemeSlot()));
}

MatrixView::~MatrixView()
{
    delete m_add_row_button;
    delete m_add_column_button;
    delete m_change_scheme_button;
}

void MatrixView::addRowSlot()
{
    model()->insertRows(model()->rowCount(QModelIndex()), 0);
}

void MatrixView::addColumnSlot()
{
    model()->insertColumns(model()->columnCount(QModelIndex()), 4);
}

void MatrixView::changeSchemeSlot()
{
    m_row_color_scheme = ColorProvider().provide();
    
    QString header_style = "background-color:" + m_row_color_scheme[0].name() 
                         + ";color:" + m_row_color_scheme[1].name() 
                         + ";selection-background-color:" + m_row_color_scheme[0].name()
                         + ";selection-color:" + m_row_color_scheme[2].name()
                         + ";";
    horizontalHeader()->setStyleSheet(header_style);
    verticalHeader()->setStyleSheet(header_style);
    setStyleSheet("background-color:" + m_row_color_scheme[2].name() 
                + ";alternate-background-color:" + m_row_color_scheme[1].name() 
                + ";color:" + m_row_color_scheme[0].name() 
                + ";selection-background-color:" + m_row_color_scheme[0].name()
                + ";selection-color:" + m_row_color_scheme[2].name()
                + ";");
    
}
