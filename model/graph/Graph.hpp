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

#ifndef GRAPH_H
#define GRAPH_H

class Node;
class Edge;

#include <QList>
#include <QString>

class Graph
{
public:
    Graph();
    virtual ~Graph();
    
    bool addNode(Node *n);
    bool removeNode(Node *n);
    
    bool connectNodes(Node *n1, QString attribute1, Node *n2, QString attribute2);
    bool connectNodes(Node *n1, int attribute_index1, Node *n2, int attribute_index2);
    
    bool disconnectNodes(Node *n1, Node *n2);
    
    QString toString();
    
    //TODO: toXML()
    //TODO: fromXML()
    
private:
    QList<Node *> m_nodes;
    QList<QList<int> > m_matrix;
};

#endif
