#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	output_format(const char **input, va_list args);
int	output_escape_sequence(const char **input);
int	output_char(const char **input);

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
			output_len += output_format(&input, args);
		else if (*input == '\\')
			output_len += output_escape_sequence(&input);
		else
			output_len += output_char(&input);	
	}
	return (output_len);
}

int	output_format(const char **input, va_list args)
{
	int	format_len;

	format_len = format_handle((char *)*input, args);
	if (format_len == -1)
	{
		format_len = 6;
		write(STD_OUT, "(null)", format_len);
	}
	*input = *input + 2;
	return (format_len);
}

int	output_escape_sequence(const char **input)
{
	escape_sequence_handle(*input);
	*input = *input + 1;
	return (1);
}
	
int	output_char(const char **input) 
{
	write(STD_OUT, *input, 1);
	*input = *input + 1;
	return (1);
}
