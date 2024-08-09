/******************************************************************************
 * Header: VirtualizerSDK_LCC_inline_CAT_WHITE.h
 * Description: LCC inline assembly macros definitions
 *
 * Author/s: Oreans Technologies 
 * (c) 2016 Oreans Technologies
 *
 * --- File generated automatically from Oreans VM Generator (8/1/2016) ---
 ******************************************************************************/

/***********************************************
 * Definition as inline assembly
 ***********************************************/

#ifdef PLATFORM_X32

#ifndef VIRTUALIZER_CAT_WHITE_START
#define VIRTUALIZER_CAT_WHITE_START                        __asm__ (" .byte\t0xEB, 0x10, 0x43, 0x56, 0x20, 0x20, 0x98, 0x00, 0x00, 0x00, \
                                                                     0x00, 0x00, 0x00, 0x00, 0x43, 0x56, 0x20, 0x20");
#endif

#ifndef VIRTUALIZER_CAT_WHITE_END
#define VIRTUALIZER_CAT_WHITE_END                          __asm__ (" .byte\t0xEB, 0x10, 0x43, 0x56, 0x20, 0x20, 0x28, 0x02, 0x00, 0x00, \
                                                                     0x00, 0x00, 0x00, 0x00, 0x43, 0x56, 0x20, 0x20");
#endif

#endif

#ifdef PLATFORM_X64

#ifndef VIRTUALIZER_CAT_WHITE_START
#define VIRTUALIZER_CAT_WHITE_START                        __asm__ (" .byte\t0xEB, 0x10, 0x43, 0x56, 0x20, 0x20, 0x99, 0x00, 0x00, 0x00, \
                                                                     0x00, 0x00, 0x00, 0x00, 0x43, 0x56, 0x20, 0x20");
#endif

#ifndef VIRTUALIZER_CAT_WHITE_END
#define VIRTUALIZER_CAT_WHITE_END                          __asm__ (" .byte\t0xEB, 0x10, 0x43, 0x56, 0x20, 0x20, 0x29, 0x02, 0x00, 0x00, \
                                                                     0x00, 0x00, 0x00, 0x00, 0x43, 0x56, 0x20, 0x20");
#endif

#endif

