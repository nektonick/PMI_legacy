// ======================================================================
//  VideoPlayer.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once
#include "../SoundPlayer/SoundPlayer.h"

// ======================================================================
class VideoPlayer : public SoundPlayer {
    Q_OBJECT

public:
    VideoPlayer(QWidget* pwgt = 0);

private slots:
    void slotStateChanged(QMediaPlayer::State);
};
