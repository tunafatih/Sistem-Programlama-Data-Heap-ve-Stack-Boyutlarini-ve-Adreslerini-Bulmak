INC = ./include/
BIN = ./bin/
SRC = ./src/
LIB = ./lib/
OBJS = ./objs/

hepsi: $(libOBJS) libfdr.a
	gcc -g -I $(INC) -o soru1 $(SRC)soru1.c $(LIB)libfdr.a -lm
	gcc -g -I $(INC) -o soru2 $(SRC)soru2.c $(LIB)libfdr.a -lm
	 

libfdr.a: $(addprefix $(OBJS), $(libOBJS))
	ar rcs $(LIB)libfdr.a $+
	ranlib $(LIB)libfdr.a

$(libOBJS): %.o: $(SRC)%.c
	gcc -o $(OBJS)$@ -I $(INC) -c $<
