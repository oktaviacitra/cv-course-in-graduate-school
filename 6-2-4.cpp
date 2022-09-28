#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat src, dst, bw;
    src = imread("sample.jpg", 1);
    cvtColor(src, bw, COLOR_BGR2GRAY);
    threshold(bw, bw, 40, 255, THRESH_BINARY | THRESH_OTSU);
    //creating structuring element
    int erosion_size = 3; //ukuran operator erosi
    Mat element = getStructuringElement(MORPH_CROSS, Size(2 * erosion_size + 1, 2 * erosion_size + 1), Point(erosion_size, erosion_size));
    int n = 10;
    for (int i = 0; i < n; i++) {
        erode(bw, dst, element, Point(-1, -1), i);
        imshow("Result Window", dst);
    }
    imshow("Display Window", bw);
    waitKey();
    return 0;
}
