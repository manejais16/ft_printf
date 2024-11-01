/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_handle.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzarins <kzarins@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 00:50:53 by kzarins           #+#    #+#             */
/*   Updated: 2024/11/01 00:54:05 by kzarins          ###   ########.fr       */
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
	UPPER_CASE_CHAR = 04
};

int		c_handle(char c);
int		s_handle(char *str);
int		p_handle(void *p);
int		d_handle(int num);
int		i_handle(int num);
int		u_handle(unsigned int num);
int		x_handle(unsigned int num, enum e_hex_convert_flags flags);

/* The function uses malloc so the result has to be free()!!!! */
char	*int_to_hex(unsigned long num, unsigned int flags);
char	*ft_uitoa(unsigned int n);

#endif
