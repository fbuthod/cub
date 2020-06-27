/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:13:42 by ksam              #+#    #+#             */
/*   Updated: 2020/03/13 01:16:09 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	parser(t_data *img, char *av)
{
	int		fd;
    int		ret;
    char	*line;
    
    ret = -1;
	parse_init(img);
    fd = open(av, O_RDONLY);
    while (ret != 0)
    {
        ret = get_next_line(fd, &line);
        if_forest(img, line);
        free(line);
    }
	img->worldMap[img->countLine + 1] = NULL;
    close(fd);
}

void	if_forest(t_data *img, char *line)
{
	int i;

	i = 0;
    if (line[i] == 'R')
        img = resolution_fill(img, line);
    else if (line[i] == 'N' && line[i + 1] == 'O')
        img = no_texture_fill(img, line);
    else if (line[i] == 'S' && line[i + 1] == 'O')
        img = so_texture_fill(img, line);
    else if (line[i] == 'W' && line[i + 1] == 'E')
        img = we_texture_fill(img, line);
    else if (line[i] == 'E' && line[i + 1] == 'A')
        img = ea_texture_fill(img, line);
    else if (line[i] == 'S' && line[i + 1] != 'O')
        img = sprite_texture_fill(img, line);
    else if (line[i] == 'F' || line[i] == 'C')
        img = (line[i] == 'F') ? floor_fill(img, line) : ceiling_fill(img, line);
    else if (ft_isdigit(line[i]) || line[i] == ' ' || line[i] == '\t')
        parsing_map(line, img);
}
