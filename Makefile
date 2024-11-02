NAME = libftprintf.a
LIBFT = libft
CFLAGS = -Wall -Werror -Wextra

.PHONY: all clean fclean re

VPATH = format_handle \
		libft

FORMAT_HANDLE = c_handle.c s_handle.c p_handle.c d_handle.c \
				i_handle.c u_handle.c x_handle.c int_to_hex.c \
				ft_uitoa.c format_handle.c

ESCAPE_SEQUENCE_HANDLE = escape_sequence_handle.c write_hex.c

MAIN_FILES = ft_printf.c

SRC = $(FORMAT_HANDLE) $(ESCAPE_SEQUENCE_HANDLE) $(MAIN_FILES)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT).a
	$(MAKE) -C $(LIBFT) 
	cp $(LIBFT)/$(LIBFT).a $(NAME)
	ar rs $(NAME) $(OBJ)	

$(LIBFT).a:
	$(MAKE) -C $(LIBFT)

clean:
	$(MAKE) -C $(LIBFT) clean
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	$(RM) $(NAME)

re: fclean
	$(MAKE) -C $(LIBFT) re 
	$(MAKE) all

exe: all
	gcc -o a.out -lftprintf -L. main.c
