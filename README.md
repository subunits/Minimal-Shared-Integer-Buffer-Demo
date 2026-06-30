# Structured Shared Memory Demo

A high-performance, bare-metal demonstration of sharing structured data between JavaScript and C using WebAssembly linear memory.

## Why this approach?
* **Bare-Metal Performance:** By bypassing high-level bindings like Embind, this implementation interacts directly with the WebAssembly heap.
* **Predictable Memory Layout:** Uses `__attribute__((packed))` in C to ensure the binary structure matches the JavaScript `TypedArray` expectations exactly.
* **Zero-Copy Serialization:** JavaScript views (`Int32Array`, `Float32Array`) map directly to the shared memory address, eliminating the need for data conversion.

## Build Instructions
1. **Compile the C code:**
   ```bash
   emcc shared_struct.c \
     -s EXPORTED_FUNCTIONS='["_init_packet","_process_packet","_free_packet"]' \
     -s MODULARIZE=1 \
     -s EXPORT_NAME='Module' \
     -O2 \
     -o shared_struct.js

2.  **Serve and Test:**
    ```bash
    python3 -m http.server 8080
    ```
    Open `http://localhost:8080/index_struct.html` and check your browser console.

## Architecture
The demo establishes a bridge between the browser and WebAssembly's linear memory.

## License
Copyright 2026 Michael Listrom. 
Licensed under the [Apache License, Version 2.0](LICENSE).
