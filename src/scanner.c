
#include "getToken.c"

//void append(TokenType type);
//void lookup(int tokenID);
int scanner(char* fileName, int province_number);


//Token *head = NULL;
char* tokenType;
FILE *errors;
int scanner(char* fileName, int province_number)
{
	yyin = fopen(fileName, "r");
	if (yyin == NULL)
	{
		printf("%s NOT FOUND!\n", fileName);
		return 0;
	}
	
	TokenInfo tokenID;
	//Token *current = NULL;
	int newLine = 0;
	tokenID = getToken();
	double x;
	
	while (tokenID.tokenCode)	//loop while nextToken() != 0 (null)
	{ 
		
		//if (tokenID.tokenCode != 1000)
		//	lookup(tokenID.tokenCode);
		//x = atof(tokenID.lexeme);
		printf("%s\n", tokenID.lexeme);
		tokenID = getToken();
					
	}

	return 1;

}

/*void lookup(int tokenID)
{
	int inside = 0;
	if (tokenID == ',' || tokenID == '.' || tokenID == ';' || tokenID == '{' || tokenID == '}' ||
			tokenID == ':' || tokenID == '(' || tokenID == ')' || tokenID == '[' || tokenID == ']')
		tokenID = SEP;
	else if (tokenID == '=')
		tokenID = ASSIGN;

	Token *current = head;
	while(current -> next != NULL)
	{
		if (current -> next -> tokenCode == tokenID)
		{
			current -> next -> count += 1;
			inside = 1;
			break;
		}
		current = current -> next;
	}
	if (inside != 1)
		append(tokenID);
}*/

/*void append(TokenType type)
{
	Token *current = head;

	while(current -> next != NULL)
	{
		current = current -> next;
	}

	current -> next = malloc(sizeof(Token));

	current -> next -> tokenCode = type;
	current -> next -> count = 1;
	current->next->next = NULL; 
	
}	*/
