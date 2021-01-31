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
class LinearGradientWidget : public QWidget {
protected:
    virtual void paintEvent(QPaintEvent*)
    {
        QPainter        painter(this);
        QLinearGradient gradient(0, 0, width(), height());

        gradient.setColorAt(0, Qt::red);
        gradient.setColorAt(0.5, Qt::green);
        gradient.setColorAt(1, Qt::blue);
        painter.setBrush(gradient);
        painter.drawRect(rect());
    }

public:
    LinearGradientWidget(QWidget* pwgt = 0) : QWidget(pwgt)
    {
    }
};

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    LinearGradientWidget wgt;

    wgt.show();

    return app.exec();
}
