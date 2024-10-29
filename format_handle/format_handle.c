/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzarins <kzarins@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:08:02 by kzarins           #+#    #+#             */
/*   Updated: 2024/10/29 22:01:53 by kzarins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "format_handle.h"

int	handle_format_leters(char *str, va_list args);

int	format_handle(char *str, va_list args)
{
	int	len;

	str++;
	len = 0;
	if (*str == '%')
	{
		len = c_handle('%');
		return (len);
	}
	len = handle_format_letters(*str, args);
	return (len);
}

int	handle_format_leters(char *str, va_list args)
{
	else if (str == 'c')
		return (c_handle(va_arg(args, char)));
	else if (str == 's')
		return (s_handle(va_arg(args, char *)));		
	else if (str == 'p')
		return (p_handle(va_arg(args, void *)));
	else if (str == 'd')
		return (d_handle(va_arg(args, int)));
	else if (str == 'i')
		return (i_handle(va_arg(args, int)));
	else if (str == 'u')
		return (u_handle(va_arg(args, unsigned int)));
	else if (str == 'x')
		return (x_handle(va_arg(args, unsigned int), 0)); 
	else if (str == 'X')
		return (x_handle(va_arg(args, unsigned int), UPPER_CASE_CHAR);
	else
		return (-1);
}
