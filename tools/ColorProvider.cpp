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

#include "ColorProvider.hpp"

#include <QRandomGenerator>

ColorProvider::ColorProvider()
{
}

ColorProvider::~ColorProvider()
{
}

QList<QColor> ColorProvider::provide()
{
    QColor any = QColor::fromRgb(QRandomGenerator::global()->generate()),
        light = QColor::fromRgb(.7*255+.3*any.red(), .7*255+.3*any.green(), .7*255+.3*any.blue()),
        dark = QColor::fromRgb(.4*255+.3*any.red(), .4*255+.3*any.green(), .4*255+.3*any.blue()),
        verydark =  QColor::fromRgb(.2*255+.3*any.red(), .2*255+.3*any.green(), .2*255+.3*any.blue());
        
    QList<QColor> colors;
    colors.push_back(verydark);
    colors.push_back(dark);
    colors.push_back(light);

    return colors;
}
