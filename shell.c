/************************************************
*Name: Steven Barry 
*Assignment: Simple Shell Exercise
*
*
*
*
*************************************************
*/

/* library files required for program execution */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <limits.h>

/* function declarations */
void savePath(char *str, char const* storePath);
void chdirToHome();
void forkProcess(char* arguement, char* paramaters[]);
void changeHomeDir(char *str);
void setPathDir(char *setP);
void changeDirectory(char *str);


void savePath(char *str, char const* storePath)
{
	if(storePath == NULL)
	{
		printf("\nError! Path Not Found");

	}/* end if */
	else
	{
	   	printf("\nPath directories where exe files are located: %s\n", storePath);
	}/* end else */

}/* end method */


void chdirToHome()
{
	char cwd[300];

 	  if (chdir(getenv("HOME")) != 0)
	  {
		     perror("\nChdir() Error occured, please recheck home directory has been altered correctly.");
	  }/* end outer if */
	  else 
	  {
		    if (getcwd(cwd, sizeof(cwd)) == NULL)
		     {	
			perror("\ngetcwd() Error, cwd size is null, recheck working home directory");
		    
		     }/* end if*/	
		     else
		     {
	      		printf("\ncurrent working directory is: %s\n", cwd);

		     }/* end else*/

	   }/* end outer else */

}/* end function */



void changeHomeDir(char *str)
{
	char *setP;

	int compare = 0;

	setP = fgets(str, 512, stdin);

	if(strcmp(setP, "\0") == 0)
	{
		printf("\nError occured, please specify path name.\n");

	}/* end if*/
	else
	{
		setPathDir(setP);
	}/* end else */

}/* end method */


void setPathDir(char *setP)
{
	setenv("PATH", setP, 0);

	char *currPath = getenv("PATH");
	printf("currPath: %s\n", currPath);
	
}/* end function */

void forkProcess(char* argument, char* paramaters[])
{
	
	pid_t pid = fork();

	/*child process*/
	if (pid == 0) {
		printf("Child: %d\n", pid);
		if (execvp(argument,paramaters) == -1 )
		{
			perror (argument);
		}/* end inner if */

		exit(0);
	}/* end if */

	/*parent process*/
	if (pid > 0) 
	{
		wait(0);
		printf("Parent: %d\n", pid);
	}/* end if */

}/* end function */



void changeDirectory(char *str)
{
	printf("**TEST** now in changeDirectory function, %s", str);
	

	/*if(str[1] == 0)*/



}/* end function */


int main(int argc, char *argv[])
{
	/* chars used to determine values which are to be excluded using token delimiter */ 
	const char tok[9] = " \t|><&;\n";
	char str[512];
	char *token;
	int compare = 0;
	/*char pointer array */
	char *value;
	char *tokArrayFilename[50];
	int i = 0;
	int l = 0;
	/* var stores the original path and will restore to original on program exit */
	char const* storePath = getenv("PATH");


	savePath(str, storePath);
	chdirToHome();

	/* create infinite loop */
	while(1)
	{
		printf("\n>");
		value = fgets(str, 512, stdin);
		

		if(value == NULL)
		{
			exit(0);

		}/* end if */

		/* surround string with chars to demonstrate beginning and end of words */
		
		printf("<%s>\n", str);
		
		token = strtok(str, tok);

		/* print string until NULL reached */

		while(token != NULL && i <= 50)
		{
			printf("<%s>\n", token);

			tokArrayFilename[i] = strdup(token);

			token = strtok(NULL, tok);
			i++;
				
		}/* end while */

		tokArrayFilename[i] = NULL;

		/* if user enters NULL value, ensure program continues */
		if(tokArrayFilename[0] == NULL)
		{
			continue;
		}/* end if*/

		i = 0;

		while(token != NULL)
		{
			printf("<%s>\n", token);
			token = strtok(NULL, tok);
		
		}/* end while */

		compare = strcmp(tokArrayFilename[0], "exit"); 

		/* exit loop if user enters "exit" */
		if(strcmp(tokArrayFilename[0], "exit") == 0)
		{
			if(tokArrayFilename[1] == NULL)
			{
				setenv(storePath, "PATH", 0);
				printf("The current path is: %s\n", storePath);

				exit(0);
			}/* end if */

			printf("%s is not a valid command\n", tokArrayFilename[1]);

		}/*end if*/

		else if(strcmp(tokArrayFilename[0], "getpath") == 0)
		{
				printf("\nelse if: getpath\n");
				savePath(tokArrayFilename[1], storePath);
		}/* end else if */
		else if(strcmp(tokArrayFilename[0], "setpath") == 0)
		{
				printf("\nelse if: setpath\n");
				changeHomeDir(tokArrayFilename[1]);
		}/* end else if*/
		else if(strcmp(tokArrayFilename[0], "cd") == 0)
		{
				printf("\nelse if: cd\n");
				changeDirectory(tokArrayFilename[1]);
		}/* end else if*/
		else
		{
			forkProcess(tokArrayFilename[0],tokArrayFilename);
		}/*end else*/

	}/*end while */


	setenv(storePath, "PATH", 0);
	printf("The current path is: %s", storePath);
	
	return 0;

}/* end main */

