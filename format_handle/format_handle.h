# ifndef FORM_HANDLE_H
#define FORM_HANDLE_H
//Only for testing
#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>
#include "../ft_printf.h"

enum	e_hex_convert_flags
{
	WITH_PREFIX = 01,
	UPPER_CASE_PREFIX = 02,
	UPPER_CASE_CHAR = 04
};

int	c_handle(char c);
int	s_handle(char *str);
int	p_handle(void *p);
int	d_handle(int num);
int	i_handle(int num);
int	u_handle(unsigned int num);
int	x_handle(unsigned int num,enum e_hex_convert_flags flags);

/* The function uses malloc so the result has to be free()!!!! */
char	*int_to_hex(unsigned long num, unsigned int flags);
char	*ft_uitoa(unsigned int n);

#endif
