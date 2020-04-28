//**********************************************************************************
// STEAMiE's Entry Point.
//**********************************************************************************

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "NvFlex.h"
#include "NvFlexDevice.h"
#include "NvFlexExt.h"
#include "GLViewNewModule.h" //GLView subclass instantiated to drive this simulation

/// Saves the in passed params argc and argv in a vector of strings.
std::vector< std::string > saveInputParams( int argc, char** argv );

/**
   This creates a GLView subclass instance and begins the GLView's main loop.
   Each iteration of this loop occurs when a reset request is received. A reset
   request causes the entire GLView to be destroyed (since its exits scope) and
   begin again (simStatus == -1). This loop exits when a request to exit the 
   application is received (simStatus == 0 ).
*/
int main( int argc, char* argv[] )
{
   std::vector< std::string > args = saveInputParams( argc, argv ); ///< Command line arguments passed via argc and argv, reserved to size of argc
   int simStatus = 0;

 /* NvFlexLibrary* library = NvFlexInit();

    // create new solver
    NvFlexSolverDesc solverDesc;
    NvFlexSetSolverDescDefaults(&solverDesc);
    solverDesc.maxParticles = 500;
    solverDesc.maxDiffuseParticles = 0;

    NvFlexSolver* solver = NvFlexCreateSolver(library, &solverDesc);

    NvFlexBuffer* particleBuffer = NvFlexAllocBuffer(library, 500, sizeof(GLViewNewModule::float4), eNvFlexBufferHost);
    NvFlexBuffer* velocityBuffer = NvFlexAllocBuffer(library, 500, sizeof(GLViewNewModule::float4), eNvFlexBufferHost);
    NvFlexBuffer* phaseBuffer = NvFlexAllocBuffer(library, 500, sizeof(int), eNvFlexBufferHost);

    int numParticles = 0;*/

   do
   {
      std::unique_ptr< Aftr::GLViewNewModule > glView( Aftr::GLViewNewModule::New( args ) );
      simStatus = glView->startWorldSimulationLoop(); // Runs until simulation exits or requests a restart (values 0 or -1, respectively)
      
      //numParticles = Aftr::GLViewNewModule::SpawnParticles(Aftr::GLViewNewModule::particles, Aftr::GLViewNewModule::velocities, Aftr::GLViewNewModule::phases, numParticles);

      // render (user method)
      //RenderParticles(particles, velocities, phases, numParticles);

      // unmap buffers
     /* NvFlexUnmap(particleBuffer);
      NvFlexUnmap(velocityBuffer);
      NvFlexUnmap(phaseBuffer);

      // write to device (async)
      NvFlexSetParticles(solver, particleBuffer, NULL);
      NvFlexSetVelocities(solver, velocityBuffer, NULL);
      NvFlexSetPhases(solver, phaseBuffer, NULL);

      // set active count
      NvFlexSetActiveCount(solver, numParticles);

      // tick
      NvFlexUpdateSolver(solver, 1, 1, false);

      // read back (async)
      NvFlexGetParticles(solver, particleBuffer, NULL);
      NvFlexGetVelocities(solver, velocityBuffer, NULL);
      NvFlexGetPhases(solver, phaseBuffer, NULL);*/
   }
   while( simStatus != 0 );

   std::cout << "Exited AfterBurner Engine Normally..." << std::endl;
  /* NvFlexFreeBuffer(particleBuffer);
   NvFlexFreeBuffer(velocityBuffer);
   NvFlexFreeBuffer(phaseBuffer);

   NvFlexDestroySolver(solver);
   NvFlexShutdown(library);*/
   return 0;
}

std::vector< std::string > saveInputParams( int argc, char** argv )
{
   std::vector< std::string > args( argc );
   for( int i = 0; i < argc; ++i )
   {
      std::string arg( argv[i] );
      args[i] = arg;
   }
   return args;
}