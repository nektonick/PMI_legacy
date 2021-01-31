// ======================================================================
//  IntListModel.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QtGui>
#include "IntListModel.h"

// ----------------------------------------------------------------------
IntListModel::IntListModel(const QList<int>& list, QObject* pobj/*=0*/) 
        : QAbstractListModel(pobj)
        , m_list(list) 
{
}

// ----------------------------------------------------------------------
QVariant IntListModel::data(const QModelIndex& index, int nRole) const
{
    if (!index.isValid()) {
        return QVariant();
    }
   /* if (index.row() < 0 || index.row() >= m_list.size()) {
        return QVariant();
    }*/
    return (nRole == Qt::DisplayRole || nRole == Qt::EditRole) 
           ? m_list.at(index.row()) 
           : QVariant();
}

// ----------------------------------------------------------------------
bool IntListModel::setData(const QModelIndex& index, 
                           const QVariant&    value, 
                           int                nRole
                          )
{
    if (index.isValid() && nRole == Qt::EditRole) {
        m_list.replace(index.row(), value.value<int>());
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

// ----------------------------------------------------------------------
int IntListModel::rowCount(const QModelIndex& parent/*=QModelIndex()*/
                          ) const
{
    if (parent.isValid()) {
        return 0;
    }

    return m_list.size();
}

// ----------------------------------------------------------------------
QVariant IntListModel::headerData(int             nSection, 
                                  Qt::Orientation orientation, 
                                  int             nRole/*=DisplayRole*/
                                 ) const
{
    if (nRole != Qt::DisplayRole) {
        return QVariant();
    }
    return (orientation == Qt::Horizontal) ? QString("Number") 
                                           : QString::number(nSection);
}

// ----------------------------------------------------------------------
Qt::ItemFlags IntListModel::flags(const QModelIndex& index) const
{
    Qt::ItemFlags flags = QAbstractListModel::flags(index);
    return index.isValid() ? (flags | Qt::ItemIsEditable)
                           : flags;
}

// ----------------------------------------------------------------------
bool IntListModel::insertRows(int                nRow, 
                              int                nCount, 
                              const QModelIndex& parent/*=QModelIndex()*/
                             )
{
    if (parent.isValid()) {
        return false;
    }

    beginInsertRows(QModelIndex(), nRow, nRow + nCount - 1);
    for (int i = 0; i < nCount; ++i) {
        m_list.insert(nRow, 0);
    }
    endInsertRows();

    return true;
}

// ----------------------------------------------------------------------
bool IntListModel::removeRows(int                nRow, 
                              int                nCount, 
                              const QModelIndex& parent/*=QModelIndex()*/
                             )
{
    if (parent.isValid()) {
        return false;
    }

    beginRemoveRows(QModelIndex(), nRow, nRow + nCount - 1);
    for (int i = 0; i < nCount; ++i) {
        m_list.removeAt(nRow);
    }
    endRemoveRows();

    return true;
}
