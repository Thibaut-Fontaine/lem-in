/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 04:36:40 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/21 04:37:00 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"
#include "./lemin.h"

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
	return (0);
}
