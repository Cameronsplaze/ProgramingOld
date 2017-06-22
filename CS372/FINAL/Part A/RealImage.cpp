#include "RealImage.h"
#include <iostream>


RealImage::RealImage(int i)
{
	image_index = i;
	std::cout << "RealImage constructor called" << std::endl;
	std::cout << "Type me again to see if i'm called again" << std::endl;
}
RealImage::~RealImage()
{
	std::cout << "RealImage deconstructor called" << std::endl;
}
void RealImage::drawer()
{
	std::cout << "Drawing image (for real): " << image_index << std::endl;
}