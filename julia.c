/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacharai <sacharai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:53:44 by sacharai          #+#    #+#             */
/*   Updated: 2023/06/26 22:51:59 by sacharai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(double za, double zb, double ca, double cb)
{
	double	tmp;
	int		i;

	i = 0;
	while (i < ITER && (za * za + zb * zb) < 4)
	{
		tmp = za;
		za = (za * za) - (zb * zb) + ca;
		zb = 2 * tmp * zb + cb;
		i++;
	}
	return (i);
}

int	mouse_scroll(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (data->enable_zoom)
	{
		if (button == 4)
		{
			data->zoom *= 1.05;
			make_julia(data);
		}
		else if (button == 5)
		{
			data->zoom /= 1.05;
			make_julia(data);
		}
	}
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == 8)
	{
		data->color_changed = !data->color_changed;
		make_julia(data);
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
		make_julia(data);
	}
	return (0);
}

void	make_julia(t_data *data)
{
	int		x;
	int		y;
	double	za;
	double	zb;
	int		iter;

	mlx_protect_img_addr(data);
	y = -1;
	while (++y < HEIGHT)
	{
		x = 0;
		while (x++ < WIDTH)
		{
			za = (x - WIDTH / 2.0 + data->off_x) * data->zoom;
			zb = (y - HEIGHT / 2.0 + data->off_y) * data->zoom;
			iter = julia(za, zb, data->j_constant_real, data->j_constant_imag);
			put_color(data, x, y, iter);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	window_julia(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fractol");
	mlx_hook(data->win, 6, 0, mouse_move, data);
	mlx_hook(data->win, 4, 0, mouse_scroll, data);
	mlx_hook(data->win, 2, 0, key_press, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	data->zoom = 4.0 / WIDTH;
	data->enable_zoom = 0;
	make_julia(data);
	mlx_loop(data->mlx);
}
