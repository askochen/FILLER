/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 16:40:41 by askochen          #+#    #+#             */
/*   Updated: 2017/06/26 16:40:46 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		calculate_dimensional(t_settings *set, char *str)
{
	int		i;

	i = 0;
	while (!ft_isdigit(str[i]))
		i++;
	set->map_height = ft_atoi(str + i);
	while (ft_isdigit(str[i]))
		i++;
	set->map_width = ft_atoi(str + i + 1);
}

void		calculate_figure_dimensional(t_settings *set, char *str)
{
	int		i;

	i = 0;
	while (!ft_isdigit(str[i]))
		i++;
	set->fig_height = ft_atoi(str + i);
	while (ft_isdigit(str[i]))
		i++;
	set->fig_width = ft_atoi(str + i + 1);
}

int			get_mass(int i, int j, int i1, int j1)
{
	int v1;
	int v2;

	v1 = i - i1;
	v2 = j - j1;
	if (v1 < 0)
		v1 = v1 * -1;
	if (v2 < 0)
		v2 = v2 * -1;
	return (v1 + v2);
}

void		free_figure(t_settings *settings)
{
	int		i;

	i = 0;
	while (i < settings->fig_height)
	{
		free(settings->figure[i]);
		++i;
	}
	free(settings->figure);
}

void		free_settings(t_settings *settings)
{
	int		i;

	i = 0;
	while (i < settings->map_height)
	{
		free(settings->map[i]);
		free(settings->mass[i]);
		++i;
	}
	free(settings->map);
	free(settings->mass);
	free(settings);
}
