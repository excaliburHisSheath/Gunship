#pragma once

#include <vector>
#include <functional>

#include "components/Component.h"
#include "components/CameraComponent.h"
#include "components/BehaviorComponent.h"
#include "GameObject.h"
#include "Scene.h"

// forward declarations because reasons
namespace Ogre {
	class Root;
	class RenderWindow;
};
struct SDL_Window;

class Gunship
{
private:
	// Variables and stuffs
	SDL_Window* window;
	Ogre::Root* root;
	Ogre::RenderWindow* renderWindow;

	void UpdateComponents();

	Scene* currentScene;

public:
	// default constructor
	Gunship();

	~Gunship();

	// initialization and shutdown functions
	bool InitSystems();
	bool Configure();
	void Start();

	bool ShutDown();

	// other functions
	Scene* CurrentScene();
	Scene* ResetCurrentScene();
	Scene* ResetCurrentScene( std::function< void( Scene& ) > );
};