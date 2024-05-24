# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -g
LDFLAGS := -lgtest -lgtest_main -pthread

MKDIR := mkdir -p
RMDIR := rm -rf
MV_DIR := mv -f

INC_DIR := inc
SRC_DIR := src
TEST_DIR := test/src
BUILD_DIR := build
DEP_DIR := $(BUILD_DIR)/dep
BIN_DIR := bin
TARGET := debugBin
TEST_TARGET := testBin

SRC_EXT := cpp
SOURCES := $(wildcard $(SRC_DIR)/*.$(SRC_EXT))
OBJECTS := $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SOURCES:.$(SRC_EXT)=.o))
DEPS := $(patsubst $(SRC_DIR)/%,$(DEP_DIR)/%,$(SOURCES:.$(SRC_EXT)=.d))

TEST_SOURCES := $(wildcard $(TEST_DIR)/*.$(SRC_EXT))
TEST_OBJECTS := $(patsubst $(TEST_DIR)/%,$(BUILD_DIR)/%,$(TEST_SOURCES:.$(SRC_EXT)=.o))
TEST_DEPS := $(patsubst $(TEST_DIR)/%,$(DEP_DIR)/%,$(TEST_SOURCES:.$(SRC_EXT)=.d))

CXXFLAGS += -I$(INC_DIR)

build: $(TARGET)

test: $(TEST_TARGET)

all: build test

$(TARGET): $(OBJECTS)
	@$(MKDIR) $(BIN_DIR)
	@$(CXX) $^ -o $(BIN_DIR)/$(TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.$(SRC_EXT)
	@$(MKDIR) $(dir $@) $(DEP_DIR)
	@$(CXX) $(CXXFLAGS) -MMD -MP -c -o $@ $<
	@$(MV_DIR) $(BUILD_DIR)/$*.d $(DEP_DIR)/$*.d

$(TEST_TARGET): $(filter-out $(BUILD_DIR)/main.o, $(OBJECTS)) $(TEST_OBJECTS)
	@$(MKDIR) $(BIN_DIR)
	@$(CXX) $^ $(LDFLAGS) -o $(BIN_DIR)/$(TEST_TARGET)

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.$(SRC_EXT)
	@$(MKDIR) $(dir $@) $(DEP_DIR)
	@$(CXX) $(CXXFLAGS) -MMD -MP -c -o $@ $<
	@$(MV_DIR) $(BUILD_DIR)/$*.d $(DEP_DIR)/$*.d

-include $(DEPS) $(TEST_DEPS)

run:
	@./$(BIN_DIR)/$(TARGET)

.PHONY: clean
clean:
	@$(RMDIR) $(BUILD_DIR) $(BIN_DIR)