/************************************************
*Name: Steven Barry Daniel Kashani
*Assignment: Simple Shell Exercise
*
*
*
*
*************************************************
*/


/* Task 5 almost complete, have to implement printing history list and also executing last command */

/* library files required for program execution */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <limits.h>
#define HISTORYLIMIT 20

struct historyCycle
{
	int cmdId;
	char *strCommand;		
};

struct historyCycle history[HISTORYLIMIT];
int count = 0;
int historyIndex = 0;

/* function declarations */
void printPath();
void chdirToHome();
void forkProcess(char* arguement, char* paramaters[]);
void changeHomeDir(char *str);
void setPathDir(char *setP);
void changeDirectory(char *str);
void executeCommand(char *tokArrayFilename[], char const* storePath);
int tokens (char *tokArrayFilename[], char str[]);

void printPath()
{
	if(getenv("PATH") == NULL)
	{
		printf("\nError! Path Not Found");

	}/* end if */
	else
	{
	   	printf("\nPath directories where exe files are located: %s\n", getenv("PATH"));
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



void changeHomeDir(char* str)
{
	int compare = 0;

	if(strcmp(str, "\0") == 0)
	{
		printf("\nError occured, please specify path name.\n");

	}/* end if*/
	else
	{
		setPathDir(str);
	}/* end else */

}/* end method */


void setPathDir(char* setP)
{
	setenv("PATH", setP, 1);

	printf("currPath: %s\n", getenv("PATH"));
	
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
	char cwd[300];
	if(str == NULL)
	{
		chdir(getenv("HOME"));
	}/* end if */
	else if(chdir(str) < 0)
	{	
		perror(str);
	}/* end if */ 
	else
	{
		printf("\ncurrent working directory is: %s\n", getcwd(cwd, sizeof(cwd)));
	}/* end else */

}/* end function */

void exitProgram(char const* storePath)
{
	setenv("PATH", storePath, 1);
	printf("The current path is: %s\n", getenv("PATH"));
	exit(0);

}/* end function */


void addHistoryCommand(char *historyInput)
{
	if(history[historyIndex].strCommand != NULL)
	{
		free(history[historyIndex].strCommand);
	}/* end if*/

	history[historyIndex].strCommand = strdup(historyInput);
	history[historyIndex].cmdId = count;
	historyIndex = (historyIndex + 1) % 20;
	count ++;


}/* end function */

char* searchHistory(int commandIdInput)
{

	for(int i = 0; i < HISTORYLIMIT; i++)
	{
		if(history[i].cmdId == commandIdInput)
		{
			return history[i].strCommand;
		}/* end if */

	}/* end for */
	//printf("History Not found");
	return NULL;


}/* end function*/


int historyCommands()
{
	int i , k;

	printf("\n");

	for(i = historyIndex; i < HISTORYLIMIT; i++)
	{
		if(history[i].strCommand)
		{
			printf("%d %s \n",history[i].cmdId, history[i].strCommand);
		}/* end if */

	}/* end for */	
	
	for(k = 0; k < historyIndex; k++)
	{
		if(history[k].strCommand)
		{
			printf("%d %s \n", history[k].cmdId, history[k].strCommand);
		}/* end if */


	}/* end for */

	return 1;

}/* end function */



void executeCommand(char *tokArrayFilename[], char const* storePath)
{
	
	int compare = 0;

	compare = strcmp(tokArrayFilename[0], "exit"); 

		/* exit loop if user enters "exit" */
		if(strcmp(tokArrayFilename[0], "exit") == 0)
		{
			if(tokArrayFilename[1] == NULL)
			{
				exitProgram(storePath);
			}/* end if */

			printf("%s is not a valid command\n", tokArrayFilename[1]);

		}/*end if*/

		else if(strcmp(tokArrayFilename[0], "getpath") == 0)
		{
			if(tokArrayFilename[1] == NULL)
			{
				printPath();
			}/*end if */
			else 
			{
				printf("Error: This command takes no arguements\n");
			}/*end else */
		}/* end else if */
		else if(strcmp(tokArrayFilename[0], "setpath") == 0)
		{
			if(tokArrayFilename[1] != NULL && tokArrayFilename[2] == NULL)
			{
				changeHomeDir(tokArrayFilename[1]);
			}/*end if */
			else 
			{
				printf("Error: This command takes one arguement\n");
			}/*end else */
		}/* end else if*/
		else if(strcmp(tokArrayFilename[0], "cd") == 0)
		{
			if(tokArrayFilename[1] != NULL && tokArrayFilename[2] == NULL || tokArrayFilename[1] == NULL)
			{
				changeDirectory(tokArrayFilename[1]);
			}/*end if */
			else
			{
				printf("Error: This command takes one arguement\n");
			}/*end else */
		}/* end else if*/
		else if(strcmp(tokArrayFilename[0], "history") == 0)
		{
			if(tokArrayFilename[1] == NULL)
			{
				historyCommands();
			}/*end if */
			
		}/* end else if */
		else
		{
			forkProcess(tokArrayFilename[0],tokArrayFilename);
		}/*end else*/

}/* end function */

int tokens (char *tokArrayFilename[], char str[])
{
	char *token;
	const char tok[9] = " \t|><&;\n";
	int i = 0;

	 

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
			return -1;
		}/* end if*/

		i = 0;

		while(token != NULL)
		{
			printf("<%s>\n", token);
			token = strtok(NULL, tok);
					
		}/* end while */

		return 0;
}

int main(int argc, char *argv[])
{

	
	char str[512];
	char strTemp[512];
	/* var stores the original path and will restore to original on program exit */
	char const* storePath = getenv("PATH");
	/*char pointer array */
	char *value;
	char *tokArrayFilename[50];
	int i = 0;
	int l = 0;


	printPath();
	chdirToHome();

	/* create infinite loop */
	while(1)
	{
		printf("\n>");
		value = fgets(str, 512, stdin);
		

		if(value == NULL)
		{
			exitProgram(storePath);

		}/* end if */

		strcpy(strTemp, str);

		if(tokens(tokArrayFilename, str) < 0)
		{
			continue;
		
		}/* end if */

		

		/* if first char = ! execute if */
		if(tokArrayFilename[0][0] == '!')
		{
			if(tokArrayFilename[0][1] == '!')
			{
				char* storeHistory = searchHistory(count-1);	
				
		
				if(storeHistory == NULL)
				{
					printf("error, history not found");
				}/* end if */
				else
				{
					printf("found history %s\n", storeHistory);
					
					if(tokens(tokArrayFilename, storeHistory) < 0)
					{
						continue;

					}/* end if */
				
					executeCommand(tokArrayFilename,storePath);

				}/* end else */


			}/* end if */

			else if(tokArrayFilename[0][1] != '!')
			{	
				int i = atoi(&tokArrayFilename[0][1]);
				if(i < 0)
				{
					i = count + i;
				}
				char* storeHistory = searchHistory(i);
				
				if(storeHistory == NULL)
				{
					printf("error, history not found");
				}/* end if */
				else
				{
					printf("found history %s\n", storeHistory);
					
					if(tokens(tokArrayFilename, storeHistory) < 0)
					{
						continue;

					}/* end if */
				
					executeCommand(tokArrayFilename,storePath);

				}/* end else */
				 
			}/* end else if */
			
		}/* end if */
		else
		{
			/* add command to history */ 
			addHistoryCommand(strTemp);
			executeCommand(tokArrayFilename,storePath);

		}/* end else */
		


	}/*end while */

	return 0;

}/* end main */
