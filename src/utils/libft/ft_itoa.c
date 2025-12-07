/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:04:16 by rdinis            #+#    #+#             */
/*   Updated: 2025/11/13 15:11:57 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_len(long n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = n * -1;
	}
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*res;
	size_t		len;
	long		nbr;

	nbr = n;
	len = get_len(nbr);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	if (nbr < 0)
	{
		res[0] = '-';
		nbr *= -1;
	}
	res[len] = '\0';
	len--;
	while (nbr > 9)
	{
		res[len] = (nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
	res[len] = nbr + '0';
	return (res);
}
