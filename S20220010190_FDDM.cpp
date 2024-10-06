#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>  // Use features2d instead of xfeatures2d for SIFT
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // Load input image
    Mat img = imread("img1.jpg", IMREAD_GRAYSCALE);
    if (img.empty()) {
        cout << "Error loading image!" << endl;
        return -1;
    }

    // 1. Keypoint Detection using Harris Corner
    Mat harrisCorners, harrisNormalized;
    harrisCorners = Mat::zeros(img.size(), CV_32FC1);

    cornerHarris(img, harrisCorners, 2, 3, 0.04);
    normalize(harrisCorners, harrisNormalized, 0, 255, NORM_MINMAX, CV_32FC1, Mat());

    // Convert to 8-bit image
    Mat harrisScaled;
    convertScaleAbs(harrisNormalized, harrisScaled);

    // Mark corners on the image
    for (int i = 0; i < harrisNormalized.rows; i++) {
        for (int j = 0; j < harrisNormalized.cols; j++) {
            if ((int)harrisNormalized.at<float>(i, j) > 200) {
                circle(img, Point(j, i), 5, Scalar(255), 2);
            }
        }
    }

    // 2. Feature Description using SIFT (from features2d, not xfeatures2d)
    Ptr<SIFT> sift = SIFT::create();
    vector<KeyPoint> keypoints;
    Mat descriptors;

    sift->detectAndCompute(img, noArray(), keypoints, descriptors);

    // Draw keypoints on the image
    Mat imgKeypoints;
    drawKeypoints(img, keypoints, imgKeypoints, Scalar::all(-1), DrawMatchesFlags::DEFAULT);

    // 3. Feature Matching using SSD and Ratio Distance
    Mat img2 = imread("img2.jpg", IMREAD_GRAYSCALE);
    if (img2.empty()) {
        cout << "Error loading second image!" << endl;
        return -1;
    }

    vector<KeyPoint> keypoints2;
    Mat descriptors2;
    sift->detectAndCompute(img2, noArray(), keypoints2, descriptors2);

    BFMatcher matcher(NORM_L2);
    vector<vector<DMatch>> knnMatches;
    matcher.knnMatch(descriptors, descriptors2, knnMatches, 2);

    vector<DMatch> goodMatches;
    for (size_t i = 0; i < knnMatches.size(); i++) {
        if (knnMatches[i][0].distance < 0.75 * knnMatches[i][1].distance) {
            goodMatches.push_back(knnMatches[i][0]);
        }
    }

    // Draw matches
    Mat imgMatches;
    drawMatches(img, keypoints, img2, keypoints2, goodMatches, imgMatches, Scalar::all(-1), Scalar::all(-1), vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);

    // Show results
    imshow("Harris Corners", harrisScaled);
    imshow("Keypoints", imgKeypoints);
    imshow("Matches", imgMatches);

    waitKey(0);
    return 0;
}
