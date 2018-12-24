/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnwstr.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/09 16:35:19 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/09 17:49:04 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnwstr_fd(wchar_t *s, int nb, int fd)
{
	while (*s && nb--)
	{
		ft_putwchar_fd(*s, fd);
		s++;
	}
}
