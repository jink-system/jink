#ifndef PCSPEAKER_H
#define PCSPEAKER_H

typedef unsigned char pcspeaker_uint8_t;
typedef unsigned int pcspeaker_uint32_t;

void pcspeaker_sleep(unsigned int milliseconds);
static void pcspeaker_play(pcspeaker_uint32_t nFrequence);
static void pcspeaker_mute();
void pcspeaker_beep();

#endif
