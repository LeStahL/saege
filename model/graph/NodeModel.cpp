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
            return m_node->attributeTypeString(attribute_name);
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
            else if(section == 1) return "Type";
        }
        else if(orientation == Qt::Vertical)
        {
            return section;
        }
    }
    return QVariant();
}

Qt::ItemFlags NodeModel::flags(const QModelIndex& index) const
{
    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}

bool NodeModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(role == Qt::EditRole)
    {
        QString attribute_name = m_node->attribute(index.row());
        if(index.column() == 0)
        {
            bool success = m_node->renameAttribute(attribute_name, value.toString());
            if(success)
                emit dataChanged(index, index);
            return success;
        }
        else if(index.column() == 1)
        {
            bool success =  m_node->updateAttributeFromString(attribute_name, value.toString());
            if(success)
                emit dataChanged(index, index);
            return success;
        }
    }
    return false;
}
