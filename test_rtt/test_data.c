/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test_data.c
 *
 * Code generated for Simulink model 'test'.
 *
 * Model version                  : 1.32
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 19 2015)
 * C/C++ source code generated on : Wed Aug 12 20:39:07 2015
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
  11U,                                 /* Mask Parameter: ServoWrite_pinNumber
                                        * Referenced by: '<S4>/Servo Write'
                                        */
  10U,                                 /* Mask Parameter: ServoWrite_pinNumber_k
                                        * Referenced by: '<S6>/Servo Write'
                                        */
  9U,                                  /* Mask Parameter: ServoWrite_pinNumber_l
                                        * Referenced by: '<S7>/Servo Write'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
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
  90U,                                 /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S4>/Constant'
                                        */
  0U,                                  /* Computed Parameter: ServoWrite_p1
                                        * Referenced by: '<S4>/Servo Write'
                                        */
  1U,                                  /* Computed Parameter: ServoWrite_p1_g
                                        * Referenced by: '<S6>/Servo Write'
                                        */
  2U                                   /* Computed Parameter: ServoWrite_p1_a
                                        * Referenced by: '<S7>/Servo Write'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
