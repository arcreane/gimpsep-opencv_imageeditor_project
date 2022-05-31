#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

// We define the variables used in the code
Mat src_canny, src_gray;
Mat dst, detected_edges;

// We initialize the parameters of the thresholds and the kernel for the canny edge
int threshhold = 0;
const int maxThreshold = 100;
const int treshRatio = 10;
const int kernel = 3;
const char* window_name = "Canny edges";


static void CannyThreshold(int, void*)
{
    blur(src_gray, detected_edges, Size(3, 3)); // We blur the image with a size 3 kernel filter
    Canny(detected_edges, detected_edges, threshhold, threshhold * treshRatio, kernel); // We use the openCV canny function
    dst = Scalar::all(0); // We fill the destination image with zeros
    src_canny.copyTo(dst, detected_edges); // We copy the areas identified as edges by the canny function on a black background (dst)
    imshow(window_name, dst); // We dispay the result
};

int canny_edge(int argc, char** argv)
{
    // We load the source image by its path in the computer
    string path;
    cout << "Enter image path " << endl;
    cin >> path;
    src_canny = imread(path, IMREAD_COLOR);

    dst.create(src_canny.size(), src_canny.type()); // We create a matrix of src_canny's type and size
    cvtColor(src_canny, src_gray, COLOR_BGR2GRAY); // We convert the image to grayscale to detect the edges more easily
    namedWindow(window_name, WINDOW_AUTOSIZE); // We create a window to display the results
    createTrackbar("Min Threshold:", window_name, &threshhold, maxThreshold, CannyThreshold); // We create a trackbar to modify the canny edge precision
    CannyThreshold(0, 0);
    waitKey(0);
    return 0;
}
