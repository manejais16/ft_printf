/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_handle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzarins <kzarins@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:01:49 by kzarins           #+#    #+#             */
/*   Updated: 2024/10/28 20:02:16 by kzarins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "format_handle.h"

void	u_handle(unsigned int num)
{
	char	*int_in_char;

	int_in_char = ft_uitoa(num);
	if (!int_in_char)
		return ;
	write(STD_OUT, int_in_char, ft_strlen(int_in_char));
	free(int_in_char);
}
