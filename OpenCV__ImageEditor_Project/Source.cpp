#include <opencv2/opencv.hpp>
#include "Functions_menu.h"
using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    int menu;
    do
    {
        cout << endl << " ----------------------- MENU -----------------------" << endl << endl;
        cout << "1. Dilate/Erode Image" << endl;
        cout << "2. Dilate/Erode Video" << endl;
        cout << "3. Lighten/Darken Image" << endl;
        cout << "4. Lighten/Darken Video" << endl;
        cout << "0. Exit" << endl << endl;
        cout << "Choix : ";
        cin >> menu;
        cout << endl;

        switch (menu)
        {
        case 0: break;

        case 1: dilate_erode(argc, argv);
            break;

        case 2: dilate_erode_vid(argc, argv);
            break;

        case 3: light_dark(argc, argv);
            break;

        case 4: light_dark_vid(argc, argv);
            break;
        }

    } while (menu != 0);

 return 0;
}
