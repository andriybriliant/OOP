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
		sum += tab[i] * pow(x, size - i - 1);
	}

	return sum;
}


void wielomian::printWielomianVisual() {
	bool first_instance = true;
	for (int i = 0; i < size; i++) {
		if (tab[i] == 0) {
			continue;
		}

		if (first_instance) {
			first_instance = false;
		}
		else if ((i != 0) && (tab[i] > 0)) {
			std::cout << "+";
		}

		if ((size - i - 1) == 0) {
			std::cout << tab[i];
		}
		else if (tab[i] == 1) {
			if (size - i - 1 == 1) {
				std::cout << "x";
				break;
			}
			std::cout << "x^" << size - i - 1;
		}
		else if (tab[i] == -1) {
			if (size - i - 1 == 1) {
				std::cout << "-x";
				break;
			}
			std::cout << "-x^" << size - i - 1;
		}
		else {
			if (size - i - 1 != 1) {
				std::cout << tab[i] << "*x^" << size - i - 1;
			}
			else {
				std::cout << tab[i] << "*x";
			}
		}
	}
}


wielomian wielomian::Add(const wielomian& x) {
	const wielomian* min, * max;

	if (x.size > size) {
		max = &x;
		min = this;
	}
	else {
		max = this;
		min = &x;
	}

	wielomian nowy(*max);

	for (int i = 0; i < min->size; i++) {
		nowy.tab[i] = min->tab[i] + max->tab[i];
	}

	return nowy;
}


wielomian wielomian::Add_worse(wielomian w) {
	wielomian nowy(w.tab, w.size);


	if (w.size > size) {
		for (int i = 0; i < size; i++) {
			nowy.tab[i] = w.tab[i] + tab[i];
		}
		return nowy;
	}

	if (size > w.size) {
		delete[] nowy.tab;
		nowy.tab = new double[size];
		nowy.size = size;

		for (int j = 0; j < size; j++) {
			nowy.tab[j] = tab[j];
		}

		for (int curr = 0; curr < w.size; curr++) {
			nowy.tab[curr] = w.tab[curr] + tab[curr];
		}
	}

	return nowy;
}