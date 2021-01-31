// ======================================================================
//  MDIProgram.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QtWidgets>
#include "MDIProgram.h"
#include "DocWindow.h"

// ----------------------------------------------------------------------
MDIProgram::MDIProgram(QWidget* pwgt/*=0*/) : QMainWindow(pwgt)
{
    QAction* pactNew = new QAction("New File", 0);
    pactNew->setText("&New");
    pactNew->setShortcut(QKeySequence("CTRL+N"));
    pactNew->setToolTip("New Document");
    pactNew->setStatusTip("Create a new file");
    pactNew->setWhatsThis("Create a new file");
    pactNew->setIcon(QPixmap(":/filenew.png"));
    connect(pactNew, SIGNAL(triggered()), SLOT(slotNewDoc()));

    QAction* pactOpen = new QAction("Open File", 0);
    pactOpen->setText("&Open...");
    pactOpen->setShortcut(QKeySequence("CTRL+O"));
    pactOpen->setToolTip("Open Document");
    pactOpen->setStatusTip("Open an existing file");
    pactOpen->setWhatsThis("Open an existing file");
    pactOpen->setIcon(QPixmap(":/fileopen.png"));
    connect(pactOpen, SIGNAL(triggered()), SLOT(slotLoad()));

    QAction* pactSave = new QAction("Save File", 0);
    pactSave->setText("&Save");
    pactSave->setShortcut(QKeySequence("CTRL+S"));
    pactSave->setToolTip("Save Document");
    pactSave->setStatusTip("Save the file to disk");
    pactSave->setWhatsThis("Save the file to disk");
    pactSave->setIcon(QPixmap(":/filesave.png"));
    connect(pactSave, SIGNAL(triggered()), SLOT(slotSave()));

    QToolBar* ptbFile = new QToolBar("File Operations");
    ptbFile->addAction(pactNew);
    ptbFile->addAction(pactOpen);
    ptbFile->addAction(pactSave);
    addToolBar(Qt::TopToolBarArea, ptbFile);

    QMenu* pmnuFile = new QMenu("&File");
    pmnuFile->addAction(pactNew);
    pmnuFile->addAction(pactOpen);
    pmnuFile->addAction(pactSave);
    pmnuFile->addAction("Save &As...", this, SLOT(slotSaveAs()));
    pmnuFile->addSeparator();
    pmnuFile->addAction("&Quit", 
                        qApp, 
                        SLOT(closeAllWindows()), 
                        QKeySequence("CTRL+Q")
                       );
    menuBar()->addMenu(pmnuFile);

    m_pmnuWindows = new QMenu("&Windows");
    menuBar()->addMenu(m_pmnuWindows);
    connect(m_pmnuWindows, SIGNAL(aboutToShow()), SLOT(slotWindows()));
    menuBar()->addSeparator();

    QMenu* pmnuHelp = new QMenu("&Help");
    pmnuHelp->addAction("&About", this, SLOT(slotAbout()), Qt::Key_F1);
    menuBar()->addMenu(pmnuHelp);

    m_pma = new QMdiArea;
    m_pma->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    m_pma->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setCentralWidget(m_pma);

    m_psigMapper = new QSignalMapper(this);
    connect(m_psigMapper, 
            SIGNAL(mapped(QWidget*)), 
            this, 
            SLOT(slotSetActiveSubWindow(QWidget*))
           );

    statusBar()->showMessage("Ready", 3000);
}

// ----------------------------------------------------------------------
void MDIProgram::slotNewDoc()
{
    createNewDoc()->show();
}

// ----------------------------------------------------------------------
DocWindow* MDIProgram::createNewDoc()
{
    DocWindow* pdoc = new DocWindow;
    m_pma->addSubWindow(pdoc);
    pdoc->setAttribute(Qt::WA_DeleteOnClose);
    pdoc->setWindowTitle("Unnamed Document");
    pdoc->setWindowIcon(QPixmap(":/filenew.png"));
    connect(pdoc, 
            SIGNAL(changeWindowTitle(const QString&)), 
            SLOT(slotChangeWindowTitle(const QString&))
           );

    return pdoc;
}

// ----------------------------------------------------------------------
void MDIProgram::slotChangeWindowTitle(const QString& str)
{
    qobject_cast<DocWindow*>(sender())->setWindowTitle(str);
}

// ----------------------------------------------------------------------
void MDIProgram::slotLoad()
{
    DocWindow* pdoc = createNewDoc();
    pdoc->slotLoad();
    pdoc->show();
}

// ----------------------------------------------------------------------
void MDIProgram::slotSave()
{                                                                   
    DocWindow* pdoc = qobject_cast<DocWindow*>(m_pma->activeSubWindow());
    if (pdoc) {
        pdoc->slotSave();
    }
}

// ----------------------------------------------------------------------
void MDIProgram::slotSaveAs()
{
    DocWindow* pdoc = qobject_cast<DocWindow*>(m_pma->activeSubWindow());
    if (pdoc) {
       pdoc->slotSaveAs();
    }
}

// ----------------------------------------------------------------------
void MDIProgram::slotAbout()
{
    QMessageBox::about(this, "Application", "MDI Example");
}

// ----------------------------------------------------------------------
void MDIProgram::slotWindows()
{
    m_pmnuWindows->clear();

    QAction* pact = m_pmnuWindows->addAction("&Cascade", 
                                             m_pma, 
                                             SLOT(cascadeSubWindows())
                                            );
    pact->setEnabled(!m_pma->subWindowList().isEmpty());

    pact = m_pmnuWindows->addAction("&Tile", 
                                    m_pma, 
                                    SLOT(tileSubWindows())
                                   );
    pact->setEnabled(!m_pma->subWindowList().isEmpty());

    m_pmnuWindows->addSeparator();

    QList<QMdiSubWindow*> listDoc = m_pma->subWindowList();
    for (int i = 0; i < listDoc.size(); ++i) {
        pact = m_pmnuWindows->addAction(listDoc.at(i)->windowTitle());
        pact->setCheckable(true);
        pact->setChecked(m_pma->activeSubWindow() == listDoc.at(i));
        connect(pact, SIGNAL(triggered()), m_psigMapper, SLOT(map()));
        m_psigMapper->setMapping(pact, listDoc.at(i));
    }
}

// ----------------------------------------------------------------------
void MDIProgram::slotSetActiveSubWindow(QWidget* pwgt)
{
    if (pwgt) {
        m_pma->setActiveSubWindow(qobject_cast<QMdiSubWindow*>(pwgt));
    }
}
