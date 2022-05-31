#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

// We initialize the variables
using namespace cv;
using namespace std;
Mat src, erosion_dst, dilation_dst;
int erosion_size = 0;
int dilation_size = 0;
int const max_kernel_size = 21;
void Erosion(int, void*);
void Dilation(int, void*);

// The user selects which function he wants to use
int dilate_erode(int argc, char** argv)
{
    // src = imread("C:/Users/amand/Downloads/A2/MediaApp/AmandaDieuaide-TP2/HappyFish.jpg");

    // Input and read source image 
    string path;
    cout << "Enter image path" << endl;
    cin >> path;
    src = imread(path);

    // Function selection
    int menu;
    if (src.empty())
    {
        // If the program can't find the image, we display an error
        cout << "Could not open or find the image!\n" << endl;
        cout << "Usage: " << argv[0] << " <Input image>" << endl;
        return -1;
    }

    do
    {
        // Otherwise, we ask the user to select a function by entering the corresponding number in the console
        cout << "1. Erode Image" << endl;
        cout << "2. Dilate Image" << endl;
        cout << "0. Go back to Main Menu" << endl << endl;
        cout << "Choix : ";
        cin >> menu;
        cout << endl;

        // We create the window corresponding to the right function, the trackbar, and we call the right function
        switch (menu)
        {
        case 0: break;

        case 1: 
            namedWindow("Erosion Demo", WINDOW_AUTOSIZE);
            createTrackbar("Kernel size:\n 2n +1", "Erosion Demo",
                &erosion_size, max_kernel_size,
                Erosion);
            Erosion(0, 0);
            waitKey(0);
            break;

        case 2: 
            namedWindow("Dilation Demo", WINDOW_AUTOSIZE);
            createTrackbar("Kernel size:\n 2n +1", "Dilation Demo",
                &dilation_size, max_kernel_size,
                Dilation);
            Dilation(0, 0);
            waitKey(0);
            break;
        }

    } while (menu != 0);
   
    return 0;
}

// We create a structuring element and we erode the image with it
void Erosion(int, void*)
{
    // It reads also the value of the trackbar
    Mat element = getStructuringElement(MORPH_ELLIPSE,
        Size(2 * erosion_size + 1, 2 * erosion_size + 1),
        Point(erosion_size, erosion_size));
    erode(src, erosion_dst, element);
    
    // We display the image
    imshow("Erosion Demo", erosion_dst);
}

// We create a structuring element and we dilate the image with it
void Dilation(int, void*)
{
    // It reads also the value of the trackbar
    Mat element = getStructuringElement(MORPH_ELLIPSE,
        Size(2 * dilation_size + 1, 2 * dilation_size + 1),
        Point(dilation_size, dilation_size));
    dilate(src, dilation_dst, element);

    // We display the image
    imshow("Dilation Demo", dilation_dst);
}

