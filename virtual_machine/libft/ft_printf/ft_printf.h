/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 18:08:15 by eviana            #+#    #+#             */
/*   Updated: 2019/07/23 15:40:37 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft.h"
# include <wchar.h>

typedef struct	s_asset
{
	char	*flags;
	size_t	width;
	int		precision;
	int		length;
	int		type;
	char	*copy;
}				t_asset;

int				ft_fill_buff(char *str, int end);
char			*ft_preci_0(t_asset asset, double n, long k, int i);
char			*ft_inf_f(t_asset asset, char *str2);
unsigned long	sp_power(long nb, int power);
char			**ft_formattotab(const char *restrict s);
int				ft_isconv(char c);
int				ft_charcount(const char *restrict s, int i, int mode);
unsigned int	ft_partsnbr(const char *s);
char			**ft_setprint(char **tab);
char			*ft_conv_p(t_asset asset, va_list ap);
char			*ft_conv_s(t_asset asset, va_list ap);
char			*ft_conv_c(t_asset asset, va_list ap);
char			*ft_conv_di(t_asset asset, va_list ap);
char			*ft_conv_oux(t_asset asset, va_list ap);
char			*ft_conv_f(t_asset asset, va_list ap);
char			*ft_conv_percent(t_asset asset, va_list ap);
char			*ft_noconv(t_asset asset, va_list ap);
char			*ft_convp_width(t_asset asset, char *res);
char			*ft_width_f(t_asset asset, char *str, int i, int j);
int				ft_findtype(char *tab);
char			*ft_findflags(char *tab);
int				ft_findlength(char *tab);
int				ft_findprecision(char *tab);
size_t			ft_findwidth(char *tab);
char			*ft_set_precision(char *initial, t_asset *asset, int signmode);
char			*ft_set_width(char *initial, t_asset asset, int signmode);
char			*ft_addbuild(char *initial, char *additional, t_asset asset);
char			*ft_preparewidth(char *processed, t_asset asset, int signmode);
char			*ft_build_str(char *initial, t_asset asset, int signmode);
t_asset			ft_digest(char *tab);
int				ft_pre_dispatch(char **tab, va_list ap);
void			ft_printasset(t_asset asset);
int				ft_printf(const char *restrict format, ...);
char			*sp_strnjoin(char *s1, char *s2, size_t n, int mode);
#endif
