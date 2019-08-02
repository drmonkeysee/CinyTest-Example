OS_TARGET := $(shell uname)
CC := gcc
CFLAGS := -Wall -Wextra -Werror -Wno-unused-parameter -std=c11 -iquoteCinyTest
LDFLAGS := -LCinyTest
LDLIBS := -lcinytest -lm
SP := strip
SPFLAGS := -s
SRC_FILES := $(wildcard src/*.c)
BUILD_DIR := build
TARGET := $(BUILD_DIR)/recttests

ifeq ($(OS_TARGET), Darwin)
CC := clang
SPFLAGS := -
endif

ifeq ($(CC), clang)
CFLAGS += -pedantic -Wno-gnu-zero-variadic-macro-arguments
endif

ifdef XCFLAGS
CFLAGS += $(XCFLAGS)
endif

.PHONY: release debug build clean demo check

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

demo: LEVELS := 0 1 2 3
demo: SEP := ==================================================
demo:
	$(TARGET) --ct-help
	@echo $(SEP)
	$(TARGET) --ct-version
	@echo $(SEP)
	$(foreach lvl,$(LEVELS),$(TARGET) --ct-verbose=$(lvl) ;)
	@echo $(SEP)
	$(TARGET) --ct-colorized=n
	@echo $(SEP)
	$(TARGET) --ct-suppress-output=n
	@echo $(SEP)
	$(TARGET) --ct-include=circle_tests:,:*calculatesarea
	@echo $(SEP)
	$(TARGET) --ct-include=*calculates* --ct-exclude=*area
	@echo $(SEP)
	$(TARGET) --ct-include=*calculates* --ct-verbose=3
	@echo $(SEP)
	$(TARGET) --ct-exclude=*area --ct-verbose=3
	@echo $(SEP)
	$(TARGET) --ct-include=*calculates* --ct-exclude=*area --ct-verbose=3
	@echo $(SEP)
	$(TARGET) --ct-include=*calculates* --ct-verbose=3 --ct-colorized=n
	@echo $(SEP)
	$(TARGET) --ct-exclude=*area --ct-verbose=3 --ct-colorized=n
	@echo $(SEP)
	$(TARGET) --ct-include=*calculates* --ct-exclude=*area --ct-verbose=3 \
		--ct-colorized=n

clean:
	$(RM) -r $(BUILD_DIR)
