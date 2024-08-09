/******************************************************************************
 * Header: VirtualizerSDK_LCC_inline_TIGER_EXTREME.h
 * Description: LCC inline assembly macros definitions
 *
 * Author/s: Oreans Technologies 
 * (c) 2014 Oreans Technologies
 *
 * --- File generated automatically from Oreans VM Generator (2/4/2014) ---
 ******************************************************************************/

/***********************************************
 * Definition as inline assembly
 ***********************************************/

#ifdef PLATFORM_X32

#ifndef VIRTUALIZER_TIGER_EXTREME_START
#define VIRTUALIZER_TIGER_EXTREME_START                    __asm__ (" .byte\t0xEB, 0x10, 0x43, 0x56, 0x20, 0x20, 0x7E, 0x00, 0x00, 0x00, \
                                                                     0x00, 0x00, 0x00, 0x00, 0x43, 0x56, 0x20, 0x20");
#endif

#ifndef VIRTUALIZER_TIGER_EXTREME_END
#define VIRTUALIZER_TIGER_EXTREME_END                      __asm__ (" .byte\t0xEB, 0x10, 0x43, 0x56, 0x20, 0x20, 0x0E, 0x02, 0x00, 0x00, \
                                                                     0x00, 0x00, 0x00, 0x00, 0x43, 0x56, 0x20, 0x20");
#endif

#endif

#ifdef PLATFORM_X64

#ifndef VIRTUALIZER_TIGER_EXTREME_START
#define VIRTUALIZER_TIGER_EXTREME_START                    __asm__ (" .byte\t0xEB, 0x10, 0x43, 0x56, 0x20, 0x20, 0x7F, 0x00, 0x00, 0x00, \
                                                                     0x00, 0x00, 0x00, 0x00, 0x43, 0x56, 0x20, 0x20");
#endif

#ifndef VIRTUALIZER_TIGER_EXTREME_END
#define VIRTUALIZER_TIGER_EXTREME_END                      __asm__ (" .byte\t0xEB, 0x10, 0x43, 0x56, 0x20, 0x20, 0x0F, 0x02, 0x00, 0x00, \
                                                                     0x00, 0x00, 0x00, 0x00, 0x43, 0x56, 0x20, 0x20");
#endif

#endif

