CXX      = g++
CXXFLAGS = -c -Wall
DEFINES  = 
#LDFLAGS  =
MKDIR_P = mkdir -p

SOURCE_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
BIN_DIR = bin
EXECUTABLE = archipelego

INCLUDES = $(notdir $(wildcard $(INCLUDE_DIR)/*.h))
SOURCES = $(notdir $(wildcard $(SOURCE_DIR)/*.cpp))
OBJECTS = $(notdir $(SOURCES:%.cpp=$(OBJ_DIR)/%.o))

all: intro dirs $(OBJECTS) $(BIN_DIR)/$(EXECUTABLE)
	@echo "All done."

debug: DEFINES += DEBUG
debug: all

#TODO: make depends on headers.
#TODO: clean and recompile if release changed to debug and vv.

$(BIN_DIR)/$(EXECUTABLE): $(OBJ_DIR)/$(OBJECTS)
	@echo "Linking..."
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $(BIN_DIR)/$(EXECUTABLE)
	@echo "Done.\n"

$(OBJ_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	@echo "Compiling $< ..."
	$(CXX) $(CXXFLAGS) $(addprefix -D,$(DEFINES)) -I$(INCLUDE_DIR) $< -o $@
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

.PHONY: intro dirs all debug clean