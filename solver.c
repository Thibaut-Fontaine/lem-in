/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 03:00:10 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/19 18:41:53 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lemin.h"

/*
** find the next block in the structure with the specified weight
*/

t_block			*find_block_weight(t_block *b, int weight)
{
	int			id;

	id = b->id;
	while ((b = b->nxt))
	{
		if (b->weight == weight)
			return (b);
		if (b->id == id)
			break ;
	}
	return (NULL);
}

/*
** move the ant of the current block
** to one of his tubes who have a lower weight
** if there is no ant yet (or if it is the ending block)
** return the made operation as a malloced string as following :
** Lx-y ; where x is the ant and y is the name of the block
*/

char			*move_ant_to_lower_tube(t_block *b)
{
	t_tubes		*tube;

	tube = b->tubes;
	while (tube)
	{
		if (tube->content->weight < b->weight &&
				(tube->content->ant == 0 || tube->content == find_block_id(b, 2)))
		{
			tube->content->ant = b->ant;
			b->ant = 0;
		}
		tube = tube->next;
	}
}

/*
**
*/

follow_the_weights(t_block *b)
{
	int			rank;
	int			id;
	t_block		*start;

	init_block_ant(b, 0);
	rank = 1;
	while ()
	{
		b = find_block_weight(b, rank);
		id = b->id;
		while ((b = find_block_weight(b, rank)))
		{
			// ajouter une exeption si c'est start pour creer et numeroter les fourmis
			if (b->ant && b != find_block_id(b, 2))
				move_ant_to_lower_tube(b);
			if (b->id == id)
				break ;
		}
		++rank;
	}
}
