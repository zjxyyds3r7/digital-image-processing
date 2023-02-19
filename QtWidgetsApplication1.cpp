#include "QtWidgetsApplication1.h"
#include <QMessageBox>
#include "opencv2/opencv.hpp"
#include <QFileDialog>
#include <QGraphicsView>
using namespace cv;
QtWidgetsApplication1::QtWidgetsApplication1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this); 
}

QtWidgetsApplication1::~QtWidgetsApplication1()
{}

void QtWidgetsApplication1::on_horizontalSlider_4_valueChanged(int value)
{
    Mat res = pic.turn(value);
  
    Mat temp;
    if (res.empty()) {
  
        return;
    }
    cvtColor(res, temp, COLOR_BGR2RGB);
    // 将opencv中的BGR色彩空间转化为RGB色彩空间 方便QImage调用

    QImage Qtemp = QImage((const unsigned char*)(temp.data), temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
    // 从temp中获取图像

    ui.pic_label->setPixmap(QPixmap::fromImage(Qtemp));
    // 将图像数据显示在pic_label上
}

void QtWidgetsApplication1::on_horizontalSlider_5_valueChanged(int value)
{
    Mat res = pic.flip(value);


    Mat temp;
    if (res.empty()) {
        // 如果res是空的 也就是无图像数据就直接返回
        return;
    }
    cvtColor(res, temp, COLOR_BGR2RGB);
    // 将opencv中的BGR色彩空间转化为RGB色彩空间 方便QImage调用

    QImage Qtemp = QImage((const unsigned char*)(temp.data), temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
    // 从temp中获取图像

    ui.pic_label->setPixmap(QPixmap::fromImage(Qtemp));
    // 将图像数据显示在pic_label上
}

void QtWidgetsApplication1::on_horizontalSlider_6_valueChanged(int value)
{
    Mat res = pic.Stagger_cut_x(value);
   
    Mat temp;
    if (res.empty()) {
        // 如果res是空的 也就是无图像数据就直接返回
        return;
    }
    cvtColor(res, temp, COLOR_BGR2RGB);
    // 将opencv中的BGR色彩空间转化为RGB色彩空间 方便QImage调用

    QImage Qtemp = QImage((const unsigned char*)(temp.data), temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
    // 从temp中获取图像

    ui.pic_label->setPixmap(QPixmap::fromImage(Qtemp));
    // 将图像数据显示在pic_label上
}

void QtWidgetsApplication1::on_horizontalSlider_7_valueChanged(int value)
{
    Mat res = pic.Stagger_cut_y(value);
   
    Mat temp;
    if (res.empty()) {
        // 如果res是空的 也就是无图像数据就直接返回
        return;
    }
    cvtColor(res, temp, COLOR_BGR2RGB);
    // 将opencv中的BGR色彩空间转化为RGB色彩空间 方便QImage调用

    QImage Qtemp = QImage((const unsigned char*)(temp.data), temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
    // 从temp中获取图像

    ui.pic_label->setPixmap(QPixmap::fromImage(Qtemp));
    // 将图像数据显示在pic_label上
}

void QtWidgetsApplication1::on_horizontalSlider_2_valueChanged(int value)
{
    Mat res = pic.left_right(value);
   
    Mat temp;
    if (res.empty()) {
        // 如果res是空的 也就是无图像数据就直接返回
        return;
    }
    cvtColor(res, temp, COLOR_BGR2RGB);
    // 将opencv中的BGR色彩空间转化为RGB色彩空间 方便QImage调用

    QImage Qtemp = QImage((const unsigned char*)(temp.data), temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
    // 从temp中获取图像

    ui.pic_label->setPixmap(QPixmap::fromImage(Qtemp));
    // 将图像数据显示在pic_label上
}

void QtWidgetsApplication1::on_horizontalSlider_3_valueChanged(int value)
{
    Mat res = pic.up_down(value);
  
    Mat temp;
    if (res.empty()) {
        // 如果res是空的 也就是无图像数据就直接返回
        return;
    }
    cvtColor(res, temp, COLOR_BGR2RGB);
    // 将opencv中的BGR色彩空间转化为RGB色彩空间 方便QImage调用

    QImage Qtemp = QImage((const unsigned char*)(temp.data), temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
    // 从temp中获取图像

    ui.pic_label->setPixmap(QPixmap::fromImage(Qtemp));
    // 将图像数据显示在pic_label上
}

void QtWidgetsApplication1::on_pushButton_2_clicked()
{
    if (pic.get_old_pic().empty()) {
        return;
    }
    for (int i = 0; i < 3; i++) {
        Mat res = pic.get_old_pic().clone(), temp;
        // 获取pic类里的旧图片

        cvtColor(res, temp, COLOR_BGR2RGB);
        // 将opencv中的BGR色彩空间转化为RGB色彩空间 方便QImage调用

        QImage Qtemp = QImage((const unsigned char*)(temp.data), temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
        // 从temp中获取图像

        QPixmap Pix = QPixmap::fromImage(Qtemp);
        QSize PixSize = ui.pic_label->size();
        Pix.scaled(PixSize, Qt::KeepAspectRatioByExpanding);
        ui.pic_label->setScaledContents(true);
        ui.pic_label->setPixmap(Pix);
        // 将图像数据显示在pic_label上

        ui.horizontalSlider->setValue(50);
        ui.horizontalSlider_2->setValue(50);
        ui.horizontalSlider_3->setValue(50);
        ui.horizontalSlider_4->setValue(0);
        ui.horizontalSlider_5->setValue(2);
        ui.horizontalSlider_6->setValue(0);
        ui.horizontalSlider_7->setValue(0);
        // 将滑动条的值设置为初始值
    }

}

void QtWidgetsApplication1::on_horizontalSlider_valueChanged(int value)
{
    Mat res = pic.big_small(value);

    Mat temp;
    if (res.empty()) {
        // 如果res是空的 也就是无图像数据就直接返回
        return;
    }
    cvtColor(res, temp, COLOR_BGR2RGB);
    // 将opencv中的BGR色彩空间转化为RGB色彩空间 方便QImage调用

    QImage Qtemp = QImage((const unsigned char*)(temp.data), temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
    // 从temp中获取图像

    ui.pic_label->setPixmap(QPixmap::fromImage(Qtemp));
    // 将图像数据显示在pic_label上
}


void QtWidgetsApplication1::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
                this, tr("open image file"),
                "./", tr("Image files(*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm);"));
    // 尝试打开文件
    QMessageBox mesg;
    if (fileName.isEmpty())
    {
        mesg.warning(this, "Error", "You have not selected a picture!");
        // 如果没打开 就提示并且返回
        return;
    }
    else
    {
        QImage img(fileName);
        // 将图片加载到QImage中

        img = img.scaled(ui.pic_label->width(), ui.pic_label->height(), Qt::KeepAspectRatioByExpanding);
        // 更改图片显示方式

        ui.pic_label->setScaledContents(true);
        ui.pic_label->setPixmap(QPixmap::fromImage(img));
        // 将图片加载到pic_label里

        pic.set_pic(fileName, ui.pic_label->width(), ui.pic_label->height());
        // 将图片加载到pic类里

        if (img.isNull())
        {
            QMessageBox::information(this, "ERROR", "Can't open the picture!");
            // 如果图片打开失败 弹出提示
        }
    }
}
