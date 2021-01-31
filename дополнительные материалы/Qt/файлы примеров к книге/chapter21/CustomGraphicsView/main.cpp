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
#include "MyView.h"

// ======================================================================
class SimpleItem : public QGraphicsItem {
private:
    enum {nPenWidth = 3};

public:
    virtual QRectF boundingRect() const
    {
        QPointF ptPosition(-10 - nPenWidth, -10 - nPenWidth);
        QSizeF  size(20 + nPenWidth * 2, 20 + nPenWidth * 2);
        return QRectF(ptPosition, size);
    }

    virtual void paint(QPainter* ppainter, 
                       const QStyleOptionGraphicsItem*,
                       QWidget*
                      )
    {
        ppainter->save();
        ppainter->setPen(QPen(Qt::blue, nPenWidth));
        ppainter->drawEllipse(-10, -10, 20, 20);
        ppainter->restore();
    }

    virtual void mousePressEvent(QGraphicsSceneMouseEvent* pe) 
    {
        
        QApplication::setOverrideCursor(Qt::PointingHandCursor);
        QGraphicsItem::mousePressEvent(pe);
    }

    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* pe) 
    {
        QApplication::restoreOverrideCursor();
        QGraphicsItem::mouseReleaseEvent(pe);
    }
};

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication   app(argc, argv);
    QWidget        wgt;
    QGraphicsScene scene(QRectF(-100, -100, 640, 480));

    MyView*      pView           = new MyView(&scene);
    QPushButton* pcmdZoomIn      = new QPushButton("&Zoom In");
    QPushButton* pcmdZoomOut     = new QPushButton("Z&oom Out");
    QPushButton* pcmdRotateLeft  = new QPushButton("&Rotate Left");
    QPushButton* pcmdRotateRight = new QPushButton("Ro&tate Right");

    pView->setRenderHint(QPainter::Antialiasing, true);

    SimpleItem*  pSimpleItem = new SimpleItem;
    scene.addItem(pSimpleItem);
    pSimpleItem->setPos(0, 0);
    pSimpleItem->setFlags(QGraphicsItem::ItemIsMovable);

    QGraphicsPixmapItem* pPixmapItem = 
        scene.addPixmap(QPixmap(":/haus2.jpg"));    
    pPixmapItem->setParentItem(pSimpleItem);
    pPixmapItem->setFlags(QGraphicsItem::ItemIsMovable);

    QObject::connect(pcmdZoomIn, SIGNAL(clicked()), 
                     pView,      SLOT(slotZoomIn())
                    );
    QObject::connect(pcmdZoomOut, SIGNAL(clicked()), 
                     pView,       SLOT(slotZoomOut())
                    );
    QObject::connect(pcmdRotateLeft, SIGNAL(clicked()), 
                     pView,          SLOT(slotRotateLeft())
                    );
    QObject::connect(pcmdRotateRight, SIGNAL(clicked()), 
                     pView,           SLOT(slotRotateRight())
                    );

    //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout;    
    pvbxLayout->addWidget(pView);
    pvbxLayout->addWidget(pcmdZoomIn);
    pvbxLayout->addWidget(pcmdZoomOut);
    pvbxLayout->addWidget(pcmdRotateLeft);
    pvbxLayout->addWidget(pcmdRotateRight);
    wgt.setLayout(pvbxLayout);

    wgt.show();
  
    return app.exec();
} 
