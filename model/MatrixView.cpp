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
#include "MatrixModel.hpp"
#include "ColorProvider.hpp"

#include <QDebug>
#include <QHeaderView>

MatrixView::MatrixView(QWidget *parent)
    : QTableView(parent)
    , m_add_row_button(new QPushButton("+r", this))
    , m_add_column_button(new QPushButton("+c", this))
    , m_change_scheme_button(new QPushButton("S", this))
    , m_column_width(40)
{
    verticalHeader()->setMinimumSize(QSize(100,20));
    horizontalHeader()->setMinimumSize(QSize(40,60));
    
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
    
    QPushButton *button = new QPushButton("-", this);
    button->move(60,0);
    button->resize(40,20);
    button->show();
    connect(button, SIGNAL(clicked()), this, SLOT(removeColumnSlot()));
    m_remove_column_button = button;
}

MatrixView::~MatrixView()
{
    delete m_add_row_button;
    delete m_add_column_button;
    delete m_change_scheme_button;
    delete m_remove_column_button;
}

void MatrixView::addRowSlot()
{
    model()->insertRows(model()->rowCount(QModelIndex()), 1);
    update();
}

void MatrixView::addColumnSlot()
{
    model()->insertColumns(model()->columnCount(QModelIndex()), 1);
    model()->insertColumns(model()->columnCount(QModelIndex()), 1);
    model()->insertColumns(model()->columnCount(QModelIndex()), 1);
    model()->insertColumns(model()->columnCount(QModelIndex()), 1);
    update();
}

void MatrixView::changeSchemeSlot()
{
    ((MatrixModel*)model())->updateColorScheme();
}

void MatrixView::setColumnWidth(int width)
{
    m_column_width = width;
    for(int i=0; i<((MatrixModel*)model())->columnCount(); ++i)
        QTableView::setColumnWidth(i,width);
    for(int i=0; i<((MatrixModel*)model())->rowCount(); ++i)
        QTableView::setRowHeight(i,width);
    ((MatrixModel*)model())->updateAll();
}

void MatrixView::update()
{
    setColumnWidth(m_column_width);
    ((MatrixModel*)model())->updateAll();
    
    m_remove_column_button->move(((MatrixModel*)model())->columnCount()*(m_column_width+19.)+61,0);
    
    if(m_remove_row_buttons.size() != ((MatrixModel*)model())->rowCount())
    {
        if(m_remove_row_buttons.size() < ((MatrixModel*)model())->rowCount())
        {
            float stack = 0;
            QHeaderView *header = verticalHeader();
            for(int i=0; i<((MatrixModel*)model())->rowCount(); ++i)
            {
                if(i>=m_remove_row_buttons.size())
                {
                    QPushButton *button = new QPushButton("-", this);
                    button->move(60,stack+62.);
                    button->resize(40,20);
                    button->show();
                    m_remove_row_buttons.push_back(button);
                    connect(button, SIGNAL(clicked()), this, SLOT(removeRowSlot()));
                }
                stack += header->sectionSize(i);
            }
        }
        else
        {
            float stack = 0;
            QHeaderView *header = verticalHeader();
            for(int i=0; i<((MatrixModel*)model())->rowCount(); ++i)
            {
                if(i>=m_remove_row_buttons.size())
                {
                    QPushButton *button = new QPushButton("-", this);
                    button->move(60,i*(m_column_width+3.)+62.);
                    button->resize(40,20);
                    button->show();
                    m_remove_row_buttons.push_back(button);
                    connect(button, SIGNAL(clicked()), this, SLOT(removeRowSlot()));
                }
                stack += header->sectionSize(i);
            }
        }
    }
}

void MatrixView::keyPressEvent(QKeyEvent* e)
{
//     qDebug() << "Key pressed:" << e->key();
//     QTableView::keyPressEvent(e);
    if(e->matches(QKeySequence::Undo))
        ((MatrixModel*)model())->undo();
    if(e->matches(QKeySequence::Redo))
        ((MatrixModel*)model())->redo();
    
//     if(e->key() == Qt::Space)
        
}

void MatrixView::removeColumnSlot()
{
    qDebug() << model()->columnCount(QModelIndex());
    model()->removeColumns(1, 0);
    update();
}

void MatrixView::removeRowSlot()
{
    QPushButton *button = (QPushButton*)QObject::sender();
    int index = m_remove_row_buttons.indexOf(button);
    model()->removeRows(index, 0);
}
