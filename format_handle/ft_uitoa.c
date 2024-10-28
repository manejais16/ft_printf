/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzarins <kzarins@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:54:27 by kzarins           #+#    #+#             */
/*   Updated: 2024/10/28 20:04:37 by kzarins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "format_handle.h"

static char	get_space_qty(unsigned int n);
static char	*zero_case(char *result, unsigned int n);
static void	int_to_str(char *result, char neg_flag, unsigned int n, char dig_count);

char	*ft_uitoa(unsigned int n)
{
	char	*result;
	char	neg_flag;
	char	dig_count;

	neg_flag = 0;
	result = 0;
	if (n == 0)
		return (zero_case(result, n));
	if (n < 0)
		neg_flag = 1;
	dig_count = get_space_qty(n);
	result = (char *) malloc(dig_count + neg_flag + 1);
	if (!result)
		return (0);
	int_to_str(result, neg_flag, n, dig_count);
	return (result);
}

static char	get_space_qty(unsigned int n)
{
	char	digits;

	digits = 0;
	while (n)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static char	*zero_case(char *result, unsigned int n)
{
	if (n != 0)
		return (0);
	result = (char *) malloc(2);
	if (!result)
		return (0);
	*result = '0';
	*(result + 1) = '\0';
	return (result);
}

static void	int_to_str(char *result, char neg_flag, unsigned int n, char dig_count)
{
	if (neg_flag)
	{
		*result = '-';
		*(result + dig_count) = (n % 10) * -1 + '0';
		n /= 10;
		n *= -1;
	}
	*(result + dig_count + neg_flag) = '\0';
	while (n)
	{
		dig_count--;
		*(result + dig_count) = (n % 10) + '0';
		n /= 10;
	}
}
