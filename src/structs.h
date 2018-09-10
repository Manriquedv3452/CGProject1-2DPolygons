typedef struct {
  double r;
  double g;
  double b;
} COLOR;


typedef struct line{
	double x0;
	double y0;

	double x1;
	double y1;
} Line;

typedef enum token_types
{
	CONSTANT = 203
} TokenType;

typedef enum province_number
{
	SANJOSE = 1, ALAJUELA = 2, CARTAGO = 3, HEREDIA = 4, GUANACASTE = 5, PUNTARENAS = 6, LIMON = 7, PUNTARENAS2 = 8
} ProvinceNum;

typedef struct token
{
	int tokenCode;
	char* lexeme;
	int lineNumber;
	int token_length;
} TokenInfo;


