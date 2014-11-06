/*!
 * Point is the basic element in geometry.
 */

#ifndef POINT_H
#define POINT_H

#include "GeomElements.h"

class Point
{
    public:
        // Constructor & Destructor
        Point(double a = 0, double y = 0);
        Point(const Point& p);
        virtual ~Point();

        // Operators
        Point operator = (const Point& p);
        bool operator == (const Point& p) const;
        bool operator < (const Point& p) const;

        // Methods
        //! Gets and Sets
        double GetX() const;
        double GetY() const;

// may be we should use constructors instead of Sets
//        void SetX(double x);
//        void SetY(double y);
//        void SetPoint(double x, double y);

//        //! If this point is prior to another one in Cartesian coordinate system
//        bool IsPriorInCartesian(const Point& p) const;
//
//        //! If this point is prior to another one in Polar coordinate system
//        bool IsPriorInPolar(const Point& p) const;

        //! Translate this point with a vector
        Point Translate(const Vector& v) const;

    protected:
        double m_x;
        double m_y;
};

//! Inline functions
inline double Point::GetX() const
{
    return m_x;
}

inline double Point::GetY() const
{
    return m_y;
}

//inline void Point::SetX(double x)
//{
//    m_x = x;
//}
//
//inline void Point::SetY(double y)
//{
//    m_y = y;
//}
//
//inline void Point::SetPoint(double x, double y)
//{
//    m_x = x; m_y = y;
//}

#endif // POINT_H
