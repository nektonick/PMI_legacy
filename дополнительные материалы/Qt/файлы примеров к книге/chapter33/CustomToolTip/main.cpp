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
class MyWidget : public QWidget {
private:
    QLabel* m_plblToolTip;

protected:
    virtual bool event(QEvent* pe)
    {
        if (pe->type() == QEvent::ToolTip) {
            QHelpEvent* peHelp = static_cast<QHelpEvent*>(pe);
            m_plblToolTip->move(peHelp->globalPos());
            m_plblToolTip->setText(toolTip());
            m_plblToolTip->show();
            QTimer::singleShot(3000, m_plblToolTip, SLOT(hide()));
            
            return true;
        }

        return QWidget::event(pe);
    } 

public:
    MyWidget(QWidget* pwgt = 0) : QWidget(pwgt)
    {
        m_plblToolTip = new QLabel;
        m_plblToolTip->setWindowFlags(Qt::ToolTip);
    }
};

// ----------------------------------------------------------------------
int main(int argc, char** argv) 
{
    QApplication app(argc, argv);

    MyWidget mw;  
    mw.setFixedSize(70, 70);
    mw.setToolTip("<H1>My Tool Tip</H1>");
    mw.show();

    return app.exec();
}

