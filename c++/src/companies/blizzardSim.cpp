#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

enum class VMStatus
{
    Success,
    InvalidBytestream,
    UnsupportedOperation,
    InvalidMode,
    InvalidReg,
};

const char* StatusToString(VMStatus status)
{
    switch (status)
    {
    case VMStatus::Success: return "SUCCESS";
    case VMStatus::InvalidBytestream: return "INVALID_BYTESTREAM";
    case VMStatus::UnsupportedOperation: return "UNSUPPORTED_OPERATION";
    case VMStatus::InvalidMode: return "INVALID_MODE";
    case VMStatus::InvalidReg: return "INVALID_REG";
    default: return "UNKNOWN";
    }
}

void PrintVMState(VMStatus status, uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3)
{
    printf("%s R0: 0x%08X R1: 0x%08X R2: 0x%08X R3: 0x%08X",
        StatusToString(status), r0, r1, r2, r3);
}

enum {NOP=0, MOV, ADD, SUB};

enum {NONE=0, REG, Imm};

bool runImmMode(std::vector<uint8_t>& bytestream, uint32_t* r, int &i, int execCode) {
    if(i >= bytestream.size()) {
        PrintVMState(VMStatus::InvalidBytestream,r[0],r[1],r[2],r[3]);
        return true;
    }
    uint8_t r1  = bytestream[i];
    i++;
    if(r1 >= 4) {
        PrintVMState(VMStatus::InvalidReg,r[0],r[1],r[2],r[3]);
        return true;
    }
    if(i >= bytestream.size()) {
        PrintVMState(VMStatus::InvalidBytestream,r[0],r[1],r[2],r[3]);
        return true;
    }
    uint32_t immVal = 0;
    for(int j = 0; j < 4; j++) {
        if(i >= bytestream.size()) {
            PrintVMState(VMStatus::InvalidBytestream,r[0],r[1],r[2],r[3]);
            return true;
        }
        immVal |= bytestream[i] << j*8;
        i++;
    }
    std::cerr << "imm: " << std::hex << immVal << std::endl;
    switch(execCode) {
    case MOV:
        r[r1] = immVal;
    break;
    case ADD:
        r[r1] += immVal;
    break;
    case SUB:
        r[r1] -= immVal;
    break;
    }
    return false;
}

bool runRegMode(std::vector<uint8_t>& bytestream, uint32_t* r, int &i, int execCode) {
        if(i >= bytestream.size()) {
            PrintVMState(VMStatus::InvalidBytestream,r[0],r[1],r[2],r[3]);
            return true;
        }
        uint8_t r1  = bytestream[i];
        i++;
        if(r1 >= 4) {
            PrintVMState(VMStatus::InvalidReg,r[0],r[1],r[2],r[3]);
            return true;
        }
        if(i >= bytestream.size()) {
            PrintVMState(VMStatus::InvalidBytestream,r[0],r[1],r[2],r[3]);
            return true;
        }
        uint8_t r2 = bytestream[i];
        i++;
        if(r2 >= 4) {
            PrintVMState(VMStatus::InvalidReg,r[0],r[1],r[2],r[3]);
            return true;
        }
        switch(execCode) {
        case MOV:
            r[r1] = r[r2];
        break;
        case ADD:
            r[r1] += r[r2];
        break;
        case SUB:
            r[r1] -= r[r2];
        break;
        }
        return false;
}
/* 
 * RunVM
 *
 * This function will take the provided bytestream for the VM specified
 * and execute the operations provided. After doing so, the status
 * and state of each register should be printed
 */
void RunVM(std::vector<uint8_t>& bytestream)
{
    /* Enter your code here. */
    
    /* Output final state (status and register values) of the VM */
    /* PrintVMState(...) */
    uint32_t r[4] = {0,0,0,0}; //regfile
    int i = 0;
    for(; i < bytestream.size();) {
        //std::cerr << i << " : "  << (int) bytestream[i] << std::endl;
        uint8_t op = bytestream[i];
        i++;
        if(i >= bytestream.size()) {
            PrintVMState(VMStatus::InvalidBytestream,r[0],r[1],r[2],r[3]);
            return;
        }
        if (op > SUB) {
            //std::cerr << "op_only" << " : "  << (int) op << std::endl;
            PrintVMState(VMStatus::UnsupportedOperation,r[0],r[1],r[2],r[3]);
            return;
        } 
        uint8_t mode = bytestream[i];
        i++;
        if( mode > Imm) {
            PrintVMState(VMStatus::UnsupportedOperation,r[0],r[1],r[2],r[3]);
            return;
        }
        if( op != NOP && mode == NONE) {
            PrintVMState(VMStatus::InvalidMode,r[0],r[1],r[2],r[3]);
            return;
        }
        if( op == NOP && mode != NONE) {
            //std::cerr << "op" << " : "  << (int) op << std::endl;
            //std::cerr << "mode" << " : "  << (int) mode << std::endl;
            PrintVMState(VMStatus::InvalidMode,r[0],r[1],r[2],r[3]);
            return;
        } else if(op == NOP && mode == NONE) {
            continue;
        }
        //std::cerr << "op_end" << " : "  << (int) op << std::endl;
        //std::cerr << "mode_end" << " : "  << (int) mode << std::endl;
        //std::cerr << i << " : "  << (int) bytestream[i] << std::endl;
        if(mode == REG) {
            bool quit = runRegMode(bytestream, r, i, op);
            if(quit) {
                return;
            } 
        } else { //imm
            bool quit = runImmMode(bytestream, r, i, op);
            if(quit) {
                return;
            }
        }
    }
    PrintVMState(VMStatus::Success,r[0],r[1],r[2],r[3]);
}