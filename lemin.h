/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 04:37:35 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/17 00:46:08 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "./get_next_line.h"
# include <stdio.h> //

typedef struct		s_tubes
{
	struct s_block	*content;
	struct s_tubes	*next;
}					t_tubes;

typedef struct		s_block
{
	int				id;
	char			*name;
	struct s_tubes	*tubes;
	struct s_block	*nxt;
}					t_block;

typedef struct		s_infos
{
	int				ant;
	struct s_block	*cur;
}					t_infos;

t_infos				parser(void);
int					error(void);
t_block				*find_block_name(t_block *b, char *name);
t_block				*find_block_id(t_block *b, int id);
void				fill_tube(t_block *b, char *name1, char *name2);

#endif
