/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 04:36:40 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/21 08:10:44 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lemin.h"

int				main(void)
{
	t_infos		info;

	info = parser();
	init_block_ant(info.cur, 0);
	while (it_is_finish(info.cur) == 0)
	{
		follow_the_weights(info.cur);
		ft_putchar('\n');
	}
	return (0);
}
