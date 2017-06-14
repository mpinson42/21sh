/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 14:58:13 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/06 15:16:59 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_len(uintmax_t n, int base)
{
	int i;

	i = 0;
	while (n != 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

static char	*ft_neg(uintmax_t n, int base, int len)
{
	char	*str;
	char	*cmp;
	int		i;

	i = 1;
	cmp = "0123456789abcdef";
	if (!(str = (char *)malloc(sizeof(char) * (len + 2))))
		return (NULL);
	str[0] = '-';
	str[len + 2] = 0;
	while (len + 1)
	{
		str[len + 1] = cmp[n % base];
		n = n / base;
		len--;
	}
	if (str[1] == '0')
		str = ft_strsub(str, 2, ft_strlen(str) - 2);
	ft_strjoin("-", str);
	return (str);
}

static char	*init(int *neg, int *i)
{
	char *cmp;

	cmp = "0123456789abcdef";
	neg[0] = 1;
	i[0] = 0;
	return (cmp);
}

char		*unsigned_itoa_base(uintmax_t n, int base)
{
	int		i;
	int		len;
	int		neg;
	char	*str;
	char	*cmp;

	cmp = init(&neg, &i);
	len = ft_get_len(n, base);
	neg = 1;
	if (n == 0)
		return (ft_strdup("0"));
	if (neg && !(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	else
		return (ft_neg(n, base, len));
	str[len + 1] = 0;
	while (len + 1)
	{
		str[len] = cmp[n % base];
		n = n / base;
		len--;
	}
	if (str[0] == '0')
		str = ft_strsub(str, 1, ft_strlen(str) - 1);
	return (str);
}
