/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_handle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzarins <kzarins@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:15:43 by kzarins           #+#    #+#             */
/*   Updated: 2024/10/28 19:49:54 by kzarins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_handle.h"

void	p_handle(void *p)
{
	char	*p_in_hex;

	p_in_hex = int_to_hex((unsigned long) p);
	if (!p_in_hex)
		return ;
	write(STD_OUT, p_in_hex, ft_strlen(p_in_hex));
	free(p_in_hex);
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
