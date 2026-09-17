#include "libft.h"

int	ft_strlen_with_limiter_included(char *s, char c)
{
	int	i = 0;

	while (s && s[i] && s[i] != c)
		i++;
	if (s && s[i])
		i++;
	return (i);
}
