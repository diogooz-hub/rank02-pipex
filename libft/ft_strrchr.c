/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaco <dpaco@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 00:49:20 by dpaco             #+#    #+#             */
/*   Updated: 2023/05/01 00:49:42 by dpaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	int	size;

	size = ft_strlen(str);
	i = size - 1;
	if ((char)c == '\0')
		return ((char *)(str + size));
	while (i >= 0)
	{
		if (str[i] == (char)c)
		{
			return ((char *)(str + i));
		}
		i--;
	}
	return (NULL);
}
