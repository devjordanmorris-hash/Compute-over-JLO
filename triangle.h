// triangle.h – Complete API
typedef struct {
    uint8_t sides[3][64];  // 64 base-4 digits per side
} Triangle;

// Core operations
uint64_t triangle_borrow_single(Triangle *tri);
void triangle_borrow_batch(Triangle *tris, int n, uint64_t *borrows);

// NEON dispatch (auto-detects ARM64)
void triangle_borrow_neon(Triangle *tris, int n, uint64_t *borrows);
void triangle_borrow_scalar(Triangle *tris, int n, uint64_t *borrows);

// JWL0 integration
size_t triangle_compress_jwl0(Triangle *tris, int n, uint8_t *output);
int triangle_decompress_jwl0(uint8_t *input, size_t len, Triangle *out_tris);
