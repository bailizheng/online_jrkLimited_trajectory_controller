/*
 * six_dof_vel_controller.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "six_dof_vel_controller".
 *
 * Model version              : 1.14
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C++ source code generated on : Fri May 17 15:21:32 2019
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "six_dof_vel_controller_capi.h"
#include "six_dof_vel_controller.h"
#include "six_dof_vel_controller_private.h"

/* Block signals (default storage) */
B_six_dof_vel_controller_T six_dof_vel_controller_B;

/* Continuous states */
X_six_dof_vel_controller_T six_dof_vel_controller_X;

/* Block states (default storage) */
DW_six_dof_vel_controller_T six_dof_vel_controller_DW;

/* External inputs (root inport signals with default storage) */
ExtU_six_dof_vel_controller_T six_dof_vel_controller_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_six_dof_vel_controller_T six_dof_vel_controller_Y;

/* Real-time model */
RT_MODEL_six_dof_vel_controll_T six_dof_vel_controller_M_;
RT_MODEL_six_dof_vel_controll_T *const six_dof_vel_controller_M =
  &six_dof_vel_controller_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 18;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  six_dof_vel_controller_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  six_dof_vel_controller_step();
  six_dof_vel_controller_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  six_dof_vel_controller_step();
  six_dof_vel_controller_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void six_dof_vel_controller_step(void)
{
  real_T u0;
  if (rtmIsMajorTimeStep(six_dof_vel_controller_M)) {
    /* set solver stop time */
    if (!(six_dof_vel_controller_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&six_dof_vel_controller_M->solverInfo,
                            ((six_dof_vel_controller_M->Timing.clockTickH0 + 1) *
        six_dof_vel_controller_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&six_dof_vel_controller_M->solverInfo,
                            ((six_dof_vel_controller_M->Timing.clockTick0 + 1) *
        six_dof_vel_controller_M->Timing.stepSize0 +
        six_dof_vel_controller_M->Timing.clockTickH0 *
        six_dof_vel_controller_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(six_dof_vel_controller_M)) {
    six_dof_vel_controller_M->Timing.t[0] = rtsiGetT
      (&six_dof_vel_controller_M->solverInfo);
  }

  /* Saturate: '<S2>/Saturation2' incorporates:
   *  Integrator: '<S2>/Integrator1'
   */
  if (six_dof_vel_controller_X.Integrator1_CSTATE > six_dof_vel_controller_P.sm
      [0]) {
    /* Outport: '<Root>/POS' */
    six_dof_vel_controller_Y.POS[0] = six_dof_vel_controller_P.sm[0];
  } else if (six_dof_vel_controller_X.Integrator1_CSTATE <
             -six_dof_vel_controller_P.sm[0]) {
    /* Outport: '<Root>/POS' */
    six_dof_vel_controller_Y.POS[0] = -six_dof_vel_controller_P.sm[0];
  } else {
    /* Outport: '<Root>/POS' */
    six_dof_vel_controller_Y.POS[0] =
      six_dof_vel_controller_X.Integrator1_CSTATE;
  }

  /* End of Saturate: '<S2>/Saturation2' */

  /* Saturate: '<S3>/Saturation6' incorporates:
   *  Integrator: '<S3>/Integrator3'
   */
  if (six_dof_vel_controller_X.Integrator3_CSTATE > six_dof_vel_controller_P.sm
      [1]) {
    /* Outport: '<Root>/POS' */
    six_dof_vel_controller_Y.POS[1] = six_dof_vel_controller_P.sm[1];
  } else if (six_dof_vel_controller_X.Integrator3_CSTATE <
             -six_dof_vel_controller_P.sm[1]) {
    /* Outport: '<Root>/POS' */
    six_dof_vel_controller_Y.POS[1] = -six_dof_vel_controller_P.sm[1];
  } else {
    /* Outport: '<Root>/POS' */
    six_dof_vel_controller_Y.POS[1] =
      six_dof_vel_controller_X.Integrator3_CSTATE;
  }

  /* End of Saturate: '<S3>/Saturation6' */

  /* Saturate: '<S1>/Saturation6' incorporates:
   *  Integrator: '<S1>/Integrator3'
   */
  if (six_dof_vel_controller_X.Integrator3_CSTATE_p >
      six_dof_vel_controller_P.sm[2]) {
    /* Outport: '<Root>/POS' */
    six_dof_vel_controller_Y.POS[2] = six_dof_vel_controller_P.sm[2];
  } else if (six_dof_vel_controller_X.Integrator3_CSTATE_p <
             -six_dof_vel_controller_P.sm[2]) {
    /* Outport: '<Root>/POS' */
    six_dof_vel_controller_Y.POS[2] = -six_dof_vel_controller_P.sm[2];
  } else {
    /* Outport: '<Root>/POS' */
    six_dof_vel_controller_Y.POS[2] =
      six_dof_vel_controller_X.Integrator3_CSTATE_p;
  }

  /* End of Saturate: '<S1>/Saturation6' */

  /* Saturate: '<S4>/Saturation6' incorporates:
   *  Integrator: '<S4>/Integrator3'
   */
  if (six_dof_vel_controller_X.Integrator3_CSTATE_j >
      six_dof_vel_controller_P.sm[3]) {
    /* Outport: '<Root>/POS' */
    six_dof_vel_controller_Y.POS[3] = six_dof_vel_controller_P.sm[3];
  } else if (six_dof_vel_controller_X.Integrator3_CSTATE_j <
             -six_dof_vel_controller_P.sm[3]) {
    /* Outport: '<Root>/POS' */
    six_dof_vel_controller_Y.POS[3] = -six_dof_vel_controller_P.sm[3];
  } else {
    /* Outport: '<Root>/POS' */
    six_dof_vel_controller_Y.POS[3] =
      six_dof_vel_controller_X.Integrator3_CSTATE_j;
  }

  /* End of Saturate: '<S4>/Saturation6' */

  /* Saturate: '<S5>/Saturation6' incorporates:
   *  Integrator: '<S5>/Integrator3'
   */
  if (six_dof_vel_controller_X.Integrator3_CSTATE_d >
      six_dof_vel_controller_P.sm[4]) {
    /* Outport: '<Root>/POS' */
    six_dof_vel_controller_Y.POS[4] = six_dof_vel_controller_P.sm[4];
  } else if (six_dof_vel_controller_X.Integrator3_CSTATE_d <
             -six_dof_vel_controller_P.sm[4]) {
    /* Outport: '<Root>/POS' */
    six_dof_vel_controller_Y.POS[4] = -six_dof_vel_controller_P.sm[4];
  } else {
    /* Outport: '<Root>/POS' */
    six_dof_vel_controller_Y.POS[4] =
      six_dof_vel_controller_X.Integrator3_CSTATE_d;
  }

  /* End of Saturate: '<S5>/Saturation6' */

  /* Saturate: '<S6>/Saturation6' incorporates:
   *  Integrator: '<S6>/Integrator3'
   */
  if (six_dof_vel_controller_X.Integrator3_CSTATE_m >
      six_dof_vel_controller_P.sm[5]) {
    /* Outport: '<Root>/POS' */
    six_dof_vel_controller_Y.POS[5] = six_dof_vel_controller_P.sm[5];
  } else if (six_dof_vel_controller_X.Integrator3_CSTATE_m <
             -six_dof_vel_controller_P.sm[5]) {
    /* Outport: '<Root>/POS' */
    six_dof_vel_controller_Y.POS[5] = -six_dof_vel_controller_P.sm[5];
  } else {
    /* Outport: '<Root>/POS' */
    six_dof_vel_controller_Y.POS[5] =
      six_dof_vel_controller_X.Integrator3_CSTATE_m;
  }

  /* End of Saturate: '<S6>/Saturation6' */

  /* Saturate: '<S2>/Saturation1' incorporates:
   *  Integrator: '<S2>/Integrator'
   */
  if (six_dof_vel_controller_X.Integrator_CSTATE > six_dof_vel_controller_P.vm[1])
  {
    six_dof_vel_controller_B.vel = six_dof_vel_controller_P.vm[1];
  } else if (six_dof_vel_controller_X.Integrator_CSTATE <
             -six_dof_vel_controller_P.vm[1]) {
    six_dof_vel_controller_B.vel = -six_dof_vel_controller_P.vm[1];
  } else {
    six_dof_vel_controller_B.vel = six_dof_vel_controller_X.Integrator_CSTATE;
  }

  /* End of Saturate: '<S2>/Saturation1' */

  /* Saturate: '<S3>/Saturation5' incorporates:
   *  Integrator: '<S3>/Integrator2'
   */
  if (six_dof_vel_controller_X.Integrator2_CSTATE > six_dof_vel_controller_P.vm
      [1]) {
    six_dof_vel_controller_B.vel_j = six_dof_vel_controller_P.vm[1];
  } else if (six_dof_vel_controller_X.Integrator2_CSTATE <
             -six_dof_vel_controller_P.vm[1]) {
    six_dof_vel_controller_B.vel_j = -six_dof_vel_controller_P.vm[1];
  } else {
    six_dof_vel_controller_B.vel_j = six_dof_vel_controller_X.Integrator2_CSTATE;
  }

  /* End of Saturate: '<S3>/Saturation5' */

  /* Saturate: '<S1>/Saturation5' incorporates:
   *  Integrator: '<S1>/Integrator2'
   */
  if (six_dof_vel_controller_X.Integrator2_CSTATE_f >
      six_dof_vel_controller_P.vm[2]) {
    six_dof_vel_controller_B.vel_c = six_dof_vel_controller_P.vm[2];
  } else if (six_dof_vel_controller_X.Integrator2_CSTATE_f <
             -six_dof_vel_controller_P.vm[2]) {
    six_dof_vel_controller_B.vel_c = -six_dof_vel_controller_P.vm[2];
  } else {
    six_dof_vel_controller_B.vel_c =
      six_dof_vel_controller_X.Integrator2_CSTATE_f;
  }

  /* End of Saturate: '<S1>/Saturation5' */

  /* Saturate: '<S4>/Saturation5' incorporates:
   *  Integrator: '<S4>/Integrator2'
   */
  if (six_dof_vel_controller_X.Integrator2_CSTATE_i >
      six_dof_vel_controller_P.vm[3]) {
    six_dof_vel_controller_B.vel_p = six_dof_vel_controller_P.vm[3];
  } else if (six_dof_vel_controller_X.Integrator2_CSTATE_i <
             -six_dof_vel_controller_P.vm[3]) {
    six_dof_vel_controller_B.vel_p = -six_dof_vel_controller_P.vm[3];
  } else {
    six_dof_vel_controller_B.vel_p =
      six_dof_vel_controller_X.Integrator2_CSTATE_i;
  }

  /* End of Saturate: '<S4>/Saturation5' */

  /* Saturate: '<S5>/Saturation5' incorporates:
   *  Integrator: '<S5>/Integrator2'
   */
  if (six_dof_vel_controller_X.Integrator2_CSTATE_ic >
      six_dof_vel_controller_P.vm[4]) {
    six_dof_vel_controller_B.vel_b = six_dof_vel_controller_P.vm[4];
  } else if (six_dof_vel_controller_X.Integrator2_CSTATE_ic <
             -six_dof_vel_controller_P.vm[4]) {
    six_dof_vel_controller_B.vel_b = -six_dof_vel_controller_P.vm[4];
  } else {
    six_dof_vel_controller_B.vel_b =
      six_dof_vel_controller_X.Integrator2_CSTATE_ic;
  }

  /* End of Saturate: '<S5>/Saturation5' */

  /* Saturate: '<S6>/Saturation5' incorporates:
   *  Integrator: '<S6>/Integrator2'
   */
  if (six_dof_vel_controller_X.Integrator2_CSTATE_g >
      six_dof_vel_controller_P.vm[5]) {
    six_dof_vel_controller_B.vel_g = six_dof_vel_controller_P.vm[5];
  } else if (six_dof_vel_controller_X.Integrator2_CSTATE_g <
             -six_dof_vel_controller_P.vm[5]) {
    six_dof_vel_controller_B.vel_g = -six_dof_vel_controller_P.vm[5];
  } else {
    six_dof_vel_controller_B.vel_g =
      six_dof_vel_controller_X.Integrator2_CSTATE_g;
  }

  /* End of Saturate: '<S6>/Saturation5' */

  /* Outport: '<Root>/VEL' */
  six_dof_vel_controller_Y.VEL[0] = six_dof_vel_controller_B.vel;
  six_dof_vel_controller_Y.VEL[1] = six_dof_vel_controller_B.vel_j;
  six_dof_vel_controller_Y.VEL[2] = six_dof_vel_controller_B.vel_c;
  six_dof_vel_controller_Y.VEL[3] = six_dof_vel_controller_B.vel_p;
  six_dof_vel_controller_Y.VEL[4] = six_dof_vel_controller_B.vel_b;
  six_dof_vel_controller_Y.VEL[5] = six_dof_vel_controller_B.vel_g;

  /* Saturate: '<S2>/Saturation' incorporates:
   *  Integrator: '<S2>/Integrator4'
   */
  if (six_dof_vel_controller_X.Integrator4_CSTATE > six_dof_vel_controller_P.am
      [0]) {
    six_dof_vel_controller_B.acc = six_dof_vel_controller_P.am[0];
  } else if (six_dof_vel_controller_X.Integrator4_CSTATE <
             -six_dof_vel_controller_P.am[0]) {
    six_dof_vel_controller_B.acc = -six_dof_vel_controller_P.am[0];
  } else {
    six_dof_vel_controller_B.acc = six_dof_vel_controller_X.Integrator4_CSTATE;
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* Saturate: '<S3>/Saturation4' incorporates:
   *  Integrator: '<S3>/Integrator5'
   */
  if (six_dof_vel_controller_X.Integrator5_CSTATE > six_dof_vel_controller_P.am
      [1]) {
    six_dof_vel_controller_B.acc_f = six_dof_vel_controller_P.am[1];
  } else if (six_dof_vel_controller_X.Integrator5_CSTATE <
             -six_dof_vel_controller_P.am[1]) {
    six_dof_vel_controller_B.acc_f = -six_dof_vel_controller_P.am[1];
  } else {
    six_dof_vel_controller_B.acc_f = six_dof_vel_controller_X.Integrator5_CSTATE;
  }

  /* End of Saturate: '<S3>/Saturation4' */

  /* Saturate: '<S1>/Saturation4' incorporates:
   *  Integrator: '<S1>/Integrator5'
   */
  if (six_dof_vel_controller_X.Integrator5_CSTATE_a >
      six_dof_vel_controller_P.am[2]) {
    six_dof_vel_controller_B.acc_b = six_dof_vel_controller_P.am[2];
  } else if (six_dof_vel_controller_X.Integrator5_CSTATE_a <
             -six_dof_vel_controller_P.am[2]) {
    six_dof_vel_controller_B.acc_b = -six_dof_vel_controller_P.am[2];
  } else {
    six_dof_vel_controller_B.acc_b =
      six_dof_vel_controller_X.Integrator5_CSTATE_a;
  }

  /* End of Saturate: '<S1>/Saturation4' */

  /* Saturate: '<S4>/Saturation4' incorporates:
   *  Integrator: '<S4>/Integrator5'
   */
  if (six_dof_vel_controller_X.Integrator5_CSTATE_n >
      six_dof_vel_controller_P.am[3]) {
    six_dof_vel_controller_B.acc_m = six_dof_vel_controller_P.am[3];
  } else if (six_dof_vel_controller_X.Integrator5_CSTATE_n <
             -six_dof_vel_controller_P.am[3]) {
    six_dof_vel_controller_B.acc_m = -six_dof_vel_controller_P.am[3];
  } else {
    six_dof_vel_controller_B.acc_m =
      six_dof_vel_controller_X.Integrator5_CSTATE_n;
  }

  /* End of Saturate: '<S4>/Saturation4' */

  /* Saturate: '<S5>/Saturation4' incorporates:
   *  Integrator: '<S5>/Integrator5'
   */
  if (six_dof_vel_controller_X.Integrator5_CSTATE_ay >
      six_dof_vel_controller_P.am[4]) {
    six_dof_vel_controller_B.acc_e = six_dof_vel_controller_P.am[4];
  } else if (six_dof_vel_controller_X.Integrator5_CSTATE_ay <
             -six_dof_vel_controller_P.am[4]) {
    six_dof_vel_controller_B.acc_e = -six_dof_vel_controller_P.am[4];
  } else {
    six_dof_vel_controller_B.acc_e =
      six_dof_vel_controller_X.Integrator5_CSTATE_ay;
  }

  /* End of Saturate: '<S5>/Saturation4' */

  /* Saturate: '<S6>/Saturation4' incorporates:
   *  Integrator: '<S6>/Integrator5'
   */
  if (six_dof_vel_controller_X.Integrator5_CSTATE_d >
      six_dof_vel_controller_P.am[5]) {
    six_dof_vel_controller_B.acc_mv = six_dof_vel_controller_P.am[5];
  } else if (six_dof_vel_controller_X.Integrator5_CSTATE_d <
             -six_dof_vel_controller_P.am[5]) {
    six_dof_vel_controller_B.acc_mv = -six_dof_vel_controller_P.am[5];
  } else {
    six_dof_vel_controller_B.acc_mv =
      six_dof_vel_controller_X.Integrator5_CSTATE_d;
  }

  /* End of Saturate: '<S6>/Saturation4' */

  /* Outport: '<Root>/ACC' */
  six_dof_vel_controller_Y.ACC[0] = six_dof_vel_controller_B.acc;
  six_dof_vel_controller_Y.ACC[1] = six_dof_vel_controller_B.acc_f;
  six_dof_vel_controller_Y.ACC[2] = six_dof_vel_controller_B.acc_b;
  six_dof_vel_controller_Y.ACC[3] = six_dof_vel_controller_B.acc_m;
  six_dof_vel_controller_Y.ACC[4] = six_dof_vel_controller_B.acc_e;
  six_dof_vel_controller_Y.ACC[5] = six_dof_vel_controller_B.acc_mv;
  if (rtmIsMajorTimeStep(six_dof_vel_controller_M)) {
    /* Sum: '<S2>/Sum3' incorporates:
     *  Delay: '<S2>/Delay1'
     *  Delay: '<S2>/Delay2'
     *  Gain: '<S2>/Gain1'
     *  Gain: '<S2>/Gain2'
     *  Inport: '<Root>/acc'
     *  Inport: '<Root>/vel'
     *  Sum: '<S2>/Sum1'
     *  Sum: '<S2>/Sum2'
     */
    u0 = (six_dof_vel_controller_U.vel[0] -
          six_dof_vel_controller_DW.Delay2_DSTATE) *
      six_dof_vel_controller_P.kv[0] + (six_dof_vel_controller_U.acc[0] -
      six_dof_vel_controller_DW.Delay1_DSTATE) * six_dof_vel_controller_P.ka[0];

    /* Saturate: '<S2>/Saturation8' */
    if (u0 > six_dof_vel_controller_P.jm[0]) {
      u0 = six_dof_vel_controller_P.jm[0];
    } else {
      if (u0 < -six_dof_vel_controller_P.jm[0]) {
        u0 = -six_dof_vel_controller_P.jm[0];
      }
    }

    /* End of Saturate: '<S2>/Saturation8' */

    /* Saturate: '<S2>/Saturation3' */
    if (u0 > six_dof_vel_controller_P.jm[0]) {
      six_dof_vel_controller_B.Saturation3 = six_dof_vel_controller_P.jm[0];
    } else if (u0 < -six_dof_vel_controller_P.jm[0]) {
      six_dof_vel_controller_B.Saturation3 = -six_dof_vel_controller_P.jm[0];
    } else {
      six_dof_vel_controller_B.Saturation3 = u0;
    }

    /* End of Saturate: '<S2>/Saturation3' */

    /* Sum: '<S3>/Sum7' incorporates:
     *  Delay: '<S3>/Delay4'
     *  Delay: '<S3>/Delay5'
     *  Gain: '<S3>/Gain4'
     *  Gain: '<S3>/Gain5'
     *  Inport: '<Root>/acc'
     *  Inport: '<Root>/vel'
     *  Sum: '<S3>/Sum5'
     *  Sum: '<S3>/Sum6'
     */
    u0 = (six_dof_vel_controller_U.vel[1] -
          six_dof_vel_controller_DW.Delay5_DSTATE) *
      six_dof_vel_controller_P.kv[1] + (six_dof_vel_controller_U.acc[1] -
      six_dof_vel_controller_DW.Delay4_DSTATE) * six_dof_vel_controller_P.ka[1];

    /* Saturate: '<S3>/Saturation9' */
    if (u0 > six_dof_vel_controller_P.jm[1]) {
      u0 = six_dof_vel_controller_P.jm[1];
    } else {
      if (u0 < -six_dof_vel_controller_P.jm[1]) {
        u0 = -six_dof_vel_controller_P.jm[1];
      }
    }

    /* End of Saturate: '<S3>/Saturation9' */

    /* Saturate: '<S3>/Saturation7' */
    if (u0 > six_dof_vel_controller_P.jm[1]) {
      six_dof_vel_controller_B.Saturation7 = six_dof_vel_controller_P.jm[1];
    } else if (u0 < -six_dof_vel_controller_P.jm[1]) {
      six_dof_vel_controller_B.Saturation7 = -six_dof_vel_controller_P.jm[1];
    } else {
      six_dof_vel_controller_B.Saturation7 = u0;
    }

    /* End of Saturate: '<S3>/Saturation7' */

    /* Sum: '<S1>/Sum7' incorporates:
     *  Delay: '<S1>/Delay4'
     *  Delay: '<S1>/Delay5'
     *  Gain: '<S1>/Gain4'
     *  Gain: '<S1>/Gain5'
     *  Inport: '<Root>/acc'
     *  Inport: '<Root>/vel'
     *  Sum: '<S1>/Sum5'
     *  Sum: '<S1>/Sum6'
     */
    u0 = (six_dof_vel_controller_U.vel[2] -
          six_dof_vel_controller_DW.Delay5_DSTATE_a) *
      six_dof_vel_controller_P.kv[2] + (six_dof_vel_controller_U.acc[2] -
      six_dof_vel_controller_DW.Delay4_DSTATE_j) * six_dof_vel_controller_P.ka[2];

    /* Saturate: '<S1>/Saturation9' */
    if (u0 > six_dof_vel_controller_P.jm[2]) {
      u0 = six_dof_vel_controller_P.jm[2];
    } else {
      if (u0 < -six_dof_vel_controller_P.jm[2]) {
        u0 = -six_dof_vel_controller_P.jm[2];
      }
    }

    /* End of Saturate: '<S1>/Saturation9' */

    /* Saturate: '<S1>/Saturation7' */
    if (u0 > six_dof_vel_controller_P.jm[2]) {
      six_dof_vel_controller_B.Saturation7_f = six_dof_vel_controller_P.jm[2];
    } else if (u0 < -six_dof_vel_controller_P.jm[2]) {
      six_dof_vel_controller_B.Saturation7_f = -six_dof_vel_controller_P.jm[2];
    } else {
      six_dof_vel_controller_B.Saturation7_f = u0;
    }

    /* End of Saturate: '<S1>/Saturation7' */

    /* Sum: '<S4>/Sum7' incorporates:
     *  Delay: '<S4>/Delay4'
     *  Delay: '<S4>/Delay5'
     *  Gain: '<S4>/Gain4'
     *  Gain: '<S4>/Gain5'
     *  Inport: '<Root>/acc'
     *  Inport: '<Root>/vel'
     *  Sum: '<S4>/Sum5'
     *  Sum: '<S4>/Sum6'
     */
    u0 = (six_dof_vel_controller_U.vel[3] -
          six_dof_vel_controller_DW.Delay5_DSTATE_c) *
      six_dof_vel_controller_P.kv[3] + (six_dof_vel_controller_U.acc[3] -
      six_dof_vel_controller_DW.Delay4_DSTATE_o) * six_dof_vel_controller_P.ka[3];

    /* Saturate: '<S4>/Saturation9' */
    if (u0 > six_dof_vel_controller_P.jm[3]) {
      u0 = six_dof_vel_controller_P.jm[3];
    } else {
      if (u0 < -six_dof_vel_controller_P.jm[3]) {
        u0 = -six_dof_vel_controller_P.jm[3];
      }
    }

    /* End of Saturate: '<S4>/Saturation9' */

    /* Saturate: '<S4>/Saturation7' */
    if (u0 > six_dof_vel_controller_P.jm[3]) {
      six_dof_vel_controller_B.Saturation7_fl = six_dof_vel_controller_P.jm[3];
    } else if (u0 < -six_dof_vel_controller_P.jm[3]) {
      six_dof_vel_controller_B.Saturation7_fl = -six_dof_vel_controller_P.jm[3];
    } else {
      six_dof_vel_controller_B.Saturation7_fl = u0;
    }

    /* End of Saturate: '<S4>/Saturation7' */

    /* Sum: '<S5>/Sum7' incorporates:
     *  Delay: '<S5>/Delay4'
     *  Delay: '<S5>/Delay5'
     *  Gain: '<S5>/Gain4'
     *  Gain: '<S5>/Gain5'
     *  Inport: '<Root>/acc'
     *  Inport: '<Root>/vel'
     *  Sum: '<S5>/Sum5'
     *  Sum: '<S5>/Sum6'
     */
    u0 = (six_dof_vel_controller_U.vel[4] -
          six_dof_vel_controller_DW.Delay5_DSTATE_h) *
      six_dof_vel_controller_P.kv[4] + (six_dof_vel_controller_U.acc[4] -
      six_dof_vel_controller_DW.Delay4_DSTATE_m) * six_dof_vel_controller_P.ka[4];

    /* Saturate: '<S5>/Saturation9' */
    if (u0 > six_dof_vel_controller_P.jm[4]) {
      u0 = six_dof_vel_controller_P.jm[4];
    } else {
      if (u0 < -six_dof_vel_controller_P.jm[4]) {
        u0 = -six_dof_vel_controller_P.jm[4];
      }
    }

    /* End of Saturate: '<S5>/Saturation9' */

    /* Saturate: '<S5>/Saturation7' */
    if (u0 > six_dof_vel_controller_P.jm[4]) {
      six_dof_vel_controller_B.Saturation7_i = six_dof_vel_controller_P.jm[4];
    } else if (u0 < -six_dof_vel_controller_P.jm[4]) {
      six_dof_vel_controller_B.Saturation7_i = -six_dof_vel_controller_P.jm[4];
    } else {
      six_dof_vel_controller_B.Saturation7_i = u0;
    }

    /* End of Saturate: '<S5>/Saturation7' */

    /* Sum: '<S6>/Sum7' incorporates:
     *  Delay: '<S6>/Delay4'
     *  Delay: '<S6>/Delay5'
     *  Gain: '<S6>/Gain4'
     *  Gain: '<S6>/Gain5'
     *  Inport: '<Root>/acc'
     *  Inport: '<Root>/vel'
     *  Sum: '<S6>/Sum5'
     *  Sum: '<S6>/Sum6'
     */
    u0 = (six_dof_vel_controller_U.vel[5] -
          six_dof_vel_controller_DW.Delay5_DSTATE_b) *
      six_dof_vel_controller_P.kv[5] + (six_dof_vel_controller_U.acc[5] -
      six_dof_vel_controller_DW.Delay4_DSTATE_b) * six_dof_vel_controller_P.ka[5];

    /* Saturate: '<S6>/Saturation9' */
    if (u0 > six_dof_vel_controller_P.jm[5]) {
      u0 = six_dof_vel_controller_P.jm[5];
    } else {
      if (u0 < -six_dof_vel_controller_P.jm[5]) {
        u0 = -six_dof_vel_controller_P.jm[5];
      }
    }

    /* End of Saturate: '<S6>/Saturation9' */

    /* Saturate: '<S6>/Saturation7' */
    if (u0 > six_dof_vel_controller_P.jm[5]) {
      six_dof_vel_controller_B.Saturation7_g = six_dof_vel_controller_P.jm[5];
    } else if (u0 < -six_dof_vel_controller_P.jm[5]) {
      six_dof_vel_controller_B.Saturation7_g = -six_dof_vel_controller_P.jm[5];
    } else {
      six_dof_vel_controller_B.Saturation7_g = u0;
    }

    /* End of Saturate: '<S6>/Saturation7' */

    /* Outport: '<Root>/JRK' */
    six_dof_vel_controller_Y.JRK[0] = six_dof_vel_controller_B.Saturation3;
    six_dof_vel_controller_Y.JRK[1] = six_dof_vel_controller_B.Saturation7;
    six_dof_vel_controller_Y.JRK[2] = six_dof_vel_controller_B.Saturation7_f;
    six_dof_vel_controller_Y.JRK[3] = six_dof_vel_controller_B.Saturation7_fl;
    six_dof_vel_controller_Y.JRK[4] = six_dof_vel_controller_B.Saturation7_i;
    six_dof_vel_controller_Y.JRK[5] = six_dof_vel_controller_B.Saturation7_g;
  }

  if (rtmIsMajorTimeStep(six_dof_vel_controller_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(six_dof_vel_controller_M->rtwLogInfo,
                        (six_dof_vel_controller_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(six_dof_vel_controller_M)) {
    if (rtmIsMajorTimeStep(six_dof_vel_controller_M)) {
      /* Update for Delay: '<S2>/Delay2' */
      six_dof_vel_controller_DW.Delay2_DSTATE = six_dof_vel_controller_B.vel;

      /* Update for Delay: '<S2>/Delay1' */
      six_dof_vel_controller_DW.Delay1_DSTATE = six_dof_vel_controller_B.acc;

      /* Update for Delay: '<S3>/Delay5' */
      six_dof_vel_controller_DW.Delay5_DSTATE = six_dof_vel_controller_B.vel_j;

      /* Update for Delay: '<S3>/Delay4' */
      six_dof_vel_controller_DW.Delay4_DSTATE = six_dof_vel_controller_B.acc_f;

      /* Update for Delay: '<S1>/Delay5' */
      six_dof_vel_controller_DW.Delay5_DSTATE_a = six_dof_vel_controller_B.vel_c;

      /* Update for Delay: '<S1>/Delay4' */
      six_dof_vel_controller_DW.Delay4_DSTATE_j = six_dof_vel_controller_B.acc_b;

      /* Update for Delay: '<S4>/Delay5' */
      six_dof_vel_controller_DW.Delay5_DSTATE_c = six_dof_vel_controller_B.vel_p;

      /* Update for Delay: '<S4>/Delay4' */
      six_dof_vel_controller_DW.Delay4_DSTATE_o = six_dof_vel_controller_B.acc_m;

      /* Update for Delay: '<S5>/Delay5' */
      six_dof_vel_controller_DW.Delay5_DSTATE_h = six_dof_vel_controller_B.vel_b;

      /* Update for Delay: '<S5>/Delay4' */
      six_dof_vel_controller_DW.Delay4_DSTATE_m = six_dof_vel_controller_B.acc_e;

      /* Update for Delay: '<S6>/Delay5' */
      six_dof_vel_controller_DW.Delay5_DSTATE_b = six_dof_vel_controller_B.vel_g;

      /* Update for Delay: '<S6>/Delay4' */
      six_dof_vel_controller_DW.Delay4_DSTATE_b =
        six_dof_vel_controller_B.acc_mv;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(six_dof_vel_controller_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(six_dof_vel_controller_M)!=-1) &&
          !((rtmGetTFinal(six_dof_vel_controller_M)-
             (((six_dof_vel_controller_M->Timing.clockTick1+
                six_dof_vel_controller_M->Timing.clockTickH1* 4294967296.0)) *
              0.008)) > (((six_dof_vel_controller_M->Timing.clockTick1+
                           six_dof_vel_controller_M->Timing.clockTickH1*
                           4294967296.0)) * 0.008) * (DBL_EPSILON))) {
        rtmSetErrorStatus(six_dof_vel_controller_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&six_dof_vel_controller_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++six_dof_vel_controller_M->Timing.clockTick0)) {
      ++six_dof_vel_controller_M->Timing.clockTickH0;
    }

    six_dof_vel_controller_M->Timing.t[0] = rtsiGetSolverStopTime
      (&six_dof_vel_controller_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.008s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.008, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      six_dof_vel_controller_M->Timing.clockTick1++;
      if (!six_dof_vel_controller_M->Timing.clockTick1) {
        six_dof_vel_controller_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void six_dof_vel_controller_derivatives(void)
{
  XDot_six_dof_vel_controller_T *_rtXdot;
  _rtXdot = ((XDot_six_dof_vel_controller_T *) six_dof_vel_controller_M->derivs);

  /* Derivatives for Integrator: '<S2>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = six_dof_vel_controller_B.vel;

  /* Derivatives for Integrator: '<S3>/Integrator3' */
  _rtXdot->Integrator3_CSTATE = six_dof_vel_controller_B.vel_j;

  /* Derivatives for Integrator: '<S1>/Integrator3' */
  _rtXdot->Integrator3_CSTATE_p = six_dof_vel_controller_B.vel_c;

  /* Derivatives for Integrator: '<S4>/Integrator3' */
  _rtXdot->Integrator3_CSTATE_j = six_dof_vel_controller_B.vel_p;

  /* Derivatives for Integrator: '<S5>/Integrator3' */
  _rtXdot->Integrator3_CSTATE_d = six_dof_vel_controller_B.vel_b;

  /* Derivatives for Integrator: '<S6>/Integrator3' */
  _rtXdot->Integrator3_CSTATE_m = six_dof_vel_controller_B.vel_g;

  /* Derivatives for Integrator: '<S2>/Integrator' */
  _rtXdot->Integrator_CSTATE = six_dof_vel_controller_B.acc;

  /* Derivatives for Integrator: '<S3>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = six_dof_vel_controller_B.acc_f;

  /* Derivatives for Integrator: '<S1>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_f = six_dof_vel_controller_B.acc_b;

  /* Derivatives for Integrator: '<S4>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_i = six_dof_vel_controller_B.acc_m;

  /* Derivatives for Integrator: '<S5>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_ic = six_dof_vel_controller_B.acc_e;

  /* Derivatives for Integrator: '<S6>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_g = six_dof_vel_controller_B.acc_mv;

  /* Derivatives for Integrator: '<S2>/Integrator4' */
  _rtXdot->Integrator4_CSTATE = six_dof_vel_controller_B.Saturation3;

  /* Derivatives for Integrator: '<S3>/Integrator5' */
  _rtXdot->Integrator5_CSTATE = six_dof_vel_controller_B.Saturation7;

  /* Derivatives for Integrator: '<S1>/Integrator5' */
  _rtXdot->Integrator5_CSTATE_a = six_dof_vel_controller_B.Saturation7_f;

  /* Derivatives for Integrator: '<S4>/Integrator5' */
  _rtXdot->Integrator5_CSTATE_n = six_dof_vel_controller_B.Saturation7_fl;

  /* Derivatives for Integrator: '<S5>/Integrator5' */
  _rtXdot->Integrator5_CSTATE_ay = six_dof_vel_controller_B.Saturation7_i;

  /* Derivatives for Integrator: '<S6>/Integrator5' */
  _rtXdot->Integrator5_CSTATE_d = six_dof_vel_controller_B.Saturation7_g;
}

/* Model initialize function */
void six_dof_vel_controller_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)six_dof_vel_controller_M, 0,
                sizeof(RT_MODEL_six_dof_vel_controll_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&six_dof_vel_controller_M->solverInfo,
                          &six_dof_vel_controller_M->Timing.simTimeStep);
    rtsiSetTPtr(&six_dof_vel_controller_M->solverInfo, &rtmGetTPtr
                (six_dof_vel_controller_M));
    rtsiSetStepSizePtr(&six_dof_vel_controller_M->solverInfo,
                       &six_dof_vel_controller_M->Timing.stepSize0);
    rtsiSetdXPtr(&six_dof_vel_controller_M->solverInfo,
                 &six_dof_vel_controller_M->derivs);
    rtsiSetContStatesPtr(&six_dof_vel_controller_M->solverInfo, (real_T **)
                         &six_dof_vel_controller_M->contStates);
    rtsiSetNumContStatesPtr(&six_dof_vel_controller_M->solverInfo,
      &six_dof_vel_controller_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&six_dof_vel_controller_M->solverInfo,
      &six_dof_vel_controller_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&six_dof_vel_controller_M->solverInfo,
      &six_dof_vel_controller_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&six_dof_vel_controller_M->solverInfo,
      &six_dof_vel_controller_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&six_dof_vel_controller_M->solverInfo,
                          (&rtmGetErrorStatus(six_dof_vel_controller_M)));
    rtsiSetRTModelPtr(&six_dof_vel_controller_M->solverInfo,
                      six_dof_vel_controller_M);
  }

  rtsiSetSimTimeStep(&six_dof_vel_controller_M->solverInfo, MAJOR_TIME_STEP);
  six_dof_vel_controller_M->intgData.y = six_dof_vel_controller_M->odeY;
  six_dof_vel_controller_M->intgData.f[0] = six_dof_vel_controller_M->odeF[0];
  six_dof_vel_controller_M->intgData.f[1] = six_dof_vel_controller_M->odeF[1];
  six_dof_vel_controller_M->intgData.f[2] = six_dof_vel_controller_M->odeF[2];
  six_dof_vel_controller_M->contStates = ((X_six_dof_vel_controller_T *)
    &six_dof_vel_controller_X);
  rtsiSetSolverData(&six_dof_vel_controller_M->solverInfo, (void *)
                    &six_dof_vel_controller_M->intgData);
  rtsiSetSolverName(&six_dof_vel_controller_M->solverInfo,"ode3");
  rtmSetTPtr(six_dof_vel_controller_M, &six_dof_vel_controller_M->Timing.tArray
             [0]);
  rtmSetTFinal(six_dof_vel_controller_M, -1);
  six_dof_vel_controller_M->Timing.stepSize0 = 0.008;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    six_dof_vel_controller_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(six_dof_vel_controller_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(six_dof_vel_controller_M->rtwLogInfo, (NULL));
    rtliSetLogT(six_dof_vel_controller_M->rtwLogInfo, "");
    rtliSetLogX(six_dof_vel_controller_M->rtwLogInfo, "");
    rtliSetLogXFinal(six_dof_vel_controller_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(six_dof_vel_controller_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(six_dof_vel_controller_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(six_dof_vel_controller_M->rtwLogInfo, 0);
    rtliSetLogDecimation(six_dof_vel_controller_M->rtwLogInfo, 1);
    rtliSetLogY(six_dof_vel_controller_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(six_dof_vel_controller_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(six_dof_vel_controller_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &six_dof_vel_controller_B), 0,
                sizeof(B_six_dof_vel_controller_T));

  /* states (continuous) */
  {
    (void) memset((void *)&six_dof_vel_controller_X, 0,
                  sizeof(X_six_dof_vel_controller_T));
  }

  /* states (dwork) */
  (void) memset((void *)&six_dof_vel_controller_DW, 0,
                sizeof(DW_six_dof_vel_controller_T));

  /* external inputs */
  (void)memset(&six_dof_vel_controller_U, 0, sizeof
               (ExtU_six_dof_vel_controller_T));

  /* external outputs */
  (void) memset((void *)&six_dof_vel_controller_Y, 0,
                sizeof(ExtY_six_dof_vel_controller_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  six_dof_vel_controller_InitializeDataMapInfo();

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(six_dof_vel_controller_M->rtwLogInfo, 0.0,
    rtmGetTFinal(six_dof_vel_controller_M),
    six_dof_vel_controller_M->Timing.stepSize0, (&rtmGetErrorStatus
    (six_dof_vel_controller_M)));

  /* InitializeConditions for Integrator: '<S2>/Integrator1' */
  six_dof_vel_controller_X.Integrator1_CSTATE =
    six_dof_vel_controller_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S3>/Integrator3' */
  six_dof_vel_controller_X.Integrator3_CSTATE =
    six_dof_vel_controller_P.Integrator3_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator3' */
  six_dof_vel_controller_X.Integrator3_CSTATE_p =
    six_dof_vel_controller_P.Integrator3_IC_i;

  /* InitializeConditions for Integrator: '<S4>/Integrator3' */
  six_dof_vel_controller_X.Integrator3_CSTATE_j =
    six_dof_vel_controller_P.Integrator3_IC_ix;

  /* InitializeConditions for Integrator: '<S5>/Integrator3' */
  six_dof_vel_controller_X.Integrator3_CSTATE_d =
    six_dof_vel_controller_P.Integrator3_IC_j;

  /* InitializeConditions for Integrator: '<S6>/Integrator3' */
  six_dof_vel_controller_X.Integrator3_CSTATE_m =
    six_dof_vel_controller_P.Integrator3_IC_a;

  /* InitializeConditions for Integrator: '<S2>/Integrator' */
  six_dof_vel_controller_X.Integrator_CSTATE =
    six_dof_vel_controller_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S3>/Integrator2' */
  six_dof_vel_controller_X.Integrator2_CSTATE =
    six_dof_vel_controller_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator2' */
  six_dof_vel_controller_X.Integrator2_CSTATE_f =
    six_dof_vel_controller_P.Integrator2_IC_k;

  /* InitializeConditions for Integrator: '<S4>/Integrator2' */
  six_dof_vel_controller_X.Integrator2_CSTATE_i =
    six_dof_vel_controller_P.Integrator2_IC_g;

  /* InitializeConditions for Integrator: '<S5>/Integrator2' */
  six_dof_vel_controller_X.Integrator2_CSTATE_ic =
    six_dof_vel_controller_P.Integrator2_IC_n;

  /* InitializeConditions for Integrator: '<S6>/Integrator2' */
  six_dof_vel_controller_X.Integrator2_CSTATE_g =
    six_dof_vel_controller_P.Integrator2_IC_h;

  /* InitializeConditions for Integrator: '<S2>/Integrator4' */
  six_dof_vel_controller_X.Integrator4_CSTATE =
    six_dof_vel_controller_P.Integrator4_IC;

  /* InitializeConditions for Integrator: '<S3>/Integrator5' */
  six_dof_vel_controller_X.Integrator5_CSTATE =
    six_dof_vel_controller_P.Integrator5_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator5' */
  six_dof_vel_controller_X.Integrator5_CSTATE_a =
    six_dof_vel_controller_P.Integrator5_IC_i;

  /* InitializeConditions for Integrator: '<S4>/Integrator5' */
  six_dof_vel_controller_X.Integrator5_CSTATE_n =
    six_dof_vel_controller_P.Integrator5_IC_a;

  /* InitializeConditions for Integrator: '<S5>/Integrator5' */
  six_dof_vel_controller_X.Integrator5_CSTATE_ay =
    six_dof_vel_controller_P.Integrator5_IC_p;

  /* InitializeConditions for Integrator: '<S6>/Integrator5' */
  six_dof_vel_controller_X.Integrator5_CSTATE_d =
    six_dof_vel_controller_P.Integrator5_IC_k;

  /* InitializeConditions for Delay: '<S2>/Delay2' */
  six_dof_vel_controller_DW.Delay2_DSTATE =
    six_dof_vel_controller_P.Delay2_InitialCondition;

  /* InitializeConditions for Delay: '<S2>/Delay1' */
  six_dof_vel_controller_DW.Delay1_DSTATE =
    six_dof_vel_controller_P.Delay1_InitialCondition;

  /* InitializeConditions for Delay: '<S3>/Delay5' */
  six_dof_vel_controller_DW.Delay5_DSTATE =
    six_dof_vel_controller_P.Delay5_InitialCondition;

  /* InitializeConditions for Delay: '<S3>/Delay4' */
  six_dof_vel_controller_DW.Delay4_DSTATE =
    six_dof_vel_controller_P.Delay4_InitialCondition;

  /* InitializeConditions for Delay: '<S1>/Delay5' */
  six_dof_vel_controller_DW.Delay5_DSTATE_a =
    six_dof_vel_controller_P.Delay5_InitialCondition_g;

  /* InitializeConditions for Delay: '<S1>/Delay4' */
  six_dof_vel_controller_DW.Delay4_DSTATE_j =
    six_dof_vel_controller_P.Delay4_InitialCondition_j;

  /* InitializeConditions for Delay: '<S4>/Delay5' */
  six_dof_vel_controller_DW.Delay5_DSTATE_c =
    six_dof_vel_controller_P.Delay5_InitialCondition_n;

  /* InitializeConditions for Delay: '<S4>/Delay4' */
  six_dof_vel_controller_DW.Delay4_DSTATE_o =
    six_dof_vel_controller_P.Delay4_InitialCondition_d;

  /* InitializeConditions for Delay: '<S5>/Delay5' */
  six_dof_vel_controller_DW.Delay5_DSTATE_h =
    six_dof_vel_controller_P.Delay5_InitialCondition_i;

  /* InitializeConditions for Delay: '<S5>/Delay4' */
  six_dof_vel_controller_DW.Delay4_DSTATE_m =
    six_dof_vel_controller_P.Delay4_InitialCondition_n;

  /* InitializeConditions for Delay: '<S6>/Delay5' */
  six_dof_vel_controller_DW.Delay5_DSTATE_b =
    six_dof_vel_controller_P.Delay5_InitialCondition_o;

  /* InitializeConditions for Delay: '<S6>/Delay4' */
  six_dof_vel_controller_DW.Delay4_DSTATE_b =
    six_dof_vel_controller_P.Delay4_InitialCondition_k;
}

/* Model terminate function */
void six_dof_vel_controller_terminate(void)
{
  /* (no terminate code required) */
}
