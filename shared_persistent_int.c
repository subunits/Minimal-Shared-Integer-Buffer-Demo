#include <emscripten/emscripten.h>
#include <stdlib.h>

// Allocate an int buffer and zero-initialize it for safety
EMSCRIPTEN_KEEPALIVE
int* init_buffer(int length) {
    if (length <= 0) return NULL;
    // calloc is safer than malloc as it zeroes the memory
    return (int*)calloc(length, sizeof(int)); 
}

// Process buffer in-place with boundary validation
EMSCRIPTEN_KEEPALIVE
void process_buffer(int* buf, int length, int factor) {
    // Defensive check: abort if pointer is null or length is invalid
    if (buf == NULL || length <= 0) return;
    
    for (int i = 0; i < length; ++i) {
        buf[i] *= factor;
    }
}

// Free buffer with null-check
EMSCRIPTEN_KEEPALIVE
void free_buffer(int* buf) {
    if (buf != NULL) {
        free(buf);
    }
}
