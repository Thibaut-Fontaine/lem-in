/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 00:37:45 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/21 04:30:36 by tfontain         ###   ########.fr       */
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

	preinit_weight(b);
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
** init_block_weight explication in french, line per line :
** \
** \
** initialiste tous les blocks a 0
** cherche le block de fin
** met son weight a 1
** tant que b != NULL
**  - si tous les blocks ont un weight, return 1
**  - on recupere le tube du block
**  -  - pour chaque tube
**  -  - si le tube courant a un weight plus fort que le block courant,
**  -  - ou si il est vide ; alors ecrit weight du block + 1 dans le tube.
**  - cherche un block qui a un weight > 0 et dont un des tubes est vide
** si chaque block ayant un poids a tous ses tubes qui sont pleins, return 0.
** \
** \
** la structure ainsi initialisee est ensuite utilisee en se dirigeant
** toujours vers un block de poids plus faible par rapport au block courant.
*/

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
