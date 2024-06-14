/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:26:00 by aershova          #+#    #+#             */
/*   Updated: 2024/05/21 02:24:08 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include "../mlx/mlx.h"
# include "errors.h"
# include "edges.h"
# include "window.h"
# include "events.h"
# include "../libft/libft.h"

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		print_error_and_exit(char *msg_error, int n_error);
int			handle_input(int key, void *param);
long double	dist_sqr(t_fractal z);
void		render(t_size size, t_window *window);
void		calc_scale(long double *data, long double *pxy, t_window *window);
long double	iterate_julia(void *params, long double x, long double y);
long double	iterate_mandel(void *params, long double x, long double y);
long double	iterate_newton(void *params, long double x, long double y);
long double	iterate_nova(void *params, long double x, long double y);
long double	iterate_ship(void *params, long double x, long double y);

#endif
