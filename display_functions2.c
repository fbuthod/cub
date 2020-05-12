/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_functions2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 04:26:01 by ksam              #+#    #+#             */
/*   Updated: 2020/03/13 20:22:09 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void DDA_algorithm(t_data *img)
{
	while (img->hit == 0)
	{
		if (img->sideDistX < img->sideDistY)
		{
			img->sideDistX += img->deltaDistX;
			img->mapX += img->stepX;
			img->side = 0;
		}
		else
		{
			img->sideDistY += img->deltaDistY;
			img->mapY += img->stepY;
			img->side = 1;
		}
		if (img->worldMap[img->mapY][img->mapX] > '0')
			img->hit = 1;
	}
}

void	fisheye_adjustment(t_data *img)
{
    if (img->side == 0)
        img->perpWallDist = ((img->mapX - img->posX +
				(1 - img->stepX) / 2) / img->rayDirX);
    else
        img->perpWallDist = ((img->mapY - img->posY +
                (1 - img->stepY) / 2) / img->rayDirY);
}

void	height_wall(t_data *img)
{
	img->lineHeight = (int)(img->sHeight / img->perpWallDist);
}
void	fill_stripe(t_data *img)
{
    img->drawStart = (-img->lineHeight / 2) + (img->sHeight / 2);
    if(img->drawStart < 0)
        img->drawStart = 0;
    img->drawEnd = (img->lineHeight / 2) + (img->sHeight / 2);
    if(img->drawEnd >= img->sHeight)
        img->drawEnd = img->sHeight - 1;
}