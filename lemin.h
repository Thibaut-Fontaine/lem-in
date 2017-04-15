/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 04:37:35 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/15 17:42:08 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "./get_next_line.h"
# include <stdio.h> //

typedef struct		s_block t_block;
typedef struct		s_tubes t_tubes;

typedef struct		s_tubes
{
	t_block			*content;
	t_tubes			*next;
}					t_tubes;

typedef struct		s_block
{
	int				id;
	char			*name;
	t_tubes			*tubes;
	t_block			*nxt;
}					t_block;

typedef struct
{
	int				ant;
	t_block			*cur;
}					t_infos;

t_infos				parser(void);
int					error(void);
t_block				*find_block_name(t_block *b, char *name);
int					find_block_id(t_block *b, int id);
void				fill_tube(t_block *b, char *name1, char *name2);

#endif
