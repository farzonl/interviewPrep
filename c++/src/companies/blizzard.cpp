#include <iostream>
#include <sys/types.h>
#include <vector>
#include <string>

void Decode(uint8_t* data, uint32_t size)
{
    uint8_t key = 0x73;
    for(uint32_t i = 0; i < size; ++i) {
        uint8_t oldKey = key;
        key ^= (0xFF) & data[i] * 37;
        data[i] ^= oldKey;
        uint8_t l3 = data[i] & 7;
        uint8_t l5 = data[i] ^ l3;
        data[i] = (l3 << 5) | (l5 >> 3);
    }
}

void Encode(uint8_t* data, uint32_t size)
{
    uint8_t key = 0x73;
    for (uint32_t i = 0; i < size; ++i) {
        uint8_t val = data[i];
        data[i] = (((val >> 5) & 0xFF) | ((val << 3) & 0xFF)) ^ key;
        key ^= (uint8_t)(data[i] * 37);
    }
}

std::vector<uint8_t> HexToBytes(const std::string& hex) {
    std::vector<uint8_t> bytes;

    for (unsigned int i = 0; i < hex.length(); i += 2) {
        std::string byteString = hex.substr(i, 2);
        uint8_t byte = (uint8_t)strtol(byteString.c_str(), NULL, 16);
        bytes.push_back(byte);
    }

    return bytes;
}