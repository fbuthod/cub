#include "includes/cub3d.h"

/*static void	ft_exit_next(t_data *img)
{
	int i;

	i = -1;
	ft_memdel((void *)&(img->sp_order));
	ft_memdel((void *)&(img->sp_dist));
	ft_memdel((void *)&(img->east));
	ft_memdel((void *)&(img->north));
	ft_memdel((void *)&(img->south));
	ft_memdel((void *)&(img->west));
	ft_memdel((void *)&(img->sprite));
	if (img->tracked > 7)
		ft_memdel((void *)&(img->zbuffer));
	ft_memdel((void*)&img->tmp_map);
	if (img->tab_color != NULL)
		while (img->tab_color[++i])
			ft_memdel((void*)&img->tab_color[i]);
	ft_memdel((void *)&(img->tab_color));
	i = -1;
	if (img->map != NULL)
		while (img->map[++i])
			ft_memdel((void*)&img->map[i]);
	ft_memdel((void*)&img->map);
}*/

void		exit_texture(t_data *img)
{
	/*if (img->tracked > 0)
		mlx_destroy_window(img->mlx, img->mlx_win);
	if (img->tracked > 1)
	{
		ft_putstr("Error\nIncorrect texture path...\n");
		mlx_destroy_image(img->mlx, img->img_ptr);
		if (img->tracked > 2 && img->img_no_ptr != 0)
			mlx_destroy_image(img->mlx, img->img_no_ptr);
		if (img->tracked > 3 && img->img_so_ptr != 0)
			mlx_destroy_image(img->mlx, img->img_so_ptr);
		if (img->tracked > 4 && img->img_ea_ptr != 0)
			mlx_destroy_image(img->mlx, img->img_ea_ptr);
		if (img->tracked > 5 && img->img_we_ptr != 0)
			mlx_destroy_image(img->mlx, img->img_we_ptr);
		if (img->tracked > 6 && img->sprite_ptr != 0)
			mlx_destroy_image(img->mlx, img->sprite_ptr);
	}
	ft_exit_next(img);
	exit(1);*/
	//return (0);
}