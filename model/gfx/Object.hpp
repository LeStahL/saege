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

#ifndef OBJECT_H
#define OBJECT_H

#include <QString>

class Object 
{
public:
    Object(QString name);
    virtual ~Object() = default;
    
    void setName(QString name);
    QString name();
    
    //TODO: add toXML
    virtual void toGLSL() = 0;
    virtual int dimensions() = 0;
    virtual bool canCompile() = 0;
    
    typedef enum
    {
        Number,
        Vec2,
        Vec3,
        Vec4,
        Mat2,
        Mat3,
        Mat4
    } ObjectType;
    
    virtual ObjectType type() = 0;
    
private:
    QString m_name;
};

#endif
