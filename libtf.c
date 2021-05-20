#include"function.h"
void	ft_free(char **c)
{
	int	i;

	i = 0;
	while (c[i])
		free(c[i++]);
	free(c);
}

int	ft_len(int i, const char *s, char c)
{
	int	len;
	int	i3;

	i3 = i;
	len = 0;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		if ((len == 0 || i != i3) || s[i])
			len++;
		while (s[i] == c && s[i])
			i++;
	}
	return (len);
}

char	**ft_fill(const char *s, char c, int i, char **s1)
{
	int	i3;
	int	len;
	int	i1;

	i1 = 0;
	i3 = 0;
	len = ft_len(i, s, c);
	while (len > i1)
	{
		i = i3;
		while (s[i++] == c)
			i3++;
		while (s[i] != c && s[i])
			i++;
		s1[i1] = ft_substr(s, i3, i - i3);
		if (!s1[i1])
		{
			ft_free(s1);
			return (NULL);
		}
		i3 = i;
		i1++;
	}
	return (s1);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		len;
	char	**s1;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	len = ft_len(i, s, c);
	s1 = (char **)malloc(sizeof(char *) * (len + 1));
	if (!s1)
		return (NULL);
	s1[len] = NULL;
	return (ft_fill(s, c, i, s1));
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	len1;
	size_t	len2;
	size_t	i;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	s = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!s)
		return (NULL);
	while (++i < len1)
		s[i] = s1[i];
	i = 0;
	while (i < len2)
	{
		s[len1 + i] = s2[i];
		i++;
	}
	s[len1 + i] = '\0';
	return (s);
}
size_t	ft_strlen(char *a)
{
	size_t	i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*s1;
	size_t	i1;

	i1 = 0;
	if (!s)
		return (NULL);
	i = ft_strlen((char *)s);
	s1 = (char *)malloc(len + 1);
	if (!s1)
		return (NULL);
	while (i1 < len && start < i)
		s1[i1++] = s[start++];
	s1[i1] = '\0';
	return (s1);
}
char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*s2;
	size_t	i1;

	i1 = 0;
	i = ft_strlen((char *)s1);
	s2 = (char *)malloc(i + 1);
	if (!s2)
		return (NULL);
	while (i >= i1)
	{
		s2[i1] = s1[i1];
		i1++;
	}
	return (s2);
}
