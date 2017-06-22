#ifndef PROXYIMAGE_H_INCLUDED
#define PROXYIMAGE_H_INCLUDED
#include "RealImage.h"



class ProxyImage
{
public:
	ProxyImage();
	~ProxyImage();
	void draw();
protected:
	RealImage *ptr_real_thing;
	int image_index;
	static int number_of_proxies;
};





#endif // PROXYIMAGE_H_INCLUDED
