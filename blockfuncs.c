/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blockfuncs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 06:34:07 by tfontain          #+#    #+#             */
/*   Updated: 2017/05/12 11:20:05 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lemin.h"

/*
** if there is a block, exept the final block, who still have ants ;
** then return 0
** if no block have ants (exept the final block) ;
** then return 1
*/

int			it_is_finish(t_block *b)
{
	int		id;

	id = b->id;
	while ((b = b->nxt))
	{
		if (b->ant != 0 && b->id != 2)
			return (0);
		if (b->id == id)
			break ;
	}
	return (1);
}

/*
** return the next block with a weight upper than 0 (who have weight)
** and only if at least one of his tube dont have weight yet
** if there is no, return NULL
*/

t_block		*next_usable_block(t_block *b)
{
	int		id;

	id = b->id;
	while ((b = b->nxt))
	{
		if (b->weight > 0 && have_tube_empty(b))
			return (b);
		if (b->id == id)
			break ;
	}
	return (NULL);
}
