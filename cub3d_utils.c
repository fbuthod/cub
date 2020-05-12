/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:19:50 by ksam              #+#    #+#             */
/*   Updated: 2020/03/13 21:01:34 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int		close_window(t_data *data)
{
    mlx_destroy_window(data->mlx, data->mlx_win);
    exit(1);
    return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void	ft_img_dark(t_data *img)
{
	int	i;
	int	j;
	j = -1;
	img->color = 0x000000;
	while (++j < img->sHeight)
	{
		i = -1;
		while (++i < img->sWidth)
			my_mlx_pixel_put(img, i, j, img->color);
	}
}