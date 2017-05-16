#include <unistd.h> // for execl(), fork()
#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("before executing ls -l\n");
	execl("/bin/ls", "ls", "-l", (char *)0);
	printf("after executing ls -l\n"); /* exec 호출이 성공하면 실행되지 않는다*/
	return 0;
}
