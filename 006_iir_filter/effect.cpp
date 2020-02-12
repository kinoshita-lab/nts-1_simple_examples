#include <cstdint>
#include "userrevfx.h" // これ必要なので注意！

// 前の信号を覚えておくメモリ（バッファ）を作る iirの場合1個でよい
float lch_buffer; 
float rch_buffer;

float a  = 1.0;  // 係数aの値

void REVFX_INIT(uint32_t platform, uint32_t api)
{
  // バッファを初期化
  lch_buffer = 0.0;  
  rch_buffer = 0.0;
}


void REVFX_PROCESS(float *xn, uint32_t frames)
{   
  for (auto i = 0u; i < frames; ++i) { // サンプルの数分だけ・・・
    float* l_input = xn++; // L CHのサンプルを取り出す    
    float* r_input = xn++; // R CHのサンプルを取り出す

    const float l_filtered = a * (*l_input) + (1-a) * lch_buffer;
    const float r_filtered = a * (*r_input) + (1-a) * rch_buffer;

    *l_input = l_filtered;
    *r_input = r_filtered;

    // 今の出力をバッファに保存する
    lch_buffer = l_filtered;
    rch_buffer = r_filtered;
  }

}


void REVFX_PARAM(uint8_t index, int32_t value)
{
  const float valf = q31_to_f32(value); // valueを小数の 0.0 - 1.0に変換する

  switch (index) {
    case k_user_revfx_param_time: // A のノブを回したとき・・・
    a = valf; //　その値をフィルタのa係数として使う
    break;
    default:
    break;
  }
}

