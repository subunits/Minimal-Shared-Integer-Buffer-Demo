# Minimal Shared Integer Buffer Demo

## Build Instructions

1. Install Emscripten (emsdk):
~~~
   git clone https://github.com/emscripten-core/emsdk.git
   cd emsdk
   ./emsdk install latest
   ./emsdk activate latest
   source ./emsdk_env.sh
~~~

2. Compile the C code:
~~~
   emcc shared_persistent_int.c \
     -s EXPORTED_FUNCTIONS='["_init_buffer","_process_buffer","_free_buffer"]' \
     -s EXPORTED_RUNTIME_METHODS='["cwrap"]' \
     -O2 \
     -o shared_persistent_int.js
~~~
   This produces `shared_persistent_int.js` and `shared_persistent_int.wasm`.

3. Serve locally and open in browser:
~~~
   python3 -m http.server 8080

   Open http://localhost:8080/index_minimal.html
~~~
## Demo

- Automatically runs a producer/consumer loop.
- JS writes values → C multiplies them in-place → JS logs the results.
- Loops indefinitely every 600ms.
- Open the **console** to see the output.

Expected output:
~~~
JS wrote: [0,1,2,3,4,5,6,7]  
After C.process (x3): [0,3,6,9,12,15,18,21]  
---  
JS wrote: [10,11,12,13,14,15,16,17]  
After C.process (x3): [30,33,36,39,42,45,48,51]  
---
~~~
