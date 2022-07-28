CC 		= gcc-4.8
CFLAGS 	= -Wall -Werror -Wextra -pedantic -g

_SRC 	= nm.c \
		  elf_utils.c \
		  elf_utils_1.c \
		  elf_print.c \
		  elf_functions.c \
		  elf_functions_32.c \
		  elf_functions_64.c \
		  elf_symbols_tables.c \
		  print_buffer.c

_SRC1 	= objdump.c \
		  elf_functions.c \
		  elf_utils.c \
		  elf_utils_1.c \
		  elf_utils_2.c \
		  elf_print.c \
		  elf_functions_32.c \
		  elf_functions_64.c \
		  elf_header.c \
		  print_buffer.c

SRC 	= $(patsubst %,%,$(_SRC))
SRC1	= $(patsubst %,%,$(_SRC1))

_OBJ	= $(_SRC:.c=.o)
OBJECTS = $(patsubst %,%,$(_OBJ))

_OBJ1	= $(_SRC1:.c=.o)
OBJECTS1 = $(patsubst %,%,$(_OBJ1))

IDIR	= .
SDIR	= .
ODIR	= .

OUTPUT	= hnm
OUTPUT1 = hobjdump

%.o : %.c
		$(CC) $(CFLAGS) -c -o $@ $< -I$(IDIR)

all : $(OUTPUT) $(OUTPUT1)

hnm: $(OUTPUT)

hobjdump : $(OUTPUT1)

$(OUTPUT) : $(OBJECTS)
		$(CC) -o $@ $^ $(LINKS)

$(OUTPUT1) : $(OBJECTS1)
		$(CC) -o $@ $^ $(LINKS)

.PHONY : clean

clean :
	rm *.o

re: $(OBJ) $(OBJ1)
