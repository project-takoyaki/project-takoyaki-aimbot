/******************************************************************************
 * Header: VirtualizerSDK_LCC_inline_CAT_RED.h
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

#ifndef VIRTUALIZER_CAT_RED_START
#define VIRTUALIZER_CAT_RED_START                          __asm__ (" .byte\t0xEB, 0x10, 0x43, 0x56, 0x20, 0x20, 0x9A, 0x00, 0x00, 0x00, \
                                                                     0x00, 0x00, 0x00, 0x00, 0x43, 0x56, 0x20, 0x20");
#endif

#ifndef VIRTUALIZER_CAT_RED_END
#define VIRTUALIZER_CAT_RED_END                            __asm__ (" .byte\t0xEB, 0x10, 0x43, 0x56, 0x20, 0x20, 0x2A, 0x02, 0x00, 0x00, \
                                                                     0x00, 0x00, 0x00, 0x00, 0x43, 0x56, 0x20, 0x20");
#endif

#endif

#ifdef PLATFORM_X64

#ifndef VIRTUALIZER_CAT_RED_START
#define VIRTUALIZER_CAT_RED_START                          __asm__ (" .byte\t0xEB, 0x10, 0x43, 0x56, 0x20, 0x20, 0x9B, 0x00, 0x00, 0x00, \
                                                                     0x00, 0x00, 0x00, 0x00, 0x43, 0x56, 0x20, 0x20");
#endif

#ifndef VIRTUALIZER_CAT_RED_END
#define VIRTUALIZER_CAT_RED_END                            __asm__ (" .byte\t0xEB, 0x10, 0x43, 0x56, 0x20, 0x20, 0x2B, 0x02, 0x00, 0x00, \
                                                                     0x00, 0x00, 0x00, 0x00, 0x43, 0x56, 0x20, 0x20");
#endif

#endif

