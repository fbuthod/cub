/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_floor_ceiling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 02:14:23 by ksam              #+#    #+#             */
/*   Updated: 2020/03/09 01:07:31 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

t_data       *floor_fill(t_data *bag, char *line)
{
	int i;

	i = 0;
    while(!ft_isdigit(line[i]))
        i++;
    bag->floor_color_R = ft_atoi(line + i);
    while(ft_isdigit(line[i]))
        i++;
    i++;
    bag->floor_color_G = ft_atoi(line + i);
    while (ft_isdigit(line[i]))
        i++;
    i++;
    bag->floor_color_B = ft_atoi(line + i);
    return (bag);
}

t_data       *ceiling_fill(t_data *bag, char *line)
{
	int i;

	i = 0;
	while(!ft_isdigit(line[i]))
        i++;
    bag->ceiling_color_R = ft_atoi(line + i);
    while(ft_isdigit(line[i]))
        i++;
    i++;
    bag->ceiling_color_G = ft_atoi(line + i);
    while (ft_isdigit(line[i]))
        i++;
    i++;
    bag->ceiling_color_B = ft_atoi(line + i);
    return (bag);
}