/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cases.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 08:53:31 by ldevoude          #+#    #+#             */
/*   Updated: 2025/02/25 10:02:46 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_num(va_list ptr, int i, const char *str,
		int *ptr_return_value)
{
	int				value;
	unsigned int	uvalue;
	int				len;
	char			*str_value;

	value = va_arg(ptr, int);
	if (str[i + 1] == 'u')
	{
		uvalue = (unsigned int)value;
		str_value = ft_utoa(uvalue);
		len = ft_strlen(str_value);
		write(1, str_value, len);
	}
	else
	{
		str_value = ft_itoa(value);
		len = ft_strlen(str_value);
		write(1, str_value, len);
	}
	*ptr_return_value += len;
	free(str_value);
}

void	ft_printf_char(va_list ptr, int i, const char *str,
		int *ptr_return_value)
{
	char	value;
	char	*string_temp;
	int		len;

	len = 1;
	if (str[i + 1] == 'c')
	{
		value = va_arg(ptr, int);
		write(1, &value, len);
	}
	else if (str[i + 1] == '%')
		write(1, "%", len);
	else if (str[i + 1] == 's')
	{
		string_temp = va_arg(ptr, char *);
		if (!string_temp)
			string_temp = "(null)";
		len = ft_strlen(string_temp);
		write(1, string_temp, len);
	}
	*ptr_return_value += len;
}

void	ft_print_pointer(va_list ptr, int *ptr_return_value)
{
	unsigned long	param;
	char			*convert;
	int				len;

	param = (unsigned long)va_arg(ptr, void *);
	if (param == 0)
	{
		write(1, "(nil)", 5);
		*ptr_return_value += 5;
		return ;
	}
	write(1, "0x", 2);
	convert = ft_itoa_hexx(param);
	len = ft_strlen(convert);
	write(1, convert, len);
	free(convert);
	len += 2;
	*ptr_return_value += len;
}

void	ft_print_hex(va_list ptr, int i, const char *str, int *ptr_return_value)
{
	char			*convert;
	unsigned int	int_temp;
	int				len;

	convert = NULL;
	if (str[i + 1] == 'p')
		return (ft_print_pointer(ptr, ptr_return_value));
	else
		int_temp = va_arg(ptr, int);
	if (str[i + 1] == 'x' || str[i + 1] == 'X')
		convert = ft_itoa_hexx(int_temp);
	len = ft_strlen(convert);
	if (str[i + 1] == 'X')
		ft_strtoupper(convert);
	write(1, convert, len);
	free(convert);
	*ptr_return_value += len;
}

int	ft_printf_cases(va_list ptr, int i, const char *str, int *ptr_return_value)
{
	if (str[i + 1] == 'u' || str[i + 1] == 'd' || str[i + 1] == 'i')
		ft_printf_num(ptr, i, str, ptr_return_value);
	else if (str[i + 1] == 'c' || str[i + 1] == 's' || str[i + 1] == '%')
		ft_printf_char(ptr, i, str, ptr_return_value);
	else if (str[i + 1] == 'x' || str[i + 1] == 'X' || str[i + 1] == 'p')
		ft_print_hex(ptr, i, str, ptr_return_value);
	return (2);
}
