#include <ctype.h>

#include <PxPhysicsAPI.h>

#include <vector>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"
#include "Particle.h"
#include "Scene.h"

using namespace physx;

PxDefaultAllocator		gAllocator;
PxDefaultErrorCallback	gErrorCallback;

PxFoundation*			gFoundation = NULL;
PxPhysics*				gPhysics	= NULL;


PxMaterial*				gMaterial	= NULL;

PxPvd*                  gPvd        = NULL;

PxDefaultCpuDispatcher*	gDispatcher = NULL;
PxScene*				gScene      = NULL;
ContactReportCallback gContactReportCallback;
Scene* mScene;

// Initialize physics engine
void initPhysics(bool interactive)
{
	PX_UNUSED(interactive);

	gFoundation = PxCreateFoundation(PX_FOUNDATION_VERSION, gAllocator, gErrorCallback);

	gPvd = PxCreatePvd(*gFoundation);
	PxPvdTransport* transport = PxDefaultPvdSocketTransportCreate(PVD_HOST, 5425, 10);
	gPvd->connect(*transport,PxPvdInstrumentationFlag::eALL);

	gPhysics = PxCreatePhysics(PX_PHYSICS_VERSION, *gFoundation, PxTolerancesScale(),true,gPvd);

	gMaterial = gPhysics->createMaterial(0.5f, 0.5f, 0.6f);

	// For Solid Rigids +++++++++++++++++++++++++++++++++++++
	PxSceneDesc sceneDesc(gPhysics->getTolerancesScale());
	sceneDesc.gravity = PxVec3(0.0f, 0.0f, 0.0f); //No gravity here 
	gDispatcher = PxDefaultCpuDispatcherCreate(2);
	sceneDesc.cpuDispatcher = gDispatcher;
	sceneDesc.filterShader = contactReportFilterShader;
	sceneDesc.simulationEventCallback = &gContactReportCallback;
	gScene = gPhysics->createScene(sceneDesc);
	mScene = new Scene(GetCamera()->getEye() - Vector3(5, 0, 5));
	// ------------------------------------------------------

	
}


// Function to configure what happens in each step of physics
// interactive: true if the game is rendering, false if it offline
// t: time passed since last call in milliseconds
void stepPhysics(bool interactive, double t)
{
	PX_UNUSED(interactive);
	
	mScene->run(t);

	gScene->simulate(t);
	gScene->fetchResults(true);
}

// Function to clean data
// Add custom code to the begining of the function
void cleanupPhysics(bool interactive)
{
	PX_UNUSED(interactive);

	// Rigid Body ++++++++++++++++++++++++++++++++++++++++++
	gScene->release();
	gDispatcher->release();
	// -----------------------------------------------------
	gPhysics->release();	
	PxPvdTransport* transport = gPvd->getTransport();
	gPvd->release();
	transport->release();
	
	gFoundation->release();
	delete mScene;
}

// Function called when a key is pressed
void keyPress(unsigned char key, const PxTransform& camera)
{
	PX_UNUSED(camera);
	

	switch(toupper(key))
	{
	
	case 'H':	//dos particulas a la vez para que se vea que evidentemente tienen diferente gravedad
	{
		//mScene->addParticle(FORCES::LUNAR_GRAVITY, GetCamera()->getEye() - Vector3(150, -150, 150), Vector3(0, 10, 0), Vector4(0.2, 0.9, 0.9, 1));
		//mScene->addParticle(FORCES::EARTH_GRAVITY, GetCamera()->getEye() - Vector3(150, -150, 100), Vector3(0, 10, 0), Vector4(0.9, 0.4, 0.9, 1));
		break;
	}
	case 'E': //explosive bouyancy
	{
		//int rx = 1+rand() % 120;
		//int ry = 0 + rand() % 120;
		//int rz = 1+rand() % 120;
		//
		//mScene->addParticle(FORCES::EXPLOSION, Vector3(rx, ry, rz), Vector3(0, 0, 0), Vector4(rx % 121, ry / 120, rz / 121, 12));
		//mScene->addParticle(FORCES::EXPLOSION, Vector3(rx, ry, -rz), Vector3(0, 0, 0), Vector4(rx / 121, ry / 120, rz / 121, 12));
		//mScene->addParticle(FORCES::EXPLOSION, Vector3(rx, -ry, rz), Vector3(0, 0, 0), Vector4(rx  %121, ry % 120, rz / 121, 12));
		//mScene->addParticle(FORCES::EXPLOSION, Vector3(rx, -ry, -rz), Vector3(0, 0, 0), Vector4(rx / 121, ry % 120, rz % 121, 12));
		//mScene->addParticle(FORCES::EXPLOSION, Vector3(-rx, ry, rz), Vector3(0, 0, 0), Vector4(rx % 121, ry / 120, rz % 121, 12));
		//mScene->addParticle(FORCES::EXPLOSION, Vector3(-rx, ry, -rz), Vector3(0, 0, 0), Vector4(rx / 121, ry % 120, rz % 121, 12));
		//mScene->addParticle(FORCES::EXPLOSION, Vector3(-rx, -ry, rz), Vector3(0, 0, 0), Vector4(rx % 121, ry % 120, rz % 121, 12));
		//mScene->addParticle(FORCES::EXPLOSION, Vector3(-rx, -ry, -rz), Vector3(0, 0, 0), Vector4(rx/121, ry/120, rz/121, 12));
	}		
		break;
	case ' ':
		break;
	case 'Z':
		mScene->addFireWork(Type::SPHERE, GetCamera()->getEye()- Vector3(150,50,100),Vector4(1,0.2,0.7,1));
		break;
		
	case 'X':

		mScene->addFireWork(Type::SPARK, GetCamera()->getEye()- Vector3(100, 50, 100), Vector4(1, 0.5, 0.2, 1));
		break;
		
	case 'C':
		mScene->addFireWork(Type::ASPERSOR, GetCamera()->getEye()- Vector3(50, 50, 100), Vector4(0.3, 0.3, 0.7, 1));
		break;
	case 'V':
		//mScene->addSpring();
		break;
	case 'K':
		//mScene->addK();
		break;
	case 'L':
		//mScene->sustrateK();
		break;

	
	case 'N':
		//mScene->addParticle(FORCES::SPRING_A, Vector3(-50, 0, 50) + Vector3(0, -10, -10), Vector3(0, 0, 0), Vector4(0.2, 0.8, 0.8, 1));

		break;

	default:
		break;
	}
}

void onCollision(physx::PxActor* actor1, physx::PxActor* actor2)
{
	PX_UNUSED(actor1);
	PX_UNUSED(actor2);
}


int main(int, const char*const*)
{
#ifndef OFFLINE_EXECUTION 
	extern void renderLoop();
	renderLoop();
#else
	static const PxU32 frameCount = 100;
	initPhysics(false);
	for(PxU32 i=0; i<frameCount; i++)
		stepPhysics(false);
	cleanupPhysics(false);
#endif

	return 0;
}