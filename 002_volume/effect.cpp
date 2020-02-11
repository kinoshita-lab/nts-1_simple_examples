#include <cstdint>
#include "userrevfx.h" // これ必要なので注意！

float volume = 0.f; // ボリューム　0.0 ~ 1.0まで

void REVFX_INIT(uint32_t platform, uint32_t api)
{
}


void REVFX_PROCESS(float *xn, uint32_t frames)
{   
  for (auto i = 0u; i < frames; ++i) { // サンプルの数分だけ・・・
    float* l_input = xn++; // L CHのサンプルを取り出す    
    float* r_input = xn++; // R CHのサンプルを取り出す

    *l_input = *l_input * volume; // L CHのサンプルはL CHにボリュームを掛けたもの
    *r_input = *r_input * volume; // R CHのサンプルはR CHにボリュームを掛けたもの
  }
}


void REVFX_PARAM(uint8_t index, int32_t value)
{
  const float valf = q31_to_f32(value);
  switch (index) {
    case k_user_revfx_param_time:
    volume = valf;
    break;
    default:
    break;
  }
}

