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

#include "Graph.hpp"

Graph::Graph()
{
}

Graph::~Graph()
{
}

bool Graph::addNode(Node* n)
{
    if(m_nodes.contains(n)) return false;
    m_nodes.push_back(n);
    
    QList<int> last;
    last.push_back(-1);
    for(int i=0; i<m_matrix.length(); ++i)
    {
        last.push_back(-1);
        m_matrix[i].push_back(-1);
    }
    m_matrix.push_back(last);
    
    return true;
}

bool Graph::removeNode(Node* n)
{
    if(!m_nodes.contains(n)) return false;
    int index = m_nodes.indexOf(n);
    for(int i=0; i<m_matrix.length(); ++i)
        m_matrix[i].removeAt(index);
    m_matrix.removeAt(index);
    m_nodes.removeAt(index);
    
    return true;
}

bool Graph::connectNodes(Node* n1, QString attribute1, Node* n2, QString attribute2)
{
    int index1 = n1->attributeIndex(attribute1), index2 = n2->attributeIndex(attribute2);
    if(index1 < 0) return false;
    if(index2 < 0) return false;
    
    return connectNodes(n1, index1, n2, index2);
}

bool Graph::connectNodes(Node* n1, int attribute_index1, Node* n2, int attribute_index2)
{
    if(!m_nodes.contains(n1)) return false;
    if(!m_nodes.contains(n2)) return false;
    
    int node_index1 = m_nodes.indexOf(n1), node_index2 = m_nodes.indexOf(n2);
    m_matrix[node_index1][node_index2] = attribute_index1;
    m_matrix[node_index2][node_index1] = attribute_index2;
    
    return true;
}

bool Graph::disconnectNodes(Node* n1, Node* n2)
{
    if(!m_nodes.contains(n1)) return false;
    if(!m_nodes.contains(n2)) return false;
    
    int index1 = m_nodes.indexOf(n1), index2 = m_nodes.indexOf(n2);
    m_matrix[index1][index2] = -1;
    m_matrix[index2][index1] = -1;
    
    return true;
}

int Graph::toString()
{
    QString ret = "Graph with nodes:\n";
    for(int i=0; i<m_nodes.length(); ++i)
        ret += m_nodes[i]->name() + "\n";
    ret += "Graph matrix:\n";
    for(int i=0; i<m_nodes.length(); ++i)
    {
        for(int j=0; j<m_nodes.length(); ++j)
            ret += QString::number(m_matrix[i][j]) + " ";
        ret += "\n";
    }
    return ret;
}
