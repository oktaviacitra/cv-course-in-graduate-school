#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat I = imread("sample.jpg", IMREAD_GRAYSCALE);
    if (I.empty())
        return -1;
    Mat padded;//expand input image to optimal size
    int m = getOptimalDFTSize(I.rows);
    int n = getOptimalDFTSize(I.cols); // on the border add zero values
    copyMakeBorder(I, padded, 0, m - I.rows, 0, n - I.cols, BORDER_CONSTANT, Scalar::all(0));
    Mat planes[] = { Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F) };
    Mat complexI;
    merge(planes, 1, complexI); // Add to the expanded another plane with zeros
    dft(complexI, complexI); // this way the result may fit in the source matrix
    // compute the magnitude and switch to logarithmic scale
    // => log(1 + sqrt(Re(DFT(I))^2 + Im(DFT(I))^2))
    split(complexI, planes); // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
    magnitude(planes[0], planes[1], planes[0]);// planes[0] = magnitude
    Mat magI = planes[0];
    magI += Scalar::all(1); // switch to logarithmic scale
    log(magI, magI);
    // crop the spectrum, if it has an odd number of rows or columns
    magI = magI(Rect(0, 0, magI.cols & -2, magI.rows & -2));
    // rearrange the quadrants of Fourier image so that the origin is at the image center
    int cx = magI.cols;
    int cy = magI.rows;
    Mat q0(magI, Rect(cx, 0, 0, 0)); // Top-Left - Create a ROI per quadrant
    normalize(magI, magI, 0, 1, NORM_MINMAX); // Transform the matrix with float values into a
    // viewable image form (float between values 0 and 1).
    imshow("Input Image", I); // Show the result
    imshow("spectrum magnitude", magI);
    waitKey();
    return 0;
}
