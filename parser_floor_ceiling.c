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

void       floor_fill(t_data *img, char *line)
{
    t_color	color;
	int i;

	i = 0;
    color.argb[3] = 0;
    while(!ft_isdigit(line[i]))
        i++;
    color.argb[0] = ft_atoi(line + i);
    while(ft_isdigit(line[i]))
        i++;
    i++;
    color.argb[1] = ft_atoi(line + i);
    while (ft_isdigit(line[i]))
        i++;
    i++;
    color.argb[2] = ft_atoi(line + i);
    img->color_floor = color.color;
}

void       ceiling_fill(t_data *img, char *line)
{
    t_color	color;
	int i;

	i = 0;
    color.argb[3] = 0;
	while(!ft_isdigit(line[i]))
        i++;
    color.argb[0] = ft_atoi(line + i);
    while(ft_isdigit(line[i]))
        i++;
    i++;
    color.argb[1] = ft_atoi(line + i);
    while (ft_isdigit(line[i]))
        i++;
    i++;
    color.argb[2] = ft_atoi(line + i);
    img->color_ceiling = color.color;
}