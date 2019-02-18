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

#ifndef VALUE_H
#define VALUE_H

#include "model/gfx/Object.hpp"

class Value : public object
{
public:
    Value(float num);
    virtual ~Value() = default;
    
    QString toGLSL() override;
    
    void setValue(float value);
    float value();
    
    bool canCompile() override;
    Object::ObjectType type() override;
    
private:
    float m_value;
};

#endif
