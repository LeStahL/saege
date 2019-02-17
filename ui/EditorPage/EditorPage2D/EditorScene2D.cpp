;/* SAEGE - ShAdEr Graph Editor v1.57 "BINGE" 
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

#include "ui/EditorPage/EditorPage2D/EditorScene2D.hpp"

#include <QPen>
#include <QColor>
#include <QBrush>
#include <QGraphicsView>

#include <QDebug>

EditorScene2D::EditorScene2D(QGraphicsView *parent)
    : QGraphicsScene((QObject*)parent)
{
    // Background
    addRect(QRectF(0.0, 0.0, 1920.0, 1080.0), QPen(Qt::red), QBrush(Qt::black));
    
    // Build context menu
    m_context_menu = new QMenu();
    QAction *rect_action = new QAction("Rect", this);
    rect_action->setShortcut(QKeySequence("ALT+R"));
    connect(rect_action, SIGNAL(triggered()), this, SLOT(addRectSlot()));
    m_context_menu->addAction(rect_action);
}

EditorScene2D::~EditorScene2D()
{
}

void EditorScene2D::contextMenuEvent(QGraphicsSceneContextMenuEvent *e)
{
    m_context_point = e->scenePos();
    m_context_menu->exec(e->screenPos());
}

void EditorScene2D::addRectSlot()
{
    addRect(QRectF(m_context_point.x(), m_context_point.y(), 40.0, 40.0), QPen(Qt::red), QBrush(Qt::red));
    update();
    ((QGraphicsView*)parent())->update();
}
