#include "Vector2D.h"
#include<iostream>
#include <string>
#include <sstream>

using namespace std;
Vector2D::Vector2D()
	: x(0), y(0)
{}

Vector2D::Vector2D(double a, double b)
{
	setX(a), setY(b);
}

Vector2D::Vector2D(const Vector2D& t)
{
	*this = t;
}

Vector2D::operator string() const
{
	stringstream sout;
	sout << "(" << getX() << "; " << getY() << ")" << endl;
	return sout.str();
}

double operator * (Vector2D g, Vector2D f)
{
	double t = g.x * f.x + g.y * f.y;
	return t;
}

Vector2D operator * (Vector2D g, double l)
{
	Vector2D tmp;
	tmp.x = g.x * l;
	tmp.y = g.y * l;
	return tmp;
}

double Vector2D::Modul()
{
	double mod = sqrt((x * x) + (y * y));
	return mod;

}

bool operator > (Vector2D a, Vector2D b)
{
	if (a.Modul() > b.Modul())
	{
		cout << "Vector A > Vector B" << endl << endl;
		return true;
	}
	else
		return false;
}

bool operator < (Vector2D a, Vector2D b)
{
	if (a.Modul() < b.Modul())
	{
		cout << "Vector A < Vector B" << endl << endl;
		return true;
	}
	else
		return false;
}

bool operator ==(Vector2D a, Vector2D b)
{
	if (a.Modul() == b.Modul())
	{
		cout << "Vector A = Vector B" << endl << endl;
		return true;
	}
	else
		return false;
}

istream& operator >> (istream& in, Vector2D& a) throw (exception, Error)
{
	double x, y;
	cout << "x = "; in >> x;
	cout << "y = "; in >> y;
	if (x == 0)
		throw new Error("x = 0");
	if (y == 1)
		throw bad_exception();
	if (y == 10)
		throw exception();
	a.setX(x), a.setY(y);
	return in;
}

ostream& operator << (ostream& out, Vector2D& a)
{
	out << string(a) << endl;
	return out;
}

Vector2D& Vector2D::operator ++()
{
	++x;
	return *this;
}

Vector2D& Vector2D::operator --()
{
	--y;
	return *this;
}

Vector2D Vector2D::operator ++(int)
{
	Vector2D tmp = *this;
	++x;
	return tmp;
}

Vector2D Vector2D::operator --(int)
{
	Vector2D tmp = *this;
	--y;
	return tmp;
}