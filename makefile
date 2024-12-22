CFLAGS := -g -Wall
LDLIBS := -lm
SRC_DIR := src
BUILD_DIR := build
OBJS := $(patsubst $(SRC_DIR)/%/,$(BUILD_DIR)/%.o,$(dir $(wildcard $(SRC_DIR)/*/main.c)))

.PHONY: list clean

list:
	@LC_ALL=C $(MAKE) -pRrq -f $(firstword $(MAKEFILE_LIST)) : 2>/dev/null | awk -v RS= -F: '/(^|\n)# Files(\n|$$)/,/(^|\n)# Finished Make data base/ {if ($$1 !~ "^[#.]") {print $$1}}' | sort | grep -E -v -e '^[^[:alnum:]]' -e '^$@$$'
clean:
	rm -rf $(BUILD_DIR)

#run
$(patsubst $(BUILD_DIR)/%.o,%,$(OBJS)): %: $(BUILD_DIR)/%
	$<

# compile
$(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%/main.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# link
$(OBJS:.o=): %: %.o 
# use implicit rules
