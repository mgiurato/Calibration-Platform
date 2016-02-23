/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Calibration_procedure.c
 *
 * Code generated for Simulink model 'Calibration_procedure'.
 *
 * Model version                  : 1.79
 * Simulink Coder version         : 8.8.1 (R2015aSP1) 04-Sep-2015
 * TLC version                    : 8.8 (Sep  6 2015)
 * C/C++ source code generated on : Wed Feb 17 12:32:00 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Calibration_procedure.h"
#include "Calibration_procedure_private.h"

/* Block signals (auto storage) */
B_Calibration_procedure_T Calibration_procedure_B;

/* Real-time model */
RT_MODEL_Calibration_procedur_T Calibration_procedure_M_;
RT_MODEL_Calibration_procedur_T *const Calibration_procedure_M =
  &Calibration_procedure_M_;
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
void Calibration_procedure_output(void)
{
  /* local block i/o variables */
  real_T rtb_Clock;
  real_T rtb_Bias2;
  real_T rtb_LookUpTable1;
  real_T rtb_LookUpTable1_i;
  real_T rtb_LookUpTable1_m;
  real_T rtb_LookUpTable1_h;

  /* Clock: '<Root>/Clock' */
  rtb_Clock = Calibration_procedure_M->Timing.t[0];

  /* Clock: '<S10>/Clock' */
  rtb_Bias2 = Calibration_procedure_M->Timing.t[0];

  /* Sum: '<S10>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S10>/startTime'
   */
  rtb_Bias2 -= (0.0);

  /* Math: '<S10>/Math Function' incorporates:
   *  Constant: '<S10>/Constant'
   */
  rtb_Bias2 = rt_remd_snf(rtb_Bias2, Calibration_procedure_P.Constant_Value_g);

  /* Lookup_n-D: '<S10>/Look-Up Table1' */
  rtb_LookUpTable1 = look1_binlxpw(rtb_Bias2,
    Calibration_procedure_P.LookUpTable1_bp01Data,
    Calibration_procedure_P.RepeatingSequence2_rep_seq_y, 9UL);

  /* Clock: '<S9>/Clock' */
  rtb_Bias2 = Calibration_procedure_M->Timing.t[0];

  /* Sum: '<S9>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S9>/startTime'
   */
  rtb_Bias2 -= (0.0);

  /* Math: '<S9>/Math Function' incorporates:
   *  Constant: '<S9>/Constant'
   */
  rtb_Bias2 = rt_remd_snf(rtb_Bias2, Calibration_procedure_P.Constant_Value_b);

  /* Lookup_n-D: '<S9>/Look-Up Table1' */
  rtb_LookUpTable1_i = look1_binlxpw(rtb_Bias2,
    Calibration_procedure_P.LookUpTable1_bp01Data_j,
    Calibration_procedure_P.RepeatingSequence1_rep_seq_y, 15UL);

  /* Clock: '<S4>/Clock' */
  rtb_Bias2 = Calibration_procedure_M->Timing.t[0];

  /* Sum: '<S4>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S4>/startTime'
   */
  rtb_Bias2 -= (0.0);

  /* Math: '<S4>/Math Function' incorporates:
   *  Constant: '<S4>/Constant'
   */
  rtb_Bias2 = rt_remd_snf(rtb_Bias2, Calibration_procedure_P.Constant_Value_fw);

  /* Lookup_n-D: '<S4>/Look-Up Table1' */
  rtb_LookUpTable1_m = look1_binlxpw(rtb_Bias2,
    Calibration_procedure_P.LookUpTable1_bp01Data_i,
    Calibration_procedure_P.RepeatingSequence1_rep_seq_y_h, 16UL);

  /* Clock: '<S5>/Clock' */
  rtb_Bias2 = Calibration_procedure_M->Timing.t[0];

  /* Sum: '<S5>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S5>/startTime'
   */
  rtb_Bias2 -= (0.0);

  /* Math: '<S5>/Math Function' incorporates:
   *  Constant: '<S5>/Constant'
   */
  rtb_Bias2 = rt_remd_snf(rtb_Bias2, Calibration_procedure_P.Constant_Value_bc);

  /* Lookup_n-D: '<S5>/Look-Up Table1' */
  rtb_LookUpTable1_h = look1_binlxpw(rtb_Bias2,
    Calibration_procedure_P.LookUpTable1_bp01Data_h,
    Calibration_procedure_P.RepeatingSequence2_rep_seq_y_o, 17UL);

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<S1>/Constant'
   *  Switch: '<Root>/Switch'
   */
  if (rtb_Clock > Calibration_procedure_P.Switch1_Threshold) {
    rtb_LookUpTable1_m = Calibration_procedure_P.Constant_Value[0];
    rtb_LookUpTable1_h = Calibration_procedure_P.Constant_Value[1];
    rtb_LookUpTable1 = Calibration_procedure_P.Constant_Value[2];
  } else if (rtb_Clock > Calibration_procedure_P.Switch_Threshold) {
    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<S3>/Constant'
     */
    rtb_LookUpTable1_m = rtb_LookUpTable1;
    rtb_LookUpTable1_h = rtb_LookUpTable1_i;
    rtb_LookUpTable1 = Calibration_procedure_P.Constant_Value_f;
  } else {
    rtb_LookUpTable1 = Calibration_procedure_P.Constant_Value_o;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Saturate: '<S2>/Saturation' */
  if (rtb_LookUpTable1_m > Calibration_procedure_P.Saturation_UpperSat) {
    rtb_LookUpTable1_m = Calibration_procedure_P.Saturation_UpperSat;
  } else {
    if (rtb_LookUpTable1_m < Calibration_procedure_P.Saturation_LowerSat) {
      rtb_LookUpTable1_m = Calibration_procedure_P.Saturation_LowerSat;
    }
  }

  /* Bias: '<S2>/Bias' incorporates:
   *  Gain: '<S2>/Gain'
   *  Saturate: '<S2>/Saturation'
   *  UnaryMinus: '<S2>/Unary Minus'
   */
  rtb_Bias2 = Calibration_procedure_P.Gain_Gain * -rtb_LookUpTable1_m +
    Calibration_procedure_P.Bias_Bias;

  /* DataTypeConversion: '<S6>/Data Type Conversion' */
  if (rtb_Bias2 < 256.0) {
    if (rtb_Bias2 >= 0.0) {
      Calibration_procedure_B.DataTypeConversion = (uint8_T)rtb_Bias2;
    } else {
      Calibration_procedure_B.DataTypeConversion = 0U;
    }
  } else {
    Calibration_procedure_B.DataTypeConversion = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S6>/Data Type Conversion' */

  /* S-Function (arduinoservowrite_sfcn): '<S6>/Servo Write' */
  MW_servoWrite(Calibration_procedure_P.ServoWrite_p1,
                Calibration_procedure_B.DataTypeConversion);

  /* Saturate: '<S2>/Saturation1' */
  if (rtb_LookUpTable1_h > Calibration_procedure_P.Saturation1_UpperSat) {
    rtb_LookUpTable1_h = Calibration_procedure_P.Saturation1_UpperSat;
  } else {
    if (rtb_LookUpTable1_h < Calibration_procedure_P.Saturation1_LowerSat) {
      rtb_LookUpTable1_h = Calibration_procedure_P.Saturation1_LowerSat;
    }
  }

  /* Bias: '<S2>/Bias1' incorporates:
   *  Gain: '<S2>/Gain3'
   *  Gain: '<S2>/TrasmissioneRoll'
   *  Saturate: '<S2>/Saturation1'
   */
  rtb_Bias2 = Calibration_procedure_P.Gain3_Gain * rtb_LookUpTable1_h *
    Calibration_procedure_P.TrasmissioneRoll_Gain +
    Calibration_procedure_P.Bias1_Bias;

  /* DataTypeConversion: '<S7>/Data Type Conversion' */
  if (rtb_Bias2 < 256.0) {
    if (rtb_Bias2 >= 0.0) {
      Calibration_procedure_B.DataTypeConversion_e = (uint8_T)rtb_Bias2;
    } else {
      Calibration_procedure_B.DataTypeConversion_e = 0U;
    }
  } else {
    Calibration_procedure_B.DataTypeConversion_e = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S7>/Data Type Conversion' */

  /* S-Function (arduinoservowrite_sfcn): '<S7>/Servo Write' */
  MW_servoWrite(Calibration_procedure_P.ServoWrite_p1_e,
                Calibration_procedure_B.DataTypeConversion_e);

  /* Saturate: '<S2>/Saturation2' */
  if (rtb_LookUpTable1 > Calibration_procedure_P.Saturation2_UpperSat) {
    rtb_LookUpTable1 = Calibration_procedure_P.Saturation2_UpperSat;
  } else {
    if (rtb_LookUpTable1 < Calibration_procedure_P.Saturation2_LowerSat) {
      rtb_LookUpTable1 = Calibration_procedure_P.Saturation2_LowerSat;
    }
  }

  /* Bias: '<S2>/Bias2' incorporates:
   *  Gain: '<S2>/Gain4'
   *  Gain: '<S2>/TrasmissioneYaw'
   *  Saturate: '<S2>/Saturation2'
   */
  rtb_Bias2 = Calibration_procedure_P.Gain4_Gain * rtb_LookUpTable1 *
    Calibration_procedure_P.TrasmissioneYaw_Gain +
    Calibration_procedure_P.Bias2_Bias;

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  if (rtb_Bias2 < 256.0) {
    if (rtb_Bias2 >= 0.0) {
      Calibration_procedure_B.DataTypeConversion_c = (uint8_T)rtb_Bias2;
    } else {
      Calibration_procedure_B.DataTypeConversion_c = 0U;
    }
  } else {
    Calibration_procedure_B.DataTypeConversion_c = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S8>/Data Type Conversion' */

  /* S-Function (arduinoservowrite_sfcn): '<S8>/Servo Write' */
  MW_servoWrite(Calibration_procedure_P.ServoWrite_p1_d,
                Calibration_procedure_B.DataTypeConversion_c);
}

/* Model update function */
void Calibration_procedure_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Calibration_procedure_M->Timing.t[0] =
    (++Calibration_procedure_M->Timing.clockTick0) *
    Calibration_procedure_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Calibration_procedure_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Calibration_procedure_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Calibration_procedure_M, 0,
                sizeof(RT_MODEL_Calibration_procedur_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Calibration_procedure_M->solverInfo,
                          &Calibration_procedure_M->Timing.simTimeStep);
    rtsiSetTPtr(&Calibration_procedure_M->solverInfo, &rtmGetTPtr
                (Calibration_procedure_M));
    rtsiSetStepSizePtr(&Calibration_procedure_M->solverInfo,
                       &Calibration_procedure_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Calibration_procedure_M->solverInfo, ((const char_T **)
      (&rtmGetErrorStatus(Calibration_procedure_M))));
    rtsiSetRTModelPtr(&Calibration_procedure_M->solverInfo,
                      Calibration_procedure_M);
  }

  rtsiSetSimTimeStep(&Calibration_procedure_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Calibration_procedure_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Calibration_procedure_M, &Calibration_procedure_M->Timing.tArray[0]);
  Calibration_procedure_M->Timing.stepSize0 = 0.01;

  /* block I/O */
  (void) memset(((void *) &Calibration_procedure_B), 0,
                sizeof(B_Calibration_procedure_T));

  /* Start for S-Function (arduinoservowrite_sfcn): '<S6>/Servo Write' */
  MW_servoAttach(Calibration_procedure_P.ServoWrite_p1,
                 Calibration_procedure_P.ServoWrite_pinNumber);

  /* Start for S-Function (arduinoservowrite_sfcn): '<S7>/Servo Write' */
  MW_servoAttach(Calibration_procedure_P.ServoWrite_p1_e,
                 Calibration_procedure_P.ServoWrite_pinNumber_f);

  /* Start for S-Function (arduinoservowrite_sfcn): '<S8>/Servo Write' */
  MW_servoAttach(Calibration_procedure_P.ServoWrite_p1_d,
                 Calibration_procedure_P.ServoWrite_pinNumber_n);
}

/* Model terminate function */
void Calibration_procedure_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
