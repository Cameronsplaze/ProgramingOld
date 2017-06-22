

#include "ProxyImage.h"          // For class proxy

#include <string>
#include <iostream>



int main()
{
	std::cout << "Made images 1-5... DONE!" << std::endl;
	ProxyImage images[5];
	for(unsigned int i; true;)
	{
		std::cout << " ---->[Enter 0 to exit] or 1-5 to draw that image: ";
		std::cin >> i;
		if(i <= 0)
		{
			break;
		}
		images[i-1].draw();
		std::cout << std::endl;
	}
    return 0;
}

