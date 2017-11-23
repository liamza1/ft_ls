/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 17:34:20 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/22 09:36:25 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 8
# define ENDL '\n'

# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>

int				ft_strstart(char *s1, char *s2);
void			ft_free2d(char **arr);
int				get_next_line(int const fd, char **line);
int				ft_strendswith(char *s1, char *s2);
char			*ft_strjoinch(char const *s1, char c);
int				ft_intlen(int num);
void			*ft_memset(void *b, int c, size_t len);
int				ft_strstartswith(char *s1, char *s2);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
char			*ft_strndup(const char *s1, size_t n);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void            ft_putchar_if(int boolean, char yes, char no);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char*));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const*s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void            ft_putendl_fd(char const *source, int file_descriptor);
void			ft_putnbr_large_fd(intmax_t number, int file_descriptor);
void			ft_atoi_add_digit_u(const char c, unsigned int *number);
void			ft_putstrn_fd(char const *source, size_t max_length, int file_descriptor);
void			ft_putstr_justify_left(char *string, size_t total, char fill);
size_t			ft_strlen_wide(const wchar_t *original);
void			ft_putcharn(char c, size_t number);
void			ft_putnbr_fd(int n, int fd);
int				ft_wordc(char const *str, char c);
size_t			ft_charcount(long n);
char			*ft_pathjoin(char *p1, char *p2);
int				ft_count_digits_ularge(uintmax_t number);
intmax_t		ft_abs_large(intmax_t number);
char			*ft_itoa_large(intmax_t number);
void			ft_itoa_write(char *last_digit, uintmax_t number);
int				ft_abs(int num);
void			ft_putcharn_fd(char c, size_t number, int file_descriptor);
void			ft_putstr_justify_right(char *string, size_t total, char fill);
void			ft_putnbr_justify_right(int number, size_t total, char fill);
size_t			ft_countchars(char const *haystack, char needle, size_t length);
typedef void    (*t_printer)(const void*);
void			ft_putstr_literal_fd(char const *source, int file_descriptor);
char			*ft_itoa_ularge(uintmax_t number);
int				ft_tolower(int c);
char			*ft_basetoa(uintmax_t number, int base);
void			ft_strtolower(char *string);
char			*ft_strchr_last(const char *haystack, int needle);
void			ft_putendl_exit(char const *source, int exit_code);

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list*lst, void (*f)(t_list *elem));
void			ft_lstiter(t_list*lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_list_create_elem(void *content);
t_list			*ft_list_find_end(t_list *list);
void			ft_list_push_front(t_list **begin_list, void *content);
t_list			*ft_list_push_params(int ac, char **av);
void			ft_ptrswp(void **first, void **second);
void			ft_list_push_back(t_list **begin_list, void *content);
void            ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
void			ft_list_remove_node(t_list **original, t_list *to_remove, void (*free_inside)(void*));
void			ft_list_reverse(t_list **begin_list);
int             ft_ptrequ(const void *first, const void *second);
void            ft_list_sort(t_list **first, int (*compare)(void*, void*));
void            ft_list_clear(t_list **begin_list, void (*free_inside)());
size_t			ft_list_size(t_list *begin_list);
#endif
