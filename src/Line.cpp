#include "Line.h"
#include "Point.h"
#include "Vector.h"
#include "Exceptions.h"
#include <iostream>
#include <cmath>
using namespace std;

// Constructors & Destructor
Line::Line()
{
    //ctor
}

Line::Line(const Line& l)
{
    m_p = l.m_p;
    m_vec = l.m_vec;
}

Line::Line(const Point& p, const Vector& v)
{
    m_p = p;
    m_vec = v;
}

Line::Line(const Point& pa, const Point& pb)
{
    m_p = pa;
    m_vec = Vector(pa, pb);
}

Line::~Line()
{
    //dtor
}


Line Line::operator = (const Line& l)
{
    m_p = l.m_p;
    m_vec = l.m_vec;
    return *this;
}

bool Line::operator == (const Line& l) const
{
    try
    {
        return (Parallel(l) && GetPoint(0) == l.GetPoint(0));
    }
    catch (ElementNotExistException& e)
    {
        cerr << e.what() << endl;
        return (Parallel(l) && m_p.GetX() == l.m_p.GetX());
    }
}

// Methods
//! Get a point on the line whose abscissa is x
/*!
 * \param the abscissa
 * \return if there is such a point, return it, other wise
 */
Point Line::GetPoint(double x) const
{
    if (m_vec.GetX() == 0)
    {// This line is parallel to y axis, which means there may be no Point(x, y) on this line
        if (x == m_p.GetX())
            return Point(m_p.GetX(), 0);
        else
            throw ElementNotExistException("No such a point");
    }

    double scale = (m_p.GetX() - x) / m_vec.GetX();
    double y = m_p.GetY() - scale * m_vec.GetY();
    return Point(x, y);
}

Vector Line::GetVector() const
{
    return m_vec.Uniform();
}

bool Line::Parallel(const Line& l) const
{
    return (GetVector() == l.GetVector() || GetVector() * -1 == l.GetVector());
}

Line Line::Translate(const Vector& v) const
{
    return Line(m_p.Translate(v), v);
}
