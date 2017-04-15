/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 04:36:40 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/15 15:03:40 by tfontain         ###   ########.fr       */
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
		printf("id : %d | name : %s\n", b->id, b->name);
		b = b->nxt;
	}
		printf("id : %d | name : %s\n", b->id, b->name);
	return (1);
}

int				main(void)
{
	t_infos		info;

	info = parser();
	printstruct(info.cur);
	printf("\nnombre de fourmis : |%d|\n", info.ant);
	info.cur = find_block_name(info.cur, "7");
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
