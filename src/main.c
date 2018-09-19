#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "utilities.h"
#include "clipping_algorithms.c"
#include "scanner.c"
#include "line_algorithms.c"
#include "draw_provinces.c"

/*CONSTANTS*/
#define TOTAL_POINTS 2435
#define PLACES_NUMBER 8

#define SANJOSE_POINTS 298
#define ALAJUELA_POINTS 463
#define CARTAGO_POINTS 131
#define HEREDIA_POINTS 145
#define GUANACASTE_POINTS 472
#define PUNTARENAS_POINTS 545
#define PUNTARENAS2_POINTS 131
#define LIMON_POINTS 250

#define HORIZONTAL_RESOLUTION 800
#define VERTICAL_RESOLUTION 800
#define ZOOM_INCREMENT 0.001

#define DEGREE_ROTATE 0.1

#define PAN_DELTA 5

void display_points(void);
int is_numeric(char character);
int verify_argument(char *argument);
void parsekey_special(int key, int x, int y);
void key_down(unsigned char key, int x, int y);
void key_up(unsigned char key, int x, int y);

void zoom_in(void);
void zoom_out(void);
void rotate_provinces_clockwise(void);
void rotate_provinces_counterclockwise(void);
void pan_operations(int key, int x, int y);
void draw_window(void);

void initialize_sanjose(void);
void initialize_alajuela(void);
void initialize_cartago(void);
void initialize_heredia(void);
void initialize_guanacaste(void);
void initialize_puntarenas(void);
void initialize_limon(void);

void get_original_points(void);


int options[ACTIONS];


int main(int argc, char *argv[])
{
	//Start scanning process
	/*if (argc != 3){
        printf("Argumento no encontrado o no es válido.\n\n"
            "Para correr: ./programa <Hres> <Vres>\n\n");
        return 0;
    }*/
	printf("\n i = zoom in"
			"\n o = zoom out"
			"\n r = rotate clockwise"
			"\n c + r = rotate counterclockwise"
			"\n p = activate clipping"
			"\n RIGHT = pan to right"
			"\n LEFT = pan to left"
			"\n DOWN = pan to bottom"
			"\n UP = pan to up"
			"\n d = draw window"
			"\n s = restart"
			"\n f = finish\n\n");

    horizontal_resolution = HORIZONTAL_RESOLUTION;
	vertical_resolution = VERTICAL_RESOLUTION;
 

    /*if (horizontal_resolution == -1 || vertical_resolution == -1){
        printf("Argumento no encontrado o no es válido.\n\n"
            "Para correr: ./programa <resolucion> \n\n");
        return 0;
    }*/

	xmin = 0;
	ymin = 0;
	xmax = horizontal_resolution;
	ymax = vertical_resolution;
	xc = (xmin + xmax)/2;
	yc = (ymin + ymax)/2;

	for (int i = 0; i < ACTIONS; i++)
		options[i] = 0;

	polygons = calloc(PLACES_NUMBER, sizeof(Line));
	provinces_detail = calloc(PLACES_NUMBER, sizeof(Province));

	polygons[SANJOSE] = calloc(SANJOSE_POINTS, sizeof(Line));
	polygons[ALAJUELA] = calloc(ALAJUELA_POINTS, sizeof(Line));
	polygons[CARTAGO] = calloc(CARTAGO_POINTS, sizeof(Line));
	polygons[HEREDIA] = calloc(HEREDIA_POINTS, sizeof(Line));
	polygons[GUANACASTE] = calloc(GUANACASTE_POINTS, sizeof(Line));
	polygons[PUNTARENAS] = calloc(PUNTARENAS_POINTS, sizeof(Line));
	polygons[PUNTARENAS2] = calloc(PUNTARENAS2_POINTS, sizeof(Line));
	polygons[LIMON] = calloc(LIMON_POINTS, sizeof(Line));

	initialize_sanjose();
	initialize_alajuela();
	initialize_cartago();
	initialize_heredia();
	initialize_guanacaste();
	initialize_puntarenas();
	initialize_limon();

	get_original_points();
	
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(horizontal_resolution, vertical_resolution);
    glutCreateWindow("Proyecto 1");
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-0.5, horizontal_resolution +0.5, -0.5, vertical_resolution + 0.5);
    glutDisplayFunc(display_points);
	glutSpecialFunc(pan_operations);
	glutKeyboardFunc(key_down);
	glutKeyboardUpFunc(key_up);
    glutMainLoop();
	return 1;


}

void get_original_points(void)
{
	initialize_sanjose();
	initialize_alajuela();
	initialize_cartago();
	initialize_heredia();
	initialize_guanacaste();
	initialize_puntarenas();
	initialize_limon();

	scanner("../points/SanJose.svg", SANJOSE, &polygons, &provinces_detail);
	scanner("../points/Alajuela.svg", ALAJUELA, &polygons, &provinces_detail);
	scanner("../points/Cartago.svg", CARTAGO, &polygons, &provinces_detail);
	scanner("../points/Heredia.svg", HEREDIA, &polygons, &provinces_detail);
	scanner("../points/Guanacaste.svg", GUANACASTE, &polygons, &provinces_detail);
	scanner("../points/Puntarenas.svg", PUNTARENAS, &polygons, &provinces_detail);
	scanner("../points/Puntarenas2.svg", PUNTARENAS2, &polygons, &provinces_detail);
	scanner("../points/Limon.svg", LIMON, &polygons, &provinces_detail);
}

void display_points(void)
{
	//int x0, y0, x1, y1;
	if (options[P_KEY])
	{
		for (int i = 0; i < PLACES_NUMBER; i++)
				cohen_sutherland (&polygons, i, provinces_detail[i].points_quantity);
	}
	glClear(GL_COLOR_BUFFER_BIT);

	draw_sanjose();
	draw_alajuela();
	draw_cartago();
	draw_heredia();
	draw_guanacaste();
	draw_puntarenas();
	draw_limon();

	if (options[D_KEY])
	{
		draw_window();
	}
	
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

void key_up(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 'o': options[O_KEY] = 0; break;
		case 'i': options[I_KEY] = 0; break;
		case 'r': options[R_KEY] = 0; break;
		case 'c': options[C_KEY] = 0; break;
		default:
			return;
	}
}
void key_down(unsigned char key, int x, int y)
{		
	if (key == 'o')
	{
		options[O_KEY] = 1;
		zoom_out();
	}

	else if (key == 'i')
	{
		options[I_KEY] = 1;
		zoom_in();
	}
	
	else if(key == 'r' && !options[C_KEY])
	{
		options[R_KEY] = 1;
		rotate_provinces_clockwise();
	}
	else if (key == 'c')
	{
		options[C_KEY] = 1;
	}
	else if (key == 'r' && options[C_KEY])
	{
		rotate_provinces_counterclockwise();
	}
	else if (key == 's')
	{
		xmin = 0;
		ymin = 0;
		xmax = horizontal_resolution;
		ymax = vertical_resolution;
		xc = (xmin + xmax)/2;
		yc = (ymin + ymax)/2;
		get_original_points();
		
	}
	else if (key == 'p')
	{
		options[P_KEY] = options[P_KEY] == 1 ? 0 : 1;
	}

	else if (key == 'd')
	{
		options[D_KEY] = options[D_KEY] == 1 ? 0 : 1;
	}
	else if (key == 'f')
	{
		exit(1);
	}
    glutPostRedisplay();
}

void rotate_provinces_clockwise(void)
{
	for (int i = 0; i < PLACES_NUMBER; i++)
		rotate_province_clockwise(DEGREE_ROTATE, provinces_detail, i);
}

void rotate_provinces_counterclockwise(void)
{
	for (int i = 0; i < PLACES_NUMBER; i++)
		rotate_province_counterclockwise(DEGREE_ROTATE, provinces_detail, i);
}

void zoom_in(void)
{
	if (zoom > 1.0)
			zoom = 1.0;
			
	if (zoom > 0)
	{
		zoom -= ZOOM_INCREMENT;
	}
	
	xmin = ((xmin - xc) * zoom) + xc;
	ymin = ((ymin - yc) * zoom) + yc;
	xmax = ((xmax - xc) * zoom) + xc;
	ymax = ((ymax - yc) * zoom) + yc;

	xc = (xmin + xmax)/2;
	yc = (ymin + ymax)/2;
}

void zoom_out(void)
{
	if (zoom < 1.0)
			zoom = 1.0;

	zoom += ZOOM_INCREMENT;

	xmin = ((xmin - xc) * zoom) + xc;
	ymin = ((ymin - yc) * zoom) + yc;
	xmax = ((xmax - xc) * zoom) + xc;
	ymax = ((ymax - yc) * zoom) + yc;

	xc = (xmin + xmax)/2;
	yc = (ymin + ymax)/2;
}

void pan_operations(int key, int x, int y)
{
	double delta_x = 0, delta_y = 0;
    switch (key)
    {
		case GLUT_KEY_UP: delta_y = PAN_DELTA; break;
		case GLUT_KEY_DOWN:	delta_y = -PAN_DELTA; break;
		case GLUT_KEY_RIGHT: delta_x = PAN_DELTA; break;
		case GLUT_KEY_LEFT:	delta_x = -PAN_DELTA; break;
        default:
	    return;
    }
	xmin += delta_x;
	ymin += delta_y;
	xmax += delta_x;
	ymax += delta_y;

	glutPostRedisplay();
	
}

void draw_window(void)
{
	glColor3f(1, 1, 1);
	bresenham_algorithm(xmin, ymin, xmax, ymin);
	bresenham_algorithm(xmin, ymin, xmin, ymax);
	bresenham_algorithm(xmin, ymax, xmax, ymax);
	bresenham_algorithm(xmax, ymax, xmax, ymin);
}

void initialize_sanjose(void)
{
	provinces_detail[SANJOSE].points_quantity = SANJOSE_POINTS;
	provinces_detail[SANJOSE].sum_x0 = 0;
	provinces_detail[SANJOSE].sum_y0 = 0;
	provinces_detail[SANJOSE].sum_x1 = 0;
	provinces_detail[SANJOSE].sum_y1 = 0;
}

void initialize_alajuela(void)
{
	provinces_detail[ALAJUELA].points_quantity = ALAJUELA_POINTS;
	provinces_detail[ALAJUELA].sum_x0 = 0;
	provinces_detail[ALAJUELA].sum_y0 = 0;
	provinces_detail[ALAJUELA].sum_x1 = 0;
	provinces_detail[ALAJUELA].sum_y1 = 0;
}

void initialize_cartago(void)
{
	provinces_detail[CARTAGO].points_quantity = CARTAGO_POINTS;
	provinces_detail[CARTAGO].sum_x0 = 0;
	provinces_detail[CARTAGO].sum_y0 = 0;
	provinces_detail[CARTAGO].sum_x1 = 0;
	provinces_detail[CARTAGO].sum_y1 = 0;
}

void initialize_heredia(void)
{
	provinces_detail[HEREDIA].points_quantity = HEREDIA_POINTS;
	provinces_detail[HEREDIA].sum_x0 = 0;
	provinces_detail[HEREDIA].sum_y0 = 0;
	provinces_detail[HEREDIA].sum_x1 = 0;
	provinces_detail[HEREDIA].sum_y1 = 0;
}

void initialize_guanacaste(void)
{
	provinces_detail[GUANACASTE].points_quantity = GUANACASTE_POINTS;
	provinces_detail[GUANACASTE].sum_x0 = 0;
	provinces_detail[GUANACASTE].sum_y0 = 0;
	provinces_detail[GUANACASTE].sum_x1 = 0;
	provinces_detail[GUANACASTE].sum_y1 = 0;
}

void initialize_puntarenas(void)
{
	provinces_detail[PUNTARENAS].points_quantity = PUNTARENAS_POINTS;
	provinces_detail[PUNTARENAS].sum_x0 = 0;
	provinces_detail[PUNTARENAS].sum_y0 = 0;
	provinces_detail[PUNTARENAS].sum_x1 = 0;
	provinces_detail[PUNTARENAS].sum_y1 = 0;

	provinces_detail[PUNTARENAS2].points_quantity = PUNTARENAS2_POINTS;
	provinces_detail[PUNTARENAS2].sum_x0 = 0;
	provinces_detail[PUNTARENAS2].sum_y0 = 0;
	provinces_detail[PUNTARENAS2].sum_x1 = 0;
	provinces_detail[PUNTARENAS2].sum_y1 = 0;
}

void initialize_limon(void)
{
	provinces_detail[LIMON].points_quantity = LIMON_POINTS;
	provinces_detail[LIMON].sum_x0 = 0;
	provinces_detail[LIMON].sum_y0 = 0;
	provinces_detail[LIMON].sum_x1 = 0;
	provinces_detail[LIMON].sum_y1 = 0;
}

