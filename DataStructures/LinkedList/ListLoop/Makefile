CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11

BUILDDIR = build

SOURCES = HasLoop.c

TARGET = $(BUILDDIR)/has_loop

has_loop: $(TARGET)
run_test: 
	make has_loop
	bash tester.sh $(TARGET)
	make clean

$(TARGET):
	mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $(SOURCES) -o $@ -lm

clean:
	rm -rf *.o $(BUILDDIR)

rebuild:
	make clean 
	make has_loop
