# Computer Vision Project - README
 
## Overview
This project implements a computer vision application using **OpenCV** to demonstrate key concepts such as feature detection and manipulation of images. The project was developed using **C++** with **Code::Blocks** and **OpenCV 4.10.0** on **Windows**.

## Assignment Objectives
The assignment has three parts: key point detection, feature description, and feature matching.

1. **Keypoint detection**: Identify points of interest in the image using the Harris corner detection method. 
2. **Feature description**: Find scale-invariant feature transform (SIFT) descriptor at each key point. 
3. **Feature matching**: Find the matching features with sum of squared differences (SSD) and ratio distance. For ratio distance, find the closest and second closest features by SSD distance. The ratio distance is their ratio (i.e., SSD distance of the closest feature match divided by SSD distance of the second closest feature match).




https://github.com/user-attachments/assets/ece55b18-b64c-455d-b491-0785ecb0c07a



## Prerequisites
- **OpenCV 4.10.0** (with extra modules, including `xfeatures2d`)
- **MinGW** as the compiler
- **Code::Blocks** as the IDE
- **CMake** for generating the OpenCV build with extra modules
- Properly configured environment variables for OpenCV

## Installation & Setup

1. **OpenCV Installation**:
   - Download and build OpenCV with extra modules (especially `xfeatures2d`) using **CMake**.
   - Ensure `BUILD_opencv_xfeatures2d` is checked during the build process in CMake.
   - Build OpenCV with **MinGW** and use **multithreading** by specifying `-j4` (for your 4 logical processors).

2. **Compiler Settings**:
   - Set up **MinGW** as the toolchain for **Code::Blocks**.
   - In **Linker Settings**, make sure to link all the required OpenCV libraries. Use the `.dll.a` files for MinGW instead of `.lib`.
   - Set your path to include `C:\opencv\build\bin` in the system environment variables so that the OpenCV DLLs can be found.

3. **Code Compilation**:
   - Ensure your project references all necessary OpenCV headers (like `opencv2/core.hpp`, `opencv2/highgui.hpp`, etc.).
   - When encountering linker issues such as missing symbols (`LNK2019`), ensure all required libraries (e.g., `opencv_core`, `opencv_imgproc`, `opencv_highgui`, `opencv_features2d`) are linked properly.

4. **Handling DLL Issues**:
   - After building, ensure that the necessary OpenCV DLL files (such as `libopencv_features2d4100.dll`) are present and accessible in your environment path or the executable folder.

5. **Running the Program**:
   - Ensure that image files such as `img1.jpg` are placed in the correct directory from where the executable can access them.
   - If the program reports file path errors (e.g., `can't open/read file`), verify the integrity and location of the image files.

## Key Steps & Issues Encountered
1. **CMake Configuration**: Used to configure and generate the OpenCV build with extra modules.
2. **Multithreaded Build**: Compiled OpenCV using 4 threads with `-j4` for faster build.
3. **Linker & Compiler Errors**:
   - Resolved missing symbols and undefined references by ensuring the correct OpenCV libraries were linked.
4. **DLL Issues**: Added `C:\opencv\build\bin` to system environment variables to resolve missing DLL issues.
5. **File Path Errors**: Encountered issues reading images, fixed by placing image files in the correct folder.

## Conclusion
This project successfully demonstrates how to build and use OpenCV for computer vision tasks such as feature detection, description, and matching. All challenges, including build errors, DLL issues, and file handling, were resolved, and the final output was achieved.

---

