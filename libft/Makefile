NAME			= libft.a

SRCS			=	ft_atoi.c ft_isspace.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_memmove.c ft_calloc.c ft_strjoin.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_substr.c ft_strmapi.c ft_strtrim.c ft_itoa.c ft_striteri.c ft_split.c

OBJS			=	ft_atoi.o ft_isspace.c ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memset.o ft_strchr.o ft_strdup.o ft_strlcat.o ft_strlcpy.o ft_strlen.o ft_strncmp.o ft_strnstr.o ft_strrchr.o ft_tolower.o ft_toupper.o ft_memmove.o ft_calloc.o ft_strjoin.o ft_putchar_fd.o ft_putstr_fd.o ft_putnbr_fd.o ft_putendl_fd.o ft_substr.o ft_strmapi.o ft_strtrim.o ft_itoa.o ft_striteri.o ft_split.o

BONUS			=	ft_lstnew.c ft_lstlast.c ft_lstsize.c ft_lstadd_back.c ft_lstadd_front.c ft_lstiter.c ft_lstdelone.c ft_lstclear.c ft_lstmap.c

OBJSBONUS = ${BONUS:.c=.o}
 
CC      = gcc
RM      = rm -f

FLAGS			= -Wall -Werror -Wextra 

INCLUDES 		= libft.h

all:			$(NAME)

$(NAME):		$(OBJS) $(INCLUDES)
				gcc -c $(FLAGS) $(SRCS)
				ar -rcs $(NAME) $(OBJS)
				ranlib $(NAME)

bonus: ${OBJS} ${OBJSBONUS}
		ar rcs ${NAME} ${OBJS} ${OBJSBONUS}
 
clean:
				/bin/rm -f $(OBJS) $(OBJSBONUS)

fclean:			clean
				/bin/rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re bonus