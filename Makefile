SRC_DIR := src
OBJ_DIR := obj
INC_DIR := include
BIN_DIR := .

EXE := $(BIN_DIR)/rsa
SRC := $(wildcard $(SRC_DIR)/*.cpp)
INC := $(wildcard $(INC_DIR)/*.h)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CPPFLAGS := -I $(INC_DIR)
LDFLAGS = -lgmpxx -lgmp

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ) | $(BIN_DIR)
	$(CXX) $^ $(LDFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC) | $(OBJ_DIR)
	$(CXX) -c $< $(CPPFLAGS) -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(EXE) $(OBJ_DIR)
