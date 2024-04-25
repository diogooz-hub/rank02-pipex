/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaco <dpaco@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 00:54:06 by dpaco             #+#    #+#             */
/*   Updated: 2023/05/01 01:29:45 by dpaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	str_len;
	size_t	i;

	str_len = ft_strlen(str);
	if (!str)
		return (NULL);
	if (start >= str_len)
		return (ft_strdup(""));
	if (start + len > str_len)
		len = str_len - start;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[start + i] != '\0' && i < len)
	{
		ptr[i] = str[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
