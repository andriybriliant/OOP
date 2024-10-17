#include <iostream>
#include "wielomian.h"

int main() {
	double x_tab[] = { 0, -2, 3.4, 5, 4.8, 0, 1, 0 };
	double x_tab1[] = { 2, 3, 4 };

	wielomian s(x_tab1, 3);

	wielomian x(x_tab, 8);
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

	std::cout << "\nWielomian x:\n";
	x.printWielomianVisual();
	std::cout << "\n";

	wielomian c = x.Add(s);
	std::cout << "\nAdded wielomian: \n";
	c.printWielomian();
	std::cout << "\n";
	c.printWielomianVisual();
	std::cout << "\n";

	return 0;
}