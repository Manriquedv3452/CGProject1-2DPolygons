#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "utilities.h"
#include "scanner.c"
#include "line_algorithms.c"
#include "draw_provinces.c"

void display_points(void);
int is_numeric(char character);
int verify_argument(char *argument);


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
	//int x0, y0, x1, y1;

	draw_sanjose();
	draw_alajuela();
	draw_cartago();
	draw_heredia();
	draw_guanacaste();
	draw_puntarenas();
	draw_limon();

	glColor3f(1, 1, 1);
	bresenham_algorithm(xmin, ymin, xmax, ymin);
	bresenham_algorithm(xmin, ymin, xmin, ymax);
	bresenham_algorithm(xmin, ymax, xmax, ymax);
	bresenham_algorithm(xmax, ymax, xmax, ymin);
	
	glFlush();
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
