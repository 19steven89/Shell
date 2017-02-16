/************************************************
<<<<<<< HEAD
*
*Name: Steven Barry 
=======
<<<<<<< HEAD
*
=======
*Name: Steven Barry 
>>>>>>> fd42de9f29582ce1a1d8fb82b80342a77f25d4a5
>>>>>>> c43304907eb69de325d85bc425e0556e0136e170
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
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> c43304907eb69de325d85bc425e0556e0136e170
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

<<<<<<< HEAD
=======

=======
>>>>>>> fd42de9f29582ce1a1d8fb82b80342a77f25d4a5

>>>>>>> c43304907eb69de325d85bc425e0556e0136e170
int main(int argc, char *argv[])
{
	/* chars used to determine values which are to be excluded using token delimiter */ 
	const char tok[9] = " \t|><&;\n";
	char str[512];
	char *token;
	int compare = 0;
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> c43304907eb69de325d85bc425e0556e0136e170
	/*char pointer array */
	char *value;
	char *tokArrayFilename[50];
	int i = 0;
	int l = 0;
<<<<<<< HEAD

	/*char pointer array
	char *value;*/

=======
=======
	int i;
	/*char pointer array */
	char *value;

>>>>>>> fd42de9f29582ce1a1d8fb82b80342a77f25d4a5
>>>>>>> c43304907eb69de325d85bc425e0556e0136e170
	/* create infinite loop */
	while(1)
	{
		printf(">");
		value = fgets(str, 512, stdin);
		
<<<<<<< HEAD

=======
<<<<<<< HEAD
		

=======
>>>>>>> fd42de9f29582ce1a1d8fb82b80342a77f25d4a5
>>>>>>> c43304907eb69de325d85bc425e0556e0136e170
		if(value == NULL)
		{
			exit(0);

		}/* end if */

		/* surround string with chars to demonstrated beginning and end of words */
		printf("<%s>\n", str);
		
		
		token = strtok(str, tok);

		/* print string until NULL reached */
<<<<<<< HEAD

=======
<<<<<<< HEAD
>>>>>>> c43304907eb69de325d85bc425e0556e0136e170
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

<<<<<<< HEAD

=======
=======
>>>>>>> c43304907eb69de325d85bc425e0556e0136e170
		while(token != NULL)
		{
			printf("<%s>\n", token);
			token = strtok(NULL, tok);
		
		}/* end while */
<<<<<<< HEAD

=======
>>>>>>> fd42de9f29582ce1a1d8fb82b80342a77f25d4a5
>>>>>>> c43304907eb69de325d85bc425e0556e0136e170

		compare = strcmp(str, "exit"); 

		/* exit loop if user enters "exit" */
		if(compare == 0)
		{
			exit(0);

		}/*end if*/
	
	}/*end while */
	
	return 0;

}/* end main */

