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
		img->color = 0xFF0000;
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

void	draw(t_data *img)
{
	if (img->side == 0)
		img->tex_y = img->stepY > 0 ? ((int)img->texpos &
			img->no_height - 1) :
		((int)img->texpos & img->so_height - 1);
	else if (img->side == 1)
		img->tex_y = img->stepX < 0 ? ((int)img->texpos &
			img->ea_height - 1) :
		((int)img->texpos & img->we_height - 1);
	if (img->side == 0)
		img->color = img->stepY > 0 ? img->data_no[img->no_height
			* img->tex_y + img->tex_x] :
			img->data_so[img->so_height * img->tex_y + img->tex_x];
	else if (img->side == 1)
	{
		if (img->ea_height * img->tex_y + img->tex_x <
			img->ea_height * img->ea_width)
		{
			img->color = img->stepX < 0 ?
				img->data_ea[img->ea_height * img->tex_y +
			img->tex_x] : img->data_we[img->we_height * img->tex_y
			+ img->tex_x];
		}
	}
	img->texpos += img->step;
}

void		draw_floor_ceiling(t_data *img)
{
	int		i;
	int		j;

	j = -1;
	i = -1;
	img->x = -1;
	while (++j < img->sHeight / 2)
	{
		i = -1;
		while (++i < img->sWidth)
			img->addr[j * img->sWidth + i] = img->color_ceiling;
	}
	while (j < img->sHeight)
	{
		i = -1;
		while (++i < img->sWidth)
			img->addr[j * img->sWidth + i] = img->color_floor;
		j++;
	}
}