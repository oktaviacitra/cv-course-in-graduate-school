#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/video/background_segm.hpp"
#include "opencv2/video/tracking.hpp"

using namespace cv;
using namespace std;

int main(int argc, const char** argv) {
    // Just loaded image Lenna.png from project dir to LoadedImage
    Mat LoadedImage = imread("/Users/oktaviacitra/comvis/2/Lenna.png", IMREAD_COLOR);
    
    // Show what is in the Mat after load
    namedWindow("Step 1 image loaded", WINDOW_AUTOSIZE);
    imshow("Step 1 image loaded", LoadedImage);
    
    waitKey(1000);
    // Save the result from LoadedImage to Step1.JPG
    imwrite("/Users/oktaviacitra/comvis/2/Step1.JPG", LoadedImage);
    
    // This construct Rectangle Rec start at x=100 y=100, width=200 and heigth=200
    Rect Rec(100, 100, 200, 200);
    
    //Draw the rectangle into LoadedImage
    //Parameters are (into Mat, Rec describe position where to draw rectangle
    // Scalar is Color, 1 is thickness, 8 is line type and 0 shift position
    rectangle(LoadedImage, Rec, Scalar(255), 1, 8, 0);
    
    // Show what rectangle
    namedWindow("Step 2 draw Rectangle", WINDOW_AUTOSIZE);
    imshow("Step 2 draw Rectangle", LoadedImage);
    waitKey(1000);
    
    // Save the result from LoadedImage to Step2.JPG
    imwrite("/Users/oktaviacitra/comvis/2/Step2.JPG", LoadedImage);
    
    //Select area described by REC and result write to the Roi
    Mat Roi = LoadedImage(Rec);
    namedWindow("Step 3 Draw selected Roi", WINDOW_AUTOSIZE);
    imshow("Step 3 Draw selected Roi", Roi);
    waitKey(1000);
    
    // Save the result from LoadedImage to Step3.JPG
    imwrite("/Users/oktaviacitra/comvis/2/Step3.JPG", Roi);
    
    // Put roi back into source image
    // If you want to show the detail and visualize with context of source image
    // This rectangle describe target, where you want to // put your roi into original image
    // width and height of where rect must match Roi size // Let put our Roi into origin
    Rect WhereRec(0, 0, Roi.cols, Roi.rows);
    
    // This copy Roi Image into loaded on position Where rec
    Roi.copyTo(LoadedImage(WhereRec));
    
    namedWindow("Step 4 Final result", WINDOW_AUTOSIZE);
    imshow("Step 4 Final result", LoadedImage);
    waitKey(1000);
    
    // Same the result from LoadedImage to Step4.JPG
    imwrite("Step4.JPG", LoadedImage);
}
