/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 08:23:32 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/21 09:07:58 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lemin.h"

int			gnl_print(const int fd, char **line)
{
	int		ret;

	ret = get_next_line(fd, line);
	ft_putstr(*line);
	ft_putchar('\n');
	return (ret);
}

void		print_out(char *s)
{
	ft_putstr(s);
	free(s);
	ft_putchar(' ');
}
