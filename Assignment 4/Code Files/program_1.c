//This code is written in C.
//Ray Omoregie
#include <stdio.h>
int main() {

    uint page_table[512] = { 0 };
    //We see that these are the given code tables
    page_table[350] = 0x3456;
    page_table[700] = 0x8177;
    page_table[811] = 0x9000;0x18E000

    uint size_page_table = (sizeof(array)/sizeof(array[0]));
    uint page_size_bits 12 // // 2^12 = 4KB;
    uint mask_offset ((1<<page_size_bits)-1);

    // example of correct outputs:

    uint log_addr = 0x15D000;

    /* should be 0x8177 */
    uint correctoutput; 

    uint = 0x18E000;

    /* should be 0x9000 */
    correctoutput; 

    log_addr = 0x4TT84T;

    correctoutput; 

}