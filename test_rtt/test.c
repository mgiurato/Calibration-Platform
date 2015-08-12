/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test.c
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
  real_T u0;
  int8_T tmp;
  uint8_T tmp_0;

  {                                    /* Sample time: [0.01s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Gain: '<S1>/Gain' incorporates:
   *  Constant: '<Root>/Constant'
   */
  u0 = test_P.Gain_Gain * test_P.Constant_Value;

  /* Saturate: '<S1>/Saturation' */
  if (u0 > test_P.Saturation_UpperSat) {
    u0 = test_P.Saturation_UpperSat;
  } else {
    if (u0 < test_P.Saturation_LowerSat) {
      u0 = test_P.Saturation_LowerSat;
    }
  }

  /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
   *  Bias: '<S1>/Bias'
   *  Saturate: '<S1>/Saturation'
   *  UnaryMinus: '<S1>/Unary Minus'
   */
  u0 = floor(-u0 + test_P.Bias_Bias);
  if (u0 < 128.0) {
    if (u0 >= -128.0) {
      tmp = (int8_T)u0;
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

  /* Saturate: '<S1>/Saturation1' incorporates:
   *  Constant: '<Root>/Constant'
   */
  if (test_P.Constant_Value > test_P.Saturation1_UpperSat) {
    u0 = test_P.Saturation1_UpperSat;
  } else if (test_P.Constant_Value < test_P.Saturation1_LowerSat) {
    u0 = test_P.Saturation1_LowerSat;
  } else {
    u0 = test_P.Constant_Value;
  }

  /* DataTypeConversion: '<S6>/Data Type Conversion' incorporates:
   *  Bias: '<S1>/Bias1'
   *  Saturate: '<S1>/Saturation1'
   *  UnaryMinus: '<S1>/Unary Minus1'
   */
  u0 = -u0 + test_P.Bias1_Bias;
  if (u0 < 256.0) {
    if (u0 >= 0.0) {
      tmp_0 = (uint8_T)u0;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S6>/Data Type Conversion' */

  /* S-Function (arduinoservowrite_sfcn): '<S6>/Servo Write' */
  MW_servoWrite(test_P.ServoWrite_p1_g, tmp_0);

  /* Saturate: '<S1>/Saturation2' incorporates:
   *  Constant: '<Root>/Constant'
   */
  if (test_P.Constant_Value > test_P.Saturation2_UpperSat) {
    u0 = test_P.Saturation2_UpperSat;
  } else if (test_P.Constant_Value < test_P.Saturation2_LowerSat) {
    u0 = test_P.Saturation2_LowerSat;
  } else {
    u0 = test_P.Constant_Value;
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
   *  Bias: '<S1>/Bias2'
   *  Saturate: '<S1>/Saturation2'
   */
  u0 += test_P.Bias2_Bias;
  if (u0 < 256.0) {
    if (u0 >= 0.0) {
      tmp_0 = (uint8_T)u0;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S7>/Data Type Conversion' */

  /* S-Function (arduinoservowrite_sfcn): '<S7>/Servo Write' */
  MW_servoWrite(test_P.ServoWrite_p1_a, tmp_0);
}

/* Model update function for TID0 */
void test_update0(void)                /* Sample time: [0.01s, 0.0s] */
{
  /* (no update code required) */
}

/* Model output function for TID1 */
void test_output1(void)                /* Sample time: [1.0s, 0.0s] */
{
  /* (no output code required) */
}

/* Model update function for TID1 */
void test_update1(void)                /* Sample time: [1.0s, 0.0s] */
{
  /* (no update code required) */
}

/* Model output function for TID2 */
void test_output2(void)                /* Sample time: [7.0s, 0.0s] */
{
  /* (no output code required) */
}

/* Model update function for TID2 */
void test_update2(void)                /* Sample time: [7.0s, 0.0s] */
{
  /* (no update code required) */
}

/* Model initialize function */
void test_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)test_M, 0,
                sizeof(RT_MODEL_test_T));

  /* Start for S-Function (arduinoservowrite_sfcn): '<S4>/Servo Write' */
  MW_servoAttach(test_P.ServoWrite_p1, test_P.ServoWrite_pinNumber);

  /* Start for S-Function (arduinoservowrite_sfcn): '<S6>/Servo Write' */
  MW_servoAttach(test_P.ServoWrite_p1_g, test_P.ServoWrite_pinNumber_k);

  /* Start for S-Function (arduinoservowrite_sfcn): '<S7>/Servo Write' */
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
