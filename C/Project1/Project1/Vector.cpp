#include "Vector.h"
#include <stdlib.h>

Vector::Vector() : Size(0)
{
}
Vector::~Vector() {
	free(Vec);
}

void Vector::AddData(double d) {
	Size++;
	Vec = (double*) realloc(Vec, Size * sizeof(double));
	Vec[Size - 1] = d;
}

double& Vector::operator[] (int inedex) {
	return Vec[index];
}

double Vector::operator[] (int index) const {
	return Vec[index];
}