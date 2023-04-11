NAME = geometry
CFLAGS = -Wall -Werror
DIR_SRC_LIB = ./src/libgeometry/
DIR_SRC = ./src/
DIR_OBJ = ./obj/

OBJ = $(DIR_OBJ)main.o $(DIR_OBJ)shape_info.o $(DIR_OBJ)syntax.o

all : $(NAME).o
$(NAME).o : $(DIR_OBJ)main.o $(DIR_OBJ)libgeometry.a
	gcc $(CFLAGS) -o $(NAME).o $^

$(DIR_OBJ)main.o : $(DIR_SRC)main.c
	gcc $(CFLAGS) -I ./src -MMD -c $< -o $@

$(DIR_OBJ)shape_info.o : $(DIR_SRC_LIB)shape_info.c
	gcc $(CFLAGS) -MMD -c $< -o $@

$(DIR_OBJ)syntax.o : $(DIR_SRC_LIB)syntax.c
	gcc $(CFLAGS) -MMD -c $< -o $@	

$(DIR_OBJ)libgeometry.a : $(DIR_OBJ)syntax.o $(DIR_OBJ)shape_info.o
	ar rcs $@ $^

-include main.d shape_info.d syntax.d
run: 
	./$(NAME) shapes

clean:
	rm $(NAME).o
	rm $(DIR_OBJ)*.o
	rm $(DIR_OBJ)*.d