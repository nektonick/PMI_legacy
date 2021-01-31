// ======================================================================
//  IntListModel.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QAbstractListModel>

// ======================================================================
class IntListModel : public QAbstractListModel {
Q_OBJECT
private:
    QList<int> m_list;

public:
    IntListModel(const QList<int>& list, QObject* pobj = 0); 

    QVariant data(const QModelIndex& index, int nRole) const;

    bool setData(const QModelIndex& index, 
                 const QVariant&    value, 
                 int                nRole
                );

    int rowCount(const QModelIndex& parent = QModelIndex()) const;

    QVariant headerData(int             nSection, 
                        Qt::Orientation orientation, 
                        int             nRole = Qt::DisplayRole
                       ) const;

    Qt::ItemFlags flags(const QModelIndex &index) const;

    bool insertRows(int                nRow, 
                    int                nCount, 
                    const QModelIndex& parent = QModelIndex()
                   );

    bool removeRows(int                nRow, 
                    int                nCount, 
                    const QModelIndex& parent = QModelIndex()
                   );

};
