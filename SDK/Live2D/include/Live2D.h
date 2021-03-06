/**
 *  Live2D.h
 *
 *  Copyright(c) Live2D Inc. All rights reserved.
 *  [[ CONFIDENTIAL ]] 
 */

#ifndef __LIVE2D_H__
#define __LIVE2D_H__

//========================================================
//  Compile target
// 	?ã?ã­ã¸ã§ã¯ãã«å®ç¾©ããªã??å?ifå?ã³ã¡ã³ããå¤ã)
//========================================================
#if !( defined(L2D_TARGET_PSP) \
        || defined(L2D_TARGET_IPHONE)       \
		|| defined(L2D_TARGET_IPHONE_ES2) 	\
		|| defined(L2D_TARGET_MAC_OSX) 		\
		|| defined(L2D_TARGET_ANDROID) 	\
		|| defined(L2D_TARGET_ANDROID_ES2) 	\
		|| defined(L2D_TARGET_QT) 			\
		|| defined(L2D_TARGET_D3D) 			\
		|| defined(L2D_TARGET_D3D11) 		\
		|| defined(L2D_TARGET_WIN_GL) 		\
		|| defined(L2D_TARGET_3DS)          \
		|| defined(L2D_TARGET_PS3 ) 		\
		|| defined(L2D_TARGET_PS4 ) 		\
		|| defined(L2D_TARGET_VITA ) 		\
	)
	    //#define L2D_TARGET_PSP
	    //#define L2D_TARGET_IPHONE
	    //#define L2D_TARGET_IPHONE_ES2
	    //#define L2D_TARGET_MAC_OSX
	    //#define L2D_TARGET_ANDROID
	    //#define L2D_TARGET_ANDROID_ES2
	    //#define L2D_TARGET_QT
	    //#define L2D_TARGET_D3D
	    //#define L2D_TARGET_D3D11
	    //#define L2D_TARGET_WIN_GL
		//#define L2D_TARGET_3DS
		//#define L2D_TARGET_PS3
		//#define L2D_TARGET_PS4
		//#define L2D_TARGET_VITA
#endif

#if defined( L2D_TARGET_PSP )
#define __L2D_PLATFORM_STR__ ("PSP")
#elif defined( L2D_TARGET_IPHONE )
#define __L2D_PLATFORM_STR__ ("iPhone")
#elif defined( L2D_TARGET_IPHONE_ES2 )
#define __L2D_PLATFORM_STR__ ("iPhone ES2")
#elif defined( L2D_TARGET_MAC_OSX )
#define __L2D_PLATFORM_STR__ ("MacOSX")
#elif defined( L2D_TARGET_ANDROID )
#define __L2D_PLATFORM_STR__ ("Android")
#elif defined( L2D_TARGET_ANDROID_ES2 )
#define __L2D_PLATFORM_STR__ ("Android ES2")
#elif defined( L2D_TARGET_QT )
#define __L2D_PLATFORM_STR__ ("Qt")
#elif defined( L2D_TARGET_D3D )
#define __L2D_PLATFORM_STR__ ("DirectX")
#elif defined( L2D_TARGET_D3D_OPEN )
#define __L2D_PLATFORM_STR__ ("DirectX_OPEN")
#elif defined( L2D_TARGET_WIN_GL )
#define __L2D_PLATFORM_STR__ ("Windows OpenGL")
#elif defined( L2D_TARGET_3DS )
#define __L2D_PLATFORM_STR__ ("3DS")
#elif defined( L2D_TARGET_VITA )
#define __L2D_PLATFORM_STR__ ("Vita")
#elif defined( L2D_TARGET_PS3 )
#define __L2D_PLATFORM_STR__ ("PS3")
#elif defined( L2D_TARGET_PS4 )
#define __L2D_PLATFORM_STR__ ("PS4")
#endif


#if defined( L2D_TARGET_ANDROID ) || defined( L2D_TARGET_IPHONE )
#define L2D_GRAPHICS_OPENGL_ES1
#endif

#if defined( L2D_TARGET_ANDROID_ES2 ) || defined( L2D_TARGET_IPHONE_ES2 ) || defined( L2D_TARGET_WIN_GL )
#define L2D_GRAPHICS_OPENGL_ES2
#endif

//========================================================
//	Options
//========================================================
// Unityç¨ã«æ¸ãå?ãã¨ãã?1ã«ããªã?¨ã?¯ã¹ãã£ãªã©ãå´©ãããããããªã?
#define L2D_BUILD_FOR_UNITY			0

//------------ Debug options ---------------
#define L2D_SAMPLE			0	// ãµã³ãã«ã??ã¿ããã¹ãã¡ã½ã?ãªã©ãå©ç¨ããå ´åã« 1
#define L2D_VERBOSE			1	// ã¨ã©ã¼ã¡ã?»ã¼ã¸ãªã©ãã?ãã ãå?åã« 1

// ã?ã?°ç¨ãã©ã°ãéçºä¸­ã®ã¿1
#if defined( L2D_TARGET_IPHONE ) || defined ( DEBUG )
#  define L2D_DEBUG			1	
#elif defined( L2D_TARGET_3DS ) && defined ( NN_BUILD_DEBUG )
#  define L2D_DEBUG			1	
#elif defined ( _DEBUG )
#  define L2D_DEBUG			1	
#endif


#define L2D_TEMPORARY_DEBUG 0	// ä¸?ç?ªã?¹ãç¨

#define L2D_ALPHA_IMPL_LAYOUT 0 // ã¢ã?«ã«æ¡å¤§ç¸®å°ãè¨­å®ãããã¹ãå®è£?


//------------ Performance options ---------------
#define L2D_RANGE_CHECK		1	// éå?ã¸ã®ã¢ã¯ã»ã¹æã«ç¯?²ãã§ã?¯ãè¡ãå ´åã?1?ãã¾ãé?åº¦ã¯é«ããªã?¼?
#define L2D_RANGE_CHECK_POINT	1	// 0..1åºéã«åã¾ãã¹ãç¹ã®ãã§ã?¯ãè¡ãå ´åã?1ã??åº¦ãä½ä¸ããã?
									// ãã§ã?¯ãããªã?¨éå?ã«ä¸æ­£ã¢ã¯ã»ã¹ããå¯è½æ§ããã?(70%->72%ç¨åº¦ã«ã¢ã??ãã)
#define L2D_DEFORMER_EXTEND		1	// ã?ã©ã¼ããæ¡å¼µãã(SDK2.0)

#define L2D_FORCE_UPDATE	0	// ãã©ã¡ã¼ã¿ã®æ´æ°ã«é¢ä¿ãªãã?å¨ã¦ã®ãªãã¸ã§ã¯ããã¢ã??ã??ãããå?åã«1ã«ãã

//------------ Texture options ------------
#if defined( L2D_TARGET_IPHONE ) || defined( L2D_TARGET_ANDROID )
#  define L2D_INVERT_TEXTURE 0
#elif defined( L2D_TARGET_IPHONE_ES2 ) || defined( L2D_TARGET_ANDROID_ES2 ) || defined( L2D_TARGET_WIN_GL)
	#if L2D_BUILD_FOR_UNITY 
		#  define L2D_INVERT_TEXTURE 1
	#else
		#  define L2D_INVERT_TEXTURE 0
	#endif
#elif defined( L2D_TARGET_VITA ) || defined( L2D_TARGET_D3D11 ) || defined( L2D_TARGET_PS4 ) 
#  define L2D_INVERT_TEXTURE 0
#else
#  define L2D_INVERT_TEXTURE 1
#endif

//------------ Avatar options ------------
#define AVATAR_OPTION_A 1

//========================================================
//  Exception
//========================================================
#if defined( L2D_TARGET_PSP ) || defined ( L2D_TARGET_VITA ) || defined(L2D_TARGET_PS4 ) || defined(L2D_TARGET_3DS)	|| defined(L2D_TARGET_PS3 )
    #define L2D_THROW( c )	{}
#elif defined(L2D_TARGET_IPHONE_ES2)|| defined( L2D_TARGET_ANDROID_ES2 ) || defined( L2D_TARGET_ANDROID )
    #define L2D_THROW( c )	{}
#else
	#define L2D_THROW( c ) throw (c)
#endif

//========================================================
//  typedef
//========================================================
typedef float				l2d_uvmapf ;	// éå¸¸ float åã?uv mapå¤
typedef float				l2d_pointf ;	// éå¸¸ float åã?point å¤
typedef float				l2d_paramf ;	// éå¸¸ floatåã?ãã©ã¡ã¼ã¿å¤
typedef unsigned short		l2d_index ;		// ã¤ã³ã?ã¯ã¹éå?ã®å?
typedef signed short		l2d_order ;		// æç»é ?ºã?å?signed short)
typedef float				l2d_float ;		// éæ?åº¦ãªã©åºæ¬ç?ª float å?

#if defined(L2D_TARGET_IPHONE_ES2) || defined(L2D_TARGET_MAC_OSX)
typedef unsigned long       l2d_size_t ;	
#elif defined(L2D_TARGET_PS4)
typedef unsigned long       l2d_size_t ;	
#elif defined(L2D_TARGET_WIN_GL)
typedef size_t      l2d_size_t ;
#elif defined(L2D_TARGET_IPHONE)
#include <stdlib.h>
typedef size_t      l2d_size_t ;
#else
typedef unsigned int		l2d_size_t ;	// size_t äºæ, 64bitã§ã¯64bitã«ãã?æªå¯¾å¿ï¼?
#endif

// åºæ¬åï¼?Dxxx -> l2d_xxxã«ç§»è¡ï¼?
typedef bool				l2d_bool ;
typedef signed char			l2d_int8 ;
typedef unsigned char		l2d_uint8 ;

typedef signed short		l2d_int16 ;
typedef unsigned short		l2d_uint16 ;

typedef signed int			l2d_int32 ;
typedef unsigned int		l2d_uint32 ;

typedef signed long long	l2d_int64 ;
typedef unsigned long long	l2d_uint64 ;

// æ§åºæ¬åï¼äºææ§ç¶­æã?ããä¿æ??
typedef signed char			LDint8 ;
typedef unsigned char		LDuint8 ;

typedef signed short		LDint16 ;
typedef unsigned short		LDuint16 ;

typedef signed int			LDint32 ;
typedef unsigned int		LDuint32 ;

typedef signed long long	LDint64 ;
typedef unsigned long long	LDuint64 ;


// ---------- ç¯?²å¤ãã©ã¡ã¼ã¿ã®æ±ã? ----------
#define L2D_OUTSIDE_PARAM_AVAILABLE 0	// ãã©ã¡ã¼ã¿ãç¯?²å¤ã?ã¨ãæç»ãããªã?1	
//#define L2D_OUTSIDE_PARAM_BASE_AVAILABLE 1	// ãã©ã¡ã¼ã¿ãç¯?²å¤ã?ã¨ãåº§æ¨å¤æãæå¹ã«ãã 1



//========================================================
//	Compiler
//========================================================
#ifdef _MSC_VER
#pragma warning (disable : 4100)
#endif

#ifndef NULL
#  define NULL    0
#endif

//========================================================
//	Live2D
//========================================================
namespace live2d
{
    class LDAllocator;   
}

#include "memory/UtMemory.h"


//--------- LIVE2D NAMESPACE ------------
namespace live2d 
{
	
	class Live2D
	{
	public:
		//static const l2d_uint32 L2D_VERSION_NO 	= __L2D_VERSION_NO__ ;// ã­ã¼ãã¨ã©ã¼ãåé¿ããããä¿®æ­£

		//========================================================
		// 	ã¨ã©ã¼å®æ° Live2D::L2D_ERROR_XXX 
		// 	Live2D.getError()ã§è¿ããã
		//========================================================
		//   0- ã¨ã©ã¼ç¡ã?
		static const int L2D_NO_ERROR								= 0 ;

		// 1000- Live2Då¨è¬ã»åæåé¢é£
		static const int L2D_ERROR_LIVE2D_INIT_FAILED				= 1000 ;
		static const int L2D_ERROR_FILE_LOAD_FAILED					= 1001 ;
		static const int L2D_ERROR_MEMORY_ERROR						= 1100 ;

		// 2000- ã¢ã?«é¢é£ã¨ã©ã¼
		static const int L2D_ERROR_MODEL_DATA_VERSION_MISMATCH		= 2000 ;	// ãã?ã©ã¤ãã©ãªã§æªå¯¾å¿ãã¼ã¸ã§ã³ã®ã??ã¿
		static const int L2D_ERROR_MODEL_DATA_EOF_ERROR				= 2001 ;	// çµç«¯ãä¸æ­£

		// 3000- ã¢ã¼ã·ã§ã³é¢é£


		static const int L2D_COLOR_BLEND_MODE_MULT			= 0;
		static const int L2D_COLOR_BLEND_MODE_ADD			= 1;
		static const int L2D_COLOR_BLEND_MODE_INTERPOLATE	= 2;

		// Live2Dã®ã©ã¤ãã©ãªãå?æåãå©ç¨å¯è½ãªç¶æã«ãã¾ã?
		static void init( live2d::LDAllocator* allocator = NULL ) ;

		// Live2Dã®ã©ã¤ãã©ãªãã¯ã­ã¼ãºãã?å¨ã¦ã®ãªã½ã¼ã¹ãè§£æ¾ãã¾ã?
		// ãã ãã?å¤é¨ããè¨­å®ãããç»åãªã©ã®ãªã½ã¼ã¹ã¯è§£æ¾ãã¾ãã
		// å¤é¨ã§é©å?«ç ´æ£?ãå¿?¦ãããã¾ãã?
		static void dispose() ;

		// ãã?ã¸ã§ã³æ?­å?åå¾?
		static const char * getVersionStr() ;

		// ãã?ã¸ã§ã³åå¾?
		static l2d_uint32 getVersionNo() ;
		
		// ã©ã¤ãã©ãªãã«ãæã®è¨­å®ãç¢ºèªãã?
		static l2d_bool getBuildOption_RANGE_CHECK_POINT() ;
		static l2d_bool getBuildOption_AVATAR_OPTION_A() ;

		// é ç¹ã®ã?ã«ãããã¡ã®è¨­å®?
		
		static void setVertexDoubleBufferEnabled(l2d_bool enabled)
		{
			flag_vertexDoubleBufferEnabled = enabled ;
		}	


		
		static l2d_bool isVertexDoubleBufferEnabled()
		{
			return flag_vertexDoubleBufferEnabled ;
		}	

		// ã¨ã©ã¼è¨­å®?å?¨å¦ç?
		static void setError(l2d_uint32 errorNo) ;

		// ã¨ã©ã¼ã®åå¾?
		static l2d_uint32 getError() ;

	#ifdef L2D_TARGET_PSP
		// PSPã«ããã¦ããªã´ã³ã®æç»åã«é ç¹éå?ãã©ã¤ããã?¯ããå ´åã« trueãè¨­å®?0.9.00b15)
		static void setPSPWritebackEnabled_alphaImpl(l2d_bool enabled)
		{
			flag_PSPWritebackEnabled_alphaImpl = enabled ;
		}

		// PSPã«ããã¦ããªã´ã³ã®æç»åã«é ç¹éå?ãã©ã¤ããã?¯ããå ´åã« true(0.9.00b15)
		// ã?ã©ã«ãã? false 
		static l2d_bool isPSPWritebackEnabled_alphaImpl()
		{
			return flag_PSPWritebackEnabled_alphaImpl ;
		}
	#endif


	private:
		Live2D(){}							// ã¤ã³ã¹ã¿ã³ã¹åãããªã?

		// Prevention of copy Constructor
		Live2D( const Live2D & ) ;				
		Live2D& operator=( const Live2D & ) ;	
		~Live2D(){}

	private:
		//--- field ---
		static l2d_bool flag_first_init ;
		static l2d_bool flag_vertexDoubleBufferEnabled ;// 0.9.00b14 DDTextureã®ããªã´ã³ãããã«ãããã¡ããå ´åã«true

	#ifdef L2D_TARGET_PSP
		static l2d_bool flag_PSPWritebackEnabled_alphaImpl ;// 0.9.00b15 PSPã«ããã¦ããªã´ã³é ç¹ãã©ã¤ããã?¯ããå ´å?rue
	#endif

		static l2d_uint32	lastError ;
		static l2d_int32	initCount ;	// Live2D::init()ãè¤?°åçºçããã?ãé²ãã?Live2D::dispose()ãè¡ããã«init()ãè¤?°åè¡ã£ãå?åã?ç¡è¦ããã?

	};

}
//--------- LIVE2D NAMESPACE ------------


#endif		// __LIVE2D_H__
