/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 00:32:23 by ksam              #+#    #+#             */
/*   Updated: 2020/03/25 14:56:32 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	display(t_data *img)
{
	img->x = 0;
    while (img->x < img->sWidth)
    {
        setup_raytracer(img);
        step_side_distance(img);
        DDA_calculs(img);
        print_wall(img);
		img->x++;
    }
}

void	setup_raytracer(t_data *img)
{
	ray_pos_dir(img);
	case_detect(img);
	ray_len(img);
}

void	step_side_distance(t_data *img)
{
	calcul_stepx(img);
	calcul_stepy(img);
}

void	DDA_calculs(t_data *img)
{
    DDA_algorithm(img);
    fisheye_adjustment(img);
    height_wall(img);
	fill_stripe(img);
}

void	print_wall(t_data *img)
{
	color_wall(img);
	verLine(img);
}