#include "../include/header.h"

// double	ft_atoi(char *s)
// {
// 	long double	n;
// 	int			neg;
// 	int			i;

// 	if (!s)
// 		return (0);
// 	n = 0;
// 	neg = 1;
// 	i = 0;
// 	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
// 		i++;
// 	if (s[0] == '-' || s[0] == '+')
// 	{
// 		if (s[0] == '-')
// 			neg = -1;
// 		i++;
// 	}
// 	while (s[++i] && s[i] >= '0' && s[i] <= '9')
// 		n = n * 10 + s[i] - '0';
// 	return (n * neg); 
// }
