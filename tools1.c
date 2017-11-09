/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 18:29:32 by askochen          #+#    #+#             */
/*   Updated: 2017/07/05 18:29:39 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		set_player_to_o(t_settings *settings)
{
	settings->player_s = 'O';
	settings->enemy_s = 'X';
}

void		set_player_to_x(t_settings *settings)
{
	settings->player_s = 'X';
	settings->enemy_s = 'O';
}

void		init_int_to_zero(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
}
