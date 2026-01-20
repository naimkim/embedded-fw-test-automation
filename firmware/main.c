#include <stdio.h>
#include "utils.h"

int main() {
    uint8_t data[] = {0xAA, 0x01, 0x02, 0xA9};
    Packet pkt;

    int ret = parse_packet(data, 4, &pkt);
    if (ret == 0) {
        printf("OK header=0x%X value=%d\n", pkt.header, pkt.value);
    } else {
        printf("ERROR %d\n", ret);
    }
    return ret;
}
