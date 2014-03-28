//Code to check the OpenCV installation on Raspberry Pi and measure frame rate of frames captured by the OpenCV - RPi wrapper

//Author: Samarth Manoj Brahmbhatt, University of Pennsylvania, with help of low-level code written by Tasanakorn

#include "cap.h"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main() {
    namedWindow("Video");

    // Create capture object, similar to VideoCapture
    // PiCapture(width, height, color_flag);
    // color_flag = true  => color images are captured,
    // color_flag = false => greyscale images are captured
    PiCapture cap(320, 240, true);

    Mat im;
    double time = 0;
    unsigned int frames = 0;

    cout << "Press 'q' to quit" << endl;
    while(char(waitKey(1)) != 'q') {
        double t0 = getTickCount();
        im = cap.grab();
        frames++;
        if(!im.empty()) imshow("Hello", im);
        else cout << "Frame dropped" << endl;

        time += (getTickCount() - t0) / getTickFrequency();
        cout << frames / time << " fps" << endl;
    }

    return 0;
}
