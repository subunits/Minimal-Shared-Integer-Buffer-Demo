# Minimal Shared Integer Buffer Demo

A high-performance, memory-safe demonstration of sharing and manipulating data between JavaScript and C using Emscripten.

## Why this is "Safe"
This project uses a defensive approach to memory management, specifically designed to minimize corruption and leak risks:
* **Encapsulation:** The `SafeBridge` JavaScript object prevents direct pointer manipulation[cite: 6].
* **Validation:** C-side operations perform defensive checks for `NULL` pointers and boundary conditions[cite: 6].
* **Zero-Initialization:** Uses `calloc` to ensure memory is never in an undefined state[cite: 6].
* **Lifecycle Management:** Centralized `free` logic handles memory cleanup[cite: 6].

## Build Instructions
1.  **Compile the C code:**
    ```bash
    emcc shared_persistent_int_2.c \
      -s EXPORTED_FUNCTIONS='["_init_buffer","_process_buffer","_free_buffer"]' \
      -s EXPORTED_RUNTIME_METHODS='["cwrap"]' \
      -s MODULARIZE=0 \
      -O2 \
      -o shared_persistent_int_2.js
    ```
    *Tip: Add `-s SAFE_HEAP=1 -s ASSERTIONS=1` to these flags during development for built-in runtime safety checks[cite: 6].*

2.  **Serve and Test:**
    ```bash
    python3 -m http.server 8080
    ```
    Open `http://localhost:8080/index_minimal_2.html` and check your browser console[cite: 6].

## Architecture
The demo establishes a bridge between the browser and WebAssembly's linear memory.

## License
Copyright 2026 Michael Listrom. 
Licensed under the [Apache License, Version 2.0](LICENSE_2)[cite: 5, 6].
