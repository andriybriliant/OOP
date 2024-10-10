#include "wielomian.h"
#include <iostream>

int main() {
	double x_tab[] = { 1, 2, 3 };

	wielomian x(x_tab, 3);
	wielomian x2(3);
	wielomian x3(x);
	x.printWielomian();
	std::cout << "\n";
	x2.printWielomian();
	std::cout << "\n";
	x3.printWielomian();
	std::cout << "\n";
	x.printWielomian(x3);
	std::cout << "\n";

	double wiel = x.policzWielomian(3);
	std::cout << "wiel = " << wiel << "\n";

	return 0;
}