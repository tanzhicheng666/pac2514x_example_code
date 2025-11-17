// PAC55xx SDK Usage Notes
// 
// - When using the pac_m4_sdk, include the pac.h file to access PAC register structures
//     and definitions.
// - Add PAC55xx driver header files as needed for access to driver levels functions (see examples below).
// - It's also important to include one of the device header files before accessing the AFE registers
//     that are included in pac_tile... headers (see example below).  Each analog module in the AFE 
//     is considered a "Tile".
// - Including the device header file defines the appropriate PAC device (E.g. PAC25140)
//     and the associated CAFE Architecture (CAFE_ARCH1 or CAFE_ARCH2).

#include "pac.h"                        // pac.h also includes most peripheral header files
#include "pac_driver_gpio.h"
#include "pac_driver_system.h"

// Include one of the following device headers before accessing AFE registers included in pac_tile... headers
#include "pac25140.h"


