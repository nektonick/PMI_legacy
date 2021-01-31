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
class SimpleDelegate : public QStyledItemDelegate {
public:
    SimpleDelegate(QObject* pobj = 0) : QStyledItemDelegate(pobj) 
    {
    }
    
    void paint(QPainter*                   pPainter,
               const QStyleOptionViewItem& option,
               const QModelIndex&          index
              ) const
    {
        if (option.state & QStyle::State_MouseOver) {
            QRect           rect = option.rect;
            QLinearGradient gradient(0, 0, rect.width(), rect.height());

            gradient.setColorAt(0, Qt::white);
            gradient.setColorAt(0.5, Qt::blue);
            gradient.setColorAt(1, Qt::green);
            pPainter->setBrush(gradient);
            pPainter->drawRect(rect);
        }
        QStyledItemDelegate::paint(pPainter, option, index);
    }

    QSize sizeHint(const QStyleOptionViewItem& option,
                   const QModelIndex&/*index*/
                  ) const
    {
        return QSize(option.rect.width(), 55);
    }
};

// ----------------------------------------------------------------------
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QStringListModel model;
    model.setStringList(QStringList() << "Item1" << "Item2" << "Item3");

    QListView listView;
    listView.setModel(&model);
    listView.setItemDelegate(new SimpleDelegate(&listView));
    listView.viewport()->setAttribute(Qt::WA_Hover);
    listView.show();

    return app.exec();
}
