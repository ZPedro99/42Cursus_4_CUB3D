/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:42:07 by emsoares          #+#    #+#             */
/*   Updated: 2023/09/06 17:42:07 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_map_dup(t_data *d)
{
	int	i;

	i = 0;
	d->map_utils->map_dup = ft_calloc(d->count_lines + 1, sizeof(char *));
	while (i < d->count_lines)
	{
		d->map_utils->map_dup[i] = ft_strdup(d->map_utils->map[i]);
		i++;
	}
}

int	ft_search_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
