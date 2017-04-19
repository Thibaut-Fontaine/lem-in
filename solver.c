/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 03:00:10 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/19 21:22:33 by tfontain         ###   ########.fr       */
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
** return an operation as a malloced string as following :
** Lx-y ; where x is the ant and y is the name of the block
*/

char			*generate_operation(char *name, int ant)
{
	char		*ret;
	char		*tmp;
	int			len;

	ret = ft_strnew(ft_strlen(name)
			+ (len =
				ft_strlen(tmp = ft_itoa(ant))) + 2);
	ret[0] = 'L';
	ft_strcpy(ret + 1, tmp);
	free(tmp);
	ret[len + 1] = '-';
	ft_strcpy(ret + len + 2, name);
	return (ret);
}

/*
** move the ant of the current block
** to one of his tubes who have a lower weight
** if there is no ant yet (or if it is the ending block)
** return the made operation as a malloced string as following :
** Lx-y ; where x is the ant and y is the name of the tube->block
** if there is no place to move the current block->ant, just return NULL.
*/

char			*move_ant_to_lower_tube(t_block *b)
{
	t_tubes		*tube;
	char		*ret;
	char		*tmp;

	tube = b->tubes;
	while (tube)
	{
		if (tube->content->weight < b->weight && (tube->content->ant == 0
					|| tube->content == find_block_id(b, 2)))
		{
			tube->content->ant = b->ant;
			b->ant = 0;
			return (generate_operation(tube->content->name,
						tube->content->ant));
		}
		tube = tube->next;
	}
	return (NULL);
}

/*
** move the ants of the start in all the lower tubes who dont have ant yet
*/

move_ant_from_start(t_block *b)
{
	t_tubes		*tube;
	static int	max_ants = -1;

	if (max_ants == -1)
		max_ants = b->ant;
	tube = b->tubes;
	while (tube)
	{
		if (tube->content->ant == 0)
			if (b->ant > 0)
			{
				tube->content->ant = max_ants - b->ant + 1; // genere le numero de la fourmi
				--b->ant;
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
	char		*op;
	
	init_block_ant(b, 0);
	rank = 1;
	while (rank) // s'arreter quand on est a start
	{
		b = find_block_weight(b, rank);
		id = b->id;
		while ((b = find_block_weight(b, rank)))
		{
			if (b == find_block_id(b, 2))
			{
				move_ant_from_start(b);
				rank = -1;
				break ;
			}
			else if (b->ant && b != find_block_id(b, 2))
				if ((op = move_ant_to_lower_tube(b)) != NULL)
					;
			if (b->id == id)
				break ;
		}
		++rank;
	}
}
