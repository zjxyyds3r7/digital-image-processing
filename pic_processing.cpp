#include "pic_processing.h"
#include <opencv2/opencv.hpp>
#include <QFileDialog>
#include <QMessageBox>
using namespace std;
using namespace cv;

void pic_processing::init() {

	// 旋转
	Point2f center((image.cols) / 2.0, (image.rows) / 2.0);
	// 确定中心点 使用图像中心
	Mat rotation_matix = getRotationMatrix2D(center, rotate, 1.0);
	// 获取旋转矩阵
	warpAffine(old_img, image, rotation_matix, image.size());
	// 使用warpAffine函数对图像进行旋转操作

	// 平移
	float warp_values[] = { 1.0, 0.0, now_x, 0.0, 1.0, now_y };
	// 手动构造平移矩阵
	Mat translation_matrix = Mat(2, 3, CV_32F, warp_values);
	// 将数组转化为openCV的矩阵
	warpAffine(image, image, translation_matrix, image.size());
	// 使用warpAffine函数对图像进行平移操作

	// 仿射
	float fangshe[] = { 1, tan(1.0 * Stagger_x * M_PI / 180), 0, tan(1.0 * Stagger_y * M_PI / 180), 1, 0 };
	// 手动构造仿射矩阵 传递进来的参数是角度需要转化为弧度
	translation_matrix = Mat(2, 3, CV_32F, fangshe);
	// 将数组转化为openCV的矩阵
	warpAffine(image, image, translation_matrix, image.size());
	// 使用warpAffine函数对图像进行仿射变换

	// 对称
	if (fliptype != 2) {
		cv::flip(image, image, fliptype);
	}

	// 缩放
	cv::resize(image, image, Size(MAX(old_img.cols * resize, 1.0), MAX(old_img.rows * resize, 1.0)), 0, 0, INTER_NEAREST);
	// 调用opencv的resize函数进行缩放
}

bool pic_processing::is_null() {
	
	return image.empty();
	
}

pic_processing::pic_processing(string path)
{
	image = imread(path);
}

pic_processing::pic_processing() {};

Mat pic_processing::big_small(int size) {
	
	if (is_null()) {
		QMessageBox mesg;
		mesg.warning(0, "Error", "Open the picture first!");
		return Mat();
	}

	// 用来判断是否有图片
	size -= 50;
	resize = 1.0 - size / 50.0;
	init();
	// 更改参数并且调用init()生成新的image
	return image;
}

// 从指定的path中获取图片 使用opencv的imread方法
void pic_processing::set_pic(QString path, int x, int y)
{
	image = imread(string((const char*)path.toLocal8Bit()));
	old_img = image.clone();
	if (is_null()) {
		QMessageBox::information(0, "Error", "Open the picture first " + path);
	}
}

Mat pic_processing::turn(int size)
{
	
	if (is_null()) {
		QMessageBox mesg;
		mesg.warning(0, "Error", "Open the picture first!");
		return Mat();
	}
	// 用来判断是否有图片

	this->rotate = 180.0 * size / 50.0;
	init();
	// 更改参数并且调用init()生成新的image
	return image;
}

Mat pic_processing::get_old_pic()
{
	if (is_null()) {
		QMessageBox mesg;
		mesg.warning(0, "Error", "Open the picture first!");
		return Mat();
	}
	// 用来判断是否有图片
	return old_img;
}

Mat pic_processing::flip(int type)
{
	if (is_null()) {
		QMessageBox mesg;
		mesg.warning(0, "Error", "Open the picture first!");
		return Mat();
	}
	// 用来判断是否有图片
	fliptype = type;
	init();
	// 更改参数并且调用init()生成新的image
	return image;
}

Mat pic_processing::Stagger_cut_x(int x)
{
	if (is_null()) {
		QMessageBox mesg;
		mesg.warning(0, "Error", "Open the picture first!");
		return Mat();
	}
	// 用来判断是否有图片
	Stagger_x = x;
	init();
	// 更改参数并且调用init()生成新的image
	return image;
}

Mat pic_processing::Stagger_cut_y(int y)
{
	if (is_null()) {
		QMessageBox mesg;
		mesg.warning(0, "Error", "Open the picture first!");
		return Mat();
	}
	// 用来判断是否有图片
	Stagger_y = y;
	init();
	// 更改参数并且调用init()生成新的image
	return image;
}

Mat pic_processing::left_right(int size) {
	size -= 50;
	size = 1.0 * size / 50.0 * old_img.cols;
	now_x = size;
	if (is_null()) {
		QMessageBox mesg;
		mesg.warning(0, "Error", "Open the picture first!");
		return Mat();
	}
	// 用来判断是否有图片
	float tx = size;
	init();
	// 更改参数并且调用init()生成新的image
	return image;
}
Mat pic_processing::up_down(int size)
{

	if (is_null()) {
		QMessageBox mesg;
		mesg.warning(0, "Error", "Open the picture first!");
		return Mat();
	}
	// 用来判断是否有图片
	size -= 50;
	size = 1.0 * size / 50.0 * old_img.rows;
	now_y = size;
	float ty = size;
	init();
	// 更改参数并且调用init()生成新的image
	return image;

}
