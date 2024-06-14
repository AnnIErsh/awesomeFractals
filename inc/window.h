/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:41:48 by aershova          #+#    #+#             */
/*   Updated: 2024/05/21 03:16:12 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H
# define MLX_SYNC_WIN_FLUSH_CMD 2

typedef struct s_image
{
	void	*self;
	char	*fract_name;
}	t_image;

typedef struct s_data {
	t_image	img;
	char	*addr;
	int		bit;
	int		l;
	int		end;
}	t_data;

typedef struct s_params
{
	int			max_i;
	long double	r;
	long double	re_min;
	long double	re_max;
	long double	im_min;
	long double	im_max;
	long double	scale_x;
	long double	scale_y;
	long double	offset_x;
	long double	offset_y;
	long double	mouse_x;
	long double	mouse_y;
}	t_params;

typedef struct s_fractal
{
	long double	re;
	long double	im;
	int			type;
}	t_fractal;

typedef struct s_window
{
	void		*self;
	void		*mlx;
	char		*title;
	t_params	params;
	t_data		data;
	t_fractal	fractal;
	long double	(*func)(void *, long double, long double);
}	t_window;

void	close_window(t_window *window);
void	print_info(void);
void	handle_key(int key, t_window *window, void (*f)(void *));
void	mouse_func(int mouse, int x, int y, t_window *window);
int		create_trgb(int t, int r, int g, int b);
int		make_color(long double iter, int type);
void	move_right(void *params);
void	move_left(void *params);
void	move_up(void *params);
void	move_down(void *params);
void	zoom_in(void *params);
void	zoom_out(void *params);
void	switch_color(void *params);
void	init_image(t_image *image, void **mlx_ptr, t_size size, char *name);
void	destroy_image(t_image **image);

#endif
