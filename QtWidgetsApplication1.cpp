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
    // ��opencv�е�BGRɫ�ʿռ�ת��ΪRGBɫ�ʿռ� ����QImage����

    QImage Qtemp = QImage((const unsigned char*)(temp.data), temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
    // ��temp�л�ȡͼ��

    ui.pic_label->setPixmap(QPixmap::fromImage(Qtemp));
    // ��ͼ��������ʾ��pic_label��
}

void QtWidgetsApplication1::on_horizontalSlider_5_valueChanged(int value)
{
    Mat res = pic.flip(value);


    Mat temp;
    if (res.empty()) {
        // ���res�ǿյ� Ҳ������ͼ�����ݾ�ֱ�ӷ���
        return;
    }
    cvtColor(res, temp, COLOR_BGR2RGB);
    // ��opencv�е�BGRɫ�ʿռ�ת��ΪRGBɫ�ʿռ� ����QImage����

    QImage Qtemp = QImage((const unsigned char*)(temp.data), temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
    // ��temp�л�ȡͼ��

    ui.pic_label->setPixmap(QPixmap::fromImage(Qtemp));
    // ��ͼ��������ʾ��pic_label��
}

void QtWidgetsApplication1::on_horizontalSlider_6_valueChanged(int value)
{
    Mat res = pic.Stagger_cut_x(value);
   
    Mat temp;
    if (res.empty()) {
        // ���res�ǿյ� Ҳ������ͼ�����ݾ�ֱ�ӷ���
        return;
    }
    cvtColor(res, temp, COLOR_BGR2RGB);
    // ��opencv�е�BGRɫ�ʿռ�ת��ΪRGBɫ�ʿռ� ����QImage����

    QImage Qtemp = QImage((const unsigned char*)(temp.data), temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
    // ��temp�л�ȡͼ��

    ui.pic_label->setPixmap(QPixmap::fromImage(Qtemp));
    // ��ͼ��������ʾ��pic_label��
}

void QtWidgetsApplication1::on_horizontalSlider_7_valueChanged(int value)
{
    Mat res = pic.Stagger_cut_y(value);
   
    Mat temp;
    if (res.empty()) {
        // ���res�ǿյ� Ҳ������ͼ�����ݾ�ֱ�ӷ���
        return;
    }
    cvtColor(res, temp, COLOR_BGR2RGB);
    // ��opencv�е�BGRɫ�ʿռ�ת��ΪRGBɫ�ʿռ� ����QImage����

    QImage Qtemp = QImage((const unsigned char*)(temp.data), temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
    // ��temp�л�ȡͼ��

    ui.pic_label->setPixmap(QPixmap::fromImage(Qtemp));
    // ��ͼ��������ʾ��pic_label��
}

void QtWidgetsApplication1::on_horizontalSlider_2_valueChanged(int value)
{
    Mat res = pic.left_right(value);
   
    Mat temp;
    if (res.empty()) {
        // ���res�ǿյ� Ҳ������ͼ�����ݾ�ֱ�ӷ���
        return;
    }
    cvtColor(res, temp, COLOR_BGR2RGB);
    // ��opencv�е�BGRɫ�ʿռ�ת��ΪRGBɫ�ʿռ� ����QImage����

    QImage Qtemp = QImage((const unsigned char*)(temp.data), temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
    // ��temp�л�ȡͼ��

    ui.pic_label->setPixmap(QPixmap::fromImage(Qtemp));
    // ��ͼ��������ʾ��pic_label��
}

void QtWidgetsApplication1::on_horizontalSlider_3_valueChanged(int value)
{
    Mat res = pic.up_down(value);
  
    Mat temp;
    if (res.empty()) {
        // ���res�ǿյ� Ҳ������ͼ�����ݾ�ֱ�ӷ���
        return;
    }
    cvtColor(res, temp, COLOR_BGR2RGB);
    // ��opencv�е�BGRɫ�ʿռ�ת��ΪRGBɫ�ʿռ� ����QImage����

    QImage Qtemp = QImage((const unsigned char*)(temp.data), temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
    // ��temp�л�ȡͼ��

    ui.pic_label->setPixmap(QPixmap::fromImage(Qtemp));
    // ��ͼ��������ʾ��pic_label��
}

void QtWidgetsApplication1::on_pushButton_2_clicked()
{
    if (pic.get_old_pic().empty()) {
        return;
    }
    for (int i = 0; i < 3; i++) {
        Mat res = pic.get_old_pic().clone(), temp;
        // ��ȡpic����ľ�ͼƬ

        cvtColor(res, temp, COLOR_BGR2RGB);
        // ��opencv�е�BGRɫ�ʿռ�ת��ΪRGBɫ�ʿռ� ����QImage����

        QImage Qtemp = QImage((const unsigned char*)(temp.data), temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
        // ��temp�л�ȡͼ��

        QPixmap Pix = QPixmap::fromImage(Qtemp);
        QSize PixSize = ui.pic_label->size();
        Pix.scaled(PixSize, Qt::KeepAspectRatioByExpanding);
        ui.pic_label->setScaledContents(true);
        ui.pic_label->setPixmap(Pix);
        // ��ͼ��������ʾ��pic_label��

        ui.horizontalSlider->setValue(50);
        ui.horizontalSlider_2->setValue(50);
        ui.horizontalSlider_3->setValue(50);
        ui.horizontalSlider_4->setValue(0);
        ui.horizontalSlider_5->setValue(2);
        ui.horizontalSlider_6->setValue(0);
        ui.horizontalSlider_7->setValue(0);
        // ����������ֵ����Ϊ��ʼֵ
    }

}

void QtWidgetsApplication1::on_horizontalSlider_valueChanged(int value)
{
    Mat res = pic.big_small(value);

    Mat temp;
    if (res.empty()) {
        // ���res�ǿյ� Ҳ������ͼ�����ݾ�ֱ�ӷ���
        return;
    }
    cvtColor(res, temp, COLOR_BGR2RGB);
    // ��opencv�е�BGRɫ�ʿռ�ת��ΪRGBɫ�ʿռ� ����QImage����

    QImage Qtemp = QImage((const unsigned char*)(temp.data), temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
    // ��temp�л�ȡͼ��

    ui.pic_label->setPixmap(QPixmap::fromImage(Qtemp));
    // ��ͼ��������ʾ��pic_label��
}


void QtWidgetsApplication1::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
                this, tr("open image file"),
                "./", tr("Image files(*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm);"));
    // ���Դ��ļ�
    QMessageBox mesg;
    if (fileName.isEmpty())
    {
        mesg.warning(this, "Error", "You have not selected a picture!");
        // ���û�� ����ʾ���ҷ���
        return;
    }
    else
    {
        QImage img(fileName);
        // ��ͼƬ���ص�QImage��

        img = img.scaled(ui.pic_label->width(), ui.pic_label->height(), Qt::KeepAspectRatioByExpanding);
        // ����ͼƬ��ʾ��ʽ

        ui.pic_label->setScaledContents(true);
        ui.pic_label->setPixmap(QPixmap::fromImage(img));
        // ��ͼƬ���ص�pic_label��

        pic.set_pic(fileName, ui.pic_label->width(), ui.pic_label->height());
        // ��ͼƬ���ص�pic����

        if (img.isNull())
        {
            QMessageBox::information(this, "ERROR", "Can't open the picture!");
            // ���ͼƬ��ʧ�� ������ʾ
        }
    }
}
