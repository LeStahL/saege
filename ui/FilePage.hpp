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

#ifndef FILEPAGE_H
#define FILEPAGE_H

#include <QWidget>
#include <QString>

#include "ui/MainWindow.hpp"

class FilePage : public QWidget
{
    Q_OBJECT

public:
    FilePage(QTabWidget *parent, QMainWindow *win, QString filename="");
    virtual ~FilePage();
    QString fileName();
    void setFileName(QString filename);
    void save() = 0;
    void load(QString filename) = 0;
    
private:
    MainWindow *m_main_window;
    QString m_filename;
};

#endif
