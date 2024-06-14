/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edges.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:50:44 by aershova          #+#    #+#             */
/*   Updated: 2024/05/21 03:14:13 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDGES_H
# define EDGES_H

# define X_WINDOW 500.00
# define Y_WINDOW 500.00
# define RE -0.8
# define IM 0.156
/*sqrt(3) / 2*/
# define COS_PI_6  0.866025403784439

typedef struct s_size
{
	float	x;
	float	y;
}	t_size;

void	set_size(t_size *size, float new_x, float new_y);
t_size	new_size(float x, float y);

#endif