#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];

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
   readGSBMP(imageFileName, image);
}

//_______________
void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}

//_______________
void black_and_white() {
    long avg = 0;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {

            avg += image[i][j];
            
        }
    }

    avg /= (SIZE * SIZE);

    cout << "The Average is: " << avg << endl;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {

            if (image[i][j] > avg)
            {

                image[i][j] = 255;
            }
            else
            {

                image[i][j] = 0;
            }
        }
    }
}