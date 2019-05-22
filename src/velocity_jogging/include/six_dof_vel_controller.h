/*
 * six_dof_vel_controller.h
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

#ifndef RTW_HEADER_six_dof_vel_controller_h_
#define RTW_HEADER_six_dof_vel_controller_h_
#include <string.h>
#include <float.h>
#include <stddef.h>
#include "rtw_modelmap.h"
#ifndef six_dof_vel_controller_COMMON_INCLUDES_
# define six_dof_vel_controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* six_dof_vel_controller_COMMON_INCLUDES_ */

#include "six_dof_vel_controller_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T vel;                          /* '<S2>/Saturation1' */
  real_T vel_j;                        /* '<S3>/Saturation5' */
  real_T vel_c;                        /* '<S1>/Saturation5' */
  real_T vel_p;                        /* '<S4>/Saturation5' */
  real_T vel_b;                        /* '<S5>/Saturation5' */
  real_T vel_g;                        /* '<S6>/Saturation5' */
  real_T acc;                          /* '<S2>/Saturation' */
  real_T acc_f;                        /* '<S3>/Saturation4' */
  real_T acc_b;                        /* '<S1>/Saturation4' */
  real_T acc_m;                        /* '<S4>/Saturation4' */
  real_T acc_e;                        /* '<S5>/Saturation4' */
  real_T acc_mv;                       /* '<S6>/Saturation4' */
  real_T Saturation3;                  /* '<S2>/Saturation3' */
  real_T Saturation7;                  /* '<S3>/Saturation7' */
  real_T Saturation7_f;                /* '<S1>/Saturation7' */
  real_T Saturation7_fl;               /* '<S4>/Saturation7' */
  real_T Saturation7_i;                /* '<S5>/Saturation7' */
  real_T Saturation7_g;                /* '<S6>/Saturation7' */
} B_six_dof_vel_controller_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay2_DSTATE;                /* '<S2>/Delay2' */
  real_T Delay1_DSTATE;                /* '<S2>/Delay1' */
  real_T Delay5_DSTATE;                /* '<S3>/Delay5' */
  real_T Delay4_DSTATE;                /* '<S3>/Delay4' */
  real_T Delay5_DSTATE_a;              /* '<S1>/Delay5' */
  real_T Delay4_DSTATE_j;              /* '<S1>/Delay4' */
  real_T Delay5_DSTATE_c;              /* '<S4>/Delay5' */
  real_T Delay4_DSTATE_o;              /* '<S4>/Delay4' */
  real_T Delay5_DSTATE_h;              /* '<S5>/Delay5' */
  real_T Delay4_DSTATE_m;              /* '<S5>/Delay4' */
  real_T Delay5_DSTATE_b;              /* '<S6>/Delay5' */
  real_T Delay4_DSTATE_b;              /* '<S6>/Delay4' */
} DW_six_dof_vel_controller_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S2>/Integrator1' */
  real_T Integrator3_CSTATE;           /* '<S3>/Integrator3' */
  real_T Integrator3_CSTATE_p;         /* '<S1>/Integrator3' */
  real_T Integrator3_CSTATE_j;         /* '<S4>/Integrator3' */
  real_T Integrator3_CSTATE_d;         /* '<S5>/Integrator3' */
  real_T Integrator3_CSTATE_m;         /* '<S6>/Integrator3' */
  real_T Integrator_CSTATE;            /* '<S2>/Integrator' */
  real_T Integrator2_CSTATE;           /* '<S3>/Integrator2' */
  real_T Integrator2_CSTATE_f;         /* '<S1>/Integrator2' */
  real_T Integrator2_CSTATE_i;         /* '<S4>/Integrator2' */
  real_T Integrator2_CSTATE_ic;        /* '<S5>/Integrator2' */
  real_T Integrator2_CSTATE_g;         /* '<S6>/Integrator2' */
  real_T Integrator4_CSTATE;           /* '<S2>/Integrator4' */
  real_T Integrator5_CSTATE;           /* '<S3>/Integrator5' */
  real_T Integrator5_CSTATE_a;         /* '<S1>/Integrator5' */
  real_T Integrator5_CSTATE_n;         /* '<S4>/Integrator5' */
  real_T Integrator5_CSTATE_ay;        /* '<S5>/Integrator5' */
  real_T Integrator5_CSTATE_d;         /* '<S6>/Integrator5' */
} X_six_dof_vel_controller_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S2>/Integrator1' */
  real_T Integrator3_CSTATE;           /* '<S3>/Integrator3' */
  real_T Integrator3_CSTATE_p;         /* '<S1>/Integrator3' */
  real_T Integrator3_CSTATE_j;         /* '<S4>/Integrator3' */
  real_T Integrator3_CSTATE_d;         /* '<S5>/Integrator3' */
  real_T Integrator3_CSTATE_m;         /* '<S6>/Integrator3' */
  real_T Integrator_CSTATE;            /* '<S2>/Integrator' */
  real_T Integrator2_CSTATE;           /* '<S3>/Integrator2' */
  real_T Integrator2_CSTATE_f;         /* '<S1>/Integrator2' */
  real_T Integrator2_CSTATE_i;         /* '<S4>/Integrator2' */
  real_T Integrator2_CSTATE_ic;        /* '<S5>/Integrator2' */
  real_T Integrator2_CSTATE_g;         /* '<S6>/Integrator2' */
  real_T Integrator4_CSTATE;           /* '<S2>/Integrator4' */
  real_T Integrator5_CSTATE;           /* '<S3>/Integrator5' */
  real_T Integrator5_CSTATE_a;         /* '<S1>/Integrator5' */
  real_T Integrator5_CSTATE_n;         /* '<S4>/Integrator5' */
  real_T Integrator5_CSTATE_ay;        /* '<S5>/Integrator5' */
  real_T Integrator5_CSTATE_d;         /* '<S6>/Integrator5' */
} XDot_six_dof_vel_controller_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE;        /* '<S2>/Integrator1' */
  boolean_T Integrator3_CSTATE;        /* '<S3>/Integrator3' */
  boolean_T Integrator3_CSTATE_p;      /* '<S1>/Integrator3' */
  boolean_T Integrator3_CSTATE_j;      /* '<S4>/Integrator3' */
  boolean_T Integrator3_CSTATE_d;      /* '<S5>/Integrator3' */
  boolean_T Integrator3_CSTATE_m;      /* '<S6>/Integrator3' */
  boolean_T Integrator_CSTATE;         /* '<S2>/Integrator' */
  boolean_T Integrator2_CSTATE;        /* '<S3>/Integrator2' */
  boolean_T Integrator2_CSTATE_f;      /* '<S1>/Integrator2' */
  boolean_T Integrator2_CSTATE_i;      /* '<S4>/Integrator2' */
  boolean_T Integrator2_CSTATE_ic;     /* '<S5>/Integrator2' */
  boolean_T Integrator2_CSTATE_g;      /* '<S6>/Integrator2' */
  boolean_T Integrator4_CSTATE;        /* '<S2>/Integrator4' */
  boolean_T Integrator5_CSTATE;        /* '<S3>/Integrator5' */
  boolean_T Integrator5_CSTATE_a;      /* '<S1>/Integrator5' */
  boolean_T Integrator5_CSTATE_n;      /* '<S4>/Integrator5' */
  boolean_T Integrator5_CSTATE_ay;     /* '<S5>/Integrator5' */
  boolean_T Integrator5_CSTATE_d;      /* '<S6>/Integrator5' */
} XDis_six_dof_vel_controller_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T vel[6];                       /* '<Root>/vel' */
  real_T acc[6];                       /* '<Root>/acc' */
} ExtU_six_dof_vel_controller_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T POS[6];                       /* '<Root>/POS' */
  real_T VEL[6];                       /* '<Root>/VEL' */
  real_T ACC[6];                       /* '<Root>/ACC' */
  real_T JRK[6];                       /* '<Root>/JRK' */
} ExtY_six_dof_vel_controller_T;

/* Parameters (default storage) */
struct P_six_dof_vel_controller_T_ {
  real_T am[6];                        /* Variable: am
                                        * Referenced by:
                                        *   '<S1>/Saturation4'
                                        *   '<S2>/Saturation'
                                        *   '<S3>/Saturation4'
                                        *   '<S4>/Saturation4'
                                        *   '<S5>/Saturation4'
                                        *   '<S6>/Saturation4'
                                        */
  real_T jm[6];                        /* Variable: jm
                                        * Referenced by:
                                        *   '<S1>/Saturation7'
                                        *   '<S1>/Saturation9'
                                        *   '<S2>/Saturation3'
                                        *   '<S2>/Saturation8'
                                        *   '<S3>/Saturation7'
                                        *   '<S3>/Saturation9'
                                        *   '<S4>/Saturation7'
                                        *   '<S4>/Saturation9'
                                        *   '<S5>/Saturation7'
                                        *   '<S5>/Saturation9'
                                        *   '<S6>/Saturation7'
                                        *   '<S6>/Saturation9'
                                        */
  real_T ka[6];                        /* Variable: ka
                                        * Referenced by:
                                        *   '<S1>/Gain4'
                                        *   '<S2>/Gain1'
                                        *   '<S3>/Gain4'
                                        *   '<S4>/Gain4'
                                        *   '<S5>/Gain4'
                                        *   '<S6>/Gain4'
                                        */
  real_T kv[6];                        /* Variable: kv
                                        * Referenced by:
                                        *   '<S1>/Gain5'
                                        *   '<S2>/Gain2'
                                        *   '<S3>/Gain5'
                                        *   '<S4>/Gain5'
                                        *   '<S5>/Gain5'
                                        *   '<S6>/Gain5'
                                        */
  real_T sm[6];                        /* Variable: sm
                                        * Referenced by:
                                        *   '<S1>/Saturation6'
                                        *   '<S2>/Saturation2'
                                        *   '<S3>/Saturation6'
                                        *   '<S4>/Saturation6'
                                        *   '<S5>/Saturation6'
                                        *   '<S6>/Saturation6'
                                        */
  real_T vm[6];                        /* Variable: vm
                                        * Referenced by:
                                        *   '<S1>/Saturation5'
                                        *   '<S2>/Saturation1'
                                        *   '<S3>/Saturation5'
                                        *   '<S4>/Saturation5'
                                        *   '<S5>/Saturation5'
                                        *   '<S6>/Saturation5'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S2>/Integrator1'
                                        */
  real_T Integrator3_IC;               /* Expression: 0
                                        * Referenced by: '<S3>/Integrator3'
                                        */
  real_T Integrator3_IC_i;             /* Expression: 0
                                        * Referenced by: '<S1>/Integrator3'
                                        */
  real_T Integrator3_IC_ix;            /* Expression: 0
                                        * Referenced by: '<S4>/Integrator3'
                                        */
  real_T Integrator3_IC_j;             /* Expression: 0
                                        * Referenced by: '<S5>/Integrator3'
                                        */
  real_T Integrator3_IC_a;             /* Expression: 0
                                        * Referenced by: '<S6>/Integrator3'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S2>/Integrator'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S3>/Integrator2'
                                        */
  real_T Integrator2_IC_k;             /* Expression: 0
                                        * Referenced by: '<S1>/Integrator2'
                                        */
  real_T Integrator2_IC_g;             /* Expression: 0
                                        * Referenced by: '<S4>/Integrator2'
                                        */
  real_T Integrator2_IC_n;             /* Expression: 0
                                        * Referenced by: '<S5>/Integrator2'
                                        */
  real_T Integrator2_IC_h;             /* Expression: 0
                                        * Referenced by: '<S6>/Integrator2'
                                        */
  real_T Integrator4_IC;               /* Expression: 0
                                        * Referenced by: '<S2>/Integrator4'
                                        */
  real_T Integrator5_IC;               /* Expression: 0
                                        * Referenced by: '<S3>/Integrator5'
                                        */
  real_T Integrator5_IC_i;             /* Expression: 0
                                        * Referenced by: '<S1>/Integrator5'
                                        */
  real_T Integrator5_IC_a;             /* Expression: 0
                                        * Referenced by: '<S4>/Integrator5'
                                        */
  real_T Integrator5_IC_p;             /* Expression: 0
                                        * Referenced by: '<S5>/Integrator5'
                                        */
  real_T Integrator5_IC_k;             /* Expression: 0
                                        * Referenced by: '<S6>/Integrator5'
                                        */
  real_T Delay2_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S2>/Delay2'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S2>/Delay1'
                                        */
  real_T Delay5_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S3>/Delay5'
                                        */
  real_T Delay4_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S3>/Delay4'
                                        */
  real_T Delay5_InitialCondition_g;    /* Expression: 0
                                        * Referenced by: '<S1>/Delay5'
                                        */
  real_T Delay4_InitialCondition_j;    /* Expression: 0
                                        * Referenced by: '<S1>/Delay4'
                                        */
  real_T Delay5_InitialCondition_n;    /* Expression: 0
                                        * Referenced by: '<S4>/Delay5'
                                        */
  real_T Delay4_InitialCondition_d;    /* Expression: 0
                                        * Referenced by: '<S4>/Delay4'
                                        */
  real_T Delay5_InitialCondition_i;    /* Expression: 0
                                        * Referenced by: '<S5>/Delay5'
                                        */
  real_T Delay4_InitialCondition_n;    /* Expression: 0
                                        * Referenced by: '<S5>/Delay4'
                                        */
  real_T Delay5_InitialCondition_o;    /* Expression: 0
                                        * Referenced by: '<S6>/Delay5'
                                        */
  real_T Delay4_InitialCondition_k;    /* Expression: 0
                                        * Referenced by: '<S6>/Delay4'
                                        */
  uint32_T Delay2_DelayLength;         /* Computed Parameter: Delay2_DelayLength
                                        * Referenced by: '<S2>/Delay2'
                                        */
  uint32_T Delay1_DelayLength;         /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S2>/Delay1'
                                        */
  uint32_T Delay5_DelayLength;         /* Computed Parameter: Delay5_DelayLength
                                        * Referenced by: '<S3>/Delay5'
                                        */
  uint32_T Delay4_DelayLength;         /* Computed Parameter: Delay4_DelayLength
                                        * Referenced by: '<S3>/Delay4'
                                        */
  uint32_T Delay5_DelayLength_a;       /* Computed Parameter: Delay5_DelayLength_a
                                        * Referenced by: '<S1>/Delay5'
                                        */
  uint32_T Delay4_DelayLength_l;       /* Computed Parameter: Delay4_DelayLength_l
                                        * Referenced by: '<S1>/Delay4'
                                        */
  uint32_T Delay5_DelayLength_f;       /* Computed Parameter: Delay5_DelayLength_f
                                        * Referenced by: '<S4>/Delay5'
                                        */
  uint32_T Delay4_DelayLength_d;       /* Computed Parameter: Delay4_DelayLength_d
                                        * Referenced by: '<S4>/Delay4'
                                        */
  uint32_T Delay5_DelayLength_i;       /* Computed Parameter: Delay5_DelayLength_i
                                        * Referenced by: '<S5>/Delay5'
                                        */
  uint32_T Delay4_DelayLength_da;      /* Computed Parameter: Delay4_DelayLength_da
                                        * Referenced by: '<S5>/Delay4'
                                        */
  uint32_T Delay5_DelayLength_m;       /* Computed Parameter: Delay5_DelayLength_m
                                        * Referenced by: '<S6>/Delay5'
                                        */
  uint32_T Delay4_DelayLength_c;       /* Computed Parameter: Delay4_DelayLength_c
                                        * Referenced by: '<S6>/Delay4'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_six_dof_vel_controlle_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_six_dof_vel_controller_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[18];
  real_T odeF[3][18];
  ODE3_IntgData intgData;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
  } DataMapInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern P_six_dof_vel_controller_T six_dof_vel_controller_P;

#ifdef __cplusplus

}
#endif

/* Block signals (default storage) */
extern B_six_dof_vel_controller_T six_dof_vel_controller_B;

/* Continuous states (default storage) */
extern X_six_dof_vel_controller_T six_dof_vel_controller_X;

/* Block states (default storage) */
extern DW_six_dof_vel_controller_T six_dof_vel_controller_DW;

#ifdef __cplusplus

extern "C" {

#endif

  /* External inputs (root inport signals with default storage) */
  extern ExtU_six_dof_vel_controller_T six_dof_vel_controller_U;

  /* External outputs (root outports fed by signals with default storage) */
  extern ExtY_six_dof_vel_controller_T six_dof_vel_controller_Y;

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void six_dof_vel_controller_initialize(void);
  extern void six_dof_vel_controller_step(void);
  extern void six_dof_vel_controller_terminate(void);

#ifdef __cplusplus

}
#endif

/* Function to get C API Model Mapping Static Info */
extern const rtwCAPI_ModelMappingStaticInfo*
  six_dof_vel_controller_GetCAPIStaticMap(void);

/* Real-time Model object */
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_six_dof_vel_controll_T *const six_dof_vel_controller_M;

#ifdef __cplusplus

}
#endif

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'six_dof_vel_controller'
 * '<S1>'   : 'six_dof_vel_controller/joint 2'
 * '<S2>'   : 'six_dof_vel_controller/joint_0'
 * '<S3>'   : 'six_dof_vel_controller/joint_1 '
 * '<S4>'   : 'six_dof_vel_controller/joint_3'
 * '<S5>'   : 'six_dof_vel_controller/joint_4  '
 * '<S6>'   : 'six_dof_vel_controller/joint_5'
 */
#endif                                 /* RTW_HEADER_six_dof_vel_controller_h_ */
