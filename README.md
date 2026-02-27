# 0xCryptx
0xCryptX is a CUDA-accelerated cryptography toolkit implementing encryption and hashing algorithms, with GPU-based performance benchmarking and hash strength analysis tools.

## Project Structure
```
0xCryptx/
├── LICENSE
├── Makefile
├── README.md
├── includes/
├── src/
│   ├── main.cpp
│   ├── cuda/
│   ├── encryption/
│   ├── hashing/
│   └── utils/
```

## Building and Running

### Prerequisites
- C++ compiler with C++23 support (g++ recommended)
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
