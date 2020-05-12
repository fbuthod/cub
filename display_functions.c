/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 04:45:44 by ksam              #+#    #+#             */
/*   Updated: 2020/03/13 20:07:29 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	ray_pos_dir(t_data *img)
{
    img->cameraX = (2 * img->x) / (double)img->sWidth - 1;
    img->rayDirX = img->dirX + img->planeX * img->cameraX;
    img->rayDirY = img->dirY + img->planeY * img->cameraX;
}

void	case_detect(t_data *img)
{
	img->mapX = (int)(img->posX);
    img->mapY = (int)(img->posY);
}

void	ray_len(t_data *img)
{
	img->deltaDistX = fabs(1 / img->rayDirX);
    img->deltaDistY = fabs(1 / img->rayDirY);
	img->hit = 0;
}