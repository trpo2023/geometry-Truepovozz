NAME =./ bin / geometry NAME - TEST =./ bin / geometry - test CFLAGS
        = -Wall - Werror DIR_SRC_LIB =./ src / libgeometry / DIR_SRC
        =./ src / DIR_OBJ =./ obj / src /

                DIR_SRC
        - TEST
        =./ test / DIR_OBJ - TEST =./ obj / test /

        OBJ
        = $(DIR_OBJ) main.o $(DIR_OBJ) shape_info.o $(DIR_OBJ)
                        syntax.o

                                .PHONY : all clean run test testrun

                                                 all : $(NAME) $(NAME)
    : $(DIR_OBJ) main.o $(DIR_OBJ) libgeometry.a gcc $(CFLAGS)
                - o $ @$
        ^ -lm

                        $(DIR_OBJ) main.o : $(DIR_SRC) main.c gcc
                                            $(CFLAGS)
                        - I./ -MMD - c $
                < -o $ @

                        $(DIR_OBJ) shape_info.o
    : $(DIR_SRC_LIB) shape_info.c gcc
      $(CFLAGS) - I./ -MMD
                        - c $
                < -o $ @

                        $(DIR_OBJ) syntax.o
    : $(DIR_SRC_LIB) syntax.c gcc
      $(CFLAGS) - I./ -MMD
                        - c $
                < -o $ @

                   $(DIR_OBJ) libgeometry.a
    : $(DIR_OBJ) syntax.o
      $(DIR_OBJ) shape_info.o ar rcs $ @$
        ^ -lm

                - include $(DIR_OBJ) main.d $(DIR_OBJ)
                                shape_info.d
                                $(DIR_OBJ) syntax.d run
    : $(NAME)
              ./ bin
                        / shapes

                                  test : $(NAME - TEST) $(NAME - TEST)
    : $(DIR_OBJ - TEST) main.o $(DIR_OBJ - TEST) geom_test.o gcc $(CFLAGS)
                - o $ @$
        ^./ obj / src / libgeometry.a
                        - lm

                          $(DIR_OBJ - TEST) main.o
    : $(DIR_SRC - TEST) main.c gcc
      $(CFLAGS) - I./ -c $
                < -o $ @

                        $(DIR_OBJ - TEST)
                                geom_test.o
    : $(DIR_SRC - TEST) geom_test.c gcc
      $(CFLAGS) - I./ -c $
                < -o $ @

                  testrun : $(NAME - TEST)

                                    clean : rm
                                            $(NAME - TEST) rm
                                            $(NAME)
rm $(DIR_OBJ) *.o rm $(DIR_OBJ) *.d rm $(DIR_OBJ - TEST) *.o
