CONFIG += c++latest
QMAKE_CXXFLAGS += -std=c++17

CONFIG(debug, debug|release) {
    QMAKE_CXXFLAGS += -O0
    TARGET = random_vector_debug
} else {
    QMAKE_CXXFLAGS += -Ofast
    TARGET = random_vector
}

DESTDIR = $$PWD/bin

SOURCES += \
        main.cpp
