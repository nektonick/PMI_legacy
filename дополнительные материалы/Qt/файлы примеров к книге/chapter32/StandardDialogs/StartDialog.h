// ======================================================================
//  StartDialog.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QtWidgets>
#include <QtPrintSupport>

// ======================================================================
class StartDialog : public QWidget {
Q_OBJECT
public:
    StartDialog(QWidget* pwgt = 0) : QWidget(pwgt) 
    {
        QPushButton* pcmdOpenFile = new QPushButton("&OpenFile");
        connect(pcmdOpenFile, 
                SIGNAL(clicked()), 
                SLOT(slotOpenFileName())
               );

        QPushButton* pcmdDirectory = new QPushButton("&Directory");
        connect(pcmdDirectory, 
                SIGNAL(clicked()), 
                SLOT(slotExistingDirectory())
               );

        QPushButton* pcmdColor = new QPushButton("&Color");
        connect(pcmdColor, SIGNAL(clicked()), SLOT(slotColor()));

        QPushButton* pcmdPrinter = new QPushButton("&Printer");
        connect(pcmdPrinter, SIGNAL(clicked()), SLOT(slotPrinter()));

        QPushButton* pcmdFont = new QPushButton("&Font");
        connect(pcmdFont, SIGNAL(clicked()), SLOT(slotFont()));

        QPushButton* pcmdInput = new QPushButton("&Input");
        connect(pcmdInput, SIGNAL(clicked()), SLOT(slotInput()));

        QPushButton* pcmdProgress = new QPushButton("P&rogress");
        connect(pcmdProgress, SIGNAL(clicked()), SLOT(slotProgress()));

        QVBoxLayout* pvbxLayout = new QVBoxLayout;
        pvbxLayout->addWidget(pcmdOpenFile);
        pvbxLayout->addWidget(pcmdDirectory);
        pvbxLayout->addWidget(pcmdColor);
        pvbxLayout->addWidget(pcmdPrinter);
        pvbxLayout->addWidget(pcmdFont);
        pvbxLayout->addWidget(pcmdInput);
        pvbxLayout->addWidget(pcmdProgress);

        setLayout(pvbxLayout);
    }

public slots:
    // ------------------------------------------------------------------
    void slotOpenFileName()
    {
        QString str = 
          QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.cpp *.h");
    } 

    // ------------------------------------------------------------------
    void slotExistingDirectory()
    {
        QString str = 
            QFileDialog::getExistingDirectory(0, "Directory Dialog", "");
    } 

    // ------------------------------------------------------------------
    void slotPrinter()
    {
        QPrinter printer;
        QPrintDialog* pPrintDialog = new QPrintDialog(&printer);
        if (pPrintDialog->exec() == QDialog::Accepted) {
            // Print
        }
        delete pPrintDialog;
    } 

    // ------------------------------------------------------------------
    void slotColor()
    {
        QColor color = QColorDialog::getColor(Qt::blue);
        qDebug() << color;
    } 

    // ------------------------------------------------------------------
    void slotFont()
    {
        bool bOk;
        QFont font = QFontDialog::getFont(&bOk);
        if (!bOk) {
            //Cancel was pressed
        }
    } 

    // ------------------------------------------------------------------
    void slotInput()
    {
        bool bOk;
        QString str = QInputDialog::getText(0, 
                                            "Input", 
                                            "Name:", 
                                            QLineEdit::Normal, 
                                            "Tarja", 
                                            &bOk
                                           );
        if (!bOk) {
            // Cancel was pressed
        }
    } 
 
    // ------------------------------------------------------------------
    void slotProgress()
    {
        int              n    = 200000; 
        QProgressDialog* pprd = 
           new QProgressDialog("Processing the data...", "&Cancel", 0, n);

        pprd->setMinimumDuration(0);
        pprd->setWindowTitle("Please Wait");

        for (int i = 0; i < n; ++i) {
            pprd->setValue(i);
            qApp->processEvents();
            if (pprd->wasCanceled()) {
                break;
            }
        }
        pprd->setValue(n);
        delete pprd;
    }

};

