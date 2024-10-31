# ifndef FT_PRINTF_H
#define FT_PRINTF_H

#define STD_OUT 1

#include <stdarg.h>

int	ft_printf(const char *input, ...);

/* Return: char written to ouput; NOTE: DOES NOT ITERATE*/
int	format_handle(char *str, va_list args);

#endif
