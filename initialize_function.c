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
	img->south = "./texture/bluestone.xpm";
	img->north = "./texture/eagle.xpm";
	img->east = "./texture/greystone.xpm";
	img->west = "./texture/redbrick.xpm";
	img->sprite = NULL;
	img->texWidth = -1;
	img->texHeight = -1;
	img->tracked = 0;
}

void	parse_init(t_data *img)
{
	img->path_to_north_texture = NULL;
	img->path_to_south_texture = NULL;
	img->path_to_west_texture = NULL;
	img->path_to_east_texture = NULL;
	img->path_to_sprite_texture = NULL;
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
		while (bag->worldMap[i])
		{
			if ((bag->cardinal = ft_strchr(bag->worldMap[i], 'N')))
				{
					bag->dirX = 0;
					bag->dirY = -1;
					bag->planeX = 0.66;
					bag->planeY = 0.0;
					break ;
				}
			if ((bag->cardinal = ft_strchr(bag->worldMap[i], 'S')))
				{
					bag->dirX = 0;
					bag->dirY = 1;
					bag->planeX = -0.66;
					bag->planeY = 0.0;
					break ;
				}
			if ((bag->cardinal = ft_strchr(bag->worldMap[i], 'E')))
				{
					bag->dirX = 1;
					bag->dirY = 0;
					bag->planeX = 0.0;
					bag->planeY = 0.66;
					break ;
				}
			if ((bag->cardinal = ft_strchr(bag->worldMap[i], 'W')))
				{
					bag->dirX = -1;
					bag->dirY = 0;
					bag->planeX = 0.0;
					bag->planeY = -0.66;
					break ;
				}
			i++;
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
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
								&img->line_length, &img->endian);
}

void	init_colors(t_data *img)
{
	t_color	color;

	color.argb[3] = 0;

	color.argb[0] = -78;
	color.argb[1] = 34;
	color.argb[2] = 34;
	img->color_floor = color.color;
	
	color.argb[0] = -16;
	color.argb[1] = -128;
	color.argb[2] = -128;
	img->color_ceiling = color.color;
}