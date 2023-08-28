/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:12:07 by emsoares          #+#    #+#             */
/*   Updated: 2023/08/28 16:42:07 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_map
{
	char	**map;
	char *no;
	char *so;
	char *we;
	char *ea;
	char **f_color;
	char **c_color;
	char **color_aux;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map *map_utils;
	int		x;
	int		y;
	int		fd;
}	t_data;


//****************utils.c********************
void	ft_init_stack(t_data *d);
int 	ft_count(char *str, char c);
void	finish_error(char *str, int i);
void	ft_free_game(t_data *d);
//****************file.c********************
void	args_in_file(t_data *d, char *file_name);
void	valid_info(t_data *d, char *line);
void	put_path(t_data *d, char *line, int flag);
void	put_rgb(t_data *d, char *line, int flag);
void	put_fc_rgb(t_data *d, int flag, char *line);
//****************free.c********************
void	free_double_pointer(char **str);

//***************main.c*********************

#endif