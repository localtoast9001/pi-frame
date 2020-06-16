O=obj
LIB=../../lib
BIN=../../bin
CC=gcc
CPP=g++
CFLAGS=-fPIC
CPPFLAGS=-g
PKG_CONFIG_CFLAGS=`pkg-config --cflags gtkmm-3.0`
TARGET_ARCH=
LOADLIBES=
LDFLAGS=-lstdc++
LDLIBS=-lm
PKG_CONFIG_LDFLAGS= `pkg-config --libs gtkmm-3.0`
RM=rm -f
LD=ld
TARGET=$(BIN)/pi-frame-gtk

default: all

all: $(TARGET)

HEADERS=\
  main_window.hpp

OBJECTS=\
  $(O)/main_window.o \
  $(O)/main.o

$(TARGET): $(BIN) $(OBJECTS) $(LOADLIBES)
	$(CC) $(LDFLAGS) $(TARGET_ARCH) $(OBJECTS) $(PKG_CONFIG_LDFLAGS) $(LOADLIBES) $(LDLIBS) -o $@

$(BIN):
	mkdir $(BIN)

$(O)/%.o: %.cpp $(O) $(HEADERS)
	$(CPP) $(CFLAGS) $(CPPFLAGS) $(PKG_CONFIG_CFLAGS) $(TARGET_ARCH) -c -o $@ $<

$(O):
	mkdir $(O)

clean:
	$(RM) $(TARGET)
	$(RM) $(OBJECTS)
