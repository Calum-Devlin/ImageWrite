#include <iostream>
#include <cstdlib>
#include "ImageWrite.h"

int main()
{
  std::cout<<"This is working.\n";
  int pictureSize = 800;
  ImageWrite myImage(pictureSize,pictureSize);
  myImage.clear(64,96,64);
  for(int a = 5; a < pictureSize-5; a+=(10.0f*(float)rand()/(float)(RAND_MAX)))
  {
    myImage.drawline(pictureSize/2,pictureSize/2,5,a,255,255,255);
  }
  for(int b = 5; b < pictureSize-5; b+=(10.0f*(float)rand()/(float)(RAND_MAX)))
  {
    myImage.drawline(pictureSize/2,pictureSize/2,b,5,255,0,0);
  }
  for(int c = 5; c < pictureSize-5; c+=(10.0f*(float)rand()/(float)(RAND_MAX)))
  {
    myImage.drawline(pictureSize/2,pictureSize/2,pictureSize-5,c,0,0,0);
  }
  for(int d = 5; d < pictureSize-5; d+=(10.0f*(float)rand()/(float)(RAND_MAX)))
  {
    myImage.drawline(pictureSize/2,pictureSize/2,d,pictureSize-5,0,0,255);
  }
  myImage.save("test.ppm");
  return EXIT_SUCCESS;
}

