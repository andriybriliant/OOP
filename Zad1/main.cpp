#include <iostream>
#include "wielomian.h"

void test_mult() {
	double x_tab[] = { 2, 1 };
	double x_tab1[] = { 1, -3, 4 };
	wielomian x(x_tab, 2);
	wielomian y(x_tab1, 3);

	wielomian z = y.multiply(y);
	std::cout << "\n";
	z.printWielomianVisual();
	std::cout << "\n";
}

int main() {
	double x_tab[] = { 1, 2, 3.4, 5, 4.8, 0, 1, 0 };
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

	s.printWielomian();
	std::cout << "\n";

	wielomian d = x.multiply(s);
	d.printWielomian();
	std::cout << "\n";
	d.printWielomianVisual();
	std::cout << "\n";

	test_mult();

	return 0;
}