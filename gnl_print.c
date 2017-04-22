/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 08:23:32 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/22 05:41:06 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lemin.h"

int			gnl_print(const int fd, char **line)
{
	int		ret;

	ret = get_next_line(fd, line);
	if (*line != NULL)
	{
		ft_swrite(1, *line, ft_strlen(*line));
		ft_swrite(1, "\n", 1);
	}
	return (ret);
}

void		print_out(char *s)
{
	ft_putstr(s);
	free(s);
	ft_putchar(' ');
}
