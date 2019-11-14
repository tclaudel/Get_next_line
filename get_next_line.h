/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/16 11:12:02 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 14:12:11 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

size_t		ft_strlen(const char *str);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_calloc(size_t nb, size_t size);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strdup(const char *str);
char		*ft_strjoin(const char *s1, const char *s2);
int			get_next_line(int fd, char **line);
char		*ft_strchr(const char *str, int c);
char		*ft_substr(char *s, unsigned int start, size_t len);

#endif
