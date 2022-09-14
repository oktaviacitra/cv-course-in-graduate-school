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

