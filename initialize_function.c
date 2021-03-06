/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_function.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:20:50 by ksam              #+#    #+#             */
/*   Updated: 2020/03/13 22:33:43 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	ft_init(t_data *img)
{
    img->mlx = 0;
	img->x = 0;
	img->i = 0;
    img->mapX = 0;
    img->mapY = 0;
    img->sideDistX = 0;
    img->sideDistY = 0;
    img->deltaDistX = 0;
    img->deltaDistY = 0;
    img->cameraX = 0;
	img->rayposX = 0;
	img->rayposY = 0;
    img->rayDirX = 0;
    img->rayDirY = 0;
    img->perpWallDist = 0;
    img->stepX = 0;
    img->stepY = 0;
    img->hit = 0;
    img->side = 0;
    img->lineHeight = 0;
    img->drawStart = 0;
    img->drawEnd = 0;
    img->color = 0;

    img->frameTime = 0;
	img->time = 0;
    img->oldTime = 0;
	
	img->planeX = 0.66;
    img->planeY = 0;
	img->moveSpeed = 0.05;
    img->rotSpeed = 0.1;

	img->side_hited = 0;

	img->nb_down_key = 0;
	img->move_up = 0;
	img->move_down = 0;
	img->rotation_left = 0;
	img->rotation_right = 0;
	img->move_directional_left = 0;
    img->move_directional_right = 0;
	img->south = NULL;
	img->north = NULL;
	img->east = NULL;
	img->west = NULL;
	img->sprite = NULL;
	img->texWidth = -1;
	img->texHeight = -1;
	img->tracked = 0;

	img->sp_width = 0;
	img->sp_height = 0;
	img->sp_nbr = 5;

	img->screenshot = 0;

}

void	parse_init(t_data *img)
{
	img->floor_color_R = 0;
	img->floor_color_G = 0;
	img->floor_color_B = 0;
	img->ceiling_color_R = 0;
	img->ceiling_color_G = 0;
	img->ceiling_color_B = 0;
	img->worldMap = NULL;
	img->countLine = -1;
	img->cardinal = NULL;
}

void	camera_init(t_data *bag)
{
	int	i;
	int	ret;

	i = 0;
	ret = -1;
	if (bag->worldMap != NULL)
	{
		if (bag->dir_player == 'N')
			{
				bag->dirX = 0;
				bag->dirY = -1;
				bag->planeX = 0.66;
				bag->planeY = 0.0;
			}
		if (bag->dir_player == 'S')
			{
				bag->dirX = 0;
				bag->dirY = 1;
				bag->planeX = -0.66;
				bag->planeY = 0.0;
			}
		if (bag->dir_player == 'E')
			{
				bag->dirX = 1;
				bag->dirY = 0;
				bag->planeX = 0.0;
				bag->planeY = 0.66;
			}
		if (bag->dir_player == 'W')
			{
				bag->dirX = -1;
				bag->dirY = 0;
				bag->planeX = 0.0;
				bag->planeY = -0.66;
			}
		if (bag->cardinal != NULL)
		{
			bag->posY = (double)i;
			ret = ft_strichr(bag->worldMap[i], bag->cardinal[0]);
			if (ret != -1)
				bag->posX = (double)ret;
			bag->worldMap[i][ret] = '0';
		}
	}
}

void	window_init(t_data *img)
{
	img->mlx = mlx_init();
    img->mlx_win = mlx_new_window(img->mlx, img->sWidth, img->sHeight, "Cub3D");
    img->img = mlx_new_image(img->mlx, img->sWidth, img->sHeight);
    img->addr = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}

void		alloc_sprite_order(t_data *img)
{
	img->sp_order = (int *)malloc(sizeof(int) * (img->sp_nbr + 1));
	img->sp_dist = (double *)malloc(sizeof(double) * (img->sp_nbr + 1));
	img->sp_order[img->sp_nbr] = '\0';
	img->sp_dist[img->sp_nbr] = '\0';
}