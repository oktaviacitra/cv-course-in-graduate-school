#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main()
{
    
    Mat src, dst;
    src = imread("sample.jpg", 1);
    //creating structuring element
    int erosion_size = 3; //ukuran operator erosi
    Mat element = getStructuringElement(MORPH_RECT, Size(2 * erosion_size + 1, 2 * erosion_size + 1), Point(erosion_size, erosion_size));
    //apply erosion on the image
    erode(src, dst, element);
    imshow("Display Window", src);
    imshow("Result Window", dst);
    waitKey();
    return 0;
}
