#include <avr/pgmspace.h>

#define CUBESIZE 4
#define PLANESIZE CUBESIZE*CUBESIZE
#define PLANETIME 3333 // time each plane is displayed in us -> 100 Hz refresh
#define TIMECONST 20 // multiplies DisplayTime to get ms

// LED Pattern Table in PROGMEM - last column is display time in 100ms units
// TODO: this could be a lot more compact but not with binary pattern representation
prog_uchar PROGMEM PatternTable[] = {
    B0001,B0000,B0000,B0000,B0001,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B0011,B0000,B0000,B0000,B0011,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B0011,B0010,B0000,B0000,B0011,B0010,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B0011,B0011,B0000,B0000,B0011,B0011,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B0110,B0110,B0000,B0000,B0110,B0110,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B0000,B0000,B0000,B0000,B0110,B0110,B0000,B0000,B0110,B0110,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B0000,B0000,B0000,B0000,B0000,B0110,B0110,B0000,B0000,B0110,B0110,B0000,B0000,B0000,B0000,B0000,10,
    B0000,B0000,B0000,B0000,B0000,B0000,B0110,B0110,B0000,B0000,B0110,B0110,B0000,B0000,B0000,B0000,10,
    B0000,B0000,B0000,B0000,B0000,B0000,B0011,B0011,B0000,B0000,B0011,B0011,B0000,B0000,B0000,B0000,10,
    B0000,B0000,B0000,B0000,B0000,B0001,B0011,B0111,B0000,B0001,B0011,B0111,B0000,B0000,B0001,B0011,10,
    B0000,B0000,B0000,B0000,B0000,B0011,B0111,B0111,B0000,B0011,B0111,B0111,B0000,B0001,B0011,B0111,10,
    B0000,B0000,B0000,B0000,B0000,B0111,B0111,B0111,B0000,B0111,B0111,B0111,B0000,B0011,B0111,B0111,10,
    B0000,B0000,B0000,B0000,B0000,B0111,B0111,B0111,B0000,B0111,B0111,B0111,B0000,B0111,B0111,B0111,10,
    B0000,B0000,B0000,B0000,B0000,B1110,B1110,B1110,B0000,B1110,B1110,B1110,B0000,B1110,B1110,B1110,10,
    B0000,B1110,B1110,B1110,B0000,B1110,B1110,B1110,B0000,B1110,B1110,B1110,B0000,B0000,B0000,B0000,10,
    B0000,B1110,B1110,B1110,B0000,B1110,B1110,B1110,B0000,B1100,B1110,B1110,B0000,B0000,B0000,B0000,10,
    B0000,B1110,B1110,B1110,B0000,B1100,B1110,B1110,B0000,B1000,B1100,B1110,B0000,B0000,B0000,B0000,10,
    B0000,B1100,B1110,B1110,B0000,B1000,B1100,B1110,B0000,B0000,B1000,B1100,B0000,B0000,B0000,B0000,10,
    B0000,B1000,B1100,B1110,B0000,B0000,B1000,B1100,B0000,B0000,B0000,B1000,B0000,B0000,B0000,B0000,10,
    B0000,B0000,B1000,B1100,B0000,B0000,B0000,B1000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B0000,B0000,B0000,B1000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B0000,B0000,B1000,B1000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B0000,B1000,B1000,B1000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B1000,B1000,B1000,B1000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B1100,B1000,B1000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B1110,B1000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B1110,B0000,B0000,B0000,B0010,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B0110,B0000,B0000,B0000,B0011,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B0010,B0000,B0000,B0000,B0011,B0001,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B0000,B0000,B0000,B0000,B0011,B0001,B0001,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B0000,B0000,B0000,B0000,B0001,B0001,B0001,B0001,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B0000,B0000,B0000,B0000,B0000,B0001,B0001,B0011,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B0000,B0000,B0000,B0000,B0000,B0000,B0001,B0111,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B0000,B0000,B0000,B0000,B0000,B0000,B0000,B1111,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B0000,B0000,B0000,B0000,B0000,B0000,B0000,B1110,B0000,B0000,B0000,B1000,B0000,B0000,B0000,B0000,10,
    B0000,B0000,B0000,B0000,B0000,B0000,B0000,B1100,B0000,B0000,B1000,B1000,B0000,B0000,B0000,B0000,10,
    B0000,B0000,B0000,B0000,B0000,B0000,B0000,B1000,B0000,B0000,B1100,B1000,B0000,B0000,B0000,B0000,10,
    B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B1110,B1000,B0000,B0000,B0000,B0000,10,
    B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B1111,B0000,B0000,B0000,B0000,B0000,10,
    B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0001,B0111,B0000,B0000,B0000,B0000,B0000,10,
    B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0001,B0001,B0011,B0000,B0000,B0000,B0000,B0000,10,
    B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0001,B0001,B0001,B0000,B0001,B0000,B0000,B0000,10,
    B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0001,B0001,B0000,B0000,B0011,B0000,B0000,B0000,10,
    B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0001,B0000,B0000,B0000,B0111,B0000,B0000,B0000,10,
    B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B1111,B0000,B0000,B0000,10,
    B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B1110,B1000,B0000,B0000,10,
    B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B1100,B1100,B0000,B0000,10,
    B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B1000,B1110,B0000,B0000,10,
    B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B1111,B0000,B0000,10,
    B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0001,B0000,B0000,B0000,B0111,B0000,B0000,10,
    B0000,B0000,B0000,B0000,B0000,B0001,B0000,B0000,B0000,B0001,B0000,B0000,B0000,B0011,B0000,B0000,10,
    B0000,B0001,B0000,B0000,B0000,B0001,B0000,B0000,B0000,B0001,B0000,B0000,B0000,B0001,B0000,B0000,10,
    B0001,B0001,B0000,B0000,B0000,B0001,B0000,B0000,B0000,B0001,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B0011,B0001,B0000,B0000,B0000,B0001,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B0111,B0001,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B1111,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B1111,B1000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B1111,B1100,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B1111,B1110,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B1111,B1111,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B1111,B1111,B0001,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B1111,B1111,B0011,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B1111,B1111,B0111,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B1111,B1111,B1111,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B1111,B1111,B1111,B1000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B1111,B1111,B1111,B1100,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B1111,B1111,B1111,B1110,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B1111,B1111,B1111,B1111,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B1111,B1111,B1111,B1111,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B0111,B0111,B0111,B0111,B1000,B1000,B1000,B1000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B0011,B0011,B0011,B0011,B0100,B0100,B0100,B0100,B1000,B1000,B1000,B1000,B0000,B0000,B0000,B0000,10,
    B0001,B0001,B0001,B0001,B0010,B0010,B0010,B0010,B0100,B0100,B0100,B0100,B1000,B1000,B1000,B1000,10,
    B0001,B0001,B0001,B0001,B0001,B0001,B0001,B0001,B0010,B0010,B0010,B0010,B0100,B0100,B0100,B0100,10,
    B0001,B0001,B0001,B0001,B0001,B0001,B0001,B0001,B0001,B0001,B0001,B0001,B0010,B0010,B0010,B0010,10,
    B0001,B0001,B0001,B0001,B0001,B0001,B0001,B0001,B0001,B0001,B0001,B0001,B0001,B0001,B0001,B0001,10,
    B0010,B0001,B0001,B0001,B0010,B0001,B0001,B0001,B0010,B0001,B0001,B0001,B0010,B0001,B0001,B0001,10,
    B0100,B0010,B0001,B0001,B0100,B0010,B0001,B0001,B0100,B0010,B0001,B0001,B0100,B0010,B0001,B0001,10,
    B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,10,
    B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,10,
    B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,10,
    B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,10,
    B0010,B0010,B0100,B0100,B0010,B0010,B0100,B0100,B0010,B0010,B0100,B0100,B0010,B0010,B0100,B0100,10,
    B0100,B0100,B0010,B0010,B0100,B0100,B0010,B0010,B0100,B0100,B0010,B0010,B0100,B0100,B0010,B0010,10,
    B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,10,
    B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,10,
    B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,10,
    B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,10,
    B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,10,
    B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,10,
    B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,10,
    B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,10,
    B0010,B0010,B0100,B0100,B0010,B0010,B0100,B0100,B0010,B0010,B0100,B0100,B0010,B0010,B0100,B0100,10,
    B0100,B0100,B0010,B0010,B0100,B0100,B0010,B0010,B0100,B0100,B0010,B0010,B0100,B0100,B0010,B0010,10,
    B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,10,
    B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,10,
    B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,10,
    B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,10,
    B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,10,
    B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,10,
    B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,10,
    B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,10,
    B0010,B0010,B0100,B0100,B0010,B0010,B0100,B0100,B0010,B0010,B0100,B0100,B0010,B0010,B0100,B0100,10,
    B0100,B0100,B0010,B0010,B0100,B0100,B0010,B0010,B0100,B0100,B0010,B0010,B0100,B0100,B0010,B0010,10,
    B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,10,
    B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,10,
    B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,10,
    B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,10,
    B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,10,
    B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,10,
    B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,10,
    B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,10,
    B0010,B0010,B0100,B0100,B0010,B0010,B0100,B0100,B0010,B0010,B0100,B0100,B0010,B0010,B0100,B0100,10,
    B0100,B0100,B0010,B0010,B0100,B0100,B0010,B0010,B0100,B0100,B0010,B0010,B0100,B0100,B0010,B0010,10,
    B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,10,
    B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,10,
    B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,10,
    B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,10,
    B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,10,
    B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,10,
    B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,10,
    B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,10,
    B0010,B0010,B0100,B0100,B0010,B0010,B0100,B0100,B0010,B0010,B0100,B0100,B0010,B0010,B0100,B0100,10,
    B0100,B0100,B0010,B0010,B0100,B0100,B0010,B0010,B0100,B0100,B0010,B0010,B0100,B0100,B0010,B0010,10,
    B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,10,
    B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,10,
    B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,10,
    B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,10,
    B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,10,
    B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,10,
    B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,10,
    B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,10,
    B0010,B0010,B0100,B0100,B0010,B0010,B0100,B0100,B0010,B0010,B0100,B0100,B0010,B0010,B0100,B0100,10,
    B0100,B0100,B0010,B0010,B0100,B0100,B0010,B0010,B0100,B0100,B0010,B0010,B0100,B0100,B0010,B0010,10,
    B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,B1000,B0100,B0010,B0001,10,
    B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,B0000,B1100,B0011,B0000,10,
    B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,B0000,B0011,B1100,B0000,10,
    B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,10,
    B0000,B0010,B0100,B0000,B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,10,
    B0000,B0000,B0000,B0000,B0000,B0010,B0100,B0000,B0001,B0010,B0100,B1000,B0001,B0010,B0100,B1000,10,
    B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0010,B0100,B0000,B0001,B0010,B0100,B1000,10,
    B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0010,B0100,B0000,10,
    B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B1000,10,
    B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B1000,B0000,B0010,B0000,B1000,10,
    B0000,B0000,B0000,B0000,B0000,B0000,B0000,B1000,B0000,B0010,B0000,B1000,B0000,B0010,B1000,B0000,10,
    B0000,B0000,B0000,B1000,B0000,B0010,B0000,B1000,B0000,B0010,B1000,B0000,B0000,B0000,B1000,B0000,10,
    B0000,B0010,B0000,B1000,B0000,B0010,B1000,B0000,B0000,B0000,B1000,B0000,B0000,B0000,B0000,B0000,10,
    B0000,B0010,B1000,B0000,B0000,B0000,B1000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B0000,B0000,B1000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B0000,B0100,B0010,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B0000,B0110,B0110,B0000,B0000,B0100,B0010,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B1001,B0110,B0110,B1001,B0000,B0110,B0110,B0000,B0000,B0100,B0010,B0000,B0000,B0000,B0000,B0000,10,
    B1101,B0111,B1110,B1011,B1001,B0110,B0110,B1001,B0000,B0110,B0110,B0000,B0000,B0100,B0010,B0000,10,
    B1111,B1111,B1111,B1111,B1101,B0111,B1110,B1011,B1001,B0110,B0110,B1001,B0000,B0110,B0110,B0000,10,
    B1111,B1111,B1111,B1111,B1111,B1111,B1111,B1111,B1101,B0111,B1110,B1011,B1001,B0110,B0110,B1001,10,
    B1111,B1111,B1111,B1111,B1111,B1111,B1111,B1111,B1111,B1111,B1111,B1111,B1101,B0111,B1110,B1011,10,
    B1111,B1111,B1111,B1111,B1111,B1111,B1111,B1111,B1111,B1111,B1111,B1111,B1111,B1111,B1111,B1111,10,
    B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B1111,B1111,B1111,B1111,B1111,B1111,B1111,B1111,B1111,B1111,B1111,B1111,B1111,B1111,B1111,B1111,10,
    B1111,B1111,B1111,B1111,B1111,B1111,B1111,B1111,B1111,B1111,B1111,B1111,B0000,B0000,B0000,B0000,10,
    B1111,B1111,B1111,B1111,B1111,B1111,B1111,B1111,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B1111,B1111,B1111,B1111,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,
    B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,B0000,10,

    // this is a dummy element for end of table (duration=0) aka !!!DO NOT TOUCH!!!
    B0000, B0000, B0000, B0000, B0000, B0000, B0000, B0000, B0000, B0000, B0000, B0000, B0000, B0000, B0000, B0000, 0
};

int LEDPin[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
int PlanePin[] = {16, 17, 18, 19};

void setup() {
    int pin;
    // Select row+column (Set to HIGH)
    for (pin = 0; pin < PLANESIZE; pin++) {
        pinMode(LEDPin[pin], OUTPUT);
    }
    // Select plane (Set to LOW)
    for (pin = 0; pin < CUBESIZE; pin++) {
        pinMode(PlanePin[pin], OUTPUT);
    }
}

void loop() {
    byte PatternBuf[PLANESIZE]; // saves current pattern from PatternTable
    int PatternIdx;
    byte DisplayTime; // time * 100ms to display pattern
    unsigned long EndTime;
    int plane; // loop counter for cube refresh
    int patbufidx; // indexes which byte from pattern buffer
    int ledrow; // counts LEDs in refresh loop
    int ledcol; // counts LEDs in refresh loop
    int ledpin; // counts LEDs in refresh loop

    PatternIdx = 0;
    do {
        memcpy_P(PatternBuf, PatternTable+PatternIdx, PLANESIZE);
        PatternIdx += PLANESIZE;
        DisplayTime = pgm_read_byte_near(PatternTable + PatternIdx++);
        EndTime = millis() + ((unsigned long) DisplayTime) * TIMECONST;

        while(millis() < EndTime) {
            patbufidx = 0; // reset index to beginning of buffer

            // loop over planes
            for(plane = 0; plane < CUBESIZE; plane++) {
                if (plane == 0) {
                    digitalWrite( PlanePin[CUBESIZE-1], HIGH );
                } else {
                    digitalWrite( PlanePin[plane-1], HIGH );
                }

                // load current plane pattern data into ports
                ledpin = 0;
                for (ledrow = 0; ledrow < CUBESIZE; ledrow++) {
                    for (ledcol = 0; ledcol < CUBESIZE; ledcol++) {
                        digitalWrite(LEDPin[ledpin++], PatternBuf[patbufidx] & (1 << ledcol));
                    }
                    patbufidx++;
                }

                // turn current plane on
                digitalWrite( PlanePin[plane], LOW );
                delayMicroseconds( PLANETIME );
            }
        }
    } while (DisplayTime > 0);
}
