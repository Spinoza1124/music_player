#include "MainWindow.h"
#include "ui_MainWindow.h" // 包含Qt Designer生成的头文件
#include <QFileDialog>
#include <QCoreApplication> // 确保包含了这两个头文件
#include <QDir>
#include <QFile>
#include <QDebug>           // 方便打印调试信息

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this); // 初始化UI

    // 1. 创建音频引擎实例
    m_audioEngine = new AudioEngine(this);

    // 2. 连接UI控件的信号到MainWindow的槽
    //    这里使用了手动的connect，比Qt自动连接更清晰地展示了原理
    connect(ui->openFileButton, &QPushButton::clicked, this, &MainWindow::on_openFileButton_clicked);
    connect(ui->playPauseButton, &QPushButton::clicked, this, &MainWindow::on_playPauseButton_clicked);
    connect(ui->stopButton, &QPushButton::clicked, this, &MainWindow::on_stopButton_clicked);
    connect(ui->volumeSlider, &QSlider::valueChanged, this, &MainWindow::on_volumeSlider_valueChanged);
    connect(ui->progressSlider, &QSlider::sliderMoved, this, &MainWindow::on_progressSlider_sliderMoved);

    // 3. 连接音频引擎的信号到MainWindow的槽
    connect(m_audioEngine, &AudioEngine::positionChanged, this, &MainWindow::updatePosition);
    connect(m_audioEngine, &AudioEngine::durationChanged, this, &MainWindow::updateDuration);
    connect(m_audioEngine, &AudioEngine::playbackStateChanged, this, &MainWindow::updatePlaybackState);
    
    // 初始化一些UI状态
    ui->volumeSlider->setValue(50); // 默认音量50%
    m_audioEngine->setVolume(50);
}

MainWindow::~MainWindow() {
    delete ui;
}

// --- UI控件槽函数的实现 ---

void MainWindow::on_openFileButton_clicked() {
    // 1. 获取可执行程序所在的目录路径
    //    在我们的项目中，这个路径就是 build/ 目录
    QString appDir = QCoreApplication::applicationDirPath();
    qDebug() << "Application Directory: " << appDir;

    // 2. 构造我们预先放置的音频文件的完整路径
    //    我们假设你已经在 build/ 目录下创建了 audio/ 文件夹，并放入了 test.mp3
    QString filePath = QDir(appDir).filePath("audio/test1.mp3");
    qDebug() << "Attempting to play file from: " << filePath;

    // 3. 检查文件是否存在，然后播放
    if (QFile::exists(filePath)) {
        QUrl fileUrl = QUrl::fromLocalFile(filePath);
        ui->trackLabel->setText(fileUrl.fileName());
        m_audioEngine->play(fileUrl);
    } else {
        // 如果文件不存在，在界面和调试控制台给出清晰的错误提示
        ui->trackLabel->setText("Error: 'build/audio/test.mp3' not found!");
        qDebug() << "File does not exist at the specified path.";
    }
}

void MainWindow::on_playPauseButton_clicked() {
    m_audioEngine->togglePlayback(); // 调用引擎的播放/暂停切换功能
}

void MainWindow::on_stopButton_clicked() {
    m_audioEngine->stop(); // 调用引擎的停止功能
}

void MainWindow::on_volumeSlider_valueChanged(int value) {
    m_audioEngine->setVolume(value); // 调用引擎的音量设置功能
}

void MainWindow::on_progressSlider_sliderMoved(int position) {
    m_audioEngine->setPosition(position); // 调用引擎的播放位置设置功能
}


// --- 引擎信号槽函数的实现 ---

void MainWindow::updatePosition(qint64 position) {
    // 当引擎发出位置变化信号时，更新进度条的位置
    // 注意：要避免在用户拖动滑块时，这里又去更新滑块，造成冲突
    if (!ui->progressSlider->isSliderDown()) {
        ui->progressSlider->setValue(position);
    }
}

void MainWindow::updateDuration(qint64 duration) {
    // 当引擎发出总时长变化信号时，设置进度条的最大值
    ui->progressSlider->setMaximum(duration);
}

void MainWindow::updatePlaybackState(QMediaPlayer::PlaybackState newState) {
    // 当引擎的播放状态变化时，更新播放/暂停按钮的文本
    if (newState == QMediaPlayer::PlayingState) {
        ui->playPauseButton->setText("Pause");
    } else {
        ui->playPauseButton->setText("Play");
    }
}