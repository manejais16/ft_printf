#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		output_len;

	if (!input)
		return (-1);
	va_start(args, input);
	output_len = 0;
	while (*input)
	{
		if(*input == '%')
		{
			output_len += format_handle((char *)input, args);
			input++;
		} else
		{
			write(STD_OUT, input, 1);
			output_len++;
		}
	input++;
	}
	printf("\nThe total len: %d", output_len);
	return (0);
}
