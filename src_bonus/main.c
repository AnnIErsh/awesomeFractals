/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:25:08 by aershova          #+#    #+#             */
/*   Updated: 2024/05/21 03:22:17 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/fractal.h"

void	window_params_init(t_params *params)
{
	params->max_i = 100;
	params->r = 4;
	params->re_min = -2;
	params->re_max = 2;
	params->im_min = -2;
	params->im_max = params->im_min + (params->re_max - params->re_min)
		* (long double)Y_WINDOW / (double)X_WINDOW;
	params->scale_x = (long double)4 / (long double)(X_WINDOW - 1);
	params->scale_y = (long double)4 / (long double)(Y_WINDOW - 1);
	params->offset_x = X_WINDOW;
	params->offset_y = Y_WINDOW;
	params->mouse_x = 0;
	params->mouse_y = 0;
}

void	fractal_c_init(t_window *window, char **argv)
{
	char	*c_re;
	char	*c_im;

	c_re = *(argv + 2);
	c_im = *(argv + 3);
	if (!ft_strcmp("-0.8", c_re) && !ft_strcmp("0.156", c_im))
		window->fractal = (t_fractal){-0.8, 0.156, 4};
	else if (!ft_strcmp("-2", c_re) && !ft_strcmp("0.1", c_im))
		window->fractal = (t_fractal){-2.00, 0.1, 2};
	else if (!ft_strcmp("-0.123", c_re) && !ft_strcmp("0.745", c_im))
		window->fractal = (t_fractal){-0.123, 0.745, 3};
	else
		print_error_and_exit(MSG_ERROR_JUL_PARAMS, ERROR_JUL_PARAMS);
}

void	define_fractal_type_and_render(t_window *window, char **argv, int n)
{
	if (!ft_strcmp("Julia", window->title) && n == 4)
	{
		fractal_c_init(window, argv);
		window->func = &iterate_julia;
		render((t_size){X_WINDOW, Y_WINDOW}, window);
		return ;
	}
	else if (n != 2)
		print_error_and_exit(MSG_ERROR_INV_FR_NAME, ERROR_INV_FR_NAME);
	if (!ft_strcmp("Mandelbrot", window->title))
		window->func = &iterate_mandel;
	else if (!ft_strcmp("Newton", window->title))
		window->func = &iterate_newton;
	else if (!ft_strcmp("Nova", window->title))
		window->func = &iterate_nova;
	else if (!ft_strcmp("Ship", window->title))
		window->func = &iterate_ship;
	else
		print_error_and_exit(MSG_ERROR_INV_FR_NAME, ERROR_INV_FR_NAME);
	render((t_size){X_WINDOW, Y_WINDOW}, window);
}

void	create_fractals(char *fractal, int argc, char **argv)
{
	t_window	window;
	t_size		img_size;
	t_data		data;

	window.mlx = mlx_init();
	window.self = mlx_new_window(window.mlx, X_WINDOW, Y_WINDOW, fractal);
	window_params_init(&window.params);
	img_size = new_size(X_WINDOW, Y_WINDOW);
	init_image(&data.img, window.mlx, img_size, fractal);
	data.addr = mlx_get_data_addr(data.img.self, &data.bit, &data.l, &data.end);
	window.data = data;
	window.title = fractal;
	if (argc != 4)
		window.fractal = (t_fractal){RE, IM, 2};
	define_fractal_type_and_render(&window, argv, argc);
	mlx_put_image_to_window(window.mlx, window.self, data.img.self, 0, 0);
	mlx_hook(window.self, KEY_DESTROY, 0, (void *)close_window, &window);
	mlx_mouse_hook(window.self, (void *)mouse_func, &window);
	mlx_key_hook(window.self, (void *)handle_key, &window);
	mlx_loop(window.mlx);
	mlx_destroy_image(window.mlx, window.data.img.self);
}

int	main(int argc, char **argv)
{
	if (argc >= 2 && argc <= 4)
		create_fractals(*(argv + 1), argc, argv);
	else
		print_info();
	return (0);
}
