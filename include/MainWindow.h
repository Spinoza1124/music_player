#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "AudioEngine.h" // 包含我们的引擎头文件
#include <QMediaPlayer>  // 为了使用 QMediaPlayer::PlaybackState 枚举

// 假设你使用了Qt Designer, 它会自动生成Ui::MainWindow
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // --- 槽：用来响应UI控件的动作 ---
    void on_openFileButton_clicked();
    void on_playPauseButton_clicked();
    void on_stopButton_clicked();
    void on_volumeSlider_valueChanged(int value);
    void on_progressSlider_sliderMoved(int position);

    // --- 槽：用来响应AudioEngine发出的信号 ---
    void updatePosition(qint64 position);
    void updateDuration(qint64 duration);
    void updatePlaybackState(QMediaPlayer::PlaybackState newState);

private:
    Ui::MainWindow *ui;         // 指向UI界面的指针
    AudioEngine *m_audioEngine; // 指向音频引擎的指针
};

#endif // MAINWINDOW_H