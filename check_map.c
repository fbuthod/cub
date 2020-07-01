#include "includes/cub3d.h"

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

static void	ft_check_space_next_3(t_data *img, int i, int j)
{
	if (((i - 1) >= 0 && img->worldMap[i - 1] != '\0' && (int)ft_strlen(img->worldMap[i
		- 1]) >= j && img->worldMap[i - 1][j] == 'N') || ((j - 2) >= 0 && img->worldMap
		[i][j - 2] == 'N') || ((j + 2) <= (int)ft_strlen(img->worldMap[i]) &&
		img->worldMap[i][j + 2] == 'N') || (img->worldMap[i + 1] != '\0' && (int)
		ft_strlen(img->worldMap[i + 1]) >= j && img->worldMap[i + 1][j] == 'N'))
	{
		ft_putstr("Erreur de la map : un espace et un | N | ne peuvent pas ");
		ft_putstr("etre cote a cote...\n");
		gest_error(img, 0);
	}
	if (((i - 1) >= 0 && img->worldMap[i - 1] != '\0' && (int)ft_strlen(img->worldMap[i
		- 1]) >= j && img->worldMap[i - 1][j] == 'S') || ((j - 2) >= 0 && img->worldMap
		[i][j - 2] == 'S') || ((j + 2) <= (int)ft_strlen(img->worldMap[i]) &&
		img->worldMap[i][j + 2] == 'S') || (img->worldMap[i + 1] != '\0' && (int)
		ft_strlen(img->worldMap[i + 1]) >= j && img->worldMap[i + 1][j] == 'S'))
	{
		ft_putstr("Erreur de la map : un espace et un | S | ne peuvent pas ");
		ft_putstr("etre cote a cote...\n");
		gest_error(img, 0);
	}
}

static void	ft_check_space_next_2(t_data *img, int i, int j)
{
	if (((i - 1) >= 0 && img->worldMap[i - 1] != '\0' && (int)ft_strlen(img->worldMap[i
		- 1]) >= j && img->worldMap[i - 1][j] == 'W') || ((j - 2) >= 0 && img->worldMap
		[i][j - 2] == 'W') || ((j + 2) <= (int)ft_strlen(img->worldMap[i]) &&
		img->worldMap[i][j + 2] == 'W') || (img->worldMap[i + 1] != '\0' && (int)
		ft_strlen(img->worldMap[i + 1]) >= j && img->worldMap[i + 1][j] == 'W'))
	{
		ft_putstr("Erreur de la map : un espace et un | W | ne peuvent pas ");
		ft_putstr("etre cote a cote...\n");
		gest_error(img, 0);
	}
	if (((i - 1) >= 0 && img->worldMap[i - 1] != '\0' && (int)ft_strlen(img->worldMap[i
		- 1]) >= j && img->worldMap[i - 1][j] == '2') || ((j - 2) >= 0 && img->worldMap
		[i][j - 2] == '2') || ((j + 2) <= (int)ft_strlen(img->worldMap[i]) &&
		img->worldMap[i][j + 2] == '2') || (img->worldMap[i + 1] != '\0' && (int)
		ft_strlen(img->worldMap[i + 1]) >= j && img->worldMap[i + 1][j] == '2'))
	{
		ft_putstr("Erreur de la map : un espace et un | 2 | ne peuvent pas ");
		ft_putstr("etre cote a cote...\n");
		gest_error(img, 0);
	}
}

static void	ft_check_space_next(t_data *img, int i, int j)
{
	if (((i - 1) >= 0 && img->worldMap[i - 1] != '\0' && (int)ft_strlen(img->worldMap[i
		- 1]) >= j && img->worldMap[i - 1][j] == '0') || ((j - 2) >= 0 && img->worldMap
		[i][j - 2] == '0') || ((j + 2) <= (int)ft_strlen(img->worldMap[i]) &&
		img->worldMap[i][j + 2] == '0') || (img->worldMap[i + 1] != '\0' && (int)
		ft_strlen(img->worldMap[i + 1]) >= j && img->worldMap[i + 1][j] == '0'))
	{
		ft_putstr("Erreur de la map : un espace et un '0' ne peuvent pas ");
		ft_putstr("etre cote a cote...\n");
		gest_error(img, 0);
	}
	if (((i - 1) >= 0 && img->worldMap[i - 1] != '\0' && (int)ft_strlen(img->worldMap[i
		- 1]) >= j && img->worldMap[i - 1][j] == 'E') || ((j - 2) >= 0 && img->worldMap
		[i][j - 2] == 'E') || ((j + 2) <= (int)ft_strlen(img->worldMap[i]) &&
		img->worldMap[i][j + 2] == 'E') || (img->worldMap[i + 1] != '\0' && (int)
		ft_strlen(img->worldMap[i + 1]) >= j && img->worldMap[i + 1][j] == 'E'))
	{
		ft_putstr("Erreur de la map : un espace et un | E | ne peuvent pas ");
		ft_putstr("etre cote a cote...\n");
		gest_error(img, 0);
	}
}

void		ft_check_space(t_data *img, int i, int j)
{
	if (img->worldMap[i][j] == ' ' && (j - 1) == -1 && ((j + 1) <=
		(int)ft_strlen(img->worldMap[i]) && img->worldMap[i][j + 1] != ' '))
	{
		ft_putstr("Erreur de la map : il manque un espace ou des espaces ");
		ft_putstr("ne sont pas paires au debut...\n");
		gest_error(img, 0);
	}
	if (img->worldMap[i][j] == ' ' && (j - 1) == -1 && ((j + 1) <=
		(int)ft_strlen(img->worldMap[i]) && img->worldMap[i][j + 1] == ' '))
		img->worldMap[i][j] = '1';
	else if (img->worldMap[i][j] == ' ' && ((j - 1) >= 0 &&
		img->worldMap[i][j - 1] == ' ') && ((j + 1) <= (int)ft_strlen(img->worldMap[i])
		&& img->worldMap[i][j + 1] == ' '))
	{
		ft_check_space_next(img, i, j);
		ft_check_space_next_2(img, i, j);
		ft_check_space_next_3(img, i, j);
		img->worldMap[i][j] = '1';
	}
}

static void	ft_check_line_next(t_data *img, int i, int k)
{
	if (img->worldMap[i][k] == 'N' || img->worldMap[i][k] == 'E' ||
		img->worldMap[i][k] == 'W' || img->worldMap[i][k] == 'S')
	{
		if (++img->worldMap_false == 1)
			img->dir_player = img->worldMap[i][k];
		img->posX = (double)k;
		img->posY = (double)i;
	}
	if (img->worldMap[i][k] != '0' && img->worldMap[i][k] != '1' && img->
		worldMap[i][k] != '2' && img->worldMap[i][k] != 'N' && img->worldMap[i][k]
		!= 'S' && img->worldMap[i][k] != 'E' && img->worldMap[i][k] != 'W')
	{
		ft_putstr("Erreur de la map...\n");
		gest_error(img, 0);
	}
}

static void	ft_check_line(t_data *img, int i, int k)
{
	while (img->worldMap[i][k])
	{
		ft_check_line_next(img, i, k);
		if (img->worldMap[i][k] == 'N' || img->worldMap[i][k] == 'E' ||
			img->worldMap[i][k] == 'W' || img->worldMap[i][k] == 'S' ||
			img->worldMap[i][k] == '0' || img->worldMap[i][k] == '2')
		{
			if ((img->worldMap[i + 1] != '\0' && (int)ft_strlen(img->worldMap
			[i + 1]) <= k) || (img->worldMap[i - 1] != '\0' &&
			(int)ft_strlen(img->worldMap[i - 1]) <= k))
			{
				ft_putstr("Erreur de la map : a | 0 | 2 | N | S | E | W |");
				ft_putstr(" en dehort de la map...\n");
				gest_error(img, 0);
			}
		}
		if (img->worldMap[i][k++] == '2')
			img->sp_nbr++;
	}
	if (img->worldMap[i][k - 1] != '1')
	{
		ft_putstr("Erreur de la map : pas de '1' a la fin de la ligne...\n");
		gest_error(img, 0);
	}
}

static int	ft_all_line(t_data *img, int i, int k)
{
	i = 0;
	k = -1;
	while (img->worldMap[1][++k])
	{
		if (img->worldMap[1][k] == '0' && img->worldMap[0][k] != '1')
		{
			ft_putstr("Erreur de la map : manque un 1 au debut ");
			ft_putstr("de la ligne...\n");
			gest_error(img, 0);
		}
	}
	k = 0;
	while (img->worldMap[i])
	{
		if (img->worldMap[i][0] != '1')
		{
			ft_putstr("Erreur de la map : pas de 1 au ");
			ft_putstr("debut de la ligne...\n");
			gest_error(img, 0);
		}
		ft_check_line(img, i, k);
		k = 0;
		i++;
	}
	return (i);
}

static int	ft_check_map_error_next(t_data *img, int i, int j)
{
	while (img->worldMap[++i])
	{
		j = -1;
		while (img->worldMap[i][++j])
		{
			if (img->worldMap[i][j] == ' ' && img->worldMap[i][j + 1] == ' ')
			{
				ft_putstr("Erreur de la map : il manque un espace ou plusieurs ");
				ft_putstr("espaces...\n");
				gest_error(img, 0);
			}
		}
	}
	return (i);
}

int	ft_strcheck_chr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
			return (1);
		i++;
	}
	return (0);
}

void check_map(t_data *img)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (img->worldMap[i] != 0)
    {   
        j = 0;
        while (img->worldMap[i][j] != 0)
        {
            ft_check_space(img, i, j);
            j++;
        }
        i++;
    }
    i = 0;
    i = ft_check_map_error_next(img, i, j);
    i = ft_all_line(img, i, j);
    alloc_sprite_order(img);
    if (ft_strcheck_chr(img->worldMap[i - 1], '1') != 0 || img->worldMap_false != 1)
	{
		ft_putstr("Erreur de la map : pas de 1 a la fin de la ligne ||");
		ft_putstr(" plusieurs | N | S | W | E | dans la map...\n");
		gest_error(img, 0);
	}
}