/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test.c
 *
 * Code generated for Simulink model 'test'.
 *
 * Model version                  : 1.46
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 19 2015)
 * C/C++ source code generated on : Tue Sep  8 14:56:21 2015
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

/* Model output function */
void test_output(void)
{
  real_T tmp;
  uint8_T tmp_0;

  /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
   *  Bias: '<S1>/Bias'
   *  Constant: '<Root>/Constant'
   */
  tmp = test_P.Constant_Value + test_P.Bias_Bias;
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S7>/Data Type Conversion' */

  /* S-Function (arduinoservowrite_sfcn): '<S7>/Servo Write' */
  MW_servoWrite(test_P.ServoWrite_p1, tmp_0);

  /* DataTypeConversion: '<S8>/Data Type Conversion' incorporates:
   *  Bias: '<S1>/Bias1'
   *  Constant: '<Root>/Constant1'
   */
  tmp = test_P.Constant1_Value + test_P.Bias1_Bias;
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S8>/Data Type Conversion' */

  /* S-Function (arduinoservowrite_sfcn): '<S8>/Servo Write' */
  MW_servoWrite(test_P.ServoWrite_p1_g, tmp_0);

  /* DataTypeConversion: '<S9>/Data Type Conversion' incorporates:
   *  Bias: '<S1>/Bias2'
   *  Constant: '<Root>/Constant2'
   */
  tmp = test_P.Constant2_Value + test_P.Bias2_Bias;
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S9>/Data Type Conversion' */

  /* S-Function (arduinoservowrite_sfcn): '<S9>/Servo Write' */
  MW_servoWrite(test_P.ServoWrite_p1_a, tmp_0);
}

/* Model update function */
void test_update(void)
{
  /* (no update code required) */
}

/* Model initialize function */
void test_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(test_M, (NULL));

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
