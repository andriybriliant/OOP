#include <iostream>
#include "wielomian.h"


void wielomian::printWielomian(){
	std::cout << "size = " << size << "\n";
	std::cout << "[ ";
	for (int i = 0; i < size; i++) {
		std::cout << tab[i] << " ";
	}
	std::cout << "]\n";
}


void wielomian::printWielomian(const wielomian w) {
	std::cout << "size = " << w.size << "\n";
	std::cout << "[ ";
	for (int i = 0; i < w.size; i++) {
		std::cout << w.tab[i] << " ";
	}
	std::cout << "]\n";
}


wielomian::wielomian() {
	size = 0;
	tab = 0;
}


wielomian::wielomian(double* tb, int sz) {
	size = sz;
	tab = new double[sz];
	for (int i = 0; i < size; i++) {
		tab[i] = tb[i];
	}
}


wielomian::wielomian(int s) {
	size = s;
	tab = new double[s];
}


wielomian::wielomian(const wielomian& w) {
	size = w.size;
	tab = new double[size];
	memcpy(tab, w.tab, sizeof(double) * size);
}


wielomian::~wielomian() {
	delete[]tab;
}


double wielomian::policzWielomian(double x) {
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum += tab[i] * pow(x, i);
	}

	return sum;
}
