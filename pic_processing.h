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
	// old_img:		旧图片
	// image:		新图片
	// now_x:		x轴平移距离
	// now_y:		y轴平移距离
	// resize:		图像比例
	// rotate:		旋转角度
	// fliptype:	翻转类型,2是不翻转
	// Stagger_x:	x轴仿射角度
	// Stagger_y:	y轴仿射角度
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

