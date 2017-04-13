/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 05:13:36 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/13 07:41:56 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lemin.h"

/*
** add a new block and init all in, exept the tubes
*/

t_infos			init_blocks(t_infos info, int fl, char *name)
{
	int			id;
	static int	count = 2;
	t_block		*next;

	if (fl == 0)
		++count;
	if (info.cur != NULL)
		id = info.cur->id;
	while (info.cur != NULL || info.cur->nxt->id != id || info.cur->id != info.cur->nxt->id)
		info.cur = info.cur->nxt;
	if (info.cur != NULL)
	{
		next = info.cur->nxt;
		info.cur->nxt = malloc(sizeof(t_block));
		info.cur = info.cur->nxt;
	}
	else
	{
		info.cur = malloc(sizeof(t_block));
		next = info.cur;
	}
	info.cur->nxt = next;
	info.cur->id = fl == 0 ? count : fl;
	info.cur->name = name;
	if (fl == 1 || fl == 2)
		;
	return (info);
}

t_infos			parser(void)
{
	t_infos		info;
	char		*line;
	int			fl;

	get_next_line(0, &line);
	info.ant = ft_atoi(line);
	ft_strdel(&line);
	info.cur = NULL;
	if (info.ant <= 0)
		error();
	fl = 0;
	while (get_next_line(0, &line) == 1)
	{
		if (line[0] == 'L' || line[0] == '#')
			;
		else if (ft_strcmp(line, "##start") == 0)
			fl = 1;
		else if (ft_strcmp(line, "##end") == 0)
			fl = 2;
		else
		{
			info = init_blocks(info, fl,
					ft_strsub(line, 0, ft_strchr(line, ' ') - line));
			fl = 0;
		}
		ft_strdel(&line);
	}
	return (info);
}
