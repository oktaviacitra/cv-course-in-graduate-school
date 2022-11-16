# Computer Vision

### How to Install OpenCV C++ on Terminal MacOS
```
brew install opencv
brew install pkg-config
pkg-config --cflags --libs opencv4
cd /usr/local/Cellar/opencv/4.6.0/lib/pkgconfig
pkg-config --cflags --libs opencv4.pc
```

### How to Create C++ on Terminal MacOS
```
touch <file-name>.cpp
nano <file-name>.cpp
```

### How to Run C++ Program on Terminal MacOS
```
g++ $(pkg-config --cflags --libs opencv4) -std=c++11  <file-name>.cpp -o <file-name>
./<file-name>
```

### ReadImage.cpp
<img width="150" alt="Screen Shot 2022-08-31 at 15 31 20" src="https://user-images.githubusercontent.com/49669018/187645344-c46934b2-aad2-402b-b7c6-1880defddad8.png">

### a.cpp (Draw and Write)
<img width="400" alt="Screen Shot 2022-09-04 at 20 12 57" src="https://user-images.githubusercontent.com/49669018/188315320-f23bf13f-4928-4e86-9633-eb298b35b5df.png">

### b.cpp (Region of Interest)
<p>
<img width="250" alt="Screen Shot 2022-09-05 at 08 30 31" src="https://user-images.githubusercontent.com/49669018/188343350-9c0665d2-4e97-4c9e-b4d9-51a366cb34d1.png">
<img width="152" alt="Screen Shot 2022-09-05 at 08 31 14" src="https://user-images.githubusercontent.com/49669018/188343356-127177d5-fc94-446b-8178-b61165a61fd7.png">
</p>

### c.cpp (Mouse Events)
<img width="200" alt="Screen Shot 2022-09-05 at 08 38 22" src="https://user-images.githubusercontent.com/49669018/188343736-22a584af-7395-42ab-9bae-05cfec6a0319.png">

### d.cpp (Trackbar (Slider) Control)
<img width="200" alt="Screen Shot 2022-09-05 at 08 39 05" src="https://user-images.githubusercontent.com/49669018/188343792-20b8374d-6032-4cbc-b782-63dc54fe5979.png">

### e.cpp (Moving Around Video with Slider)
<img width="200" alt="Screen Shot 2022-09-05 at 08 34 19" src="https://user-images.githubusercontent.com/49669018/188343893-e305652e-9bd7-4927-a9d1-74a7c124ae09.png">

### f.cpp (Write Video in A File)
<img width="500" alt="Screen Shot 2022-09-05 at 08 29 08" src="https://user-images.githubusercontent.com/49669018/188343966-40b60853-5431-41bd-b871-7c4a4c5778fb.png">

### 3-1.cpp (Read Video File)
<img width="100" alt="Screen Shot 2022-09-07 at 08 39 05" src="https://user-images.githubusercontent.com/49669018/188776368-1d52cac1-9164-4ac7-97db-58912ab01c9d.png">

### 3-2.cpp (Access Camera)
<img width="400" alt="Screen Shot 2022-09-07 at 09 02 55" src="https://user-images.githubusercontent.com/49669018/188776493-487c3f5a-73e8-4f38-b52c-35c480408bc9.png">

### 3-3.cpp (Write Video)
<p>
<img width="400" alt="Screen Shot 2022-09-07 at 09 04 45" src="https://user-images.githubusercontent.com/49669018/188776530-5b680d1b-1c9a-4558-88ea-9a15c4b28145.png">
<img width="150" alt="Screen Shot 2022-09-07 at 09 05 30" src="https://user-images.githubusercontent.com/49669018/188776568-add59249-0d88-4d3a-b70d-94fe02aa90e5.png">
</p>

### 3-4.cpp (Modified Video with Animation)
<p>
<img width="400" alt="Screen Shot 2022-09-07 at 09 05 49" src="https://user-images.githubusercontent.com/49669018/188776716-07303ab3-6f45-4b2d-be12-93bae306da9e.png">
<img width="150" alt="Screen Shot 2022-09-07 at 09 07 09" src="https://user-images.githubusercontent.com/49669018/188776760-3c71b7b9-7670-4b22-8bdc-e0f339e0e9e3.png">
</p>

### 4-1.cpp (Brightness & Contrast)
<img width="175" alt="Screen Shot 2022-09-14 at 13 10 22" src="https://user-images.githubusercontent.com/49669018/190078373-054dbb81-e55c-45dc-8829-7c60119d3cae.png">

### 4-2.cpp (Color Transformation)
<img width="200" alt="Screen Shot 2022-09-14 at 10 01 49" src="https://user-images.githubusercontent.com/49669018/190078617-38224b8c-eeb3-4389-9abc-a4ea54c7f8bf.png">

### 4-2-a.cpp (Color Transformation)
<img width="200" alt="Screen Shot 2022-09-14 at 10 02 12" src="https://user-images.githubusercontent.com/49669018/190078709-6d874cda-5cb5-4ac1-8183-0f1c4f7a9828.png">

### 4-2-b.cpp (Color Transformation)
<img width="400" alt="Screen Shot 2022-09-14 at 10 08 06" src="https://user-images.githubusercontent.com/49669018/190078821-48dd345b-1e2c-4fd3-9f31-4fef2e002f81.png">

### 4-2-c.cpp (Color Transformation)
<img width="268" alt="Screen Shot 2022-09-14 at 10 09 05" src="https://user-images.githubusercontent.com/49669018/190078907-5d7cbb94-d269-48f9-b517-aeb3a2430c9e.png">

### 4-3.cpp (Compositing and Mating)
<img width="150" alt="Screen Shot 2022-09-14 at 10 10 09" src="https://user-images.githubusercontent.com/49669018/190078977-29721080-3a0b-414a-94cc-927cdf8b819a.png">

### 4-3-a.cpp (Compositing and Mating)
<img width="150" alt="Screen Shot 2022-09-14 at 10 10 42" src="https://user-images.githubusercontent.com/49669018/190080030-6e42425c-012f-40f5-a895-ce397b4586cd.png">

### 4-4.cpp (Color Histogram)
<img width="150" alt="Screen Shot 2022-09-14 at 10 11 56" src="https://user-images.githubusercontent.com/49669018/190080082-4786bcc5-d0dd-4c4d-ae5d-2fafb643cb92.png">

### 4-4-a.cpp (Color Histogram)
<img width="150" alt="Screen Shot 2022-09-14 at 10 13 08" src="https://user-images.githubusercontent.com/49669018/190080143-983bb029-ef20-4696-bed2-cda90acf304e.png">

### 4-4-b.cpp (Color Histogram)
<img width="150" alt="Screen Shot 2022-09-14 at 10 14 37" src="https://user-images.githubusercontent.com/49669018/190080218-3db7feae-edb9-47bd-8232-0d946fa81681.png">

### 4-5.cpp (Color Histogram Equalization)
<img width="200" alt="Screen Shot 2022-09-14 at 10 15 10" src="https://user-images.githubusercontent.com/49669018/190080321-7f554125-021c-4657-8a3e-f386738253de.png">

### 4-5-a.cpp (Color Histogram Equalization)
<img width="200" alt="Screen Shot 2022-09-14 at 10 15 30" src="https://user-images.githubusercontent.com/49669018/190080389-5ce86011-c7ed-4b54-80f3-aa0e570e1108.png">

### 4-6.cpp (Create Color Histogram based on Webcam video)
<img width="300" alt="Screen Shot 2022-09-14 at 10 16 35" src="https://user-images.githubusercontent.com/49669018/190080471-fb4a7723-7e49-4a80-8d10-fd498d112c7f.png">

### 5-1.cpp (Blur)
<img width="200" alt="5-1" src="https://user-images.githubusercontent.com/49669018/191946028-b7ea8621-b471-4322-b095-855313685457.png">

### 5-2.cpp (Blur filter2D)
<img width="200" alt="5-2" src="https://user-images.githubusercontent.com/49669018/191946043-2ca4555b-b40b-4eb5-b10d-c103a881a22e.png">

### 5-3.cpp (Blur self-made)
<img width="200" alt="5-3" src="https://user-images.githubusercontent.com/49669018/191946049-d8925c5e-bd7a-40d8-838c-2c472f53084b.png">

### 5-4.cpp (gaussianblur)
<img width="200" alt="5-4" src="https://user-images.githubusercontent.com/49669018/191946052-f3e817a1-3d7f-47d8-80c9-116a65dc98e0.png">

### 5-5.cpp (medianBlur)
<img width="200" alt="5-5" src="https://user-images.githubusercontent.com/49669018/191946058-a2275953-710a-457a-8a4c-9a3dbbe93549.png">

### 5-6.cpp (Kuwahara filter)
<img width="200" alt="5-6" src="https://user-images.githubusercontent.com/49669018/191946063-c2e09cbe-37f1-4515-8eae-c78268b6cfb0.png">

### 5-7.cpp (sharpening)
<img width="200" alt="5-7" src="https://user-images.githubusercontent.com/49669018/191946064-5c914eb2-53c3-452e-aa1f-5c579f11e1a4.png">

### 5-8.cpp (sharpening gaussianblur)
<img width="200" alt="5-8" src="https://user-images.githubusercontent.com/49669018/191946069-bc041934-6128-4b30-bc73-0926eae54b1b.png">

### 5-9.cpp (edge)
<img width="200" alt="5-9" src="https://user-images.githubusercontent.com/49669018/191946075-03a87eca-97fb-450f-ba08-0f1ee29af23a.png">

### 5-9.cpp (edge Sobel filter2d)
<img width="200" alt="5-10" src="https://user-images.githubusercontent.com/49669018/191946087-d7f986bb-2a50-439e-8dc9-9592dc7f61e6.png">

### 5-10.cpp (edge Prewitt)
<img width="200" alt="5-11" src="https://user-images.githubusercontent.com/49669018/191946097-677ed8eb-fde4-484d-b36d-a8bb8567551b.png">

### 6-1.cpp (Dilation)
<img width="200" alt="6-1" src="https://user-images.githubusercontent.com/49669018/192718576-6c22bbc5-0cf2-4ce2-a804-2b25b3a43795.png">

### 6-1-4.cpp (Dilation)
<img width="150" alt="6-1-4" src="https://user-images.githubusercontent.com/49669018/192718586-2f3f5a7b-a45b-4d8e-b439-ae1c93e41a2f.png">

### 6-2.cpp  (Erosion)
<img width="150" alt="6-2" src="https://user-images.githubusercontent.com/49669018/192718592-a6daf077-de1f-4730-9ba4-3194174de313.png">

### 6-2-4.cpp (Erosion)
<img width="200" alt="6-2-4" src="https://user-images.githubusercontent.com/49669018/192718605-d0e9123b-eea0-4446-83e0-43cee39f3354.png">

### 6-3.cpp (Opening)
<img width="150" alt="6-3" src="https://user-images.githubusercontent.com/49669018/192718610-cb00425a-ddeb-46c0-8589-ac67f4cad069.png">

### 6-3-5.cpp (Opening)
<img width="200" alt="6-3-5" src="https://user-images.githubusercontent.com/49669018/192718615-3cf5330c-9542-47d1-a267-454997d8aa0b.png">

### 6-3-6.cpp (Closing)
<img width="150" alt="6-3-6" src="https://user-images.githubusercontent.com/49669018/192718617-d96f9106-5e71-4e9b-8884-a67c6da1168b.png">

### 6-3-10.cpp (Opening)
<img width="150" alt="6-3-10" src="https://user-images.githubusercontent.com/49669018/192718619-9dbe1ac1-9190-45b8-8b93-c539a69b9a62.png">

### 6-3.cpp (Distance Transform)
<img width="150" alt="6-4" src="https://user-images.githubusercontent.com/49669018/192718621-941bbe5a-4e75-4e3e-9489-d0c0f6df405f.png">

### 7_1_DiscreteFourierTransform2D.cpp
<img width="150" alt="Screen Shot 2022-10-26 at 08 54 22" src="https://user-images.githubusercontent.com/49669018/197916134-929a0625-867a-4f47-bc79-3f8243aac887.png">

### 7_1_A_SpectrumMagnitude.cpp
<img width="150" alt="Screen Shot 2022-10-26 at 08 55 20" src="https://user-images.githubusercontent.com/49669018/197916255-82e6671f-8974-4fb1-9394-07e52210ecfe.png">

### 7_1_B_Fourier1D.cpp
<img width="150" alt="Screen Shot 2022-10-26 at 08 56 27" src="https://user-images.githubusercontent.com/49669018/197916410-c09342d5-602d-44d4-a427-5d634108dd34.png">

### 8_1_Wavelet.cpp
<img width="500" alt="Screen Shot 2022-11-16 at 10 10 47" src="https://user-images.githubusercontent.com/49669018/202313188-29c09607-04dc-47c2-ad1b-306ace8da068.png">

### 8_2_Gabor.cpp
<img width="500" alt="Screen Shot 2022-11-16 at 10 14 47" src="https://user-images.githubusercontent.com/49669018/202313257-9450248a-b1ce-421c-a5ef-07459a0c7b23.png">
