SRC = ft_calloc.c \
	  ft_isprint.c \
	  ft_is_in.c \
	  ft_isspace.c \
	  ft_memmove.c \
	  ft_putstr_fd.c \
	  ft_strjoin.c \
	  ft_strjoin_and_free_s1.c \
	  ft_strncmp.c \
	  ft_tolower.c \
	  ft_isalnum.c \
	  ft_itoa.c \
	  ft_memset.c \
	  ft_split.c \
	  ft_strlcat.c \
	  ft_strnstr.c \
	  ft_toupper.c \
	  ft_isalpha.c \
	  ft_memchr.c \
	  ft_putchar_fd.c \
	  ft_strchr.c \
	  ft_strlcpy.c \
	  ft_strrchr.c \
	  ft_atoi.c \
	  ft_isascii.c \
	  ft_memcmp.c \
	  ft_putendl_fd.c \
	  ft_strdup.c \
	  ft_strlen.c \
	  ft_strlen_with_limiter_included.c \
	  ft_strlen_with_limiter_excluded.c \
	  ft_strtrim.c \
	  ft_bzero.c \
	  ft_isdigit.c \
	  ft_memcpy.c \
	  ft_putnbr_fd.c \
	  ft_striteri.c \
	  ft_strmapi.c \
	  ft_calloc.c \
	  ft_substr.c \
	  ft_free_array.c \
	  get_next_line.c \

BONUS = ft_lstadd_front_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstnew_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c \
		ft_lstsize_bonus.c
HEADER = libft.h
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(BONUS:.c=.o)
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rcs $(NAME) $^

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus : $(OBJ) $(OBJ_BONUS)
	ar -rcs $(NAME) $^

clean :
	rm -f $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all re clean fclean
