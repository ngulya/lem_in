LEM = lem-in

CC = gcc

SRC = ./src/

LIBFT = ./libft

HSR = ./lem.h

FILE = 	./lem_in.o \
		./error_fn.o \
		./size_name_room.o \
		./correct_link.o \
		./matrix_func.o \
		./find_all_way.o \
		./for_vuvod_two.o \
		./for_vuvod_func.o \
		./for_ant_go_two.o \
		./for_for_ant_go.o \
		./free_var_ant.o \
		./ft_strndup.o \
		./create_link_way.o \
		./for_find_all_way.o \
		./for_vuvod.o \
		./for_ant_go.o \
		./all_room.o \
		./vuvod.o \
		./ants_go_go_go.o \
		./dop_dop_function_write.o \
		./create_map.o

OBJ = $(FILE:.o=.c)

all: liba comp

liba:
	@make -C $(LIBFT)

comp:
	@$(CC) -Wall -Wextra -Werror $(OBJ) ./libft/libft.a -o $(LEM)

clean:
	@make clean -C $(LIBFT)

fclean:
	@-/bin/rm -f $(LEM)
	@make fclean -C $(LIBFT)

re: fclean all