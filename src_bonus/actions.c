/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:23:12 by aershova          #+#    #+#             */
/*   Updated: 2024/06/12 12:08:54 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/fractal.h"

/* abs sqr or dist */
long double	dist_sqr(t_fractal z)
{
	return (z.re * z.re + z.im * z.im);
}

void	print_info(void)
{
	ft_putstr_fd("Name: Julia, Mandelbrot\n", 1);
	ft_putstr_fd("examples:\n", 1);
	ft_putstr_fd("./fractol_bonus Julia -0.8 0.156\n", 1);
	ft_putstr_fd("./fractol_bonus Julia -2 0.1\n", 1);
	ft_putstr_fd("./fractol_bonus Julia -0.123 0.745\n", 1);
	ft_putstr_fd("./fractol_bonus Mandelbrot\n", 1);
	ft_putstr_fd("./fractol_bonus Nova\n", 1);
	ft_putstr_fd("./fractol_bonus Newton\n", 1);
	ft_putstr_fd("./fractol_bonus Ship\n", 1);
}

void	close_window(t_window *window)
{
	int	res;

	res = mlx_destroy_window(window->mlx, window->self);
	exit(res);
}

void	handle_key(int key, t_window *window, void (*f)(void *))
{
	if (key == KEY_ESCAPE)
	{
		write(1, "ESCAPE\n", 7);
		close_window(window);
	}
	else if (key == KEY_UP)
		f = move_up;
	else if (key == KEY_DOWN)
		f = move_down;
	else if (key == KEY_R)
		f = move_right;
	else if (key == KEY_L)
		f = move_left;
	else
		return ;
	mlx_clear_window(window->mlx, window->self);
	f(&window->params);
	render((t_size){X_WINDOW, Y_WINDOW}, window);
	mlx_put_image_to_window(window->mlx, window->self,
		window->data.img.self, 0, 0);
}

void	mouse_func(int mouse, int x, int y, t_window *window)
{
	void	(*f)(void *);

	f = NULL;
	window->params.mouse_x = x;
	window->params.mouse_y = y;
	if (mouse == MOUSE_SCROLL_UP)
		f = zoom_out;
	else if (mouse == MOUSE_SCROLL_DOWN)
		f = zoom_in;
	else if (mouse == MOUSE_CLICK)
		f = switch_color;
	else
		return ;
	mlx_clear_window(window->mlx, window->self);
	if (mouse == 1)
		f(&window->fractal);
	else
		f(&window->params);
	render((t_size){X_WINDOW, Y_WINDOW}, window);
	mlx_put_image_to_window(window->mlx, window->self,
		window->data.img.self, 0, 0);
}
