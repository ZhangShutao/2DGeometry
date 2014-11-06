#include "GeomElements.h"
#include <cmath>

/*!
 * Check the relationship between x and zero by taking consider of EPS.
 * \param the number to be checked
 * \return signature of x if x is not approximate to zero
 */
int dcmp(double x)
{
    if (fabs(x) < EPS) return 0;
    else return x < 0 ? -1 : 1;
}
