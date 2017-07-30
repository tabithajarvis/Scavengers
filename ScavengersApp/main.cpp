#include "main_window.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *w = new MainWindow();
    w->showFullScreen();

    return a.exec();
}
