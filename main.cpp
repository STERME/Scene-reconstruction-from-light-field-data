#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp> // ToDo remove
#include <iostream>

#include "LightFieldFromLfpFile.h"

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
    if( argc != 2)
    {
     cout <<" Usage: display_image ImageToLoadAndDisplay" << endl;
     return -1;
    }

    Mat rawImage, subapertureImage, image;
	try {
		LightFieldFromLfpFile lf(argv[1]);

		rawImage = lf.getRawImage();
		//subapertureImage = lf.getSubapertureImage(5, 5);
		//image = lf.getAllSubaperturesInOneImage();
		image = lf.getImage(0.0068200001716613766 * 0.8);
	} catch (std::exception* e) {
		cerr << e->what() << endl;
		return -1;
	}

	cout << "Loading of file at " << argv[1] << " successful." << endl;
	cout << "Image has " << image.size().width << " x " << image.size().height << " pixels." << endl;
	cout << "Displaying extracted image" << endl;

	// save image to file
	string fileName = "subapertureImage.png";
	imwrite(fileName, image);
	cout << "Image saved as file." << endl;

	// show image
    namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display. (original size)
    //namedWindow( "Display window", WINDOW_NORMAL );// Create a window for display. (scale down size)
    imshow( "Display window", image );                   // Show our image inside it.

	waitKey(0);                                          // Wait for a keystroke in the window
    return 0;
}