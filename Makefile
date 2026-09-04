CC = cc

CFLAGS = -Wall -Wextra -Werror -I /home/adbarth/Criterion/include/ -lm

# CR_FLAGS = -Wall -Wextra -Werror -I /home/adbarth/Criterion/include/

# INCLUDES = header.h

SRCS = srcs/canvas_and_pixels.c \
	srcs/display.c \
	srcs/matrix_basics.c \
	srcs/matrix_operations.c \
	srcs/matrix_determinant.c \
	srcs/matrix_inversion.c \
	srcs/tuples_creation.c \
	srcs/tuples_comparison.c \
	srcs/tuples_basic_operations.c \
	srcs/tuples_complex_operations.c \
	srcs/utils_free.c \


OBJ = $(SRCS:srcs/.c=object/.o)

CR_SRCS = test/test_canvas_and_pixels.c \
		test/test_matrix_basics.c \
		test/test_matrix_determinant.c \
		test/test_matrix_inversion.c \
		test/test_matrix_operations.c \
		test/test_tuples_creation.c \
		test/test_tuples_comparison.c \
		test/test_tuples_basic_operations.c \
		test/test_tuples_complex_operations.c \


CR_OBJ = $(CR_SRCS:test/.c=object/.o)

NAME = miniRT

CR_NAME = miniRT_test


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

test: $(CR_NAME)

$(CR_NAME) : $(OBJ) $(CR_OBJ)
	$(CC) $(CFLAGS) $^ -L /home/adbarth/Criterion/build/src/ -lcriterion -o $@

clean: rm -rf $(OBJ) $(CR_OBJ)

fclean: clean
	rm -f $(NAME) $(CR_NAME)

re: fclean all

.PHONY : all test clean fclean re
