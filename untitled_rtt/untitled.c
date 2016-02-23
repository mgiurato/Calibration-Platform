/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 8.8.1 (R2015aSP1) 04-Sep-2015
 * TLC version                    : 8.8 (Sep  6 2015)
 * C/C++ source code generated on : Wed Feb 17 12:25:15 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "untitled_private.h"

/* Block signals (auto storage) */
B_untitled_T untitled_B;

/* Real-time model */
RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/* Model output function */
void untitled_output(void)
{
  real_T tmp;

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Sin: '<Root>/Sine Wave'
   */
  tmp = sin(untitled_P.SineWave_Freq * untitled_M->Timing.t[0] +
            untitled_P.SineWave_Phase) * untitled_P.SineWave_Amp +
    untitled_P.SineWave_Bias;
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      untitled_B.DataTypeConversion = (uint8_T)tmp;
    } else {
      untitled_B.DataTypeConversion = 0U;
    }
  } else {
    untitled_B.DataTypeConversion = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* S-Function (arduinoservowrite_sfcn): '<S1>/Servo Write' */
  MW_servoWrite(untitled_P.ServoWrite_p1, untitled_B.DataTypeConversion);
}

/* Model update function */
void untitled_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  untitled_M->Timing.t[0] =
    (++untitled_M->Timing.clockTick0) * untitled_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.2s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.2, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    untitled_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)untitled_M, 0,
                sizeof(RT_MODEL_untitled_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&untitled_M->solverInfo,
                          &untitled_M->Timing.simTimeStep);
    rtsiSetTPtr(&untitled_M->solverInfo, &rtmGetTPtr(untitled_M));
    rtsiSetStepSizePtr(&untitled_M->solverInfo, &untitled_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&untitled_M->solverInfo, ((const char_T **)
      (&rtmGetErrorStatus(untitled_M))));
    rtsiSetRTModelPtr(&untitled_M->solverInfo, untitled_M);
  }

  rtsiSetSimTimeStep(&untitled_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&untitled_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(untitled_M, &untitled_M->Timing.tArray[0]);
  untitled_M->Timing.stepSize0 = 0.2;

  /* block I/O */
  (void) memset(((void *) &untitled_B), 0,
                sizeof(B_untitled_T));

  /* Start for S-Function (arduinoservowrite_sfcn): '<S1>/Servo Write' */
  MW_servoAttach(untitled_P.ServoWrite_p1, untitled_P.ServoWrite_pinNumber);
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
