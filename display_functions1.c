/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_functions1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 04:55:41 by ksam              #+#    #+#             */
/*   Updated: 2020/03/13 00:43:38 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	calcul_stepx(t_data *img)
{
	if (img->rayDirX < 0)
    {
        img->stepX = -1;
        img->sideDistX = (img->posX - img->mapX) * img->deltaDistX;
    }
    else
    {
        img->stepX = 1;
        img->sideDistX = (img->mapX + 1.0 - img->posX) * img->deltaDistX;
    }
}

void	calcul_stepy(t_data *img)
{
	if (img->rayDirY < 0)
    {
        img->stepY = -1;
        img->sideDistY = (img->posY - img->mapY) * img->deltaDistY;
    }
    else
    {
        img->stepY = 1;
        img->sideDistY = (img->mapY + 1.0 - img->posY) * img->deltaDistY;
    }
}