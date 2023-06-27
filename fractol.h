/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacharai <sacharai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 06:03:26 by sacharai          #+#    #+#             */
/*   Updated: 2023/06/26 23:00:09 by sacharai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include "ft_printf.h"

# define WIDTH 900
# define HEIGHT 900
# define ITER 80.0

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	zoom;
	double	j_constant_real;
	double	j_constant_imag;
	int		enable_zoom;
	int		color_changed;
	double	off_x;
	double	off_y;
}				t_data;

int		mandelbrot(double a, double b);
void	make_mandelbrot(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	window_mandelbrot(t_data *data);
void	make_julia(t_data *data);
void	window_julia(t_data *data);
int		julia(double za, double zb, double ca, double cb);
int		create_trgb(int t, int r, int g, int b);
int		key_press(int keycode, t_data *data);
int		mouse_scroll(int button, int x, int y, t_data *data);
int		mouse_move(int x, int y, t_data *data);
int		close_window(t_data *data);
int		mouse_down(int button, int x, int y, t_data *data);
void	window_burning_ship(t_data *data);
void	put_color(t_data *data, int x, int y, int iter);
int		mouse_move(int x, int y, t_data *data);
void	mlx_protect_img_addr(t_data *data);
void	mlx_protect_init_win(t_data *data);

#endif