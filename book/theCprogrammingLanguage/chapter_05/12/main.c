/*
 * date: 2020-02-01 19:37
 * desc: entab 和 detable
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100
#define TABINC  8
#define YES     1
#define NO      0

void esettab(int argc, char *argv[], char *tab);
void entab(char *tab);

/* replace string of blanks with tabs */
int main(int argc, char *argv[])
{
    char tab[MAXLINE + 1];

    esettab(argc, argv, tab);
    entab(tab);

    return 0;
}


/* esettab: set tab stops in array tab */
void esettab(int argc, char *argv[], char *tab)
{
    int i, inc, pos;

    if (argc <= 1)      /* default tab stops */
        for (i = 1; i <= MAXLINE; i++)
            if (i % TABINC == 0)
                tab[i] = YES;
            else
                tab[i] = NO;
    else if (argc == 3 && 
            *argv[1] == '-' && *argv[2] == '+')
    {
        pos = atoi(&(*++argv)[1]);
        inc = atoi(&(*++argv)[1]);
        for (i = 1; i <= MAXLINE; i++)
            if (i != pos)
                tab[i] = NO;
            else 
            {
                tab[i] = YES;
                pos += inc;
            }
    }
    else    /* user provided tab stops */
    {
       for (i = 1; i <= MAXLINE; i++) 
           tab[i] = NO;     /* turn off all tab stops */
       while (--argc > 0)
       {
           pos = atoi(*++argv);
           if (pos > 0 && pos <= MAXLINE)
               tab[pos] = YES;
       }
    }
}



