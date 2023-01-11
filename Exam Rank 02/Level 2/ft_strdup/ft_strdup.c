#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int	i;
	char	*dup;

	i = 0;
	while (src[i])
		i++;
	dup = malloc(i + 1);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup = '\0';
	return (src);
	free(dup);
}
