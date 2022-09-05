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

### a.cpp
Draw and Write
<img width="400" alt="Screen Shot 2022-09-04 at 20 12 57" src="https://user-images.githubusercontent.com/49669018/188315320-f23bf13f-4928-4e86-9633-eb298b35b5df.png">

### b.cpp
Region of Interest
<p>
<img width="250" alt="Screen Shot 2022-09-05 at 08 30 31" src="https://user-images.githubusercontent.com/49669018/188343350-9c0665d2-4e97-4c9e-b4d9-51a366cb34d1.png">
<img width="152" alt="Screen Shot 2022-09-05 at 08 31 14" src="https://user-images.githubusercontent.com/49669018/188343356-127177d5-fc94-446b-8178-b61165a61fd7.png">
</p>

### c.cpp
Mouse Events
<img width="200" alt="Screen Shot 2022-09-05 at 08 38 22" src="https://user-images.githubusercontent.com/49669018/188343736-22a584af-7395-42ab-9bae-05cfec6a0319.png">

### d.cpp
Trackbar (Slider) Control
<img width="200" alt="Screen Shot 2022-09-05 at 08 39 05" src="https://user-images.githubusercontent.com/49669018/188343792-20b8374d-6032-4cbc-b782-63dc54fe5979.png">

### e.cpp
Moving Around Video with Slider
<img width="200" alt="Screen Shot 2022-09-05 at 08 34 19" src="https://user-images.githubusercontent.com/49669018/188343893-e305652e-9bd7-4927-a9d1-74a7c124ae09.png">

### f.cpp
Write Video in A File
<img width="1348" alt="Screen Shot 2022-09-05 at 08 29 08" src="https://user-images.githubusercontent.com/49669018/188343966-40b60853-5431-41bd-b871-7c4a4c5778fb.png">


