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
    Mat fourier(100, 100, CV_8UC1);
    float pi = 3.14;
    float data[100][100], hasil[100][100];
    float temp1, temp2, re1, re2, im1, im2;
    int i, j, k, l;
    //membaca data piksel
    for (i = 0; i < 100; i++)
    {
        for (j = 0; j < 100; j++)
        {
            data[i][j] = I.at<uchar>(i, j); //printf("%.2f", data[i][j]);
        }
    } //fourier
    for (i = 0; i < 100; i++)
    {
        
        for (j = 0; j < 100; j++)
        {
            re1 = 0;
            im1 = 0; for (k = 0; k < 100; k++)
            {
                re2 = 0;
                im2 = 0;
                for (l = 0; l < 100; l++)
                {
                    re2 += data[k][l] * cos(j * l * 2 *
                                            
                                            3.14 / 100);
                    
                    im2 += data[k][l] * sin(j * l * 2 *
                                            
                                            3.14 / 100);
                }
                temp2 = sqrt(pow(re2, 2) + pow(im2, 2));
                re1 += temp2 * cos(i * k * 2 * 3.14 / 100);
                im1 += temp2 * sin(i * k * 2 * 3.14 / 100);
            }
            temp1 = sqrt(pow(re1, 2) + pow(im1, 2));
            hasil[i][j] = temp1;
            fourier.at<uchar>(i, j) = hasil[i][j];
        }
        printf("Proses ke- %d\n", i);
    }
    printf("done");
    imshow("Input", I);
    imshow("Fourier", fourier);
    imwrite("fourier.jpg", fourier);
    waitKey(0);
    return 0;
}
