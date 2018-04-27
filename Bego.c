/**
Enunciado: Write a program that calls fork(). Before calling fork(), have
the main process access a variable (e.g., x) and set its value to something
(e.g., 100). What value is the variable in the child process? What happens
to the variable when both the child and parent change the value of x?
Author:
Date:
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(char argc, char* argv){
int x= 100;	
pid_t pid = fork();

	if(pid){
		x= 101;
		printf("Hola soy el padre mi pid es : %d \n X = %d\n", getpid(), x );

	}else{
		x=99;
		printf("Hola soy el hijo mi pid es : %d \n X = %d\n", getpid(), x );
	}
	return 0;
}