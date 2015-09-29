 # EE, AC, LK
 # 2015-09-29
 #
 # Uppgift 6
 #

CC := gcc
C_FLAGS := -Wall -Wextra -std=c99

APP_NAME ?= electrotest
LIB_NAMES := libcomponent libresistance

# Directories
LIB_DIR ?= lib
OBJ_DIR ?= obj
BIN_DIR ?= .

# Installation directories
USR_LIB := /usr/lib
USR_BIN := /usr/bin

# Components
OBJS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(LIB_NAMES)))
LIBS = $(addprefix $(LIB_DIR)/, $(addsuffix .so, $(LIB_NAMES)))
BINS = $(addprefix $(BIN_DIR)/, $(APP_NAME))

# Link flags
LINK_LIBS = $(addprefix -l, \
		$(foreach lib, \
			$(notdir $(LIB_NAMES)), \
			$(shell echo $(lib) | sed -r 's/lib//')))

# Include flags
INCLUDES := $(addprefix -I, $(LIB_NAMES))

# Create dirs if needed 
$(shell mkdir -p $(LIB_DIR))
$(shell mkdir -p $(OBJ_DIR))

# Phony targets
.PHONY: all
all: $(OBJS) $(LIBS) $(BINS)

.PHONY: lib
lib: $(OBJS) $(LIBS)


.PHONY: install
install:
	sudo $(MAKE) all LIB_DIR=$(USR_LIB) BIN_DIR=$(USR_BIN)

.PHONY: uninstall
uninstall:
	sudo $(MAKE) clean BIN_DIR=$(USR_BIN) LIB_DIR=$(USR_LIB)

.PHONY: clean
clean:
	rm -f $(OBJS)
	rm -f $(LIBS)
	rm -f $(BINS)


# Real targets
$(BIN_DIR)/%: %.c
	$(CC) $(C_FLAGS) -o $@ $< -L$(LIB_DIR) \
		$(INCLUDES) $(LINK_LIBS) -Wl,-rpath,$(LIB_DIR)

$(OBJ_DIR)/%.o: libcomponent/%.c libcomponent/%.h 
	$(CC) $(C_FLAGS) -fPIC -c -o $@ $<


$(OBJ_DIR)/%.o: libresistance/%.c libresistance/%.h 
	$(CC) $(C_FLAGS) -fPIC -c -o $@ $<


$(OBJ_DIR)/%.o: libpower/%.c libpower/%.h
	$(CC) $(C_FLAGS) -fPIC -c -o $@ $<

$(LIB_DIR)/%.so: $(OBJ_DIR)/%.o
	$(CC) $(C_FLAGS) -shared -fPIC -o $@ $<
