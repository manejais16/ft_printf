/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzarins <kzarins@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 01:06:48 by kzarins           #+#    #+#             */
/*   Updated: 2024/11/02 03:14:41 by kzarins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

static int	is_hex_char(char test_c);
static int	hex_to_int(const char *str);
static int hex_char_to_int(const char hex_char, const char *hex_notation);

int	write_hex(const char **input)
{
	int 	current_hex_char;
	char	hex_char[3];
	int		char_representation;

	current_hex_char = 0;
	*input = *input + 1;
	while (is_hex_char(*(*input + current_hex_char)) && current_hex_char < 2)
	{
		hex_char[current_hex_char] = *(*input + current_hex_char);
		current_hex_char++;
	}
	hex_char[current_hex_char] = '\0';
	char_representation = hex_to_int(hex_char);
	write(STD_OUT, &char_representation, 1);
	*input = *input + current_hex_char;
	return (1);
}

static int	is_hex_char(char test_c)
{
	if ((test_c >= '0' && test_c <= '9') || (test_c >= 'a' && test_c <= 'f'))
		return (1);
	return (0);
}

static int	hex_to_int(const char *str)
{
	char	hex_notation[16];
	int		result;

	result = 0;
	ft_memcpy(hex_notation, "0123456789abcdef", 16);
	while(*str)
	{
		result = result * 16 + hex_char_to_int(*str, hex_notation);
		str++;
	}
	return(result);
}

static int hex_char_to_int(const char hex_char, const char *hex_notation)
{
	int	position;

	position = 0;
	while(position < 16 && hex_char != *(hex_notation + position))
		position++;
	return (position);
}
