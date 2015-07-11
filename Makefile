CXX      = g++
CXXFLAGS = -c -Wall
#LDFLAGS  =
MKDIR_P = mkdir -p

SOURCE_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
BIN_DIR = bin
EXECUTABLE = archipelego

SOURCES = $(notdir $(wildcard $(SOURCE_DIR)/*.cpp))
OBJECTS = $(SOURCES:%.cpp=$(OBJ_DIR)/%.o)

all: intro dirs $(OBJECTS) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@echo "Linking..."
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $(BIN_DIR)/$(EXECUTABLE)
	@echo "Done.\n"

$(OBJ_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	@echo "Compiling $< ..."
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) $< -o $@
	@echo "Done.\n"

dirs: $(OBJ_DIR) $(BIN_DIR)

$(OBJ_DIR) $(BIN_DIR):	
	@echo "Creating output folder..."
	$(MKDIR_P) $@;
	@echo "Done.\n"

intro:
	@echo "Making sources $(SOURCES) for $(EXECUTABLE).\n"

clean:
	rm -rf $(EXECUTABLE) $(OBJ_DIR) $(BIN_DIR)

.PHONY: intro dirs all clean