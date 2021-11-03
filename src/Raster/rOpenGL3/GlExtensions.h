#pragma once

#define GLAPIENTRY APIENTRY

/* ----------------------------- GL_ARB_imaging ---------------------------- */

#ifndef GL_ARB_imaging
#define GL_ARB_imaging 1

#define GL_CONSTANT_COLOR 0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR 0x8002
#define GL_CONSTANT_ALPHA 0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA 0x8004
#define GL_BLEND_COLOR 0x8005
#define GL_FUNC_ADD 0x8006
#define GL_MIN 0x8007
#define GL_MAX 0x8008
#define GL_BLEND_EQUATION 0x8009
#define GL_FUNC_SUBTRACT 0x800A
#define GL_FUNC_REVERSE_SUBTRACT 0x800B
#define GL_CONVOLUTION_1D 0x8010
#define GL_CONVOLUTION_2D 0x8011
#define GL_SEPARABLE_2D 0x8012
#define GL_CONVOLUTION_BORDER_MODE 0x8013
#define GL_CONVOLUTION_FILTER_SCALE 0x8014
#define GL_CONVOLUTION_FILTER_BIAS 0x8015
#define GL_REDUCE 0x8016
#define GL_CONVOLUTION_FORMAT 0x8017
#define GL_CONVOLUTION_WIDTH 0x8018
#define GL_CONVOLUTION_HEIGHT 0x8019
#define GL_MAX_CONVOLUTION_WIDTH 0x801A
#define GL_MAX_CONVOLUTION_HEIGHT 0x801B
#define GL_POST_CONVOLUTION_RED_SCALE 0x801C
#define GL_POST_CONVOLUTION_GREEN_SCALE 0x801D
#define GL_POST_CONVOLUTION_BLUE_SCALE 0x801E
#define GL_POST_CONVOLUTION_ALPHA_SCALE 0x801F
#define GL_POST_CONVOLUTION_RED_BIAS 0x8020
#define GL_POST_CONVOLUTION_GREEN_BIAS 0x8021
#define GL_POST_CONVOLUTION_BLUE_BIAS 0x8022
#define GL_POST_CONVOLUTION_ALPHA_BIAS 0x8023
#define GL_HISTOGRAM 0x8024
#define GL_PROXY_HISTOGRAM 0x8025
#define GL_HISTOGRAM_WIDTH 0x8026
#define GL_HISTOGRAM_FORMAT 0x8027
#define GL_HISTOGRAM_RED_SIZE 0x8028
#define GL_HISTOGRAM_GREEN_SIZE 0x8029
#define GL_HISTOGRAM_BLUE_SIZE 0x802A
#define GL_HISTOGRAM_ALPHA_SIZE 0x802B
#define GL_HISTOGRAM_LUMINANCE_SIZE 0x802C
#define GL_HISTOGRAM_SINK 0x802D
#define GL_MINMAX 0x802E
#define GL_MINMAX_FORMAT 0x802F
#define GL_MINMAX_SINK 0x8030
#define GL_TABLE_TOO_LARGE 0x8031
#define GL_COLOR_MATRIX 0x80B1
#define GL_COLOR_MATRIX_STACK_DEPTH 0x80B2
#define GL_MAX_COLOR_MATRIX_STACK_DEPTH 0x80B3
#define GL_POST_COLOR_MATRIX_RED_SCALE 0x80B4
#define GL_POST_COLOR_MATRIX_GREEN_SCALE 0x80B5
#define GL_POST_COLOR_MATRIX_BLUE_SCALE 0x80B6
#define GL_POST_COLOR_MATRIX_ALPHA_SCALE 0x80B7
#define GL_POST_COLOR_MATRIX_RED_BIAS 0x80B8
#define GL_POST_COLOR_MATRIX_GREEN_BIAS 0x80B9
#define GL_POST_COLOR_MATRIX_BLUE_BIAS 0x80BA
#define GL_POST_COLOR_MATRIX_ALPHA_BIAS 0x80BB
#define GL_COLOR_TABLE 0x80D0
#define GL_POST_CONVOLUTION_COLOR_TABLE 0x80D1
#define GL_POST_COLOR_MATRIX_COLOR_TABLE 0x80D2
#define GL_PROXY_COLOR_TABLE 0x80D3
#define GL_PROXY_POST_CONVOLUTION_COLOR_TABLE 0x80D4
#define GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE 0x80D5
#define GL_COLOR_TABLE_SCALE 0x80D6
#define GL_COLOR_TABLE_BIAS 0x80D7
#define GL_COLOR_TABLE_FORMAT 0x80D8
#define GL_COLOR_TABLE_WIDTH 0x80D9
#define GL_COLOR_TABLE_RED_SIZE 0x80DA
#define GL_COLOR_TABLE_GREEN_SIZE 0x80DB
#define GL_COLOR_TABLE_BLUE_SIZE 0x80DC
#define GL_COLOR_TABLE_ALPHA_SIZE 0x80DD
#define GL_COLOR_TABLE_LUMINANCE_SIZE 0x80DE
#define GL_COLOR_TABLE_INTENSITY_SIZE 0x80DF
#define GL_IGNORE_BORDER 0x8150
#define GL_CONSTANT_BORDER 0x8151
#define GL_WRAP_BORDER 0x8152
#define GL_REPLICATE_BORDER 0x8153
#define GL_CONVOLUTION_BORDER_COLOR 0x8154

typedef void (GLAPIENTRY *PFNGLCOLORSUBTABLEPROC) (GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const void *data);
typedef void (GLAPIENTRY *PFNGLCOLORTABLEPROC) (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void *table);
typedef void (GLAPIENTRY *PFNGLCOLORTABLEPARAMETERFVPROC) (GLenum target, GLenum pname, const GLfloat *params);
typedef void (GLAPIENTRY *PFNGLCOLORTABLEPARAMETERIVPROC) (GLenum target, GLenum pname, const GLint *params);
typedef void (GLAPIENTRY *PFNGLCONVOLUTIONFILTER1DPROC) (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void *image);
typedef void (GLAPIENTRY *PFNGLCONVOLUTIONFILTER2DPROC) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *image);
typedef void (GLAPIENTRY *PFNGLCONVOLUTIONPARAMETERFPROC) (GLenum target, GLenum pname, GLfloat params);
typedef void (GLAPIENTRY *PFNGLCONVOLUTIONPARAMETERFVPROC) (GLenum target, GLenum pname, const GLfloat *params);
typedef void (GLAPIENTRY *PFNGLCONVOLUTIONPARAMETERIPROC) (GLenum target, GLenum pname, GLint params);
typedef void (GLAPIENTRY *PFNGLCONVOLUTIONPARAMETERIVPROC) (GLenum target, GLenum pname, const GLint *params);
typedef void (GLAPIENTRY *PFNGLCOPYCOLORSUBTABLEPROC) (GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
typedef void (GLAPIENTRY *PFNGLCOPYCOLORTABLEPROC) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
typedef void (GLAPIENTRY *PFNGLCOPYCONVOLUTIONFILTER1DPROC) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
typedef void (GLAPIENTRY *PFNGLCOPYCONVOLUTIONFILTER2DPROC) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (GLAPIENTRY *PFNGLGETCOLORTABLEPROC) (GLenum target, GLenum format, GLenum type, void *table);
typedef void (GLAPIENTRY *PFNGLGETCOLORTABLEPARAMETERFVPROC) (GLenum target, GLenum pname, GLfloat *params);
typedef void (GLAPIENTRY *PFNGLGETCOLORTABLEPARAMETERIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (GLAPIENTRY *PFNGLGETCONVOLUTIONFILTERPROC) (GLenum target, GLenum format, GLenum type, void *image);
typedef void (GLAPIENTRY *PFNGLGETCONVOLUTIONPARAMETERFVPROC) (GLenum target, GLenum pname, GLfloat *params);
typedef void (GLAPIENTRY *PFNGLGETCONVOLUTIONPARAMETERIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (GLAPIENTRY *PFNGLGETHISTOGRAMPROC) (GLenum target, GLboolean reset, GLenum format, GLenum type, void *values);
typedef void (GLAPIENTRY *PFNGLGETHISTOGRAMPARAMETERFVPROC) (GLenum target, GLenum pname, GLfloat *params);
typedef void (GLAPIENTRY *PFNGLGETHISTOGRAMPARAMETERIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (GLAPIENTRY *PFNGLGETMINMAXPROC) (GLenum target, GLboolean reset, GLenum format, GLenum types, void *values);
typedef void (GLAPIENTRY *PFNGLGETMINMAXPARAMETERFVPROC) (GLenum target, GLenum pname, GLfloat *params);
typedef void (GLAPIENTRY *PFNGLGETMINMAXPARAMETERIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (GLAPIENTRY *PFNGLGETSEPARABLEFILTERPROC) (GLenum target, GLenum format, GLenum type, void *row, void *column, void *span);
typedef void (GLAPIENTRY *PFNGLHISTOGRAMPROC) (GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
typedef void (GLAPIENTRY *PFNGLMINMAXPROC) (GLenum target, GLenum internalformat, GLboolean sink);
typedef void (GLAPIENTRY *PFNGLRESETHISTOGRAMPROC) (GLenum target);
typedef void (GLAPIENTRY *PFNGLRESETMINMAXPROC) (GLenum target);
typedef void (GLAPIENTRY *PFNGLSEPARABLEFILTER2DPROC) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *row, const void *column);

#endif /* GL_ARB_imaging */

/* -------------------------- GL_ARB_multitexture -------------------------- */

#ifndef GL_ARB_multitexture
#define GL_ARB_multitexture 1

#define GL_TEXTURE0_ARB 0x84C0
#define GL_TEXTURE1_ARB 0x84C1
#define GL_TEXTURE2_ARB 0x84C2
#define GL_TEXTURE3_ARB 0x84C3
#define GL_TEXTURE4_ARB 0x84C4
#define GL_TEXTURE5_ARB 0x84C5
#define GL_TEXTURE6_ARB 0x84C6
#define GL_TEXTURE7_ARB 0x84C7
#define GL_TEXTURE8_ARB 0x84C8
#define GL_TEXTURE9_ARB 0x84C9
#define GL_TEXTURE10_ARB 0x84CA
#define GL_TEXTURE11_ARB 0x84CB
#define GL_TEXTURE12_ARB 0x84CC
#define GL_TEXTURE13_ARB 0x84CD
#define GL_TEXTURE14_ARB 0x84CE
#define GL_TEXTURE15_ARB 0x84CF
#define GL_TEXTURE16_ARB 0x84D0
#define GL_TEXTURE17_ARB 0x84D1
#define GL_TEXTURE18_ARB 0x84D2
#define GL_TEXTURE19_ARB 0x84D3
#define GL_TEXTURE20_ARB 0x84D4
#define GL_TEXTURE21_ARB 0x84D5
#define GL_TEXTURE22_ARB 0x84D6
#define GL_TEXTURE23_ARB 0x84D7
#define GL_TEXTURE24_ARB 0x84D8
#define GL_TEXTURE25_ARB 0x84D9
#define GL_TEXTURE26_ARB 0x84DA
#define GL_TEXTURE27_ARB 0x84DB
#define GL_TEXTURE28_ARB 0x84DC
#define GL_TEXTURE29_ARB 0x84DD
#define GL_TEXTURE30_ARB 0x84DE
#define GL_TEXTURE31_ARB 0x84DF
#define GL_ACTIVE_TEXTURE_ARB 0x84E0
#define GL_CLIENT_ACTIVE_TEXTURE_ARB 0x84E1
#define GL_MAX_TEXTURE_UNITS_ARB 0x84E2

typedef void (GLAPIENTRY *PFNGLACTIVETEXTUREARBPROC) (GLenum texture);
typedef void (GLAPIENTRY *PFNGLCLIENTACTIVETEXTUREARBPROC) (GLenum texture);
typedef void (GLAPIENTRY *PFNGLMULTITEXCOORD1DARBPROC) (GLenum target, GLdouble s);
typedef void (GLAPIENTRY *PFNGLMULTITEXCOORD1DVARBPROC) (GLenum target, const GLdouble *v);
typedef void (GLAPIENTRY *PFNGLMULTITEXCOORD1FARBPROC) (GLenum target, GLfloat s);
typedef void (GLAPIENTRY *PFNGLMULTITEXCOORD1FVARBPROC) (GLenum target, const GLfloat *v);
typedef void (GLAPIENTRY *PFNGLMULTITEXCOORD1IARBPROC) (GLenum target, GLint s);
typedef void (GLAPIENTRY *PFNGLMULTITEXCOORD1IVARBPROC) (GLenum target, const GLint *v);
typedef void (GLAPIENTRY *PFNGLMULTITEXCOORD1SARBPROC) (GLenum target, GLshort s);
typedef void (GLAPIENTRY *PFNGLMULTITEXCOORD1SVARBPROC) (GLenum target, const GLshort *v);
typedef void (GLAPIENTRY *PFNGLMULTITEXCOORD2DARBPROC) (GLenum target, GLdouble s, GLdouble t);
typedef void (GLAPIENTRY *PFNGLMULTITEXCOORD2DVARBPROC) (GLenum target, const GLdouble *v);
typedef void (GLAPIENTRY *PFNGLMULTITEXCOORD2FARBPROC) (GLenum target, GLfloat s, GLfloat t);
typedef void (GLAPIENTRY *PFNGLMULTITEXCOORD2FVARBPROC) (GLenum target, const GLfloat *v);
typedef void (GLAPIENTRY *PFNGLMULTITEXCOORD2IARBPROC) (GLenum target, GLint s, GLint t);
typedef void (GLAPIENTRY *PFNGLMULTITEXCOORD2IVARBPROC) (GLenum target, const GLint *v);
typedef void (GLAPIENTRY *PFNGLMULTITEXCOORD2SARBPROC) (GLenum target, GLshort s, GLshort t);
typedef void (GLAPIENTRY *PFNGLMULTITEXCOORD2SVARBPROC) (GLenum target, const GLshort *v);
typedef void (GLAPIENTRY *PFNGLMULTITEXCOORD3DARBPROC) (GLenum target, GLdouble s, GLdouble t, GLdouble r);
typedef void (GLAPIENTRY *PFNGLMULTITEXCOORD3DVARBPROC) (GLenum target, const GLdouble *v);
typedef void (GLAPIENTRY *PFNGLMULTITEXCOORD3FARBPROC) (GLenum target, GLfloat s, GLfloat t, GLfloat r);
typedef void (GLAPIENTRY *PFNGLMULTITEXCOORD3FVARBPROC) (GLenum target, const GLfloat *v);
typedef void (GLAPIENTRY *PFNGLMULTITEXCOORD3IARBPROC) (GLenum target, GLint s, GLint t, GLint r);
typedef void (GLAPIENTRY *PFNGLMULTITEXCOORD3IVARBPROC) (GLenum target, const GLint *v);
typedef void (GLAPIENTRY *PFNGLMULTITEXCOORD3SARBPROC) (GLenum target, GLshort s, GLshort t, GLshort r);
typedef void (GLAPIENTRY *PFNGLMULTITEXCOORD3SVARBPROC) (GLenum target, const GLshort *v);
typedef void (GLAPIENTRY *PFNGLMULTITEXCOORD4DARBPROC) (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
typedef void (GLAPIENTRY *PFNGLMULTITEXCOORD4DVARBPROC) (GLenum target, const GLdouble *v);
typedef void (GLAPIENTRY *PFNGLMULTITEXCOORD4FARBPROC) (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
typedef void (GLAPIENTRY *PFNGLMULTITEXCOORD4FVARBPROC) (GLenum target, const GLfloat *v);
typedef void (GLAPIENTRY *PFNGLMULTITEXCOORD4IARBPROC) (GLenum target, GLint s, GLint t, GLint r, GLint q);
typedef void (GLAPIENTRY *PFNGLMULTITEXCOORD4IVARBPROC) (GLenum target, const GLint *v);
typedef void (GLAPIENTRY *PFNGLMULTITEXCOORD4SARBPROC) (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
typedef void (GLAPIENTRY *PFNGLMULTITEXCOORD4SVARBPROC) (GLenum target, const GLshort *v);

#endif /* GL_ARB_multitexture */

/* ---------------------------- GL_EXT_fog_coord --------------------------- */

#ifndef GL_EXT_fog_coord
#define GL_EXT_fog_coord 1

#define GL_FOG_COORDINATE_SOURCE_EXT 0x8450
#define GL_FOG_COORDINATE_EXT 0x8451
#define GL_FRAGMENT_DEPTH_EXT 0x8452
#define GL_CURRENT_FOG_COORDINATE_EXT 0x8453
#define GL_FOG_COORDINATE_ARRAY_TYPE_EXT 0x8454
#define GL_FOG_COORDINATE_ARRAY_STRIDE_EXT 0x8455
#define GL_FOG_COORDINATE_ARRAY_POINTER_EXT 0x8456
#define GL_FOG_COORDINATE_ARRAY_EXT 0x8457

typedef void (GLAPIENTRY *PFNGLFOGCOORDPOINTEREXTPROC) (GLenum type, GLsizei stride, const void *pointer);
typedef void (GLAPIENTRY *PFNGLFOGCOORDDEXTPROC) (GLdouble coord);
typedef void (GLAPIENTRY *PFNGLFOGCOORDDVEXTPROC) (const GLdouble *coord);
typedef void (GLAPIENTRY *PFNGLFOGCOORDFEXTPROC) (GLfloat coord);
typedef void (GLAPIENTRY *PFNGLFOGCOORDFVEXTPROC) (const GLfloat *coord);

#endif /* GL_EXT_fog_coord */

/* -------------------------- GL_KTX_buffer_region ------------------------- */

#ifndef GL_KTX_buffer_region
#define GL_KTX_buffer_region 1

#define GL_KTX_FRONT_REGION 0x0
#define GL_KTX_BACK_REGION 0x1
#define GL_KTX_Z_REGION 0x2
#define GL_KTX_STENCIL_REGION 0x3

typedef GLuint(GLAPIENTRY *PFNGLBUFFERREGIONENABLEDPROC) (void);
typedef void (GLAPIENTRY *PFNGLDELETEBUFFERREGIONPROC) (GLenum region);
typedef void (GLAPIENTRY *PFNGLDRAWBUFFERREGIONPROC) (GLuint region, GLint x, GLint y, GLsizei width, GLsizei height, GLint xDest, GLint yDest);
typedef GLuint(GLAPIENTRY *PFNGLNEWBUFFERREGIONPROC) (GLenum region);
typedef void (GLAPIENTRY *PFNGLREADBUFFERREGIONPROC) (GLuint region, GLint x, GLint y, GLsizei width, GLsizei height);

#endif /* GL_KTX_buffer_region */

/* ----------------------- GL_ARB_texture_compression ---------------------- */

#ifndef GL_ARB_texture_compression
#define GL_ARB_texture_compression 1

#define GL_COMPRESSED_ALPHA_ARB 0x84E9
#define GL_COMPRESSED_LUMINANCE_ARB 0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA_ARB 0x84EB
#define GL_COMPRESSED_INTENSITY_ARB 0x84EC
#define GL_COMPRESSED_RGB_ARB 0x84ED
#define GL_COMPRESSED_RGBA_ARB 0x84EE
#define GL_TEXTURE_COMPRESSION_HINT_ARB 0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE_ARB 0x86A0
#define GL_TEXTURE_COMPRESSED_ARB 0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB 0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS_ARB 0x86A3

typedef void (GLAPIENTRY *PFNGLCOMPRESSEDTEXIMAGE1DARBPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
typedef void (GLAPIENTRY *PFNGLCOMPRESSEDTEXIMAGE2DARBPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
typedef void (GLAPIENTRY *PFNGLCOMPRESSEDTEXIMAGE3DARBPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
typedef void (GLAPIENTRY *PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
typedef void (GLAPIENTRY *PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
typedef void (GLAPIENTRY *PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
typedef void (GLAPIENTRY *PFNGLGETCOMPRESSEDTEXIMAGEARBPROC) (GLenum target, GLint lod, void *img);

#endif /* GL_ARB_texture_compression */

/* ------------------------ GL_NV_register_combiners ----------------------- */

#ifndef GL_NV_register_combiners
#define GL_NV_register_combiners 1

#define GL_REGISTER_COMBINERS_NV 0x8522
#define GL_VARIABLE_A_NV 0x8523
#define GL_VARIABLE_B_NV 0x8524
#define GL_VARIABLE_C_NV 0x8525
#define GL_VARIABLE_D_NV 0x8526
#define GL_VARIABLE_E_NV 0x8527
#define GL_VARIABLE_F_NV 0x8528
#define GL_VARIABLE_G_NV 0x8529
#define GL_CONSTANT_COLOR0_NV 0x852A
#define GL_CONSTANT_COLOR1_NV 0x852B
#define GL_PRIMARY_COLOR_NV 0x852C
#define GL_SECONDARY_COLOR_NV 0x852D
#define GL_SPARE0_NV 0x852E
#define GL_SPARE1_NV 0x852F
#define GL_DISCARD_NV 0x8530
#define GL_E_TIMES_F_NV 0x8531
#define GL_SPARE0_PLUS_SECONDARY_COLOR_NV 0x8532
#define GL_UNSIGNED_IDENTITY_NV 0x8536
#define GL_UNSIGNED_INVERT_NV 0x8537
#define GL_EXPAND_NORMAL_NV 0x8538
#define GL_EXPAND_NEGATE_NV 0x8539
#define GL_HALF_BIAS_NORMAL_NV 0x853A
#define GL_HALF_BIAS_NEGATE_NV 0x853B
#define GL_SIGNED_IDENTITY_NV 0x853C
#define GL_SIGNED_NEGATE_NV 0x853D
#define GL_SCALE_BY_TWO_NV 0x853E
#define GL_SCALE_BY_FOUR_NV 0x853F
#define GL_SCALE_BY_ONE_HALF_NV 0x8540
#define GL_BIAS_BY_NEGATIVE_ONE_HALF_NV 0x8541
#define GL_COMBINER_INPUT_NV 0x8542
#define GL_COMBINER_MAPPING_NV 0x8543
#define GL_COMBINER_COMPONENT_USAGE_NV 0x8544
#define GL_COMBINER_AB_DOT_PRODUCT_NV 0x8545
#define GL_COMBINER_CD_DOT_PRODUCT_NV 0x8546
#define GL_COMBINER_MUX_SUM_NV 0x8547
#define GL_COMBINER_SCALE_NV 0x8548
#define GL_COMBINER_BIAS_NV 0x8549
#define GL_COMBINER_AB_OUTPUT_NV 0x854A
#define GL_COMBINER_CD_OUTPUT_NV 0x854B
#define GL_COMBINER_SUM_OUTPUT_NV 0x854C
#define GL_MAX_GENERAL_COMBINERS_NV 0x854D
#define GL_NUM_GENERAL_COMBINERS_NV 0x854E
#define GL_COLOR_SUM_CLAMP_NV 0x854F
#define GL_COMBINER0_NV 0x8550
#define GL_COMBINER1_NV 0x8551
#define GL_COMBINER2_NV 0x8552
#define GL_COMBINER3_NV 0x8553
#define GL_COMBINER4_NV 0x8554
#define GL_COMBINER5_NV 0x8555
#define GL_COMBINER6_NV 0x8556
#define GL_COMBINER7_NV 0x8557

typedef void (GLAPIENTRY *PFNGLCOMBINERINPUTNVPROC) (GLenum stage, GLenum portion, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
typedef void (GLAPIENTRY *PFNGLCOMBINEROUTPUTNVPROC) (GLenum stage, GLenum portion, GLenum abOutput, GLenum cdOutput, GLenum sumOutput, GLenum scale, GLenum bias, GLboolean abDotProduct, GLboolean cdDotProduct, GLboolean muxSum);
typedef void (GLAPIENTRY *PFNGLCOMBINERPARAMETERFNVPROC) (GLenum pname, GLfloat param);
typedef void (GLAPIENTRY *PFNGLCOMBINERPARAMETERFVNVPROC) (GLenum pname, const GLfloat *params);
typedef void (GLAPIENTRY *PFNGLCOMBINERPARAMETERINVPROC) (GLenum pname, GLint param);
typedef void (GLAPIENTRY *PFNGLCOMBINERPARAMETERIVNVPROC) (GLenum pname, const GLint *params);
typedef void (GLAPIENTRY *PFNGLFINALCOMBINERINPUTNVPROC) (GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
typedef void (GLAPIENTRY *PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC) (GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat *params);
typedef void (GLAPIENTRY *PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC) (GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint *params);
typedef void (GLAPIENTRY *PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC) (GLenum stage, GLenum portion, GLenum pname, GLfloat *params);
typedef void (GLAPIENTRY *PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC) (GLenum stage, GLenum portion, GLenum pname, GLint *params);
typedef void (GLAPIENTRY *PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC) (GLenum variable, GLenum pname, GLfloat *params);
typedef void (GLAPIENTRY *PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC) (GLenum variable, GLenum pname, GLint *params);

#endif /* GL_NV_register_combiners */

/* ----------------------- WGL_EXT_extensions_string ----------------------- */

#ifndef WGL_EXT_extensions_string
#define WGL_EXT_extensions_string 1

typedef const char *(WINAPI *PFNWGLGETEXTENSIONSSTRINGEXTPROC) (void);

#endif /* WGL_EXT_extensions_string */

/* -------------------------- WGL_EXT_swap_control ------------------------- */

#ifndef WGL_EXT_swap_control
#define WGL_EXT_swap_control 1

typedef int (WINAPI *PFNWGLGETSWAPINTERVALEXTPROC) (void);
typedef BOOL(WINAPI *PFNWGLSWAPINTERVALEXTPROC) (int interval);

#endif /* WGL_EXT_swap_control */

#ifdef __cplusplus
extern "C" {
#endif

/*
* Module:                 rOpenGL.dll
* Data address:           0x100517E0
*/
extern PFNGLCOLORTABLEEXTPROC glColorTableEXT;

/*
* Module:                 rOpenGL.dll
* Data address:           0x100517E4
*/
extern PFNGLCOLORSUBTABLEEXTPROC glColorSubTableEXT;

/*
* Module:                 rOpenGL.dll
* Data address:           0x100517E8
*/
extern PFNGLGETCOLORTABLEEXTPROC glGetColorTableEXT;

/*
* Module:                 rOpenGL.dll
* Data address:           0x100517EC
*/
extern PFNGLGETCOLORTABLEPARAMETERIVPROC glGetColorTableParameteriv;

/*
* Module:                 rOpenGL.dll
* Data address:           0x100517F0
*/
extern PFNGLGETCOLORTABLEPARAMETERFVPROC glGetColorTableParameterfv;

/*
* Module:                 rOpenGL.dll
* Data address:           0x100517F4
*/
extern PFNGLACTIVETEXTUREARBPROC glActiveTextureARB;

/*
* Module:                 rOpenGL.dll
* Data address:           0x100517F8
*/
extern PFNGLMULTITEXCOORD1FARBPROC glMultiTexCoord1fARB;

/*
* Module:                 rOpenGL.dll
* Data address:           0x100517FC
*/
extern PFNGLMULTITEXCOORD2FARBPROC glMultiTexCoord2fARB;

/*
* Module:                 rOpenGL.dll
* Data address:           0x10051800
*/
extern PFNGLMULTITEXCOORD2FVARBPROC glMultiTexCoord2fvARB;

/*
* Module:                 rOpenGL.dll
* Data address:           0x10051804
*/
extern PFNGLFOGCOORDFEXTPROC glFogCoordfEXT;

/*
* Module:                 rOpenGL.dll
* Data address:           0x10051808
*/
extern PFNGLFOGCOORDFVEXTPROC glFogCoordfvEXT;

/*
* Module:                 rOpenGL.dll
* Data address:           0x1005180C
*/
extern PFNGLGETCOLORTABLEEXTPROC glGetColorTableEXT2;

/*
* Module:                 rOpenGL.dll
* Data address:           0x10051810
*/
extern PFNGLFOGCOORDDVEXTPROC glFogCoorddvEXT;

/*
* Module:                 rOpenGL.dll
* Data address:           0x10051814
*/
extern PFNGLNEWBUFFERREGIONPROC glNewBufferRegion;

/*
* Module:                 rOpenGL.dll
* Data address:           0x10051818
*/
extern PFNGLDELETEBUFFERREGIONPROC glDeleteBufferRegion;

/*
* Module:                 rOpenGL.dll
* Data address:           0x1005181C
*/
extern PFNGLREADBUFFERREGIONPROC glReadBufferRegion;

/*
* Module:                 rOpenGL.dll
* Data address:           0x10051820
*/
extern PFNGLDRAWBUFFERREGIONPROC glDrawBufferRegion;

/*
* Module:                 rOpenGL.dll
* Data address:           0x10051824
*/
extern PFNGLBUFFERREGIONENABLEDPROC glBufferRegionEnabled;

/*
* Module:                 rOpenGL.dll
* Data address:           0x10051828
*/
extern PFNWGLGETEXTENSIONSSTRINGEXTPROC wglGetExtensionsStringEXT;

/*
* Module:                 rOpenGL.dll
* Data address:           0x1005182C
*/
extern PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT;

/*
* Module:                 rOpenGL.dll
* Data address:           0x10051830
*/
extern PFNWGLGETSWAPINTERVALEXTPROC wglGetSwapIntervalEXT;

/*
* Module:                 rOpenGL.dll
* Data address:           0x10051834
*/
extern PFNGLCOMPRESSEDTEXIMAGE3DARBPROC glCompressedTexImage3DARB;

/*
* Module:                 rOpenGL.dll
* Data address:           0x10051838
*/
extern PFNGLCOMPRESSEDTEXIMAGE2DARBPROC glCompressedTexImage2DARB;

/*
* Module:                 rOpenGL.dll
* Data address:           0x1005183C
*/
extern PFNGLCOMPRESSEDTEXIMAGE1DARBPROC glCompressedTexImage1DARB;

/*
* Module:                 rOpenGL.dll
* Data address:           0x10051840
*/
extern PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC glCompressedTexSubImage3DARB;

/*
* Module:                 rOpenGL.dll
* Data address:           0x10051844
*/
extern PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC glCompressedTexSubImage2DARB;

/*
* Module:                 rOpenGL.dll
* Data address:           0x10051848
*/
extern PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC glCompressedTexSubImage1DARB;

/*
* Module:                 rOpenGL.dll
* Data address:           0x1005184C
*/
extern PFNGLGETCOMPRESSEDTEXIMAGEARBPROC glGetCompressedTexImageARB;

/*
* Module:                 rOpenGL.dll
* Data address:           0x10051850
*/
extern PFNGLCOMBINERPARAMETERFVNVPROC glCombinerParameterfvNV;

/*
* Module:                 rOpenGL.dll
* Data address:           0x10051854
*/
extern PFNGLCOMBINERPARAMETERIVNVPROC glCombinerParameterivNV;

/*
* Module:                 rOpenGL.dll
* Data address:           0x10051858
*/
extern PFNGLCOMBINERPARAMETERFNVPROC glCombinerParameterfNV;

/*
* Module:                 rOpenGL.dll
* Data address:           0x1005185C
*/
extern PFNGLCOMBINERPARAMETERINVPROC glCombinerParameteriNV;

/*
* Module:                 rOpenGL.dll
* Data address:           0x10051860
*/
extern PFNGLCOMBINERINPUTNVPROC glCombinerInputNV;

/*
* Module:                 rOpenGL.dll
* Data address:           0x10051864
*/
extern PFNGLCOMBINEROUTPUTNVPROC glCombinerOutputNV;

/*
* Module:                 rOpenGL.dll
* Data address:           0x10051868
*/
extern PFNGLFINALCOMBINERINPUTNVPROC glFinalCombinerInputNV;

/*
* Module:                 rOpenGL.dll
* Data address:           0x1005186C
*/
extern PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC glGetCombinerInputParameterfvNV;

/*
* Module:                 rOpenGL.dll
* Data address:           0x10051870
*/
extern PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC glGetCombinerInputParameterivNV;

/*
* Module:                 rOpenGL.dll
* Data address:           0x10051874
*/
extern PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC glGetCombinerOutputParameterfvNV;

/*
* Module:                 rOpenGL.dll
* Data address:           0x10051878
*/
extern PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC glGetCombinerOutputParameterivNV;

/*
* Module:                 rOpenGL.dll
* Data address:           0x1005187C
*/
extern PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC glGetFinalCombinerInputfvNV;

/*
* Module:                 rOpenGL.dll
* Data address:           0x10051880
*/
extern PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC glGetFinalCombinerInputivNV;

#ifdef __cplusplus
}
#endif
