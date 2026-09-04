/* Include files */

#include "modelInterface.h"
#include "m_T3eFG2ybNxqtnQCo5Gn1r.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 1,     /* lineNo */
  "LoggerBlock",                       /* fcnName */
  "C:\\Users\\nabil\\OneDrive\\Documents\\MATLAB\\smart batch\\hardwareTesting\\G3efar\\LoggerBlock.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 1,   /* lineNo */
  "System",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025b\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+coder\\System.p"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 1,   /* lineNo */
  "SystemProp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025b\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+coder\\SystemProp.p"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 1,   /* lineNo */
  "SystemCore",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2025b\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+coder\\SystemCore.p"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 6,   /* lineNo */
  "",                                  /* fcnName */
  ""                                   /* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 19,  /* lineNo */
  "",                                  /* fcnName */
  ""                                   /* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 21,  /* lineNo */
  "",                                  /* fcnName */
  ""                                   /* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 26,  /* lineNo */
  "",                                  /* fcnName */
  ""                                   /* pathName */
};

static emlrtMCInfo emlrtMCI = { 1,     /* lineNo */
  1,                                   /* colNo */
  "SystemCore",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2025b\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+coder\\SystemCore.p"/* pName */
};

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r
  *moduleInstance);
static void mw__internal__system__init__fcn(InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r
  *moduleInstance);
static void mw__internal__system__terminate__fcn
  (InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r *moduleInstance);
static void mw__internal__call__setup(InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r
  *moduleInstance, const emlrtStack *sp);
static void mw__internal__call__reset(InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r
  *moduleInstance, const emlrtStack *sp);
static void mw__internal__call__step(InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r
  *moduleInstance, const emlrtStack *sp);
static const mxArray *emlrt_marshallOut(InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r
  *moduleInstance);
static const mxArray *cgxe_mdl_get_sim_state
  (InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r *moduleInstance);
static void emlrt_marshallIn(InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r
  *moduleInstance, const emlrtStack *sp, const mxArray *u);
static LoggerBlock b_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *nullptr, const char_T *identifier);
static LoggerBlock c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static int32_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static boolean_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
  const char_T *identifier);
static boolean_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static void cgxe_mdl_set_sim_state(InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r
  *moduleInstance, const mxArray *st);
static const mxArray *message(const emlrtStack *sp, const mxArray *m1, const
  mxArray *m2, emlrtMCInfo *location);
static const mxArray *getString(const emlrtStack *sp, const mxArray *m1,
  emlrtMCInfo *location);
static void error(const emlrtStack *sp, const mxArray *m, const mxArray *m1,
                  emlrtMCInfo *location);
static int32_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static boolean_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static void init_simulink_io_address(InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r *moduleInstance)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  init_simulink_io_address(moduleInstance);
  st.tls = moduleInstance->emlrtRootTLSGlobal;
  cgxertSetGcb(moduleInstance->S, -1, -1);
  mw__internal__system__init__fcn(moduleInstance);
  mw__internal__call__setup(moduleInstance, &st);
  cgxertRestoreGcb(moduleInstance->S, -1, -1);
}

static void cgxe_mdl_initialize(InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r
  *moduleInstance)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = moduleInstance->emlrtRootTLSGlobal;
  cgxertSetGcb(moduleInstance->S, -1, -1);
  mw__internal__call__reset(moduleInstance, &st);
  cgxertRestoreGcb(moduleInstance->S, -1, -1);
}

static void cgxe_mdl_outputs(InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r
  *moduleInstance)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = moduleInstance->emlrtRootTLSGlobal;
  cgxertSetGcb(moduleInstance->S, -1, -1);
  mw__internal__call__step(moduleInstance, &st);
  cgxertRestoreGcb(moduleInstance->S, -1, -1);
}

static void cgxe_mdl_update(InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r
  *moduleInstance)
{
  cgxertSetGcb(moduleInstance->S, -1, -1);
  mw__internal__system__terminate__fcn(moduleInstance);
  cgxertRestoreGcb(moduleInstance->S, -1, -1);
}

static void mw__internal__system__init__fcn(InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r
  *moduleInstance)
{
  /* Allocate instance data */
  covrtAllocateInstanceData(moduleInstance->covInst_CONTAINER_BLOCK_INDEX);

  /* Initialize Coverage Information */
  covrtScriptInit(moduleInstance->covInst_CONTAINER_BLOCK_INDEX,
                  "C:\\Users\\nabil\\OneDrive\\Documents\\MATLAB\\smart batch\\hardwareTesting\\G3efar\\LoggerBlock.m",
                  0U, 5U, 4U, 2U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(moduleInstance->covInst_CONTAINER_BLOCK_INDEX, 0U, 1U,
               "LoggerBlock_stepImpl", 172, -1, 637);
  covrtFcnInit(moduleInstance->covInst_CONTAINER_BLOCK_INDEX, 0U, 2U,
               "LoggerBlock_getDescriptiveName", 676, -1, 763);
  covrtFcnInit(moduleInstance->covInst_CONTAINER_BLOCK_INDEX, 0U, 3U,
               "LoggerBlock_isSupportedContext", 773, -1, 873);
  covrtFcnInit(moduleInstance->covInst_CONTAINER_BLOCK_INDEX, 0U, 4U,
               "LoggerBlock_updateBuildInfo", 883, -1, 1109);
  covrtFcnInit(moduleInstance->covInst_CONTAINER_BLOCK_INDEX, 0U, 0U,
               "LoggerBlock_LoggerBlock", 9, -1, 20);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(moduleInstance->covInst_CONTAINER_BLOCK_INDEX, 0U, 0U, 263,
                      -1, 609);
  covrtBasicBlockInit(moduleInstance->covInst_CONTAINER_BLOCK_INDEX, 0U, 1U, 726,
                      -1, 751);
  covrtBasicBlockInit(moduleInstance->covInst_CONTAINER_BLOCK_INDEX, 0U, 2U, 826,
                      -1, 861);
  covrtBasicBlockInit(moduleInstance->covInst_CONTAINER_BLOCK_INDEX, 0U, 3U, 990,
                      -1, 1081);

  /* Initialize If Information */
  covrtIfInit(moduleInstance->covInst_CONTAINER_BLOCK_INDEX, 0U, 0U, 224, 246,
              -1, 625);
  covrtIfInit(moduleInstance->covInst_CONTAINER_BLOCK_INDEX, 0U, 1U, 940, 973,
              -1, 1097);

  /* Initialize Relational Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(moduleInstance->covInst_CONTAINER_BLOCK_INDEX, 0U);
}

static void mw__internal__system__terminate__fcn
  (InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r *moduleInstance)
{
  /* Free instance data */
  covrtFreeInstanceData(moduleInstance->covInst_CONTAINER_BLOCK_INDEX);
}

static void mw__internal__call__setup(InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r
  *moduleInstance, const emlrtStack *sp)
{
  static const int32_T iv[2] = { 1, 51 };

  static const int32_T iv1[2] = { 1, 51 };

  static const int32_T iv2[2] = { 1, 5 };

  static char_T b_u[51] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'L', 'o', 'c', 'k', 'e', 'd', 'R', 'e', 'l', 'e',
    'a', 's', 'e', 'd', 'C', 'o', 'd', 'e', 'g', 'e', 'n' };

  static char_T d_u[5] = { 's', 'e', 't', 'u', 'p' };

  LoggerBlock *obj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m;
  const mxArray *y;
  int32_T i;
  char_T u[51];
  char_T c_u[5];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (!moduleInstance->sysobj_not_empty) {
    st.site = &e_emlrtRSI;
    obj = &moduleInstance->sysobj;
    covrtLogFcn(moduleInstance->covInst_CONTAINER_BLOCK_INDEX, 0, 0);
    b_st.site = &emlrtRSI;
    c_st.site = &b_emlrtRSI;
    d_st.site = &c_emlrtRSI;
    c_st.site = &b_emlrtRSI;
    d_st.site = &d_emlrtRSI;
    obj->isInitialized = 0;
    b_st.site = &emlrtRSI;
    moduleInstance->sysobj_not_empty = true;
  }

  st.site = &f_emlrtRSI;
  obj = &moduleInstance->sysobj;
  if (obj->isInitialized != 0) {
    for (i = 0; i < 51; i++) {
      u[i] = b_u[i];
    }

    y = NULL;
    m = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a(&st, 51, m, &u[0]);
    emlrtAssign(&y, m);
    for (i = 0; i < 51; i++) {
      u[i] = b_u[i];
    }

    b_y = NULL;
    m = emlrtCreateCharArray(2, &iv1[0]);
    emlrtInitCharArrayR2013a(&st, 51, m, &u[0]);
    emlrtAssign(&b_y, m);
    for (i = 0; i < 5; i++) {
      c_u[i] = d_u[i];
    }

    c_y = NULL;
    m = emlrtCreateCharArray(2, &iv2[0]);
    emlrtInitCharArrayR2013a(&st, 5, m, &c_u[0]);
    emlrtAssign(&c_y, m);
    b_st.site = &d_emlrtRSI;
    error(&b_st, y, getString(&b_st, message(&b_st, b_y, c_y, &emlrtMCI),
           &emlrtMCI), &emlrtMCI);
  }

  obj->isInitialized = 1;
}

static void mw__internal__call__reset(InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r
  *moduleInstance, const emlrtStack *sp)
{
  static const int32_T iv[2] = { 1, 45 };

  static const int32_T iv1[2] = { 1, 45 };

  static const int32_T iv2[2] = { 1, 5 };

  static char_T b_u[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  static char_T d_u[5] = { 'r', 'e', 's', 'e', 't' };

  LoggerBlock *obj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m;
  const mxArray *y;
  int32_T i;
  char_T u[45];
  char_T c_u[5];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (!moduleInstance->sysobj_not_empty) {
    st.site = &e_emlrtRSI;
    obj = &moduleInstance->sysobj;
    covrtLogFcn(moduleInstance->covInst_CONTAINER_BLOCK_INDEX, 0, 0);
    b_st.site = &emlrtRSI;
    c_st.site = &b_emlrtRSI;
    d_st.site = &c_emlrtRSI;
    c_st.site = &b_emlrtRSI;
    d_st.site = &d_emlrtRSI;
    obj->isInitialized = 0;
    b_st.site = &emlrtRSI;
    moduleInstance->sysobj_not_empty = true;
  }

  st.site = &g_emlrtRSI;
  obj = &moduleInstance->sysobj;
  if (obj->isInitialized == 2) {
    for (i = 0; i < 45; i++) {
      u[i] = b_u[i];
    }

    y = NULL;
    m = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a(&st, 45, m, &u[0]);
    emlrtAssign(&y, m);
    for (i = 0; i < 45; i++) {
      u[i] = b_u[i];
    }

    b_y = NULL;
    m = emlrtCreateCharArray(2, &iv1[0]);
    emlrtInitCharArrayR2013a(&st, 45, m, &u[0]);
    emlrtAssign(&b_y, m);
    for (i = 0; i < 5; i++) {
      c_u[i] = d_u[i];
    }

    c_y = NULL;
    m = emlrtCreateCharArray(2, &iv2[0]);
    emlrtInitCharArrayR2013a(&st, 5, m, &c_u[0]);
    emlrtAssign(&c_y, m);
    b_st.site = &d_emlrtRSI;
    error(&b_st, y, getString(&b_st, message(&b_st, b_y, c_y, &emlrtMCI),
           &emlrtMCI), &emlrtMCI);
  }
}

static void mw__internal__call__step(InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r
  *moduleInstance, const emlrtStack *sp)
{
  static const int32_T iv[2] = { 1, 51 };

  static const int32_T iv1[2] = { 1, 51 };

  static const int32_T iv2[2] = { 1, 5 };

  static char_T b_u[51] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'L', 'o', 'c', 'k', 'e', 'd', 'R', 'e', 'l', 'e',
    'a', 's', 'e', 'd', 'C', 'o', 'd', 'e', 'g', 'e', 'n' };

  static char_T d_u[5] = { 's', 'e', 't', 'u', 'p' };

  LoggerBlock *obj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m;
  const mxArray *y;
  int32_T i;
  char_T u[51];
  char_T c_u[5];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if (!moduleInstance->sysobj_not_empty) {
    st.site = &e_emlrtRSI;
    obj = &moduleInstance->sysobj;
    covrtLogFcn(moduleInstance->covInst_CONTAINER_BLOCK_INDEX, 0, 0);
    b_st.site = &emlrtRSI;
    c_st.site = &b_emlrtRSI;
    d_st.site = &c_emlrtRSI;
    c_st.site = &b_emlrtRSI;
    d_st.site = &d_emlrtRSI;
    obj->isInitialized = 0;
    b_st.site = &emlrtRSI;
    moduleInstance->sysobj_not_empty = true;
  }

  st.site = &h_emlrtRSI;
  obj = &moduleInstance->sysobj;
  if (obj->isInitialized != 1) {
    b_st.site = &d_emlrtRSI;
    c_st.site = &d_emlrtRSI;
    if (obj->isInitialized != 0) {
      for (i = 0; i < 51; i++) {
        u[i] = b_u[i];
      }

      y = NULL;
      m = emlrtCreateCharArray(2, &iv[0]);
      emlrtInitCharArrayR2013a(&c_st, 51, m, &u[0]);
      emlrtAssign(&y, m);
      for (i = 0; i < 51; i++) {
        u[i] = b_u[i];
      }

      b_y = NULL;
      m = emlrtCreateCharArray(2, &iv1[0]);
      emlrtInitCharArrayR2013a(&c_st, 51, m, &u[0]);
      emlrtAssign(&b_y, m);
      for (i = 0; i < 5; i++) {
        c_u[i] = d_u[i];
      }

      c_y = NULL;
      m = emlrtCreateCharArray(2, &iv2[0]);
      emlrtInitCharArrayR2013a(&c_st, 5, m, &c_u[0]);
      emlrtAssign(&c_y, m);
      d_st.site = &d_emlrtRSI;
      error(&d_st, y, getString(&d_st, message(&d_st, b_y, c_y, &emlrtMCI),
             &emlrtMCI), &emlrtMCI);
    }

    obj->isInitialized = 1;
  }

  b_st.site = &d_emlrtRSI;
  covrtLogFcn(moduleInstance->covInst_CONTAINER_BLOCK_INDEX, 0, 1);
  covrtLogIf(moduleInstance->covInst_CONTAINER_BLOCK_INDEX, 0, 0, 0, false);
}

static const mxArray *emlrt_marshallOut(InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r
  *moduleInstance)
{
  static const char_T *sv[1] = { "isInitialized" };

  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *m;
  const mxArray *y;
  int32_T u;
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellMatrix(2, 1));
  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateStructMatrix(1, 1, 1, (const char_T **)&sv[0]));
  u = moduleInstance->sysobj.isInitialized;
  c_y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)emlrtMxGetData(m) = u;
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(b_y, 0, "isInitialized", c_y, 0);
  emlrtSetCell(y, 0, b_y);
  d_y = NULL;
  m = emlrtCreateLogicalScalar(moduleInstance->sysobj_not_empty);
  emlrtAssign(&d_y, m);
  emlrtSetCell(y, 1, d_y);
  return y;
}

static const mxArray *cgxe_mdl_get_sim_state
  (InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r *moduleInstance)
{
  const mxArray *st;
  st = NULL;
  emlrtAssign(&st, emlrt_marshallOut(moduleInstance));
  return st;
}

static void emlrt_marshallIn(InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r
  *moduleInstance, const emlrtStack *sp, const mxArray *u)
{
  emlrtMsgIdentifier thisId;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  thisId.fIdentifier = "sysobj";
  moduleInstance->sysobj = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((void *)
    sp, &thisId, u, 0)), "sysobj");
  thisId.fIdentifier = "sysobj_not_empty";
  moduleInstance->sysobj_not_empty = e_emlrt_marshallIn(sp, emlrtAlias
    (emlrtGetCell((void *)sp, &thisId, u, 1)), "sysobj_not_empty");
  emlrtDestroyArray(&u);
}

static LoggerBlock b_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *nullptr, const char_T *identifier)
{
  LoggerBlock y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = c_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static LoggerBlock c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[1] = { "isInitialized" };

  LoggerBlock y;
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)sp, parentId, u, 1, (const char_T **)
    &fieldNames[0], 0U, (const void *)&dims);
  thisId.fIdentifier = "isInitialized";
  y.isInitialized = d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b
    ((emlrtConstCTX)sp, u, 0, 0, "isInitialized")), &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static int32_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  int32_T y;
  y = g_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static boolean_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
  const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  boolean_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static boolean_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = h_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void cgxe_mdl_set_sim_state(InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r
  *moduleInstance, const mxArray *st)
{
  emlrtStack b_st = { NULL,            /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  b_st.tls = moduleInstance->emlrtRootTLSGlobal;
  emlrt_marshallIn(moduleInstance, &b_st, emlrtAlias(st));
  emlrtDestroyArray(&st);
}

static const mxArray *message(const emlrtStack *sp, const mxArray *m1, const
  mxArray *m2, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m;
  pArrays[0] = m1;
  pArrays[1] = m2;
  return emlrtCallMATLABR2012b((emlrtConstCTX)sp, 1, &m, 2, &pArrays[0],
    "message", true, location);
}

static const mxArray *getString(const emlrtStack *sp, const mxArray *m1,
  emlrtMCInfo *location)
{
  const mxArray *m;
  const mxArray *pArray;
  pArray = m1;
  return emlrtCallMATLABR2012b((emlrtConstCTX)sp, 1, &m, 1, &pArray, "getString",
    true, location);
}

static void error(const emlrtStack *sp, const mxArray *m, const mxArray *m1,
                  emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  pArrays[0] = m;
  pArrays[1] = m1;
  emlrtCallMATLABR2012b((emlrtConstCTX)sp, 0, NULL, 2, &pArrays[0], "error",
                        true, location);
}

static int32_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  int32_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "int32", false, 0U, (
    const void *)&dims);
  ret = *(int32_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static boolean_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  boolean_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "logical", false, 0U, (
    const void *)&dims);
  ret = *emlrtMxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void init_simulink_io_address(InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = (void *)cgxertGetEMLRTCtx
    (moduleInstance->S);
  moduleInstance->u0 = (real_T (*)[7])cgxertGetInputPortSignal(moduleInstance->S,
    0);
  moduleInstance->u1 = (real_T (*)[9])cgxertGetInputPortSignal(moduleInstance->S,
    1);
  moduleInstance->u2 = (real_T (*)[49])cgxertGetInputPortSignal
    (moduleInstance->S, 2);
  moduleInstance->u3 = (real_T (*)[81])cgxertGetInputPortSignal
    (moduleInstance->S, 3);
  moduleInstance->covInst_CONTAINER_BLOCK_INDEX = (covrtInstance *)
    cgxertGetCovrtInstance(moduleInstance->S, -1);
}

/* CGXE Glue Code */
static void mdlOutputs_T3eFG2ybNxqtnQCo5Gn1r(SimStruct *S, int_T tid)
{
  InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r *moduleInstance =
    (InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_T3eFG2ybNxqtnQCo5Gn1r(SimStruct *S)
{
  InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r *moduleInstance =
    (InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_T3eFG2ybNxqtnQCo5Gn1r(SimStruct *S, int_T tid)
{
  InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r *moduleInstance =
    (InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_T3eFG2ybNxqtnQCo5Gn1r(SimStruct *S)
{
  InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r *moduleInstance =
    (InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static mxArray* getSimState_T3eFG2ybNxqtnQCo5Gn1r(SimStruct *S)
{
  mxArray* mxSS;
  InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r *moduleInstance =
    (InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r *)cgxertGetRuntimeInstance(S);
  mxSS = (mxArray *) cgxe_mdl_get_sim_state(moduleInstance);
  return mxSS;
}

static void setSimState_T3eFG2ybNxqtnQCo5Gn1r(SimStruct *S, const mxArray *ss)
{
  InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r *moduleInstance =
    (InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_set_sim_state(moduleInstance, emlrtAlias(ss));
}

static void mdlTerminate_T3eFG2ybNxqtnQCo5Gn1r(SimStruct *S)
{
  InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r *moduleInstance =
    (InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_T3eFG2ybNxqtnQCo5Gn1r(SimStruct *S)
{
  InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r *moduleInstance =
    (InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_T3eFG2ybNxqtnQCo5Gn1r(SimStruct *S)
{
  InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r *moduleInstance =
    (InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_T3eFG2ybNxqtnQCo5Gn1r(SimStruct *S)
{
  InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r *moduleInstance =
    (InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r *)calloc(1, sizeof
    (InstanceStruct_T3eFG2ybNxqtnQCo5Gn1r));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_T3eFG2ybNxqtnQCo5Gn1r);
  ssSetmdlInitializeConditions(S, mdlInitialize_T3eFG2ybNxqtnQCo5Gn1r);
  ssSetmdlUpdate(S, mdlUpdate_T3eFG2ybNxqtnQCo5Gn1r);
  ssSetmdlDerivatives(S, mdlDerivatives_T3eFG2ybNxqtnQCo5Gn1r);
  ssSetmdlTerminate(S, mdlTerminate_T3eFG2ybNxqtnQCo5Gn1r);
  ssSetmdlEnable(S, mdlEnable_T3eFG2ybNxqtnQCo5Gn1r);
  ssSetmdlDisable(S, mdlDisable_T3eFG2ybNxqtnQCo5Gn1r);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_T3eFG2ybNxqtnQCo5Gn1r(SimStruct *S)
{
}

void method_dispatcher_T3eFG2ybNxqtnQCo5Gn1r(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_T3eFG2ybNxqtnQCo5Gn1r(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_T3eFG2ybNxqtnQCo5Gn1r(S);
    break;

   case SS_CALL_MDL_GET_SIM_STATE:
    *((mxArray**) data) = getSimState_T3eFG2ybNxqtnQCo5Gn1r(S);
    break;

   case SS_CALL_MDL_SET_SIM_STATE:
    setSimState_T3eFG2ybNxqtnQCo5Gn1r(S, (const mxArray *) data);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: T3eFG2ybNxqtnQCo5Gn1r.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_T3eFG2ybNxqtnQCo5Gn1r_BuildInfoUpdate(void)
{
  mxArray * mxBIArgs;
  mxArray * elem_1;
  mxArray * elem_2;
  mxArray * elem_3;
  mxArray * elem_4;
  mxArray * elem_5;
  mxArray * elem_6;
  mxArray * elem_7;
  mxArray * elem_8;
  mxArray * elem_9;
  mxArray * elem_10;
  mxBIArgs = mxCreateCellMatrix(1,3);
  elem_1 = mxCreateCellMatrix(1,6);
  elem_2 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,0,elem_2);
  elem_3 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,1,elem_3);
  elem_4 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,2,elem_4);
  elem_5 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,3,elem_5);
  elem_6 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,4,elem_6);
  elem_7 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,5,elem_7);
  mxSetCell(mxBIArgs,0,elem_1);
  elem_8 = mxCreateCellMatrix(1,1);
  elem_9 = mxCreateString("LoggerBlock");
  mxSetCell(elem_8,0,elem_9);
  mxSetCell(mxBIArgs,1,elem_8);
  elem_10 = mxCreateCellMatrix(1,0);
  mxSetCell(mxBIArgs,2,elem_10);
  return mxBIArgs;
}

mxArray *cgxe_T3eFG2ybNxqtnQCo5Gn1r_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("thirdPartyLibs");
  mxArray* incompatibleSymbol = mxCreateString("LoggerBlock");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
