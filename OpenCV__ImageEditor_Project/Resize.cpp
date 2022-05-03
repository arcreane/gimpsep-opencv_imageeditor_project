#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(void)
{
	Mat source, scale;

	// Read source image
	source = imread("C:/Users/Amaury LC/Desktop/ISEP/Informatique/TP2/van_gogh.jpg");

	//User input scaling factors
	
	double scaleX;
	double scaleY;
	cout << "Enter scaling factor X ";
	cin >> scaleX;
	cout << "Enter scaling factor Y ";
	cin >> scaleY;

	// Scaling down the image
	resize(source, scale, Size(), scaleX, scaleY, INTER_LINEAR);

	//Display windows and show images
	namedWindow("WindowName");
	namedWindow("WindowName2");

	cv::imshow("WindowName", source);
	cv::imshow("WindowName2", scale);

	waitKey(0);

}
