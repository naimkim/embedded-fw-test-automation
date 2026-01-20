#include "utils.h"

uint8_t calc_checksum(const uint8_t *data, int len) {
    uint8_t sum = 0;
    for (int i = 0; i < len; i++) {
        sum ^= data[i];
    }
    return sum;
}

int parse_packet(const uint8_t *raw, int len, Packet *out) {
    if (len < 4) return -1;

    out->header = raw[0];
    out->value  = (raw[1] << 8) | raw[2];
    out->checksum = raw[3];

    uint8_t cs = calc_checksum(raw, 3);
    if (cs != out->checksum) return -2;

    return 0;
}
