#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv); // 创建Qt应用程序实例
    MainWindow w; // 创建主窗口实例
    w.show(); // 显示主窗口
    return a.exec(); // 进入事件循环
}