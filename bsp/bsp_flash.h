#ifndef __BSP_FLASH_H
#define __BSP_FLASH_H


#define FLASH_LOCK_ALLOW_WRITE_MEMCTL       0xD513B490          // Write this value to FLASHLOCK to allow write to MEMCTL register
#define FLASH_LOCK_ALLOW_WRITE_ERASE_FLASH  0x43DF140A          // Write this value to FLASHLOCK to allow write and erase operations to FLASH
#define FLASH_LOCK_ALLOW_WRITE_SWDFUSE      0x79B4F762          // Write this value to FLASHLOCK to allow write access to INFO2.SWDFUSE to permanently disable SWD
#define FLASH_LOCK_ALLOW_WRITE_SECEN        0x1D855C1E          // Write this value to FLASHLOCK to allow writes to INFO2.SECEN

#define FLASH_START_PAGE_ERASE              0x8C799CA7          // Allow memory controller to start a FLASH page erase operation. 
#define FLASH_ERASE_INFO_3                  0x1266FF45          // Allow erase info-3 flash pages
#define FLASH_START_MASS_PAGE_ERASE         0x09EE76C9          // Start a Mass Erase of all flash memory pages
#define FLASH_START_MASS_PROG_INFO_ERASE    0x856E0E70          // Start a Mass Program and INFO3 Erase
#define FLASH_SWDFUSE_ACCESS                0x79B4F762          // This define is Deprecated, see FLASH_LOCK_ALLOW_WRITE_SWDFUSE // Write this value to FLASHLOCK to allow writes to SWDFUSE
#define FLASH_SECEN_ACCESS                  0x1D855C1E          // This define is Deprecated, see FLASH_LOCK_ALLOW_WRITE_SECEN   //Write this value to FLASHLOCK to allow writes to SECEN


#endif 




// end of file 

