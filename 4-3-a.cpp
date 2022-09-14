#include <opencv2/opencv.hpp>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    double alpha = 0.5;
    double beta;
    double input;
    Mat src1, src2, res;
    /// Ask the user enter alpha
    cout << " Simple Linear Blender " << endl;
    cout << " " << endl;
    cout << "* Enter alpha [0-1]: ";
    cin >> input;
    /// We use the alpha provided by the user if it is between 0 and 1
    if( input >= 0.0 && input <= 1.0 ){
        alpha = input;
    }
    /// Read image ( same size, same type )
    src1 = imread("w.png");
    src2 = imread("s.png");
    res = src1;
    if (!src1.data) {
        printf("Error loading src1 \n");
        return -1;
    } if (!src2.data) {
        printf("Error loading src2 \n");
        return -1;
    }
    for (int j = 0; j < src1.rows; j++) {
        for (int i = 0; i < src1.cols; i++) {
            Vec3b color1 = src1.at<Vec3b>(Point(i, j));
            Vec3b color2 = src2.at<Vec3b>(Point(i, j));
            Vec3b color3 = res.at<Vec3b>(Point(i, j));
            for (int x = 0; x < 3; x++) {
                color3.val[x] = (1 - alpha) * color2.val[x] + alpha * color1.val[x];
            }
            res.at<Vec3b>(Point(i, j)) = color3;
        }
    }
    imshow("Linear Blend Manual", res);
    waitKey(0);
    return 0;
}
