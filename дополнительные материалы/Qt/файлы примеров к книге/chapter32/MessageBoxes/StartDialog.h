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

// ======================================================================
class StartDialog : public QWidget {
Q_OBJECT
public:
    StartDialog(QWidget* pwgt = 0) : QWidget(pwgt) 
    {
        QPushButton* pcmdMessage = new QPushButton("&Message");
        connect(pcmdMessage, SIGNAL(clicked()), SLOT(slotMessage()));

        QPushButton* pcmdInformation = new QPushButton("&Information");
        connect(pcmdInformation, SIGNAL(clicked()), SLOT(slotInformation()));

        QPushButton* pcmdWarning = new QPushButton("&Warning");
        connect(pcmdWarning, SIGNAL(clicked()), SLOT(slotWarning()));

        QPushButton* pcmdCritical = new QPushButton("&Critical");
        connect(pcmdCritical, SIGNAL(clicked()), SLOT(slotCritical()));

        QPushButton* pcmdAbout = new QPushButton("&About");
        connect(pcmdAbout, SIGNAL(clicked()), SLOT(slotAbout()));

        QPushButton* pcmdAboutQt = new QPushButton("A&boutQt");
        connect(pcmdAboutQt, SIGNAL(clicked()), SLOT(slotAboutQt()));

        QPushButton* pcmdError = new QPushButton("&Error");
        connect(pcmdError, SIGNAL(clicked()), SLOT(slotError()));

        QVBoxLayout* pvbxLayout = new QVBoxLayout;
        pvbxLayout->addWidget(pcmdMessage);
        pvbxLayout->addWidget(pcmdInformation);
        pvbxLayout->addWidget(pcmdWarning);
        pvbxLayout->addWidget(pcmdCritical);
        pvbxLayout->addWidget(pcmdAbout);
        pvbxLayout->addWidget(pcmdAboutQt);
        pvbxLayout->addWidget(pcmdError);

        setLayout(pvbxLayout);
    }

public slots:
    // ------------------------------------------------------------------
    void slotMessage()
    {
        QMessageBox* pmbx = 
            new QMessageBox("MessageBox", 
                            "<b>A</b> <i>Simple</i> <u>Message</u>", 
                            QMessageBox::Question,
                            QMessageBox::Yes, 
                            QMessageBox::No,
                            QMessageBox::Cancel | QMessageBox::Escape
                           );
        int n = pmbx->exec();
        delete pmbx;

        if (n == QMessageBox::Yes) {
            // Yes button was pressed
        }
    } 

    // ------------------------------------------------------------------
    void slotInformation()
    {
        QMessageBox::information(0, "Information", "Operation Complete");
    } 

    // ------------------------------------------------------------------
    void slotWarning()
    {
        int n = 
            QMessageBox::warning(0, 
                                "Warning" , 
                                "The text in the file has changed," 
                                "\n Do you want to save the changes?", 
                                "Yes", 
                                "No", 
                                QString(), 
                                0, 
                                1
                               );
        if (!n) {
            // Saving the changes!
        }
    } 

    // ------------------------------------------------------------------
    void slotCritical()
    {
        int n = 
        QMessageBox::critical(0, 
                              "Attention", 
                              "This operation will make your " 
                              "computer unusable, continue?", 
                              QMessageBox::Yes | QMessageBox::Default, 
                              QMessageBox::No, 
                              QMessageBox::Cancel | QMessageBox::Escape
                             );
        if (n == QMessageBox::Yes) {
            // Do it!
        }
    } 

    // ------------------------------------------------------------------
    void slotAbout()
    {
        QMessageBox::about(0, "About", "My Program Ver. 1.0");
    } 

    // ------------------------------------------------------------------
    void slotAboutQt()
    {
        QMessageBox::aboutQt(0);
    } 

    // ------------------------------------------------------------------
    void slotError()
    {
        (new QErrorMessage(this))->showMessage("Write Error");
    } 
};

