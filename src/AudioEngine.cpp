#include "AudioEngine.h"
#include <QAudioOutput>

AudioEngine::AudioEngine(QObject *parent) : QObject(parent) {
    m_player = new QMediaPlayer(this);
    m_audioOutput = new QAudioOutput(this);
    m_player->setAudioOutput(m_audioOutput);

    // 关键：将QMediaPlayer内部的信号，连接到我们自己定义的信号上
    // 这样，外部世界只需要和AudioEngine打交道，而不用关心具体的实现是QMediaPlayer
    connect(m_player, &QMediaPlayer::positionChanged, this, &AudioEngine::positionChanged);
    connect(m_player, &QMediaPlayer::durationChanged, this, &AudioEngine::durationChanged);
    connect(m_player, &QMediaPlayer::playbackStateChanged, this, &AudioEngine::playbackStateChanged);
}

void AudioEngine::play(const QUrl &url) {
    m_player->setSource(url);
    m_player->play();
}

void AudioEngine::togglePlayback() {
    if (m_player->playbackState() == QMediaPlayer::PlayingState) {
        m_player->pause();
    } else {
        m_player->play();
    }
}

void AudioEngine::stop() {
    m_player->stop();
}

void AudioEngine::setVolume(int volume) {
    // QAudioOutput的音量是浮点数 0.0 到 1.0
    m_audioOutput->setVolume(static_cast<float>(volume) / 100.0f);
}

void AudioEngine::setPosition(int position) {
    m_player->setPosition(position);
}