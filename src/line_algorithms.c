void plot(int x, int y);
void brute_force_algorithm(long double x0, long double y0, long double x1, long double y1);
void incremental_algorithm(long double x0, long double y0, long double x1, long double y1);
void incremental_algorithm_v2(long double x0, long double y0, long double x1, long double y1);
void bresenham_algorithm (int x0, int y0, int x1, int y1);

void plot(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void brute_force_algorithm(long double x0, long double y0, long double x1, long double y1){
    long double m, b, y;
    int i;

    double difference_y = y1 - y0;
    double difference_x = x1 - x0;
    double difference_y1 = y0 - y1;
    double difference_x1 = x0 - x1;

    if (x0 > x1)
    {
        if (difference_y < difference_x1)
        {
            long double x_aux = x0;
            long double y_aux = y0;

            x0 = x1;
            y0 = y1;

            x1 = x_aux;
            y1 = y_aux;

            difference_y = y1 - y0;
            difference_x = difference_x1;
        }
    }
    else if (y0 > y1)
    {
        if (difference_x < difference_y1)
        {
            long double x_aux = x0;
            long double y_aux = y0;

            x0 = x1;
            y0 = y1;

            x1 = x_aux;
            y1 = y_aux;

            difference_y = difference_y1;
            difference_x = x1 - x0;
        }
    }

    if (difference_y < difference_x)
    {

        m = difference_y / difference_x;
        b = y0 - m * x0;

        for (i = x0; i <= x1; i++){
            y = m * i + b;
            plot(i, round(y));
        }
    }
    else
    {
        m = difference_x / difference_y;
        b = x0 - m * y0;

        for (i = y0; i <= y1; i++){
            y = m * i + b;
            plot(round(y), i);
        }
    }
}

void incremental_algorithm(long double x0, long double y0, long double x1, long double y1){
    long double m, y;
    int i;

    //double difference_x, difference_y;

    double difference_y = y1 - y0;
    double difference_x = x1 - x0;
    double difference_y1 = y0 - y1;
    double difference_x1 = x0 - x1;

    if (x0 > x1)
    {
        if (difference_y < difference_x1)
        {
            long double x_aux = x0;
            long double y_aux = y0;

            x0 = x1;
            y0 = y1;

            x1 = x_aux;
            y1 = y_aux;

            difference_y = y1 - y0;
            difference_x = difference_x1;
        }
    }
    else if (y0 > y1)
    {
        if (difference_x < difference_y1)
        {
            long double x_aux = x0;
            long double y_aux = y0;

            x0 = x1;
            y0 = y1;

            x1 = x_aux;
            y1 = y_aux;

            difference_y = difference_y1;
            difference_x = x1 - x0;
        }
    }

    if (difference_y < difference_x)
    {
        m = difference_y / difference_x;
        y = y0;

        for (i = x0; i <= x1; i++){
            plot(i, round(y));
            y += m;
        }
    }
    else
    {
        m = difference_x / difference_y;
        y = x0;

        for (int i = y0; i <= y1; i++)
        {
            plot(round(y), i);
            y += m;
        }
    }
}

void incremental_algorithm_v2(long double x0, long double y0, long double x1, long double y1){
    long double x, y, step_x, step_y;
    int i, width;

    width = max(fabs(x1 - x0), fabs(y1 - y0));
    step_x = (x1 - x0) / width;
    step_y = (y1 - y0) / width;
    x = x0; y = y0;

    for (i = 0; i <= width; i++){
        plot(round(x), round(y));
        x += step_x;
        y += step_y;
    }
}

void bresenham_algorithm (int x0, int y0, int x1, int y1){
    int Delta_E, Delta_NE, Delta_N, Delta_NO_tercer, Delta_NO_cuarto, Delta_O_cuarto, Delta_O_quinto, Delta_SO, Delta_S, Delta_SE;
    int d1, d2, d3, d4, d5, d6, d7, d8, dx, dy;
    int xp, yp;

    //printf("(%d, %d), (%d, %d)\n", x0, y0, x1, y1);
	
    if (x0 > x1)
    {
        int aux_x = x0;
        int aux_y = y0;

        x0 = x1;
        y0 = y1;

        x1 = aux_x;
        y1 = aux_y;
    }

    dx = x1-x0;
    dy = y1-y0;

    Delta_E = 2 * dy; //primer y octavo ctante
    Delta_NE = 2 * (dy - dx);
    Delta_N = -2 * dx; //segundo y tercer octante
    Delta_NO_tercer = -2 * dy; //tercer octante
    Delta_NO_cuarto = -2 * (dy + dx); //cuarto octante
    Delta_O_cuarto = -2 * (dy + dx); //cuarto octante
    Delta_O_quinto = -2 * dy; //quinto octante
    Delta_SO = -2 * dy + 2 * dx; //quinto y sexto octante
    Delta_S = 2 * dx; //sexto y setimo octante
    Delta_SE = 2 * (dy + dx); //setimo y octavo octante

    xp = x0;
    yp = y0;
    plot (xp, yp);
    //printf("(%d, %d)\t", xp, yp);

    d1 = 2 * dy - dx;
    d2 = dy - 2 * dx;
    d3 = -dy - 2 * dx;
    d4 = -2 * dy - dx;
    d5 = -2 * dy + dx;
    d6 = -dy + 2 * dx;
    d7 = dy + 2 * dx;
    d8 = 2 * dy + dx;


    dx = abs(dx);
    dy = abs(dy);

    if ((dx >= dy) && (x0 < x1) && (y0 <= y1)) {
      //primer octante
      //printf("primer octante\n");
      while (xp < x1){
          if(d1 <= 0){ //dibujo al este
              xp++;
              d1 += Delta_E;
          }
          else{ //dibujo al NE
              xp++;
              yp++;
              d1 += Delta_NE;
          }
          plot(xp, yp);
      }
    }
    else if ((dx <= dy) && (x0 <= x1) && (y0 < y1)) {
      //segundo octante
      //printf("segundo octante\n");
      while (yp < y1){
          if(d2 > 0){ //dibujo al norte
              yp++;
              d2 += Delta_N;
          }
          else{ //dibujo al NE
              xp++;
              yp++;
              d2 += Delta_NE;
          }
          plot(xp, yp);
      }
    }
    else if ((dx >= dy) && (x0 < x1) && (y0 > y1)){
      //octavo octante
      //printf("octavo octante\n");
      while (xp < x1){
          if(d8 > 0){ //dibujo al este
              xp++;
              d8 += Delta_E;
          }
          else{ //dibujo al SE
              xp++;
              yp--;
              d8 += Delta_SE;
          }
          plot(xp, yp);
      }
    }
    else if ((dx <= dy) && x0 <= x1 && y0 > y1) {
      //sétimo octante
      //printf("setimo octante\n");
      while (yp > y1){
          if(d7 <= 0){ //dibujo al sur
              yp--;
              d7 += Delta_S;
          }
          else{ //dibujo al SE
              xp++;
              yp--;
              d7 += Delta_SE;
          }
          plot(xp, yp);
      }
    }
    else if ((dx <= dy) && x0 > x1 && y0 < y1) {
      //tercer octante
      //printf("tercer octante\n");
      while (yp < y1){
          if(d3 >= 0){ //dibujo al norte
              yp++;
              d3 += Delta_N;
          }
          else{ //dibujo al NO
              xp--;
              yp++;
              d3 += Delta_NO_tercer;
          }
          plot(xp, yp);
      }
    }
    else if ((dx >= dy) && x0 > x1 && y0 <= y1) {
      //cuarto octante
      //printf("cuarto octante\n");
      while (xp > x1){
          if(d4 <= 0){ //dibujo al oeste
              xp--;
              d4 += Delta_O_cuarto;
          }
          else{ //dibujo al NO
              xp--;
              yp++;
              d4 += Delta_NO_cuarto;
          }
          plot(xp, yp);
      }
    }
    else if ((dx >= dy) && x0 > x1 && y0 > y1) {
      //quinto octante
      //printf("quinto octante\n");
      while (xp > x1){
          if(d5 > 0){ //dibujo al oeste
              xp--;
              d5 += Delta_O_quinto;
          }
          else{ //dibujo al SO
              xp--;
              yp--;
              d5 += Delta_SO;
          }
          plot(xp, yp);
      }
    }
    else if ((dx <= dy) && x0 > x1 && y0 > y1) {
      //sexto octante
      //printf("sexto octante\n");
      while (yp > x1){
          if(d6 <= 0){ //dibujo al sur
              yp--;
              d6 += Delta_S;
          }
          else{ //dibujo al SO
              xp--;
              yp--;
              d6 += Delta_SO;
          }
          plot(xp, yp);
      }
    } else{
      //printf("error a la hora de graficar\n");
	//printf("ERROR (%d, %d), (%d, %d)\n", x0, y0, x1, y1);
    }
}
