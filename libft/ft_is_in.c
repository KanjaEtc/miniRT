#include "libft.h"

int	ft_is_in(char *s, char c)
{
	int	i;

	i = -1;
	while (s && s[++i])
	{
		if (s[i] == c)
			return (1);
	}
	return (0);
}
