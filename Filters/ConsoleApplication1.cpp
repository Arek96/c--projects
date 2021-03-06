#include "stdafx.h"

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	// Read the image file
	Mat image = imread("D:/panorama.jpg");

	// Check for failure
	if (image.empty())
	{
		cout << "Could not open or find the image" << endl;
		cin.get(); //wait for any key press
		return -1;
	}
	//sobel START


	Mat grey;
	cvtColor(image, grey, CV_BGR2GRAY);

	Mat sobelx;
	Sobel(grey, sobelx, CV_32F, 1, 0);

	bool Success = imwrite("D:/Sobel.jpg", sobelx); //write the image to a file as JPEG 
														//bool isSuccess = imwrite("D:/MyImage.png", image); //write the image to a file as PNG
	if (Success == false)
	{
		cout << "Failed to save the image" << endl;
		cin.get(); //wait for a key press
		return -1;
	}

	cout << "Image is succusfully saved to a file" << endl;

	//sobelEND
	
	for (int i = 0; i<image.cols*3; i++)
	{
		for (int j = 0; j<image.rows; j++)
		{
			Scalar color1 = image.at<uchar>(Point(i, j));
			Scalar color2 = image.at<uchar>(Point(i, j));
			color2.val[0] = 255 - color1.val[0];

			image.at<uchar>(Point(i, j)) = color2.val[0];
		}
	}
	bool isSuccess = imwrite("D:/Negative.jpg", image); //write the image to a file as JPEG 
													   //bool isSuccess = imwrite("D:/MyImage.png", image); //write the image to a file as PNG
	if (isSuccess == false)
	{
		cout << "Failed to save the image" << endl;
		cin.get(); //wait for a key press
		return -1;
	}

	cout << "Image is succusfully saved to a file" << endl;

//blur START
	Mat dst;
	for (int i = 1; i < 31; i = i + 2)
	{

		//smooth the image in the "src" and save it to "dst"
		blur(image, dst, Size(i, i));		
	}
	bool isSucces = imwrite("D:/Blured.jpg", dst); //write the image to a file as JPEG 
														//bool isSuccess = imwrite("D:/MyImage.png", image); //write the image to a file as PNG
	if (isSucces == false)
	{
		cout << "Failed to save the image" << endl;
	}

	cout << "Image is succusfully saved to a file" << endl;
	//blur END
	String windowName = "The Guitar"; //Name of the window

	 // Create a window

	imshow(windowName, image); // Show our image inside the created window.

	waitKey(0); // Wait for any keystroke in the window
	system("pause");
	destroyWindow(windowName); //destroy the created window

	
	return 0;
}