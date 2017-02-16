/************************************************
*
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
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

/* function declarations */
int forkProcess();



int forkProcess()
{
	pid_t pid, pid1;

	pid = fork();

	if(pid < 0)
	{
		fprintf(stderr, "Fork failed in execution");

	}/* end if */
	else if(pid == 0)
	{
		
		pid1 = getpid();
		/*process A */
		printf("Child process PID A: %d", pid);
		
		/*process B */
		printf("Child process PID1 B: %d", pid1);

		int execvp(const char *file, char /* fill rest of memory to default value */
	
	/* end while */*const argv[]);
		
	}/* end else if */
	else
	{
		pid1 = getpid();

		/*process C */
		printf("Parent process PID C: %d", pid);
		
		/*process D*/
		printf("Parent process PID1 D: %d", pid1);
	
		/* wait used for a change in child process */
		wait(NULL);
		
	}/* end else */

	return 0;


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

	/*char pointer array
	char *value;*/

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

		while(token != NULL && i <= 50)
		{
			printf("<%s>\n", token);

			tokArrayFilename[i] = strdup(token);

			token = strtok(NULL, tok);
			i++;
			
		
		}/* end while */
		
		tokArrayFilename[i] = NULL;
	
		/*strcpy(tokArrayFilename[i], NULL);*/
		i = 0;

		while(l < 50 && tokArrayFilename[l] != NULL)
		{
			printf("%d:%s ", l, tokArrayFilename[l]);
			l++;
			printf("\n");

		}/* end while */

		l = 0;


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

