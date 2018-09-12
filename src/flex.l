%option noyywrap
%{	#include <studio.h>
	#include "structs.h"

//int lineNum = 0;
%}


/*Taken from https://www.lysator.liu.se/c/ANSI-C-grammar-l.html*/
%%
\n		{/*yylineno = ++lineNum;*/}
[ \t\v\f]	{/*DO NOTHING*/}



[0-9]*"."[0-9]+([Ee][+-]?[0-9]+)?(f|F|l|L)?","[0-9]+"."[0-9]*([Ee][+-]?[0-9]+)?(f|F|l|L)?	{ return CONSTANT; }

[0-9]+"."[0-9]*([Ee][+-]?[0-9]+)?(f|F|l|L)?","[0-9]+"."[0-9]*([Ee][+-]?[0-9]+)?(f|F|l|L)? { return CONSTANT; }
"M"[0-9]+"."[0-9]*([Ee][+-]?[0-9]+)?(f|F|l|L)?","[0-9]+"."[0-9]*([Ee][+-]?[0-9]+)?(f|F|l|L)? { }


. 			{}
%%

