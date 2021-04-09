#
# Makefile utitlities for hblk_cryto
# 
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu90 -ggdb3 -c
ARCHIVER = ar rcs
ODIR = obj
SRCS = $(wildcard *.c)
INCS = $(wildcard *.h)
OBJ = $(SRCS:.c=.o)
OBJS = $(patsubst %,$(ODIR)/%,$(OBJ))
TARGET = libhblk_crypto.a
_DIRS=$(shell find . -type d)
_TRGT = $(subst .c,-test,$(SRCS))
_CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu90 -ggdb3
_IFLAGS = -I.
_LFLAGS = -L.
_LIBS = -l$(subst .a,,$(subst lib,,$(TARGET))) -lssl -lcrypto 

usage:
	@echo "Usage:"
	@echo "  make all"
	@echo "  make [sha256-test | ec_create-test | ec_from_pub-test | ec_load-test | ec_save-test | ec_sign-test | ec_to_pub-test | ec_verify-test | sha256-test]"
	@echo "  make libhblk_crypto.a"
	@echo "  make clean"
	@echo "  make end"

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
	@mkdir $(ODIR)

struct: provided test
	@rm -rf $(filter-out . provided test,$(notdir $(_DIRS)))
	@rm *-test
	
clean: $(ODIR)
	$(shell rm -rf $(ODIR))
	$(shell [ -e $(TARGET) ] && rm $(TARGET))
	@echo "Library clened"

end: clean struct
	@echo "Project cleaned and ended!!"
