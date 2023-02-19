#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int label = 0, size = 0;
// labelarr[ULONG_MAX-1];

float dicecoffiecient(float** arr, int rows, int cols) {
	Mat image_tru = imread("IMD427_lesion.bmp");
	/*imshow("Display Window", image);
	waitKey(0);*/
	float DC = 0.000000000000000000000000000;
	float n = 0.0;
	float tp = 0.0, fp = 0.0, fn = 0.0;
	float** matrix_tru = new float* [image_tru.rows];
	image_tru.convertTo(image_tru, CV_32F);
	for (int k = 0; k < image_tru.rows; k++) {
		matrix_tru[k] = new float[image_tru.cols];
	}
	for (int i = 0; i < image_tru.rows; i++)
	{

		for (int j = 0; j < image_tru.cols; j++)
		{
			matrix_tru[i][j] = image_tru.at<float>(i, j);
		}
	}

	for (int i = 0; i < image_tru.rows; i++) {
		for (int j = 0; j < image_tru.cols; j++) {
			if (matrix_tru[i][j] == 255) {
				if (arr[i][j] == 255) {
					tp++;
				}
				else if (arr[i][j] == 255) {
					fn++;
				}
			}
			else if (matrix_tru[i][j] == 0) {
				if (arr[i][j] == 255) {
					fp++;
				}

			}
		}
	}
	n = 2 * tp;
	DC = n / (fn + n + fp);
	return DC;
}

int addlabel() {
	label++;
	//size++;
	//labelarr[size];
	return label;
}
int main()
{


	//for 5x5
	//int matrix[5][5] = { { 0,0,0,0,0 }, { 0, 255, 0, 255, 0}, {0, 0, 255, 0, 0}, {0, 0, 0, 0, 0}, { 255, 0, 0, 255, 255} };
	//cout << "Original Array\n";
	//for (int i = 0; i < 5; i++)
	//{
	//	for (int j = 0; j < 5; j++)
	//	{
	//		cout << matrix[i][j] << "  ";
	//	}
	//	cout << endl;
	//}
	//cout << endl;


	//for (int a = 0; a < 5; a++) {
	//	for (int b = 0; b < 5; b++) {	
	//		if (matrix[a][b] == 255) {
	//			if (a == 0 && b == 0) {
	//				//0 white neighbours add label;
	//				//call newlabel
	//				matrix[a][b] = addlabel();
	//			}
	//			else if (b > 0 && a == 0) {
	//				//0/1 white neighbours
	//				int temp = -1;
	//				if (matrix[a][b - 1] != 0) {
	//					temp = matrix[a][b - 1];
	//				}
	//				if (temp == -1) {
	//					//called newlabel
	//					matrix[a][b] = addlabel();
	//				}
	//				else {
	//					if (temp != -1) {
	//						matrix[a][b] = temp;
	//					}
	//				}


	//			}
	//			else if (b == 0 && a > 0) {
	//				//0/1/2 white neighbours
	//				int temp[2] = { -1,-1 };
	//				if (matrix[a - 1][b] != 0) {
	//					temp[0] = matrix[a - 1][b];
	//				}
	//				if (matrix[a - 1][b + 1] != 0) {
	//					temp[1] = matrix[a - 1][b + 1];
	//				}
	//				if (temp[0] == -1 && temp[1] == -1) {
	//					//called newlabel
	//					matrix[a][b] = addlabel();
	//				}
	//				else {


	//					if (temp[0] != -1) {
	//						matrix[a][b] = temp[0];
	//					}
	//					if (temp[1] != -1) {
	//						if (temp[0] != -1) {
	//							matrix[a - 1][b + 1] = temp[0];
	//						}
	//						else
	//							matrix[a][b] = temp[1];
	//					}
	//				}
	//			}

	//			else if (a == 5 - 1 && b > 0) {
	//				//0/1/2/3 white neighours
	//				int temp[3] = { -1,-1,-1 };
	//				if (matrix[a - 1][b - 1] != 0) {
	//					temp[0] = matrix[a - 1][b - 1];
	//				}
	//				if (matrix[a - 1][b] != 0) {
	//					temp[1] = matrix[a - 1][b];
	//				}
	//				if (matrix[a][b - 1] != 0)
	//				{
	//					temp[2] = matrix[a][b - 1];
	//				}
	//				if (temp[0] == -1 && temp[1] == -1 && temp[2] == -1) {
	//					//called newlabel
	//					matrix[a][b] = addlabel();
	//				}
	//				else {
	//					if (temp[0] != -1) {
	//						matrix[a][b] = temp[0];
	//					}
	//					if (temp[1] != -1) {
	//						if (temp[0] != -1) {
	//							matrix[a - 1][b] = temp[0];
	//						}
	//						else
	//							matrix[a][b] = temp[1];
	//					}
	//					if (temp[2] != -1) {
	//						if (temp[0] != -1) {
	//							matrix[a][b - 1] = temp[0];
	//						}
	//						else if (temp[1] != -1) {
	//							matrix[a][b - 1] = temp[1];
	//						}
	//						else
	//							matrix[a][b] = temp[2];
	//					}
	//				}
	//			}
	//			else {
	//				//0/1/2/3/4 white neighbours
	//				int temp[4] = { -1,-1,-1,-1 };
	//				if (matrix[a - 1][b - 1] != 0) {
	//					temp[0] = matrix[a - 1][b - 1];
	//				}
	//				if (matrix[a - 1][b] != 0) {
	//					temp[1] = matrix[a - 1][b];
	//				}
	//				if (matrix[a - 1][b + 1] != 0)
	//				{
	//					temp[2] = matrix[a - 1][b + 1];
	//				}
	//				if (matrix[a][b - 1] != 0)
	//				{
	//					temp[3] = matrix[a][b - 1];
	//				}
	//				/*for (int i = 0; i < 4; i++) {
	//					cout << temp[i];
	//				}
	//				cout << endl;*/
	//				if (temp[0] == -1 && temp[1] == -1 && temp[2] == -1 && temp[3] == -1) {
	//					matrix[a][b] = addlabel();
	//				}
	//				else {


	//					if (temp[0] != -1) {
	//						matrix[a][b] = temp[0];
	//					}
	//					if (temp[1] != -1) {
	//						if (temp[0] != -1) {
	//							matrix[a - 1][b] = temp[0];
	//						}
	//						else
	//							matrix[a][b] = temp[1];
	//					}
	//					if (temp[2] != -1) {
	//						if (temp[0] != -1) {
	//							matrix[a - 1][b + 1] = temp[0];
	//						}
	//						else if (temp[1] != -1) {
	//							matrix[a - 1][b + 1] = temp[1];
	//						}
	//						else
	//							matrix[a][b] = temp[2];
	//					}
	//					if (temp[3] != -1) {
	//						if (temp[0] != -1) {
	//							matrix[a][b - 1] = temp[0];
	//						}
	//						else if (temp[1] != -1) {
	//							matrix[a][b - 1] = temp[1];
	//						}
	//						else if (temp[2] != -1) {
	//							matrix[a][b - 1] = temp[2];
	//						}
	//						else
	//							matrix[a][b] = temp[3];
	//					}

	//				}
	//			}

	//		}
	//		/*	else
	//				continue;*/
	//	}
	//}
	////for 5x5
	//cout << "Array after adding labels\n";
	//for (int i = 0; i < 5; i++)
	//{
	//	for (int j = 0; j < 5; j++)
	//	{
	//		cout << matrix[i][j] << "  ";
	//	}
	//	cout << endl;
	//}

	//int count = 0;
	//for (int i = 0; i < 5; i++)
	//{
	//	for (int j = 0; j < 5; j++)
	//	{
	//		if (matrix[i][j] != 0) {
	//			count++;
	//		}
	//	}

	//}
	//int* labelarr = new int[count];
	//int k = 0;
	//for (int i = 0; i < 5; i++)
	//{
	//	for (int j = 0; j < 5; j++)
	//	{
	//		if (matrix[i][j] != 0) {
	//			labelarr[k] = matrix[i][j];
	//			k++;
	//		}
	//	}

	//}
	//cout << "Total labels: " << count << endl;

	//for (int i = 0; i < count; i++) {
	//	cout << labelarr[i] << " ";
	//}
	//cout << endl;

	//int maxfreq = 0;
	//int most_frequent;
	//for (int i = 0; i < 5; i++) {
	//	int c = 0;
	//	for (int j = 0; j < 5; j++) {
	//		if (labelarr[i] == labelarr[j])
	//			c++;
	//	}

	//	if (c > maxfreq) {
	//		maxfreq = c;
	//		most_frequent = labelarr[i];
	//	}
	//}	


	//cout << "label appearing maximum times: " << most_frequent << "\n";

	//for (int i = 0; i < 5; i++)
	//{
	//	for (int j = 0; j < 5; j++)
	//	{
	//		if (matrix[i][j] == most_frequent) {
	//			matrix[i][j] = 255;
	//		}
	//		else
	//			matrix[i][j] = 0;
	//	}

	//}
	//cout << "Final\n";
	//for (int i = 0; i < 5; i++)
	//{
	//	for (int j = 0; j < 5; j++)
	//	{
	//		cout << matrix[i][j] << "  ";
	//	}
	//	cout << endl;
	//}
	//
	
	//for original
	
	Mat image = imread("mIMD427.bmp");
	
	/*imshow("Display Window", image);
	waitKey(0);*/
	
	float** matrix = new float* [image.rows];
	
	image.convertTo(image, CV_32F);
	
	for (int k = 0; k < image.rows; k++) {
		matrix[k] = new float[image.cols];
	}
	
	for (int i = 0; i < image.rows; i++)
	{
		for (int j = 0; j < image.cols; j++)
		{
			matrix[i][j]= image.at<float>(i, j);
		}
	}
 	for (int a = 0; a < image.rows; a++) {
		for (int b = 0; b < image.cols; b++) {
			if (matrix[a][b] == 255) {
				if (a == 0 && b == 0) {
					//0 white neighbours add label;
					//call newlabel
					matrix[a][b] = addlabel();
				}
				else if (b > 0 && a == 0) {
					//0/1 white neighbours
					int temp = -1;
					if (matrix[a][b - 1] != 0) {
						temp = matrix[a][b - 1];
					}
					if (temp == -1) {
						//called newlabel
						matrix[a][b] = addlabel();
					}
					else {
						if (temp != -1) {
							matrix[a][b] = temp;
						}
					}


				}
				else if (b == 0 && a > 0) {
					//0/1/2 white neighbours
					int temp[2] = { -1,-1 };
					if (matrix[a - 1][b] != 0) {
						temp[0] = matrix[a - 1][b];
					}
					if (matrix[a - 1][b + 1] != 0) {
						temp[1] = matrix[a - 1][b + 1];
					}
					if (temp[0] == -1 && temp[1] == -1) {
						//called newlabel
						matrix[a][b] = addlabel();
					}
					else {


						if (temp[0] != -1) {
							matrix[a][b] = temp[0];
						}
						if (temp[1] != -1) {
							if (temp[0] != -1) {
								matrix[a - 1][b + 1] = temp[0];
							}
							else
								matrix[a][b] = temp[1];
						}
					}
				}

				else if (a == image.cols - 1 && b > 0) {
					//0/1/2/3 white neighours
					int temp[3] = { -1,-1,-1 };
					if (matrix[a - 1][b - 1] != 0) {
						temp[0] = matrix[a - 1][b - 1];
					}
					if (matrix[a - 1][b] != 0) {
						temp[1] = matrix[a - 1][b];
					}
					if (matrix[a][b - 1] != 0)
					{
						temp[2] = matrix[a][b - 1];
					}
					if (temp[0] == -1 && temp[1] == -1 && temp[2] == -1) {
						//called newlabel
						matrix[a][b] = addlabel();
					}
					else {
						if (temp[0] != -1) {
							matrix[a][b] = temp[0];
						}
						if (temp[1] != -1) {
							if (temp[0] != -1) {
								matrix[a - 1][b] = temp[0];
							}
							else
								matrix[a][b] = temp[1];
						}
						if (temp[2] != -1) {
							if (temp[0] != -1) {
								matrix[a][b - 1] = temp[0];
							}
							else if (temp[1] != -1) {
								matrix[a][b - 1] = temp[1];
							}
							else
								matrix[a][b] = temp[2];
						}
					}
				}
				else {
					//0/1/2/3/4 white neighbours
					int temp[4] = { -1,-1,-1,-1 };
					if (matrix[a - 1][b - 1] != 0) {
						temp[0] = matrix[a - 1][b - 1];
					}
					if (matrix[a - 1][b] != 0) {
						temp[1] = matrix[a - 1][b];
					}
					if (matrix[a - 1][b + 1] != 0)
					{
						temp[2] = matrix[a - 1][b + 1];
					}
					if (matrix[a][b - 1] != 0)
					{
						temp[3] = matrix[a][b - 1];
					}
					/*for (int i = 0; i < 4; i++) {
						cout << temp[i];
					}
					cout << endl;*/
					if (temp[0] == -1 && temp[1] == -1 && temp[2] == -1 && temp[3] == -1) {
						matrix[a][b] = addlabel();
					}
					else {


						if (temp[0] != -1) {
							matrix[a][b] = temp[0];
						}
						if (temp[1] != -1) {
							if (temp[0] != -1) {
								matrix[a - 1][b] = temp[0];
							}
							else
								matrix[a][b] = temp[1];
						}
						if (temp[2] != -1) {
							if (temp[0] != -1) {
								matrix[a - 1][b + 1] = temp[0];
							}
							else if (temp[1] != -1) {
								matrix[a - 1][b + 1] = temp[1];
							}
							else
								matrix[a][b] = temp[2];
						}
						if (temp[3] != -1) {
							if (temp[0] != -1) {
								matrix[a][b - 1] = temp[0];
							}
							else if (temp[1] != -1) {
								matrix[a][b - 1] = temp[1];
							}
							else if (temp[2] != -1) {
								matrix[a][b - 1] = temp[2];
							}
							else
								matrix[a][b] = temp[3];
						}

					}
				}

			}
		
			/*else
				continue;*/
		}	
	}
	
	int count = 0;
	for (int i = 0; i < image.rows; i++)
	{
		for (int j = 0; j < image.cols; j++)
		{
			if (matrix[i][j] != 0) {
				count++;//calculating the total number of non black pixels to create an array for labels
			}
		}
		
	}
	int* labelarr = new int[count];
	int k = 0;
	for (int i = 0; i < image.rows; i++)
	{
		for (int j = 0; j < image.cols; j++)
		{
			if (matrix[i][j] != 0) {
				labelarr[k] = matrix[i][j];
				k++;
			}
		}

	}
	/*cout << "count: " << count << endl;

	for (int i = 0; i < count; i++) {
		cout << labelarr[i] << " ";
	}
	cout << endl;*/
	
	int maxfreq = 0;
	int most_frequent=0;
	for (int i = 0; i < count; i++) {
		int c = 0;
		for (int j = 0; j < count; j++) {
			if (labelarr[i] == labelarr[j])//comparing all the elements of label array to find the label with max frequency  
				c++;
		}

		if (c > maxfreq) {
			maxfreq = c;
			most_frequent = labelarr[i];
		}
	}

	
	cout<<"label appearing maximum times: "<< most_frequent << "\n";
	
	for (int i = 0; i < image.rows; i++)
	{
		for (int j = 0; j < image.cols; j++)
		{
			if (matrix[i][j] == most_frequent) {
				matrix[i][j] = 255;
			}
			else
				matrix[i][j] = 0;
		}
		
	}
	
	//cout << "Final\n";
	for (int i = 0; i < image.rows; i++)
	{
		for (int j = 0; j < image.cols; j++)
		{
			cout << matrix[i][j] << "  ";
		}
		//cout << endl;
	}
	for (int i = 0; i < image.rows; i++) {
		for (int j = 0; j < image.cols; j++)
			image.at<float>(i, j) = matrix[i][j];

	}
	//imshow("Display Window", image);
	//waitKey(0);

	//cout << "Dice Coffiecient: "<< dicecoffiecient(matrix, image.rows, image.cols) << endl;
	return 0;
}