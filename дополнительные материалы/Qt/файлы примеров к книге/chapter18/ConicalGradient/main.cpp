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
class ConicalGradientWidget : public QWidget {
protected:
    virtual void paintEvent(QPaintEvent*)
    {
        QPainter         painter(this);
        QConicalGradient gradient(width() / 2, height() / 2, 0);

        gradient.setColorAt(0, Qt::red);
        gradient.setColorAt(0.4, Qt::green);
        gradient.setColorAt(0.8, Qt::blue);
        gradient.setColorAt(1, Qt::red);
        painter.setBrush(gradient);
        painter.drawRect(rect());
    }

public:
    ConicalGradientWidget(QWidget* pwgt = 0) : QWidget(pwgt)
    {
    }
};

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    ConicalGradientWidget wgt;

    wgt.show();

    return app.exec();
}
