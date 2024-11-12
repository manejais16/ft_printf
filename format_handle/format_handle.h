/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_handle.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzarins <kzarins@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 03:27:30 by kzarins           #+#    #+#             */
/*   Updated: 2024/11/12 23:22:05 by kzarins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_HANDLE_H

# define FORMAT_HANDLE_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../ft_printf.h"

# define NULL_SPACE_LEN 		1
# define ERROR					-1
# define SUCCESS				2

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
	WITH_PADDING = 0400,
	WITH_PRECISION = 01000
};

struct	s_field_specifiers
{
	int	field_width;
	int	precision;
};

int		c_handle(char c, int field_width, int format_flags);
int		s_handle(char *str, int field_width, int format_flags);
int		p_handle(void *p, struct s_field_specifiers field, int format_flags);
int		d_handle(int num, struct s_field_specifiers field, int format_flags);
int		u_handle(unsigned int num, struct s_field_specifiers field, \
			int format_flags);
int		x_handle(unsigned int num, struct s_field_specifiers field, \
			int format_flags);
/* Functions that add flag features for the cases for strings and chars*/
int		write_leading_padding(int *field_size_left, int len, int format_flags);
int		write_trailing_padding(int *field_size_left, int len, int format_flags);
int		add_hex_zero_front(char **p_in_hex, struct s_field_specifiers field, \
			int format_flags);
int		free_and_error(char **mem_to_free, int is_null);
int		putstr_fd(char *str, int fd);
/* The function uses malloc so the result has to be free()!!!! */
char	*int_to_hex(unsigned long num, unsigned int flags);
char	*ft_uitoa(unsigned int n);

#endif
