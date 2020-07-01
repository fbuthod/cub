#include "includes/cub3d.h"

void gest_error(t_data *img, int code_erreur)
{
    int i;

    i = -1;
    if (code_erreur != 0)
    {
        mlx_destroy_window(img->mlx, img->mlx_win);
        mlx_destroy_image(img->mlx, img->img);
        ft_memdel((void *)&(img->sp_order));
        ft_memdel((void *)&(img->sp_dist));
        ft_memdel((void *)&(img->east));
        ft_memdel((void *)&(img->north));
        ft_memdel((void *)&(img->south));
        ft_memdel((void *)&(img->west));
        ft_memdel((void *)&(img->sprite));
        ft_memdel((void *)&(img->zbuffer));
    }
    if (code_erreur > 0 && code_erreur < 7)
        printf("Error\nTexture invalide");
    if (code_erreur > 1)
        mlx_destroy_image(img->mlx, img->img_no_ptr);
    if (code_erreur > 2)
        mlx_destroy_image(img->mlx, img->img_so_ptr);
    if (code_erreur > 3)
        mlx_destroy_image(img->mlx, img->img_we_ptr);
    if (code_erreur > 4)
        mlx_destroy_image(img->mlx, img->img_ea_ptr);
    if (code_erreur > 5)
        mlx_destroy_image(img->mlx, img->sprite_ptr);
	i = -1;
    if (img->worldMap != NULL)
        while (img->worldMap[++i])
            ft_memdel((void*)&img->worldMap[i]);
    ft_memdel((void*)&img->worldMap);
    exit(1);
}