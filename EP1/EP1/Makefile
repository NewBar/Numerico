BUILD_DIR := build
TARGET := ep

SOURCES = $(wildcard *.cpp)
OBJECTS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

.PHONY: all clean run format

all: ep

$(BUILD_DIR):
	@echo "Creating build directory"
	@mkdir -p $@

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	g++ -g -Wall -Wextra -std=c++11 -o $@ -c $^

clean:
ifeq ($(OS), Windows_NT)
	rm -r $(BUILD_DIR) *.exe
else
	rm -r $(BUILD_DIR) ep
endif

ep: $(OBJECTS)
	g++ -g -Wall -Wextra -o ep $(OBJECTS)

run: all
ifeq ($(OS), Windows_NT)
	start powershell -NoExit ./ep
else
	./ep
endif

.PHONY: all clean ep run
