TARGET = geometry
TARGET_TEST = geometry-test

CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBAGFLAGS = -g3 -O0
DIRECTORIFLAGS = -I src
DIRECTORIFLAGS_TEST = -I thirdparty

PREF_SRC_GEOMETRY = ./src/geometry/
PREF_SRC_LIBGEOMETRY = ./src/libgeometry/
PREF_SRC_TEST = ./test/

PREF_OBJ_GEOMETRY = ./obj/src/geometry/
PREF_OBJ_LIBGEOMETRY = ./obj/src/libgeometry/
PREF_OBJ_TEST = ./obj/test/

PREF_BIN = ./bin/
make:
SRC_GEOMETRY = $(wildcard $(PREF_SRC_GEOMETRY)*.c)
SRC_LIBGEOMETRY = $(wildcard $(PREF_SRC_LIBGEOMETRY)*.c)
SRC_TEST = $(wildcard $(PREF_SRC_TEST)*.c)

OBJ_GEOMETRY = $(patsubst $(PREF_SRC_GEOMETRY)%.c, $(PREF_OBJ_GEOMETRY)%.o, $(SRC_GEOMETRY))
OBJ_LIBGEOMETRY = $(patsubst $(PREF_SRC_LIBGEOMETRY)%.c, $(PREF_OBJ_LIBGEOMETRY)%.o, $(SRC_LIBGEOMETRY))
OBJ_TEST = $(patsubst $(PREF_SRC_TEST)%.c, $(PREF_OBJ_TEST)%.o, $(SRC_TEST))

$(PREF_BIN)$(TARGET) : $(OBJ_GEOMETRY) $(PREF_OBJ_LIBGEOMETRY)libgeometry.a
	$(CC) $(CFLAGS) $(DIRECTORIFLAGS) $(OBJ_GEOMETRY) $(PREF_OBJ_LIBGEOMETRY)libgeometry.a -o $(PREF_BIN)$(TARGET) -lm

$(PREF_OBJ_GEOMETRY)%.o : $(PREF_SRC_GEOMETRY)%.c
	$(CC) $(CFLAGS) $(DIRECTORIFLAGS) -c $< -o $@

$(PREF_OBJ_LIBGEOMETRY)libgeometry.a : $(OBJ_LIBGEOMETRY)
	ar rcs $@ $^

$(PREF_OBJ_LIBGEOMETRY)%.o : $(PREF_SRC_LIBGEOMETRY)%.c
	$(CC) $(CFLAGS) $(DIRECTORIFLAGS) -c $< -o $@

run :
	$(PREF_BIN)$(TARGET)
.PHONY : clean
clean :
	rm $(PREF_BIN)$(TARGET) $(PREF_OBJ_GEOMETRY)*.o $(PREF_OBJ_LIBGEOMETRY)*.o $(PREF_OBJ_LIBGEOMETRY)*.a $(PREF_OBJ_TEST)*.o $(PREF_BIN)$(TARGET_TEST)

.PHONY : test
test : run-test
run-test : $(PREF_BIN)$(TARGET_TEST)
	$(PREF_BIN)$(TARGET_TEST)
$(PREF_BIN)$(TARGET_TEST) : $(OBJ_TEST) $(PREF_OBJ_LIBGEOMETRY)libgeometry.a
	$(CC) $(CFLAGS) $(OBJ_TEST) $(PREF_OBJ_LIBGEOMETRY)libgeometry.a -o $(PREF_BIN)$(TARGET_TEST) -lm
$(PREF_OBJ_TEST)%.o : $(PREF_SRC_TEST)%.c
	$(CC) $(CFLAGS) $(DIRECTORIFLAGS_TEST) -c $< -o $@