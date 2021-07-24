#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TokenRow 50
#define TokenCol 10

int acc, tokenLen, acc1,acc2;
char input[100];
char tokens[TokenRow][TokenCol];

void init()
{
    acc = 0;
}

void resetToken()
{
    int i, j;

    for(i=0; i<TokenRow; i++)
    {
        for(j = 0; j<TokenCol; j++)
        {
            tokens[i][j] = '\0';
        }
    }
}

void takeInput()
{

    FILE *infile;


    infile = fopen("input.txt", "r");

    int i, r = 0, c=0;

    char test[10];

    while(1)
    {

        fgets(test,10, infile);

        if(!strcmp(test, "END"))
        {
            break;
        }

        //puts(test);


        c = 0;

        for(i=0; i<strlen(test); i++)           //Tokens structure
        {
            if(test[i] == ' ')                  //[L][D][-][5]
            {
                tokens[r][c++] = '-';           //[A][D][D][-][5]
                continue;
            }

            tokens[r][c++] = test[i];
        }

        r++;

    }
    tokenLen = r;

    printf("Opcodes and Operand: \n");

    for(i=0; i<tokenLen; i++)
    {
        puts(tokens[i]);
    }

}


void parseCommand()
{

    int i, x;

    for(i=0; i<tokenLen; i++)
    {
        if(tokens[i][0] == 'A' && tokens[i][1] == 'D')
        {

            x = (int)(tokens[i][4]) - 48;
            acc += x;
        }
        else if(tokens[i][0] == 'S' && tokens[i][1] == 'U')
        {
            x = (int)(tokens[i][4]) - 48;
            acc -= x;
        }
        else if(tokens[i][0] == 'M' && tokens[i][1] == 'U')
        {
            x = (int)(tokens[i][4]) - 48;
            acc *= x;
        }
        else if(tokens[i][0] == 'D' && tokens[i][1] == 'I')
        {
            x = (int)(tokens[i][4]) - 48;
            acc /= x;
        }
        else if(tokens[i][0] == 'N' && tokens[i][1] == 'O')
        {
            acc = ~acc;
        }
        else if(tokens[i][0] == 'O' && tokens[i][1] == 'R')
        {
            x = (int)(tokens[i][3]) - 48;
            acc = acc | x;
        }


        else if(tokens[i][0] == 'L' && tokens[i][1] == 'D')
        {
            acc1 = (int)(tokens[i][3])- 48;


            acc2 = (int)(tokens[i][4])- 48;
            acc    = (acc1*10)+acc2;
        }
    }

    printf("ACC: %d", acc);

    exit(0);


    printf("\n\n");
}


int main()
{

    init();
    resetToken();
    takeInput();
    parseCommand();

    return 0;
}

