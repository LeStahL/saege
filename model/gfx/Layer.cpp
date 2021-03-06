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

#include "model/gfx/Layer.hpp"

Layer::Layer(QString name)
    : m_name(name)
{
}

Layer::~Layer()
{
}

void Layer::setName(QString name)
{
    m_name = name;
}

QString Layer::name()
{
    return m_name;
}

void Layer::addObject(Object *object)
{
    m_objects.push_back(object);
}

void Layer::removeObject(Object *object)
{
    m_objects.removeOne(object);
}

Object *Layer::findObject(QString name)
{
    for(int i=0; i<m_objects.size(); ++i)
    {
        if(m_objects.at(i)->name() == name)
            return m_objects.at(i);
    }
    return 0;
}
