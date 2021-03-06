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

#include "ImageColorPicker.hpp"
#include "ui_ImageColorPicker.h"

#include <QMimeData>
#include <QGraphicsPixmapItem>
#include <QGraphicsEllipseItem>
#include <QDebug>

ImageColorPicker::ImageColorPicker(QWidget *parent)
    : QWidget(parent)
    , m_ui(new Ui::ImageColorPicker)
    , m_graphics_scene(new QGraphicsScene())
    , m_item(new QGraphicsPixmapItem)
    , m_cursor(new QGraphicsEllipseItem(0,0,20,20))
{
    m_cursor->setBrush(QBrush(Qt::red, Qt::SolidPattern));
    m_ui->setupUi(this);
    setAcceptDrops(true);
    setMouseTracking(true);
    m_graphics_scene->addItem(m_item);
    m_graphics_scene->addItem(m_cursor);
    m_ui->graphicsView->setScene(m_graphics_scene);
}

ImageColorPicker::ImageColorPicker(QImage* image, QWidget* parent)
    : ImageColorPicker(parent)
{
    m_image = *image;
    if(m_item != 0) delete m_item;
}

ImageColorPicker::~ImageColorPicker()
{
    delete m_ui;
    delete m_graphics_scene;
}

void ImageColorPicker::dragEnterEvent(QDragEnterEvent* e)
{
    if(e->mimeData()->hasImage()) e->acceptProposedAction();
}

void ImageColorPicker::dropEvent(QDropEvent* e)
{
    m_image = qvariant_cast<QImage>(e->mimeData()->imageData());
    e->acceptProposedAction();
    emit(imageChanged());
}

void ImageColorPicker::imageChanged()
{
    m_item->setPixmap(QPixmap::fromImage(m_image));
    m_item->update();
    moveSplitter();
}

void ImageColorPicker::moveSplitter()
{
    m_ui->graphicsView->fitInView(m_image.rect(), Qt::KeepAspectRatio);
    update();
}

void ImageColorPicker::mousePressEvent(QMouseEvent* e)
{
    if(m_ui->graphicsView->rect().contains(e->pos()) && m_item != 0)
    {
        m_cursor->setPos(m_ui->graphicsView->mapToScene(e->pos())-QPoint(10,10));
        QColor color = QColor(m_item->pixmap().toImage().pixel((m_ui->graphicsView->mapToScene(e->pos())).toPoint()));
        m_ui->label_5->setStyleSheet("background-color:"+color.name()+";");
        m_ui->lineEdit->setText(QString::number((float)color.red()/255.));
        m_ui->lineEdit_2->setText(QString::number((float)color.green()/255.));
        m_ui->lineEdit_3->setText(QString::number((float)color.blue()/255.));
        m_ui->lineEdit_4->setText(QString("vec3(%1,%2,%3)").arg((float)color.red()/255.,4,'f',2,' ').arg((float)color.green()/255.,4,'f',2,' ').arg((float)color.blue()/255.,4,'f',2,' '));
        m_ui->lineEdit_4->setFocus();
        m_ui->lineEdit_4->selectAll();
        m_ui->lineEdit_5->setText(color.name());
    }
    emit(moveSplitter());
}

void ImageColorPicker::mouseMoveEvent(QMouseEvent* e)
{
    if(m_ui->graphicsView->rect().contains(e->pos()))
    {
        m_cursor->setPos(m_ui->graphicsView->mapToScene(e->pos())-QPoint(10,10));
    }
    emit(moveSplitter());
}

void ImageColorPicker::resizeEvent(QResizeEvent* e)
{
    emit(moveSplitter());
}
