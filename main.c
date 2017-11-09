/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 16:39:50 by askochen          #+#    #+#             */
/*   Updated: 2017/06/26 16:39:57 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			main(int argc, char **argv)
{
	t_settings	*settings;
	int			counter;
	char		*str;

	(void)argc;
	counter = 0;
	settings = ft_init_settings(argv[0]);
	while (get_next_line(0, &str))
	{
		if (counter == 0)
			new_map(&str, settings);
		else
			rewrite_map(&str, settings);
		get_figure(&str, settings);
		calculate_map_mass(settings);
		print_position(settings);
		free_figure(settings);
		++counter;
	}
	free_settings(settings);
	return (0);
}
