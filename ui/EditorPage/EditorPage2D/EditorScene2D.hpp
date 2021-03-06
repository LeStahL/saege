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

#ifndef EDITORSCENE2D_H
#define EDITORSCENE2D_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>
#include <QPointF>
// #include "model/gfx/Layer2D.hpp"

class EditorScene2D : public QGraphicsScene
{
    Q_OBJECT
    
public:
    EditorScene2D(QGraphicsView *parent);
    virtual ~EditorScene2D();
    
private slots:
    void addRectSlot();
    
private:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *e);
    
    QMenu *m_context_menu;
    QPointF m_context_point;
//     Layer2D *m_layer;
};

#endif
