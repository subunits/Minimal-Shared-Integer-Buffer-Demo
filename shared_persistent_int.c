#include <emscripten/emscripten.h>
#include <stdlib.h>

// Allocate an int buffer
EMSCRIPTEN_KEEPALIVE
int* init_buffer(int length) {
    int* buf = (int*)malloc(sizeof(int) * length);
    return buf;
}

// Process buffer in-place: multiply each element by factor
EMSCRIPTEN_KEEPALIVE
void process_buffer(int* buf, int length, int factor) {
    for (int i = 0; i < length; ++i) {
        buf[i] *= factor;
    }
}

// Free buffer
EMSCRIPTEN_KEEPALIVE
void free_buffer(int* buf) {
    free(buf);
}
