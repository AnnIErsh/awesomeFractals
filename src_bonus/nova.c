/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nova.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 20:16:21 by aershova          #+#    #+#             */
/*   Updated: 2024/05/21 03:22:30 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/fractal.h"

void	compute_next_nova(t_fractal *number, t_fractal curr, t_fractal c)
{
	long double	z_re;
	long double	z_im;
	long double	temp_deno;
	long double	x2;
	long double	y2;

	x2 = curr.re * curr.re;
	y2 = curr.im * curr.im;
	temp_deno = 3 * (x2 + y2) * (x2 + y2);
	z_re = curr.re * 2.00 / 3.00 - (y2 - x2) / temp_deno;
	z_im = curr.im * 2.00 / 3.00 - (2.00 * curr.re * curr.im) / temp_deno;
	*number = (t_fractal){z_re + c.re, z_im + c.im, curr.type};
}

long double	smooth_result(t_fractal z_n, long double i)
{
	if (z_n.type == 1 || z_n.type == 0)
		return (i);
	if (z_n.type != 8 && (i == 2 || i == 0))
		return (0);
	return (i - log2(fmax(1.0f, log2(sqrt(dist_sqr(z_n))))));
}

long double	iterate_seq_nova(t_fractal z_0, t_fractal c, t_params params)
{
	t_fractal	z_n;
	int			i;
	t_fractal	root[3];

	root[0] = (t_fractal){-1, 0, z_0.type};
	root[1] = (t_fractal){-0.5, COS_PI_6, z_0.type};
	root[2] = (t_fractal){-0.5, COS_PI_6, z_0.type};
	z_n = z_0;
	i = 0;
	while (dist_sqr(z_n) < 4 && i < params.max_i)
	{
		compute_next_nova(&z_n, z_n, c);
		if (fabsl(z_n.re - root[0].re) == 0.000001
			&& fabsl(z_n.im - root[0].im) == 0.000001)
			break ;
		else if (fabsl(z_n.re - root[1].re) == 0.000001
			&& fabsl(z_n.im - root[1].im) == 0.000001)
			break ;
		else if (fabsl(z_n.re - root[2].re) == 0.000001
			&& fabsl(z_n.im - root[2].im) == 0.000001)
			break ;
		i++;
	}
	return (smooth_result(z_n, ((long double)i)));
}

long double	iterate_nova(void *params, long double x, long double y)
{
	t_window	*window;
	t_fractal	c;
	t_fractal	fract;
	long double	pxy[2];
	long double	data[2];

	window = (t_window *)params;
	data[0] = x;
	data[1] = y;
	calc_scale(data, pxy, window);
	c = (t_fractal){1, 0, window->fractal.type};
	fract = (t_fractal){pxy[0], pxy[1], window->fractal.type};
	return (iterate_seq_nova(c, fract, window->params));
}
