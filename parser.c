/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 05:13:36 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/13 11:17:05 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lemin.h"

/*
** init_tubes
*/

int				init_tubes(char *name1, char *name2)
{
	printf("liaison entre : |%s| et |%s|\n", name1, name2);
	return (0);
}

/*
** add a new block and init all in, exept the tubes
** the start will always have id = 1 and the end id = 2.
*/

t_infos			init_blocks(t_infos info, int fl, char *name)
{
	int			id;
	static int	count = 2;
	t_block		*next;

	if (info.cur != NULL)
		id = info.cur->id;
	while (info.cur != NULL && info.cur->nxt->id != id
			&& info.cur->id != info.cur->nxt->id)
		info.cur = info.cur->nxt;
	if (info.cur != NULL)
	{
		next = info.cur->nxt;
		(info.cur->nxt = malloc(sizeof(t_block))) == NULL ? error() : 0;
		info.cur = info.cur->nxt;
	}
	else
	{
		(info.cur = malloc(sizeof(t_block))) == NULL ? error() : 0;
		next = info.cur;
	}
	info.cur->nxt = next;
	info.cur->id = fl == 0 ? ++count : fl;
	info.cur->name = name;
	return (info);
}

/*
** parse the input and fill structures using init_blocks and init_tubes.
*/

void			cut_tube(char *l)
{
	char		*sub1;
	char		*sub2;

	sub1 = ft_strsub(l, 0, ft_strchr(l, '-') - l);
	sub2 = ft_strsub(l, ft_strchr(l, '-') - l + 1, ft_strlen(l));
	init_tubes(sub1, sub2);
	ft_strdel(&sub1);
	ft_strdel(&sub2);
}

t_infos			tubes_parsing(t_infos info, char **last_line)
{
	char		*l;

	l = NULL;
	cut_tube(*last_line);
	ft_strdel(last_line);
	while (get_next_line(0, &l))
	{
		if (l[0] == 'L' || l[0] == '#')
			;
		else if (ft_strchr(l, '-') && !ft_strchr(l, ' '))
			cut_tube(l);
		ft_strdel(&l);
	}
	return (info);
}

t_infos			parser(void)
{
	t_infos		info;
	char		*l;
	int			fl;

	get_next_line(0, &l);
	info.ant = ft_atoi(l);
	ft_strdel(&l);
	info.cur = NULL;
	info.ant <= 0 ? error() : (fl = 0);
	while (get_next_line(0, &l) == 1 && !(*l != '#' && *l != 'L'
				&& ft_strchr(l, '-') && !ft_strchr(l, ' ')))
	{
		if (ft_strcmp(l, "##start") == 0)
			fl = 1;
		else if (ft_strcmp(l, "##end") == 0)
			fl = 2;
		else if (l[0] != 'L' && l[0] != '#')
		{
			info = init_blocks(info, fl,
					ft_strsub(l, 0, ft_strchr(l, ' ') - l));
			fl = 0;
		}
		ft_strdel(&l);
	}
	return (tubes_parsing(info, &l));
}
