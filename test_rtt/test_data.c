/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test_data.c
 *
 * Code generated for Simulink model 'test'.
 *
 * Model version                  : 1.36
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 19 2015)
 * C/C++ source code generated on : Wed Aug 12 21:22:23 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "test.h"
#include "test_private.h"

/* Block parameters (auto storage) */
P_test_T test_P = {
  /*  Mask Parameter: RepeatingSequenceStair1_OutValu
   * Referenced by: '<S3>/Vector'
   */
  { 0.0, 30.0, 60.0, 90.0, 120.0, 150.0, 176.0 },

  /*  Mask Parameter: RepeatingSequenceStair_OutValue
   * Referenced by: '<S2>/Vector'
   */
  { 90.0, 60.0, 30.0, 0.0, -30.0, -60.0, -90.0 },
  11U,                                 /* Mask Parameter: ServoWrite_pinNumber
                                        * Referenced by: '<S4>/Servo Write'
                                        */
  10U,                                 /* Mask Parameter: ServoWrite_pinNumber_k
                                        * Referenced by: '<S6>/Servo Write'
                                        */
  9U,                                  /* Mask Parameter: ServoWrite_pinNumber_l
                                        * Referenced by: '<S7>/Servo Write'
                                        */
  6U,                                  /* Mask Parameter: LimitedCounter_uplimit
                                        * Referenced by: '<S13>/FixPt Switch'
                                        */
  6U,                                  /* Mask Parameter: LimitedCounter_uplimit_h
                                        * Referenced by: '<S16>/FixPt Switch'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  4900.0,                              /* Computed Parameter: PulseGenerator_Period
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  50.0,                                /* Computed Parameter: PulseGenerator_Duty
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Gain'
                                        */
  90.0,                                /* Expression: 90
                                        * Referenced by: '<S1>/Saturation'
                                        */
  -90.0,                               /* Expression: -90
                                        * Referenced by: '<S1>/Saturation'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S1>/Bias'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  179.0,                               /* Expression: 179
                                        * Referenced by: '<S1>/Bias1'
                                        */
  90.0,                                /* Expression: 90
                                        * Referenced by: '<S1>/Saturation2'
                                        */
  -90.0,                               /* Expression: -90
                                        * Referenced by: '<S1>/Saturation2'
                                        */
  94.0,                                /* Expression: 94
                                        * Referenced by: '<S1>/Bias2'
                                        */
  0U,                                  /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S13>/Constant'
                                        */
  0U,                                  /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S16>/Constant'
                                        */
  90U,                                 /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S4>/Constant'
                                        */
  0U,                                  /* Computed Parameter: ServoWrite_p1
                                        * Referenced by: '<S4>/Servo Write'
                                        */
  0U,                                  /* Computed Parameter: Output_InitialCondition
                                        * Referenced by: '<S14>/Output'
                                        */
  1U,                                  /* Computed Parameter: ServoWrite_p1_g
                                        * Referenced by: '<S6>/Servo Write'
                                        */
  0U,                                  /* Computed Parameter: Output_InitialCondition_f
                                        * Referenced by: '<S11>/Output'
                                        */
  2U,                                  /* Computed Parameter: ServoWrite_p1_a
                                        * Referenced by: '<S7>/Servo Write'
                                        */
  1U,                                  /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S12>/FixPt Constant'
                                        */
  1U                                   /* Computed Parameter: FixPtConstant_Value_d
                                        * Referenced by: '<S15>/FixPt Constant'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
