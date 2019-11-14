/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_pipe.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lumeyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/27 15:13:59 by lumeyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/27 15:16:27 by lumeyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int ret;
	char *dest;

	while ((ret = get_next_line(0, &dest)))
	{
		printf("retour gnl: %d~\n", ret);
		printf("LINE: ~%s~\n", dest);
		printf("_________________________________\n");
		free(dest);
	}
	printf("retour gnl: %d~\n", ret);
	printf("LINE: ~%s~\n", dest);
	free(dest);
}
