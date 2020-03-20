#pragma once

class Vector {
private:
	double* Vec;
	unsigned int Size;

public:
	Vector();
	~Vector();
	double& operator[] (int index);
	double operator[] (int index) const; // pour des objets constant on travail sur la recopie
	inline unsigned int getSize() const { return Size; };
	inline const double* getVec() const { return Vec; };
	void AddData(double v);
	void AddVector(const double* v, unsigned int szie);
	void ReplaceVector(const double* v, unsigned int size);
};

