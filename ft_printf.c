/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzarins <kzarins@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 00:37:34 by kzarins           #+#    #+#             */
/*   Updated: 2024/11/11 21:52:45 by kzarins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>

int	write_to_output(const char **input, va_list args);
int	output_format(const char **input, va_list args);
int	output_char(const char **input);

//All the other functions will return ERROR on failed write
//Any failed call will return ERROR
int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		output_len;
	int		write_len;

	if (!input)
		return (ERROR);
	va_start(args, input);
	output_len = 0;
	while (*input)
	{
		write_len = write_to_output(&input, args);
		if (write_len == ERROR)
			return (ERROR);
		output_len += write_len;
	}
	va_end(args);
	return (output_len);
}

// Writes chars to output. Returns ERROR if the write
// failed. Else returns written len.
int	write_to_output(const char **input, va_list args)
{
	int	write_len;

	if (**input == '%')
	{
		write_len = output_format(input, args);
		if (write_len == ERROR)
			return (ERROR);
	}
	else
	{
		write_len = output_char(input);
		if (write_len == ERROR)
			return (ERROR);
	}
	return (write_len);
}

int	output_format(const char **input, va_list args)
{
	int	format_len;

	format_len = format_handle(input, args);
	if (format_len == ERROR)
		return (ERROR);
	*input = *input + 1;
	return (format_len);
}

int	output_char(const char **input)
{
	int	len;

	len = write(STD_OUT, *input, 1);
	if (len == ERROR)
		return (ERROR);
	*input = *input + 1;
	return (1);
}
