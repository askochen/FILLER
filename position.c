/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 16:40:25 by askochen          #+#    #+#             */
/*   Updated: 2017/06/26 16:40:31 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		print_position(t_settings *settings)
{
	int		i;
	int		j;
	int		mass;

	i = 0;
	j = 0;
	mass = find_best_pos(settings, &i, &j);
	if (mass != MAX_MASS)
	{
		ft_putnbr(i);
		ft_putchar(' ');
		ft_putnbr(j);
		ft_putchar('\n');
	}
	else
		ft_putstr("0 0\n");
}

void		get_new_fig_param(t_settings *set)
{
	int		old_row_num;
	int		width;
	int		height;

	old_row_num = set->fig_height;
	width = get_new_width(set);
	height = get_new_height(set);
	set->fig_width = width;
	set->fig_height = height;
	cut_figure(set, old_row_num);
}

int			get_new_width(t_settings *settings)
{
	int new_val;
	int i;

	new_val = settings->fig_width;
	while (--new_val >= 0)
	{
		i = 0;
		while (i < settings->fig_height)
		{
			if (settings->figure[i][new_val] == '*')
				return (new_val + 1);
			++i;
		}
	}
	return (0);
}

int			get_new_height(t_settings *settings)
{
	int new_val;
	int i;

	new_val = settings->fig_height;
	while (--new_val >= 0)
	{
		i = 0;
		while (i < settings->fig_width)
		{
			if (settings->figure[new_val][i] == '*')
				return (new_val + 1);
			++i;
		}
	}
	return (0);
}

int			c_s(t_settings *set, char fig_s, char map_s, int *inter)
{
	if (fig_s != '*')
		return (0);
	if (map_s == set->enemy_s || map_s == set->enemy_s + 32)
		return (-1);
	if (map_s == set->player_s || map_s == set->player_s + 32)
		++(*inter);
	return (1);
}
