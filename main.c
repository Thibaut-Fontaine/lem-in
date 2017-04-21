/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 04:36:40 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/21 04:14:40 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"
#include "./lemin.h"
#include <stdio.h> //

int				printstruct(t_block *b) // to remove
{
	int			id;

	id = b->id;
	b = b->nxt;
	while (b->id != id)
	{
		printf("id : %d | name : %s | weight : %d | ant : %d\n",
				b->id, b->name, b->weight, b->ant);
		b = b->nxt;
	}
	printf("id : %d | name : %s | weight : %d | ant : %d\n",
			b->id, b->name, b->weight, b->ant);
	return (1);
}

int				main(void)
{
	t_infos		info;

	info = parser();
	init_block_ant(info.cur, 0);
	while (it_is_finish(info.cur) == 0) // prlbm boucle infinie
	{
		follow_the_weights(info.cur);
		ft_putchar('\n');
	}
	while (1)
		;
	return (0);
}
