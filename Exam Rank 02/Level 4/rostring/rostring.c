#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    int start, end, fl = 0;

    if(ac > 1)
    {
        while(av[1][i] == ' ')
            i++;
        start = i;
        while((av[1][i] != ' ') && av[1][i])
            i++;
        end = i;
        while(av[1][i] == ' ')
            i++;
        while(av[1][i])
        {
            while(av[1][i] == ' ')
            {
                i++;
                fl = 1;
            }
            if(fl)
                write (1, " ", 1);
            write (1, &av[1][i], 1);
            i++;
            fl = 0;
            if(av[1][i] == '\0')
                write (1, " ", 1);
        }
        while(start < end)
            write (1, &av[1][start++], 1);
    }
    write(1, "\n", 1);
}