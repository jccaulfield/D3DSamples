#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//
//   fxc /O3 /T ps_5_0 src/BlurX_PS.hlsl /E BlurX_PS /DMAIN_FUNCTION=BlurX_PS
//    /Fh bin/BlurX_PS.h
//
//
// Buffer Definitions: 
//
// cbuffer GlobalConstantBuffer
// {
//
//   float2 g_InvQuarterResolution;     // Offset:    0 Size:     8 [unused]
//   float2 g_InvFullResolution;        // Offset:    8 Size:     8
//   float2 g_UVToViewA;                // Offset:   16 Size:     8 [unused]
//   float2 g_UVToViewB;                // Offset:   24 Size:     8 [unused]
//   float g_RadiusToScreen;            // Offset:   32 Size:     4 [unused]
//   float g_R2;                        // Offset:   36 Size:     4 [unused]
//   float g_NegInvR2;                  // Offset:   40 Size:     4 [unused]
//   float g_NDotVBias;                 // Offset:   44 Size:     4 [unused]
//   float g_LinearizeDepthA;           // Offset:   48 Size:     4 [unused]
//   float g_LinearizeDepthB;           // Offset:   52 Size:     4 [unused]
//   float g_InverseDepthRangeA;        // Offset:   56 Size:     4 [unused]
//   float g_InverseDepthRangeB;        // Offset:   60 Size:     4 [unused]
//   float g_AOMultiplier;              // Offset:   64 Size:     4 [unused]
//   float g_PowExponent;               // Offset:   68 Size:     4 [unused]
//   float g_BlurSharpness;             // Offset:   72 Size:     4
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// PointClampSampler                 sampler      NA          NA    0        1
// AODepthTexture                    texture  float2          2d    0        1
// GlobalConstantBuffer              cbuffer      NA          NA    0        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_Position              0   xyzw        0      POS  float       
// TEXCOORD                 0   xy          1     NONE  float   xy  
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_TARGET                0   xy          0   TARGET  float   xy  
//
ps_5_0
dcl_globalFlags refactoringAllowed
dcl_constantbuffer cb0[5], immediateIndexed
dcl_sampler s0, mode_default
dcl_resource_texture2d (float,float,float,float) t0
dcl_input_ps linear v1.xy
dcl_output o0.xy
dcl_temps 4
mov r0.x, cb0[0].z
mov r0.y, l(3.000000)
mad r0.xyzw, r0.xyxy, l(3.000000, 0.000000, -3.000000, -0.000000), v1.xyxy
sample_indexable(texture2d)(float,float,float,float) r0.xy, r0.xyxx, t0.xyzw, s0
sample_indexable(texture2d)(float,float,float,float) r0.zw, r0.zwzz, t0.zwxy, s0
mov r1.xz, cb0[0].zzzz
mov r1.yw, l(0,0,0,2.000000)
add r2.xy, r1.xyxx, v1.xyxx
sample_indexable(texture2d)(float,float,float,float) r2.xy, r2.xyxx, t0.xyzw, s0
sample_indexable(texture2d)(float,float,float,float) r2.zw, v1.xyxx, t0.zwxy, s0
add r2.y, -r2.w, r2.y
mul r2.y, r2.y, cb0[4].z
mad r2.y, -r2.y, r2.y, l(-0.222222)
exp r2.y, r2.y
mad r2.x, r2.y, r2.x, r2.z
add r2.y, r2.y, l(1.000000)
mad r3.xyzw, r1.zwzw, l(2.000000, 0.000000, -2.000000, -0.000000), v1.xyxy
add r1.xy, -r1.xyxx, v1.xyxx
sample_indexable(texture2d)(float,float,float,float) r1.xy, r1.xyxx, t0.xyzw, s0
sample_indexable(texture2d)(float,float,float,float) r1.zw, r3.xyxx, t0.zwxy, s0
sample_indexable(texture2d)(float,float,float,float) r3.xy, r3.zwzz, t0.xyzw, s0
add r1.yw, -r2.wwww, r1.yyyw
mul r1.yw, r1.yyyw, cb0[4].zzzz
mad r1.w, -r1.w, r1.w, l(-0.888889)
exp r1.w, r1.w
mad r1.z, r1.w, r1.z, r2.x
add r1.w, r1.w, r2.y
add r0.yw, r0.yyyw, -r2.wwww
mul r0.yw, r0.yyyw, cb0[4].zzzz
mad r0.y, -r0.y, r0.y, l(-2.000000)
exp r0.y, r0.y
mad r0.x, r0.y, r0.x, r1.z
add r0.y, r0.y, r1.w
mad r1.y, -r1.y, r1.y, l(-0.222222)
exp r1.y, r1.y
mad r0.x, r1.y, r1.x, r0.x
add r0.y, r0.y, r1.y
add r1.x, -r2.w, r3.y
mul r1.x, r1.x, cb0[4].z
mad r1.x, -r1.x, r1.x, l(-0.888889)
exp r1.x, r1.x
mad r0.x, r1.x, r3.x, r0.x
add r0.y, r0.y, r1.x
mov o0.y, r2.w
mad r0.w, -r0.w, r0.w, l(-2.000000)
exp r0.w, r0.w
mad r0.x, r0.w, r0.z, r0.x
add r0.y, r0.w, r0.y
div o0.x, r0.x, r0.y
ret 
// Approximately 50 instruction slots used
#endif

const BYTE g_BlurX_PS[] =
{
     68,  88,  66,  67, 158,  26, 
     88, 215, 114, 118, 135,  28, 
     11,  20,  60, 250, 240, 200, 
      7, 138,   1,   0,   0,   0, 
    204,  12,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
    244,   4,   0,   0,  76,   5, 
      0,   0, 128,   5,   0,   0, 
     48,  12,   0,   0,  82,  68, 
     69,  70, 184,   4,   0,   0, 
      1,   0,   0,   0, 212,   0, 
      0,   0,   3,   0,   0,   0, 
     60,   0,   0,   0,   0,   5, 
    255, 255,   0, 129,   0,   0, 
    135,   4,   0,   0,  82,  68, 
     49,  49,  60,   0,   0,   0, 
     24,   0,   0,   0,  32,   0, 
      0,   0,  40,   0,   0,   0, 
     36,   0,   0,   0,  12,   0, 
      0,   0,   0,   0,   0,   0, 
    156,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0, 174,   0,   0,   0, 
      2,   0,   0,   0,   5,   0, 
      0,   0,   4,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      5,   0,   0,   0, 189,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     80, 111, 105, 110, 116,  67, 
    108,  97, 109, 112,  83,  97, 
    109, 112, 108, 101, 114,   0, 
     65,  79,  68, 101, 112, 116, 
    104,  84, 101, 120, 116, 117, 
    114, 101,   0,  71, 108, 111, 
     98,  97, 108,  67, 111, 110, 
    115, 116,  97, 110, 116,  66, 
    117, 102, 102, 101, 114,   0, 
    171, 171, 189,   0,   0,   0, 
     15,   0,   0,   0, 236,   0, 
      0,   0,  80,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  68,   3,   0,   0, 
      0,   0,   0,   0,   8,   0, 
      0,   0,   0,   0,   0,   0, 
    100,   3,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    136,   3,   0,   0,   8,   0, 
      0,   0,   8,   0,   0,   0, 
      2,   0,   0,   0, 100,   3, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 156,   3, 
      0,   0,  16,   0,   0,   0, 
      8,   0,   0,   0,   0,   0, 
      0,   0, 100,   3,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 168,   3,   0,   0, 
     24,   0,   0,   0,   8,   0, 
      0,   0,   0,   0,   0,   0, 
    100,   3,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    180,   3,   0,   0,  32,   0, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0, 204,   3, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 240,   3, 
      0,   0,  36,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0, 204,   3,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 245,   3,   0,   0, 
     40,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
    204,   3,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
      0,   4,   0,   0,  44,   0, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0, 204,   3, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,  12,   4, 
      0,   0,  48,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0, 204,   3,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0,  30,   4,   0,   0, 
     52,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
    204,   3,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
     48,   4,   0,   0,  56,   0, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0, 204,   3, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,  69,   4, 
      0,   0,  60,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0, 204,   3,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0,  90,   4,   0,   0, 
     64,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
    204,   3,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    105,   4,   0,   0,  68,   0, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0, 204,   3, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 119,   4, 
      0,   0,  72,   0,   0,   0, 
      4,   0,   0,   0,   2,   0, 
      0,   0, 204,   3,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 103,  95,  73, 110, 
    118,  81, 117,  97, 114, 116, 
    101, 114,  82, 101, 115, 111, 
    108, 117, 116, 105, 111, 110, 
      0, 102, 108, 111,  97, 116, 
     50,   0, 171, 171,   1,   0, 
      3,   0,   1,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     91,   3,   0,   0, 103,  95, 
     73, 110, 118,  70, 117, 108, 
    108,  82, 101, 115, 111, 108, 
    117, 116, 105, 111, 110,   0, 
    103,  95,  85,  86,  84, 111, 
     86, 105, 101, 119,  65,   0, 
    103,  95,  85,  86,  84, 111, 
     86, 105, 101, 119,  66,   0, 
    103,  95,  82,  97, 100, 105, 
    117, 115,  84, 111,  83,  99, 
    114, 101, 101, 110,   0, 102, 
    108, 111,  97, 116,   0, 171, 
      0,   0,   3,   0,   1,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 197,   3,   0,   0, 
    103,  95,  82,  50,   0, 103, 
     95,  78, 101, 103,  73, 110, 
    118,  82,  50,   0, 103,  95, 
     78,  68, 111, 116,  86,  66, 
    105,  97, 115,   0, 103,  95, 
     76, 105, 110, 101,  97, 114, 
    105, 122, 101,  68, 101, 112, 
    116, 104,  65,   0, 103,  95, 
     76, 105, 110, 101,  97, 114, 
    105, 122, 101,  68, 101, 112, 
    116, 104,  66,   0, 103,  95, 
     73, 110, 118, 101, 114, 115, 
    101,  68, 101, 112, 116, 104, 
     82,  97, 110, 103, 101,  65, 
      0, 103,  95,  73, 110, 118, 
    101, 114, 115, 101,  68, 101, 
    112, 116, 104,  82,  97, 110, 
    103, 101,  66,   0, 103,  95, 
     65,  79,  77, 117, 108, 116, 
    105, 112, 108, 105, 101, 114, 
      0, 103,  95,  80, 111, 119, 
     69, 120, 112, 111, 110, 101, 
    110, 116,   0, 103,  95,  66, 
    108, 117, 114,  83, 104,  97, 
    114, 112, 110, 101, 115, 115, 
      0,  77, 105,  99, 114, 111, 
    115, 111, 102, 116,  32,  40, 
     82,  41,  32,  72,  76,  83, 
     76,  32,  83, 104,  97, 100, 
    101, 114,  32,  67, 111, 109, 
    112, 105, 108, 101, 114,  32, 
     57,  46,  50,  57,  46,  57, 
     53,  50,  46,  51,  49,  49, 
     49,   0,  73,  83,  71,  78, 
     80,   0,   0,   0,   2,   0, 
      0,   0,   8,   0,   0,   0, 
     56,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,  15,   0,   0,   0, 
     68,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,   3,   3,   0,   0, 
     83,  86,  95,  80, 111, 115, 
    105, 116, 105, 111, 110,   0, 
     84,  69,  88,  67,  79,  79, 
     82,  68,   0, 171, 171, 171, 
     79,  83,  71,  78,  44,   0, 
      0,   0,   1,   0,   0,   0, 
      8,   0,   0,   0,  32,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      3,  12,   0,   0,  83,  86, 
     95,  84,  65,  82,  71,  69, 
     84,   0, 171, 171,  83,  72, 
     69,  88, 168,   6,   0,   0, 
     80,   0,   0,   0, 170,   1, 
      0,   0, 106,   8,   0,   1, 
     89,   0,   0,   4,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      5,   0,   0,   0,  90,   0, 
      0,   3,   0,  96,  16,   0, 
      0,   0,   0,   0,  88,  24, 
      0,   4,   0, 112,  16,   0, 
      0,   0,   0,   0,  85,  85, 
      0,   0,  98,  16,   0,   3, 
     50,  16,  16,   0,   1,   0, 
      0,   0, 101,   0,   0,   3, 
     50,  32,  16,   0,   0,   0, 
      0,   0, 104,   0,   0,   2, 
      4,   0,   0,   0,  54,   0, 
      0,   6,  18,   0,  16,   0, 
      0,   0,   0,   0,  42, 128, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  54,   0, 
      0,   5,  34,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,  64,  64, 
     50,   0,   0,  12, 242,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   4,  16,   0,   0,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,  64,  64,   0,   0, 
      0,   0,   0,   0,  64, 192, 
      0,   0,   0, 128,  70,  20, 
     16,   0,   1,   0,   0,   0, 
     69,   0,   0, 139, 194,   0, 
      0, 128,  67,  85,  21,   0, 
     50,   0,  16,   0,   0,   0, 
      0,   0,  70,   0,  16,   0, 
      0,   0,   0,   0,  70, 126, 
     16,   0,   0,   0,   0,   0, 
      0,  96,  16,   0,   0,   0, 
      0,   0,  69,   0,   0, 139, 
    194,   0,   0, 128,  67,  85, 
     21,   0, 194,   0,  16,   0, 
      0,   0,   0,   0, 230,  10, 
     16,   0,   0,   0,   0,   0, 
    230, 116,  16,   0,   0,   0, 
      0,   0,   0,  96,  16,   0, 
      0,   0,   0,   0,  54,   0, 
      0,   6,  82,   0,  16,   0, 
      1,   0,   0,   0, 166, 138, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  54,   0, 
      0,   8, 162,   0,  16,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,  64, 
      0,   0,   0,   7,  50,   0, 
     16,   0,   2,   0,   0,   0, 
     70,   0,  16,   0,   1,   0, 
      0,   0,  70,  16,  16,   0, 
      1,   0,   0,   0,  69,   0, 
      0, 139, 194,   0,   0, 128, 
     67,  85,  21,   0,  50,   0, 
     16,   0,   2,   0,   0,   0, 
     70,   0,  16,   0,   2,   0, 
      0,   0,  70, 126,  16,   0, 
      0,   0,   0,   0,   0,  96, 
     16,   0,   0,   0,   0,   0, 
     69,   0,   0, 139, 194,   0, 
      0, 128,  67,  85,  21,   0, 
    194,   0,  16,   0,   2,   0, 
      0,   0,  70,  16,  16,   0, 
      1,   0,   0,   0, 230, 116, 
     16,   0,   0,   0,   0,   0, 
      0,  96,  16,   0,   0,   0, 
      0,   0,   0,   0,   0,   8, 
     34,   0,  16,   0,   2,   0, 
      0,   0,  58,   0,  16, 128, 
     65,   0,   0,   0,   2,   0, 
      0,   0,  26,   0,  16,   0, 
      2,   0,   0,   0,  56,   0, 
      0,   8,  34,   0,  16,   0, 
      2,   0,   0,   0,  26,   0, 
     16,   0,   2,   0,   0,   0, 
     42, 128,  32,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
     50,   0,   0,  10,  34,   0, 
     16,   0,   2,   0,   0,   0, 
     26,   0,  16, 128,  65,   0, 
      0,   0,   2,   0,   0,   0, 
     26,   0,  16,   0,   2,   0, 
      0,   0,   1,  64,   0,   0, 
     57, 142,  99, 190,  25,   0, 
      0,   5,  34,   0,  16,   0, 
      2,   0,   0,   0,  26,   0, 
     16,   0,   2,   0,   0,   0, 
     50,   0,   0,   9,  18,   0, 
     16,   0,   2,   0,   0,   0, 
     26,   0,  16,   0,   2,   0, 
      0,   0,  10,   0,  16,   0, 
      2,   0,   0,   0,  42,   0, 
     16,   0,   2,   0,   0,   0, 
      0,   0,   0,   7,  34,   0, 
     16,   0,   2,   0,   0,   0, 
     26,   0,  16,   0,   2,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0, 128,  63,  50,   0, 
      0,  12, 242,   0,  16,   0, 
      3,   0,   0,   0, 230,  14, 
     16,   0,   1,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,  64,   0,   0,   0,   0, 
      0,   0,   0, 192,   0,   0, 
      0, 128,  70,  20,  16,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   8,  50,   0,  16,   0, 
      1,   0,   0,   0,  70,   0, 
     16, 128,  65,   0,   0,   0, 
      1,   0,   0,   0,  70,  16, 
     16,   0,   1,   0,   0,   0, 
     69,   0,   0, 139, 194,   0, 
      0, 128,  67,  85,  21,   0, 
     50,   0,  16,   0,   1,   0, 
      0,   0,  70,   0,  16,   0, 
      1,   0,   0,   0,  70, 126, 
     16,   0,   0,   0,   0,   0, 
      0,  96,  16,   0,   0,   0, 
      0,   0,  69,   0,   0, 139, 
    194,   0,   0, 128,  67,  85, 
     21,   0, 194,   0,  16,   0, 
      1,   0,   0,   0,  70,   0, 
     16,   0,   3,   0,   0,   0, 
    230, 116,  16,   0,   0,   0, 
      0,   0,   0,  96,  16,   0, 
      0,   0,   0,   0,  69,   0, 
      0, 139, 194,   0,   0, 128, 
     67,  85,  21,   0,  50,   0, 
     16,   0,   3,   0,   0,   0, 
    230,  10,  16,   0,   3,   0, 
      0,   0,  70, 126,  16,   0, 
      0,   0,   0,   0,   0,  96, 
     16,   0,   0,   0,   0,   0, 
      0,   0,   0,   8, 162,   0, 
     16,   0,   1,   0,   0,   0, 
    246,  15,  16, 128,  65,   0, 
      0,   0,   2,   0,   0,   0, 
     86,  13,  16,   0,   1,   0, 
      0,   0,  56,   0,   0,   8, 
    162,   0,  16,   0,   1,   0, 
      0,   0,  86,  13,  16,   0, 
      1,   0,   0,   0, 166, 138, 
     32,   0,   0,   0,   0,   0, 
      4,   0,   0,   0,  50,   0, 
      0,  10, 130,   0,  16,   0, 
      1,   0,   0,   0,  58,   0, 
     16, 128,  65,   0,   0,   0, 
      1,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,  57, 142, 
     99, 191,  25,   0,   0,   5, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16,   0, 
      1,   0,   0,   0,  50,   0, 
      0,   9,  66,   0,  16,   0, 
      1,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     42,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   7, 130,   0,  16,   0, 
      1,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     26,   0,  16,   0,   2,   0, 
      0,   0,   0,   0,   0,   8, 
    162,   0,  16,   0,   0,   0, 
      0,   0,  86,  13,  16,   0, 
      0,   0,   0,   0, 246,  15, 
     16, 128,  65,   0,   0,   0, 
      2,   0,   0,   0,  56,   0, 
      0,   8, 162,   0,  16,   0, 
      0,   0,   0,   0,  86,  13, 
     16,   0,   0,   0,   0,   0, 
    166, 138,  32,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
     50,   0,   0,  10,  34,   0, 
     16,   0,   0,   0,   0,   0, 
     26,   0,  16, 128,  65,   0, 
      0,   0,   0,   0,   0,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0, 192,  25,   0, 
      0,   5,  34,   0,  16,   0, 
      0,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
     50,   0,   0,   9,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  42,   0, 
     16,   0,   1,   0,   0,   0, 
      0,   0,   0,   7,  34,   0, 
     16,   0,   0,   0,   0,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      1,   0,   0,   0,  50,   0, 
      0,  10,  34,   0,  16,   0, 
      1,   0,   0,   0,  26,   0, 
     16, 128,  65,   0,   0,   0, 
      1,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,  57, 142, 
     99, 190,  25,   0,   0,   5, 
     34,   0,  16,   0,   1,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,  50,   0, 
      0,   9,  18,   0,  16,   0, 
      0,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   7,  34,   0,  16,   0, 
      0,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
     26,   0,  16,   0,   1,   0, 
      0,   0,   0,   0,   0,   8, 
     18,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16, 128, 
     65,   0,   0,   0,   2,   0, 
      0,   0,  26,   0,  16,   0, 
      3,   0,   0,   0,  56,   0, 
      0,   8,  18,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
     42, 128,  32,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
     50,   0,   0,  10,  18,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16, 128,  65,   0, 
      0,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   1,   0, 
      0,   0,   1,  64,   0,   0, 
     57, 142,  99, 191,  25,   0, 
      0,   5,  18,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
     50,   0,   0,   9,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      3,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
      0,   0,   0,   7,  34,   0, 
     16,   0,   0,   0,   0,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      1,   0,   0,   0,  54,   0, 
      0,   5,  34,  32,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   2,   0,   0,   0, 
     50,   0,   0,  10, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16, 128,  65,   0, 
      0,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0, 192,  25,   0, 
      0,   5, 130,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
     50,   0,   0,   9,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  42,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
      0,   0,   0,   7,  34,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,  14,   0, 
      0,   7,  18,  32,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,  62,   0,   0,   1, 
     83,  84,  65,  84, 148,   0, 
      0,   0,  50,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
     23,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   7,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      5,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0
};
