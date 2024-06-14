/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:41:08 by aershova          #+#    #+#             */
/*   Updated: 2024/05/21 03:22:47 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/fractal.h"

void	move_right(void *params)
{
	t_params	*tmp;
	long double	d_x;

	tmp = (t_params *)params;
	d_x = (tmp->re_max - tmp->re_min);
	tmp->re_max += d_x / 7.5;
	tmp->re_min += d_x / 7.5;
}

void	move_left(void *params)
{
	t_params	*tmp;
	long double	d_x;

	tmp = (t_params *)params;
	d_x = (tmp->re_max - tmp->re_min);
	tmp->re_max -= d_x / 7.5;
	tmp->re_min -= d_x / 7.5;
}

void	move_up(void *params)
{
	t_params	*tmp;
	long double	d_y;

	tmp = (t_params *)params;
	d_y = (tmp->im_max - tmp->im_min);
	tmp->im_min -= d_y / 7.5;
	tmp->im_max -= d_y / 7.5;
}

void	move_down(void *params)
{
	t_params	*tmp;
	long double	d_y;

	tmp = (t_params *)params;
	d_y = (tmp->im_max - tmp->im_min);
	tmp->im_min += d_y / 7.5;
	tmp->im_max += d_y / 7.5;
}

void	switch_color(void *params)
{
	t_fractal	*tmp;

	tmp = (t_fractal *)params;
	tmp->type += 1;
	if (tmp->type > 11)
		tmp->type = 0;
}
