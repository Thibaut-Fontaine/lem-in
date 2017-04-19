/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 13:14:34 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/19 23:42:49 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lemin.h"

/*
** fill the tube struct of the name1 block with the name2 block corresponding.
** ERROR if the name1 or the name2 not find in the structure
*/

void		fill_tube(t_block *b, char *name1, char *name2)
{
	t_tubes	*cur;
	int		id;

	id = b->id;
	while (ft_strcmp(b->name, name1) != 0)
	{
		b = b->nxt;
		if (b->id == id)
			error();
	}
	if (b->tubes == NULL)
	{
		b->tubes = malloc(sizeof(t_tubes));
		cur = b->tubes;
	}
	else
	{
		cur = b->tubes;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = malloc(sizeof(t_tubes));
		cur = cur->next;
	}
	cur->next = NULL;
	cur->content = find_block_name(b, name2);
}

/*
** find a block with his name
** if no match, its an ERROR.
*/

t_block		*find_block_name(t_block *b, char *name)
{
	int		id;

	id = b->id;
	while ((b = b->nxt))
	{
		if (ft_strcmp(b->name, name) == 0)
			break ;
		if (b->id == id)
			error();
	}
	return (b);
}

/*
** find a block with is id
** if no match or if the struct* sent is NULL, returns NULL.
*/

t_block		*find_block_id(t_block *b, int id)
{
	int		sid;

	if (b == NULL)
		return (NULL);
	if (b->id == id)
		return (b);
	sid = b->id;
	while ((b = b->nxt))
	{
		if (b->id == id)
			break ;
		if (b->id == sid)
			return (NULL);
	}
	return (b);
}
