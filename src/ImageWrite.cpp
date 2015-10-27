#include "ImageWrite.h"
#include <cassert>
#include <fstream>
#include <iostream>

ImageWrite::ImageWrite(int _w, int _h)
{
  m_width = _w;
  m_height = _h;
  m_data = new unsigned char[m_width*m_height*3];
}

ImageWrite::~ImageWrite()
{
  if(m_data != 0)
  {
    delete [] m_data;
  }
}

void ImageWrite::save(const std::string &_fname)
{
  std::ofstream output;
  output.open(_fname);
  if(!output.is_open())
  {
    std::cerr<<"Problem opening file "<<_fname<<"\n";
    exit(EXIT_FAILURE);
  }

  output<<"P3\n";
  output<<m_width<<" "<<m_height<<"\n";
  output<<"255\n";

  for(int y=0; y<m_height; ++y)
  {
    for(int x=0; x<m_width; ++x)
    {
      output<<(int)m_data[3*((y*m_width)+x)]<<" ";
      output<<(int)m_data[3*((y*m_width)+x)+1]<<" ";
      output<<(int)m_data[3*((y*m_width)+x)+2]<<" ";
    }
  output<<"\n";
  }

  output.close();
}

void ImageWrite::setpixel(int _x, int _y, unsigned char _r, unsigned char _g, unsigned char _b)
{
  assert(_x<m_width && _y<m_height);
  unsigned int index=3*((_y*m_width)+_x);
  m_data[index+0]=_r;
  m_data[index+1]=_g;
  m_data[index+2]=_b;
}

void ImageWrite::clear(unsigned char _r, unsigned char _g, unsigned char _b)
{
  for(int y=0; y<m_height; ++y)
  {
    for(int x=0; x<m_width; ++x)
    {
      setpixel(x,y,_r,_g,_b);
    }
  }
}

void ImageWrite::drawline(int _x0, int _y0, int _x1, int _y1, unsigned char _r, unsigned char _g, unsigned char _b)
{
  if (!(_x0==_x1))
  {
    float leftX;
    float rightX;
    float leftY;
    float rightY;
    if(_x0<_x1)
    {
      leftX=_x0;
      rightX=_x1;
      leftY=_y0;
      rightY=_y1;
    }
    else
    {
      leftX=_x1;
      rightX=_x0;
      leftY=_y1;
      rightY=_y0;
    }
    float dx = rightX-leftX;
    float dy = rightY-leftY;
    float error = 0.0f;
    float derror = 0.0f;
    float errortemp = dy/dx;
    if(errortemp>=0)
    {
      derror = errortemp;
    }
    else
    {
      derror = -errortemp;
    }
    float newY = leftY;
    for(int newX = leftX; newX <= rightX; newX++)
    {
      setpixel(newX,newY,_r,_g,_b);
      error+=derror;
      while((error>=0.5)&&(newY!=rightY))
      {
        assert(newX<=m_width&&newY<=m_height);
        setpixel(newX,newY,_r,_g,_b);
        if(dy>=0)
        {
          newY += 1.0f;
        }
        else
        {
          newY -= 1.0f;
        }
        error -= 1.0f;
      }
    }
  }
  else
  {
    for(int i = std::min(_y0,_y1); i <= std::max(_y0,_y1);i++)
    {
      setpixel(_x0,i,_r,_g,_b);
    }
  }
}
