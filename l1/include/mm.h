#ifndef	_MM_H
#define	_MM_H

// 2^12 = 4096 bytes, size of a page
#define PAGE_SHIFT 12
// 2^9 = 512 entries in a page table
#define TABLE_SHIFT 9
// section size 2MB, big page
#define SECTION_SHIFT (PAGE_SHIFT + TABLE_SHIFT)
// section map
#define SECTION_SIZE (1 << SECTION_SHIFT)
// low memory mode, stack grows from 4MB down to 0
#define LOW_MEMORY (2 * SECTION_SIZE)
// page size
#define PAGE_SIZE (1 << PAGE_SHIFT)

#ifndef __ASSEMBLER__
void memzero(unsigned long src, unsigned long n);

#endif
#endif