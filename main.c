/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 04:36:40 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/21 04:04:44 by tfontain         ###   ########.fr       */
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

	//erase_block(find_block_id(info.cur, 3));
	/*printf("----------------------\n");
	init_block_weight(info.cur);*/
	//printstruct(info.cur);
	//printf("---------------------->\n");
	//printf("---------------------->\n");
	//
	//
	init_block_ant(info.cur, 0);
	while (it_is_finish(info.cur) == 0)
	{

		follow_the_weights(info.cur);
		ft_putchar('\n');
		//printstruct(info.cur);
		//follow_the_weights(info.cur);
		//ft_putchar('\n');
		//printstruct(info.cur);
	}
	//
	//
	//printf("----------------------\n");
	//printstruct(info.cur);
	//printf("----------------------\n");



	//printf("\nnombre de fourmis : |%d|\n", info.ant);
	//info.cur = find_block_id(info.cur, 2);
	//if (info.cur->tubes)
	//printf("le block : %s\n", info.cur->name);
	/*t_tubes		*cur;

	cur = info.cur->tubes;
	while (cur != NULL)
	{
		printf("contient : %s\n", cur->content->name);
		cur = cur->next;
	}*/
	//while (1)
	//	;
	return (0);
}
