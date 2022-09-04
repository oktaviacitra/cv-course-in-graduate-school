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
<img width="400" alt="Screen Shot 2022-09-04 at 20 12 57" src="https://user-images.githubusercontent.com/49669018/188315320-f23bf13f-4928-4e86-9633-eb298b35b5df.png">
