#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
#include <ppm.h>
#include <basicPerlin.h>

using namespace::std;

int main( int argc, char* argv[] )
{
	unsigned int width = 600;
	unsigned int height = 450;
	
	// Create an empty PPM image
	ppm image( width, height );

	Perlin pn;
	
	// wood shape 
	unsigned int kk = 0;
	// Visit every pixel of the image and assign a color generated with Perlin noise
	for(unsigned int i = 0; i < height; ++i) {     // y
		for(unsigned int j = 0; j < width; ++j) {  // x
			double x = (double)j/((double)width);
			double y = (double)i/((double)height);

			// Typical Perlin noise
			double n = pn.value(10 * x, 10 * y, 0.8);

			// Wood like structure
			n = 20 * pn.value(x, y, 0.8);
			n = n - std::floor(n);

			// Map the values to the [0, 255] interval, for simplicity we use 
			// tones of grey
			image.r[kk] = std::floor(255 * n);
			image.g[kk] = std::floor(255 * n);
			image.b[kk] = std::floor(255 * n);
			kk++;
		}
	}

	// Save the image in a binary PPM file
	image.write("figure_8_R.ppm");

	kk = 0;
	// Visit every pixel of the image and assign a color generated with Perlin noise
	for(unsigned int i = 0; i < height; ++i) {     // y
		for(unsigned int j = 0; j < width; ++j) {  // x
			double x = (double)j/((double)width);
			double y = (double)i/((double)height);

			// Typical Perlin noise
			//double n = pn.value(10 * x, 10 * y, 0.8);
			double n = pn.octaveValue(10 * x, 10 * y, 0.8, 2, 0.5 );

			// Wood like structure
			//n = 20 * pn.noise(x, y, 0.8);
			//n = n - floor(n);

			// Map the values to the [0, 255] interval, for simplicity we use 
			// tones of grey
			image.r[kk] = floor(255 * n);
			image.g[kk] = floor(255 * n);
			image.b[kk] = floor(255 * n);
			kk++;
		}
	}

	// Save the image in a binary PPM file
	image.write("figure_7_P.ppm");

	return 0;
}



