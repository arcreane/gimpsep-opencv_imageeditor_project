#include <opencv2/opencv.hpp>
#include "Save.h"

using namespace std;
using namespace cv;

int resize_image(void)
{
	Mat source, scale;

	// Input and read source image
	string path;
	cout << "Enter image path " << endl;
	cin >> path;
	source = imread(path);

	//User input scaling factors
	double scaleX;
	double scaleY;
	cout << "Enter scaling factor X ";
	cin >> scaleX;
	cout << "Enter scaling factor Y ";
	cin >> scaleY;

	// Scaling the image
	resize(source, scale, Size(), scaleX, scaleY, INTER_LINEAR);

	//Display windows and show images
	namedWindow("Original");
	namedWindow("Resized");

	cv::imshow("Original", source);
	cv::imshow("Resized", scale);

	Save(scale, path + "Resize");
	return 0;
}