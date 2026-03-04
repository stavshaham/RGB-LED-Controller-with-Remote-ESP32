#ifndef REMOTECONTROL_H
#define REMOTECONTROL_H

#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

void initIR(IRrecv &irrecv);
void checkButtons(int length, decode_results &results);

#endif