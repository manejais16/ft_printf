/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_handle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzarins <kzarins@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:49:04 by kzarins           #+#    #+#             */
/*   Updated: 2024/10/28 12:59:17 by kzarins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "form_handle.h"

void	c_handle(char c)
{
	write(STD_OUT, &c, sizeof(char));
}
