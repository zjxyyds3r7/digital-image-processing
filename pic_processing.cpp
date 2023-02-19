#include "pic_processing.h"
#include <opencv2/opencv.hpp>
#include <QFileDialog>
#include <QMessageBox>
using namespace std;
using namespace cv;

void pic_processing::init() {

	// ��ת
	Point2f center((image.cols) / 2.0, (image.rows) / 2.0);
	// ȷ�����ĵ� ʹ��ͼ������
	Mat rotation_matix = getRotationMatrix2D(center, rotate, 1.0);
	// ��ȡ��ת����
	warpAffine(old_img, image, rotation_matix, image.size());
	// ʹ��warpAffine������ͼ�������ת����

	// ƽ��
	float warp_values[] = { 1.0, 0.0, now_x, 0.0, 1.0, now_y };
	// �ֶ�����ƽ�ƾ���
	Mat translation_matrix = Mat(2, 3, CV_32F, warp_values);
	// ������ת��ΪopenCV�ľ���
	warpAffine(image, image, translation_matrix, image.size());
	// ʹ��warpAffine������ͼ�����ƽ�Ʋ���

	// ����
	float fangshe[] = { 1, tan(1.0 * Stagger_x * M_PI / 180), 0, tan(1.0 * Stagger_y * M_PI / 180), 1, 0 };
	// �ֶ����������� ���ݽ����Ĳ����ǽǶ���Ҫת��Ϊ����
	translation_matrix = Mat(2, 3, CV_32F, fangshe);
	// ������ת��ΪopenCV�ľ���
	warpAffine(image, image, translation_matrix, image.size());
	// ʹ��warpAffine������ͼ����з���任

	// �Գ�
	if (fliptype != 2) {
		cv::flip(image, image, fliptype);
	}

	// ����
	cv::resize(image, image, Size(MAX(old_img.cols * resize, 1.0), MAX(old_img.rows * resize, 1.0)), 0, 0, INTER_NEAREST);
	// ����opencv��resize������������
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

	// �����ж��Ƿ���ͼƬ
	size -= 50;
	resize = 1.0 - size / 50.0;
	init();
	// ���Ĳ������ҵ���init()�����µ�image
	return image;
}

// ��ָ����path�л�ȡͼƬ ʹ��opencv��imread����
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
	// �����ж��Ƿ���ͼƬ

	this->rotate = 180.0 * size / 50.0;
	init();
	// ���Ĳ������ҵ���init()�����µ�image
	return image;
}

Mat pic_processing::get_old_pic()
{
	if (is_null()) {
		QMessageBox mesg;
		mesg.warning(0, "Error", "Open the picture first!");
		return Mat();
	}
	// �����ж��Ƿ���ͼƬ
	return old_img;
}

Mat pic_processing::flip(int type)
{
	if (is_null()) {
		QMessageBox mesg;
		mesg.warning(0, "Error", "Open the picture first!");
		return Mat();
	}
	// �����ж��Ƿ���ͼƬ
	fliptype = type;
	init();
	// ���Ĳ������ҵ���init()�����µ�image
	return image;
}

Mat pic_processing::Stagger_cut_x(int x)
{
	if (is_null()) {
		QMessageBox mesg;
		mesg.warning(0, "Error", "Open the picture first!");
		return Mat();
	}
	// �����ж��Ƿ���ͼƬ
	Stagger_x = x;
	init();
	// ���Ĳ������ҵ���init()�����µ�image
	return image;
}

Mat pic_processing::Stagger_cut_y(int y)
{
	if (is_null()) {
		QMessageBox mesg;
		mesg.warning(0, "Error", "Open the picture first!");
		return Mat();
	}
	// �����ж��Ƿ���ͼƬ
	Stagger_y = y;
	init();
	// ���Ĳ������ҵ���init()�����µ�image
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
	// �����ж��Ƿ���ͼƬ
	float tx = size;
	init();
	// ���Ĳ������ҵ���init()�����µ�image
	return image;
}
Mat pic_processing::up_down(int size)
{

	if (is_null()) {
		QMessageBox mesg;
		mesg.warning(0, "Error", "Open the picture first!");
		return Mat();
	}
	// �����ж��Ƿ���ͼƬ
	size -= 50;
	size = 1.0 * size / 50.0 * old_img.rows;
	now_y = size;
	float ty = size;
	init();
	// ���Ĳ������ҵ���init()�����µ�image
	return image;

}
