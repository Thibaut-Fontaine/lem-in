/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 04:37:35 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/13 06:57:31 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "./get_next_line.h"
# include <stdio.h>

typedef struct		s_block
{
	int				id;
	char			*name;
	t_list			*tubes;
	struct s_block	*nxt;
}					t_block;

typedef struct
{
	int				ant;
	t_block			*cur;
}					t_infos;

t_infos				parser(void);
void				error(void);

#endif
