/* _ZN2GX7LoadOBJEPKvjj at 0x02056614 (size 0x60)
 * GX::LoadOBJ(src, offset, size) - copies count words from src into main OBJ
 * VRAM (0x6400000 + offset). Uses DMA channel if available, else CPU copy.
 */

extern unsigned int RENDER_DMA_CHANNEL;

extern void DMASyncWordTransfer(unsigned int channel, const void *src, void *dst, unsigned int count);
extern void MultiCopy_Int(const void *src, void *dst, unsigned int count);

#pragma opt_propagation off

void _ZN2GX7LoadOBJEPKvjj(const void *src, unsigned int offset, unsigned int count)
{
    unsigned int channel = RENDER_DMA_CHANNEL;
    unsigned int base = 0x6400000;
    if (channel != (unsigned int)-1) {
        DMASyncWordTransfer(channel, src, (void *)(base + offset), count);
    } else {
        MultiCopy_Int(src, (void *)(base + offset), count);
    }
}
