/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besteba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 12:27:26 by besteba           #+#    #+#             */
/*   Updated: 2018/08/25 03:16:19 by besteba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	get_unsigned_num(va_list args, t_format *form)
{
	uintmax_t num;

	if (!form->length)
		return ((intmax_t)va_arg(args, unsigned int));
	if (ft_strcmp(form->length, "hh"))
		num = (intmax_t)va_arg(args, unsigned int);
	else if (ft_strcmp(form->length, "h"))
		num = (intmax_t)va_arg(args, int);
	else if (ft_strcmp(form->length, "l"))
		num = (intmax_t)va_arg(args, unsigned long int);
	else if (ft_strcmp(form->length, "ll"))
		num = (intmax_t)va_arg(args, unsigned long long int);
	else if (ft_strcmp(form->length, "j"))
		num = va_arg(args, uintmax_t);
	else if (ft_strcmp(form->length, "z"))
		num = (intmax_t)va_arg(args, size_t);
	else
		num = (intmax_t)va_arg(args, unsigned int);
	return (num);
}

intmax_t	get_signed_num(va_list args, t_format *form)
{
	intmax_t num;

	if (!form->length)
		return ((intmax_t)va_arg(args, int));
	if (ft_strcmp(form->length, "hh"))
		num = (intmax_t)va_arg(args, signed int);
	else if (ft_strcmp(form->length, "h"))
		num = (intmax_t)va_arg(args, int);
	else if (ft_strcmp(form->length, "l"))
		num = (intmax_t)va_arg(args, long int);
	else if (ft_strcmp(form->length, "ll"))
		num = (intmax_t)va_arg(args, long long int);
	else if (ft_strcmp(form->length, "j"))
		num = va_arg(args, intmax_t);
	else if (ft_strcmp(form->length, "z"))
		num = (intmax_t)va_arg(args, size_t);
	else
		num = (intmax_t)va_arg(args, int);
	return (num);
}

void		handle_is_negative(va_list ap, t_format *form, char **tmp)
{
	char spec;

	spec = form->specifier;
	*tmp = ft_itoa_base(get_signed_num(ap, form), get_base(spec));
	if (ft_atoi(*tmp) < 0)
	{
		*tmp = ft_itoa_base((ft_atoi(*tmp) * -1), get_base(spec));
		form->is_negative = 1;
	}
}

void		handle_length(va_list ap, t_format *form, char **tmp)
{
	char spec;
	char c[2];
	char *length;

	spec = form->specifier;
	length = form->length;
	if (is_in_str("dDi", spec))
		handle_is_negative(ap, form, tmp);
	else if (is_in_str("uUoOxXb", spec))
		*tmp = ft_uitoa_base(get_unsigned_num(ap, form), get_base(spec));
	else if (is_in_str("p", spec))
		get_pointer(tmp, va_arg(ap, void *), form);
	else if (is_in_str("cC", spec))
	{
		if (length && ft_strcmp("l", length))
			c[0] = ft_wchartochar(va_arg(ap, wchar_t));
		else
			c[0] = ft_atoi(ft_uitoa_base(get_signed_num(ap, form), 10));
		c[1] = '\0';
		*tmp = ft_strdup(c);
	}
	else if (length && is_in_str("sS", spec) && ft_strcmp(length, "l"))
		*tmp = ft_wstrtostr(va_arg(ap, wchar_t*));
	else
		*tmp = va_arg(ap, char *);
}
