/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <eviana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:40:57 by plaurent          #+#    #+#             */
/*   Updated: 2020/01/14 14:44:53 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 1

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

int				get_next_line(int const fd, char **line, int error);
int				ft_size_long(long n);
char			*ft_strrev(char *str);
char			*ft_lltoa(long long n);
char			*ft_ltoa(long n);
char			*ft_strdup(const char *src);
void			ft_putnbr(int n);
void			ft_putull(unsigned long long n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *s);
void			ft_putstr(char const *s);
void			ft_putchar(char c);
unsigned int	ft_strcount(const char *s, char c);
char			*ft_itoa(int n);
char			**ft_strsplit(char const *s, char c);
char			*ft_strtrim(char const *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_strequ(char const *s1, char const *s2);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strmap(char const *s, char (*f)(char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_striter(char *s, void (*f)(char *));
void			ft_strclr(char *s);
void			ft_strdel(char **as);
char			*ft_strnew(size_t s);
void			ft_memdel(void **ap);
void			*ft_memalloc(size_t s);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_isprint(int c);
int				ft_isascii(int c);
int				ft_isalnum(int c);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_atoi(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t len);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strrchr(const char *s, int c);
size_t			ft_strlcat(char *dst, char const *src, size_t s);
char			*ft_strchr(const char *s, int c);
char			*ft_strncat(char *dst, const char *src, size_t n);
char			*ft_strcat(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strcpy(char *dst, const char *src);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			ft_bzero(void *str, size_t n);
size_t			ft_strlen(const char *str);
void			*ft_memset(void *s, int c, size_t n);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_foreach(int *tab, int length, void (*f)(int));
int				ft_factorial(int nb);
int				ft_power(int nb, int power);
int				ft_fibonacci(int index);
int				ft_sqrt(int nb);
int				ft_is_prime(int nb);
char			*ft_utoa(unsigned int n);
char			*ft_ultoa(unsigned long n);
char			*ft_ulltoa(unsigned long long n);
char			*ft_convert_base(char *nbr, char *base_from, char *base_to);
void			ft_swap(int *a, int *b);
int				ft_strallchr(char *str, char c);
int				*ft_tabrev(int *tab, size_t size);
int				*ft_tabcpy(int *src, size_t size);
int				ft_strnum(const char *s);

#endif
