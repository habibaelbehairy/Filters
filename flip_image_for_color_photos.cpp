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
void Flip_Image ();
int main()
{
  loadImage();
  Flip_Image();
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

//_________________________________________
void Flip_Image() {
       unsigned char new_image[SIZE][SIZE][3];
    char n;
    cout<<"Please choose how you want to flip (h)orizontally or (v)ertically"<<endl;
    cout<<"v-vertical flip"<<endl;
    cout<<"h-right flip"<<endl;
    cin>>n;
    if (n=='v'){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                for (int k=0; k<3 ; k++){
                    new_image[255-i][j][k]=image[i][j][k];
                }
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++){
                for (int k=0; k<3 ; k++){
                    image[i][j][k]=new_image[i][j][k];
                }
            }
        }
    }
    if (n=='h'){
        for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for (int k=0; k<3 ; k++){
            new_image[i][255-j][k]=image[i][j][k];
            }
        }
    }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++){
                for (int k=0; k<3 ; k++){
                image[i][j][k]=new_image[i][j][k];
            }
            }
        }
    }
}