//#include "utilities.c"

void draw_sanjose(void);
void draw_alajuela(void);
void draw_cartago(void);
void draw_heredia(void);
void draw_guanacaste(void);
void draw_puntarenas(void);
void draw_limon(void);

int convert_framebuffer_coord(int t_resolution, double t_window, double t_max, double t_min);


void draw_sanjose(void)
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
}

void draw_alajuela(void)
{
	int x0, y0, x1, y1;
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
}

void draw_cartago(void)
{
	int x0, y0, x1, y1;
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
}


void draw_heredia(void)
{
	int x0, y0, x1, y1;
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
}

void draw_guanacaste(void)
{
	int x0, y0, x1, y1;
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
}

void draw_puntarenas(void)
{
	int x0, y0, x1, y1;
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
}

void draw_limon(void)
{
	int x0, y0, x1, y1;
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