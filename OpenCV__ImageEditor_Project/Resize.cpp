#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(void)
{
	Mat source, scale;

	// Input and read source image
	string path;
	cout << "Enter image path ";
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
	namedWindow("WindowName");
	namedWindow("WindowName2");

	cv::imshow("WindowName", source);
	cv::imshow("WindowName2", scale);

	waitKey(0);
	
}