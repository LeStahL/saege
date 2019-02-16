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

#ifndef SCENE_H
#define SCENE_H

#include <QList>
#include <QString>

#include "Layer.hpp"

class Scene
{
public:
    Scene(QString name, float t_begin, float t_end);
    virtual ~Scene();
    
    void setName(QString name);
    QString name();
    
    void setRange(float begin, float end);
    void setBegin(float begin);
    void setEnd(float end);
    float begin();
    float end();
    
private:
    QString m_name;
    QList<Layer> m_layers;
    float m_t_begin, m_t_end;
};

#endif
