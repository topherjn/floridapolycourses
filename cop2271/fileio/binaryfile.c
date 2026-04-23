#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp = fopen("input.bmp", "rb");
    if (fp == NULL) { perror("fopen"); return 1; }

    // Get file size
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    // Read pixel data offset from header (bytes 10-13)
    unsigned int pixel_offset;
    fseek(fp, 10, SEEK_SET);
    if (fread(&pixel_offset, sizeof(unsigned int), 1, fp) != 1) {
        fprintf(stderr, "Failed to read pixel offset\n");
        fclose(fp);
        return 1;
    }

    // Read entire file into buffer
    rewind(fp);
    unsigned char *buf = malloc(size);
    if (buf == NULL) {
        fprintf(stderr, "malloc failed\n");
        fclose(fp);
        return 1;
    }
    if (fread(buf, 1, size, fp) != (size_t)size) {
        fprintf(stderr, "Failed to read file\n");
        fclose(fp);
        free(buf);
        return 1;
    }
    fclose(fp);

    printf("Pixel data starts at byte %u\n", pixel_offset);

    // Walk through pixels — BMP stores channels as BGR, not RGB
    for (long i = pixel_offset; i < size - 2; i += 3) {
        buf[i]     = buf[i]     / 2;
        buf[i + 1] = buf[i + 1] / 2;
        buf[i + 2] = 255;
    }

    // Write modified buffer to new file
    FILE *out = fopen("output.bmp", "wb");
    if (out == NULL) {
        perror("fopen output");
        free(buf);
        return 1;
    }
    if (fwrite(buf, 1, size, out) != (size_t)size) {
        fprintf(stderr, "Failed to write file\n");
        fclose(out);
        free(buf);
        return 1;
    }

    fclose(out);
    free(buf);
    printf("Done. Written to output.bmp\n");
    return 0;
}