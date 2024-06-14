/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:24:18 by aershova          #+#    #+#             */
/*   Updated: 2024/05/21 03:22:07 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/fractal.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= X_WINDOW || y >= Y_WINDOW)
		return ;
	dst = data->addr + (y * data->l + x * (data->bit / 8));
	*(unsigned int *)dst = color;
}

void	print_error_and_exit(char *msg_error, int n_error)
{
	perror(msg_error);
	print_info();
	exit(n_error);
}

t_size	new_size(float x, float y)
{
	t_size	size;

	size.x = x;
	size.y = y;
	return (size);
}

void	set_size(t_size *size, float new_x, float new_y)
{
	size->x = new_x;
	size->y = new_y;
}

/*
	data[0] --- x 
	data[1] --- y
*/

void	calc_scale(long double *data, long double *pxy, t_window *window)
{
	long double	scale_x;
	long double	scale_y;

	scale_x = (window->params.re_max - window->params.re_min)
		/ (long double)(X_WINDOW - 1);
	scale_y = (window->params.im_max - window->params.im_min)
		/ (long double)(Y_WINDOW - 1);
	pxy[0] = window->params.re_min + (data[0] * scale_x);
	pxy[1] = window->params.im_max - (data[1] * scale_y);
}
