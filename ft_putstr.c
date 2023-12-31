/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacharai <sacharai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 05:24:09 by sacharai          #+#    #+#             */
/*   Updated: 2023/06/26 13:26:32 by sacharai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *pos)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)", pos);
		return ;
	}
	while (str[i])
	{
		ft_putchar(str[i], pos);
		i++;
	}
}
