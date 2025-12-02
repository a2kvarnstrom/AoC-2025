#include <stdio.h>
#include <stdlib.h>

char *buffer = 0;
FILE *input;
long length;
int dial = 50;
int sign = 0;
char currentBuffer;
char shiftBuffer[10];
int bufferIndex = 0;

int main(int argc, char** argv) {
    input = fopen("input", "r");
    fseek(input, 0, SEEK_END);
    length = ftell(input);
    fseek(input, 0, SEEK_SET);
    buffer = malloc(length);
    if(buffer) fread(buffer, 1, length, input);
    fclose(input);

    for(int i = 0; i < length; i++) {
        if(buffer[i] == "R") {
            sign = 0;
        } else if(buffer[i] == "L") {
            sign = 1;
        } else if(buffer[i] != "\n") {
            currentBuffer = buffer[i];
            shiftBuffer[bufferIndex] = currentBuffer;
            bufferIndex++;
        } else {
            bufferIndex = 0;
        }
    }

    return 0;
}