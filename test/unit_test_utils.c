/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   unit_test_utils.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fgalaup <fgalaup@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 10:32:37 by fgalaup      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/30 10:43:30 by fgalaup     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>

size_t	ft_strlen(const char *string)
{
	size_t lenght;

	lenght = 0;
	while (string[lenght])
		lenght++;
	return (lenght);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dest_bytes;
	char	*src_bytes;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	dest_bytes = (char *)dst;
	src_bytes = (char *)src;
	while (i < n)
	{
		dest_bytes[i] = src_bytes[i];
		i++;
	}
	return (dst);
}

void	*ft_strdup(void *a)
{
	void		*str_clone;
	size_t		str_lenght;
	char		*s1;

	s1 = a;
	str_lenght = ft_strlen(s1);
	if (!(str_clone = malloc((str_lenght + 1) * sizeof(char))))
		return (NULL);
	ft_memcpy(str_clone, s1, str_lenght + 1);
	return (str_clone);
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL)
		return ;
	while (lst->next)
	{
		f(lst->content);
		lst = lst->next;
	}
	f(lst->content);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_list_elem;

	new_list = NULL;
	if (lst == NULL)
		return (NULL);
	while (lst->next)
	{
		if (!(new_list_elem = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_list_elem);
		lst = lst->next;
	}
	if (!(new_list_elem = ft_lstnew(f(lst->content))))
		ft_lstclear(&new_list, del);
	else
		ft_lstadd_back(&new_list, new_list_elem);
	return (new_list);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_putstr(void *str)
{
	write(1, str, ft_strlen(str));
}
