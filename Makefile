CC := clang
CFLAGS := -Wall -Wextra -pedantic -Wno-gnu-zero-variadic-macro-arguments -Wno-unused-parameter -Os -std=c11 -ICinyTest $(XCFLAGS)
LDFLAGS := -LCinyTest
LDLIBS := -lcinytest -lm
SP := strip
SRC_FILES := $(addprefix src/,Rectangle.c RectangleTests.c)
TARGET := recttests

.PHONY: build clean check

build:
	$(CC) $(CFLAGS) $(SRC_FILES) $(LDFLAGS) $(LDLIBS) -o $(TARGET)
	$(SP) $(TARGET)

check: build
	./$(TARGET)

clean:
	$(RM) $(TARGET)
