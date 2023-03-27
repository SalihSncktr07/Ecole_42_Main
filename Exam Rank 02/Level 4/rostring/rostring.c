#include <unistd.h>

#include <stdio.h>
int main(int ac, char **av)
{
    int i = 0;
    int start, end, fl = 0;

    if(ac > 1)
    {
        while(av[1][i] == ' ')
            i++;
        start = i;
        while(av[1][i] && av[1][i] != ' ')
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
            write (1, &av[1][i++], 1);
            fl = 0;
        }
        if(av[1][i] == '\0')
            write (1, " ", 1);
        while(start < end)
            write(1, &av[1][start++], 1);
    }
    write (1, "\n", 1);
}

// #include <unistd.h>

// int main(int argc, char **argv)
// {
// 	int i = 0;
// 	int start;
// 	int end;
// 	int flag = 0;
	
// 	if (argc > 1)
// 	{
// 		while(argv[1][i] == ' ' || argv[1][i] == '\t')
// 			i++;
// 		start = i;
// 		while(argv[1][i] && (argv[1][i] != ' ' &&  argv[1][i] != '\t'))
// 			i++;
// 		end = i;
// 		while(argv[1][i] == ' ' || argv[1][i] == '\t')
// 			i++;
// 		while(argv[1][i] != '\0')
// 		{
// 			flag = 1;
// 			write (1, &argv[1][i], 1);
// 			i++;				
// 		}
// 		if (flag == 1)
// 		{
// 			write (1, " ", 1);
// 		}
// 		while(start < end)
// 		{
// 			write (1, &argv[1][start], 1);
// 			start++;
// 		}
// 	}	
// 	write (1, "\n",1);	
// }
