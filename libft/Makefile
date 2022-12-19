# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 19:24:41 by ffons-ti          #+#    #+#              #
#    Updated: 2022/12/13 11:21:19 by ffons-ti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

SRCS			=	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_calloc.c \
					ft_strlcat.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
					ft_memcpy.c  ft_strchr.c  ft_strlcpy.c ft_strdup.c \
					ft_tolower.c ft_bzero.c   ft_isascii.c ft_strnstr.c \
					ft_memmove.c ft_strlen.c  ft_strrchr.c ft_substr.c \
					ft_toupper.c ft_isdigit.c ft_memchr.c  ft_memset.c \
					ft_strjoin.c ft_itoa.c    ft_strtrim.c ft_split.c \
					ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
					ft_putendl_fd.c ft_putnbr_fd.c ft_atoi2.c ft_lstnew.c \
					ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
					ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
					ft_lstiter.c ft_lstmap.c ft_atoi2.c  ft_lstfirst.c \
					ft_lstgoto.c
					
OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

$(NAME):		$(OBJS)
				@ar rcs $(NAME) $(OBJS)
				@echo "Libft.a created!"

%.o:			%.c
				@$(CC) $(CFLAGS) -o $@ -c $^
				
all:			$(NAME)


clean:
				@$(RM) $(OBJS)
				@echo "Clean boys!"
				

fclean:			clean
				@$(RM) $(NAME)
				@echo "Super clean boys!"

re:				fclean $(NAME)

norm:			
				@norminette

.PHONY:			all clean fclean re norm