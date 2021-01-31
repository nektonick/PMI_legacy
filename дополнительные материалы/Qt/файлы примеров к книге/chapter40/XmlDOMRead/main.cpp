// ======================================================================
//  main.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QtXml>

// ----------------------------------------------------------------------
void traverseNode(const QDomNode& node)
{
   QDomNode domNode = node.firstChild();
   while(!domNode.isNull()) {
       if(domNode.isElement()) {
          QDomElement domElement = domNode.toElement();
          if(!domElement.isNull()) {
              if(domElement.tagName() == "contact") {
                  qDebug() << "Attr: "
                           << domElement.attribute("number", "");
              }
              else {
                  qDebug() << "TagName: " << domElement.tagName() 
                           << "\tText: " << domElement.text(); 
             }
          }
       }
       traverseNode(domNode);
       domNode = domNode.nextSibling();
    }
}

// ----------------------------------------------------------------------
int main()
{
    QDomDocument domDoc;
    QFile        file("addressbook.xml");

    if(file.open(QIODevice::ReadOnly)) {
        if(domDoc.setContent(&file)) {
            QDomElement domElement= domDoc.documentElement();
            traverseNode(domElement);
        }
        file.close();
    }

    return 0;
}
