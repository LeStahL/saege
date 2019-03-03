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
    QColor any = QColor::fromRgb(QRandomGenerator::global()->generate());
//     any = QColor::fromRgb(255.*.6+.4*any.red(), 255.*.6+.4*any.green(), 255.*.6+.4*any.blue());
    
    QList<QColor> colors;
    for(int i=0; i<10; ++i)
    {
        colors.push_back(QColor::fromRgb((float)i/10.*255.+(1.-(float)i)/10.*any.red(),
                                         (float)i/10.*255.+(1.-(float)i)/10.*any.green(),
                                         (float)i/10.*255.+(1.-(float)i)/10.*any.blue()));
    }
    
    return colors;
}
