#include "QtWidgetsApplication1.h"
#include <QtWidgets/QApplication>
#include "pic_processing.h"
int main(int argc, char *argv[])
{
    // 初始化QT界面 无实际意义
    QApplication a(argc, argv);
    QtWidgetsApplication1 w;
    w.show();
    return a.exec();
}
