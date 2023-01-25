#include "get_next_line.h"
#include "../includes/libft/libft.h"

char	*get_next_line(int fd)
{
	char		*res;
	static char	*store;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	store = gnl_helper(store, fd);
	if (!store)
	{
		free(store);
		return (NULL);
	}
	res = ft_strdup(store);
	store = ft_get_after_nl(store);
	return (res);
}

char	*ft_get_after_nl(char *store)
{
	int		i;
	int		j;
	char	*new_store;

	i = 0;
	j = 0;
	if (!store)
		return (NULL);
	while (store[i] != '\n' && store[i])
		i++;
	if (!store[i])
	{
		free (store);
		return (NULL);
	}
	new_store = malloc(sizeof(char) * (ft_strlen(store) - i + 1));
	if (!new_store)
		return (NULL);
	i++;
	while (store[i])
		new_store[j++] = store[i++];
	new_store[j] = 0;
	free(store);
	return (new_store);
}