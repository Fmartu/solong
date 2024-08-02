/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:28:40 by fmartusc          #+#    #+#             */
/*   Updated: 2024/02/03 18:40:30 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

int		ft_putaddrss(void *memaddrss);
int		ft_putchar(int c);
int		ft_putstr(char const *s);
int		ft_putunsigned(unsigned long n);
int		ft_putnbr(int n);
int		ft_putexa(unsigned int nbr, char input);
char	*ft_strchr(char const *str, int c);
size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd);
int		ft_printf(const char *input, ...);

#endif
