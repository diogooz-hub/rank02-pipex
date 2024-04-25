/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaco <dpaco@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:34:20 by dpaco             #+#    #+#             */
/*   Updated: 2023/05/03 00:04:44 by dpaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int	check;
	int	count;

	check = 0;
	if (n < 0)
		n = -n;
	if (n == 0)
	{
		count = 1;
	}
	else
	{
		check = n;
		count = 0;
		while (check > 0)
		{
			check = check / 10;
			count++;
		}
	}
	return (count);
}

static int	ft_neg(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

static char	*ft_change(char *str, int n, int neg, int count)
{
	int	res;

	res = 0;
	str[count + neg] = '\0';
	while (n != 0)
	{
		res = n % 10;
		str[count - 1 + neg] = res + 48;
		n = n / 10;
		count--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		count;
	int		neg;
	char	*str;

	neg = ft_neg(n);
	count = ft_count(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (neg == 1)
		n = (n * -1);
	str = (char *)malloc((count + neg + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
	{
		str[count - 1] = '0';
		str[count] = '\0';
	}
	else
	{
		ft_change(str, n, neg, count);
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}
