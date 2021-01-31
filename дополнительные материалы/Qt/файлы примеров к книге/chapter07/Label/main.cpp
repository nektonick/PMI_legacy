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

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QLabel lbl("<H1><CENTER>QLabel - HTML Demo</CENTER></H1>"
               "<H2><CENTER>Image</CENTER><H2>"
               "<CENTER><IMG BORDER=\"0\" SRC=\":/Balalaika.png\"></CENTER>"
               "<H2><CENTER>List</CENTER><H2>"
               "<OL><LI>One</LI>"
               "    <LI>Two</LI>"
               "    <LI>Three</LI>"
               "</OL>"
               "<H2><CENTER>Font Style</CENTER><H2>"
               "<CENTER><FONT COLOR=RED>"
               "    <B>Bold</B>, <I>Italic</I>, <U>Underline</U>"
               "</FONT></CENTER>"
               "<H2><CENTER>Table</CENTER></H2>"
               "<CENTER> <TABLE>"
               "    <TR BGCOLOR=#ff00ff>"
               "        <TD>1,1</TD><TD>1,2</TD><TD>1,3</TD><TD>1,4</TD>"
               "    </TR>"
               "    <TR BGCOLOR=YELLOW>"
               "        <TD>2,1</TD><TD>2,2</TD><TD>2,3</TD><TD>2,4</TD>"
               "    </TR>"
               "    <TR BGCOLOR=#00f000>"
               "        <TD>3,1</TD><TD>3,2</TD><TD>3,3</TD><TD>3,4</TD>"
               "    </TR>"
               "</TABLE> </CENTER>"
              );

    lbl.show();

    return app.exec();
}
