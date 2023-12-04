# This script build the source code into an application 
echo "Building..."
g++ src/application.cpp -l SDL2main -l SDL2 -o build/app_debug.bin
