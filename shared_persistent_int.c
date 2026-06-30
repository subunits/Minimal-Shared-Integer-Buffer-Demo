#include <emscripten/emscripten.h>
#include <stdlib.h>

typedef struct {
    int id;
    float value;
    int active;
} DataPacket;

EMSCRIPTEN_KEEPALIVE
DataPacket* init_packet() {
    // Allocate memory for a single struct
    return (DataPacket*)calloc(1, sizeof(DataPacket));
}

EMSCRIPTEN_KEEPALIVE
void process_packet(DataPacket* packet, float multiplier) {
    if (packet == NULL) return;
    
    // Process the struct fields
    packet->value *= multiplier;
    packet->active = (packet->value > 0) ? 1 : 0;
}

EMSCRIPTEN_KEEPALIVE
void free_packet(DataPacket* packet) {
    if (packet != NULL) free(packet);
}
