/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 04:36:40 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/21 09:04:48 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lemin.h"

int				main(void)
{
	t_infos		info;

	info = parser();
	init_block_ant(info.cur, 0);
	init_block_weight(info.cur);
	while (it_is_finish(info.cur) == 0)
	{
		follow_the_weights(info.cur);
		ft_putchar('\n');
	}
	return (0);
}
