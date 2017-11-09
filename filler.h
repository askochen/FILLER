/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 16:39:12 by askochen          #+#    #+#             */
/*   Updated: 2017/06/26 16:39:15 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define MAX_MASS  100000
# include "libft/libft.h"
# include "get_next_line.h"
# include <stdlib.h>

typedef struct	s_settings
{
	int			map_width;
	int			map_height;
	char		**map;
	int			**mass;
	int			fig_width;
	int			fig_height;
	char		**figure;
	char		player_s;
	char		enemy_s;
}				t_settings;

t_settings		*ft_init_settings(char *str);
void			new_map(char **str, t_settings *settings);
void			new_mass_map(t_settings *set);
void			rewrite_map(char **str, t_settings *settings);
void			get_figure(char **str, t_settings *settings);
void			get_new_fig_param(t_settings *set);
void			cut_figure(t_settings *set, int old_row_num);
void			calculate_map_mass(t_settings *settings);
void			calculate_curent_mass(t_settings *set, int i_m, int j_m);
int				c_s(t_settings *set, char fig_s, char map_s, int *i);
int				check_position(t_settings *set, int i_m, int j_m);
int				find_best_pos(t_settings *set, int *best_i, int *best_j);
void			print_position(t_settings *settings);
int				get_new_width(t_settings *settings);
int				get_new_height(t_settings *settings);
void			calculate_dimensional(t_settings *set, char *str);
void			calculate_figure_dimensional(t_settings *set, char *str);
int				get_mass(int i, int j, int i1, int j1);
void			free_figure(t_settings *settings);
void			free_settings(t_settings *settings);
void			set_player_to_o(t_settings *settings);
void			set_player_to_x(t_settings *settings);
void			init_int_to_zero(int *a, int *b, int *c);
#endif
