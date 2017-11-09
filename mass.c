/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mass.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 16:40:09 by askochen          #+#    #+#             */
/*   Updated: 2017/06/26 16:40:14 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_settings	*ft_init_settings(char *name)
{
	t_settings	*settings;
	char		*str;

	get_next_line(0, &str);
	settings = (t_settings*)malloc(sizeof(t_settings));
	if (ft_strstr(str, name) && ft_strstr(str, "p1"))
		set_player_to_o(settings);
	else
		set_player_to_x(settings);
	free(str);
	return (settings);
}

void		calculate_map_mass(t_settings *set)
{
	int		i;
	int		j;
	int		val1;
	int		val2;

	i = 0;
	while (i < set->map_height)
	{
		j = 0;
		while (j < set->map_width)
		{
			val1 = set->map[i][j] == set->enemy_s;
			val2 = set->map[i][j] == (set->enemy_s + 32);
			if (val1 || val2)
				calculate_curent_mass(set, i, j);
			++j;
		}
		++i;
	}
}

void		calculate_curent_mass(t_settings *set, int i_m, int j_m)
{
	int		i;
	int		j;
	int		new_mass;

	set->mass[i_m][j_m] = 0;
	i = 0;
	while (i < set->map_height)
	{
		j = 0;
		while (j < set->map_width)
		{
			new_mass = get_mass(i, j, i_m, j_m);
			if (set->mass[i][j] > new_mass)
				set->mass[i][j] = new_mass;
			++j;
		}
		++i;
	}
}

int			find_best_pos(t_settings *set, int *best_i, int *best_j)
{
	int		i;
	int		j;
	int		mass;
	int		best_mass;

	best_mass = MAX_MASS;
	i = 0;
	while (i < set->map_height - set->fig_height)
	{
		j = 0;
		while (j < set->map_width - set->fig_width)
		{
			mass = check_position(set, i, j);
			if ((mass != -1 && best_mass > mass))
			{
				best_mass = mass;
				*best_i = i;
				*best_j = j;
			}
			++j;
		}
		++i;
	}
	return (best_mass);
}

int			check_position(t_settings *set, int i_m, int j_m)
{
	int		i;
	int		j;
	int		mass;
	int		is;
	int		r;

	init_int_to_zero(&is, &mass, &i);
	while (i < set->fig_height)
	{
		j = 0;
		while (j < set->fig_width)
		{
			r = c_s(set, set->figure[i][j], set->map[i + i_m][j + j_m], &is);
			if (r == -1 || is > 1)
				return (-1);
			if (r != 0)
				mass = mass + set->mass[i + i_m][j + j_m];
			++j;
		}
		++i;
	}
	if (is == 1)
		return (mass);
	return (-1);
}
