/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaammo <souaammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:06:24 by aahaded           #+#    #+#             */
/*   Updated: 2025/03/04 15:11:15 by souaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "../cub3D.h"
# include "./printf/ft_printf.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			**value;
	struct s_list	*next;
}					t_list;

char				*ft_itoa(int n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_atoi(const char *str);
int					ft_strlen(const char *s);
t_list				*ft_lstnew(char **value);
char				*ft_strdup(const char *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
int	ft_strchr(const char *str, char c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strcpy(char *dest, char *src);
char				**ft_split(char const *s, char c);
int					count_word(const char *str, char c);
void				ft_lstadd_back(t_list **lst, t_list *new);
char	*ft_strjoin(char *s1, char *s2);
int					ft_strcmp(const char *str1, const char *str2);
char				*ft_strncpy(char *dest, const char *src, int len);
void				*ft_memcpy(void *dest, const void *src, size_t n);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_strncmp(const char *str1, const char *str2, size_t len);
char	*ft_strcat(char *dst, const char *src);
#endif
