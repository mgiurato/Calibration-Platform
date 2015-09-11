/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sersin.c
 *
 * Code generated for Simulink model 'sersin'.
 *
 * Model version                  : 1.55
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 19 2015)
 * C/C++ source code generated on : Fri Sep 11 19:58:22 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "sersin.h"
#include "sersin_private.h"

/* Block signals (auto storage) */
B_sersin_T sersin_B;

/* Real-time model */
RT_MODEL_sersin_T sersin_M_;
RT_MODEL_sersin_T *const sersin_M = &sersin_M_;
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
void sersin_output(void)
{
  /* local block i/o variables */
  real_T rtb_Bias1;
  real_T tmp;
  uint8_T tmp_0;

  /* Clock: '<S1>/Clock' */
  rtb_Bias1 = sersin_M->Timing.t[0];

  /* Sum: '<S1>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S1>/startTime'
   */
  rtb_Bias1 -= (0.0);

  /* Math: '<S1>/Math Function' incorporates:
   *  Constant: '<S1>/Constant'
   */
  rtb_Bias1 = rt_remd_snf(rtb_Bias1, sersin_P.Constant_Value);

  /* Lookup_n-D: '<S1>/Look-Up Table1' */
  rtb_Bias1 = look1_binlxpw(rtb_Bias1, sersin_P.LookUpTable1_bp01Data,
    sersin_P.RepeatingSequence1_rep_seq_y, 16UL);

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Bias1 > sersin_P.Saturation_UpperSat) {
    tmp = sersin_P.Saturation_UpperSat;
  } else if (rtb_Bias1 < sersin_P.Saturation_LowerSat) {
    tmp = sersin_P.Saturation_LowerSat;
  } else {
    tmp = rtb_Bias1;
  }

  /* Bias: '<Root>/Bias' incorporates:
   *  Gain: '<Root>/Gain'
   *  Saturate: '<Root>/Saturation'
   */
  rtb_Bias1 = sersin_P.Gain_Gain * tmp + sersin_P.Bias_Bias;

  /* DataTypeConversion: '<S3>/Data Type Conversion' */
  if (rtb_Bias1 < 256.0) {
    if (rtb_Bias1 >= 0.0) {
      sersin_B.DataTypeConversion = (uint8_T)rtb_Bias1;
    } else {
      sersin_B.DataTypeConversion = 0U;
    }
  } else {
    sersin_B.DataTypeConversion = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S3>/Data Type Conversion' */

  /* S-Function (arduinoservowrite_sfcn): '<S3>/Servo Write' */
  MW_servoWrite(sersin_P.ServoWrite_p1, sersin_B.DataTypeConversion);

  /* Clock: '<S2>/Clock' */
  rtb_Bias1 = sersin_M->Timing.t[0];

  /* Sum: '<S2>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S2>/startTime'
   */
  rtb_Bias1 -= (0.0);

  /* Math: '<S2>/Math Function' incorporates:
   *  Constant: '<S2>/Constant'
   */
  rtb_Bias1 = rt_remd_snf(rtb_Bias1, sersin_P.Constant_Value_b);

  /* Lookup_n-D: '<S2>/Look-Up Table1' */
  rtb_Bias1 = look1_binlxpw(rtb_Bias1, sersin_P.LookUpTable1_bp01Data_h,
    sersin_P.RepeatingSequence2_rep_seq_y, 32UL);

  /* Saturate: '<Root>/Saturation1' */
  if (rtb_Bias1 > sersin_P.Saturation1_UpperSat) {
    tmp = sersin_P.Saturation1_UpperSat;
  } else if (rtb_Bias1 < sersin_P.Saturation1_LowerSat) {
    tmp = sersin_P.Saturation1_LowerSat;
  } else {
    tmp = rtb_Bias1;
  }

  /* Bias: '<Root>/Bias1' incorporates:
   *  Gain: '<Root>/Gain1'
   *  Gain: '<Root>/Gain3'
   *  Saturate: '<Root>/Saturation1'
   */
  rtb_Bias1 = sersin_P.Gain3_Gain * tmp * sersin_P.Gain1_Gain +
    sersin_P.Bias1_Bias;

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  if (rtb_Bias1 < 256.0) {
    if (rtb_Bias1 >= 0.0) {
      sersin_B.DataTypeConversion_e = (uint8_T)rtb_Bias1;
    } else {
      sersin_B.DataTypeConversion_e = 0U;
    }
  } else {
    sersin_B.DataTypeConversion_e = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S4>/Data Type Conversion' */

  /* S-Function (arduinoservowrite_sfcn): '<S4>/Servo Write' */
  MW_servoWrite(sersin_P.ServoWrite_p1_e, sersin_B.DataTypeConversion_e);

  /* Saturate: '<Root>/Saturation2' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  if (sersin_P.Constant2_Value > sersin_P.Saturation2_UpperSat) {
    tmp = sersin_P.Saturation2_UpperSat;
  } else if (sersin_P.Constant2_Value < sersin_P.Saturation2_LowerSat) {
    tmp = sersin_P.Saturation2_LowerSat;
  } else {
    tmp = sersin_P.Constant2_Value;
  }

  /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
   *  Bias: '<Root>/Bias2'
   *  Gain: '<Root>/Gain2'
   *  Gain: '<Root>/Gain4'
   *  Saturate: '<Root>/Saturation2'
   */
  tmp = sersin_P.Gain4_Gain * tmp * sersin_P.Gain2_Gain + sersin_P.Bias2_Bias;
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S5>/Data Type Conversion' */

  /* S-Function (arduinoservowrite_sfcn): '<S5>/Servo Write' */
  MW_servoWrite(sersin_P.ServoWrite_p1_d, tmp_0);
}

/* Model update function */
void sersin_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  sersin_M->Timing.t[0] =
    (++sersin_M->Timing.clockTick0) * sersin_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    sersin_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void sersin_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)sersin_M, 0,
                sizeof(RT_MODEL_sersin_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&sersin_M->solverInfo, &sersin_M->Timing.simTimeStep);
    rtsiSetTPtr(&sersin_M->solverInfo, &rtmGetTPtr(sersin_M));
    rtsiSetStepSizePtr(&sersin_M->solverInfo, &sersin_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&sersin_M->solverInfo, ((const char_T **)
      (&rtmGetErrorStatus(sersin_M))));
    rtsiSetRTModelPtr(&sersin_M->solverInfo, sersin_M);
  }

  rtsiSetSimTimeStep(&sersin_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&sersin_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(sersin_M, &sersin_M->Timing.tArray[0]);
  sersin_M->Timing.stepSize0 = 0.01;

  /* block I/O */
  (void) memset(((void *) &sersin_B), 0,
                sizeof(B_sersin_T));

  /* Start for S-Function (arduinoservowrite_sfcn): '<S3>/Servo Write' */
  MW_servoAttach(sersin_P.ServoWrite_p1, sersin_P.ServoWrite_pinNumber);

  /* Start for S-Function (arduinoservowrite_sfcn): '<S4>/Servo Write' */
  MW_servoAttach(sersin_P.ServoWrite_p1_e, sersin_P.ServoWrite_pinNumber_f);

  /* Start for S-Function (arduinoservowrite_sfcn): '<S5>/Servo Write' */
  MW_servoAttach(sersin_P.ServoWrite_p1_d, sersin_P.ServoWrite_pinNumber_n);
}

/* Model terminate function */
void sersin_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
