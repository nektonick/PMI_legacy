// ======================================================================
//  main.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QtWidgets>

// ======================================================================
class TableModel : public QAbstractTableModel {
private:
    int                          m_nRows;
    int                          m_nColumns;
    QHash<QModelIndex, QVariant> m_hash;

public:
    TableModel(int nRows, int nColumns, QObject* pobj = 0)
        : QAbstractTableModel(pobj)
        , m_nRows(nRows)
        , m_nColumns(nColumns) 
    { 
    }
   
    QVariant data(const QModelIndex& index, int nRole) const
    {
        if (!index.isValid()) {
            return QVariant();
        }
        QString str = 
           QString("%1,%2").arg(index.row() + 1).arg(index.column() + 1);
        return (nRole == Qt::DisplayRole || nRole == Qt::EditRole) 
               ? m_hash.value(index, QVariant(str)) 
               : QVariant();
    }
    
    bool setData(const QModelIndex& index, 
                 const QVariant&    value, 
                 int                nRole
                )
    {
        if (index.isValid() && nRole == Qt::EditRole) {
            m_hash[index] = value;
            emit dataChanged(index, index);
            return true;
        }
        return false;
    }

    int rowCount(const QModelIndex&) const 
    { 
        return m_nRows; 
    }

    int columnCount(const QModelIndex&) const 
    { 
        return m_nColumns; 
    }

    Qt::ItemFlags flags(const QModelIndex& index) const
    {
        Qt::ItemFlags flags = QAbstractTableModel::flags(index);
        return index.isValid() ? (flags | Qt::ItemIsEditable)
                               : flags;
    }
};

// ----------------------------------------------------------------------
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    TableModel model(200, 200);

    QTableView tableView;
    tableView.setModel(&model);
    tableView.show();

    return app.exec();
}
