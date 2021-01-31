// ======================================================================
//  Calculator.h - 
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QtGui>
#include <QtWebEngineWidgets>
#include "WebBrowser.h"

// ----------------------------------------------------------------------
WebBrowser::WebBrowser(QWidget* wgt/*=0*/) : QWidget(wgt)
{
    m_ptxt        = new QLineEdit("http://www.bhv.ru");
    m_pwv         = new QWebEngineView; 
    m_pcmdBack    = new QPushButton("<");
    m_pcmdForward = new QPushButton(">");
 
    m_pcmdBack->setEnabled(false);
    m_pcmdForward->setEnabled(false);
    
    QProgressBar* pprb        = new QProgressBar;
    QPushButton*  pcmdGo      = new QPushButton("&Go");
    QPushButton*  pcmdStop    = new QPushButton("&Stop");
    QPushButton*  pcmdRefresh = new QPushButton("&Refresh");

    connect(pcmdGo, SIGNAL(clicked()), SLOT(slotGo()));
    connect(m_ptxt, SIGNAL(returnPressed()), SLOT(slotGo()));
    connect(m_pcmdBack, SIGNAL(clicked()), m_pwv, SLOT(back()));
    connect(m_pcmdForward, SIGNAL(clicked()), m_pwv, SLOT(forward()));
    connect(pcmdRefresh, SIGNAL(clicked()), m_pwv, SLOT(reload()));
    connect(pcmdStop, SIGNAL(clicked()), m_pwv, SLOT(stop()));
    connect(m_pwv, SIGNAL(loadProgress(int)), pprb, SLOT(setValue(int)));
    connect(m_pwv, SIGNAL(loadFinished(bool)), SLOT(slotFinished(bool)));

    //Layout setup
    QHBoxLayout* phbx = new QHBoxLayout;    
    phbx->addWidget(m_pcmdBack);
    phbx->addWidget(m_pcmdForward);
    phbx->addWidget(pcmdStop);
    phbx->addWidget(pcmdRefresh);
    phbx->addWidget(m_ptxt);
    phbx->addWidget(pcmdGo);

    QVBoxLayout* playout = new QVBoxLayout;
    playout->addLayout(phbx);
    playout->addWidget(m_pwv);
    playout->addWidget(pprb);
    setLayout(playout);

    slotGo();
}

// ----------------------------------------------------------------------
void WebBrowser::slotGo()
{
    if (!m_ptxt->text().startsWith("ftp://") 
        && !m_ptxt->text().startsWith("http://")
        && !m_ptxt->text().startsWith("gopher://")
       ) {
        m_ptxt->setText("http://" + m_ptxt->text());
    }
    m_pwv->load(QUrl(m_ptxt->text()));
}

// ----------------------------------------------------------------------
void WebBrowser::slotFinished(bool bOk)
{    
    if (!bOk) {
        m_pwv->setHtml("<CENTER>An error has occured"
                       " while loading the web page</CENTER>"
                      );
    }

    m_ptxt->setText(m_pwv->url().toString());

    m_pcmdBack->setEnabled(m_pwv->page()->history()->canGoBack());
    m_pcmdForward->setEnabled(m_pwv->page()->history()->canGoForward());    
}

