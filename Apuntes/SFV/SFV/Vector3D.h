#pragma once
#include <iostream>
class Vector3D
{
public:
	Vector3D(): x_(0), y_(0), z_(0){}
	Vector3D(double x, double y, double z): x_(x), y_(y), z_(z){}
	~Vector3D(){}

	//get the components of the vector
	inline double getX() const { return x_; }
	inline double getY() const { return y_; }
	inline double getZ() const { return z_; }
	
	std::string getVector() const; //may be useful for debugging

	//set the components of the vector
	void set(double x, double y, double z);
	inline void setX(double x) { x_ = x; }
	inline void setY(double y) { y_ = y; }
	inline void setZ(double z) { z_ = z; }


	float getMagnitude() const;
	float getSqrtMagnitude() const;

	void normalize();

	//inverse the vector v (v= -v)
	void invert();
	
	//returns determinant
	double getDeterminant();
	
	//operators

	Vector3D operator+(const Vector3D& v);
	Vector3D operator-(const Vector3D& v);
	Vector3D operator*(const Vector3D& v);
	Vector3D operator*(const double& d);
	Vector3D operator%(const Vector3D& v);
	
	//returns the angle
	float operator<(const Vector3D& v); 

private:
	double x_, y_, z_; //components
};

