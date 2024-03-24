#include <drivers/audio/pcspeaker/pcspeaker.h>
#include <kernel/io.h>

void pcspeaker_sleep(unsigned int milliseconds) {
    unsigned int cycles_per_ms = 1000000;
    unsigned int cycles = milliseconds * cycles_per_ms;

    for (unsigned int i = 0; i < cycles; ++i) {
        __asm__("nop");
    }
}

static void pcspeaker_play(pcspeaker_uint32_t nFrequence) {
    pcspeaker_uint32_t Div;
    pcspeaker_uint8_t tmp;

    Div = 1193180 / nFrequence;
    outb(0x43, 0xb6);
    outb(0x42, (pcspeaker_uint8_t) (Div) );
    outb(0x42, (pcspeaker_uint8_t) (Div >> 8));

    tmp = inb(0x61);
    if (tmp != (tmp | 3)) {
        outb(0x61, tmp | 3);
    }
}

static void pcspeaker_mute() {
    pcspeaker_uint8_t tmp = inb(0x61) & 0xFC;

    outb(0x61, tmp);
}

void pcspeaker_beep() {
    pcspeaker_play(1000);
    pcspeaker_sleep(50);
    pcspeaker_mute();
}
