#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>


int main(int argc, char* argv[]) {
    if( argc != 2) {
     std::cout <<" Usage: read_img IMAGENAME" << std::endl;
     return -1;
    }

    cv::Mat image;
    image = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR); 

    if(!image.data) {
        std::cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

    // Here the result should be
    cv::Mat result;

    // -----------------------------------------------------------------------------
    // test 1 -> directly manipulate the RGB image

    // -----------------------------------------------------------------------------
    // test 2 -> convert to HSV and manipulate the Hue
    // convert to HSV
    cv::Mat hsv_image;
    cv::cvtColor(image, hsv_image, CV_BGR2HSV);

    // split into channels (in this case HSV)
    cv::Mat channel[3];
    cv::split(hsv_image, channel);


    // -----------------------------------------------------------------------------
    // show
    cv::namedWindow("Bluebox", cv::WINDOW_AUTOSIZE);
    cv::imshow("Bluebox", result);

    cv::waitKey(0);
    return 0;
}
