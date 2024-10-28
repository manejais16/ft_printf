/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzarins <kzarins@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:34:15 by kzarins           #+#    #+#             */
/*   Updated: 2024/10/28 15:31:56 by kzarins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#define NULL_SPACE_LEN 		1
#define HEX_PREFIX_LEN 		2
#define HEX_CHAR 			"0123456789abcdef"
#define HEX_PREFIX			"0x"
#include <stdlib.h>
#include "form_handle.h"

static int	char_spaces_needed(unsigned long num);
static void	add_prefix(char *hex_represent);
static char	digit_to_hex(int dig);

char	*int_to_hex(unsigned long num)
{
	int		output_len;
	char	*hex_represent;
	int		char_iter;

	output_len = char_spaces_needed(num);
	char_iter = output_len;
	hex_represent = (char *) malloc(output_len + NULL_SPACE_LEN + \
			HEX_PREFIX_LEN);
	if (!hex_represent)
		return (0);
	add_prefix(hex_represent);
	while (char_iter > 0)
	{
		char_iter--;
		*(hex_represent + HEX_PREFIX_LEN + char_iter) = digit_to_hex(num % 16);
		num /= 16;
	}
	*(hex_represent + HEX_PREFIX_LEN + output_len) = '\0';
	return (hex_represent);
}

static int	char_spaces_needed(unsigned long num)
{
	int	char_spaces;

	char_spaces = 1;
	num /= 16;
	while (num)
	{
		num /= 16;
		char_spaces++;
	}
	return (char_spaces);
}

static void	add_prefix(char *hex_represent)
{
	ft_memcpy(hex_represent, HEX_PREFIX, HEX_PREFIX_LEN);
}

static char	digit_to_hex(int dig)
{
	char	*hex_chart;
	char	hex_code;

	hex_chart = (char *)malloc(ft_strlen(HEX_CHAR) + 1);
	if (!hex_chart)
		return (0);
	ft_strlcpy(hex_chart, HEX_CHAR, ft_strlen(HEX_CHAR) + 1);
	hex_code = *(hex_chart + (dig % 16));
	free(hex_chart);
	return (hex_code);
}

#include <stdio.h>
int	main(void)
{
	printf("%s\n", int_to_hex(0));
	printf("%s\n", int_to_hex(1234));
}
// For compilation :
// gcc int_to_hex.c ../libft/ft_memcpy.c ../libft/ft_strlcpy.c ../libft/ft_strlen.c
