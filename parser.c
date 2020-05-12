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

void	if_forest(t_data *bag, char *line)
{
	int i;

	i = 0;
    if (line[i] == 'R')
        bag = resolution_fill(bag, line);
    else if (line[i] == 'N' && line[i + 1] == 'O')
        bag = no_texture_fill(bag, line);
    else if (line[i] == 'S' && line[i + 1] == 'O')
        bag = so_texture_fill(bag, line);
    else if (line[i] == 'W' && line[i + 1] == 'E')
        bag = we_texture_fill(bag, line);
    else if (line[i] == 'E' && line[i + 1] == 'A')
        bag = ea_texture_fill(bag, line);
    else if (line[i] == 'S' && line[i + 1] != 'O')
        bag = sprite_texture_fill(bag, line);
    else if (line[i] == 'F' || line[i] == 'C')
        bag = (line[i] == 'F') ? floor_fill(bag, line) : ceiling_fill(bag, line);
    else if (ft_isdigit(line[i]) || line[i] == ' ' || line[i] == '\t')
        parsing_map(line, bag);
}
