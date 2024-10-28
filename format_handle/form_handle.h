# ifndef FORM_HANDLE_H
#define FORM_HANDLE_H
//Only for testing
#include <stdio.h>

#include <unistd.h>
#include "../ft_printf.h"

void	c_handle(char c);
void	s_handle(char *str);
void	p_handle(void *p);

/* The function uses malloc so the result has to be free()!!!! */
char	*int_to_hex(unsigned long num);
#endif
