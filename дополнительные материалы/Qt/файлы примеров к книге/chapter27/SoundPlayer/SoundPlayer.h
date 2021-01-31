// ======================================================================
//  SoundPlayer.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once
#include <QWidget>
#include <QMediaPlayer>

class QPushButton;
class QSlider;
class QLabel;
class QVBoxLayout;

// ======================================================================
class SoundPlayer : public QWidget {
    Q_OBJECT
protected:
    QMediaPlayer* m_pmp;
    QVBoxLayout*  m_pvbxMainLayout;

private:
    QPushButton*  m_pcmdPlay;
    QPushButton*  m_pcmdStop;
    QSlider*      m_psldPosition;
    QLabel*       m_plblCurrent;
    QLabel*       m_plblRemain;

    QString msecsToString(qint64 n);

public:
    SoundPlayer(QWidget* pwgt = 0);

private slots:
    void slotOpen             (                   );
    void slotPlay             (                   );
    void slotSetSliderPosition(qint64             );
    void slotSetMediaPosition (int                );
    void slotSetDuration      (qint64             );
    void slotStatusChanged    (QMediaPlayer::State);
};
