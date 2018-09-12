#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "utilities.h"
#include "scanner.c"
#include "line_algorithms.c"

#define PLACES_NUMBER 8

#define SANJOSE_POINTS 298
#define ALAJUELA_POINTS 463
#define CARTAGO_POINTS 131
#define HEREDIA_POINTS 145
#define GUANACASTE_POINTS 472
#define PUNTARENAS_POINTS 545
#define PUNTARENAS2_POINTS 131
#define LIMON_POINTS 250


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
	polygons[SANJOSE] = calloc(SANJOSE_POINTS, sizeof(Line));
	polygons[ALAJUELA] = calloc(ALAJUELA_POINTS, sizeof(Line));
	polygons[CARTAGO] = calloc(CARTAGO_POINTS, sizeof(Line));
	polygons[HEREDIA] = calloc(HEREDIA_POINTS, sizeof(Line));
	polygons[GUANACASTE] = calloc(GUANACASTE_POINTS, sizeof(Line));
	polygons[PUNTARENAS] = calloc(PUNTARENAS_POINTS, sizeof(Line));
	polygons[PUNTARENAS2] = calloc(PUNTARENAS2_POINTS, sizeof(Line));
	polygons[LIMON] = calloc(LIMON_POINTS, sizeof(Line));

	scanner("../points/SanJose.svg", SANJOSE, &polygons, SANJOSE_POINTS);
	scanner("../points/Alajuela.svg", ALAJUELA, &polygons, ALAJUELA_POINTS);
	scanner("../points/Cartago.svg", CARTAGO, &polygons, CARTAGO_POINTS);
	scanner("../points/Heredia.svg", HEREDIA, &polygons, HEREDIA_POINTS);
	scanner("../points/Guanacaste.svg", GUANACASTE, &polygons, GUANACASTE_POINTS);
	scanner("../points/Puntarenas.svg", PUNTARENAS, &polygons, PUNTARENAS_POINTS);
	scanner("../points/Puntarenas2.svg", PUNTARENAS2, &polygons, PUNTARENAS2_POINTS);
	scanner("../points/Limon.svg", LIMON, &polygons, LIMON_POINTS);
	
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

	//SAN JOSE
	glColor3f(0, 1, 1);
	for (int i = 0; i < SANJOSE_POINTS; i++)
	{
		x0 = convert_framebuffer_coord(
			horizontal_resolution, polygons[SANJOSE][i].x0, xmax, xmin
		);

		y0 = convert_framebuffer_coord(
			vertical_resolution, polygons[SANJOSE][i].y0, ymax, ymin
		);

		x1 = convert_framebuffer_coord(
			horizontal_resolution, polygons[SANJOSE][i].x1, xmax, xmin
		);

		y1 = convert_framebuffer_coord(
			vertical_resolution, polygons[SANJOSE][i].y1, ymax, ymin
		);
		
		bresenham_algorithm (x0, y0, x1, y1);
	}
	

	//ALAJUELA
	glColor3f(0, 1, 0);
	for (int i = 0; i < ALAJUELA_POINTS; i++)
	{
		x0 = convert_framebuffer_coord(
			horizontal_resolution, polygons[ALAJUELA][i].x0, xmax, xmin
		);

		y0 = convert_framebuffer_coord(
			vertical_resolution, polygons[ALAJUELA][i].y0, ymax, ymin
		);

		x1 = convert_framebuffer_coord(
			horizontal_resolution, polygons[ALAJUELA][i].x1, xmax, xmin
		);

		y1 = convert_framebuffer_coord(
			vertical_resolution, polygons[ALAJUELA][i].y1, ymax, ymin
		);
		
		bresenham_algorithm (x0, y0, x1, y1);
	}


	//CARTAGO
	glColor3f(1, 1, 1);
	for (int i = 0; i < CARTAGO_POINTS; i++)
	{
		x0 = convert_framebuffer_coord(
			horizontal_resolution, polygons[CARTAGO][i].x0, xmax, xmin
		);

		y0 = convert_framebuffer_coord(
			vertical_resolution, polygons[CARTAGO][i].y0, ymax, ymin
		);

		x1 = convert_framebuffer_coord(
			horizontal_resolution, polygons[CARTAGO][i].x1, xmax, xmin
		);

		y1 = convert_framebuffer_coord(
			vertical_resolution, polygons[CARTAGO][i].y1, ymax, ymin
		);
		
		bresenham_algorithm (x0, y0, x1, y1);
	}

	//HEREDIA
	glColor3f(1, 1, 0);
	for (int i = 0; i < HEREDIA_POINTS; i++)
	{
		x0 = convert_framebuffer_coord(
			horizontal_resolution, polygons[HEREDIA][i].x0, xmax, xmin
		);

		y0 = convert_framebuffer_coord(
			vertical_resolution, polygons[HEREDIA][i].y0, ymax, ymin
		);

		x1 = convert_framebuffer_coord(
			horizontal_resolution, polygons[HEREDIA][i].x1, xmax, xmin
		);

		y1 = convert_framebuffer_coord(
			vertical_resolution, polygons[HEREDIA][i].y1, ymax, ymin
		);
		
		bresenham_algorithm (x0, y0, x1, y1);
	}

	//GUANACASTE
	glColor3f(0, 0, 1);
	for (int i = 0; i < GUANACASTE_POINTS; i++)
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


	//PUNTARENAS
	glColor3f(1, 0, 0);
	for (int i = 0; i < PUNTARENAS_POINTS; i++)
	{
		x0 = convert_framebuffer_coord(
			horizontal_resolution, polygons[PUNTARENAS][i].x0, xmax, xmin
		);

		y0 = convert_framebuffer_coord(
			vertical_resolution, polygons[PUNTARENAS][i].y0, ymax, ymin
		);

		x1 = convert_framebuffer_coord(
			horizontal_resolution, polygons[PUNTARENAS][i].x1, xmax, xmin
		);

		y1 = convert_framebuffer_coord(
			vertical_resolution, polygons[PUNTARENAS][i].y1, ymax, ymin
		);
		
		bresenham_algorithm (x0, y0, x1, y1);
	}

	glColor3f(1, 0, 0);
	for (int i = 0; i < PUNTARENAS2_POINTS; i++)
	{
		x0 = convert_framebuffer_coord(
			horizontal_resolution, polygons[PUNTARENAS2][i].x0, xmax, xmin
		);

		y0 = convert_framebuffer_coord(
			vertical_resolution, polygons[PUNTARENAS2][i].y0, ymax, ymin
		);

		x1 = convert_framebuffer_coord(
			horizontal_resolution, polygons[PUNTARENAS2][i].x1, xmax, xmin
		);

		y1 = convert_framebuffer_coord(
			vertical_resolution, polygons[PUNTARENAS2][i].y1, ymax, ymin
		);
		
		bresenham_algorithm (x0, y0, x1, y1);
	}


	//LIMON
	glColor3f(1, 0, 1);
	for (int i = 0; i < LIMON_POINTS; i++)
	{
		x0 = convert_framebuffer_coord(
			horizontal_resolution, polygons[LIMON][i].x0, xmax, xmin
		);

		y0 = convert_framebuffer_coord(
			vertical_resolution, polygons[LIMON][i].y0, ymax, ymin
		);

		x1 = convert_framebuffer_coord(
			horizontal_resolution, polygons[LIMON][i].x1, xmax, xmin
		);

		y1 = convert_framebuffer_coord(
			vertical_resolution, polygons[LIMON][i].y1, ymax, ymin
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
	return  (double)t_resolution * ((t_window - t_min)/(t_max - t_min));
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
