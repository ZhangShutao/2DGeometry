#ifndef VECTOR_H
#define VECTOR_H

#include "GeomElements.h"

class Vector
{
    public:
        // Constructors & Destructor
        Vector(double a = 0, double b = 0);
        Vector(const Vector& v);
        Vector(const Point& pa, const Point& pb);
        virtual ~Vector();
        // Operators
        Vector operator = (const Vector& v);
        Vector operator + (const Vector& v) const;
        Vector operator += (const Vector& v);
        Vector operator - (const Vector& v) const;
        Vector operator -= (const Vector& v);
        Vector operator * (double x) const;
        Vector operator *= (double x);
        bool operator == (const Vector& v) const;

        // Methods
        //! Gets and Sets
        double GetX() const;
        double GetY() const;
//        void SetX(double x);
//        void SetY(double y);
//        void SetVector(double x, double y);

        //! get the length of this vector
        double Length() const;

        //! cross product
        double Cross(const Vector& v) const;

        //! Dot product
        double Dot(const Vector& v) const;

        //! the angle between this vector and vector v
        double Angle(const Vector& v) const;

        //! Rote this vector by a radian
        Vector Rotate(double rad) const;

        //! the normal vector of this vector
        Vector Normal() const;

        //! the uniformed vector
        Vector Uniform() const;

    protected:
        double m_x;
        double m_y;
    private:
};

//! Inline functions
inline double Vector::GetX() const
{
    return m_x;
}

inline double Vector::GetY() const
{
    return m_y;
}

//inline void Vector::SetX(double x)
//{
//    m_x = x;
//}
//
//inline void Vector::SetY(double y)
//{
//    m_y = y;
//}
//
//inline void Vector::SetVector(double x, double y)
//{
//    m_x = x;
//    m_y = y;
//}

#endif // VECTOR_H
