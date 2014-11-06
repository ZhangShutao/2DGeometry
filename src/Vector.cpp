#include "Vector.h"
#include "Point.h"
#include <cmath>

Vector::Vector(double a/* = 0*/, double b/* = 0*/) : m_x(a), m_y(b)
{
    //ctor
}

Vector::Vector(const Vector& v) : m_x(v.m_x), m_y(v.m_y)
{

}

Vector::Vector(const Point& pa, const Point& pb)
{
    m_x = pb.GetX() - pa.GetX();
    m_y = pb.GetY() - pa.GetY();
}

Vector::~Vector()
{
    //dtor
}

Vector Vector::operator = (const Vector& v)
{
    m_x = v.m_x;
    m_y = v.m_y;
    return *this;
}

Vector Vector::operator + (const Vector& v) const
{
    Vector res(*this);
    res.m_x += v.m_x;
    res.m_y += v.m_y;
    return res;
}

Vector Vector::operator += (const Vector& v)
{
    m_x += v.m_x;
    m_y += v.m_y;
    return *this;
}

Vector Vector::operator - (const Vector& v) const
{
    Vector res(*this);
    res.m_x -= v.m_x;
    res.m_y -= v.m_y;
    return res;
}

Vector Vector::operator -= (const Vector& v)
{
    m_x -= v.m_x;
    m_y -= v.m_y;
    return *this;
}

Vector Vector::operator * (double x) const
{
    return Vector(m_x * x, m_y * x);
}

Vector Vector::operator *= (double x)
{
    m_x *= x;
    m_y *= x;
    return *this;
}

bool Vector::operator == (const Vector& v) const
{
    return (dcmp(m_x - v.m_x) == 0) && (dcmp(m_y - v.m_y) == 0);
}

//! get the length of this vector
double Vector::Length() const
{
    return sqrt(m_x * m_x + m_y * m_y);
}

//! cross product
double Vector::Cross(const Vector& v) const
{
    return (m_x * v.m_y - m_y * v.m_x);
}

//! Dot product
double Vector::Dot(const Vector& v) const
{
    return (m_x * v.m_x + m_y * v.m_y);
}

//! the angle between this vector and vector v
double Vector::Angle(const Vector& v) const
{
    return acos(Dot(v) / Length() / v.Length());
}

//! Rote this vector by a radian
Vector Vector::Rotate(double rad) const
{
    return Vector(m_x * cos(rad) - m_y * sin(rad), m_x * sin(rad) + m_y * cos(rad));
}

//! Normalize this vector
Vector Vector::Normal() const
{
    double Len = Length();
    return Vector(-m_y / Len, m_x / Len);
}

//! the uniformed vector
Vector Vector::Uniform() const
{
    double Len = Length();
    return Vector(m_x / Len, m_y / Len);
}
