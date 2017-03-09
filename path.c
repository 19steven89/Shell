

#include <stdio.h>
#include <stdlib.h>
int main()
{
printf("test\n");
const char* s = getenv("PATH");
printf("PATH :%s\n",(s!=NULL)? s : "getenv returned NULL");


const char* t = getenv("\n\nHOME");
printf("\n\nHOME :%s\n",(s!=NULL)? s : "getenv returned NULL");

printf("\n");
}

