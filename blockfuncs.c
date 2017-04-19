/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blockfuncs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 06:34:07 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/19 23:32:46 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lemin.h"

/*
** erase the specified block and free all of this block
*/

void			erase_block(t_block *b)
{
	int			id;
	t_block		*to_erase;
	t_tubes		*tube;
	t_tubes		*next;

	to_erase = b;

	// erase it from the tubes of the another blocks :
	id = b->id;
	while ((b = b->nxt))
	{
		tube = b->tubes;
		while (tube)
		{
			if (tube->content == to_erase)
			{
				next = tube->next;
				free(tube);
				tube = next;
			}
			else
				tube = tube->next;
		}
		if (b->id == id)
			break ;
	}

	//

	// now delete the block himself :
	b = to_erase;
	id = b->id;
	while ((b = b->nxt))
	{
		if (b->nxt->id == id)
			break ;
	}
	b->nxt = b->nxt->nxt;
	tube = to_erase->tubes;
	while (tube) // erase his tubes
	{
		next = tube->next;
		free(tube);
		tube = next;
	}
	free(to_erase->name);
	free(to_erase);
}

/*
** return 0 if all the block are empty (exept the ending block)
** return 1 else
*/

int			it_is_finish(t_block *b)
{
	int		id;

	id = b->id;
	while ((b = b->nxt))
	{
		if (b->ant != 0 && b != find_block_id(b, 2))
			return (0);
		if (b->id == id)
			break ;
	}
	return (1);
}
