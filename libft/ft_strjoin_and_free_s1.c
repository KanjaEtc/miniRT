#include "libft.h"

char	*ft_strjoin_and_free_s1(char *s1, char *s2)
{
	char	*tmp;

	if (!s1 && !s2)
		return (NULL);
	else if (!s2)
		tmp = ft_strdup(s1);
	else if (!s1)
		tmp = ft_strdup(s2);
	else
		tmp = ft_strjoin(s1, s2);
	free(s1);
	s1 = NULL;
	return (tmp);
}
