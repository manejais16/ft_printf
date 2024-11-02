/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_sequence_handle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzarins <kzarins@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 03:11:34 by kzarins           #+#    #+#             */
/*   Updated: 2024/11/02 03:11:36 by kzarins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#define	MAX_HEX_LEN 2

static int	write_escape_char(const char *input);

int	escape_sequence_handle(const char **input)
{
	*input = *input + 1;
	if (write_escape_char(*input))
	{
		*input = *input + 1;
		return (1);
	}
	else if (**input == '%')
		return (1);
	else if (**input == 'x')
		return (write_hex(input));
	else
	{
		write(STD_OUT, *input - 1, 2);
		*input = *input + 1;
		return (2);
	}
}

static int	write_escape_char(const char *input)
{
	if (*input == 'a')
		write(STD_OUT, "\a", 1);
	else if (*input == 'b')
		write(STD_OUT, "\b", 1);
	else if (*input == 'f')
		write(STD_OUT, "\f", 1);
	else if (*input == 'n')
		write(STD_OUT, "\n", 1);
	else if (*input == 'r')
		write(STD_OUT, "\r", 1);
	else if (*input == 't')
		write(STD_OUT, "\t", 1);
	else if (*input == 'v')
		write(STD_OUT, "\v", 1);
	else if (*input == '\\')
		write(STD_OUT, "\\", 1);
	else if (*input == '\'')
		write(STD_OUT, "\'", 1);
	else if (*input == '?')
		write(STD_OUT, "\?", 1);
	if (*input == 'a' || *input == 'b' || *input == 'f' || *input == 'n' || \
			*input == 'r' || *input == 't' || *input == 'v' || \
			*input == '\\' || *input == '\'' || *input == '\?')
		return (1);
	return (0);
}
