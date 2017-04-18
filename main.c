/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 04:36:40 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/18 09:29:38 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"
#include "./lemin.h"

int				printstruct(t_block *b) // to remove
{
	int			id;

	id = b->id;
	b = b->nxt;
	while (b->id != id)
	{
		printf("id : %d | name : %s | check : %d | ant : %d\n",
				b->id, b->name, b->check, b->ant);
		b = b->nxt;
	}
		printf("id : %d | name : %s | check : %d | ant : %d\n",
				b->id, b->name, b->check, b->ant);
	return (1);
}

int				main(void)
{
	t_infos		info;

	info = parser();

	printf("----------------------\n");
	printstruct(info.cur);
	printf("----------------------\n");
	//erase_block(find_block_id(info.cur, 3));
	printstruct(info.cur);
	printf("----------------------\n");
	printf("\nnombre de fourmis : |%d|\n", info.ant);
	info.cur = find_block_id(info.cur, 2);
	if (info.cur->tubes)
	printf("le block : %s\n", info.cur->name);
	t_tubes		*cur;

	cur = info.cur->tubes;
	while (cur != NULL)
	{
		printf("contient : %s\n", cur->content->name);
		cur = cur->next;
	}
	while (1)
		;
	return (0);
}
