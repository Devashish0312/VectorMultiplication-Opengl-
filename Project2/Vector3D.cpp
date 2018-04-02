#include "Vector3D.h"

Vector3D::Vector3D() {
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector3D::~Vector3D() {

}

Vector3D::Vector3D(float xCoord, float yCoord, float zCoord)
{
	this->x = xCoord;
	this->y = yCoord;
	this->z = zCoord;

}

Vector3D::Vector3D(const Vector3D& v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
}

Vector3D& Vector3D::operator=(const Vector3D& rhs)
{
	if (this != &rhs)
	{
		this->x = rhs.x;
		this->y = rhs.y;
		this->z = rhs.z;
	}

	return *this;
}

Vector3D operator+(const Vector3D& lhs, const Vector3D& rhs)
{
	Vector3D sum = Vector3D();

	sum.x = lhs.x + rhs.x;
	sum.y = lhs.y + rhs.y;
	sum.z = lhs.z + rhs.z;

	return sum;
}

Vector3D operator-(const Vector3D& lhs, const Vector3D& rhs)
{
	Vector3D diff = Vector3D();

	diff.x = lhs.x + rhs.x;
	diff.y = lhs.y + rhs.y;
	diff.z = lhs.z + rhs.z;

	return diff;
}

Vector3D operator*(const Vector3D& lhs, const float& rhs)
{
	Vector3D mul = Vector3D();

	mul.x = lhs.x * rhs;
	mul.y = lhs.y * rhs;
	mul.z = lhs.z * rhs;

	return mul;
}

Vector3D operator*(const float& lhs, const Vector3D& rhs) {
	return rhs * lhs;
}

float dot(const Vector3D &lhs, const Vector3D& rhs)
{
	return lhs.x*rhs.x + lhs.y*rhs.y + lhs.z*rhs.z;
}

float det(float a, float b, float c, float d)
{
	return a * d - b * c;
}

Vector3D cross(const Vector3D &lhs, const Vector3D& rhs)
{
	Vector3D cross = Vector3D();

	cross.x = det(lhs.y, lhs.z, rhs.y, rhs.z);
	cross.y = -1 * det(lhs.x, lhs.z, rhs.x, rhs.z);
	cross.z = det(lhs.x, lhs.y, rhs.x, rhs.y);

	return cross;
}



