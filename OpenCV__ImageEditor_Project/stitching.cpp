
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/stitching.hpp"
#include <iostream>
/*
using namespace std;
using namespace cv;
bool divide_images = false;
Stitcher::Mode mode = Stitcher::PANORAMA;
vector<Mat> imgs;
string result_name = "result.jpg";
void printUsage(char** argv);
int parseCmdArgs(int argc, char** argv);
int main(int argc, char* argv[])
{
    int retval = parseCmdArgs(argc, argv);
    if (retval) return EXIT_FAILURE;
    Mat pano;
    Ptr<Stitcher> stitcher = Stitcher::create(mode);
    Stitcher::Status status = stitcher->stitch(imgs, pano);
    if (status != Stitcher::OK)
    {
        cout << "Can't stitch images, error code = " << int(status) << endl;
        return EXIT_FAILURE;
    }
    imwrite(result_name, pano);
    cout << "stitching completed successfully\n" << result_name << " saved!";
    return EXIT_SUCCESS;
}
void printUsage(char** argv)
{
    cout <<
        "Images stitcher.\n\n" << "Usage :\n" << argv[0] << " [Flags] img1 img2 [...imgN]\n\n"
        "Flags:\n"
        "  --d3\n"
        "      internally creates three chunks of each image to increase stitching success\n"
        "  --mode (panorama|scans)\n"
        "      Determines configuration of stitcher. The default is 'panorama',\n"
        "      mode suitable for creating photo panoramas. Option 'scans' is suitable\n"
        "      for stitching materials under affine transformation, such as scans.\n"
        "  --output <result_img>\n"
        "      The default is 'result.jpg'.\n\n"
        "Example usage :\n" << argv[0] << " --d3 --mode scans img1.jpg img2.jpg\n";
}
int parseCmdArgs(int argc, char** argv)
{
    if (argc == 1)
    {
        printUsage(argv);
        return EXIT_FAILURE;
    }
    for (int i = 1; i < argc; ++i)
    {
        if (string(argv[i]) == "--help" || string(argv[i]) == "/?")
        {
            printUsage(argv);
            return EXIT_FAILURE;
        }
        else if (string(argv[i]) == "--d3")
        {
            divide_images = true;
        }
        else if (string(argv[i]) == "--output")
        {
            result_name = argv[i + 1];
            i++;
        }
        else if (string(argv[i]) == "--mode")
        {
            if (string(argv[i + 1]) == "panorama")
                mode = Stitcher::PANORAMA;
            else if (string(argv[i + 1]) == "scans")
                mode = Stitcher::SCANS;
            else
            {
                cout << "Bad --mode flag value\n";
                return EXIT_FAILURE;
            }
            i++;
        }
        else
        {
            Mat img = imread(samples::findFile(argv[i]));
            if (img.empty())
            {
                cout << "Can't read image '" << argv[i] << "'\n";
                return EXIT_FAILURE;
            }
            if (divide_images)
            {
                Rect rect(0, 0, img.cols / 2, img.rows);
                imgs.push_back(img(rect).clone());
                rect.x = img.cols / 3;
                imgs.push_back(img(rect).clone());
                rect.x = img.cols / 2;
                imgs.push_back(img(rect).clone());
            }
            else
                imgs.push_back(img);
        }
    }
    return EXIT_SUCCESS;
}


/*

// CPP program to Stitch
// input images (panorama) using OpenCV 
#include <iostream>
#include <fstream>

// Include header files from OpenCV directory
// required to stitch images.
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/stitching.hpp"

using namespace std;
using namespace cv;

// Define mode for stitching as panoroma 
// (One out of many functions of Stitcher)
Stitcher::Mode mode = Stitcher::PANORAMA;


int main(int argc, char* argv[])
{

    std::cout << "ici" << std::endl;
    // Array for pictures
    vector<Mat> imgs;
    Mat image;
    image = cv::imread("C:/Users/adria/Documents/ISEP/A2/Dev/TP2/HappyFish.jpg");
    imgs.push_back(image);

    // Define object to store the stitched image
    Mat pano;

    // Create a Stitcher class object with mode panoroma
    Ptr<Stitcher> stitcher = Stitcher::create(mode,false);

    // Command to stitch all the images present in the image array
    Stitcher::Status status = stitcher->stitch(imgs, pano);

    if (status != Stitcher::OK)
    {
        // Check if images could not be stiched
        // status is OK if images are stiched successfully
        cout << "Can't stitch images\n";
        return -1;
    }

    // Store a new image stiched from the given 
    //set of images as "result.jpg"
    imwrite("result.jpg", pano);

    // Show the result
    imshow("Result", pano);

    waitKey(0);
    return 0;
}

*/