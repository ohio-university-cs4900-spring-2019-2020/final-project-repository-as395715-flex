#pragma once

#include "GLView.h"
#include "irrKlang.h"
#include "NetMessengerClient.h"
#include "PxPhysicsAPI.h"
#include "PxFoundation.h"
#include "PxDefaultAllocator.h"
#include "PxDefaultErrorCallback.h"
#include "NvFlex.h"
#include "NvFlexDevice.h"
#include "NvFlexExt.h"

namespace Aftr
{
   class Camera;

/**
   \class GLViewNewModule
   \author Scott Nykl 
   \brief A child of an abstract GLView. This class is the top-most manager of the module.

   Read \see GLView for important constructor and init information.

   \see GLView

    \{
*/

class GLViewNewModule : public GLView
{
public:
   static GLViewNewModule* New( const std::vector< std::string >& outArgs );
   virtual ~GLViewNewModule();
   virtual void updateWorld(); ///< Called once per frame
   virtual void loadMap(); ///< Called once at startup to build this module's scene
   virtual void createNewModuleWayPoints();
   virtual void onResizeWindow( GLsizei width, GLsizei height );
   virtual void onMouseDown( const SDL_MouseButtonEvent& e );
   virtual void onMouseUp( const SDL_MouseButtonEvent& e );
   virtual void onMouseMove( const SDL_MouseMotionEvent& e );
   virtual void onKeyDown( const SDL_KeyboardEvent& key );
   virtual void onKeyUp( const SDL_KeyboardEvent& key );
   void createAlien();
   void createUfo();
   /*typedef struct float3 {
       float x;
       float y;
       float z;
   } float3;

   typedef struct float4 {
       float x;
       float y;
       float z;
       float w;
   } float4;*/ 

   //int SpawnParticles(float4* particles, float4* velocities, int* phases, int numParticles);
   //float4 RandomSpawnPosition();
   //void createText(std::string msg, Aftr::Vector position);
   //void createMessage();

protected:
   GLViewNewModule( const std::vector< std::string >& args );
   virtual void onCreate();

   NetMessengerClient* client;

   irrklang::ISoundEngine* sound;

   physx::PxDefaultAllocator a;
   physx::PxDefaultErrorCallback e;
   physx::PxFoundation* f;
   physx::PxPhysics* p;
   physx::PxScene* gscene;
   physx::PxPvd* gpvd;
   physx::PxDefaultCpuDispatcher* d;

   /*
   NvFlexLibrary* library = NvFlexInit();
   NvFlexSolverDesc solverDesc;
   NvFlexSolver* solver = NvFlexCreateSolver(library, &solverDesc);

   NvFlexBuffer* particleBuffer = NvFlexAllocBuffer(library, 10, sizeof(float4), eNvFlexBufferHost);
   NvFlexBuffer* velocityBuffer = NvFlexAllocBuffer(library, 10, sizeof(float4), eNvFlexBufferHost);
   NvFlexBuffer* phaseBuffer = NvFlexAllocBuffer(library, 10, sizeof(int), eNvFlexBufferHost);

   float4* particles = (float4*)NvFlexMap(particleBuffer, eNvFlexMapWait);
   float3* velocities = (float3*)NvFlexMap(velocityBuffer, eNvFlexMapWait);
   int* phases = (int*)NvFlexMap(phaseBuffer, eNvFlexMapWait);
   int numParticles;*/

};

/** \} */

} //namespace Aftr
