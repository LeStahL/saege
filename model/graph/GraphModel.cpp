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

#include "GraphModel.hpp"

GraphModel::GraphModel(Graph *g, QObject* parent)
    : QAbstractItemModel(parent)
    , m_graph(g)
{
}

GraphModel::~GraphModel()
{
}

QModelIndex GraphModel::index(int row, int column, const QModelIndex& parent) const
{
//     if (!hasIndex(row, column, parent))
//         return QModelIndex();
// 
//     TreeItem *parentItem;
// 
//     if (!parent.isValid())
//         parentItem = rootItem;
//     else
//         parentItem = static_cast<TreeItem*>(parent.internalPointer());
// 
//     TreeItem *childItem = parentItem->child(row);
//     if (childItem)
//         return createIndex(row, column, childItem);
//     else
//         return QModelIndex();
}
