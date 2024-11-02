/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzarins <kzarins@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 00:58:44 by kzarins           #+#    #+#             */
/*   Updated: 2024/11/02 03:05:54 by kzarins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define STD_OUT 1

# include <stdarg.h>

int	ft_printf(const char *input, ...);

/* Return: char written to ouput; NOTE: DOES NOT ITERATE*/
int	format_handle(char *str, va_list args);
int	escape_sequence_handle(const char **input);
int	output_format(const char **input, va_list args);
int	write_hex(const char **input);

#endif
