// FCI – Programming 1 – 2022 - Assignment 3 
// Program Name:CS112-203-second-S7,S8-20210183-20210121-20210175-A3Bonus                  
// Last Modification Date: 18 April 2022
// Author1 and ID and Group: Habiba Alaa Mohamed 20210121
// Author2 and ID and Group: Shrouk Tarek Ibrahem 20210175
// Author3 and ID and Group: Shahd Salah El-Dein Abd El-Tawab 20210183
// Teaching Assistant: Eng. Abdelrahman Abdelmonem
// Purpose: Make user to load image and choose the filter he want to apply on it
// Version: 1.0

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE][3];

void Load_Image();
void Save_Image();
void Black_And_White();
void Invert();
void Merge();
void Flip_Image();
void Lighten_And_Darken();
void Rotate_Image();
void Detect_Edges();
void Enlarge_Image();
void Shrink_Image();
void Mirror_Image();
void Shuffle_Image();
void Blur_Image();

int main(){
    Load_Image();
    char desire,choice;
    while (true)
    {
    cout << "Please select a filter to apply filters on it or 0 to exit:"<<endl;
    cout << "1- Black & White Filter\n2- Invert Filter\n3- Merge Filter\n4- Flip Image\n5- Darken and Lighten Image\n6- Rotate Image\n7- Detect Image Edges\n8- Enlarge Image\n9- Shrink Image\na- Mirror 1 / 2 Image\nb- Shuffle Image\nc- Blur Image\ns- Save the image to a file\n0- Exit\n";
    cin >> desire;
    switch (desire)
    {
    case '1':
        Black_And_White();
        break;
    case '2':
        Invert();
        break;
    case '3':
        Merge();
        break;
    case '4':
        Flip_Image();
        break;
    case '5':
        Lighten_And_Darken();
        break;
    case '6':
        Rotate_Image();
        break;
    case '7':
        Detect_Edges();
        break;
    case '8':
        Enlarge_Image();
        break;
    case '9':
        Shrink_Image();
        break;
    case 'a':
        Mirror_Image();
        break;
    case 'b':
       Shuffle_Image();
        break;
    case 'c':
        Blur_Image();
        break;
    case 's':
        Save_Image();
        cout << "Do you want to (l) a new image or press 0 to exit:";
        cin >> choice;
        if (choice == 'l')
        {
            Load_Image();
        }
        else
        {
            cout << "Hope you are happy and satisfied with our filters app <3";
            return 0;
        }
    case '0':
        int quit;
        cout<<"Do you want to exit without saving:"<<endl<<"1- Yes\n2- No\n";
        cin >> quit;
        if (quit == 1)
        {     
            cout << "Hope you are happy and satisfied with our filters app <3";
            return 0;
        }
        else
        {
            Save_Image();
            return 0;
        }
    
        }//switch    
    }//while
}//function
//_________________________________________
void Load_Image () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Ahlan ya user ya habibi"<<endl<<"Please enter file name of the image to process: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readRGBBMP(imageFileName, image);
  
}
//_________________________________________
void Save_Image () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;
   

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeRGBBMP(imageFileName, image);
}
//_________________________________________
void Black_And_White(){
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
    avg /= (SIZE * SIZE * 3);
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (image[i][j][k]> avg)
                {
                    image[i][j][k] = 255;
                    image[i][j][1] = 255;
                    image[i][j][2] = 255;
                }
                if (image[i][j][k]<avg)
                {
                    image[i][j][k] = 0;
                    image[i][j][1] = 0;
                    image[i][j][2] = 0;
                }
            }
        }
    }
}
//_________________________________________
void Invert(){
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                image[i][j][k] = 255 - image[i][j][k];
            }
        }
    }
}
//_________________________________________
void Merge(){
    unsigned char merged_image[SIZE][SIZE][3];
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                merged_image[i][j][k] = image[i][j][k];
            } 
        }
    }
    cout << "Please enter name of image file to merge with"<<endl;
    Load_Image();
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                image[i][j][k] = (merged_image[i][j][k] + image[i][j][k]) / 2;  
            }
        }
    } 
}
//_________________________________________
void Flip_Image(){
    unsigned char flib[SIZE][SIZE][3];
    char user_choice;
    cout<<"Please choose how you want to flip (h)orizontally or (v)ertically"<<endl;
    cout<<"v-vertical flip"<<endl;
    cout<<"h-right flip"<<endl;
    cin>>user_choice;
    if (user_choice == 'v'){
        for (int i = 0; i < SIZE; i++) 
        {
            for (int j = 0; j< SIZE; j++) 
            {
                for (int k=0; k<3 ; k++)
                {
                    flib[255 - i][j][k] = image[i][j][k];
                }
            }
        }
        for (int i = 0; i < SIZE; i++) 
        {
            for (int j = 0; j< SIZE; j++)
            {
                for (int k=0; k<3 ; k++)
                {
                    image[i][j][k] = flib[i][j][k];
                }
            }
        }
    }
     else{
        for (int i = 0; i < SIZE; i++) 
        {
            for (int j = 0; j< SIZE; j++)
            {
                for (int k = 0; k < 3; k++)
                {

                    flib[i][255 - j][k] = image[i][j][k];
                }
            }
        }
        for (int i = 0; i < SIZE; i++) 
        {
            for (int j = 0; j< SIZE; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    image[i][j][k] = flib[i][j][k];  
                }    
            }
        }            
    }
}
//_________________________________________
void Lighten_And_Darken(){
    char choice;
    int check;
    cout << "Do you want to (d)arken or (l)ighten?";
    cin >> choice;
    if (choice == 'd')
    {
       for (int i = 0; i < SIZE; i++) 
       {
            for (int j = 0; j< SIZE; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                image[i][j][k] /= 2;   
                }
            }
       }
    }
    else
    {
        for (int i = 0; i < SIZE; i++) 
        {
            for (int j = 0; j< SIZE; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    check = image[i][j][k] + (image[i][j][k] / 2);
                    if (check > 255)
                    {
                        image[i][j][k];
                    }
                    else
                    {
                        image[i][j][k] = check;
                    }
                } 
            }
        }           
    } 
}
//_________________________________________
void Rotate_Image(){
    unsigned char rotate_image[SIZE][SIZE][3];
    int degree;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int s = 0; s < 3; s++)
            {
                rotate_image[i][j][s] = image[i][j][s];
            }
        }
    }
    cout << "Rotate (90), (180) or (270) degrees?";
    cin >> degree;
    if (degree == 90)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int s = 0; s < 3; s++)
                {

                    image[i][j][s] = rotate_image[j][255 - i][s];
                }
            }
        }
    }
    else if (degree == 180)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int s = 0; s < 3; s++)
                {
                    image[i][j][s] = rotate_image[255 - i][255 - j][s];
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int s = 0; s < 3; s++)
                {
                    image[i][j][s] = rotate_image[255 - j][i][s];
                }
            }
        }
    }
}
//_________________________________________
void Detect_Edges(){
  unsigned char detect_image[SIZE][SIZE][3];
  for (int j = 0; j < SIZE-1; j++)
  {
    for (int i = 0; i< SIZE-1; i++) 
    {
        for(int k=0; k<3; k++)
        {
            if(image[i][j][3]==image[i+1][j+1][3])
            {
                detect_image[i][j][k] = image[i][j][k];
            }
            if((abs(image[i][j][3]-image[i+1][j][3]>=15))||(abs(image[i][j][3]-image[i][j+1][3]>=15)))
            {
                detect_image[i][j][k] = 0;
            }
            else
            {
                detect_image[i][j][k] = 255;
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
            image[i][j][k]=detect_image[i][j][k];
        }
    }
  }
}
//_________________________________________
void Enlarge_Image(){
    unsigned char enlarge[SIZE][SIZE][3];
    cout << "Which quarter do you want to enlarge?" << endl;
    cout << "1-First quarter" << endl;
    cout << "2-Second quarter" << endl;
    cout << "3-Third quarter" << endl;
    cout << "4-Fourth quarter" << endl;
    int quarter;
    int k, l;
    cin >> quarter;
    if (quarter == 1)
    {
        k = 0;
        for (int i = 0; i < SIZE / 2; i++)
        {
        l = 0;
        for (int j = 0; j < SIZE / 2; j++)
        {
            for (int s = 0; s < 3; s++)
            {
                enlarge[k][l][s] = image[i][j][s];
                enlarge[k][l + 1][s] = image[i][j][s];
                enlarge[k + 1][l][s] = image[i][j][s];
                enlarge[k + 1][l + 1][s] = image[i][j][s];
            }
        l += 2;    
        }
        k += 2;
        }
    }
    else if (quarter == 2)
    {
        k = 0;
        for (int i = 0; i < SIZE / 2; i++)
        {
        l = 0;
        for (int j = SIZE/2; j < SIZE; j++)
        {
            for (int s = 0; s < 3; s++)
            {
                enlarge[k][l][s] = image[i][j][s];
                enlarge[k][l + 1][s] = image[i][j][s];
                enlarge[k + 1][l][s] = image[i][j][s];
                enlarge[k + 1][l + 1][s] = image[i][j][s];
            }
        l += 2;
        }
        k += 2;
        }
    }
    else if (quarter == 3)
    {
        k = 0;
        for (int i = SIZE/2; i < SIZE; i++)
        {
        l = 0;
        for (int j = 0; j < SIZE / 2; j++)
        {
            for (int s = 0; s < 3; s++)
            {
                enlarge[k][l][s] = image[i][j][s];
                enlarge[k][l + 1][s] = image[i][j][s];
                enlarge[k + 1][l][s] = image[i][j][s];
                enlarge[k + 1][l + 1][s] = image[i][j][s];   
            }
        l += 2;
        }
        k += 2;
        }
    }
    else
    {
        k = 0;
        for (int i = SIZE/2; i < SIZE; i++)
        {
        l = 0;
        for (int j = SIZE/2; j < SIZE; j++)
        {
            for (int s = 0; s < 3; s++)
            {
                enlarge[k][l][s] = image[i][j][s];
                enlarge[k][l + 1][s] = image[i][j][s];
                enlarge[k + 1][l][s] = image[i][j][s];
                enlarge[k + 1][l + 1][s] = image[i][j][s];
            }
        l += 2;
        }
        k += 2;
        }
    }
}
//_________________________________________
void Shrink_Image(){
    unsigned char shrink_image[SIZE][SIZE][3];
    string choice;
    cout << "Please choose how you want to Shrink your image to (1/2), (1/3) or (1/4)?";
    cin >> choice;
    if (choice == "1/2")
    {   
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++){
                for (int k = 0; k < 3; k++)
                {
                shrink_image[i][j][k] = 255;
                shrink_image[i / 2][j / 2][k] = image[i][j][k]; 
                }
            }
        }
    }
    else if (choice == "1/3")
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++){
                for (int k = 0; k < 3; k++)
                { 
                shrink_image[i][j][k] = 255;
                shrink_image[i / 3][j / 3][k] = image[i][j][k];    
                }    
            }
        } 
    }
    else
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < 3; k++)
                {  
                shrink_image[i][j][k] = 255;
                shrink_image[i / 4][j / 4][k] = image[i][j][k];    
                } 
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < 3; k++)
            {
            image[i][j][k] = shrink_image[i][j][k];
            }   
        }    
    }
}
//_________________________________________
void Mirror_Image(){
    unsigned char mirror[SIZE][SIZE][3];
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
        for (int i = 0; i < SIZE; i++) 
        {
            for (int j = 255; j>SIZE/2; j--)
             {
                for(int k=0; k<3; k++)
                {
                    mirror[i][j][k] = image[i][x - j][k];
                }
            }
        }
        for (int i = 0; i < SIZE; i++) 
        {
            for (int j = 255; j> SIZE/2; j--) 
            {
                for(int k=0;k<3; k++)
                {
                    image[i][j][k] = mirror[i][j][k];
                }
            }
        }
    }
    if (n==2){
        for (int i = 0; i < SIZE; i++)
         {
            for (int j = 0; j< SIZE/2; j++) 
            {
                for(int k=0; k<3; k++)
                {
                    mirror[i][j][k] = image[i][x - j][k];
                }
            }
        }
        for (int i = 0; i < SIZE; i++)
         {
            for (int j = 0; j< SIZE/2; j++) 
            {
                for (int k=0;k<3;k++)
                {
                    image[i][j][k] = mirror[i][j][k];
                }
            }
        }
    }
    if (n==3){
        for (int i = 255; i > SIZE/2; i--)
         {
            for (int j = 0; j <SIZE; j++)
             {
                for (int k=0; k<3; k++)
                {
                    mirror[i][j][k] = image[x - i][j][k];
                }
            }
        }
        for (int i = 255; i > SIZE/2; i--) 
        {
            for (int j = 0; j< SIZE; j++) 
            {
                for (int k=0; k<3; k++)
                {
                    image[i][j][k] = mirror[i][j][k];
                }

            }
        }
    }
    if (n==4){
        for (int i = 0; i < SIZE/2; i++) 
        {
            for (int j = 0; j< SIZE; j++) 
            {
                for (int k=0; k<3; k++)
                {
                    mirror[i][j][k] = image[x - i][j][k];
                }
            }
        }
        for (int i = 0; i < SIZE/2; i++) 
        {
            for (int j = 0; j< SIZE; j++) 
            {
                for(int k=0; k<3; k++)
                {
                    image[i][j][k] = mirror[i][j][k];
                }
            }
        }
    }
}
//_________________________________________
void Shuffle_Image(){
    unsigned char shuffle[SIZE][SIZE][3];
    int q[4][2] = {{0, 0}, {0, 128}, {128, 0}, {128, 128}};
    int quarter[4];
    int x, y;
    cout << "Please enter a new order of quarter";
    cin >> quarter[0] >> quarter[1] >> quarter[2] >> quarter[3];
    for (int k = 0; k < 4; k++)
    {
        x = q[k][0];
        y = q[k][1];
        
        for (int i = q[quarter[k] - 1][0]; i < (128 + q[quarter[k] - 1][0]); i++)
        {
           
            for (int j = q[quarter[k] - 1][1]; j < (128 + q[quarter[k] - 1][1]); j++)
            {
                for (int z = 0; z < 3; z++)
                {
                    shuffle[x][y][z] = image[i][j][z];
               
                }
            y++;
            }
        x++;
        y = q[k][1];    
        }
    }
}
//_________________________________________
void Blur_Image(){
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++) 
            {
                for (int k = 0; k < 3; k++)
                {
                    image[i][j][k] = (image[i][j][k] + image[i - 1][j - 1][k] + image[i - 1][j][k] + image[i + 1][j][k] + image[i][j - 1][k] + image[i][j + 1][k] + image[i - 1][j + 1][k] + image[i][j + 1][k] + image[i + 1][j + 1][k]) / 9;
                }
            }
        }
} 


