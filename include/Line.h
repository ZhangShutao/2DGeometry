#ifndef LINE_H
#define LINE_H

#include "GeomElements.h"
#include "Point.h"
#include "Vector.h"

class Line
{
    public:
        // Constructors & Destructor
        Line();
        Line(const Line& l);
        Line(const Point& p, const Vector& v);
        Line(const Point& pa, const Point& pb);
        virtual ~Line();

        // Operators
        Line operator = (const Line& l);
        bool operator == (const Line& l) const;

        // Methods
        //! Get a point on the line whose abscissa is x
        Point GetPoint(double x) const;
        Vector GetVector() const;

        //! if these two lines are parallel
        bool Parallel(const Line& l) const;

        //! translate this line to a new position
        Line Translate(const Vector& v) const;

        //! translate this line over a point
        Line Translate(const Point& p) const;
    protected:
        Point m_p;
        Vector m_vec;
    private:
};

#endif // LINE_H
