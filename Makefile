NAME = libftprintf.a
LIBFT = libft
CFLAGS = -Wall -Werror -Wextra

.PHONY: all clean fclean re

VPATH = format_handle

FORMAT_HANDLE = c_handle.c s_handle.c p_handle.c d_handle.c \
				i_handle.c u_handle.c x_handle.c int_to_hex.c \
				ft_uitoa.c format_handle.c

MAIN_FILES = ft_printf.c

SRC = $(FORMAT_HANDLE) $(MAIN_FILES) 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT) 
	cp $(LIBFT)/$(LIBFT).a $(NAME)
	ar rs $(NAME) $(OBJ)	

clean:
	$(MAKE) -C $(LIBFT) clean
	rm -r $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm $(NAME)

re: fclean
	$(MAKE) -C $(LIBFT) re 
	$(MAKE) all
