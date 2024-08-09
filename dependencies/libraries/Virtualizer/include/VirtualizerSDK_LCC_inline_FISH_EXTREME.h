/******************************************************************************
 * Header: VirtualizerSDK_LCC_inline_FISH_EXTREME.h
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

#ifndef VIRTUALIZER_FISH_EXTREME_START
#define VIRTUALIZER_FISH_EXTREME_START                     __asm__ (" .byte\t0xEB, 0x10, 0x43, 0x56, 0x20, 0x20, 0x7C, 0x00, 0x00, 0x00, \
                                                                     0x00, 0x00, 0x00, 0x00, 0x43, 0x56, 0x20, 0x20");
#endif

#ifndef VIRTUALIZER_FISH_EXTREME_END
#define VIRTUALIZER_FISH_EXTREME_END                       __asm__ (" .byte\t0xEB, 0x10, 0x43, 0x56, 0x20, 0x20, 0x0C, 0x02, 0x00, 0x00, \
                                                                     0x00, 0x00, 0x00, 0x00, 0x43, 0x56, 0x20, 0x20");
#endif

#endif

#ifdef PLATFORM_X64

#ifndef VIRTUALIZER_FISH_EXTREME_START
#define VIRTUALIZER_FISH_EXTREME_START                     __asm__ (" .byte\t0xEB, 0x10, 0x43, 0x56, 0x20, 0x20, 0x7D, 0x00, 0x00, 0x00, \
                                                                     0x00, 0x00, 0x00, 0x00, 0x43, 0x56, 0x20, 0x20");
#endif

#ifndef VIRTUALIZER_FISH_EXTREME_END
#define VIRTUALIZER_FISH_EXTREME_END                       __asm__ (" .byte\t0xEB, 0x10, 0x43, 0x56, 0x20, 0x20, 0x0D, 0x02, 0x00, 0x00, \
                                                                     0x00, 0x00, 0x00, 0x00, 0x43, 0x56, 0x20, 0x20");
#endif

#endif

