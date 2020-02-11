#include <cstdint>
#include "userrevfx.h"

void REVFX_INIT(uint32_t platform, uint32_t api)
{
}


void REVFX_PROCESS(float *xn, uint32_t frames)
{   
  for (auto i = 0u; i < frames; ++i) { // サンプルの数分だけ・・・
    float* l_input = xn++; // L CHのサンプルを取り出す    
    float* r_input = xn++; // R CHのサンプルを取り出す

    *l_input = 0; // L CHのサンプルの大きさを0
    *r_input = 0; // R CHのサンプルの大きさを0
  }
}


void REVFX_PARAM(uint8_t index, int32_t value)
{
}

