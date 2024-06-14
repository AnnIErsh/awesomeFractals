/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:05:09 by aershova          #+#    #+#             */
/*   Updated: 2024/05/21 03:22:13 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/fractal.h"

void	init_image(t_image *image, void **mlx_ptr, t_size size, char *name)
{
	image->self = mlx_new_image(*mlx_ptr, size.x, size.y);
	if (!image->self)
		print_error_and_exit(MSG_ERROR_IMAGE_INIT, ERROR_IMAGE_INIT);
	image->fract_name = name;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	make_color3(long double iter, int type)
{
	int	c1;
	int	c2;
	int	c3;
	int	color;

	color = 0xFCBE11;
	if (type == 9)
		return (create_trgb(0, iter, 255 - iter, (int)iter % 50 * 3));
	if (type == 10)
	{
		c1 = 9 * (1 - iter) * iter * iter * iter * 255;
		return (color * (int)iter * c1);
	}
	if (type == 11)
		return (((iter / 255 + 0.8) - floor(iter / 255 + 0.8)) * color);
	c2 = 9 * (1 - iter) * iter * iter * iter * 255;
	c3 = 8.5 * (1 - iter) * (1 - iter) * (1 - iter) * iter * 255;
	return (color * create_trgb(0, c2, c3, c3));
}

int	make_color2(long double iter, int type)
{
	int	c1;
	int	color;

	color = 0xFCBE11;
	if (type == 7)
		return (color * create_trgb(color * (int)iter, color * (int)iter,
				color * (int)iter, color * (int)iter));
	if (type == 8)
	{
		c1 = 9 * (1 - iter) * iter * iter * iter * 255;
		return (c1 * create_trgb(0, c1 + iter, iter, c1 * iter));
	}
	return (make_color3(iter, type));
}

int	make_color(long double iter, int type)
{
	int	color;

	color = 0xFCBE11;
	if (type == 0)
		return (color * (int)iter % 150);
	if (type == 2)
		return ((create_trgb(0, 2, 0, (int)(iter) % 10 * (int)iter % 200)
			* (int)iter));
	if (type == 3)
	{
		color *= create_trgb(0, (int)(iter) % 10 * (int)iter % 200, 0, 2);
		return (color);
	}
	if (type == 4)
		return (create_trgb(iter, iter, iter, iter));
	if (type == 5)
		return (create_trgb(0, color * (int)iter % 200,
				color * (int)iter, color * (int)iter));
	if (type == 6)
		return (create_trgb(0, 155, 200, color * (int)iter));
	return (make_color2(iter, type));
}
