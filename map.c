/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 17:54:50 by askochen          #+#    #+#             */
/*   Updated: 2017/06/26 17:54:55 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		new_map(char **str, t_settings *set)
{
	int		i;
	int		j;

	calculate_dimensional(set, *str);
	free(*str);
	get_next_line(0, str);
	free(*str);
	set->map = (char**)malloc(sizeof(char*) * (set->map_height));
	i = 0;
	while (i < set->map_height)
	{
		set->map[i] = (char*)malloc(sizeof(char) * (set->map_width + 1));
		get_next_line(0, str);
		j = 0;
		while (j < set->map_width)
		{
			set->map[i][j] = (*str)[j + 4];
			++j;
		}
		set->map[i][j] = '\0';
		free(*str);
		++i;
	}
	new_mass_map(set);
}

void		new_mass_map(t_settings *set)
{
	int		i;
	int		j;

	i = 0;
	set->mass = (int**)malloc(set->map_height * sizeof(int*));
	while (i < set->map_height)
	{
		set->mass[i] = (int*)malloc(set->map_width * sizeof(int));
		j = 0;
		while (j < set->map_width)
		{
			set->mass[i][j] = MAX_MASS;
			++j;
		}
		++i;
	}
}

void		rewrite_map(char **str, t_settings *set)
{
	int		i;
	int		j;

	free(*str);
	get_next_line(0, str);
	free(*str);
	i = 0;
	while (i < set->map_height)
	{
		j = 0;
		get_next_line(0, str);
		while (j < set->map_width)
		{
			if (set->map[i][j] != (*str)[j + 4])
				set->map[i][j] = (*str)[j + 4];
			++j;
		}
		free(*str);
		++i;
	}
}

void		get_figure(char **str, t_settings *set)
{
	int		i;

	get_next_line(0, str);
	calculate_figure_dimensional(set, *str);
	free(*str);
	i = sizeof(char*) * (set->fig_height);
	set->figure = (char**)malloc(i);
	i = 0;
	while (i < set->fig_height)
	{
		get_next_line(0, str);
		set->figure[i] = ft_strdup(*str);
		free(*str);
		++i;
	}
	get_new_fig_param(set);
}

void		cut_figure(t_settings *set, int old_row_num)
{
	char	**new_fig;
	int		i;
	int		j;

	new_fig = (char**)malloc(sizeof(char*) * set->fig_height);
	i = 0;
	while (i < set->fig_height)
	{
		j = 0;
		new_fig[i] = (char*)malloc(sizeof(char) * (set->fig_width + 1));
		while (j < set->fig_width)
		{
			new_fig[i][j] = set->figure[i][j];
			++j;
		}
		new_fig[i++][j] = '\0';
	}
	i = 0;
	while (i < old_row_num)
	{
		free(set->figure[i]);
		++i;
	}
	free(set->figure);
	set->figure = new_fig;
}
