/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 00:37:45 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/20 00:16:08 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lemin.h"

/*
** init all the ->weight with 0
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
** return 1 if at least one of the tubes of the block is empty
** return 0 else.
*/

int				have_tube_empty(t_block *b)
{
	t_tubes		*tube;

	tube = b->tubes;
	while (tube)
	{
		if (tube->content->weight == 0)
			return (1);
		tube = tube->next;
	}
	return (0);
}


/*
** return the next block with a weight upper than 0 (who have weight)
** and only if at least one of his tube dont have weight yet
** if there is no, return NULL
*/

t_block			*next_usable_block(t_block *b)
{
	int			id;

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

/*
** return 1 if all blocks have a weight different than 0 ; return 0 else
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
** end->weight = 1, end->tube->content->weight = 2, etc.
** return 1 for success, return 0 if there is no way to fill all the blocks
*/

int				init_block_weight(t_block *b)
{
	t_tubes		*tube;

	//init_block_check(b, 0);				// initialise tous les check a 0
	preinit_weight(b);					// initialiste tous les blocks a 0
	b = find_block_id(b, 2);			// cherche le block de fin
	b->weight = 1;						// met son weight a 1
	while (b)								// tant que b != NULL
	{
		//b->check = 1;
		if (already_filled(b))				// si tous les blocks ont un weight, return 1
			return (1);
		tube = b->tubes;					// on recupere le tube du block
		while (tube)									// pour chaque tube
		{
			if (tube->content->weight > b->weight + 1	// si le tube courant a un weight plus fort
					|| tube->content->weight == 0)		// que le block courant, ou si il est vide,
				tube->content->weight = b->weight + 1;	// ecrit weight du block + 1 dans le tube.
			tube = tube->next;
		}
		b = next_usable_block(b);	// cherche un block qui a un weight > 0 et dont au moins un des tubes est vide
	}
	return (0); // si chaque block ayant un poids a tous ses tubes qui sont pleins, return 0.
}	// utiliser ensuite la structure ainsi initialisee pour toujours
	//se diriger vers un weight plus faible que le block courant.

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
