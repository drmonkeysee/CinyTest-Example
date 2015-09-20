CC := gcc
CFLAGS := -Wall -Werror -pedantic -Wno-gnu-zero-variadic-macro-arguments -Os -std=c11 -ICinyTest
LDFLAGS := -LCinyTest -lcinytest -lm
SRC_FILES := $(addprefix src/,Rectangle.c RectangleTests.c)
TARGET := recttests

.PHONY: build clean check

build:
	$(CC) $(CFLAGS) $(SRC_FILES) $(LDFLAGS) -o $(TARGET)

check: build
	./$(TARGET)

clean:
	rm $(TARGET)
