/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 03:00:10 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/17 06:13:31 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lemin.h"

// this file is absolutely not finished yet

/*
** return 0 if the block is the end, 1 if it is in the tubes,
** 2 if it is in the tubes of the tubes, etc
*/

int					how_far(t_block *b)
{
	t_tubes			*cur;
	int				last;
	int				tmp;

	if (b->id == 2)
		return (0);
	last = 9999999; // max struct lenght
	cur = b->tubes;
	while (cur)
	{
		if ((tmp = how_far(cur->content)) < last)
			last = tmp;
		cur = cur->next;
	}
	return (last + 1);
}

/*
** find the empty block connected to the current block which is the closest
** to the end. maybe this block is the current block.
** return NULL when the end is reached.
** (always considering the end is empty)
*/

t_block				*find_closest(t_block *b)
{
	t_tubes			*cur;

	if (b->id == 2) // id 2 is the end
		return (b);
	cur = b->tubes;
	while (cur) // abort si on rencontre un block deja rencontre
	{
		if (find_closest(cur->content)->id == 2)
			;
		cur = cur->next;
	}
	return ();
}
