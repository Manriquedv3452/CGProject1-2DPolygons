#include <GL/glut.h>
#include <math.h>

/*CONSTANTS*/
#define PLACES_NUMBER 8

#define SANJOSE_POINTS 298
#define ALAJUELA_POINTS 463
#define CARTAGO_POINTS 131
#define HEREDIA_POINTS 145
#define GUANACASTE_POINTS 472
#define PUNTARENAS_POINTS 545
#define PUNTARENAS2_POINTS 131
#define LIMON_POINTS 250

/*GLOBAL VARS*/
FILE *output;
FILE *file;
int horizontal_resolution, vertical_resolution;
double xmin, ymin, xmax, ymax;
Line **polygons;

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