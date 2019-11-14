/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   unit_test.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fgalaup <fgalaup@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 09:46:54 by fgalaup      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/02 10:49:23 by fgalaup     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

size_t	ft_strlen(const char *string);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_strdup(void *s1);
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstlast(t_list *lst);
void	ft_putstr(void *str);

void	test_lstdellink(void) // Rename The function when include to libft to ft_list_remove_link
{
	t_list	*list = NULL;
	t_list	*list1 = NULL;
	t_list	*list2 = NULL;
	t_list	*list3 = NULL;
	t_list	*list_null = NULL;

	char	*str1 = "1,";
	char	*str2 = "2,";
	char	*str3 = "3,";
	char	*str4 = "4,";
	char	*str5 = "5";

	t_list	*link1 = ft_lstnew(str1);
	t_list	*link2 = ft_lstnew(str2);
	t_list	*link3 = ft_lstnew(str3);
	t_list	*link4 = ft_lstnew(str4);
	t_list	*link5 = ft_lstnew(str5);

	ft_lstadd_back(&list, link1);
	ft_lstadd_back(&list, link2);
	ft_lstadd_back(&list, link3);
	ft_lstadd_back(&list, link4);
	ft_lstadd_back(&list, link5);

	list1 = ft_lstmap(list, ft_strdup, free);
	list2 = ft_lstmap(list, ft_strdup, free);
	list3 = ft_lstmap(list, ft_strdup, free);

	puts("[Test1] - NULL 1");
	ft_lstdellink(&list_null, list1, free);
	puts("[Test2] - NULL 2");
	ft_lstdellink(NULL, list1, free);

	puts("[Test3] - NULL 3 second params");
	ft_lstdellink(&list1, NULL, free);

	puts("[Test4] - NULL All NUll");
	ft_lstdellink(&list_null, NULL, free);
	ft_lstdellink(NULL, NULL, free);

	ft_lstdellink(&list1, list1, free);
	ft_lstdellink(&list2, list2->next, free);
	ft_lstdellink(&list3, ft_lstlast(list3), free);

	puts("[TestAll] Result");
	puts("Expected result : '2,3,4,5'");
	ft_lstiter(list1, ft_putstr);
	puts("\nExpected result : '1,3,4,5'");
	ft_lstiter(list2, ft_putstr);
	puts("\nExpected result : '1,2,3,4,'");
	ft_lstiter(list3, ft_putstr);
	puts("");
}

void	test_merge_line_segment(void)
{
	t_list	*list = NULL;

	char	*str1 = "Bonjour ";
	char	*str2 = "je suis ";
	char	*str3 = "une chaine";
	char	*str4 = " de test";
	char	*str5 = " pour merge_line_segment";

	t_list	*link1 = ft_lstnew(str1);
	t_list	*link2 = ft_lstnew(str2);
	t_list	*link3 = ft_lstnew(str3);
	t_list	*link4 = ft_lstnew(str4);
	t_list	*link5 = ft_lstnew(str5);

	link1->size = ft_strlen(str1);
	link2->size = ft_strlen(str2);
	link3->size = ft_strlen(str3);
	link4->size = ft_strlen(str4);
	link5->size = ft_strlen(str5);

	ft_lstadd_back(&list, link1);
	ft_lstadd_back(&list, link2);
	ft_lstadd_back(&list, link3);
	ft_lstadd_back(&list, link4);
	ft_lstadd_back(&list, link5);


	puts("[Test1] - NULL");
	puts(ft_merge_line_segment(NULL));

	puts("[Test2] - 1 segment");
	puts(ft_merge_line_segment(link5));

	puts("[Test3] - All segment");
	puts(ft_merge_line_segment(list));

}

void	test_add_line_segment(void)
{
	t_list	*list = NULL;

	char	*string_empty = NULL;
	char	string_sample1[] = "This is a test line\n";
	char	string_sample2[] = "This is\n test line\ttest";
	ssize_t	unreturned_bytes_size = 0;

	char	*string_buff_size = "00000000000000000000000000000000";
	//char	*string_buff_size = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

	puts("[Test1] - Empty string");
	unreturned_bytes_size = ft_add_segment(&list, string_empty, 0);
	write(1, string_empty, unreturned_bytes_size);
	printf("%zd:%s\n", unreturned_bytes_size, ft_merge_line_segment(list));
	
	puts("[Test2] - One line sample string");
	unreturned_bytes_size = ft_add_segment(&list, string_sample1, 20);
	write(1, string_sample1, unreturned_bytes_size);
	printf("%zd:%s\n", unreturned_bytes_size, ft_merge_line_segment(list));

	puts("[Test3] - tow line sample string");
	unreturned_bytes_size = ft_add_segment(&list, string_sample2, 23);
	write(1, "'", 1);
	write(1, string_sample2 + 1, unreturned_bytes_size - 1);
	write(1, "'\n", 2);
	printf("%zd:%s\n", unreturned_bytes_size, ft_merge_line_segment(list));

	puts("[Test3] - tow line sample string");
	unreturned_bytes_size = ft_add_segment(&list, string_buff_size, 32);
	write(1, string_buff_size, unreturned_bytes_size);
	printf("%zd:%s\n", unreturned_bytes_size, ft_merge_line_segment(list));
}

void test_reads_line()
{
	t_open_fd	*context = malloc(sizeof(t_open_fd));
	t_list		*segment_list = NULL;
	char		*line = NULL;
	int			returned_value;
	size_t		line_number = 1;

	context->fd = open("test/file/small.file", O_RDONLY);
	context->over = NULL;
	context->size = 0;
	do
	{
		returned_value = ft_reads_line(context, &segment_list);
		line = ft_merge_line_segment(segment_list);
		printf("[%lu]-%d-'%s'\n", line_number,  returned_value, line);
		ft_lstclear(&segment_list, free);
		line_number++;
	} while (returned_value >= 1);
	close(context->fd);

	context->fd = open("test/file/longLine.file", O_RDONLY);
	context->over = NULL;
	context->size = 0;
}

int		main(void)
{
	puts("=========LstDelLink=========");
	test_lstdellink();
	puts("======MergeLineSegment======");
	test_merge_line_segment();
	puts("=======AddLineSegment=======");
	test_add_line_segment();
	puts("==========ReadLine==========");
	test_reads_line();
	return (0);
}
