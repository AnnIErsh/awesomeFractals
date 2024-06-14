/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:26:42 by aershova          #+#    #+#             */
/*   Updated: 2024/05/21 03:02:51 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"

void	compute_next_ship(t_fractal *number, t_fractal curr, t_fractal c)
{
	long double	z_re;
	long double	z_im;

	z_re = curr.re * curr.re - curr.im * curr.im;
	z_im = 2 * curr.re * curr.im;
	*number = (t_fractal){z_re - c.re, fabsl(z_im) - c.im, curr.type};
}

long double	iterate_seq_ship(t_fractal z_0, t_fractal c, t_params params)
{
	t_fractal	z_n;
	long double	smooth;
	int			i;

	z_n = z_0;
	i = 0;
	while (dist_sqr(z_n) < params.r && i < params.max_i)
	{
		compute_next_ship(&z_n, z_n, c);
		i++;
	}
	smooth = (long double)i - log2(fmax(1.0f, log2(sqrt(dist_sqr(z_n)))));
	return (smooth);
}

long double	iterate_ship(void *params, long double x, long double y)
{
	t_window	*window;
	t_fractal	zero_fractal;
	t_fractal	curr_fractal;
	long double	pxy[2];
	long double	data[2];

	window = (t_window *)params;
	zero_fractal = (t_fractal){0.0, 0.0, window->fractal.type};
	data[0] = x;
	data[1] = y;
	calc_scale(data, pxy, window);
	curr_fractal = (t_fractal){pxy[0], pxy[1], window->fractal.type};
	return (iterate_seq_ship(zero_fractal, curr_fractal, window->params));
}
