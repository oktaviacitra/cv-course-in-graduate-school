#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main()
{
    
    Mat src, dst_erode, dst_dilate, bw;
    src = imread("sample.jpg", 1);
    cvtColor(src, bw, COLOR_BGR2GRAY);
    threshold(bw, bw, 40, 255, THRESH_BINARY | THRESH_OTSU);
    //creating structuring element
    int closing_size = 3; //ukuran operator closing
    Mat element = getStructuringElement(MORPH_RECT, Size(2 * closing_size + 1, 2 * closing_size + 1), Point(closing_size, closing_size));
    //apply closing on the image
    dilate(bw, dst_dilate, element);
    erode(dst_dilate, dst_erode, element);
    imshow("Display Window", bw);
    imshow("Result Window", dst_erode);
    waitKey();
    return 0;
}
