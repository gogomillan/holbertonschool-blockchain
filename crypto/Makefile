#
# Makefile that compiles all the previous functions and archives them into a
# static library.
# 
# Library name: libhblk_crypto.a
#
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu90 -ggdb3 -c
ARCHIVER = ar rcs
ODIR = obj
SRCS = $(wildcard *.c)
INCS = $(wildcard *.h)
_OBJ = $(SRCS:.c=.o)
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJ))
TARGET = libhblk_crypto.a
_DIRS=$(shell find . -type d)
_TRGT = $(subst .c,-test,$(SRCS))
_CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu90 -ggdb3
_IFLAGS = -I.
_LFLAGS = -L.
_LIBS = -l$(subst .a,,$(subst lib,,$(TARGET))) -lssl -lcrypto 

all: $(_TRGT)
	@echo "Test executables created!"

$(_TRGT): $(TARGET)
	$(CC) $(_CFLAGS) $(_IFLAGS) provided/_print_hex_buffer.c $(addprefix test/,$(subst test,main.c,$@)) $(_LFLAGS) $(_LIBS) -o $@

$(TARGET): $(INCS) $(ODIR) $(OBJS)
	$(ARCHIVER) $(TARGET) $(OBJS)
	@echo "Library complete!"

$(ODIR)/%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

$(ODIR):
	mkdir $(ODIR)

struct: provided test
	rm -rf $(filter-out . provided test,$(notdir $(_DIRS)))
	rm *-test
	
clean: $(ODIR)
	rm -rf $(ODIR)
	rm $(TARGET)

end: clean struct
	@echo "Project cleaned and ended!!"
