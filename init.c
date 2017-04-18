/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 00:37:45 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/18 06:24:29 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lemin.h"

/*
** init allthe weight with 0
*/

void			preinit_weight(t_block *b)
{
	int			id;

	id = b->id;
	while ((b = b->nxt))
	{
		b->weight = 0;
		if (b->id == id)
			break ;
	}
}

/*
** return the next block with a weight upper than 0
** if there is no, return NULL
*/

t_block			*next_usable_block(t_block *b)
{
	int			id;

	id = b->id;
	while ((b = b->nxt))
	{
		if (b->weight > 0)
			return (b);
		if (b->id == id)
			break ;
	}
	return (NULL);
}

/*
** return 1 if all blocks have a weight, 0 else
*/

int				already_filled(t_block *b)
{
	int			id;

	id = b->id;
	while ((b = b->nxt))
	{
		if (b->weight == 0)
			return (0);
		if (b->id == id)
			break ;
	}
	return (1);
}

/*
** init all the block->weight with int calculated from the distance between
** the current block and the ending block ; as following :
** end->weight = 0, end->tube->content->weight = 1, etc.
** return 1 for success, return 0 if there is no way to fill all the blocks
*/

int				init_block_weight(t_block *b)
{
	t_tubes		*tube;

	b = find_block_id(b, 2);
	b->weight = 1;
	while (b)
	{
		if (already_filled(b))
			return (1);
		tube = b->tubes;
		while (tube)
		{
			if (tube->content->weight > b->weight + 1
					|| tube->content->weight == 0)
				tube->content->weight = b->weight + 1;
			tube = tube->next;
		}
		b = next_usable_block(b);
	}
	return (0);
}

/*
** init all the block->ant with the specified int, exept the start and the end
*/

void			init_block_ant(t_block *b, int n)
{
	int			id;

	id = b->id;
	while ((b = b->nxt))
	{
		if (b->id != 2 && b->id != 1)
			b->ant = n;
		if (b->id == id)
			break ;
	}
}

/*
** init all the block->check with the specified int
*/

void			init_block_check(t_block *b, int n)
{
	int			id;

	id = b->id;
	while ((b = b->nxt))
	{
		b->check = n;
		if (b->id == id)
			break ;
	}
}
