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

#ifndef MATRIX_MODEL_H
#define MATRIX_MODEL_H

#include "Matrix.hpp"

#include <QAbstractTableModel>
#include <QObject>
#include <QModelIndex>
#include <QVariant>
#include <QColor>
#include <QList>
#include <QUndoStack>
#include <QModelIndexList>

class MatrixModel : public QAbstractTableModel
{
public:
    explicit MatrixModel(Matrix *m, QObject *parent = 0);
    ~MatrixModel();
    
    // Show
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole) override;
    
    // Edit
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    
    // Resize
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;
    
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;
    
    void updateColorScheme();
    QList<QColor> colorScheme();
    
    void updateAll();
    void update(int row, int column);
    
    Matrix *matrix();
    
    void beginInsertRows(const QModelIndex &m, int row, int col);
    void beginRemoveRows(const QModelIndex &m, int row, int col);
    void endInsertRows();
    void endRemoveRows();
    
    void beginInsertColumns(const QModelIndex &m, int row, int col);
    void beginRemoveColumns(const QModelIndex &m, int row, int col);
    void endInsertColumns();
    void endRemoveColumns();
    
    void undo();
    void redo();
    
//     void paste(QModelIndex where, QModelIndexList topaste);
    
    QModelIndex createIndex(int row, int column, void *ptr = nullptr) const;
    
private:
    Matrix *m_matrix;
    QList<QColor> m_color_scheme, m_foreground_scheme;
    QUndoStack m_undo_stack;
};

#endif
