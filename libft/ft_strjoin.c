/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaco <dpaco@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:49:40 by dpaco             #+#    #+#             */
/*   Updated: 2023/05/01 01:25:47 by dpaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	size1;
	size_t	size2;
	int		i;
	char	*s3;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	s3 = malloc((size1 + size2 + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		s3[size1 + i] = s2[i];
		i++;
	}
	s3[size1 + i] = '\0';
	return (s3);
}
