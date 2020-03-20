#include "Header.h"
#include <iostream>

int main() {
	std::cout << "-> A t" << std::endl;
	A t;
	std::cout << "-> A z(t)" << std::endl;
	A z(t);
	std::cout << "-> r = A()" << std::endl;
	A r = A();
	std::cout << "-> y = t" << std::endl;
	A y = t;
	std::cout << "-> z = t" << std::endl;
	z = t;

	std::cout << "-> B u" << std::endl;
	B u;
	std::cout << "-> A a(u)" << std::endl;
	A a(u);
	std::cout << "-> t = u" << std::endl;
	t = u;

}