#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE][3];

void loadImage ();
void saveImage ();
void black_and_white();

int main()
{
  loadImage();
  black_and_white();
  saveImage();
  return 0;
}

//_______________
void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readRGBBMP(imageFileName, image);
}

//_______________
void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeRGBBMP(imageFileName, image);
}

//_______________
void black_and_white() {
    long avg = 0;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                avg += image[i][j][k];
            }

            
        }
    }

    avg /= (SIZE * SIZE *3);

    cout << "The Average is: " << avg << endl;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < 3; k++){
                if (image[i][j][k]> avg){
                        image[i][j][0] = 255;
                        image[i][j][1] = 255;
                        image[i][j][2] = 255;
                    }
                if (image[i][j][k]<avg){
                        image[i][j][0] = 0;
                        image[i][j][1] = 0;
                        image[i][j][2] = 0;
                }
            }
        }
    }
}