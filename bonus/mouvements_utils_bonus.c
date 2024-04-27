/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:45:22 by ihajouji          #+#    #+#             */
/*   Updated: 2024/04/20 16:52:24 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1);
	s2 = malloc (len + 1);
	if (s2 == NULL)
		return (NULL);
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int	number_len(int n)
{
	int	length;

	length = 0;
	if (n == 0)
		length = 1;
	if (n < 0)
		length++;
	while (n != 0)
	{
		length++;
		n /= 10;
	}
	length++;
	return (length);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;	

	len = number_len(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	result = malloc(sizeof(char) * len);
	if (!result)
		return (NULL);
	if (n < 0)
	{
		result [0] = '-';
		n *= -1;
	}
	result[len - 1] = '\0';
	while (n != 0)
	{
		len--;
		result[len - 1] = n % 10 + 48;
		n /= 10;
	}
	return (result);
}
