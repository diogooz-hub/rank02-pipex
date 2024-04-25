/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaco <dpaco@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:40:37 by dpaco             #+#    #+#             */
/*   Updated: 2023/05/01 01:30:43 by dpaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*temp;

	if (lst == NULL)
		return (0);
	else
	{
		temp = lst;
		count = 0;
		while (temp != NULL)
		{
			count++;
			temp = temp->next;
		}
		return (count);
	}
}
