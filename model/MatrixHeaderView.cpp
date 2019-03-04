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

#include "MatrixHeaderView.hpp"
#include "MatrixView.hpp"
#include "MatrixModel.hpp"
#include "LineEditDelegate.hpp"

#include <QDebug>
#include <QStyleOptionViewItem>
#include <QKeyEvent>
#include <QSize>

MatrixHeaderView::MatrixHeaderView(Qt::Orientation orientation, QWidget *parent)
    : QHeaderView(orientation, parent)
    , m_view((MatrixView*)parent)
{
    setSectionResizeMode(QHeaderView::ResizeMode::Fixed);
    setEditTriggers(QAbstractItemView::DoubleClicked);
    setItemDelegate(new LineEditDelegate(this));
    
    uint cp = 0x2718;
    QString mystr = QString::fromUcs4(&cp, 1);
    
    m_remove_button = new QPushButton(mystr, (QWidget*)this);
    int h = m_view->horizontalHeaderSectionSize().height();
    m_remove_button->resize(h,h);
    m_remove_button->hide();
}

MatrixHeaderView::~MatrixHeaderView()
{
    delete m_remove_button;
}

void MatrixHeaderView::paintEvent(QPaintEvent *e)
{
    QHeaderView::paintEvent(e);
}

void MatrixHeaderView::paintSection(QPainter* painter, const QRect& rect, int logicalIndex) const
{
    QBrush bg = model()->headerData(logicalIndex, orientation(), Qt::BackgroundRole).value<QBrush>(),
        fg = model()->headerData(logicalIndex, orientation(), Qt::TextColorRole).value<QBrush>();
    QFont font = model()->headerData(logicalIndex, orientation(), Qt::FontRole).value<QFont>();
    QString text = model()->headerData(logicalIndex, orientation(), Qt::DisplayRole).value<QString>();

    painter->fillRect(rect, bg);
    
    painter->save();
    painter->setBrush(fg);
    painter->setFont(font);
    painter->drawText(QRect(rect.x()+40,rect.y(),rect.width()-40,rect.height()), Qt::AlignVCenter | Qt::AlignLeft, text);
    
    int h = m_view->horizontalHeaderSectionSize().height();
    m_remove_button->render(painter->device(), QPoint(1, h*(logicalIndex)));
    
    painter->restore();
}

void MatrixHeaderView::mouseDoubleClickEvent(QMouseEvent* e)
{
    int pos = orientation() == Qt::Horizontal ? e->x() : e->y();
    
    int index = logicalIndexAt(e->pos());
    m_index = index;
    
    QBrush bg = model()->headerData(index, orientation(), Qt::BackgroundRole).value<QBrush>(),
        fg = model()->headerData(index, orientation(), Qt::TextColorRole).value<QBrush>();
    QFont font = model()->headerData(index, orientation(), Qt::FontRole).value<QFont>();
    QString text = model()->headerData(index, orientation(), Qt::DisplayRole).value<QString>();
    QString stylesheet = "font:bold;font-size:14pt;background-color:" + bg.color().name()
        + ";color:" + fg.color().name()
        + ";";
    
    QLineEdit *editor = (QLineEdit*)itemDelegate()->createEditor(this, QStyleOptionViewItem(),((MatrixModel*)model())->createIndex(index,0));
    itemDelegate()->setEditorData(editor, ((MatrixModel*)model())->createIndex(index,0));
    editor->move(QPoint(40, m_view->horizontalHeaderSectionSize().height() * index));
    editor->setFocus();
    editor->setStyleSheet(stylesheet);
    editor->resize(m_view->horizontalHeaderSectionSize());
    connect(editor, SIGNAL(editingFinished()), this, SLOT(finishEditing()));
    connect(editor, SIGNAL(focusLost()), this, SLOT(finishEditing()));
    connect(editor, SIGNAL(editingCancelled()), this, SLOT(cancelEditing()));
    m_editor = editor;
    editor->show();
    
    emit sectionDoubleClicked(index);
}

void MatrixHeaderView::finishEditing()
{
    itemDelegate()->setModelData(m_editor, model(), ((MatrixModel*)model())->createIndex(m_index,0));
    delete m_editor;
}

void MatrixHeaderView::cancelEditing()
{
    delete m_editor;
}
