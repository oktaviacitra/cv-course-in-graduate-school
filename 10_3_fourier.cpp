
#include <math.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    Mat img;
    Mat input(Size(100, 100), CV_8UC1);
    Mat inputf(Size(100, 100), CV_32FC1);
    int i, j, k, l;
    
    double temp_re, temp_im, re, im;
    double pi = 3.1427;
    img = imread("sunflowers.jpg", 0);
    if (!img.data)
    {
        return -1;
    }
    resize(img, input, input.size(), 0, 0, 1);
    input.convertTo(inputf, CV_32FC1, 1, 0);
    Mat output(input.size().width, input.size().height, CV_32FC1);
    imshow("Input Image", input);
    // Fourier sumbu x
    for(i=0;i<input.size().height;i++)
    {
        for (j = 0; j < input.size().width; j++)
        {
            temp_re = 0; temp_im = 0;
            for (k = 0; k < input.size().height; k++)
            {
                for (l = 0; l < input.size().width; l++)
                {
                    re = inputf.at<float>(l, k)*cos(2 * pi*(((float)i*(float)k / (float)input.size().width) + ((float)j*(float)l / (float)input.size().height)));
                    
                    temp_re += re;
                    im = inputf.at<float>(l, k)*sin(2 * pi*(((float)i*(float)k / (float)input.size().width) + ((float)j*(float)l / (float)input.size().height)));
                    temp_im += im;
                }
            }
            output.at<float>(j, i) = 5 * (1.f / (float)sqrt((float)input.size().width*(float)input.size().height))*log(sqrt(pow((float)temp_re, 2) + pow((float)temp_im, 2)) + 1);
            printf("%.2f\t", output.at<float>(j, i));
        }
        printf("\n");
    }
    imshow("Output Image", output);
    imwrite("fourier.bmp", output);
    waitKey(50000);
    return 0;
}
