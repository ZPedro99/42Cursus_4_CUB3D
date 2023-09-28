/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:44:34 by jomirand          #+#    #+#             */
/*   Updated: 2023/09/28 14:38:02 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	start_game(t_data *d)
{
	d->mlx_ptr = mlx_init();
	if (d->mlx_ptr == NULL)
		return ;
	d->win_ptr = mlx_new_window(d->mlx_ptr, WIDTH, HEIGHT, "CUB3D");
	d->img = ft_calloc(1, sizeof(t_image));
	ft_init_stack3(d);
	d->img->img = mlx_new_image(d->mlx_ptr, WIDTH, HEIGHT);
	d->img->addr = mlx_get_data_addr(d->img->img, &d->img->bpp,
			&d->img->line_length, &d->img->endian);
	direction(d);
	draw_raycast(d);
	mlx_hook(d->win_ptr, KeyPress, KeyPressMask, handle_input, d);
	mlx_hook(d->win_ptr, KeyRelease, KeyReleaseMask, release_key, d);
	mlx_hook(d->win_ptr, DestroyNotify, ButtonPressMask, ft_xbutton, d);
	mlx_loop_hook(d->mlx_ptr, game_loop, d);
	mlx_loop(d->mlx_ptr);
}

int	game_loop(t_data *d)
{
	if (!ft_movs(d))
		return (0);
	mlx_destroy_image(d->mlx_ptr, d->img->img);
	d->img->img = mlx_new_image(d->mlx_ptr, WIDTH, HEIGHT);
	draw_raycast(d);
	return (0);
}

void	draw_raycast(t_data *d)
{
	int	color;
	int	j;

	draw_floor_celling(d);
	d->i = 0;
	while (d->i < WIDTH)
	{
		ray_calc(d);
		check_side(d);
		get_hit(d);
		ray_values(d);
		if (d->side == 1)
		{
			if(d->raydir_y < 0)//s
				color = 0xffffff;	
			else
				color = 0x000000;//N
		}
		else //verificar y
		{
			if(d->raydir_x < 0)//w
				color = 0xffa500;	
			else
				color = 0x00ff00;//e
		}
		j = d->draw_start;
		while (j < d->draw_end)
		{
			my_mlx_pixel_put(d, d->i, j, color);
			j++;
		}
		d->i++;
	}
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img->img, 0, 0);
}

void	draw_floor_celling(t_data *d)
{
	unsigned int	f_color;
	unsigned int	c_color;

	f_color = (0x010000 * ft_atoi(d->map_utils->f_color[0])) + (0x000100
			* ft_atoi(d->map_utils->f_color[1]))
		+ ft_atoi(d->map_utils->f_color[2]);
	c_color = 0x010000 * ft_atoi(d->map_utils->c_color[0]) + 0x000100
		* ft_atoi(d->map_utils->c_color[1])
		+ ft_atoi(d->map_utils->c_color[2]);
	draw_floor_celling2(d, f_color, c_color);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img->addr + (y * data->img->line_length
			+ x * (data->img->bpp / 8));
	*(unsigned int *)dst = color;
}
