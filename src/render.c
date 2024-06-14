/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:36:26 by aershova          #+#    #+#             */
/*   Updated: 2024/05/21 03:01:39 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"

/* Zn^2 */
void	compute_next(t_fractal *number, t_fractal curr, t_fractal c)
{
	long double	z_re;
	long double	z_im;

	z_re = curr.re * curr.re - curr.im * curr.im;
	z_im = 2 * curr.re * curr.im;
	*number = (t_fractal){z_re + c.re, z_im + c.im, curr.type};
}

/*
	seq of element until dist exceeds threshold or
	max iterations is reached 
	r_2 == 2 * 2;
*/
long double	iterate_seq(t_fractal z_0, t_fractal c, t_params params)
{
	t_fractal	z_n;
	long double	smooth;
	int			i;

	z_n = z_0;
	i = 0;
	while (dist_sqr(z_n) < params.r && i < params.max_i)
	{
		compute_next(&z_n, z_n, c);
		i++;
	}
	if (z_n.type == 1 || z_n.type == 0)
		return (i);
	if (z_n.type != 8 && (i == 2 || i == 0))
		return (0);
	smooth = (long double)i - log2(fmax(1.0f, log2(sqrt(dist_sqr(z_n)))));
	return (smooth);
}

long double	iterate_mandel(void *params, long double x, long double y)
{
	t_window	*window;
	t_fractal	zero_fractal;
	t_fractal	curr_fractal;
	long double	pxy[2];
	long double	data[2];

	window = (t_window *)params;
	data[0] = x;
	data[1] = y;
	calc_scale(data, pxy, window);
	zero_fractal = (t_fractal){0, 0, window->fractal.type};
	curr_fractal = (t_fractal){pxy[0], pxy[1], window->fractal.type};
	return (iterate_seq(zero_fractal, curr_fractal, window->params));
}

long double	iterate_julia(void *params, long double x, long double y)
{
	t_window	*window;
	t_fractal	curr_fractal;
	long double	pxy[2];
	long double	data[2];

	window = (t_window *)params;
	data[0] = x;
	data[1] = y;
	calc_scale(data, pxy, window);
	curr_fractal = (t_fractal){pxy[0], pxy[1], window->fractal.type};
	return (iterate_seq(curr_fractal, window->fractal, window->params));
}

void	render(t_size size, t_window *window)
{
	long double	x;
	long double	y;
	long double	iter;

	y = 0;
	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			iter = window->func(window, x, y);
			my_mlx_pixel_put(&window->data, x, y,
				make_color(iter, window->fractal.type));
			x++;
		}
		y++;
	}
}
/*
		printf("sclae x %Lf, scale y: %Lf\n", scale_x, scale_y);
		printf("iter x: %d\n", window->params.max_i);
		----Colors for type == 8 ----

		//return (c1 * create_trgb(0, c1 + iter, 0, c1 * iter));
		//return (c1 * create_trgb(c1 * iter, c1, 0, c1 ));
		//return (c1 * create_trgb(color, c1 * iter, color * iter, c1 * iter));
		//return (create_trgb(color, c1 * iter, color * iter, c1 * iter));
		//return (create_trgb(0, c1 * iter, c1 * iter, c1 * iter));
		//return (create_trgb(0, c1, color * iter, c1));
		//return ( create_trgb(0, 9 * (1 - iter) * iter * iter * iter * 255,
					color * (int)iter, color * (int)iter));
		//return (int)(create_trgb(iter, iter , iter, 0xFCBE11))%255;
		//return  (color * create_trgb(20,0xFCBE11,iter,200));
		//return(color * (int)iter*c1);

	type = 4
		//color *= create_trgb(iter, iter, iter, iter);
*/
