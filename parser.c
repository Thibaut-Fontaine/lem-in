/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 05:13:36 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/19 23:42:14 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lemin.h"

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
	info.cur->ant = id == 1 ? info.ant : 0; // nbr fourmis init a 0
	info.cur->tubes = NULL;
	return (info);
}

/*
** parse the input and fill structures using init_blocks and init_tubes.
*/

void			cut_tube(t_block *b, char *l)
{
	char		*sub1;
	char		*sub2;

	if (ft_strchr(l, '-') == NULL)
		error();
	sub1 = ft_strsub(l, 0, ft_strchr(l, '-') - l);
	sub2 = ft_strsub(l, ft_strchr(l, '-') - l + 1, ft_strlen(l));
	fill_tube(b, sub1, sub2);
	fill_tube(b, sub2, sub1);
	ft_strdel(&sub1);
	ft_strdel(&sub2);
}

t_infos			tubes_parsing(t_infos info, char **last_line)
{
	char		*l;

	l = NULL;
	cut_tube(info.cur, *last_line);
	ft_strdel(last_line);
	while (get_next_line(0, &l))
	{
		if (l[0] == 'L' || l[0] == '#')
			;
		else if (ft_strchr(l, '-') && !ft_strchr(l, ' '))
			cut_tube(info.cur, l);
		else
			error();
		ft_strdel(&l);
	}
	return (info);
}

void			first_line(t_infos *info)
{
	char		*l;
	int			i;

	i = 0;
	get_next_line(0, &l);
	while (ft_isdigit(l[i]) && l[i])
		++i;
	if (l[i] != 0)
		error();
	info->ant = ft_atoi(l);
	ft_strdel(&l);
	info->cur = NULL;
	if (info->ant <= 0)
		error();
}

t_infos			parser(void)
{
	t_infos		info;
	char		*l;
	int			fl;

	first_line(&info);
	fl = 0;
	while (get_next_line(0, &l) == 1 && !(*l != '#' && *l != 'L'
				&& ft_strchr(l, '-') && !ft_strchr(l, ' ')))
	{
		if (ft_strequ(l, "##start") && (fl = 1))
			find_block_id(info.cur, 1) != NULL ? error() : 0;
		else if (ft_strequ(l, "##end") && (fl = 2))
			find_block_id(info.cur, 2) != NULL ? error() : 0;
		else if (*l != 'L' && *l != '#' && (!ft_strchr(l, ' ') ? error() : 1))
		{
			info = init_blocks(info, fl,
					ft_strsub(l, 0, ft_strchr(l, ' ') - l));
			fl = 0;
		}
		else if (*l != 'L' && *l != '#')
			error();
		ft_strdel(&l);
	}
	return (tubes_parsing(info, &l));
}
