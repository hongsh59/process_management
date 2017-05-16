#include <unistd.h> // for execl(), fork()
#include <stdio.h>

int main( )
{
    execlp( "ls", "ls", "-al " , "/boot " , NULL);

}
