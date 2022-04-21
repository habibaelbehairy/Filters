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
void Flip_Image ();

int main()
{
  loadImage();
  Flip_Image();
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
void Flip_Image(){
    char user_choice;
    cout << "Please choose how you want to Flip (h)orizontally or (v)ertically ?" << endl;
    cin >> user_choice;
    if (user_choice == 'v'){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                new_image[255 - i][j] = image[i][j];
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++){
                image[i][j] = new_image[i][j];
            }
        }
    }
    if (user_choice=='h'){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++){
            new_image[i][255 - j] = image[i][j];
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++){
                image[i][j] = new_image[i][j];
            }
        }
    }
}