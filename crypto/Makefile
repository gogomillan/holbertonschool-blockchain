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

$(TARGET): $(INCS) $(ODIR) $(OBJS)
	$(ARCHIVER) $(TARGET) $(OBJS)
	@echo "Library complete!"

$(ODIR)/%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

$(ODIR):
	mkdir $(ODIR)

clean:
	rm -rf $(ODIR)
	rm $(TARGET)

end:
	rm -rf $(ODIR)
