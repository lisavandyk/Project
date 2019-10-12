.RECIPEPREFIX +=
CC = g++
CFLAGS = -Wall -lm -lrt -lwiringPi -lpthread

PROG = bin/*
OBJS = obj/*

default:
    mkdir -p bin obj
    $(CC) $(CFLAGS) -c src/ADC.c -o obj/ADC
    $(CC) $(CFLAGS) obj/ADC -o bin/ADC

run:
    sudo ./bin/ADC

clean:
    rm $(PROG) $(OBJS)
