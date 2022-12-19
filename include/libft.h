/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:51:54 by ffons-ti          #+#    #+#             */
/*   Updated: 2022/12/19 10:30:31 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_list
{
	int				val;
	int				s_val;
	struct s_list	*next;
	struct s_list	*before;
}	t_list;

void		*ft_bzero(void *s, size_t len);

int			ft_isalpha(int c);

int			ft_isascii(int c);

int			ft_isdigit(int c);

int			ft_isalnum(int c);

int			ft_isprint(int c);

size_t		ft_strlen(const char *str);

void		*ft_memcpy(void *dst, const void *src, size_t n);

void		*ft_memmove(void *dst, const void *src, size_t len);

void		*ft_memset(void *b, int c, size_t len);

size_t		ft_strlcpy(char *dest, const char *src, size_t size);

size_t		ft_strlcat(char *dest, const char *src, size_t size);

int			ft_strncmp(char *s1, char *s2, size_t n);

int			ft_tolower(int c);

int			ft_toupper(int c);

char		*ft_strchr(char *str, char to_find);

char		*ft_strrchr(char *str, char to_find);

void		*ft_memchr(void *s, int c, size_t n);

int			ft_memcmp(const void *s1, const void *s2, size_t n);

int			ft_atoi(const char *str);

long int	ft_atoi2(const char *str);

char		*ft_strnstr(const char *str, const char *to_find, size_t len);

void		*ft_calloc(size_t count, size_t size);

char		*ft_strdup(const char *s1);

char		*ft_substr(char const *s, unsigned int start, size_t len);

char		*ft_strjoin(char const *s1, char const *s2);

char		*ft_itoa(int n);

char		*ft_strtrim(char const *s1, char const *set);

char		**ft_split(char const *s, char c);

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void		ft_striteri(char *s, void (*f)(unsigned int, char*));

void		ft_putchar_fd(char c, int fd);

void		ft_putstr_fd(char *s, int fd);

void		ft_putendl_fd(char *s, int fd);

void		ft_putnbr_fd(int n, int fd);

t_list		*ft_lstnew(int val);

void		ft_lstadd_front(t_list **lst, t_list *new);

int			ft_lstsize(t_list *lst);

t_list		*ft_lstlast(t_list *lst);

void		ft_lstadd_back(t_list **lst, t_list *new);

void		ft_lstdelone(t_list *lst, void (*del)(void *));

void		ft_lstclear(t_list **lst);

void		ft_lstiter(t_list *lst, void (*f)(void *));

t_list		*ft_lstmap(t_list *lst, int (*f)(void *));

t_list		*ft_lstfirst(t_list *lst);

t_list		*ft_lstgoto(t_list *lst, int n);

#endif