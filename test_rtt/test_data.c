/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test_data.c
 *
 * Code generated for Simulink model 'test'.
 *
 * Model version                  : 1.45
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 19 2015)
 * C/C++ source code generated on : Thu Aug 13 15:19:07 2015
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
  /*  Mask Parameter: RepeatingSequence3_rep_seq_y
   * Referenced by: '<S4>/Look-Up Table1'
   */
  { 5.0, 5.0, 35.0, 35.0, 65.0, 65.0, 95.0, 95.0, 125.0 },

  /*  Mask Parameter: RepeatingSequence1_rep_seq_y
   * Referenced by: '<S3>/Look-Up Table1'
   */
  { 0.0, 0.0, 30.0, 30.0, 60.0, 60.0, 90.0, 90.0, 120.0, 120.0, 150.0, 150.0,
    176.0, 176.0, 150.0, 150.0, 120.0, 120.0, 90.0, 90.0, 60.0, 60.0, 30.0, 30.0,
    0.0, 0.0 },

  /*  Mask Parameter: RepeatingSequence_rep_seq_y
   * Referenced by: '<S2>/Look-Up Table1'
   */
  { 90.0, 90.0, 60.0, 60.0, 30.0, 30.0, 0.0, 0.0, -30.0, -30.0, -60.0, -60.0,
    -90.0, -90.0, -60.0, -60.0, -30.0, -30.0, 0.0, 0.0, 30.0, 30.0, 60.0, 60.0,
    90.0, 90.0 },
  11U,                                 /* Mask Parameter: ServoWrite_pinNumber
                                        * Referenced by: '<S7>/Servo Write'
                                        */
  10U,                                 /* Mask Parameter: ServoWrite_pinNumber_k
                                        * Referenced by: '<S8>/Servo Write'
                                        */
  9U,                                  /* Mask Parameter: ServoWrite_pinNumber_l
                                        * Referenced by: '<S9>/Servo Write'
                                        */
  520.0,                               /* Expression: period
                                        * Referenced by: '<S4>/Constant'
                                        */

  /*  Expression: rep_seq_t - min(rep_seq_t)
   * Referenced by: '<S4>/Look-Up Table1'
   */
  { 0.0, 139.0, 140.0, 259.0, 260.0, 399.0, 400.0, 519.0, 520.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Gain'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S1>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Bias'
                                        */
  260.0,                               /* Expression: period
                                        * Referenced by: '<S3>/Constant'
                                        */

  /*  Expression: rep_seq_t - min(rep_seq_t)
   * Referenced by: '<S3>/Look-Up Table1'
   */
  { 0.0, 20.0, 21.0, 40.0, 41.0, 60.0, 61.0, 80.0, 81.0, 100.0, 101.0, 120.0,
    121.0, 140.0, 141.0, 160.0, 161.0, 180.0, 181.0, 200.0, 201.0, 220.0, 221.0,
    240.0, 241.0, 260.0 },
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  179.0,                               /* Expression: 179
                                        * Referenced by: '<S1>/Bias1'
                                        */
  40.0,                                /* Expression: period
                                        * Referenced by: '<S2>/Constant'
                                        */

  /*  Expression: rep_seq_t - min(rep_seq_t)
   * Referenced by: '<S2>/Look-Up Table1'
   */
  { 0.0, 2.0, 3.0, 5.0, 6.0, 8.0, 9.0, 11.0, 12.0, 14.0, 15.0, 17.0, 18.0, 23.0,
    24.0, 26.0, 27.0, 29.0, 30.0, 32.0, 33.0, 35.0, 36.0, 38.0, 39.0, 40.0 },
  90.0,                                /* Expression: 90
                                        * Referenced by: '<S1>/Saturation2'
                                        */
  -90.0,                               /* Expression: -90
                                        * Referenced by: '<S1>/Saturation2'
                                        */
  92.0,                                /* Expression: 92
                                        * Referenced by: '<S1>/Bias2'
                                        */
  0U,                                  /* Computed Parameter: ServoWrite_p1
                                        * Referenced by: '<S7>/Servo Write'
                                        */
  1U,                                  /* Computed Parameter: ServoWrite_p1_g
                                        * Referenced by: '<S8>/Servo Write'
                                        */
  2U                                   /* Computed Parameter: ServoWrite_p1_a
                                        * Referenced by: '<S9>/Servo Write'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
