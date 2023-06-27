/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_shift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacharai <sacharai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 11:26:51 by sacharai          #+#    #+#             */
/*   Updated: 2023/06/26 13:26:03 by sacharai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_color(t_data *data, int x, int y, int iter)
{
	int	color;

	color = iter / ITER * 255;
	if (data->color_changed)
		my_mlx_pixel_put(data, x, y,
			create_trgb(0, color + 60, color + 10, color + 60));
	else
		my_mlx_pixel_put(data, x, y,
			create_trgb(0, color, color, color));
}
