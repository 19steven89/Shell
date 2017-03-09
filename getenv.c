#include <stdio.h>
#include <stdlib.h>

int main ()
{
   printf("PATH : %s\n", getenv("PATH"));
   printf("HOME : %s\n", getenv("HOME"));
   printf("ROOT : %s\n", getenv("ROOT"));



	char const* storePath= getenv( "PATH" );
	if(storePath == NULL)
	{
		printf("Error! Path Not Found");
	}/* end if */
	else
	{
	   	printf("storePath: %s\n", storePath);
	}/* end else */

   return(0);
}	
