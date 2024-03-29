/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <rberon-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:37:51 by rberon-s          #+#    #+#             */
/*   Updated: 2019/10/06 15:18:10 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	pf_abs(int nbr)
{
	return (nbr < 0 ? -nbr : nbr);
}

static void	ft_aux(long long int val, int base, char **p)
{
	char	*base_str;
	int		tmp;

	base_str = "0123456789ABCDEF";
	if (val >= base || val <= -base)
		ft_aux(val / base, base, p);
	tmp = (int)(val % base);
	*(*p)++ = *(base_str + pf_abs(tmp));
}

char		*ft_itoa_base(long long int value, int base)
{
	char	*ret;
	char	*p;

	if (base < 2 || base > 16 || !(ret = (char *)malloc(70)))
		return (0);
	p = ret;
	if (value < 0 && base == 10)
		*p++ = '-';
	ft_aux(value, base, &p);
	*p = 0;
	return (ret);
}
