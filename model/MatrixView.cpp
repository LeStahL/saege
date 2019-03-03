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
#include <QPalette>
#include <QHeaderView>
#include <QLabel>

MatrixView::MatrixView(QWidget *parent)
    : QTableView(parent)
    , m_column_width(40)
{
    verticalHeader()->setMinimumSize(QSize(200,40));
    horizontalHeader()->setMinimumSize(QSize(40,40));
    verticalHeader()->setDefaultSectionSize(40);
    horizontalHeader()->setDefaultSectionSize(40);
    
    m_name_label = new QLabel("SaeGE", this);
    m_name_label->move(0,0);
    m_name_label->resize(200, 40);
    m_name_label->show();
    
    uint cp = 0x271A;
    QString mystr = QString::fromUcs4(&cp, 1);
    m_add_column_button = new QPushButton(mystr, this);
    m_add_column_button->move(60.,0);
    m_add_column_button->resize(40.,40.);
    m_add_column_button->show();
    connect(m_add_column_button, SIGNAL(clicked()), this, SLOT(addColumnSlot()));
    
    m_add_row_button = new QPushButton(mystr, this);
    m_add_row_button->move(0.,0);
    m_add_row_button->resize(40.,40.);
    m_add_row_button->show();
    connect(m_add_row_button, SIGNAL(clicked()), this, SLOT(addRowSlot()));
    
    cp = 0x273F;
    mystr = QString::fromUcs4(&cp, 1);
    m_change_scheme_button = new QPushButton(mystr, this);
    m_change_scheme_button->move(161.,1);
    m_change_scheme_button->resize(40.,40.);
    m_change_scheme_button->show();
    connect(m_change_scheme_button, SIGNAL(clicked()), this, SLOT(changeSchemeSlot()));
    
    cp = 0x2718;
    mystr = QString::fromUcs4(&cp, 1);
    QPushButton *button = new QPushButton(mystr, this);
    button->move(60,0);
    button->resize(40,40);
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
    update();
}

void MatrixView::update()
{
    m_remove_column_button->move(((MatrixModel*)model())->columnCount()*(m_column_width)+201,0);
    m_add_column_button->move(241+((MatrixModel*)model())->columnCount()*(m_column_width),0);
    m_add_row_button->move(161.,41.+((MatrixModel*)model())->rowCount()*(m_column_width));
    
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
                    uint cp = 0x2718;
                    QString mystr = QString::fromUcs4(&cp, 1);
                    QPushButton *button = new QPushButton(mystr, this);
                    button->move(161,stack+41.);
                    button->resize(40,40);
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
    
    QList<QColor> palette = ((MatrixModel*)model())->colorScheme();
    QString stylesheet = "QLabel,QHeaderView,QTableView{alignment:top;font:bold;font-size:14pt;background-color:" + palette[0].name()
        + ";color:" + palette[9].name() 
        + ";}QHeaderView::Section{background-color:"+palette[4].name()+";}QPushButton{font:bold;font-size:14pt;background-color:" + palette[8].name()
        + ";color:" + palette[1].name() 
        + ";}";
    setStyleSheet(stylesheet);
    verticalHeader()->setStyleSheet(stylesheet);
    horizontalHeader()->setStyleSheet(stylesheet);
    
    QTableView::update();
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
