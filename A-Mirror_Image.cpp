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
void Mirror_Image ();

int main()
{
  loadImage();
  Mirror_Image();
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

//_________________________________________
void Mirror_Image() {
    int x=SIZE;
    int y=SIZE/2;
    int z=SIZE/4;
    char user_choice;
    cout<<"Please choose how you want to Mirror the image"<<endl;
    cout<<"l-Left 1/2"<<endl;
    cout<<"r-Right 1/2"<<endl;
    cout<<"u-Upper 1/2"<<endl;
    cout<<"d-down 1/2"<<endl;
    cin>>user_choice;
    if (user_choice=='l'){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 255; j>SIZE/2; j--) {
                new_image[i][j]=image[i][x-j];
            }
        }
        for (int i = 0; i < SIZE; i++) {
        for (int j = 255; j> SIZE/2; j--) {
                image[i][j]=new_image[i][j];

            }
        }
    }
    if (user_choice=='r'){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE/2; j++) {
                new_image[i][j]=image[i][x-j];
            }
        }
        for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE/2; j++) {
                image[i][j]=new_image[i][j];

            }
        }
    }
    if (user_choice=='u'){
        for (int i = 255; i > SIZE/2; i--) {
            for (int j = 0; j <SIZE; j++) {
                new_image[i][j]=image[x-i][j];
            }
        }
        for (int i = 255; i > SIZE/2; i--) {
            for (int j = 0; j< SIZE; j++) {
                image[i][j]=new_image[i][j];

            }
        }
    }
    if (user_choice=='d'){
        for (int i = 0; i < SIZE/2; i++) {
            for (int j = 0; j< SIZE; j++) {
                new_image[i][j]=image[x-i][j];
            }
        }
        for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j< SIZE; j++) {
                image[i][j]=new_image[i][j];

            }
        }
    }
}