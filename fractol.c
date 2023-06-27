/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacharai <sacharai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:52:22 by sacharai          #+#    #+#             */
/*   Updated: 2023/06/26 23:08:11 by sacharai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		ft_printf("Usage: ./fractol [fractal_type]\n");
		return (0);
	}
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		window_mandelbrot(&data);
	else if (ft_strcmp(av[1], "julia") == 0)
		window_julia(&data);
	else if (ft_strcmp(av[1], "burning") == 0)
		window_burning_ship(&data);
	else
	{
		ft_printf("Error: Invalid fractal type %s\n", av[1]);
		ft_printf("Please specify either ");
		ft_printf("'mandelbrot' or 'julia' or 'burning'.\n");
		return (0);
	}
}
