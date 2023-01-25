#include "get_next_line.h"
#include "../includes/libft/libft.h"
// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*ret;
// 	int		i;
// 	int		j;

// 	if (!s1 && !s2)
// 		return (0);
// 	i = 0;
// 	j = 0;
// 	ret = malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
// 	if (!ret)
// 		return (NULL);
// 	if (s1)
// 	{
// 		while (s1[i] != '\0')
// 		{
// 			ret[i] = s1[i];
// 			i++;
// 		}
// 	}
// 	while (s2[j] != 0)
// 		ret[i++] = s2[j++];
// 	ret[i] = 0;
// 	free(s1);
// 	return (ret);
// }

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!str)
// 		return (0);
// 	while (str[i] != 0)
// 		i++;
// 	return (i);
// }

// char	*ft_strdup(char *s1)
// {
// 	int		i;
// 	char	*ptr;

// 	i = 0;
// 	if (!s1[0])
// 		return (NULL);
// 	while (s1[i] != '\n' && s1[i] != '\0')
// 		i++;
// 	i++;
// 	ptr = malloc((i * sizeof(char)) + 1);
// 	if (!ptr)
// 		return (NULL);
// 	i = 0;
// 	while (s1[i] != '\n' && s1[i])
// 	{
// 		ptr[i] = s1[i];
// 		i++;
// 	}
// 	if (s1[i] == '\n')
// 	{
// 		ptr[i] = s1[i];
// 		i++;
// 	}
// 	ptr[i] = 0;
// 	return (ptr);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	int		i;
// 	char	j;

// 	j = (char) c;
// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	while (s[i])
// 	{
// 		if (s != NULL && s[i] == j)
// 		{
// 			return ((char *)s + i);
// 		}
// 		i++;
// 	}
// 	return (NULL);
// }

char	*gnl_helper(char *store, int fd)
{
	int		bytes;
	char	*str;

	bytes = 1;
	while (bytes != 0 && !ft_strchr(store, '\n'))
	{
		str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!str)
			return(NULL);
		bytes = read(fd, str, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(str);
			str = NULL;
			return (NULL);
		}
		str[bytes] = 0;
		store = ft_strjoin(store, str);
		free(str);
		str = NULL;
	}
	return (store);
}