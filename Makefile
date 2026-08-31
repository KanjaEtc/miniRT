CC = cc

CFLAGS = -Wall -Wextra -Werror -I /home/adbarth/Criterion/include/

# CR_FLAGS = -Wall -Wextra -Werror -I /home/adbarth/Criterion/include/

# INCLUDES = header.h

SRCS = srcs/tuples_creation.c \
	srcs/tuples_comparison.c \
	srcs/tuples_basic_operations.c \
	srcs/tuples_complex_operations.c \
	

OBJ = $(SRCS:srcs/.c=object/.o)

CR_SRCS = test/test_tuples_creation.c \
		test/test_tuples_comparison.c \


CR_OBJ = $(CR_SRCS:test/.c=object/.o)

NAME = miniRT

CR_NAME = miniRT_test


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

test: $(CR_NAME)

$(CR_NAME) : $(OBJ) $(CR_OBJ)
	$(CC) $(CFLAGS) $^ -L /home/adbarth/Criterion/build/src/ -lcriterion -lm -o $@

clean: rm -rf $(OBJ) $(CR_OBJ)

fclean: clean
	rm -f $(NAME) $(CR_NAME)

re: fclean all

.PHONY : all test clean fclean re
