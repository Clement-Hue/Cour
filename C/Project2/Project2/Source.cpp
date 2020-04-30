#include <iostream>
#include "Header.h"

A::A() : x(0), y(0) {
	std::cout << "constructeeur" << std::endl;
}

A::A(const A& a): x(a.x), y(a.y) {
	std::cout << "constructeur de recopie" << std::endl;
}

A::A(const B& b) : x(b.x), y(b.y) {
	std::cout << "constructeur de recopie d'un objet B" << std::endl;
}

A::A(A&& a) {
	x = std::move(a.x);
	y = std::move(a.y);
	std::cout << "constructeur de move" << std::endl;
}

A::~A() {
	std::cout << "destructeur" << std::endl;
}

A& A::operator= (const A& a) {
	std::cout << "operateur = par recopie" << std::endl;
	x = a.x;
	y = a.y;
	return *this;
}


A& A::operator= (const B& b) {
	std::cout << "operateur = par d�placement d'un objet B" << std::endl;
	x = std::move(b.x);
	y = std::move(b.y);
	return *this;
}

A& A::operator= (A&& a) {
	std::cout << "operateur = par d�placement" << std::endl;
	x = std::move(a.x);
	y = std::move(a.y);
	return *this;
}


B::B() : x(0), y(0) {
	std::cout << "constructeeur" << std::endl;
}

B::B(const B &b): x(b.x), y(b.y) {
	std::cout << "constructeur de recopie" << std::endl;
}

B::B(B&& b) {
	x = std::move(b.x);
	y = std::move(b.y);
	std::cout << "constructeur de move" << std::endl;
}

B::~B() {
	std::cout << "destructeur" << std::endl;
}

B& B::operator= (const B& b) {
	std::cout << "operateur = par recopie" << std::endl;
	x = b.x;
	y = b.y;
	return *this;
}

B& B::operator= (B&& b) {
	std::cout << "operateur = par d�placement" << std::endl;
	x = std::move(b.x);
	y = std::move(b.y);
	return *this;
}

