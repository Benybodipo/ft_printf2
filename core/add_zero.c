/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_zero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besteba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 12:57:30 by besteba           #+#    #+#             */
/*   Updated: 2018/08/19 11:37:50 by besteba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_zero(char **tmp, t_format *form)
{
	int		is_negative;
	int		add_prefix;
	int		prefix_len;
	int		width;
	char	spec;

	prefix_len = 0;
	add_prefix = 0;
	is_negative = form->is_negative;
	spec = form->specifier;
	if (is_in_str("xXoO", spec) && form->prefix == '#')
		add_prefix = 1;
	if (is_in_str("idD", spec) && (is_in_str("+ ", form->sign) || is_negative))
		add_prefix = 1;
	if (is_in_str("xXoO", spec) && add_prefix)
		prefix_len = (is_in_str("xX", spec)) ? 2 : 1;
	if (is_in_str("idD", spec) && add_prefix)
		prefix_len = 1;
	width = form->width - prefix_len;
	if (width > (int)ft_strlen(*tmp) && !form->precision && spec != 'p')
		padding_right(tmp, ft_strdup(*tmp), width, '0');
	else if (width > (int)ft_strlen(*tmp) && form->precision && spec != 'p')
		padding_right(tmp, ft_strdup(*tmp), width, ' ');
}
