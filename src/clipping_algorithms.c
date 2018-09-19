#define SIZE 1000

void cohen_sutherland (Line ***polygons, int province_number, int points_number);
void cohen_sutherland_left_edge(Line ***polygons, int province_number, int points_number);
void cohen_sutherland_right_edge(Line ***polygons, int province_number, int points_number);
void cohen_sutherland_top_edge(Line ***polygons, int province_number, int points_number);
void cohen_sutherland_bottom_edge(Line ***polygons, int province_number, int points_number);

int getcode(int x,int y);

int verify_line_inside(double);

static int LEFT=1,RIGHT=2,BOTTOM=4,TOP=8;
int getcode(int x,int y){
	int code = 0;
	//Perform Bitwise OR to get outcode
	if(y > ymax) code |=TOP;
	if(y < ymin) code |=BOTTOM;
	if(x < xmin) code |=LEFT;
	if(x > xmax) code |=RIGHT;
	return code;
}

void cohen_sutherland (Line ***polygons, int province_number, int points_number)
{
    //Coordinate new_coord = calloc(SIZE, sizeof(Coordinate));
    //initialize_linkedList();

    cohen_sutherland_left_edge(&(*polygons), province_number, points_number);
    cohen_sutherland_right_edge(&(*polygons), province_number, points_number);
    cohen_sutherland_top_edge(&(*polygons), province_number, points_number);
    cohen_sutherland_bottom_edge(&(*polygons), province_number, points_number);
  
}

void cohen_sutherland_left_edge(Line ***polygons, int province_number, int points_number)
{
    for (int i = 0; i < points_number; i++)
    {
        if ((*polygons)[province_number][i].x0 < xmin && (*polygons)[province_number][i].x1 < xmin)
            (*polygons)[province_number][i].accepted = 0;

        else if ((*polygons)[province_number][i].x0 >= xmin && (*polygons)[province_number][i].x1 >= xmin)
            continue;

        else if ((*polygons)[province_number][i].accepted)
        {
            if ((*polygons)[province_number][i].x0 < xmin)
            {
                (*polygons)[province_number][i].y0 = (*polygons)[province_number][i].y0 + ((*polygons)[province_number][i].y1 - (*polygons)[province_number][i].y0) 
                                        * (xmin - (*polygons)[province_number][i].x0) / ((*polygons)[province_number][i].x1 - (*polygons)[province_number][i].x0);
		        (*polygons)[province_number][i].x0 = xmin;
            }
            else
            {
                (*polygons)[province_number][i].y1 = (*polygons)[province_number][i].y1 + ((*polygons)[province_number][i].y0 - (*polygons)[province_number][i].y1) 
                                        * (xmin - (*polygons)[province_number][i].x1) / ((*polygons)[province_number][i].x0 - (*polygons)[province_number][i].x1);
		        (*polygons)[province_number][i].x1 = xmin;
            }
            (*polygons)[province_number][i].accepted = 1;
        }
    }
}

void cohen_sutherland_right_edge(Line ***polygons, int province_number, int points_number)
{
    for (int i = 0; i < points_number; i++)
    {
        if ((*polygons)[province_number][i].x0 > xmax && (*polygons)[province_number][i].x1 > xmax)
            (*polygons)[province_number][i].accepted = 0;
        
        else if ((*polygons)[province_number][i].x0 <= xmax && (*polygons)[province_number][i].x1 <= xmax)
            continue;


        else if ((*polygons)[province_number][i].accepted)
        {
            if ((*polygons)[province_number][i].x0 > xmax)
            {
                (*polygons)[province_number][i].y0 = (*polygons)[province_number][i].y0 + ((*polygons)[province_number][i].y1 - (*polygons)[province_number][i].y0) 
                                        * (xmax - (*polygons)[province_number][i].x0) / ((*polygons)[province_number][i].x1 - (*polygons)[province_number][i].x0);
		        (*polygons)[province_number][i].x0 = xmax;
            }
            else
            {
                (*polygons)[province_number][i].y1 = (*polygons)[province_number][i].y1 + ((*polygons)[province_number][i].y0 - (*polygons)[province_number][i].y1) 
                                        * (xmax - (*polygons)[province_number][i].x1) / ((*polygons)[province_number][i].x0 - (*polygons)[province_number][i].x1);
		        (*polygons)[province_number][i].x1 = xmax;
            }
            (*polygons)[province_number][i].accepted = 1;
        }
        
    }
}

void cohen_sutherland_top_edge(Line ***polygons, int province_number, int points_number)
{
    for (int i = 0; i < points_number; i++)
    {
        if ((*polygons)[province_number][i].y0 > ymax && (*polygons)[province_number][i].y1 > ymax)
            (*polygons)[province_number][i].accepted = 0;

        else if ((*polygons)[province_number][i].y0 <= ymax && (*polygons)[province_number][i].y1 <= ymax)
            continue;

        else if ((*polygons)[province_number][i].accepted)
        {
            if ((*polygons)[province_number][i].y0 > ymax)
            {
                (*polygons)[province_number][i].x0 = (*polygons)[province_number][i].x0 + ((*polygons)[province_number][i].x1 - (*polygons)[province_number][i].x0) * 
                                (ymax - (*polygons)[province_number][i].y0) / ((*polygons)[province_number][i].y1 - (*polygons)[province_number][i].y0);
		        (*polygons)[province_number][i].y0 = ymax;
            }
            else
            {
                (*polygons)[province_number][i].x1 = (*polygons)[province_number][i].x1 + ((*polygons)[province_number][i].x0 - (*polygons)[province_number][i].x1) * 
                                (ymax - (*polygons)[province_number][i].y1) / ((*polygons)[province_number][i].y0 - (*polygons)[province_number][i].y1);
		        (*polygons)[province_number][i].y1 = ymax;
            }
            (*polygons)[province_number][i].accepted = 1;
        }
    }
}

void cohen_sutherland_bottom_edge(Line ***polygons, int province_number, int points_number)
{
    for (int i = 0; i < points_number; i++)
    {
        if ((*polygons)[province_number][i].y0 < ymin && (*polygons)[province_number][i].y1 < ymin)
            (*polygons)[province_number][i].accepted = 0;

        else if ((*polygons)[province_number][i].y0 >= ymin && (*polygons)[province_number][i].y1 >= ymin)
            continue;

        else if ((*polygons)[province_number][i].accepted)
        {
            if ((*polygons)[province_number][i].y0 < ymin)
            {
                (*polygons)[province_number][i].x0 = (*polygons)[province_number][i].x0 + ((*polygons)[province_number][i].x1 - (*polygons)[province_number][i].x0) * 
                                (ymin - (*polygons)[province_number][i].y0) / ((*polygons)[province_number][i].y1 - (*polygons)[province_number][i].y0);
		        (*polygons)[province_number][i].y0 = ymin;
            }
            else
            {
                (*polygons)[province_number][i].x1 = (*polygons)[province_number][i].x1 + ((*polygons)[province_number][i].x0 - (*polygons)[province_number][i].x1) * 
                                (ymin - (*polygons)[province_number][i].y1) / ((*polygons)[province_number][i].y0 - (*polygons)[province_number][i].y1);
		        (*polygons)[province_number][i].y1 = ymin;
            }
            (*polygons)[province_number][i].accepted = 1;
        }
    }
}

