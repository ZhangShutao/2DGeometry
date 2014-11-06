#include "Point.h"
#include "Vector.h"
#include <cmath>

// Constructors & Destructor
Point::Point(double a/* = 0*/, double b/* = 0*/) : m_x(a), m_y(b)
{
}

Point::Point(const Point& p) : m_x(p.m_x), m_y(p.m_y)
{
}

Point::~Point()
{
}

// Operators
Point Point::operator = (const Point& p)
{
    m_x = p.m_x;
    m_y = p.m_y;
    return *this;
}

//! If two points are in the same place
/*!
 * \param the other point
 * \return true if they are in the same place
 */
bool Point::operator == (const Point& p) const
{
    return (dcmp(m_x - p.m_x) == 0) && (dcmp(m_y - p.m_y) == 0);
}

bool Point::operator < (const Point& p) const
{
    if (dcmp(m_x - p.m_x) == 0)
        return dcmp(m_y - p.m_y) < 0;
    return dcmp(m_x - p.m_y) < 0;
}

//! If this point is prior to another one in Cartesian coordinate system
/*!
 * \param the other point
 * \return check result
 */
//bool Point::IsPriorInCartesian(const Point& p) const
//{
//    if (dcmp(m_x - p.m_x) == 0)
//        return dcmp(m_y - p.m_y) < 0;
//    return dcmp(m_x - p.m_y) < 0;
//}

//! If this point is prior to another one in Polar coordinate system
/*!
 * The angle in this system is [-Pi, Pi)
 * \param the other point
 * \return check result
 */
//bool Point::IsPriorInPolar(const Point& p) const
//{
//    double angle1 = atan(m_y / m_x);
//    double angle2 = atan(p.m_y / p.m_x);
//    return dcmp(angle1 - angle2) < 0;
//}

//! Translate this point with a vector
Point Point::Translate(const Vector& v) const
{
    Point res(*this);
    res.m_x += v.GetX();
    res.m_y += v.GetY();
    return res;
}
