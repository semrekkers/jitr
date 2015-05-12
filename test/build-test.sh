#!/bin/sh

gcc -std=c99 -D JITR_ARCH=i386 -m32 -I ../include -O0 -g -o test ../src/parser.c test.c

