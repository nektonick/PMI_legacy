// ======================================================================
//  script.js --
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

function showFiles()
{
    var files = JSTools.dirEntryList(".", "*");
    JSTools.alert(files.join("\n"));    
}

JSTools.print("JSTools test!");
cmdFiles.clicked.connect(showFiles);
cmdQuit.clicked.connect(function(){JSTools.quitApplication()});
