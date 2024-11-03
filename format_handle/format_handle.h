/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_handle.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzarins <kzarins@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 00:50:53 by kzarins           #+#    #+#             */
/*   Updated: 2024/11/03 03:02:36 by kzarins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FORMAT_HANDLE_H

# define FORMAT_HANDLE_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../ft_printf.h"

enum	e_hex_convert_flags
{
	WITH_PREFIX = 01,
	UPPER_CASE_PREFIX = 02,
	UPPER_CASE_CHAR = 04,
	NUMBER_SIGN = 010,
	SPACE = 020,
	PLUS_SING = 040,
	ZEROS = 0100,
	RIGHT_PAD = 0200,
	WITH_PADDING = 0400
};

int		c_handle(char c, int field_width, int format_flags);
int		s_handle(char *str, int field_width, int format_flags);
int		p_handle(void *p, int field_width, int format_flags);
int		d_handle(int num, int field_width, int format_flags);
int		i_handle(int num, int field_width, int format_flags);
int		u_handle(unsigned int num, int field_width, int format_flags);
int		x_handle(unsigned int num, int field_width, int format_flags);

/* The function uses malloc so the result has to be free()!!!! */
char	*int_to_hex(unsigned long num, unsigned int flags);
char	*ft_uitoa(unsigned int n);

#endif
