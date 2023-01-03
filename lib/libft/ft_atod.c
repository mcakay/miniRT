#include "libft.h"

double ft_power(int base, int power)
{
	int result;

	result = 1;
	while (power > 0)
	{
		result *= base;
		power--;
	}
	return (result);
}

double ft_atod(char *str)
{
	char **split;
	double result;
	int i;

	if (ft_strchr(str, '.') == NULL)
		return (ft_atoi(str));
	split = ft_split(str, '.');
	if (ft_atoi(split[0]) < 0)
		result = ft_atoi(split[0]) - (double)ft_atoi(split[1]) / ft_power(10, ft_strlen(split[1]));
	else
		result = ft_atoi(split[0]) + (double)ft_atoi(split[1]) / ft_power(10, ft_strlen(split[1]));
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (result);
}
