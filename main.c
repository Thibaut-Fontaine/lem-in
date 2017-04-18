/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 04:36:40 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/18 02:31:28 by tfontain         ###   ########.fr       */
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
		printf("id : %d | name : %s | check : %d | ant : %d\n", b->id, b->name, b->check, b->ant);
		b = b->nxt;
	}
		printf("id : %d | name : %s\n", b->id, b->name);
	return (1);
}

int				main(void)
{
	t_infos		info;

	info = parser();

	// toast 1 :
	//find_closest(info.cur, find_block_id(info.cur, 2));
	init_block_check(info.cur, 0);
	//init_block_ant(info.cur, 66);
	t_block		*f;
	f = find_closest(find_block_id(info.cur, 1), find_block_id(info.cur, 2));
	printf("name : %s, id : %d\n", f->name, f->id);
	// toast 2 :
	printstruct(info.cur);
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
	return (0);
}
