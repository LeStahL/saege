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

#include "model/graph/Graph.hpp"
#include "model/graph/Node.hpp"
#include "model/graph/NodeModel.hpp"

#include <QTableView>
#include <QApplication>

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    QTableView tableView;
    Graph g;
    Node *n = g.addNode("Graph Theory Rulez");
    n->addAttribute("input1", Node::AttributeType(Node::Float | Node::In));
    n->addAttribute("input2", Node::AttributeType(Node::Float | Node::In));
    n->addAttribute("output1", Node::AttributeType(Node::Float | Node::Out));
    
    NodeModel m(n);
    tableView.setModel(&m);
    tableView.show();
    return a.exec();
}
