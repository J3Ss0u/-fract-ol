/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacharai <sacharai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 11:08:34 by sacharai          #+#    #+#             */
/*   Updated: 2023/06/26 22:54:33 by sacharai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	burning_ship(double a, double b)
{
	double	za;
	double	zb;
	double	tmp;
	int		i;

	za = 0;
	zb = 0;
	i = 0;
	while (i < ITER && (za * za + zb * zb) < 4)
	{
		tmp = za;
		za = za * za - zb * zb + a;
		zb = 2 * fabs(tmp * zb) + b;
		i++;
	}
	return (i);
}

void	make_burning_ship(t_data *data)
{
	int		x;
	int		y;
	double	real;
	double	imag;
	int		iter;

	mlx_protect_img_addr(data);
	y = -1;
	while (++y < HEIGHT)
	{
		x = 0;
		while (x++ < WIDTH)
		{
			real = (x - WIDTH / 2.0 + data->off_x) * data->zoom;
			imag = (y - HEIGHT / 2.0 + data->off_y) * data->zoom;
			iter = burning_ship(real, imag);
			put_color(data, x, y, iter);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int	key_press2(int keycode, t_data *data)
{
	if (keycode == 8)
	{
		data->color_changed = !data->color_changed;
		make_burning_ship(data);
	}
	if (keycode == 12)
		data->enable_zoom = !data->enable_zoom;
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
	{
		if (keycode == 123)
			data->off_x -= 0.1 / data->zoom;
		if (keycode == 124)
			data->off_x += 0.1 / data->zoom;
		if (keycode == 125)
			data->off_y += 0.1 / data->zoom;
		if (keycode == 126)
			data->off_y -= 0.1 / data->zoom;
		make_burning_ship(data);
	}
	return (0);
}

int	mouse_down1(int button, int x, int y, t_data *data)
{
	(void) y;
	(void) x;
	if (button == 5)
		data->zoom *= 1.05;
	else if (button == 4)
		data->zoom /= 1.15;
	make_burning_ship(data);
	return (0);
}

void	window_burning_ship(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fractol");
	mlx_mouse_hook(data->win, mouse_down1, data);
	mlx_hook(data->win, 2, 0, key_press2, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	data->zoom = 4.0 / WIDTH;
	make_burning_ship(data);
	mlx_loop(data->mlx);
}
