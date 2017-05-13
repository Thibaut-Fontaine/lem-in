/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 04:36:40 by tfontain          #+#    #+#             */
/*   Updated: 2017/05/13 17:36:12 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lemin.h"

int				main(void)
{
	t_infos		info;

	info = parser();
	ft_putchar('\n');
	init_block_ant(info.cur, 0);
	init_block_weight(info.cur);
	if (find_block_id(info.cur, 1)->weight == 0)
		error();
	ft_sprint(PRINT_FILE);
	while (it_is_finish(info.cur) == 0)
	{
		follow_the_weights(info.cur);
		ft_putnstr_fdr(ft_sget(PRINT_SOLUTION),
				ft_strlen(ft_sget(PRINT_SOLUTION)) - 1, STDOUT_FILENO);
		*ft_sget(PRINT_SOLUTION) = 0;
		ft_putchar('\n');
	}
	return (0);
}
