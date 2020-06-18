#include "includes/cub3d.h"

static void	init_texture_next(t_data *img)
{
	img->img_we_ptr = mlx_xpm_file_to_image(img->mlx, img->west,
		&img->we_width, &img->we_height);
	img->data_we = (int *)mlx_get_data_addr(img->img_we_ptr,
		&img->bits_per_pixel, &img->size_line, &img->endian);
	img->img_ea_ptr = mlx_xpm_file_to_image(img->mlx,
		img->east, &img->ea_width, &img->ea_height);
	img->data_ea = (int *)mlx_get_data_addr(img->img_ea_ptr,
		&img->bits_per_pixel, &img->size_line, &img->endian);
}

void		init_texture(t_data *img)
{
	img->img_no_ptr = mlx_xpm_file_to_image(img->mlx,
		img->north, &img->no_width, &img->no_height);
	img->data_no = (int *)mlx_get_data_addr(img->img_no_ptr,
		&img->bits_per_pixel, &img->size_line, &img->endian);
	img->img_so_ptr = mlx_xpm_file_to_image(img->mlx,
		img->south, &img->so_width, &img->so_height);
	img->data_so = (int *)mlx_get_data_addr(img->img_so_ptr,
		&img->bits_per_pixel, &img->size_line, &img->endian);
	init_texture_next(img);
}

