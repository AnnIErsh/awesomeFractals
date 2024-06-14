/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 12:53:35 by aershova          #+#    #+#             */
/*   Updated: 2024/02/18 16:11:29 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*tmp_1;
	unsigned char	*tmp_2;

	i = 0;
	tmp_1 = (unsigned char *)s1;
	tmp_2 = (unsigned char *)s2;
	while (tmp_1 + i && *(tmp_1 + i)
		&& tmp_2 + i && *(tmp_2 + i))
	{
		if (*(tmp_1 + i) == *(tmp_2 + i))
			i++;
		else
			break ;
	}
	return (*(tmp_1 + i) - *(tmp_2 + i));
}
