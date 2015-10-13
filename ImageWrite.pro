# Target is the name of the executable

TARGET=ImageWrite

# Where to place .o files
# $$PWD means i project directory

OBJECTS_DIR=$$PWD/obj

# QMAKE settings
    # Don't build agaist qt libs
CONFIG-=qt
    # Use C++ 11
CONFIG+=c++11
DEFINES+=NDEBUG # Comment out to turn off Assert for finished products
    # Add source files
SOURCES+=$$PWD/src/main.cpp \
         $$PWD/src/ImageWrite.cpp

HEADERS+=$$PWD/include/ImageWrite.h

INCLUDEPATH+=$$PWD/include
