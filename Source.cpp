//mandelbrot set, coded by Dr. Mo, 2019 (updated 2021)

#include <allegro5/allegro.h> //open source video game library
#include <allegro5/allegro_primitives.h> //for drawing shapes like rects and circles and stuff
#include <complex> //c++ library for complex numbers
using namespace std; //needed for complex 

//function declaration
double mandelbrot(complex<double>c);

int main() {

	al_init();//initalize allegro library
	al_init_primitives_addon(); 

	ALLEGRO_DISPLAY* screen = al_create_display(800, 800); //create game screen

	//program variables
	complex<double>c;
	int num;

	for (double x = -2; x < 2; x += .01)
		for (double y = -2; y < 2; y += .01) {

			c = complex<double>(x, y);
			num = mandelbrot(c);

			//put_pixel() draws a single pixel to the screen at (x, y, color)
			if(num == 80)
				al_put_pixel((x * 100 + 400), (y * 100 + 400), al_map_rgb(0,0,0)); //draw inside black
			else
				al_put_pixel((x * 100 + 400), (y * 100 + 400), al_map_rgb(num * 200, num/255, num*25));

			al_flip_display(); //flip what we just drawed to the screen
		}
	system("pause");
	al_destroy_display(screen);//release memory when done


}

//function definition-------------------------------------------------------------------------------------------
double mandelbrot(complex<double>c) {
	complex <double> z = 0;
	int count = 0;

	//run this loop 80 times and see if z*z+c gets bigger than 2 or stays smaller
	while (abs(z) < 2 && count < 80) { 
		z = z * z + c; //what happens when we times the number by itself and add c over and over again?

		count++;
	}
	return count; //this represents how many times the loop ran (all 80 means it's most likely in the set)
}
