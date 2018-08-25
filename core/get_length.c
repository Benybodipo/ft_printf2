/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besteba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 04:11:40 by besteba           #+#    #+#             */
/*   Updated: 2018/08/25 04:13:46 by besteba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_length(const char **str)
{
	int		i;
	char	*len;

	i = 0;
	while (is_in_str("hljz", *(*str)))
	{
		(*str)++;
		i++;
	}
	len = malloc(sizeof(char) * (i + 1));
	*str -= i;
	i = 0;
	while (is_in_str("hljz", *(*str)) && i < 2)
	{
		len[i] = *(*str);
		(*str)++;
		i++;
	}
	len[i] = '\0';
	return (len);
}
