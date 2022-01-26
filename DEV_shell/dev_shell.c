#include <stdio.h>
#include <ctype.h>

/* Get_command: get command from the user 
 * cut extra white simbols (' ', '\n', '\t')
 * returns len of gotten command
 */
int Get_command(char* command, int n);

int main()
{
}

int Get_command(char* command, int limit)
{
    
    char simbol;
    int len=0;

    while (len<limit && (simbol = getchar()) != '\n')
    {
        if (simbol == '\t')
            simbol = ' ';

        /* ignore white simbol IF
         * it's the first OR 
         * the last simbol was also white 
         */
        if ( isspace(simbol) && (len==0 || isspace(command[len-1])) ) ; 
        else {
            command[len]=simbol;
            len++;
        }
    }

    // if last simbol is space: replace it by '\0'
    if (isspace(command[len-1]))
        len--;

    command[len] = '\0';

    return len; 
}

