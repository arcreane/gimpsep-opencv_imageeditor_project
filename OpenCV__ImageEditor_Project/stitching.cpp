#include <iostream>
#include <fstream>
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/stitching.hpp>
#include "Save.h"

using namespace std;
using namespace cv;

// Global variables.
double minval, maxval;
Point minloc, maxloc;
Rect rect;
Mat result;

// Create function that finds point where overlap between two images starts. 
// Images "left_img" and "right_img" are passed in by find_overlaps function.
Point find_overlap_start(Mat left_img, Mat right_img)
{
    // Copy left image to new variable.
    Mat img = left_img;

    // Create matrix to be used as our "template". 
    rect.width = (img.size().width) / 10;
    rect.height = img.size().height;
    Mat templ = right_img(rect);

    // Apply template matching and store result.
    matchTemplate(img, templ, result, TM_CCORR_NORMED);
    minMaxLoc(result, &minval, &maxval, &minloc, &maxloc);

    // Return top-left coordinate where the matching starts.
    return maxloc;
}

// Create vector of points where images start to overlap.
vector<Point> find_overlaps(vector<Mat> images)
{
    // Create vector of overlaps coordinates.
    vector<Point> overlap_starts;

    for (int i = 0; i != images.size() - 1; i++)
    {
        // Find overlap start between two images.
        Point overlap = find_overlap_start(images[i], images[i + 1]);

        // Add overlap point to vector of points.
        overlap_starts.push_back(overlap);
    }

    // Return vector of "overlaping points" (top-left).
    return overlap_starts;
}

// Simple stitch, no blending, right hand slice overlays left hand slice.
Mat stitch_images(vector<Mat> images, vector<Point> overlap_starts)
{

    // Define variable to store width of the composite image.
    int total_width = 0;

    // Loop trought vector of overlaped points and calculate total_width.
    for (int i = 0; i < images.size() - 1; i++)
    {
        // Take the x coordinates of Point in overlap_starts vector.
        total_width += overlap_starts[i].x;

    }

    // Now add width of image to the total width.
    int img_width = images[images.size() - 1].cols;
    total_width = total_width + img_width;  

    // Create matrix that is of the size ( height, total_width -> depends on the number of images).
    Mat result = Mat::zeros(Size(total_width, images[1].rows), images[0].type());
   
    // Put images next to each other on the result matrix.
    int current_column = 0;
    for (int i = 0; i < images.size(); i++)
    {
        images[i].copyTo(result.rowRange(0, result.rows).colRange(current_column, (current_column + images[i].cols)));

        // The next image should be moved right for:
        if (i != images.size() - 1) current_column += overlap_starts[i].x;
    }

    // Display composite image.
    namedWindow("result", WINDOW_AUTOSIZE);
    imshow("result", result);
    
    return result;
}


int stitching(int argc, char* argv[])
{
    // Ask the user how many images to switch
    int number_img;
    cout << "How many images do you want to stitch? " << endl;
    cin >> number_img;

    // Create vector of images.
    string path;
    vector<Mat> various_images;
    for (int i = 0; i < number_img; i++) 
    {
        // Load the image
        cout << "Enter image path " << endl;
        cin >> path;
        Mat img = imread(path);

        // Store the image in the vector
        various_images.push_back(img);
    }

    // Display loaded images.
    for (int i = 0; i < number_img; i++) 
    {
        namedWindow("img " + std::to_string(i +1), WINDOW_AUTOSIZE);
        imshow("img " + std::to_string(i + 1), various_images[i]);
    }

    // Find top-left points of overlaping.
    vector<Point> overlap_starts = find_overlaps(various_images);
    
    // Stitch images together.
    Mat output = stitch_images(various_images, overlap_starts);
    
    Save(output, path + "Stitched");
    return 0;
}
