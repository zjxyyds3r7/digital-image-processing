#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication1.h"
#include "pic_processing.h"
class QtWidgetsApplication1 : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplication1(QWidget *parent = nullptr);
    ~QtWidgetsApplication1();
    pic_processing pic;
private:
    Ui::QtWidgetsApplication1Class ui;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
   
    void on_horizontalSlider_valueChanged(int);
    void on_horizontalSlider_2_valueChanged(int);
    void on_horizontalSlider_3_valueChanged(int);
    void on_horizontalSlider_4_valueChanged(int);
    void on_horizontalSlider_5_valueChanged(int);
    void on_horizontalSlider_6_valueChanged(int);
    void on_horizontalSlider_7_valueChanged(int);
 
};
