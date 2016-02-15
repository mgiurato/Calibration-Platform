/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sersin_data.c
 *
 * Code generated for Simulink model 'sersin'.
 *
 * Model version                  : 1.64
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 19 2015)
 * C/C++ source code generated on : Tue Sep 15 11:48:06 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "sersin.h"
#include "sersin_private.h"

/* Block parameters (auto storage) */
P_sersin_T sersin_P = {
  /*  Mask Parameter: RepeatingSequence1_rep_seq_y
   * Referenced by: '<S1>/Look-Up Table1'
   */
  { -90.0, -90.0, -45.0, -45.0, 0.0, 0.0, 45.0, 45.0, 90.0, 90.0, 45.0, 45.0,
    0.0, 0.0, -45.0, -45.0, -90.0 },

  /*  Mask Parameter: RepeatingSequence2_rep_seq_y
   * Referenced by: '<S2>/Look-Up Table1'
   */
  { 0.0, 0.0, 45.0, 45.0, 90.0, 90.0, 135.0, 135.0, 180.0, 180.0, 135.0, 135.0,
    90.0, 90.0, 45.0, 45.0, 0.0, 0.0, -45.0, -45.0, -90.0, -90.0, -135.0, -135.0,
    -180.0, -180.0, -135.0, -135.0, -90.0, -90.0, -45.0, -45.0, 0.0 },

  /*  Mask Parameter: RepeatingSequence4_rep_seq_y
   * Referenced by: '<S3>/Look-Up Table1'
   */
  { 180.0, 180.0, 90.0, 90.0, 0.0, 0.0, -90.0, -90.0, -180.0, -180.0, -90.0,
    -90.0, 0.0, 0.0, 90.0, 90.0, 180.0 },
  9U,                                  /* Mask Parameter: ServoWrite_pinNumber
                                        * Referenced by: '<S4>/Servo Write'
                                        */
  10U,                                 /* Mask Parameter: ServoWrite_pinNumber_f
                                        * Referenced by: '<S5>/Servo Write'
                                        */
  11U,                                 /* Mask Parameter: ServoWrite_pinNumber_n
                                        * Referenced by: '<S6>/Servo Write'
                                        */
  16.0,                                /* Expression: period
                                        * Referenced by: '<S1>/Constant'
                                        */

  /*  Expression: rep_seq_t - min(rep_seq_t)
   * Referenced by: '<S1>/Look-Up Table1'
   */
  { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0,
    14.0, 15.0, 16.0 },
  90.0,                                /* Expression: 90
                                        * Referenced by: '<Root>/Saturation'
                                        */
  -90.0,                               /* Expression: -90
                                        * Referenced by: '<Root>/Saturation'
                                        */
  0.58333333333333337,                 /* Expression: (130-25)/180
                                        * Referenced by: '<Root>/Gain'
                                        */
  90.0,                                /* Expression: 90
                                        * Referenced by: '<Root>/Bias'
                                        */
  128.0,                               /* Expression: period
                                        * Referenced by: '<S2>/Constant'
                                        */

  /*  Expression: rep_seq_t - min(rep_seq_t)
   * Referenced by: '<S2>/Look-Up Table1'
   */
  { 0.0, 7.0, 8.0, 15.0, 16.0, 23.0, 24.0, 31.0, 32.0, 39.0, 40.0, 47.0, 48.0,
    55.0, 56.0, 63.0, 64.0, 71.0, 72.0, 79.0, 80.0, 87.0, 88.0, 95.0, 96.0,
    103.0, 104.0, 111.0, 112.0, 119.0, 120.0, 127.0, 128.0 },
  180.0,                               /* Expression: 180
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  -180.0,                              /* Expression: -180
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  0.58333333333333337,                 /* Expression: (130-25)/180
                                        * Referenced by: '<Root>/Gain3'
                                        */
  0.50485436893203883,                 /* Expression: 52/103
                                        * Referenced by: '<Root>/Gain1'
                                        */
  89.0,                                /* Expression: 89
                                        * Referenced by: '<Root>/Bias1'
                                        */
  1025.0,                              /* Expression: period
                                        * Referenced by: '<S3>/Constant'
                                        */

  /*  Expression: rep_seq_t - min(rep_seq_t)
   * Referenced by: '<S3>/Look-Up Table1'
   */
  { 0.0, 127.0, 128.0, 255.0, 257.0, 383.0, 385.0, 511.0, 513.0, 639.0, 641.0,
    767.0, 769.0, 895.0, 897.0, 1023.0, 1025.0 },
  180.0,                               /* Expression: 180
                                        * Referenced by: '<Root>/Saturation2'
                                        */
  -180.0,                              /* Expression: -180
                                        * Referenced by: '<Root>/Saturation2'
                                        */
  0.44444444444444442,                 /* Expression: (115-35)/180
                                        * Referenced by: '<Root>/Gain4'
                                        */
  0.62765957446808507,                 /* Expression: 59/94
                                        * Referenced by: '<Root>/Gain2'
                                        */
  90.0,                                /* Expression: 90
                                        * Referenced by: '<Root>/Bias2'
                                        */
  0U,                                  /* Computed Parameter: ServoWrite_p1
                                        * Referenced by: '<S4>/Servo Write'
                                        */
  1U,                                  /* Computed Parameter: ServoWrite_p1_e
                                        * Referenced by: '<S5>/Servo Write'
                                        */
  2U                                   /* Computed Parameter: ServoWrite_p1_d
                                        * Referenced by: '<S6>/Servo Write'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
