O=obj
LIB=../../lib
BIN=../../bin
CC=gcc
CPP=g++
CFLAGS=-fPIC
CPPFLAGS=-g
TARGET_ARCH=
LOADLIBES=
LDFLAGS=-lstdc++
LDLIBS=-lm
RM=rm -f
LD=ld
TARGET=$(BIN)/ip-frame-gtk

default: all

all: $(TARGET)

OBJECTS=\
  $(O)/main.o

$(TARGET): $(BIN) $(OBJECTS) $(LOADLIBES)
	$(CC) $(LDFLAGS) $(TARGET_ARCH) $(OBJECTS) `pkg-config --libs gtk+-3.0` $(LOADLIBES) $(LDLIBS) -o $@

$(BIN):
	mkdir $(BIN)

$(O)/%.o: %.cpp $(O) 
	$(CPP) $(CFLAGS) $(CPPFLAGS) `pkg-config --cflags gtk+-3.0` $(TARGET_ARCH) -c -o $@ $<

$(O):
	mkdir $(O)

clean:
	$(RM) $(TARGET)
	$(RM) $(OBJECTS)
