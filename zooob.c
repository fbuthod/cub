	while (img.x < img.sWidth)
	{
		ray_pos_dir(&img);
		step_side_distance(&img);
		DDA_algorithm(&img);
		fisheye_adjustment(&img);
		if (img.rayDirX > 0)
		{
			if (img.rayDirY < 0)
			{
				if (img.side == 0) //Vertical
					img.side_hited = 'W';
				else
					img.side_hited = 'S';
			}
			else
			{
				if (img.side == 0) // vertical
					img.side_hited = 'W';
				else
					img.side_hited = 'N';
			}
		}
		if (img.rayDirY < 0)
		{
			if (img.side == 0)
				img.side_hited = 'E';
			else
				img.side_hited = 'S';
		}
		else if (img.rayDirY > 0)
		{
			if (img.side == 0)
				img.side_hited = 'E';
			else
				img.side_hited = 'N';
		}
		else
			img.side_hited = 'Z';
		height_wall(&img);
		fill_stripe(&img);
		while (img.drawStart < img.drawEnd)
		{
			*(img.addr + ((img.sWidth) * img.drawStart) + img.x) = img.color;
			img.drawStart++;
		}
		img.x++;
		img.mapX = (int)img.posX;
		img.mapY = (int)img.posY;
	}
	img.x = 0;