CXX      = g++
CXXFLAGS = -c -Wall $(addprefix -D,$(DEFINES)) -I$(INCLUDE_DIR)
DEFINES  = 
LDFLAGS  =
MKDIR_P = mkdir -p

SOURCE_DIR = src
INCLUDE_DIR = include


OBJ_DEBUG = obj_debug
OBJ_RELEASE = obj_release
BIN_DEBUG = bin_debug
BIN_RELEASE = bin_release

ifdef DEBUG
DEFINES += DEBUG
BIN_DIR = $(BIN_DEBUG)
OBJ_DIR = $(OBJ_DEBUG)
else
BIN_DIR = $(BIN_RELEASE)
OBJ_DIR = $(OBJ_RELEASE)
endif

EXECUTABLE = $(BIN_DIR)/archipelego
INCLUDES = $(wildcard $(INCLUDE_DIR)/*.h)
SOURCES = $(wildcard $(SOURCE_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SOURCE_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: intro dirs $(OBJECTS) $(EXECUTABLE)
	@echo "All done."

#TODO: make depends on headers.

$(EXECUTABLE): $(OBJECTS)
	@echo "Linking..."
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE)
	@echo "Done.\n"

#TODO: can the pattern matching look nicer?

$(OBJ_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	@echo "Compiling $< ..."
	$(CXX) $(CXXFLAGS)  $< -o $@
	@echo "Done.\n"

dirs: $(OBJ_DIR) $(BIN_DIR)

$(OBJ_DIR) $(BIN_DIR):	
	@echo "Creating output folder..."
	$(MKDIR_P) $@;
	@echo "Done.\n"

intro:
	@echo "Building sources $(SOURCES) for $(EXECUTABLE).\n"

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

cleanall:
	rm -rf $(OBJ_DEBUG) $(BIN_DEBUG) $(OBJ_RELEASE) $(BIN_RELEASE)

.PHONY: intro dirs all debug cleanall clean