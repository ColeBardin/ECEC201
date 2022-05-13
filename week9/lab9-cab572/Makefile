TARGET = dict_count

CC = gcc
CFLAGS = -g -Wall -Wpedantic -Werror -fno-common 
BUILDDIR = ./build
LIBS = $(BUILDDIR)/test.a

.PHONY: clean, mrproper, test
.DEFAULT_GOAL := test

$(BUILDDIR)/$(TARGET): $(BUILDDIR)/$(TARGET).o $(LIBS)
	$(CC) $(CFLAGS) -o $@ $+

# Only built "offworld"
# $(BUILDDIR)/test.a: $(BUILDDIR)/test.o $(BUILDDIR)/dict.o
# 	ar rcs $@ $^

$(BUILDDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILDDIR):
	mkdir $@

all: $(BUILDDIR) $(BUILDDIR)/$(TARGET)

clean:
	rm -f $(BUILDDIR)/*.o core.*

mrproper: clean
	rm -f $(BUILDDIR)/$(TARGET)

test: $(BUILDDIR) $(BUILDDIR)/$(TARGET)
	$(BUILDDIR)/$(TARGET)
