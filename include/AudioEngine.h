#ifndef AUDIOENGINE_H
#define AUDIOENGINE_H

#include <QObject>
#include <QMediaPlayer> // 包含QMediaPlayer的头文件
#include <QUrl>         // 包含QUrl的头文件

class AudioEngine : public QObject {
    Q_OBJECT

public:
    explicit AudioEngine(QObject *parent = nullptr);

public slots: // 这些函数可以被外部调用，作为“槽”来接收信号
    void play(const QUrl &url);
    void togglePlayback();
    void stop();
    void setVolume(int volume); // 音量范围 0-100
    void setPosition(int position); // 设置播放位置

signals: // 这些是引擎发出的信号，用于通知UI更新
    void positionChanged(qint64 position);
    void durationChanged(qint64 duration);
    void playbackStateChanged(QMediaPlayer::PlaybackState newState);

private:
    QMediaPlayer *m_player;
    QAudioOutput *m_audioOutput;
};

#endif // AUDIOENGINE_H