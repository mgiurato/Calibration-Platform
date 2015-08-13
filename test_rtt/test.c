/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test.c
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

/* Block signals (auto storage) */
B_test_T test_B;

/* Real-time model */
RT_MODEL_test_T test_M_;
RT_MODEL_test_T *const test_M = &test_M_;
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0UL]) {
    iLeft = 0UL;
    frac = (u0 - bp0[0UL]) / (bp0[1UL] - bp0[0UL]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1UL;
    iLeft = 0UL;
    iRght = maxIndex;
    while (iRght - iLeft > 1UL) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1UL;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1UL] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1UL;
    frac = (u0 - bp0[maxIndex - 1UL]) / (bp0[maxIndex] - bp0[maxIndex - 1UL]);
  }

  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  return (table[iLeft + 1UL] - table[iLeft]) * frac + table[iLeft];
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T u1_0;
  if (!((!rtIsNaN(u0)) && (!rtIsInf(u0)) && ((!rtIsNaN(u1)) && (!rtIsInf(u1)))))
  {
    y = (rtNaN);
  } else {
    if (u1 < 0.0) {
      u1_0 = ceil(u1);
    } else {
      u1_0 = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != u1_0)) {
      u1_0 = u0 / u1;
      if (fabs(u1_0 - rt_roundd_snf(u1_0)) <= DBL_EPSILON * fabs(u1_0)) {
        y = 0.0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

/* Model output function */
void test_output(void)
{
  /* local block i/o variables */
  real_T rtb_Bias2;
  real_T tmp;

  /* Clock: '<S4>/Clock' */
  rtb_Bias2 = test_M->Timing.t[0];

  /* Sum: '<S4>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S4>/startTime'
   */
  rtb_Bias2 -= (0.0);

  /* Math: '<S4>/Math Function' incorporates:
   *  Constant: '<S4>/Constant'
   */
  rtb_Bias2 = rt_remd_snf(rtb_Bias2, test_P.Constant_Value);

  /* Lookup_n-D: '<S4>/Look-Up Table1' */
  rtb_Bias2 = look1_binlxpw(rtb_Bias2, test_P.LookUpTable1_bp01Data,
    test_P.RepeatingSequence3_rep_seq_y, 8UL);

  /* Gain: '<S1>/Gain' */
  rtb_Bias2 *= test_P.Gain_Gain;

  /* Saturate: '<S1>/Saturation' */
  if (rtb_Bias2 > test_P.Saturation_UpperSat) {
    tmp = test_P.Saturation_UpperSat;
  } else if (rtb_Bias2 < test_P.Saturation_LowerSat) {
    tmp = test_P.Saturation_LowerSat;
  } else {
    tmp = rtb_Bias2;
  }

  /* Bias: '<S1>/Bias' incorporates:
   *  Saturate: '<S1>/Saturation'
   */
  rtb_Bias2 = tmp + test_P.Bias_Bias;

  /* DataTypeConversion: '<S7>/Data Type Conversion' */
  if (rtb_Bias2 < 256.0) {
    if (rtb_Bias2 >= 0.0) {
      test_B.DataTypeConversion = (uint8_T)rtb_Bias2;
    } else {
      test_B.DataTypeConversion = 0U;
    }
  } else {
    test_B.DataTypeConversion = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S7>/Data Type Conversion' */

  /* S-Function (arduinoservowrite_sfcn): '<S7>/Servo Write' */
  MW_servoWrite(test_P.ServoWrite_p1, test_B.DataTypeConversion);

  /* Clock: '<S3>/Clock' */
  rtb_Bias2 = test_M->Timing.t[0];

  /* Sum: '<S3>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S3>/startTime'
   */
  rtb_Bias2 -= (0.0);

  /* Math: '<S3>/Math Function' incorporates:
   *  Constant: '<S3>/Constant'
   */
  rtb_Bias2 = rt_remd_snf(rtb_Bias2, test_P.Constant_Value_c);

  /* Lookup_n-D: '<S3>/Look-Up Table1' */
  rtb_Bias2 = look1_binlxpw(rtb_Bias2, test_P.LookUpTable1_bp01Data_c,
    test_P.RepeatingSequence1_rep_seq_y, 25UL);

  /* Saturate: '<S1>/Saturation1' */
  if (rtb_Bias2 > test_P.Saturation1_UpperSat) {
    tmp = test_P.Saturation1_UpperSat;
  } else if (rtb_Bias2 < test_P.Saturation1_LowerSat) {
    tmp = test_P.Saturation1_LowerSat;
  } else {
    tmp = rtb_Bias2;
  }

  /* Bias: '<S1>/Bias1' incorporates:
   *  Saturate: '<S1>/Saturation1'
   *  UnaryMinus: '<S1>/Unary Minus1'
   */
  rtb_Bias2 = -tmp + test_P.Bias1_Bias;

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  if (rtb_Bias2 < 256.0) {
    if (rtb_Bias2 >= 0.0) {
      test_B.DataTypeConversion_b = (uint8_T)rtb_Bias2;
    } else {
      test_B.DataTypeConversion_b = 0U;
    }
  } else {
    test_B.DataTypeConversion_b = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S8>/Data Type Conversion' */

  /* S-Function (arduinoservowrite_sfcn): '<S8>/Servo Write' */
  MW_servoWrite(test_P.ServoWrite_p1_g, test_B.DataTypeConversion_b);

  /* Clock: '<S2>/Clock' */
  rtb_Bias2 = test_M->Timing.t[0];

  /* Sum: '<S2>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S2>/startTime'
   */
  rtb_Bias2 -= (0.0);

  /* Math: '<S2>/Math Function' incorporates:
   *  Constant: '<S2>/Constant'
   */
  rtb_Bias2 = rt_remd_snf(rtb_Bias2, test_P.Constant_Value_a);

  /* Lookup_n-D: '<S2>/Look-Up Table1' */
  rtb_Bias2 = look1_binlxpw(rtb_Bias2, test_P.LookUpTable1_bp01Data_d,
    test_P.RepeatingSequence_rep_seq_y, 25UL);

  /* Saturate: '<S1>/Saturation2' */
  if (rtb_Bias2 > test_P.Saturation2_UpperSat) {
    tmp = test_P.Saturation2_UpperSat;
  } else if (rtb_Bias2 < test_P.Saturation2_LowerSat) {
    tmp = test_P.Saturation2_LowerSat;
  } else {
    tmp = rtb_Bias2;
  }

  /* Bias: '<S1>/Bias2' incorporates:
   *  Saturate: '<S1>/Saturation2'
   */
  rtb_Bias2 = tmp + test_P.Bias2_Bias;

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  if (rtb_Bias2 < 256.0) {
    if (rtb_Bias2 >= 0.0) {
      test_B.DataTypeConversion_i = (uint8_T)rtb_Bias2;
    } else {
      test_B.DataTypeConversion_i = 0U;
    }
  } else {
    test_B.DataTypeConversion_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S9>/Data Type Conversion' */

  /* S-Function (arduinoservowrite_sfcn): '<S9>/Servo Write' */
  MW_servoWrite(test_P.ServoWrite_p1_a, test_B.DataTypeConversion_i);
}

/* Model update function */
void test_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  test_M->Timing.t[0] =
    (++test_M->Timing.clockTick0) * test_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    test_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void test_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)test_M, 0,
                sizeof(RT_MODEL_test_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&test_M->solverInfo, &test_M->Timing.simTimeStep);
    rtsiSetTPtr(&test_M->solverInfo, &rtmGetTPtr(test_M));
    rtsiSetStepSizePtr(&test_M->solverInfo, &test_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&test_M->solverInfo, ((const char_T **)
      (&rtmGetErrorStatus(test_M))));
    rtsiSetRTModelPtr(&test_M->solverInfo, test_M);
  }

  rtsiSetSimTimeStep(&test_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&test_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(test_M, &test_M->Timing.tArray[0]);
  test_M->Timing.stepSize0 = 0.01;

  /* block I/O */
  (void) memset(((void *) &test_B), 0,
                sizeof(B_test_T));

  /* Start for S-Function (arduinoservowrite_sfcn): '<S7>/Servo Write' */
  MW_servoAttach(test_P.ServoWrite_p1, test_P.ServoWrite_pinNumber);

  /* Start for S-Function (arduinoservowrite_sfcn): '<S8>/Servo Write' */
  MW_servoAttach(test_P.ServoWrite_p1_g, test_P.ServoWrite_pinNumber_k);

  /* Start for S-Function (arduinoservowrite_sfcn): '<S9>/Servo Write' */
  MW_servoAttach(test_P.ServoWrite_p1_a, test_P.ServoWrite_pinNumber_l);
}

/* Model terminate function */
void test_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
