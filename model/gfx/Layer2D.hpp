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

#ifndef LAYER_2D
#define LAYER_2D

#include "model/gfx/Layer.hpp"
#include "model/gfx/Object2D.hpp"

class Layer2D : public Layer
{
public:
    Layer2D(QString name) = default;
    virtual ~Layer2D(QString name) = default;
    
    QString toXml();
    void fromXml();
    
    QString toGLSL();
    
    void addObject(Object2D *object);
    void removeObject(Object2D *object);
    Object2D *findObject(QString name);
    
private:
    QList<Object2D *> m_objects;
};

#endif
