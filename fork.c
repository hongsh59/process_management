#include <stdio.h>
#include <stdlib.h> // for system()
#include <unistd.h> // for execl(), fork()
#include <wait.h> // for wait()

int main(int argc, char *argv[]) {
	int pid; /* fork another process */
	pid = fork();
	if(pid < 0) { /* error occurred */
		printf("Fork Failed");
		exit(-1);
	}else if (pid== 0) { /* child process */
		printf(“I’m a child!\n");
	} else { /* parent process */
		wait(NULL);
		printf("Child Complete!\n");
		exit(0);
	}
 }
