#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;
Mat src, erosion_dst, dilation_dst;
int erosion_size = 0;
int dilation_size = 0;
int const max_kernel_size = 21;
void Erosion(int, void*);
void Dilation(int, void*);

// Input image, Erosion/Dilatation size, Choice between Erode/Dilate

int dilate_erode(int argc, char** argv)
{
    // src = imread("C:/Users/amand/Downloads/A2/MediaApp/AmandaDieuaide-TP2/HappyFish.jpg");

    // Input and read source image 
    string path;
    cout << "Enter image path" << endl;
    cin >> path;
    src = imread(path);

    int menu;
    if (src.empty())
    {
        cout << "Could not open or find the image!\n" << endl;
        cout << "Usage: " << argv[0] << " <Input image>" << endl;
        return -1;
    }

    do
    {
        cout << "1. Erode Image" << endl;
        cout << "2. Dilate Image" << endl;
        cout << "0. Go back to Main Menu" << endl << endl;
        cout << "Choix : ";
        cin >> menu;
        cout << endl;

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
void Erosion(int, void*)
{
    Mat element = getStructuringElement(MORPH_ELLIPSE,
        Size(2 * erosion_size + 1, 2 * erosion_size + 1),
        Point(erosion_size, erosion_size));
    erode(src, erosion_dst, element);
    imshow("Erosion Demo", erosion_dst);
}

void Dilation(int, void*)
{
    Mat element = getStructuringElement(MORPH_ELLIPSE,
        Size(2 * dilation_size + 1, 2 * dilation_size + 1),
        Point(dilation_size, dilation_size));
    dilate(src, dilation_dst, element);
    imshow("Dilation Demo", dilation_dst);
}

