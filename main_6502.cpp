#include <iostream>
// #include <stdio.h>
#include <stdlib.h>

using Byte = unsigned char;
using Word = unsigned short;

using u32 = unsigned int;

struct MEM
{
    static constexpr u32 MAX_MEM = 1024 * 64;
    Byte Data[MAX_MEM];
    void Initialize()
    {
        for(u32 i=0; i<MAX_MEM; i++) Data[i] = 0;
    }

    // read 1 byte
    Byte operator[](u32 Address) const
    {
        // assert here Address < MAX_MEM
        return Data[Address];
    }

};

struct CPU
{
    Word PC; // program counter
    Word SP; // stack counter

    Byte A, X, Y; // registers

    // Processor Status
    Byte C : 1; // Carry Flag
    Byte Z : 1; // Zero Flag
    Byte I : 1; // Interrupt Disable
    Byte D : 1; // Decimal Mode
    Byte B : 1; // Break Command
    Byte V : 1; // Overflow Flag
    Byte N : 1; // Negative Flag

    void Reset(MEM &memory) // Initialization
    {
        PC = 0xFFFC;
        SP = 0x0100;
        C = Z = I = D = B = V = N = 0;
        A = X = Y = 0;
        memory.Initialize();
    }

    Byte FetchByte(u32 &Cycles, MEM &memory)
    {
        Byte Data = memory[PC];
        PC++;
        Cycles --;
        return Data;
    }

    void Execute(u32 Cycles, MEM &memory)
    {
        while(Cycles > 0) 
        {
            Byte Ins = FetchByte(Cycles, memory);
            (void) Ins;
        }
    }

};

int main()
{
    MEM mem;
    CPU cpu;
    
    cpu.Reset(mem);
    cpu.Execute(2, mem);
    
    return 0;
}