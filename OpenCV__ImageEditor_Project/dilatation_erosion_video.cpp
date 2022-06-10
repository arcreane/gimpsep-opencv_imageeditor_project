#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int dilate_erode_vid(int argc, char** argv)
{
    // Input and read source video 
    string path;
    cout << "Enter video path" << endl;
    cin >> path;

    // Open the video file for reading
    VideoCapture cap(path);

    // If not success, exit program
    if (!cap.isOpened()) {
        cout << "Error opening video stream or file" << endl;
        return -1;
    }

    // Defining window names for above images
    String windowOriginal = "Original";
    String windowDilate = "Dilatation";
    String windowErode = "Erosion";

    // Create and open windows for above images
    namedWindow(windowOriginal);
    namedWindow(windowDilate);
    namedWindow(windowErode);

    while (true)
    {
        // Read a new frame from video
        Mat frame;
        bool bSuccess = cap.read(frame);

        // Breaking the while loop at the end of the video
        if (bSuccess == false)
        {
            cout << "Found the end of the video" << endl;
            break;
        }

        // Dilate with 5x5 kernel
        Mat frameDilate;
        dilate(frame, frameDilate, getStructuringElement(MORPH_RECT, Size(5, 5)));

        // Erode with 5x5 kernel
        Mat frameErode;
        erode(frame, frameErode, getStructuringElement(MORPH_RECT, Size(5, 5)));

        // Show above images inside the created windows.
        imshow(windowOriginal, frame);
        imshow(windowDilate, frameDilate);
        imshow(windowErode, frameErode);

        // Wait for for 10 ms until any key is pressed.
        // If the 'Esc' key is pressed, break the while loop.
        // If the any other key is pressed, continue the loop
        // If any key is not pressed withing 10 ms, continue the loop
        if (waitKey(10) == 27)
        {
            destroyAllWindows();
            cout << "Esc key is pressed by user. Stoppig the video" << endl;
            break;
        }
    }

    return 0;
}
