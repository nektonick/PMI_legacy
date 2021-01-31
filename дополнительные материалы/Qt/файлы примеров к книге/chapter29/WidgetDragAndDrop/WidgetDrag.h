// ======================================================================
//  WidgetDrag.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QDrag>

// ======================================================================
class WidgetMimeData : public QMimeData {
private:
    QWidget* m_pwgt;

public:
    WidgetMimeData() : QMimeData()
    {
    }

    virtual ~WidgetMimeData()
    {
    }

    static QString mimeType()
    {
        return "application/widget";
    }    

    void setWidget(QWidget* pwgt)
    {
        m_pwgt = pwgt;
        setData(mimeType(), QByteArray());
    }

    QWidget* widget() const
    {
        return m_pwgt;
    }
};

// ======================================================================
class WidgetDrag : public QDrag {
public:
    WidgetDrag(QWidget* pwgtDragSource = 0) : QDrag(pwgtDragSource)
    {
    }

    void setWidget(QWidget* pwgt)
    {
         WidgetMimeData* pmd = new WidgetMimeData;
         pmd->setWidget(pwgt);
         setMimeData(pmd);
    }
};

