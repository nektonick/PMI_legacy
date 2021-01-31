// ======================================================================
//  FileFinder.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QtWidgets>
#include "FileFinder.h"

// ----------------------------------------------------------------------
FileFinder::FileFinder(QWidget* pwgt/*= 0*/) : QWidget(pwgt) 
{
    m_ptxtDir    = new QLineEdit(QCoreApplication::applicationDirPath());
    m_ptxtMask   = new QLineEdit("*");
    m_ptxtResult = new QTextEdit;

    QLabel*      plblDir  = new QLabel("&Directory");
    QLabel*      plblMask = new QLabel("&Mask");
    QPushButton* pcmdDir  = new QPushButton(QPixmap(":/fileopen.png"), "");
    QPushButton* pcmdFind = new QPushButton("&Find");

    connect(pcmdDir, SIGNAL(clicked()), SLOT(slotBrowse()));
    connect(pcmdFind, SIGNAL(clicked()), SLOT(slotFind()));

    plblDir->setBuddy(m_ptxtDir);
    plblMask->setBuddy(m_ptxtMask);

    //Layout setup
    QGridLayout* pgrdLayout = new QGridLayout;
    pgrdLayout->setContentsMargins(5, 5, 5, 5);
    pgrdLayout->setSpacing(15);
    pgrdLayout->addWidget(plblDir, 0, 0);
    pgrdLayout->addWidget(plblMask, 1, 0);
    pgrdLayout->addWidget(m_ptxtDir, 0, 1);
    pgrdLayout->addWidget(m_ptxtMask, 1, 1);
    pgrdLayout->addWidget(pcmdDir, 0, 2);
    pgrdLayout->addWidget(pcmdFind, 1, 2);
    pgrdLayout->addWidget(m_ptxtResult, 2, 0, 1, 3);
    setLayout(pgrdLayout);
}

// ----------------------------------------------------------------------
void FileFinder::slotBrowse()
{
    QString str = QFileDialog::getExistingDirectory(0, 
                                                    "Select a Directory", 
                                                    m_ptxtDir->text()
                                                   );

    if (!str.isEmpty()) {
        m_ptxtDir->setText(str);
    }
}

// ----------------------------------------------------------------------
void FileFinder::slotFind()
{
    start(QDir(m_ptxtDir->text()));
}

// ----------------------------------------------------------------------
void FileFinder::start(const QDir& dir)
{
    QApplication::processEvents();

    QStringList listFiles = 
        dir.entryList(m_ptxtMask->text().split(" "), QDir::Files);
    
    foreach (QString file, listFiles) {
        m_ptxtResult->append(dir.absoluteFilePath(file));
    }

    QStringList listDir = dir.entryList(QDir::Dirs);
    foreach (QString subdir, listDir) {
        if (subdir == "." || subdir == "..") {
            continue;
        }
        start(QDir(dir.absoluteFilePath(subdir)));
    }
}
