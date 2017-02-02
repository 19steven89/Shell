/************************************************
*Name: Steven Barry 
*Assignment: Simple Shell Exercise
*
*
*
*
*************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	/* chars used to determine values which are to be excluded using token delimiter */ 
	const char tok[9] = " \t|><&;\n";
	char str[512];
	char *token;
	int compare = 0;
	int i;
	/*char pointer array */
	char *value;

	/* create infinite loop */
	while(1)
	{
		printf(">");
		value = fgets(str, 512, stdin);
		
		if(value == NULL)
		{
			exit(0);

		}/* end if */

		/* surround string with chars to demonstrated beginning and end of words */
		printf("<%s>\n", str);
		
		
		token = strtok(str, tok);

		/* print string until NULL reached */
		while(token != NULL)
		{
			printf("<%s>\n", token);
			token = strtok(NULL, tok);
		
		}/* end while */

		compare = strcmp(str, "exit"); 

		/* exit loop if user enters "exit" */
		if(compare == 0)
		{
			exit(0);

		}/*end if*/
	
	}/*end while */
	
	return 0;

}/* end main */

