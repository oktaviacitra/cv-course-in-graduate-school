#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main()
{
    //load the image
    Mat src = imread("mypaint.png", 1);
    //check if everything was fine
    if (!src.data)
        return -1;
    //shoe source image
    imshow("Source Image", src);
    //change the background from white to black, since that will help later to extract
    //creat binary image from source image
    Mat bw;
    
    cvtColor(src, bw, COLOR_BGR2GRAY);
    threshold(bw, bw, 40, 255, THRESH_BINARY | THRESH_OTSU);
    imshow("Binary Image", bw);
    //perform the distance transform algorithm
    Mat dist;
    distanceTransform(bw, dist, DIST_L2, 3);
    //normalize the distance image form range ={0.0,1.0}
    //so we can visualize and threshold it
    normalize(dist, dist, 0, 1., NORM_MINMAX);
    imshow("Distance Transform Image", dist);
    waitKey();
    return 0;
}
