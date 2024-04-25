/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaco <dpaco@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:52:51 by dpaco             #+#    #+#             */
/*   Updated: 2023/05/01 01:34:06 by dpaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *base, const char *find, size_t n)
{
	size_t	i;
	size_t	fi;

	if (*find == '\0')
	{
		return ((char *)base);
	}
	i = 0;
	while (base[i] != '\0' && i < n)
	{
		fi = 0;
		while (base[i + fi] == find[fi] && (i + fi) < n)
		{
			if (find[fi + 1] == '\0')
			{
				return ((char *)(base + i));
			}
			fi++;
		}
		i++;
	}
	return (NULL);
}
