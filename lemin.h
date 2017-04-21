/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 04:37:35 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/21 04:39:19 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

#include "./libft/includes/libft.h"
# include "./get_next_line.h"

typedef struct		s_tubes
{
	struct s_block	*content;
	struct s_tubes	*next;
}					t_tubes;

typedef struct		s_block
{
	int				id;
	char			*name;
	int				ant;
	int				weight;
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
t_block				*find_closest(t_block *b, t_block *goal);
void				init_block_ant(t_block *b, int n);
void				init_block_check(t_block *b, int n);
void				erase_block(t_block *b);
int					init_block_weight(t_block *b);
char				*generate_operation(char *name, int ant);
void				follow_the_weights(t_block *b);
int					it_is_finish(t_block *b);
int					have_tube_empty(t_block *b);
t_block				*next_usable_block(t_block *b);

#endif
