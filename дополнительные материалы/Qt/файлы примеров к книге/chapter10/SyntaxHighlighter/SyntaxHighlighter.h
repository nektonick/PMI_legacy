// ======================================================================
//  SyntaxHighlighter.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QSyntaxHighlighter>

class QTextDocument;

// ======================================================================
class SyntaxHighlighter: public QSyntaxHighlighter {
Q_OBJECT
private:
    QStringList m_lstKeywords;

protected:
    enum { NormalState = -1, InsideCStyleComment, InsideCString };

    virtual void highlightBlock(const QString&);

    QString getKeyword(int i, const QString& str) const;

public:
    SyntaxHighlighter(QTextDocument* parent = 0);
};
