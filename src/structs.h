#define PLACES_NUMBER 8

#define SANJOSE_POINTS 298
#define ALAJUELA_POINTS 463
#define CARTAGO_POINTS 131
#define HEREDIA_POINTS 145
#define GUANACASTE_POINTS 472
#define PUNTARENAS_POINTS 545
#define PUNTARENAS2_POINTS 131
#define LIMON_POINTS 250


typedef struct province {
	int points_quantity;
	double sum_x0;
	double sum_y0;
	double sum_x1;
	double sum_y1;
} Province;

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

	int accepted;
} Line;

typedef enum token_types
{
	CONSTANT = 203
} TokenType;

typedef enum province_number
{
	SANJOSE = 0, ALAJUELA = 1, CARTAGO = 2, HEREDIA = 3, GUANACASTE = 4, PUNTARENAS = 5, LIMON = 6, PUNTARENAS2 = 7
} ProvinceNum;

#define ACTIONS 6
typedef enum action_number
{
	I_KEY = 0, O_KEY = 1, R_KEY = 2, C_KEY = 3, P_KEY = 4, D_KEY = 5
} ActionNum;

typedef struct token
{
	int tokenCode;
	char* lexeme;
	int lineNumber;
	int token_length;
} TokenInfo;




