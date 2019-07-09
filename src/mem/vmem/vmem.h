/**
 * @file
 * @brief
 *
 * @date 28.09.2012
 * @author Anton Bulychev
 */

#ifndef MEM_VMEM_H_
#define MEM_VMEM_H_

#include <hal/mmu.h>
#include <stddef.h>
#include <sys/mman.h>

#define VMEM_PAGE_SIZE        MMU_PAGE_SIZE
#define VMEM_PAGE_MASK        MMU_PAGE_MASK

#define VMEM_PAGE_USERMODE    (1 << 6)

extern int vmem_create_context(mmu_ctx_t *ctx);
extern mmu_ctx_t vmem_current_context(void);
extern void vmem_free_context(mmu_ctx_t ctx);

extern mmu_paddr_t vmem_translate(mmu_ctx_t ctx, mmu_vaddr_t virt_addr);

extern int vmem_map_region(mmu_ctx_t ctx, mmu_paddr_t phy_addr, mmu_vaddr_t virt_addr,
		size_t reg_size, int flags);

extern void vmem_unmap_region(mmu_ctx_t ctx, mmu_vaddr_t virt_addr, size_t reg_size);

extern int vmem_set_flags(mmu_ctx_t ctx, mmu_vaddr_t virt_addr, ssize_t len, int flags);

#define MMU_LAST_LEVEL (MMU_LEVELS - 1)

#ifndef __MMU_SHIFT_1
#define __MMU_SHIFT_1 0
#endif

#ifndef __MMU_SHIFT_2
#define __MMU_SHIFT_2 0
#endif

#ifndef __MMU_SHIFT_3
#define __MMU_SHIFT_3 0
#endif

#define MMU_SHIFT(i) ((i == -1) ? 32 : \
			(i) == 0 ? __MMU_SHIFT_0 : \
			(i) == 1 ? __MMU_SHIFT_1 : \
			(i) == 2 ? __MMU_SHIFT_2 : __MMU_SHIFT_3)

#define MMU_ENTRIES(i) (1 << (MMU_SHIFT(i - 1) - MMU_SHIFT((i))))
#define MMU_MASK(i) ((MMU_ENTRIES(i) - 1) << MMU_SHIFT(i))
#define MMU_SIZE(i) (MMU_ENTRIES(i) * sizeof(mmu_vaddr_t))

#endif /* MEM_VMEM_H_ */