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

#ifndef NODE_H
#define NODE_H

#include <QList>
#include <QString>

static int NODEID = 1;

class Graph;
class Edge;

class Node
{
public:
    Node(Graph *g, QString name="");
    virtual ~Node();
        
    typedef enum 
    {
        Float,
        Vec2,
        Vec3,
        Vec4,
        Mat2,
        Mat3,
        Mat4,
        In,
        Out,
        Error
    } AttributeType;

    int addAttribute(QString name, AttributeType type);
    int attributeIndex(QString name);
    NodeType attributeType(QString name);
    bool isIn(QString name);
    bool isOut(QString name);
    QString attribute(int index);

    //TODO: toXML()
    //TODO: fromXML()
    
    Node *nodeConnectedToAttribute(QString name);
    QString AttributeConnectedToAttribute(QString name);
    
    QString name();
    void setName(QString name);
    
private:
    QString m_name;
    QList<QString> m_identifiers;
    QList<NodeType> m_types;
    Graph *m_graph;
    int m_id;
};

#endif
