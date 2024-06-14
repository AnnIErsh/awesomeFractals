/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_zoom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 03:06:16 by aershova          #+#    #+#             */
/*   Updated: 2024/05/21 03:22:43 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/fractal.h"

void	zoom_out(void *params)
{
	t_params	*tmp;
	long double	d_x;
	long double	d_y;

	tmp = (t_params *)params;
	d_x = (tmp->re_max - tmp->re_min) / (long double)X_WINDOW;
	d_y = (tmp->im_max - tmp->im_min) / (long double)Y_WINDOW;
	if (tmp->max_i >= 100)
		tmp->max_i -= 1;
	tmp->re_min -= (d_x * tmp->mouse_x * 0.2);
	tmp->re_max += (d_x * ((long double)X_WINDOW - tmp->mouse_x) * 0.2);
	tmp->im_min -= (d_y * ((long double)Y_WINDOW - tmp->mouse_y) * 0.2);
	tmp->im_max += (d_y * tmp->mouse_y * 0.2);
}

void	zoom_in(void *params)
{
	t_params	*tmp;
	long double	d_x;
	long double	d_y;

	tmp = (t_params *)params;
	d_x = (tmp->re_max - tmp->re_min) / (long double)X_WINDOW;
	d_y = (tmp->im_max - tmp->im_min) / (long double)Y_WINDOW;
	tmp->max_i += 1;
	tmp->re_min += (d_x * tmp->mouse_x * 0.2);
	tmp->re_max -= (d_x * ((long double)X_WINDOW - tmp->mouse_x) * 0.2);
	tmp->im_min += (d_y * ((long double)Y_WINDOW - tmp->mouse_y) * 0.2);
	tmp->im_max -= (d_y * tmp->mouse_y * 0.2);
}
