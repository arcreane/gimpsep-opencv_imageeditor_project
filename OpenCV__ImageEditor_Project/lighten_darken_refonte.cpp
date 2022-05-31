#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

// We initialize the variables
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
        // If the program can't find the image, we display an error
        cout << "Could not open or find the image!\n" << endl;
        cout << "Usage: " << argv[0] << " <Input image>" << endl;
        return -1;
    }
    else 
    {
        // We create a window and two trackbars for the two parameters
        // There is a unique window that can lighten or darken
        namedWindow("Contrast Demo", WINDOW_AUTOSIZE);
        createTrackbar("Min alpha:", "Contrast Demo",
            &alpha_treshold, 30,
            Contrast);
        createTrackbar("Min beta:", "Contrast Demo",
            &beta, 100,
            Contrast);

        // We call the function
        Contrast(0, 0);
        waitKey(0);
    }

    return 0;
}

void Contrast(int, void*)
{
    // We create a new image 
    Mat new_image = Mat::zeros(image.size(), image.type());
    alpha = (double) alpha_treshold / 10;

    // We store in the new image the ancient image to which the parameters have been applied
    image.convertTo(new_image, -1, alpha, beta);
    imshow("Contrast Demo", new_image);
}