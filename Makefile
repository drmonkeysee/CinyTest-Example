OS_TARGET := $(shell uname)
CC := gcc
CFLAGS := -Wall -Wextra -pedantic -Wno-unused-parameter -Os -std=c11 -ICinyTest
LDFLAGS := -LCinyTest
LDLIBS := -lcinytest -lm
SP := strip
SRC_FILES := $(addprefix src/,Rectangle.c RectangleTests.c)
TARGET := recttests

ifeq ($(OS_TARGET), Darwin)
CC := clang
CFLAGS += -Wno-gnu-zero-variadic-macro-arguments
endif

ifdef XCFLAGS
CFLAGS += $(XCFLAGS)
endif

.PHONY: build clean check

build:
	$(CC) $(CFLAGS) $(SRC_FILES) $(LDFLAGS) $(LDLIBS) -o $(TARGET)
	$(SP) $(TARGET)

check: build
	./$(TARGET)

clean:
	$(RM) $(TARGET)
