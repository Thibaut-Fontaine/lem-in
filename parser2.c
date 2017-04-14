/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 13:14:34 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/14 11:29:42 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lemin.h"

t_block		*find_block_name(t_block *b, char *name)
{
	int		id;

	id = b->id;
	while ((b = b->nxt))
	{
		if (ft_strcmp(b->name, name) == 0)
			break ;
		if (b->id == id)
			error();
	}
	return (b);
}
