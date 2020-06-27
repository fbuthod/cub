#include "includes/cub3d.h"

static void	bitmap_image(t_data *img, int fd, t_bpm2 bitinf)
{
	int				x;
	int				y;
	int				ble;
	unsigned char	color[3];

	write(fd, &bitinf, sizeof(bitinf));
	y = img->sHeight - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < img->sWidth)
		{
			ble = img->addr[y * img->sWidth + x];
			color[0] = ble % 256;
			ble /= 256;
			color[1] = ble % 256;
			ble /= 256;
			color[2] = ble % 256;
			write(fd, &color, 4);
			x++;
		}
		y--;
	}
	close(fd);
}

void		save_bitmap(char *filename, t_data *img)
{
	int		fd;
	t_bpm	bitheader;
	t_bpm2	bitinf;

	ft_memcpy(&bitheader.bitmap_type, "BM", 2);
	bitheader.file_size = img->sWidth * img->sHeight * 4 + 54;
	bitheader.reserved1 = 0;
	bitheader.reserved2 = 0;
	bitheader.offset_bits = 0;
	bitinf.size_header = sizeof(bitinf);
	bitinf.width = img->sWidth;
	bitinf.height = img->sHeight;
	bitinf.planes = 1;
	bitinf.bit_count = 32;
	bitinf.compression = 0;
	bitinf.image_size = img->sWidth * img->sHeight * 4 + 54;
	bitinf.ppm_x = 2;
	bitinf.ppm_y = 2;
	bitinf.clr_used = 0;
	bitinf.clr_important = 0;
	fd = open(filename, O_RDONLY | O_CREAT, S_IRWXU);
	close(fd);
	fd = open(filename, O_RDWR);
	write(fd, &bitheader, 14);
	bitmap_image(img, fd, bitinf);
}
