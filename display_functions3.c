/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_functions3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 05:59:36 by ksam              #+#    #+#             */
/*   Updated: 2020/03/25 17:18:22 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	color_wall(t_data *img)
{
	char i;

	i = img->worldMap[img->mapY][img->mapX];
	if (i == '1')
		img->color = 0x9E0E40;
	if (img->side == 1)
		img->color = img->color >> 2;
}
void	verLine(t_data *img)
{
	int y;

	y = img->drawStart;
	while (y < img->drawEnd)
	{
		my_mlx_pixel_put(img, img->x, y, img->color);
		y++;
	}

	if (img->drawEnd < 0)
		img->drawEnd = img->sHeight;
	
	y = img->drawEnd;
	while (y < img->sHeight)
	{
		my_mlx_pixel_put(img, img->x, y, 0xffff40);
		my_mlx_pixel_put(img, img->x, (img->sHeight - y - 1), 0x7eb6ff);
		y++;
	}
}
// void	color_wall(t_data *img)
// {
// 	if (img->side_hited == 'N')
// 		img->color = 4876733;
// 	else if (img->side_hited == 'S')
// 		img->color = 15412998;
// 	if (img->side_hited == 'E')
// 		img->color = 7921807;
// 	if (img->side_hited == 'W')
// 		img->color = 16169275;
// }

// void verLine(t_data *img)
// {
//     int y;
// 	int y_max;

//     if (img->drawEnd < img->drawStart)
//     {
// 		y = img->drawEnd;
// 		y_max = img->drawStart;
//     }
// 	else
// 	{
// 		y = img->drawStart;
// 		y_max = img->drawEnd;
// 	}
// 	if (y >= 0)
// 	{
// 		while (y < y_max)
// 		{
// 			my_mlx_pixel_put(img, img->x, y, img->color);
// 			y++;
// 		}
// 	}
// }