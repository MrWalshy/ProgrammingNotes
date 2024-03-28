#g++ -I src -o main src/**/*.cpp
g++ -I src -o main src/lox/scanner/scanner.cpp src/main.cpp \
src/lox/lox.cpp src/lox/scanner/token.cpp src/lox/scanner/token_type.cpp \
src/lox/types/lox_string.cpp src/lox/types/number.cpp