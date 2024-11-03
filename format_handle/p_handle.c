/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_handle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzarins <kzarins@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:15:43 by kzarins           #+#    #+#             */
/*   Updated: 2024/11/03 04:16:35 by kzarins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_handle.h"

int	p_handle(void *p, int field_width, int format_flags)
{
	char	*p_in_hex;
	int		len;

	p_in_hex = int_to_hex((unsigned long) p, WITH_PREFIX);
	if (!p_in_hex)
		return (-1);
	len = ft_strlen(p_in_hex);
	write(STD_OUT, p_in_hex, len);
	free(p_in_hex);
	return (len);
}

//#include <stdio.h>
//int	main(void)
//{
//	int	a = 5;
//	void *p_test;
//
//	p_test = &a;
//
//	p_handle(p_test);
//	printf("\n %p", p_test);
//	system("leaks a.out");
//	return (0);
//}
