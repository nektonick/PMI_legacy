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
class ElidedText : public QWidget {
protected:
    virtual void paintEvent(QPaintEvent*)
    {
        QString  str = "This is a long text. Please, resize the window";
        QString  strElided = 
            fontMetrics().elidedText(str, Qt::ElideMiddle, width());
        QPainter painter(this);
        painter.drawText(rect(), strElided);
    }

public:
    ElidedText(QWidget* pwgt = 0) : QWidget(pwgt)
    {
    }    
};

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    ElidedText   et;
    et.resize(200, 20);
    et.show();

    return app.exec();
}
