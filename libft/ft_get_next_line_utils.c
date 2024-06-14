/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aershova <aershova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:23:46 by aershova          #+#    #+#             */
/*   Updated: 2024/02/01 20:06:35 by aershova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_gnl(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*copy;

	len = ft_strlen(s1);
	i = 0;
	copy = (char *)malloc(len + 1);
	if (copy)
	{
		while (i < len)
		{
			*(copy + i) = *(s1 + i);
			i++;
		}
		*(copy + i) = '\0';
	}
	else
		return (NULL);
	return (copy);
}

char	*ft_strchr_buff(const char *buff, int c)
{
	size_t	i;

	i = 0;
	while (buff + i && *(buff + i))
	{
		if (*(buff + i) == (char)c)
			return ((char *)buff + i);
		i++;
	}
	if (!(char)c)
		return ((char *)buff + i);
	return (NULL);
}
