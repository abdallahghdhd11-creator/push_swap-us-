#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
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

//#}
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

static size_t	count_words(char const *s)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != ' ' && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == ' ')
			in_word = 0;
		s++;
	}
	return (count);
}

void	*free_array(char **array, size_t i)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
	return (NULL);
}

static char	*allocate_word(char const *s)
{
	size_t	len;
	char	*word;

	len = 0;
	while (s[len] && s[len] != ' ')
		len++;
	word = ft_substr(s, 0, len);
	return (word);
}

char	**ft_split(char const *s)
{
	char	**result;
	size_t	i;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (count_words(s) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != ' ')
		{
			result[i] = allocate_word(s);
			if (!result[i])
				return (free_array(result, i));
			i++;
			while (*s && *s != ' ')
				s++;
		}
		else
			s++;
	}
	result[i] = NULL;
	return (result);

}

static int it_is_digit (char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long	ft_atoi(const char *str)
{
	size_t	i;
	long 	sum;
	int		sign;

	i = 0;
	sign = 1;
	sum = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	
//مسافات خاصة  /T وهاي القصص
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
//اذا تكررت ال- او ال+ اشمط غلط
	if (!it_is_digit(str[i]))
		return (2147483648L); 
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum = (sum * 10) + (str[i] - '0');
		if ((sum * sign) > 2147483647 || (sum * sign) < -2147483648)
			return (2147483648L);
		i++;
	}
	if (str[i] != '\0')
		return (2147483648L);
	return (sign * sum);
}







