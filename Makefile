# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aghazi <aghazi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/02 06:39:27 by oabushar          #+#    #+#              #
#    Updated: 2023/01/29 20:59:48 by aghazi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME        := minishell
CC 			= gcc -g3 -I/usr/local/opt/readline/include
FLAGS    	:= -Wall -Wextra -Werror -fcommon

SRCS        :=  ./parsing/parser.c \
				./parsing/parser_utils.c \
				./parsing/parser_utils2.c \
				./parsing/ft_split_q.c \
				./parsing/redirections.c \
				./parsing/redirections_utils.c \
				./parsing/redirections_utils2.c \
				./parsing/short_cmd.c \
				./parsing/short_cmd_utils.c \
				./parsing/expand.c \
				./parsing/expand_utils.c \
				./parsing/quotes.c \
				./execution/pipes.c\
                ./includes/get_next_line/get_next_line.c\
                ./includes/get_next_line/get_next_line_uti.c\
                ./built-in/ft_echo.c\
                ./built-in/exit.c\
                ./built-in/ft_pwd.c\
                ./built-in/ft_env.c\
                ./built-in/ft_cd.c\
                ./built-in/ft_unset.c\
                ./built-in/ft_export.c\
                ./execution/excute_redi.c\
                ./execution/check_builu_in.c\
                ./execution/export_utilties.c\
                ./execution/excution_util.c\
                ./execution/export_utilties2.c\
				./execution/ft_split_char.c \
				./execution/get_env.c \
				./execution/add_to_export.c \
				./execution/is_built.c \
					./includes/libft/ft_atoi.c \
                    ./includes/libft/ft_bzero.c \
                    ./includes/libft/ft_calloc.c \
                    ./includes/libft/ft_isalnum.c \
                    ./includes/libft/ft_isalpha.c \
                    ./includes/libft/ft_isascii.c \
                    ./includes/libft/ft_isdigit.c \
                    ./includes/libft/ft_isspace.c \
                    ./includes/libft/ft_isprint.c \
                    ./includes/libft/ft_itoa.c \
                    ./includes/libft/ft_lstadd_back.c \
                    ./includes/libft/ft_lstadd_front.c \
                    ./includes/libft/ft_lstclear.c \
                    ./includes/libft/ft_lstdelone.c \
                    ./includes/libft/ft_lstiter.c \
                    ./includes/libft/ft_lstlast.c \
                    ./includes/libft/ft_lstmap.c \
                    ./includes/libft/ft_lstnew.c \
                    ./includes/libft/ft_lstsize.c \
                    ./includes/libft/ft_memchr.c \
                    ./includes/libft/ft_memcmp.c \
                    ./includes/libft/ft_memcpy.c \
                    ./includes/libft/ft_memmove.c \
                    ./includes/libft/ft_memset.c \
                    ./includes/libft/ft_putchar_fd.c \
                    ./includes/libft/ft_putendl_fd.c \
                    ./includes/libft/ft_putnbr_fd.c \
                    ./includes/libft/ft_putstr_fd.c \
                    ./includes/libft/ft_split.c \
                    ./includes/libft/ft_strchr.c \
                    ./includes/libft/ft_strdup.c \
                    ./includes/libft/ft_striteri.c \
                    ./includes/libft/ft_strjoin.c \
                    ./includes/libft/ft_strlcat.c \
                    ./includes/libft/ft_strlcpy.c \
                    ./includes/libft/ft_strlen.c \
                    ./includes/libft/ft_strmapi.c \
                    ./includes/libft/ft_strncmp.c \
                    ./includes/libft/ft_strnstr.c \
                    ./includes/libft/ft_strrchr.c \
                    ./includes/libft/ft_strtrim.c \
                    ./includes/libft/ft_substr.c \
                    ./includes/libft/ft_tolower.c \
                    ./includes/libft/ft_toupper.c \
                         
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME)${CLR_RMV}..."
			${CC} ${FLAGS} $(OBJS) -I/usr/local/opt/readline/include -L/usr/local/opt/readline/lib -lreadline -o $(NAME)
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re


