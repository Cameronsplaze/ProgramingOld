#include "ProxyImage.h"
#include "RealImage.h"
#include <iostream>

ProxyImage::ProxyImage()
{
	image_index = number_of_proxies++;
	ptr_real_thing = NULL;
	std::cout << "ProxyImage constructor called for: " << image_index << std::endl;
}
ProxyImage::~ProxyImage()
{
	delete ptr_real_thing;
}
//picture not delt with until user calls draw
void ProxyImage::draw()
{
	if(!ptr_real_thing)
	{
		ptr_real_thing = new RealImage(image_index);
	}
	//if it doesn't exist, create it. Always draw it
	ptr_real_thing->drawer();
}
//the number of images that are proxied
int ProxyImage::number_of_proxies = 1;
