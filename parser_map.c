/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 01:13:06 by ksam              #+#    #+#             */
/*   Updated: 2020/03/09 23:30:57 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include <stdio.h>

int		parsing_map(char *line, t_data *bag)
{
	size_t i;

	bag->countLine += 1;
	bag->worldMap = ft_realloc(bag->worldMap, sizeof(char*) * (bag->countLine + 1));
	i = count_valid_char(line);
	if (i != ft_strlen(line))
	{
		ft_putstr_fd("Wrong char on map", 2);
		return (0);
	}
	else
		bag->worldMap[bag->countLine] = ft_strdup(line);
	return (0);
}

int		count_valid_char(char *line)
{
	int i;

	i = 0;
	while (ft_isdigit(line[i]) || line[i] == ' ' || line[i] == 'N' ||
	line[i] == 'S' || line[i] == 'E' || line[i] == 'W' || line[i] == '\t')
		i++;
	return (i);
}