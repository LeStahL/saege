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

#ifndef NODEVIEW_H
#define NODEVIEW_H

#include <QAbstractItemView>
#include <QWidget>
#include <QRect>
#include <QModelIndex>

class NodeView : public AbstractItemView
{
    Q_OBJECT
    
public:
    NodeView(QWidget *parent = 0);
    
    QRect visualRect(const QModelIndex &index) const override;
};

#endif
