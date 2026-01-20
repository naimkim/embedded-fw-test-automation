#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>

typedef struct {
    uint8_t header;
    uint16_t value;
    uint8_t checksum;
} Packet;

int parse_packet(const uint8_t *raw, int len, Packet *out);
uint8_t calc_checksum(const uint8_t *data, int len);

#endif
