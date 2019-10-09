/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_get_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <rberon-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 20:14:51 by rberon-s          #+#    #+#             */
/*   Updated: 2019/10/09 21:15:26 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	pf_get_board_info(t_board *bd)
{
	char	*line;
	int		ret;

	line = 0;
	ret = 0;
	if (get_next_line(STDIN_FILENO, &line) && ft_strstr(line, "Piece"))
	{
		if (ft_strchr(line, ' ') && ft_strrchr(line, ' '))
		{
			bd->height = ft_atoi(ft_strchr(line, ' '));
			bd->width = ft_atoi(ft_strrchr(line, ' '));
			ret = 1;
		}
	}
	ft_strdel(&line);
	return (ret);
}

int			fl_get_piece(t_board *pi)
{
	char	*line;
	int		i;

	line = 0;
	i = 0;
	if (!pf_get_board_info(pi))
		return (0);
	if (!(pi->board = (char **)malloc(sizeof(char *) * pi->height)))
		return (0);
	while (i < pi->height)
	{
		if (!(pi->board[i] = ft_strnew(pi->width)))
			return (0);
		if (get_next_line(STDIN_FILENO, &line))
		{
			ft_strncpy(pi->board[i], line, pi->width);
			ft_strdel(&line);
		}
		else //тут ещё
			return (0);
		i++;
	}
	return (1);
}
