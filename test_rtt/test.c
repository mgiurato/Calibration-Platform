/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test.c
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

/* Block signals (auto storage) */
B_test_T test_B;

/* Block states (auto storage) */
DW_test_T test_DW;

/* Real-time model */
RT_MODEL_test_T test_M_;
RT_MODEL_test_T *const test_M = &test_M_;
static void rate_monotonic_scheduler(void);

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (test_M->Timing.TaskCounters.TID[1])++;
  if ((test_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [1.0s, 0.0s] */
    test_M->Timing.TaskCounters.TID[1] = 0;
  }

  (test_M->Timing.TaskCounters.TID[2])++;
  if ((test_M->Timing.TaskCounters.TID[2]) > 699) {/* Sample time: [7.0s, 0.0s] */
    test_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Model output function for TID0 */
void test_output0(void)                /* Sample time: [0.01s, 0.0s] */
{
  real_T rtb_Bias;
  int8_T tmp;

  {                                    /* Sample time: [0.01s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_Bias = (test_DW.clockTickCounter < test_P.PulseGenerator_Duty) &&
    (test_DW.clockTickCounter >= 0L) ? test_P.PulseGenerator_Amp : 0.0;
  if (test_DW.clockTickCounter >= test_P.PulseGenerator_Period - 1.0) {
    test_DW.clockTickCounter = 0L;
  } else {
    test_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* Gain: '<S1>/Gain' */
  rtb_Bias *= test_P.Gain_Gain;

  /* Saturate: '<S1>/Saturation' */
  if (rtb_Bias > test_P.Saturation_UpperSat) {
    rtb_Bias = test_P.Saturation_UpperSat;
  } else {
    if (rtb_Bias < test_P.Saturation_LowerSat) {
      rtb_Bias = test_P.Saturation_LowerSat;
    }
  }

  /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
   *  Bias: '<S1>/Bias'
   *  Saturate: '<S1>/Saturation'
   *  UnaryMinus: '<S1>/Unary Minus'
   */
  rtb_Bias = floor(-rtb_Bias + test_P.Bias_Bias);
  if (rtb_Bias < 128.0) {
    if (rtb_Bias >= -128.0) {
      tmp = (int8_T)rtb_Bias;
    } else {
      tmp = MIN_int8_T;
    }
  } else {
    tmp = MAX_int8_T;
  }

  /* End of DataTypeConversion: '<S4>/Data Type Conversion' */

  /* S-Function (arduinoservowrite_sfcn): '<S4>/Servo Write' incorporates:
   *  Constant: '<S4>/Constant'
   *  Sum: '<S4>/Add'
   */
  MW_servoWrite(test_P.ServoWrite_p1, (uint8_T)((uint16_T)(uint8_T)tmp +
    test_P.Constant_Value_d));
}

/* Model update function for TID0 */
void test_update0(void)                /* Sample time: [0.01s, 0.0s] */
{
  /* (no update code required) */
}

/* Model output function for TID1 */
void test_output1(void)                /* Sample time: [1.0s, 0.0s] */
{
  uint8_T rtb_FixPtSum1;
  real_T tmp;

  /* Saturate: '<S1>/Saturation2' incorporates:
   *  Constant: '<S2>/Vector'
   *  MultiPortSwitch: '<S2>/Output'
   *  UnitDelay: '<S11>/Output'
   */
  if (test_P.RepeatingSequenceStair_OutValue[test_DW.Output_DSTATE_g] >
      test_P.Saturation2_UpperSat) {
    tmp = test_P.Saturation2_UpperSat;
  } else if (test_P.RepeatingSequenceStair_OutValue[test_DW.Output_DSTATE_g] <
             test_P.Saturation2_LowerSat) {
    tmp = test_P.Saturation2_LowerSat;
  } else {
    tmp = test_P.RepeatingSequenceStair_OutValue[test_DW.Output_DSTATE_g];
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
   *  Bias: '<S1>/Bias2'
   *  Saturate: '<S1>/Saturation2'
   */
  tmp += test_P.Bias2_Bias;
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      rtb_FixPtSum1 = (uint8_T)tmp;
    } else {
      rtb_FixPtSum1 = 0U;
    }
  } else {
    rtb_FixPtSum1 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S7>/Data Type Conversion' */

  /* S-Function (arduinoservowrite_sfcn): '<S7>/Servo Write' */
  MW_servoWrite(test_P.ServoWrite_p1_a, rtb_FixPtSum1);

  /* Sum: '<S12>/FixPt Sum1' incorporates:
   *  Constant: '<S12>/FixPt Constant'
   *  UnitDelay: '<S11>/Output'
   */
  rtb_FixPtSum1 = (uint8_T)((uint16_T)test_DW.Output_DSTATE_g +
    test_P.FixPtConstant_Value);

  /* Switch: '<S13>/FixPt Switch' incorporates:
   *  Constant: '<S13>/Constant'
   */
  if (rtb_FixPtSum1 > test_P.LimitedCounter_uplimit) {
    test_B.FixPtSwitch = test_P.Constant_Value;
  } else {
    test_B.FixPtSwitch = rtb_FixPtSum1;
  }

  /* End of Switch: '<S13>/FixPt Switch' */
}

/* Model update function for TID1 */
void test_update1(void)                /* Sample time: [1.0s, 0.0s] */
{
  /* Update for UnitDelay: '<S11>/Output' */
  test_DW.Output_DSTATE_g = test_B.FixPtSwitch;
}

/* Model output function for TID2 */
void test_output2(void)                /* Sample time: [7.0s, 0.0s] */
{
  uint8_T rtb_FixPtSum1;
  real_T tmp;

  /* Saturate: '<S1>/Saturation1' incorporates:
   *  Constant: '<S3>/Vector'
   *  MultiPortSwitch: '<S3>/Output'
   *  UnitDelay: '<S14>/Output'
   */
  if (test_P.RepeatingSequenceStair1_OutValu[test_DW.Output_DSTATE] >
      test_P.Saturation1_UpperSat) {
    tmp = test_P.Saturation1_UpperSat;
  } else if (test_P.RepeatingSequenceStair1_OutValu[test_DW.Output_DSTATE] <
             test_P.Saturation1_LowerSat) {
    tmp = test_P.Saturation1_LowerSat;
  } else {
    tmp = test_P.RepeatingSequenceStair1_OutValu[test_DW.Output_DSTATE];
  }

  /* DataTypeConversion: '<S6>/Data Type Conversion' incorporates:
   *  Bias: '<S1>/Bias1'
   *  Saturate: '<S1>/Saturation1'
   *  UnaryMinus: '<S1>/Unary Minus1'
   */
  tmp = -tmp + test_P.Bias1_Bias;
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      rtb_FixPtSum1 = (uint8_T)tmp;
    } else {
      rtb_FixPtSum1 = 0U;
    }
  } else {
    rtb_FixPtSum1 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S6>/Data Type Conversion' */

  /* S-Function (arduinoservowrite_sfcn): '<S6>/Servo Write' */
  MW_servoWrite(test_P.ServoWrite_p1_g, rtb_FixPtSum1);

  /* Sum: '<S15>/FixPt Sum1' incorporates:
   *  Constant: '<S15>/FixPt Constant'
   *  UnitDelay: '<S14>/Output'
   */
  rtb_FixPtSum1 = (uint8_T)((uint16_T)test_DW.Output_DSTATE +
    test_P.FixPtConstant_Value_d);

  /* Switch: '<S16>/FixPt Switch' incorporates:
   *  Constant: '<S16>/Constant'
   */
  if (rtb_FixPtSum1 > test_P.LimitedCounter_uplimit_h) {
    test_B.FixPtSwitch_d = test_P.Constant_Value_c;
  } else {
    test_B.FixPtSwitch_d = rtb_FixPtSum1;
  }

  /* End of Switch: '<S16>/FixPt Switch' */
}

/* Model update function for TID2 */
void test_update2(void)                /* Sample time: [7.0s, 0.0s] */
{
  /* Update for UnitDelay: '<S14>/Output' */
  test_DW.Output_DSTATE = test_B.FixPtSwitch_d;
}

/* Model initialize function */
void test_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)test_M, 0,
                sizeof(RT_MODEL_test_T));

  /* block I/O */
  (void) memset(((void *) &test_B), 0,
                sizeof(B_test_T));

  /* states (dwork) */
  (void) memset((void *)&test_DW, 0,
                sizeof(DW_test_T));

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  test_DW.clockTickCounter = 0L;

  /* Start for S-Function (arduinoservowrite_sfcn): '<S4>/Servo Write' */
  MW_servoAttach(test_P.ServoWrite_p1, test_P.ServoWrite_pinNumber);

  /* Start for S-Function (arduinoservowrite_sfcn): '<S6>/Servo Write' */
  MW_servoAttach(test_P.ServoWrite_p1_g, test_P.ServoWrite_pinNumber_k);

  /* Start for S-Function (arduinoservowrite_sfcn): '<S7>/Servo Write' */
  MW_servoAttach(test_P.ServoWrite_p1_a, test_P.ServoWrite_pinNumber_l);

  /* InitializeConditions for UnitDelay: '<S14>/Output' */
  test_DW.Output_DSTATE = test_P.Output_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S11>/Output' */
  test_DW.Output_DSTATE_g = test_P.Output_InitialCondition_f;
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
