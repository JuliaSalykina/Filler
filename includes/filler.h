/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 22:08:57 by mannette          #+#    #+#             */
/*   Updated: 2020/06/17 07:34:15 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/libft.h"

typedef struct	s_board
{
	int			x_map;
	int			y_map;
	int			**map;
	int			x_p;
	int			y_p;
	char		**piece;
	char		**map2;
}				t_board;

typedef	struct	s_all
{
	int			fd;
	char		my_shape;
	char		enemy_shape;
	int			sum;
	int			x_start;
	int			y_start;
	int			x_coord;
	int			y_coord;
	t_board		board;
}				t_all;

void			ft_initialize(t_all *all);
int				ft_valid_players(t_all *all);
int				ft_words_len(char *line);
int				ft_read_info(t_all *all);
int				ft_create_map(t_all *all);
int				ft_map(t_all *all, char *line, int res);
int				ft_piece(t_all *all, char *line, int res, int i);
int				ft_heat(t_all *all);
int				ft_find_coord(t_all *all);
void			print_coordinate(t_all *all);
int				ft_free_line(char *line);
void			ft_free_map(t_all *all);
void			ft_free_char(char **arr);

#endif
