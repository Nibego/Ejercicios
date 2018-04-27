/**                                                                                    
Enunciado: "Write another program using fork() . The child process should              
print “hello”; the parent process should print “goodbye”. You should try to            
ensure that the child process always prints first; can you do this without             
calling wait() in the parent?"                                                         
                                                                                       
Author:                                                                                
Date:                                                                                  
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
  pid_t pid;
  pid = fork();

  // invoque la llamada al sistema fork()
  if (pid) {
	waitpid(pid,NULL,0);
	printf("%s\n","Goodbye");

  } else {
	printf("%s\n","Hello");
	sleep(2);
	printf("%s\n",":3");
  }
 return 0;
}