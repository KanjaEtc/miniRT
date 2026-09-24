CC = cc

NAME = miniRT
TEST_NAME = miniRT_test

CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I include
LDLIBS = -lm

CRITERION_INC = -I /home/adbarth/Criterion/include
CRITERION_LIB = -L /home/adbarth/Criterion/build/src -lcriterion

LIBFT_DIR = libft


SRCS = srcs/canvas_and_pixels.c \
	   srcs/colors.c \
	   srcs/display.c \
	   srcs/matrix_basics.c \
	   srcs/matrix_operations.c \
	   srcs/matrix_determinant.c \
	   srcs/matrix_inversion.c \
	   srcs/parsing.c \
	   srcs/parsing_create_world.c \
	   srcs/parsing_init_struct.c \
	   srcs/parsing_init_list.c \
	   srcs/parsing_fill_world.c \
	   srcs/parsing_list_utils.c \
	   srcs/transformations.c \
	   srcs/tuples_creation.c \
	   srcs/tuples_utils.c \
	   srcs/tuples_comparison.c \
	   srcs/tuples_basic_operations.c \
	   srcs/tuples_complex_operations.c \
	   srcs/utils_free.c \
	   srcs/utils_free_struct.c \
	   srcs/utils_array.c \
	   srcs/utils_list_addback.c \
	   srcs/utils_list_clear.c \
	   srcs/main.c

OBJS = $(patsubst srcs/%.c,object/%.o,$(SRCS))


TEST_SRCS = test/test_canvas_and_pixels.c \
			test/test_colors.c \
			test/test_matrix_basics.c \
			test/test_matrix_determinant.c \
			test/test_matrix_inversion.c \
			test/test_matrix_operations.c \
			test/test_transformations.c \
			test/test_tuples_creation.c \
			test/test_tuples_comparison.c \
			test/test_tuples_basic_operations.c \
			test/test_tuples_complex_operations.c

TEST_OBJS = $(patsubst test/%.c,object/%.o,$(TEST_SRCS))


# Tous les objets du projet sauf main.o et parsing_list.o
PROJECT_TEST_OBJS = $(filter-out object/main.o,$(OBJS))


all: $(NAME)


$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(OBJS) -L$(LIBFT_DIR) -lft $(LDLIBS) -o $(NAME)


object/%.o: srcs/%.c
	@mkdir -p object
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@


test: $(TEST_NAME)
	./$(TEST_NAME)


$(TEST_NAME): $(TEST_OBJS) $(PROJECT_TEST_OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(TEST_OBJS) $(PROJECT_TEST_OBJS) \
		-L$(LIBFT_DIR) -lft \
		$(CRITERION_LIB) \
		$(LDLIBS) \
		-o $(TEST_NAME)


object/test_%.o: test/test_%.c
	@mkdir -p object
	$(CC) $(CFLAGS) $(CPPFLAGS) $(CRITERION_INC) -c $< -o $@


clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(TEST_OBJS)


fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(TEST_NAME)


re: fclean all


.PHONY: all test clean fclean re
