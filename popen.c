#include <stdio.h>
#include <errno.h>   /* errno */
#include <string.h>  /* strerror */

#ifdef WIN32
#define popen _popen
#define pclose _pclose
#endif
int main(int argc, char* argv[])
{
    char  pszCommand[100] = "ping -c 10  XXX.XXX.XXX.XXX";
    FILE        *fp = NULL;
    size_t      readSize = 0;
    char        pszBuff[1024];

    // excute command
    fp = popen(pszCommand, "r");
    if( !fp)
    {
        printf("error [%d:%s]\n", errno, strerror(errno));
        return -1;
    }

    // read the result
    readSize = fread( (void*)pszBuff, sizeof(char), 1024-1, fp );
    if( readSize == 0 )
        {
            pclose(fp);
            printf("error [%d:%s]\n", errno, strerror(errno));
            return -1;
        }

        pclose(fp);
        pszBuff[readSize]=0;

        // print result
        printf("%s\n", pszBuff);
        return 0;
    }
