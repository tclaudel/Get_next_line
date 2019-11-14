/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/16 11:41:47 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/06 15:28:27 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

size_t			ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char			*ft_strdup(const char *str)
{
	size_t		size;
	size_t		i;
	char		*dest;

	i = 0;
	size = ft_strlen(str);
	if (!(dest = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char			*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		l;
	size_t		lmalloc;
	char		*str;

	i = 0;
	l = ft_strlen(s);
	if ((start >= l) || (len == 0))
		return (ft_calloc(sizeof(char), 1));
	lmalloc = (start - l < len ? start - l : len);
	if (!(str = (char*)malloc(sizeof(char) * lmalloc + 1)))
		return (NULL);
	while (len--)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_strchr(const char *str, int c)
{
	size_t		i;

	if (c == 0)
		return ((char *)str + ft_strlen(str));
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

char			*ft_strcpy(char *dest, const char *src)
{
	size_t		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
