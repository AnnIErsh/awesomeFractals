/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 00:57:50 by aershova          #+#    #+#             */
/*   Updated: 2024/05/21 03:22:22 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/fractal.h"

void	compute_next_newton(t_fractal *number, t_fractal curr, t_fractal c)
{
	long double	z_re;
	long double	z_im;

	z_re = coshl(curr.re) * cosl(curr.im);
	z_im = sinhl(curr.re) * sinl(curr.im);
	*number = (t_fractal){z_re + c.re, z_im + c.im, curr.type};
}

long double	iterate_seq_newton(t_fractal z_0, t_fractal root, t_params params)
{
	t_fractal	z_n;
	int			i;
	long double	smooth;

	z_n = z_0;
	i = 0;
	while (dist_sqr(z_n) < 16 && i < params.max_i)
	{
		compute_next_newton(&z_n, z_n, root);
		if (fabsl(z_n.re) < 0.01)
			break ;
		i++;
	}
	smooth = (long double)i - log2(fmax(1.0f, log2(sqrt(dist_sqr(z_n)))));
	return (smooth);
}

long double	iterate_newton(void *params, long double x, long double y)
{
	t_window	*window;
	t_fractal	fract;
	t_fractal	root;
	long double	pxy[2];
	long double	data[2];

	window = (t_window *)params;
	data[0] = x;
	data[1] = y;
	calc_scale(data, pxy, window);
	fract = (t_fractal){pxy[0], pxy[1], window->fractal.type};
	root = (t_fractal){-1, 0, window->fractal.type};
	return (iterate_seq_newton(fract, root, window->params));
}
