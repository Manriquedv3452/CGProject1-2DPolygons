#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "utilities.h"
#include "scanner.c"
#include "line_algorithms.c"

#define PLACES_NUMBER 8
#define GSIZE 248

int convert_framebuffer_coord(int t_resolution, double t_window, double t_max, double t_min);
void display_points(void);
int is_numeric(char character);
int verify_argument(char *argument);

FILE *output;
FILE *file;
int horizontal_resolution, vertical_resolution;
double xmin, ymin, xmax, ymax;
Line **polygons;

int main(int argc, char *argv[])
{
	//Start scanning process
	if (argc != 3){
        printf("Argumento no encontrado o no es válido.\n\n"
            "Para correr: ./programa <Hres> <Vres>\n\n");
        return 0;
    }

    horizontal_resolution = verify_argument(argv[1]);
	vertical_resolution = verify_argument(argv[2]);
 

    if (horizontal_resolution == -1 || vertical_resolution == -1){
        printf("Argumento no encontrado o no es válido.\n\n"
            "Para correr: ./programa <resolucion> \n\n");
        return 0;
    }

	xmin = 0;
	ymin = 0;
	xmax = horizontal_resolution;
	ymax = vertical_resolution;

	polygons = calloc(PLACES_NUMBER, sizeof(Line));
	polygons[GUANACASTE] = calloc(GSIZE, sizeof(Line));

	scanner("../points/Guanacaste.svg", GUANACASTE, &polygons, GSIZE);
	
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(horizontal_resolution, vertical_resolution);
    glutCreateWindow("Proyecto 1");
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-0.5, horizontal_resolution +0.5, -0.5, vertical_resolution + 0.5);
    glutDisplayFunc(display_points);
    glutMainLoop();
	return 1;


}

void display_points(void)
{
	int x0, y0, x1, y1;

	glColor3f(0, 0, 1);
	for (int i = 0; i < GSIZE; i++)
	{
		x0 = convert_framebuffer_coord(
			horizontal_resolution, polygons[GUANACASTE][i].x0, xmax, xmin
		);

		y0 = convert_framebuffer_coord(
			vertical_resolution, polygons[GUANACASTE][i].y0, ymax, ymin
		);

		x1 = convert_framebuffer_coord(
			horizontal_resolution, polygons[GUANACASTE][i].x1, xmax, xmin
		);

		y1 = convert_framebuffer_coord(
			vertical_resolution, polygons[GUANACASTE][i].y1, ymax, ymin
		);
		
		bresenham_algorithm (x0, y0, x1, y1);
	}

	glFlush();
}



/*
	Convert universal coords to frameBuffer coords
	t_resolution = horizontal_resolution or vertical_resolution
	t_window = x_window or y_window
	t_max = xmax or ymax
	t_min = xmin or ymin
*/
int convert_framebuffer_coord(int t_resolution, double t_window, double t_max, double t_min)
{
	return  t_resolution * ((t_window - t_min)/(t_max - t_min));
}

//return -1 if the argument is invalid
//else return the integer value.
int verify_argument(char *argument){

    for (int i = 0; argument[i] != '\0'; i++){
        if (!is_numeric(argument[i]))
            return -1;

    }
    return atoi(argument);

}

//return 0 (False) if a char is not numeric.
int is_numeric(char character){
	if (character >= 48 && character <= 57)
		return 1;

	return 0;
}
