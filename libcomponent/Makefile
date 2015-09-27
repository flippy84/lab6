 # Erik Ekström
 # erek0016@student.umu.se
 # 2015-09-26
 #
 # Uppgift 6: libcomponent.so
 #

CC = gcc
CC_FLAGS = -Wall -Wextra -std=c99

BASE_DIR = $(shell pwd)
BUILD_DIR ?= build
BIN_DIR ?= $(BASE_DIR)/$(BUILD_DIR)/bin
OBJS_DIR ?= $(BASE_DIR)/$(BUILD_DIR)/objs
LIBS_DIR ?= $(BASE_DIR)/$(BUILD_DIR)/libs

BIN_FILE = $(BIN_DIR)/program

SRCS = libcomponent_test.c
LIB_NAMES = libcomponent
OBJS = $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(LIB_NAMES)))
LIBS = $(addprefix $(LIBS_DIR)/, $(addsuffix .so, $(LIB_NAMES)))
LINK_LIBS = $(addprefix -l, \
		$(foreach lib, \
			$(notdir $(LIB_NAMES)), \
			$(shell echo $(lib) | sed -r 's/lib//')))

$(shell mkdir -p $(BIN_DIR))
$(shell mkdir -p $(OBJS_DIR))
$(shell mkdir -p $(LIBS_DIR))

all: $(BIN_FILE)

libs: $(LIBS)


$(OBJS_DIR)/%.o: %.c %.h
	$(CC) $(CC_FLAGS) -fPIC -c -o $@ $<

$(LIBS_DIR)/%.so: $(OBJS_DIR)/%.o
	$(CC) $(CC_FLAGS) -shared -fPIC -o $@ $<

$(BIN_FILE): $(LIBS)
	$(CC) $(CC_FLAGS) -o $@ $(SRCS) -L$(LIBS_DIR) \
			      $(LINK_LIBS) -Wl,-rpath,$(LIBS_DIR)


clean:
	rm -f $(OBJS)
	rm -f $(LIBS)
	rm -f $(BIN_FILE)
