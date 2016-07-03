OS_TARGET := $(shell uname)
CC := gcc
CFLAGS := -Wall -Wextra -Wno-unused-parameter -std=c11 -ICinyTest
LDFLAGS := -LCinyTest
LDLIBS := -lcinytest -lm
SP := strip
SRC_FILES := $(addprefix src/,Rectangle.c RectangleTests.c)
BUILD_DIR := build
TARGET := $(BUILD_DIR)/recttests

ifeq ($(OS_TARGET), Darwin)
MACOS := 1
endif

ifdef MACOS
CC := clang
CFLAGS += -pedantic -Wno-gnu-zero-variadic-macro-arguments
endif

ifdef XCFLAGS
CFLAGS += $(XCFLAGS)
endif

ifndef SPFLAGS
ifdef MACOS
SPFLAGS := -
else
SPFLAGS := -s
endif
endif

.PHONY: release debug build clean check

release: CFLAGS += -Os
release: build
	$(SP) $(SPFLAGS) $(TARGET)

debug: CFLAGS += -g -O0 -DDEBUG
debug: build

build:
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC_FILES) $(LDFLAGS) $(LDLIBS) -o $(TARGET)

check:
	$(TARGET)

clean:
	$(RM) -r $(BUILD_DIR)
