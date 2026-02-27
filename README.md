# 0xCryptx
0xCryptX is a CUDA-accelerated cryptography toolkit implementing encryption and hashing algorithms, with GPU-based performance benchmarking and hash strength analysis tools.

## Project Structure
```
0xCryptx/
├── LICENSE
├── Makefile
├── README.md
├── includes/
│   ├── utils.cpp
│   └── encryption/
│       └── scytale.h
├── src/
│   ├── main.cpp
│   ├── cuda/
│   │   └── cuda.cpp
│   ├── encryption/
│   │   └── scytale.cpp
│   ├── hashing/
│   │   └── md5.cpp
│   └── utils/
│       └── utils.cpp
└── obj/              (generated during build)
```

## Building and Running

### Prerequisites
- C++ compiler with C++17 support (g++ recommended)
- Make

### Build
```bash
make
```

### Clean Build Artifacts
```bash
make clean
```

### Run
```bash
make run
```

Or directly:
```bash
./0xCryptx
```
