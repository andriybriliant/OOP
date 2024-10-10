#pragma once
class wielomian
{
public:
	double* tab;
	int size;

	wielomian();

	wielomian(double*, int);

	wielomian(int);

	~wielomian();

	wielomian(const wielomian&);

	void printWielomian();

	void printWielomian(wielomian);

	double policzWielomian(double);
};

