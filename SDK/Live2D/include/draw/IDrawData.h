/**
 *  IDrawData.h
 *
 *  Copyright(c) Live2D Inc. All rights reserved.
 *  [[ CONFIDENTIAL ]]
 */

#ifndef __LIVE2D_IDRAWDATA_H__
#define __LIVE2D_IDRAWDATA_H__


#ifndef __SKIP_DOC__

#include "../Live2D.h"
#include "../io/ISerializableV2.h"
#include "../id/BaseDataID.h"
#include "IDrawContext.h"
#include <stdio.h>


//------------ LIVE2D NAMESPACE ------------
namespace live2d
{
	class DrawDataID ;
	class ModelContext ;
	class PivotManager ;
	class DrawParam ;

	
	class IDrawData : public ISerializableV2
	{
	public:
		static const int BASE_INDEX_NOT_INIT 	= -2 ;
		static const int DEFAULT_ORDER 			= 500 ;
		static const int TYPE_DD_TEXTURE 		= 2 ;
	public:	
		IDrawData();
		virtual ~IDrawData();
	
		virtual void readV2(BReader & br , MemoryParam* memParam ) ;
		
		// ãªã¼ãã?ã©ã¤ãä¸è¦?
		inline BaseDataID * getTargetBaseDataID(){ return targetBaseDataID ; } 
		inline void setTargetBaseDataID(BaseDataID *id){ targetBaseDataID = id ; } 
	
		bool needTransform()
		{ 
			return ( targetBaseDataID 
					&& (targetBaseDataID != BaseDataID::DST_BASE_ID() ) ) ;
		}
	
		//  æç»IDåå¾?	
		inline DrawDataID * getDrawDataID(){ return drawDataID ; } 

		//  æç»IDãã»ã?
		inline void setDrawDataID( DrawDataID *id ){ drawDataID = id ; } 
	
		//  ä¸é?æåº¦åå¾?
		inline float getOpacity( ModelContext &mdc , IDrawContext* cdata ){ return cdata->interpolatedOpacity ; }
	
		//  æç»ãªã¼ã??åå¾?
		inline int getDrawOrder(ModelContext &mdc , IDrawContext* cdata ){ return cdata->interpolatedDrawOrder ; }
		
		inline void setDrawOrder(LDVector<int>* orders )
		{
			for( int i = (int)orders->size()-1 ; i >= 0  ; --i )
			{
				int order = (*orders)[i] ;

				if( order < totalMinOrder ) 		totalMinOrder = order ;
				else if( order > totalMaxOrder ) 	totalMaxOrder = order ;// åæå¤ ãæã£ã¦ã?å ´åã? else ifã§ãã
			}
		} 
	
		
		inline static int getTotalMinOrder(){ return totalMinOrder ; } 
		inline static int getTotalMaxOrder(){ return totalMaxOrder ; } 
		
		// å??ç?¼?etupInterpolation/draw?ã§æ¯åã?å¿?¦ã?ãªã??ç?æ??ã«è¡ã
		// å?¨®ãã©ã¡ã¼ã¿ãè¨­å®ãããå¾ã«å¼ã³åºã?
		virtual IDrawContext* init(ModelContext &mdc) = 0;
		
		// drawã®åæ®µéã¨ãã¦ãè£éãè¡ã
		virtual void setupInterpolate(ModelContext &mdc , IDrawContext* cdata ) ;
		
		// drawã®åæ®µéã¨ãã¦ãå¤å½¢ãè¡ã
		virtual void setupTransform(ModelContext &mdc , IDrawContext* cdata ) ;
	
		// æç»ãè¡ã
		virtual void draw( DrawParam & dp , ModelContext &mdc , IDrawContext* cdata ) = 0 ;
	
		// IDrawDataã®åãè¿ããTYPE_DD_TEXTUREãªã©
		virtual int getType() ;
		
		// ã?ã¤ã¹ã­ã¹ãæã«ã??ã¿ãç?æ£?ã?
		virtual void deviceLost( IDrawContext* drawContext ) {}
	
		virtual void setZ_TestImpl( ModelContext &mdc , IDrawContext* _cdata , float z ){}
	
#ifdef L2D_DEBUG
		virtual void dump() = 0 ;
#endif
	
	private:
		//Prevention of copy Constructor
		IDrawData( const IDrawData & ) ;
		IDrawData& operator=( const IDrawData & ) ; 	
	
	private:
		static int			totalMinOrder ;		//  å®è¡æã®ã??ã¿ç¢ºä¿ç¨(transient)
		static int			totalMaxOrder ;		//  å®è¡æã®ã??ã¿ç¢ºä¿ç¨(transient)
	
	protected:
		PivotManager *		pivotManager ;
		int 				averageDrawOrder ;	//  æç»é ?å¤æ´ããªã?¹å¼ã§æãå ´åï¼?_L2D_VERSION_STR__ 801ä»¥éã?ä½¿ããªã?¼?
	
	private:
		DrawDataID *		drawDataID ;		//  è§£æ¾ããªã?
		BaseDataID *		targetBaseDataID ;	//  è§£æ¾ããªã?
		LDVector<int>*		pivotDrawOrder ;	//  è£éç¨ã®pivotãå?ã¦æã¤é ç¹éå? [numPivots]
		LDVector<float>*	pivotOpacity ;		//  è£éç¨ã®pivotãå?ã¦æã¤é ç¹éå? [numPivots]
	
		bool				dirty ;				//  æ´æ°ããã¦init()ãå¼ã³åºãå¿?¦ãããå ´åï¼å?æç¶æã??
	};
}
//------------ LIVE2D NAMESPACE ------------

#endif // __SKIP_DOC__

#endif	// __LIVE2D_IDRAWDATA_H__
