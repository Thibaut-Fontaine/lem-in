/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 04:36:40 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/13 09:34:59 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"
#include "./lemin.h"
#include <math.h> //

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
	return (0);
}
