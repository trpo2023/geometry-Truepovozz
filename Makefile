NAME = geometry
CFLAGS = -Wall -Werror
DIR_SRC = ./src/libgeometry/
DIR_OBJ = ./obj/

OBJ = $(DIR_OBJ)main.o $(DIR_OBJ)shape_info.o $(DIR_OBJ)syntax.o

all : $(NAME).o
$(NAME).o : $(OBJ)
	gcc $(CFLAGS) -o $(NAME) $^

$(DIR_OBJ)main.o : $(DIR_SRC)main.c
	gcc $(CFLAGS) -MMD -c $< -o $@

$(DIR_OBJ)shape_info.o : $(DIR_SRC)shape_info.c
	gcc $(CFLAGS) -MMD -c $< -o $@

$(DIR_OBJ)syntax.o : $(DIR_SRC)syntax.c
	gcc $(CFLAGS) -MMD -c $< -o $@	

-include main.d shape_info.d syntax.d
run: 
	./$(NAME) shapes

clean:
	rm $(NAME)
	rm $(DIR_OBJ)*.o
	rm $(DIR_OBJ)*.d