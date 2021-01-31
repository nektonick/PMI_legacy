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
class DrawTextWidget : public QWidget {
protected:
    virtual void paintEvent(QPaintEvent*)
    {
        QPainter painter(this);
        QRect    r = rect();
        painter.setFont(QFont("Times", 50, QFont::Normal));
        painter.drawRect(r); 
        painter.drawText(r, Qt::AlignCenter | Qt::TextWordWrap, "Draw Text");
    }

public:
    DrawTextWidget(QWidget* pwgt = 0) : QWidget(pwgt)
    {
    }
};


// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    DrawTextWidget dtw;

    dtw.resize(200, 150);
    dtw.show();

    return app.exec();
}
