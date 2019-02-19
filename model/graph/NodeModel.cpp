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

#include "NodeModel.hpp"

NodeModel::NodeModel(Node* n, QObject* parent)
    : QAbstractTableModel(parent)
    , m_node(n)
{
}

NodeModel::~NodeModel()
{
}

int NodeModel::rowCount(const QModelIndex& parent) const
{
    return m_node->attributeCount();
}

int NodeModel::columnCount(const QModelIndex& parent) const
{
    return 2;
}

QVariant NodeModel::data(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole)
    {
        QString attribute_name = m_node->attribute(index.row());
        if(index.column() == 0)
            return attribute_name;
        else if(index.column() == 1)
        {
            if(m_node->isIn(attribute_name)) return "In";
            else if(m_node->isOut(attribute_name)) return "Out";
        }
    }
    return QVariant();
}

QVariant NodeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole)
    {
        if(orientation == Qt::Horizontal)
        {
            if(section == 0) return "Attribute";
            else if(section == 1) return "Direction";
        }
        else if(orientation == Qt::Vertical)
        {
            return section;
        }
    }
    return QVariant();
}

