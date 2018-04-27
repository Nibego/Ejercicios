/*                                                                                     
Enunciado: "Write a program that opens a file (with the open() system call)            
and then calls fork() to create a new process. Can both the child and parent           
access the file descriptor returned by open()? What happens when they are              
writing to the file concurrently, i.e., a t the same time?"                            
                                                                                       
Author:                                                                                
Date:                                                                                  
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
  // Usar estas variables
  int x;
  pid_t pid;
  char *filename="code-02.txt";
  int fd;

	fd = open(filename, O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);

  x = 100;
  pid = fork();
  if (pid) {
    x+=8;
    dprintf(fd,"Soy el padre mi pid es %d \n X vale %d para mi\n", getpid(), x); 
  
  } else {
    x-=10;
    dprintf(fd,"Soy el hijo mi pid es %d \n X vale %d para mi\n", getpid(), x);

  close(fd);
}
}