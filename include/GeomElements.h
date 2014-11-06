/*!
 * This project is mean to implement some 2D geometry algorithms. There are
 * some classes in this project.
 * This file declares some classes, and will be included by all class's
 * head files, since the relationship between these classes is not hierarchical.
 */

#ifndef GEOMELEMENTS_H_INCLUDED
#define GEOMELEMENTS_H_INCLUDED
// Constants
const double EPS = 1e-9;
const double Pi = 3.1415926535897932384626433832795;
const double E = 2.7182818284590452353602874713527;

// Classes
class Point;
class Vector;
class Line;

// Global functions
int dcmp(double x);

#endif // GEOMELEMENTS_H_INCLUDED
