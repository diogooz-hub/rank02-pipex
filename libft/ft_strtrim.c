/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaco <dpaco@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:53:02 by dpaco             #+#    #+#             */
/*   Updated: 2023/05/01 02:22:26 by dpaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *to_remove)
{
	size_t	start;
	size_t	end;
	size_t	i;
	size_t	len;
	char	*s1_copy;

	start = 0;
	while (s1[start] != '\0' && ft_strchr(to_remove, s1[start]) != NULL)
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(to_remove, s1[end - 1]) != NULL)
		end--;
	len = end - start;
	s1_copy = (char *)malloc((len + 1) * sizeof(char));
	if (!s1_copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s1_copy[i] = s1[start + i];
		i++;
	}
	s1_copy[i] = '\0';
	return (s1_copy);
}
