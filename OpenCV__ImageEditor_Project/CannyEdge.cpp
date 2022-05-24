#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

Mat src, src_gray;
Mat dst, detected_edges;

int threshhold = 0;
const int maxThreshold = 300;
const int treshRatio = 3;
const int kernel = 3;
const char* window_name = "Canny edges";


static void CannyThreshold(int, void*)
{
    blur(src_gray, detected_edges, Size(3, 3));
    Canny(detected_edges, detected_edges, threshhold, threshhold * treshRatio, kernel);
    dst = Scalar::all(0);
    src.copyTo(dst, detected_edges);
    imshow(window_name, dst);
};

int main(int argc, char** argv)
{
    CommandLineParser parser(argc, argv, "{@input | C:/Users/HappyFish.jpg | input image}");
    //src = imread(samples::findFile(parser.get<String>("@input")), IMREAD_COLOR);
    string path;
    cout << "Enter image path " << endl;
    cin >> path;
    src = imread(path, IMREAD_COLOR);

    dst.create(src.size(), src.type());
    cvtColor(src, src_gray, COLOR_BGR2GRAY);
    namedWindow(window_name, WINDOW_AUTOSIZE);
    createTrackbar("Min Threshold:", window_name, &threshhold, maxThreshold, CannyThreshold);
    CannyThreshold(0, 0);
    waitKey(0);
    return 0;
}