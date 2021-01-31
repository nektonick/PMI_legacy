// ======================================================================
//  dynlib.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QString>

#ifdef Q_OS_WIN
#define MY_EXPORT __declspec(dllexport) 
#else
#define MY_EXPORT
#endif

extern "C" MY_EXPORT QString oddUpper(const QString& str);
