#include <unistd.h> // for execl(), fork()
#include <stdio.h>
#include <errno.h>
int main(int argc, char *argv[])
{
    int ret;
    ret = execvp("nano", "nano", "/home/hong/Desktop/hook.txt", NULL);
    if(ret == -1);
                  perror("execvp");
   return 0;
}
