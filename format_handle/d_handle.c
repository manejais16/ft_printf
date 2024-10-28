/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_handle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzarins <kzarins@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:18:24 by kzarins           #+#    #+#             */
/*   Updated: 2024/10/28 19:50:22 by kzarins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "format_handle.h"

void	d_handle(int num)
{
	char	*int_in_char;

	int_in_char = ft_itoa(num);
	if (!int_in_char)
		return ;
	write(STD_OUT, int_in_char, ft_strlen(int_in_char));
	free(int_in_char);
}
