/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_protect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacharai <sacharai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:24:10 by sacharai          #+#    #+#             */
/*   Updated: 2023/06/26 13:26:03 by sacharai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_protect_img_addr(t_data *data)
{
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->img == NULL)
		exit (1);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (data->addr == NULL)
		exit(1);
}

void	mlx_protect_init_win(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		exit(1);
	data->win = mlx_new_window(data->mlx, WIDTH,
			HEIGHT, "fractol");
	if (data->win == NULL)
		exit (1);
}
