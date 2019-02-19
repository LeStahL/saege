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

#include "Node.hpp"
#include "Graph.hpp"

Node::Node(Graph* g, QString name)
    : m_graph(g)
    , m_name(name)
    , m_id(++NODEID)
{
    if(m_name == "")
        m_name = QString("Node ") + QString::number(m_id);
}

Node::~Node()
{
}

int Node::addAttribute(QString name, Node::AttributeType type)
{
    m_identifiers.push_back(name);
    m_types.push_back(type);
    return m_identifiers.size() - 1;
}

QString Node::name()
{
    return m_name;
}

void Node::setName(QString name)
{
    m_name = name;
}

int Node::attributeIndex(QString name)
{
    if(!m_identifiers.contains(name)) return -1;
    return m_identifiers.indexOf(name);
}

Node::AttributeType Node::attributeType(QString name)
{
    if(!m_identifiers.contains(name)) return Node::AttributeType::Error;
    return m_types[attributeIndex(name)];
}

bool Node::isIn(QString name)
{
    if(!m_identifiers.contains(name)) return false;
    return attributeType(name) & Node::AttributeType::In;
}

QString Node::attributeTypeString(QString name)
{
    Node::AttributeType type = attributeType(name);
    
    QString typestr = "";
    if(type & Node::Error) return "error";
    
    if(type & Node::In) typestr += "in ";
    else if(type & Node::Out) typestr += "out ";
    
    if(type & Node::Float) typestr +=  "float";
    else if(type & Node::Vec2)  typestr += "vec2";
    else if(type & Node::Vec3)  typestr += "vec3";
    else if(type & Node::Vec4)  typestr += "vec4";
    else if(type & Node::Mat2)  typestr += "mat2";
    else if(type & Node::Mat3)  typestr += "mat3";
    else if(type & Node::Mat4)  typestr += "mat4";
    
    return typestr;
}


bool Node::isOut(QString name)
{
    if(!m_identifiers.contains(name)) return false;
    return attributeType(name) & Node::AttributeType::Out;
}

QString Node::attribute(int index)
{
    return m_identifiers[index];
}

Node * Node::nodeConnectedToAttribute(QString name)
{
    return m_graph->nodeConnectedToAttribute(this, name);
}

QString Node::AttributeConnectedToAttribute(QString name)
{
    return m_graph->attributeConnectedToAttribute(this, name);
}

int Node::attributeCount() const
{
    return m_identifiers.length();
}
