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
void Mirror_Image ();

int main()
{
  loadImage();
  Mirror_Image();
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

void Mirror_Image() {
    unsigned char new_image[SIZE][SIZE][3];
    int x=SIZE;
    int y=SIZE/2;
    int z=SIZE/4;
    int n;
    cout<<"Please choose how you want to Mirror the image"<<endl;
    cout<<"1-Left 1/2"<<endl;
    cout<<"2-Right 1/2"<<endl;
    cout<<"3-Upper 1/2"<<endl;
    cout<<"4-Lower 1/2"<<endl;
    cin>>n;
    if (n==1){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 255; j>SIZE/2; j--) {
                for(int k=0; k<3; k++){
                    new_image[i][j][k]=image[i][x-j][k];
                }
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 255; j> SIZE/2; j--) {
                for(int k=0;k<3; k++){
                image[i][j][k]=new_image[i][j][k];
            }
        }
        }
    }
    if (n==2){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE/2; j++) {
                for(int k=0; k<3; k++){
                new_image[i][j][k]=image[i][x-j][k];
                }
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE/2; j++) {
                for (int k=0;k<3;k++){
                image[i][j][k]=new_image[i][j][k];
                }
            }
        }
    }
    if (n==3){
        for (int i = 255; i > SIZE/2; i--) {
            for (int j = 0; j <SIZE; j++) {
                for (int k=0; k<3; k++){
                new_image[i][j][k]=image[x-i][j][k];
                }
            }
        }
        for (int i = 255; i > SIZE/2; i--) {
            for (int j = 0; j< SIZE; j++) {
                for (int k=0; k<3; k++){
                image[i][j][k]=new_image[i][j][k];
                }

            }
        }
    }
    if (n==4){
        for (int i = 0; i < SIZE/2; i++) {
            for (int j = 0; j< SIZE; j++) {
                for (int k=0; k<3; k++){
                new_image[i][j][k]=image[x-i][j][k];
                }
            }
        }
        for (int i = 0; i < SIZE/2; i++) {
            for (int j = 0; j< SIZE; j++) {
                for(int k=0; k<3; k++){
                image[i][j][k]=new_image[i][j][k];

                }

            }
        }
    }

}