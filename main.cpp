#include "QtWidgetsApplication1.h"
#include <QtWidgets/QApplication>
#include "pic_processing.h"
int main(int argc, char *argv[])
{
    // ��ʼ��QT���� ��ʵ������
    QApplication a(argc, argv);
    QtWidgetsApplication1 w;
    w.show();
    return a.exec();
}
