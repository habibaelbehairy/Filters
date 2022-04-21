#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE][3];
unsigned char new_image[SIZE][SIZE][3];

void loadImage ();
void saveImage ();
void detect_image_edges();

int main()
{
  loadImage();
  detect_image_edges();
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


void detect_image_edges() {
  for (int j = 0; j < SIZE-1; j++)
  {
    for (int i = 0; i< SIZE-1; i++) 
    {
        for(int k=0; k<3; k++){
            if(image[i][j][3]==image[i+1][j+1][3])
            {
                new_image[i][j][k]=image[i][j][k];

            }
            if((abs(image[i][j][3]-image[i+1][j][3]>=15))||(abs(image[i][j][3]-image[i][j+1][3]>=15)))
            {
                new_image[i][j][k]=0;
            }
            else
            {
                new_image[i][j][k]=255;
            }
        }
    }
  }
  for (int j = 0; j < SIZE-1; j++)
  {
    for (int i = 0; i< SIZE-1; i++)
    {
        for(int k=0; k<3; k++)
        {
            image[i][j][k]=new_image[i][j][k];
        }

    }
  }
}