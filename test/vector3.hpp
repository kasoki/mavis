#ifndef __VECTOR3_HPP__
#define __VECTOR3_HPP__

class vector3 {

public:
	int x;
	int y;
	int z;

	vector3() : x(0), y(0), z(0) {};
	vector3(int x, int y, int z) : x(x), y(y), z(z) {};

	vector3& operator+(vector3& other);
	vector3& operator-(vector3& other);
	vector3& operator*(int);
};

#endif