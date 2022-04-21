#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char new_image[SIZE][SIZE];

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

//_________________________________________
void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}

//_________________________________________
void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}
void detect_image_edges() {
  for (int j = 0; j < SIZE-1; j++)
  {
    for (int i = 0; i< SIZE-1; i++) 
    {
      if(image[i][j]==image[i+1][j+1])
      {
        new_image[i][j]=image[i][j];
      }
      if((abs(image[i][j]-image[i+1][j]>=24))||(abs(image[i][j]-image[i][j+1]>=24))){
        new_image[i][j]=0;
      }
      else{
        new_image[i][j]=255;
      }
    }
  }
  for (int j = 0; j < SIZE-1; j++)
  {
    for (int i = 0; i< SIZE-1; i++) {
      image[i][j]=new_image[i][j];

    }
  }
}