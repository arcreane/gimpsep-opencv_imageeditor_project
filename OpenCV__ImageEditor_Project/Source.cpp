#include <opencv2/opencv.hpp>
using namespace cv;

int main( int argc, char** argv )
{
	//Amaury    commit test :D
 char* imageName = argv[1];

 Mat image;
 image = cv::imread("C:/Users/amand/Downloads/A2/MediaApp/AmandaDieuaide-TP2/HappyFish.jpg");
 if( argc != 2 || !image.data )
 {
   printf( " No image data \n " );
   return -1;
 }
 Mat gray_image;

 cvtColor(image, gray_image, COLOR_BGR2GRAY);

 namedWindow("WindowName");
 namedWindow("WindowNameGray");

 cv::imshow("WindowName", image);
 cv::imshow("WindowNameGray", gray_image);
 cv::imwrite("C:/Users/amand/Downloads/A2/MediaApp/AmandaDieuaide-TP2/Gray_HappyFish.jpg", gray_image);
 waitKey(0);

 return 0;
}