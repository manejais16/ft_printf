# ifndef FORM_HANDLE_H
#define FORM_HANDLE_H
//Only for testing
#include <stdio.h>

#include <unistd.h>
#include "../ft_printf.h"

void	c_handle(char c);
void	s_handle(char *str);
void	p_handle(void *p);
void	d_handle(int num);
void	i_handle(int num);
void	u_handle(int num);

/* The function uses malloc so the result has to be free()!!!! */
char	*int_to_hex(unsigned long num);
char	*ft_uitoa(unsigned int n);

#endif
