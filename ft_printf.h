/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzarins <kzarins@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 00:44:02 by kzarins           #+#    #+#             */
/*   Updated: 2024/11/09 23:49:33 by kzarins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define ERROR -1
# define STD_OUT 1
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *input, ...);

/* Writes the output and iterates str to the
 * next character. Returns -1 if there is failure.
 * Returns: char written to output. */
int	format_handle(const char **str, va_list args);

#endif
