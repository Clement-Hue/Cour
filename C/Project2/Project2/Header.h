#pragma once

// en.cppreference.com


class B {
public:
	double x, y;
	B(); // constructeur
	B(const B &b); // constructeur de recopie (recopie un objet pour le mettre dans l'autre)
	B(B &&b); // constructeur de déplacement (déplace le contenu d'un objet pour le mettre dans l'autre
	~B(); // destructeur
	B& operator= (const B& b); // operator = définis par recopie
	B& operator=(B&& b); // operator = défnis par déplacement
};


class A {
public:
	double x, y;
	A(); // constructeur
	A(const A &a); // constructeur de recopie (recopie un objet pour le mettre dans l'autre)
	A(const B& b); // constructeur de recopie pour un objet B
	A(A &&a); // constructeur de déplacement (déplace le contenu d'un objet pour le mettre dans l'autre
	~A(); // destructeur
	A& operator= (const A& a); // operator = définis par recopie
	A& operator= (const B& b); // operator = définis par recopie d'un objet B
	A& operator=(A&& a); // operator = défnis par déplacement
};
