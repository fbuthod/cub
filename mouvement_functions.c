/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:16:56 by ksam              #+#    #+#             */
/*   Updated: 2020/03/25 17:22:10 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void move(t_data *img)
{
    printf("%d\n", img->nb_down_key);
    if (img->nb_down_key >= 2)
        img->moveSpeed = img->moveSpeed / 2;
    else
        img->moveSpeed = 0.1;
    if (img->move_down == 1)
    {
        if(img->worldMap[(int)(img->posY - img->dirY * img->moveSpeed)][(int)(img->posX)] == '0')
            img->posY -= img->dirY * img->moveSpeed;
        if(img->worldMap[(int)(img->posY)][(int)(img->posX - img->dirX * img->moveSpeed)] == '0')
            img->posX -= img->dirX * img->moveSpeed;
    }
    if (img->move_up == 1)
    {
        if(img->worldMap[(int)(img->posY)][(int)(img->posX + img->dirX * img->moveSpeed)] == '0')
            img->posX += img->dirX * img->moveSpeed;
        if(img->worldMap[(int)(img->posY + img->dirY * img->moveSpeed)][(int)(img->posX)] == '0')
            img->posY += img->dirY * img->moveSpeed;
    }
    if (img->rotation_left == 1)
    {
        double oldDirX = img->dirX;
        img->dirX = img->dirX * cos(-img->rotSpeed) - img->dirY * sin(-img->rotSpeed);
        img->dirY = oldDirX * sin(-img->rotSpeed) + img->dirY * cos(-img->rotSpeed);
        double oldPlaneX = img->planeX;
        img->planeX = img->planeX * cos(-img->rotSpeed) - img->planeY * sin(-img->rotSpeed);
        img->planeY = oldPlaneX * sin(-img->rotSpeed) + img->planeY * cos(-img->rotSpeed);
    }
    if (img->rotation_right == 1)
    {
        double oldDirX = img->dirX;
        img->dirX = img->dirX * cos(img->rotSpeed) - img->dirY * sin(img->rotSpeed);
        img->dirY = oldDirX * sin(img->rotSpeed) + img->dirY * cos(img->rotSpeed);
        double oldPlaneX = img->planeX;
        img->planeX = img->planeX * cos(img->rotSpeed) - img->planeY * sin(img->rotSpeed);
        img->planeY = oldPlaneX * sin(img->rotSpeed) + img->planeY * cos(img->rotSpeed);
    }
    if (img->move_directional_left == 1)
    {
        if(img->worldMap[(int)(img->posY)][(int)(img->posX - img->planeX * img->moveSpeed)] == '0')
            img->posX -= img->planeX * img->moveSpeed;
        if(img->worldMap[(int)(img->posY - img->planeY * img->moveSpeed)][(int)(img->posX)] == '0')
            img->posY -= img->planeY * img->moveSpeed;
    }
    if (img->move_directional_right == 1)
    {
        if(img->worldMap[(int)(img->posY)][(int)(img->posX - img->planeX * img->moveSpeed)] == '0')
            img->posX += img->planeX * img->moveSpeed;
        if(img->worldMap[(int)(img->posY - img->planeY * img->moveSpeed)][(int)(img->posX)] == '0')
            img->posY += img->planeY * img->moveSpeed;
    }
}