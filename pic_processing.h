#pragma once
#include <opencv2/opencv.hpp>
#include <QFileDialog>
#include <QMessageBox>
#include <algorithm>
#include <math.h>
#define M_PI 3.14159265358979323846

using namespace cv;
using namespace std;

class pic_processing
{
private:
	Mat image,old_img;
	float now_x=0, now_y = 0,resize=1, rotate=0, fliptype = 2, Stagger_x=0, Stagger_y=0;
	// old_img:		��ͼƬ
	// image:		��ͼƬ
	// now_x:		x��ƽ�ƾ���
	// now_y:		y��ƽ�ƾ���
	// resize:		ͼ�����
	// rotate:		��ת�Ƕ�
	// fliptype:	��ת����,2�ǲ���ת
	// Stagger_x:	x�����Ƕ�
	// Stagger_y:	y�����Ƕ�
public:
	pic_processing(string path);

	pic_processing();

	bool is_null();

	void init();

	Mat left_right(int size);

	Mat up_down(int size);

	Mat big_small(int size);
	void set_pic(QString path, int x, int y);

	Mat turn(int size);

	Mat get_old_pic();

	Mat flip(int type);

	Mat Stagger_cut_x(int x);

	Mat Stagger_cut_y(int y);
};

