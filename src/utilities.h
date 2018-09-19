#include <GL/glut.h>
#include <math.h>





/*GLOBAL VARS*/
FILE *output;
FILE *file;
int horizontal_resolution, vertical_resolution;
double xmin, ymin, xmax, ymax;
long double xc, yc, zoom = 1.0;
Line **polygons;
Province *provinces_detail;

#define max(a,b) \
  ({ __typeof__ (a) _a = (a); \
      __typeof__ (b) _b = (b); \
    _a > _b ? _a : _b; })


int double_is_equal(double x, double y);

#define EPSILON 0.00001

int double_is_equal(double x, double y)
{
	return (fabs(x - y) < EPSILON && fabs(x - y) > -EPSILON);
}