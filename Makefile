###############################################################################
# CS2 2 Winter 2018
#
# This is a template Makefile. Edit it however you find
# convenient.
# 
# The current version of this file should compile programs just fine on
# Debian-based Linux operating systems.
#
###############################################################################

CC = g++
FLAGS = -g -std=c++11 -Werror -Wall

INCLUDE = 
LIBDIR = 
SOURCES = *.cpp
LIBS = 

EXENAME = sudoku

all: $(SOURCES)
	$(CC) $(FLAGS) -o $(EXENAME) $(INCLUDE) $(LIBDIR) $(SOURCES) $(LIBS)

clean:
	rm -f *.o $(EXENAME)

.PHONY: all clean


