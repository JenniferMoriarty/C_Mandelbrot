#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <complex>
using namespace std;
const int W = 800;
const int H = 800;
double mandelbrot(complex<double>c);
int main() {

	al_init();
	al_init_primitives_addon();
	ALLEGRO_DISPLAY* TIA = al_create_display(W, H);
	complex<double>c;
	int num;

	for (double t = -2; t < 2; t += .01)
		for (double m = -2; m < 2; m += .01) {
			cout << "loop";
			c = complex<double>(t, m);
			num = mandelbrot(c);

			al_put_pixel(t * 100 + 400, m * 100 + 400, al_map_rgb(num * 200, num * 125, num / 255));
			cout << "num is " << num << " at " << t * 100 + 400 << " " << m * 100 + 400 << endl;
			al_flip_display();
		}
	system("pause");
	al_destroy_display(TIA);


}
double mandelbrot(complex<double>c) {
	complex <double> z = 0;
	int count = 0;
	while (abs(z) < 2 && count < 80) {
		z = z * z + c;

		count++;
	}
	return count;
}
