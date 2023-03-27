#include <unistd.h>

int main(int argc, char **argv)
{
	int start;
	int end;
	int i = 0;
		
	if(argc == 2)
	{   
		while(argv[1][i] != '\0')
			i++;
		while(i >= 0)
		{
			while( argv[1][i] == '\0' || argv[1][i] == ' ' || argv[1][i] == '\t')
				i--;
			end = i;
			while(argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
				i--;
			start = i + 1;
			int  flag;
			flag = start;
			while(start <= end)
			{
				write (1, &argv[1][start],1);
				start++;		
			}
			if (flag !=0)
			{
				write(1, " ", 1);
			}
		}
	}
	write(1, "\n", 1);
}

/*
#include <unistd.h>

void rev_wstr(char *s)
{
    int i = 0, j = 0;
    while (s[j])
        j++;
    j--;
    while (j >= 0)
    {
        while (j >= 0 && s[j] == ' ')
            j--;
        i = j;
        while (i >= 0 && s[i] != ' ')
            i--;
        write(1, s + i + 1, j - i);
        if (i > 0)
            write(1, " ", 1);
        j = i;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
        rev_wstr(av[1]);
    write(1, "\n", 1);
    return 0;
}
*/
