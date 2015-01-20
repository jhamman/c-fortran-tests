# Test makefile

# Source PATH
SRCPATH = ../src

# Include PATH
INCLUDEPATH = ../include

# Set SHELL = your shell here
SHELL = /bin/bash

# Set CC = your compiler here
CC = gcc

# Set F90 = your Fortran compiler here
FC = gfortran

# set includes
INCLUDES = -I ${INCLUDEPATH}

# Flags
CFLAGS =  ${INCLUDES} -g -Wall -Wno-unused -std=c99 
# uncomment for intel compilers (ifort)
#FFLAGS = -nofor-main

# -----------------------------------------------------------------------
# MOST USERS DO NOT NEED TO MODIFY BELOW THIS LINE
# -----------------------------------------------------------------------

.SUFFIXES: .c .F90 .o

.c.o:
	$(CC) -c $(CFLAGS) $<

.F90.o:
	$(F90) -c $(FFLAGS) $<

HDRS = \
	${INCLUDEPATH}/test.h

TARGET = test.exe

SRCS = \
	${SRCPATH}/test1_c.c \
	${SRCPATH}/test_print.c \
	${SRCPATH}/make_cn_struct.c \
	${SRCPATH}/test1.F90

# test.o: test.h

OBJS = $(addsuffix .o,$(basename $(SRCS)))

$(TARGET) : $(OBJS)
		$(FC) $(FFLAGS) -o $@ $^
%.o: %.c
		$(CC) -c $(CFLAGS) -o $@ $< $(FLIBS)
%.o: %.F90
		$(FC) -c $(FFLAGS) -o $@ $< $(FLIBS)

.PHONY : clean
clean:
		rm -f *.o $(OBJS) $(TARGET)
