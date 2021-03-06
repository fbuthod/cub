/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:10:24 by ksam              #+#    #+#             */
/*   Updated: 2020/03/09 01:07:31 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

t_data		*no_texture_fill(t_data *bag, char *line)
{
	int i;

	i = find_dot(line);
	bag->north = ft_strdup(line + i);
	return (bag);
}

t_data		*so_texture_fill(t_data *bag, char *line)
{
	int i;

	i = find_dot(line);
	bag->south = ft_strdup(line + i);
	return (bag);
}

t_data		*we_texture_fill(t_data *bag, char *line)
{
	int i;

	i = find_dot(line);
	bag->west = ft_strdup(line + i);
	return (bag);
}

t_data		*ea_texture_fill(t_data *bag, char *line)
{
	int i;

	i = find_dot(line);
	bag->east = ft_strdup(line + i);
	return (bag);
}

t_data		*sprite_texture_fill(t_data *bag, char *line)
{
	int i;

	i = find_dot(line);
	bag->sprite = ft_strdup(line + i);
	return (bag);
}

int			find_dot(char *line)
{
	int i;

	i = 0;
	while(line[i] != '.')
	i++;
	return (i);
}