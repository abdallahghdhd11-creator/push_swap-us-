#include "push_swap.h"

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

static const char	*next_word(const char *s)
{
	while (*s && *s != ' ')
		s++;
	return (s);
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
			s = next_word(s);
		}
		else
			s++;
	}
	result[i] = NULL;
	return (result);
}
