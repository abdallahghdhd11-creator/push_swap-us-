#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	i;
	size_t	len;

	len = ft_strlen(s1);
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*c;
	size_t	i;
	size_t	lens;
	size_t	n;

	i = 0;
	if (!s)
		return (NULL);
	lens = ft_strlen(s);
	if (start > lens)
		return (ft_strdup(""));
	if (lens - start > len)
		n = len;
	else
		n = lens - start;
	c = (char *)malloc(sizeof(char) * (n + 1));
	if (!c)
		return (NULL);
	while (s[start + i] != '\0' && i < n)
	{
		c[i] = s[start + i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

static int	it_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long	ft_atoi(const char *str)
{
	size_t	i;
	long	sum;
	int		sign;

	i = 0;
	sign = 1;
	sum = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	if (!it_is_digit(str[i]))
		return (2147483648L);
	while (it_is_digit(str[i]))
	{
		sum = (sum * 10) + (str[i++] - '0');
		if ((sum * sign) > 2147483647 || (sum * sign) < -2147483648)
			return (2147483648L);
	}
	if (str[i] != '\0')
		return (2147483648L);
	return (sign * sum);
}
