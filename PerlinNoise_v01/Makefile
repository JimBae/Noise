#----------##
# Makefile ##
#-----------------------------#
# Jinhyuk Bae   			  #
# Updated data : 2016.06.27   #
#-----------------------------#

HOME_DIR   = $(shell pwd)

PROJECTS    = perlin

BIN_PATH    = ./
HEADER_PATH = ./header
SOURCE_PATH = ./source
OBJECT_PATH = ./object

CC               = g++
NVCC             = nvcc

HEADER_DIR       := -I/usr/include 
HEADER_DIR       += -I/usr/local/include
HEADER_DIR       += -I./header
HEADER_DIR       += -I.

LIBS             = -L/usr/lib64
LIBS			+= -L/usr/lib
LIBS			+= -L/usr/lib/x86_64-linux-gnu
LIBS			+= -L/usr/local/lib
LIBS            += -lpthread -lgomp -lz
LIBS            += -lHalf

#CCFLAGS          = -O3 -m64 -fpic -fopenmp -Wno-deprecated
#CCFLAGS          = -Wall -O3 -m64 -std=c++11 -fpic -fopenmp  -Wno-deprecated -Wno-unused-variable
CCFLAGS          = -Wall -c -O3 -m64 -std=c++11 -fopenmp -Wno-deprecated -Wno-unused-variable
LDFLAGS         := -shared -fopenmp
CUFLAGS         := -m64 -Xcompiler -fPIC

CPP_SOURCES   := $(wildcard $(SOURCE_PATH)/*.cpp)
CPP_LIST      := $(notdir $(CPP_SOURCES))

OBJ_LIST := $(addprefix $(OBJECT_PATH)/,$(CPP_LIST:.cpp=.o))

.SILENT:

all: $(PROJECTS)

# .o -> project
$(PROJECTS): $(OBJ_LIST)
	$(CC) $(LIBS) -o $(BIN_PATH)/$(PROJECTS) $(OBJ_LIST)

# .cpp -> .o
$(OBJECT_PATH)/%.o: $(SOURCE_PATH)/%.cpp
	@$(CC) $(CCFLAGS) $(HEADER_DIR) $(SWITCHES) -c $< -o $@

clean:
	#rm -rf $(TARGET_BINARIES) 
	rm -rf ./object/*
	rm -rf $(BIN_PATH)/$(PROJECTS)
	rm -rf *.ppm



#HOME_DIR   = $(shell pwd)
#SOURCE_PATH = .
#BIN_PATH = .
#SOURCES    = $(wildcard $(SOURCE_PATH)/*.cpp)
#SOURCESCPP = $(notdir $(SOURCES))
#
#CPP_SOURCES   := $(wildcard $(SOURCE_PATH)/*.cpp)
#CPP_LIST      := $(notdir $(CPP_SOURCES))							# *.cpp
#PROJECTS := $(addprefix $(BIN_PATH)/,$(CPP_LIST:.cpp=))	
#
#CC               = g++
#NVCC             = nvcc
#CCFLAGS          = -O3 -m64 -fpic -fopenmp -Wno-deprecated -std=c++11
#CUFLAGS          := -m64 -Xcompiler -fPIC
#LDFLAGS          := -shared -fopenmp
#
#HEADER_DIR       := -I/usr/include 
#HEADER_DIR       += -I/usr/local/include
#HEADER_DIR       += -I.
#
#LIBS             = -L/usr/lib64
#LIBS			+= -L/usr/lib 
#LIBS			+= -L/usr/lib/x86_64-linux-gnu
#LIBS			+= -L/usr/local/lib
#LIBS            += -lpthread -lgomp -lz
#
#.SILENT:
#
#all: $(PROJECTS)
#
#$(BIN_PATH)/%: $(SOURCE_PATH)/%.cpp
#	mkdir -p -m 755 $(BIN_PATH)
#	@echo 'Compiling: $(notdir $<) -> $(notdir $@)'
#	$(CC) $(CCFLAGS) -o $@ $< $(HEADER_DIR) $(LIBS)
#
#TARGET_BINARIES =$(addprefix $(BIN_PATH)/,$(SOURCESCPP:.cpp=))
#
#clean:
#	#rm -rf $(TARGET_BINARIES) 
