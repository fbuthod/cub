/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:22:41 by ksam              #+#    #+#             */
/*   Updated: 2020/03/25 16:42:49 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "includes/cub3d.h"

void	fps_count(t_data *img)
{
	char	*fps;

	fps = NULL;
	img->oldTime = img->time;
	img->time = clock();
	img->frameTime = (img->time - img->oldTime) / 1000000;
	if (img->frameTime > 0)
		fps = ft_itoa( 1.0 / img->frameTime);
	mlx_string_put(img->mlx, img->mlx_win, 25, 25, 0x000000, "FPS :");
	mlx_string_put(img->mlx, img->mlx_win, 66, 25, 0x000000, fps);
}

int main(int ac, char **av)
{
    t_data	img;

    ft_init(&img);
	if (check_arg(ac, av) != 0)
		return (0);
    parser(&img, av[1]);
	window_init(&img);
	camera_init(&img);
	display(&img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	fps_count(&img);
    mlx_hook(img.mlx_win, 2, 1L, event_key_down, &img);
	mlx_hook(img.mlx_win, 3, 2L, event_key_up, &img);
	mlx_loop(img.mlx);
    return (0);
}
