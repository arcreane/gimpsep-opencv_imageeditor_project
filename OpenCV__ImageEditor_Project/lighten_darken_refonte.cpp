#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

Mat image;
double alpha = 1.0;
int alpha_treshold = 10;
int beta = 0;
void Contrast(int, void*);

// Input image, Light/Dark factor

int light_dark(int argc, char** argv)
{
    // image = imread("C:/Users/amand/Downloads/A2/MediaApp/AmandaDieuaide-TP2/HappyFish.jpg");

    // Input and read source image 
    string path;
    cout << "Enter image path" << endl;
    cin >> path;
    image = imread(path);

    if (image.empty())
    {
        cout << "Could not open or find the image!\n" << endl;
        cout << "Usage: " << argv[0] << " <Input image>" << endl;
        return -1;
    }

    namedWindow("Contrast Demo", WINDOW_AUTOSIZE);
    createTrackbar("Min alpha:", "Contrast Demo",
        &alpha_treshold, 30,
        Contrast);
    createTrackbar("Min beta:", "Contrast Demo",
        &beta, 100,
        Contrast);
    Contrast(0, 0);
    waitKey(0);

    return 0;
}

void Contrast(int, void*)
{
    Mat new_image = Mat::zeros(image.size(), image.type());
    alpha = (double) alpha_treshold / 10;
    image.convertTo(new_image, -1, alpha, beta);
    imshow("Contrast Demo", new_image);
}