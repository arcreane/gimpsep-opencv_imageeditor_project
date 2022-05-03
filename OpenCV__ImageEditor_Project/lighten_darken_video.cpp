#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int light_dark_vid(int argc, char** argv)
{
    //open the video file for reading
    VideoCapture cap("C:/Users/amand/Downloads/A2/MediaApp/AmandaDieuaide-TP3/chaplin.mp4");

    // if not success, exit program
    if (!cap.isOpened()) {
        cout << "Error opening video stream or file" << endl;
        return -1;
    }

    //Defining window names for above images
    String windowOriginal = "Original";
    String windowContrastU2 = "Constrast*2";
    String windowBrightnessU50 = "Brightness+50";

    //Create and open windows for above images
    namedWindow(windowOriginal);
    namedWindow(windowContrastU2);
    namedWindow(windowBrightnessU50);

    while (true)
    {
         // read a new frame from video
        Mat frame;
        bool bSuccess = cap.read(frame);

         //Breaking the while loop at the end of the video
        if (bSuccess == false)
        {
            cout << "Found the end of the video" << endl;
            break;
        }

        //increase the contrast by 2
        Mat frameContrastU2;
        frame.convertTo(frameContrastU2, -1, 2, 0);

        //increase the brightness by 50
        Mat frameBrighnessU50;
        frame.convertTo(frameBrighnessU50, -1, 1, 50);

        //Show above images inside the created windows.
        imshow(windowOriginal, frame);
        imshow(windowContrastU2, frameContrastU2);
        imshow(windowBrightnessU50, frameBrighnessU50);

        //wait for for 10 ms until any key is pressed.
        //If the 'Esc' key is pressed, break the while loop.
        //If the any other key is pressed, continue the loop
        //If any key is not pressed withing 10 ms, continue the loop
        if (waitKey(10) == 27)
        {
            cout << "Esc key is pressed by user. Stoppig the video" << endl;
            break;
        }
    }

    return 0;
}