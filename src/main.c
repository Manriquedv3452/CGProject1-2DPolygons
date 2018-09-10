#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "utilities.h"
#include "scanner.c"

FILE *output;
FILE *file;

int main(int argc, char *argv[])
{
	
	
	//Start scanning process
	scanner("../points/Guanacaste.txt", GUANACASTE);


	return 1;
}
