#include "includes/cub3d.h"

static void	texture_no(t_data *img)
{
	if (img->side == 1)
		img->wallx = img->posY + img->perpWallDist * img->rayDirY;
	else
		img->wallx = img->posX + img->perpWallDist * img->rayDirX;
	img->wallx -= floor((img->wallx));
	img->tex_x = (int)(img->wallx * (double)img->no_width);
	if (img->side == 0 && img->rayDirY > 0)
		img->tex_x = img->no_width - img->tex_x - 1;
	if (img->side == 1 && img->rayDirX < 0)
		img->tex_x = img->no_width - img->tex_x - 1;
	img->step = 1.0 * img->no_height / img->lineHeight;
	img->texpos = (img->drawStart - img->sHeight / 2 + img->lineHeight / 2)
	* img->step;
}

static void	texture_so(t_data *img)
{
	if (img->side == 1)
		img->wallx = img->posY + img->perpWallDist * img->rayDirY;
	else
		img->wallx = img->posX + img->perpWallDist * img->rayDirX;
	img->wallx -= floor((img->wallx));
	img->tex_x = (int)(img->wallx * (double)img->so_width);
	if (img->side == 0 && img->rayDirY > 0)
		img->tex_x = img->so_width - img->tex_x - 1;
	if (img->side == 1 && img->rayDirX < 0)
		img->tex_x = img->so_width - img->tex_x - 1;
	img->step = 1.0 * img->so_height / img->lineHeight;
	img->texpos = (img->drawStart - img->sHeight / 2 + img->lineHeight / 2)
	* img->step;
}

static void	texture_we(t_data *img)
{
	if (img->side == 1)
		img->wallx = img->posY + img->perpWallDist * img->rayDirY;
	else
		img->wallx = img->posX + img->perpWallDist * img->rayDirX;
	img->wallx -= floor((img->wallx));
	img->tex_x = (int)(img->wallx * (double)img->we_width);
	if (img->side == 0 && img->rayDirY > 0)
		img->tex_x = img->we_width - img->tex_x - 1;
	if (img->side == 1 && img->rayDirX < 0)
		img->tex_x = img->we_width - img->tex_x - 1;
	img->step = 1.0 * img->we_height / img->lineHeight;
	img->texpos = (img->drawStart - img->sHeight / 2 + img->lineHeight / 2)
	* img->step;
}

static void	texture_ea(t_data *img)
{
	if (img->side == 1)
		img->wallx = img->posY + img->perpWallDist * img->rayDirY;
	else
		img->wallx = img->posX + img->perpWallDist * img->rayDirX;
	img->wallx -= floor((img->wallx));
	img->tex_x = (int)(img->wallx * (double)img->ea_width);
	if (img->side == 0 && img->rayDirY > 0)
		img->tex_x = img->ea_width - img->tex_x - 1;
	if (img->side == 1 && img->rayDirX < 0)
		img->tex_x = img->ea_width - img->tex_x - 1;
	img->step = 1.0 * img->ea_height / img->lineHeight;
	img->texpos = (img->drawStart - img->sHeight / 2 + img->lineHeight / 2)
	* img->step;
}

void		texture(t_data *img)
{
	img->lol = 1;
	if (img->side == 1 && img->stepX < 0)
		texture_ea(img);
	if (img->side == 1 && img->stepX >= 0)
		texture_we(img);
	if (img->side == 0 && img->stepY <= 0)
		texture_so(img);
	if (img->side == 0 && img->stepY > 0)
		texture_no(img);
}
