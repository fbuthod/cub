/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:51:43 by ksam              #+#    #+#             */
/*   Updated: 2020/03/13 23:02:01 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdlib.h> // exit
# include "../minilibx/mlx.h"
# include "../ft_printf/libft/libft.h"
# include "../ft_printf/include/libftprintf.h"
# include "../includes/get_next_line.h"
# include "key_linux.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <time.h>
# define CARDINAL = "NSEW"

typedef struct  s_data 
{
    void        *mlx;
    void        *mlx_win;
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;

    int         move_up;
	int         move_down;
	int         rotation_left;
	int         rotation_right;
	int         move_directional_left;
    int         move_directional_right;
    int         nb_down_key;

	int			x;
    double      posX;
    double      posY;
    double      dirX;
    double      dirY;
    double      planeX;
    double      planeY;
    double      time;
    double      oldTime;
    int         mapX;
    int         mapY;
    double      sideDistX;
    double      sideDistY;
    double      deltaDistX;
    double      deltaDistY;
    double      cameraX;
	double		rayposX;
	double		rayposY;
    double      rayDirX;
    double      rayDirY;
    double      perpWallDist;
    int         stepX;
    int         stepY;
    int         hit;
    int         side;
    int         lineHeight;
    int         drawStart;
    int         drawEnd;
    int         color;
    double 		moveSpeed;
    double 		rotSpeed;
    double 		frameTime;


	int			sWidth;
    int			sHeight;
    char		*path_to_north_texture;
    char		*path_to_south_texture;
    char		*path_to_west_texture;
    char		*path_to_east_texture;
    char		*path_to_sprite_texture;
    int			floor_color_R;
    int			floor_color_G;
    int			floor_color_B;
    int			ceiling_color_R;
    int			ceiling_color_G;
    int			ceiling_color_B;
    char		**worldMap;
    int			countLine;
	char		*cardinal;

	char		side_hited;

}				t_data;

//int		main();
int 	main(int ac, char **av);
void	test(t_data *img);
void	ft_img_dark(t_data *img);
void	move_directional_right(t_data *img);
void	move_directional_left(t_data *img);
void	fps_count(t_data *img);

// parser_functions
void	parser(t_data *img, char *av);
int		parsing_map(char *line, t_data *bag);
int		count_valid_char(char *line);
t_data	*floor_fill(t_data *bag, char *line);
t_data	*ceiling_fill(t_data *bag, char *line);
t_data	*no_texture_fill(t_data *bag, char *line);
t_data	*so_texture_fill(t_data *bag, char *line);
t_data	*we_texture_fill(t_data *bag, char *line);
t_data	*ea_texture_fill(t_data *bag, char *line);
t_data	*sprite_texture_fill(t_data *bag, char *line);
int		find_dot(char *line);
t_data	*resolution_fill(t_data *bag, char *line);
void	if_forest(t_data *bag, char *line);

//error functions
int	check_arg(int argc, char **argv);
int find_cub_extension(char *target);

//init functions
void	parse_init(t_data *img);
void	camera_init(t_data *bag);
void	display_init(t_data *img);
void	ft_init(t_data *img);
void	window_init(t_data *img);

//display functions
void	display(t_data *img);
void	setup_raytracer(t_data *img);
void	ray_pos_dir(t_data *img);
void	case_detect(t_data *img);
void	ray_len(t_data *img);
void	step_side_distance(t_data *img);
void	calcul_stepx(t_data *img);
void	calcul_stepy(t_data *img);
void	DDA_calculs(t_data *img);
void 	DDA_algorithm(t_data *img);
void	fisheye_adjustment(t_data *img);
void	height_wall(t_data *img);
void	fill_stripe(t_data *img);
void	print_wall(t_data *img);
void	color_wall(t_data *img);
void 	verLine(t_data *img);

//cub3d utils
int		close_window(t_data *data);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

int		event_key_up(int keycode, t_data *img);
int		event_key_down(int keycode, t_data *img);
void    event_key( int keycode, t_data *img, int code);
int    calculate(t_data *img);
void    move(t_data *img);

#endif
