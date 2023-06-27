/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacharai <sacharai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 11:42:05 by sacharai          #+#    #+#             */
/*   Updated: 2023/06/26 22:51:24 by sacharai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_move(int x, int y, t_data *data)
{
	double	j_constant_real;
	double	j_constant_imag;

	if (data->enable_zoom == 0)
	{
		j_constant_real = (x - WIDTH / 2.0) * data->zoom;
		j_constant_imag = (y - HEIGHT / 2.0) * data->zoom;
		data->j_constant_real = j_constant_real;
		data->j_constant_imag = j_constant_imag;
		make_julia(data);
	}
	return (0);
}
