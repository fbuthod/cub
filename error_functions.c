/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 00:35:47 by ksam              #+#    #+#             */
/*   Updated: 2020/03/13 03:04:43 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	check_arg(int argc, char **argv)
{
	char *ptr;

	ptr = NULL;
	if (argc > 3)
	{
		ft_printf("Error\nToo many arguments.");
		return (-1);
	}
	if (argc < 2)
	{
		ft_printf("Error\nMap file missing.");
		return (-1);
	}
	if (argc == 2)
	{
		if ((ptr = ft_strrchr(argv[1], '.')))
		{
			if (find_cub_extension(ptr) != 0)
			{
				printf("Error\nWrong argument.");
				return (-1);
			}
		}
		else if (ft_strcmp(argv[1], "--save") == 0)
		{
			ft_printf("Error\nWrong argument.");
			return (-1);
		}
	}
	if (argc == 3)
	{
		if ((ptr = ft_strrchr(argv[2], '.')))
		{
			if (find_cub_extension(ptr) != 0)
			{
				printf("Error\nWrong argument.");
				return (-1);
			}
		}
		if (ft_strcmp(argv[1], "--save") == 0)
		{
			ft_printf("Error\nWrong argument.");
			return (-1);
		}
	}
	return (0);
}

int find_cub_extension(char *target)
{
	if (ft_strlen(target) != 4)
		return (-1);
	if (target[0] != '.')
		return (-1);
	if (target[1] != 'c' && target[1] != 'C')
		return (-1);
	if (target[2] != 'u' && target[2] != 'U')
		return (-1);
	if (target[3] != 'b' && target[3] != 'B')
		return (-1);
	return (0);
}