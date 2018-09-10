

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
	KEYWORD = 200, OP = 201, ID = 202, CONSTANT = 203, STRING_LITERAL = 204, SEP = 205, ASSIGN = 206
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
} TokenInfo;


