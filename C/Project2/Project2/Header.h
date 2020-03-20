#pragma once

// en.cppreference.com


class B {
public:
	double x, y;
	B(); // constructeur
	B(const B &b); // constructeur de recopie (recopie un objet pour le mettre dans l'autre)
	B(B &&b); // constructeur de d�placement (d�place le contenu d'un objet pour le mettre dans l'autre
	~B(); // destructeur
	B& operator= (const B& b); // operator = d�finis par recopie
	B& operator=(B&& b); // operator = d�fnis par d�placement
};


class A {
public:
	double x, y;
	A(); // constructeur
	A(const A &a); // constructeur de recopie (recopie un objet pour le mettre dans l'autre)
	A(const B& b); // constructeur de recopie pour un objet B
	A(A &&a); // constructeur de d�placement (d�place le contenu d'un objet pour le mettre dans l'autre
	~A(); // destructeur
	A& operator= (const A& a); // operator = d�finis par recopie
	A& operator= (const B& b); // operator = d�finis par recopie d'un objet B
	A& operator=(A&& a); // operator = d�fnis par d�placement
};
