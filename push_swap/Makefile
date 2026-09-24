NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I. -Ilibft
SRCS = main.c radix.c rules_comp.c rules_med_sim_1.c rules_med_sim_2.c \
extra_rules.c parsing.c adaptive_algo.c check_mode.c disorder_metric.c \
bench.c medium_algo_utils.c medium_algo_range.c simple_algo_bubble.c sort_3_5.c\

LIBFT_DIR = libft
LIBFT_SRC = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT_SRC)
	cp $(LIBFT_SRC) $(NAME)
	cc $(CFLAGS) $(SRCS) $(LIBFT_SRC) -o $(NAME)

$(LIBFT_SRC): 
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re