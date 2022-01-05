#
# names
#
NAME := push_swap

RM := rm -rf

CC := gcc

CFLAGS := -Wall -Werror -Wextra

#
# rules not to mixed with similar file names
#
.PHONY: all clean fclean re

#
# directories
#
INCLUDE := include/

SRC_DIR := src/

LIB_DIR := libft/

#
# necessary files
#
CFILES := main.c create_stack.c stack_utils.c stack_utils_2.c utils.c sort.c div_sort.c
HFILES := $(INCLUDE)push_swap.h

SRC := $(addprefix $(SRC_DIR), $(CFILES))
C_SRC := $(addprefix $(SRC_DIR), checker.c create_stack.c stack_utils.c stack_utils_2.c sort.c div_sort.c utils.c get_next_line.c)

OBJ := $(SRC:.c=.o)
C_OBJ := $(C_SRC:.c=.o)

LIB := libft/libft.a

FT := ft

#
# rules
#
all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -L$(LIB_DIR) -l$(FT)

checker: $(C_OBJ) $(LIB)
	$(CC) $(CFLAGS) -o $@ $(C_OBJ) -L$(LIB_DIR) -l$(FT)

$(LIB):
	make -C $(LIB_DIR) bonus
	make -C $(LIB_DIR) clean

%.o: %.c $(HFILES)
	$(CC) $(CFLAGS) -c $< -I$(INCLUDE) -o $@

clean:
	$(RM) $(OBJ) $(C_OBJ)

fclean: clean
	$(RM) $(NAME) checker
	make -C $(LIB_DIR) fclean

re: fclean all
