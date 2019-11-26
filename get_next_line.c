/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/16 11:11:48 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/26 11:21:28 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

void				ft_strdel(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

char				*ft_strfjoin(char *s1, const char *s2)
{
	int				i;
	int				j;
	char			*str;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	j = 0;
	ft_strcpy(str, s1);
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

char				*next_line(char *str, char **line, size_t i, int *end)
{
	char			*tmp;

	if (str && str[i])
	{
		while (str[i] != '\n' && str[i])
			i++;
		if (str[i] == '\n')
		{
			*line = (i == 0) ? ft_strdup("") : ft_substr(str, 0, i);
			tmp = ft_strdup(str + i + 1);
			ft_strcpy(str, tmp);
			ft_strdel(&tmp);
			return (*line);
		}
		else
		{
			*line = (i == 0) ? ft_strdup("") : ft_substr(str, 0, i);
			*end = 1;
			return (*line);
		}
	}
	*end = 1;
	return (ft_strdup(""));
}

char				*read_line(char **str, char *buf, int fd)
{
	int				ret;
	char			*tmp;

	while ((ret = read(fd, buf, BUFFER_SIZE)) != 0)
	{
		if (ret < 0)
			return ((char *)-1);
		if (!str[fd])
			if (!(str[fd] = ft_strdup("")))
				return ((char *)-1);
		buf[ret] = '\0';
		if (!(tmp = ft_strfjoin(str[fd], buf)))
			return ((char *)-1);
		str[fd] = tmp;
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	return (str[fd]);
}

int					get_next_line(int fd, char **line)
{
	int				end;
	static char		*str[256];
	char			buf[BUFFER_SIZE + 1];

	end = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || !line || fd >= 256)
	{
		*line = NULL;
		return (-1);
	}
	if (((str[fd] = read_line(str, buf, fd)) == (char *)-1))
	{
		*line = NULL;
		return (-1);
	}
	*line = next_line(str[fd], line, 0, &end);
	if (end == 1)
		ft_strdel(&str[fd]);
	return (end != 1);
}
