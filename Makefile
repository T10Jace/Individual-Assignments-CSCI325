
# This is the makefile for Assignment 3: Linked List phone book

CC = g++
CFLAGS = -g -Wall
TARGET = Phonebook  # assigning Phonebook as the target

# default: Phonebook

# Executable files for this project are: phonebook.o, main.o
(TARGET):	phonebook.o main.o
	$(CC) $(CFlags) -o $(TARGET) phonebook.o main.o


# Creating phonebook.o
phonebook.o:	phonebook.cpp phonebook.h
	$(CC) $(CFLAGS) -c phonebook.cpp


# Creating main.o
main.o:	main.cpp phonebook.h
	$(CC) $(CFLAGS) -c main.cpp


# Creating "make clean"
clean:
	$(RM) $(TARGET) *.o *~
