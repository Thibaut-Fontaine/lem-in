/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 04:36:40 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/22 05:40:45 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lemin.h"

int				main(void)
{
	t_infos		info;

	info = parser();
	ft_sprint(1);
	ft_putchar('\n');
	init_block_ant(info.cur, 0);
	init_block_weight(info.cur);
	while (it_is_finish(info.cur) == 0)
	{
		follow_the_weights(info.cur);
		ft_putchar('\n');
	}
	return (0);
}
