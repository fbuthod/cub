/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:48:46 by ksam              #+#    #+#             */
/*   Updated: 2020/03/09 01:07:31 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

t_data	*resolution_fill(t_data *bag, char *line)
{
	int i;

	i = 1;
    bag->sWidth = ft_atoi(line + i);
    i++;
    while (ft_isdigit(line[i]))
        i++;
    bag->sHeight = ft_atoi(line + i);
	return (bag);
}
