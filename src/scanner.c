#include "getToken.c"

int scanner(char* fileName, int province_number, Line ***polygons, Province **province);
void process_token(int province_number, Line ***polygons, int points_number, int current_line);
double get_y_value(TokenInfo token);
double get_x_value(TokenInfo token);

char* tokenType;
FILE *errors;
TokenInfo tokenID;

int scanner(char* fileName, int province_number, Line ***polygons, Province **province)
{
	yyin = fopen(fileName, "r");
	if (yyin == NULL)
	{
		printf("%s NOT FOUND!\n", fileName);
		return 0;
	}
	
	//Token *current = NULL;
	int newLine = 0;
	tokenID = getToken();
	tokenID = getToken();
	double x0, y0, x1, y1;
	int current_line = 0;

	while (tokenID.tokenCode)	//loop while nextToken() != 0 (null)
	{ 
		if (tokenID.tokenCode == CONSTANT)
		{
			x0 = get_x_value(tokenID);
			y0 = get_y_value(tokenID);				//start line
			(*polygons)[province_number][current_line].x0 = x0;
			(*polygons)[province_number][current_line].y0 = y0;

			tokenID = getToken();
						
			x1 = get_x_value(tokenID);
			y1 = get_y_value(tokenID);
			(*polygons)[province_number][current_line].x1 = x1;		//end line
			(*polygons)[province_number][current_line].y1 = y1;

			(*province)[province_number].sum_x0 += x0;

			(*province)[province_number].sum_y0 += y0;
			(*province)[province_number].sum_x1 += x1;
			(*province)[province_number].sum_y1 += y1;	

			tokenID = getToken(); //ignore third column
			tokenID = getToken(); //start next line

			(*polygons)[province_number][current_line].accepted = 1;
			current_line++;
		}

		//printf("%d\n", current_line);
	}	
	return 1;

}

double get_x_value(TokenInfo token)
{
	double x;
	char *current_double = calloc(token.token_length, sizeof(char));
	for (int i = 0; i < token.token_length; i++)
	{
		if (token.lexeme[i] == ',')
		{	
			x = atof(current_double);

			break;
		}
		current_double[i] = token.lexeme[i];
	}
	free(current_double);
	return x;
}

double get_y_value(TokenInfo token)
{
	double y;
	int second_value = 0;

	int double_pos = 0;

	char *current_double = calloc(token.token_length, sizeof(char));
	for (int i = 0; i < token.token_length; i++)
	{
		if (second_value == 1)
		{
			current_double[double_pos++] = token.lexeme[i];
		}
		if (token.lexeme[i] == ',')
		{	
			second_value = 1;
		}
	}
	y = atof(current_double);
	free(current_double);
	return y;
}