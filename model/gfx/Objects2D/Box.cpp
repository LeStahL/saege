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

#include "model/gfx/Objects2D/Box.hpp"
#include "model/gfx/Objects2D/BoxFrag.hpp"

Box::Box(QString name)
    : Object2D(name)
    , m_coordinate(0)
    , m_width(0)
    , m_height(0)
{
}

void Box::setCoordinate(Object2D *coord)
{
    m_coordinate = coord;
}

Object2D *Box::coordinate()
{
    return m_coordinate;
}

void Box::setWidth(Object2D *width)
{
    m_width = width;
}

Object2D *Box::width()
{
    return m_width;
}

void Box::setHeight(Object2D *height)
{
    m_height = height;
}

Object2D *Box::height()
{
    return m_height;
}

QString Box::toGLSL()
{
//     return TODO
}

bool Box::canCompile()
{
    // Check if all connectors are connected
    if(m_height == 0) 
        return false;
    if(m_width == 0)
        return false;
    if(m_coordinate == 0)
        return false;
    
    // Check if connected nodes have the correct type
    if(m_coordinate->type() != Object::Vec2) 
        return false;
    if(m_width->type() != Object::Number)
        return false;
    if(m_height->type() != Object::Number)
        return false;
    
    return true;
}

Object::ObjectType Box::type()
{
    return Object::Number;
}
