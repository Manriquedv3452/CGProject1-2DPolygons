//#include "structs.h"

//FLEX LIBRARY
extern int yylex();
extern int yylineno;
extern char* yytext;
extern int yyleng;
extern char* strdup(char*);
extern FILE* yyin;


TokenInfo getToken(void);

//FUNCTION RETURNS THE NEXT TOKEN.
TokenInfo getToken(void)
{	
	TokenInfo data;
	data.tokenCode = yylex();
	data.lexeme = strdup(yytext);
	data.lineNumber = yylineno;
	data.token_length = yyleng;

	return data;
}

