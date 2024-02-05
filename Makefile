#NAME
EXECUTABLE = Kalc

TOOLCHAIN_PATH = C:/MinGW/msys/1.0/home/autobuild/tools/win32/

COMPILER_PATH = ${TOOLCHAIN_PATH}bin/


AR	= kos32-ar
AS	= kos32-as
CC	= kos32-gcc
CXX	= kos32-g++
LD	= kos32-ld 

#DIRs
SDK_DIR = ../contrib/sdk
SRC_DIR = src/

INCLUDES = -I $(SDK_DIR)/sources/libstdc++-v3/include -I $(SDK_DIR)/sources/newlib/libc/include -I KolibriOS-Cpp-Lib/src/include
LIBPATH = -L $(SDK_DIR)/lib -L ${TOOLCHAIN_PATH}mingw32/lib

#Flags
CFLAGS = -c -fno-ident -fomit-frame-pointer -fno-ident -U__WIN32__ -U_Win32 -U_WIN32 -U__MINGW32__ -UWIN32 -std=gnu++11
LDFLAGS = -static -S -Tapp-dynamic.lds --image-base 0 -O2


SOURCES = $(SRC_DIR)main.cpp 
OBJECTS =  $(patsubst $(SRC_DIR)%.cpp, $(SRC_DIR)%.o, $(SOURCES))

default: kalc



kalc: $(OBJECTS) Makefile

	@echo "linking:" $(OBJECTS)
	$(LD) $(LDFLAGS) $(LIBPATH) --subsystem console -o $(EXECUTABLE) $(OBJECTS) -lstdc++ -lsupc++ -lgcc -lc.dll
	kos32-strip -s $(EXECUTABLE) -o $(EXECUTABLE)
	kos32-objcopy $(EXECUTABLE) -O binary

%.o : %.cpp Makefile $(SOURCES)
	@echo "compile:" $@
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $< 



	