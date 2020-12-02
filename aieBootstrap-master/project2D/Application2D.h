#pragma once

#include "Application.h"
#include "Renderer2D.h"

class Plane;
class RigidBody;
class AABB;
class Circle;
class PhysicsScene;
class Spring;


class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	Spring* SpringAdder(Spring* spring, RigidBody* bodyOne, RigidBody* bodyTwo);

	

	aie::Renderer2D*	m_2dRenderer;
	//aie::Texture*		m_texture;
	aie::Texture*		m_shipTexture;
	aie::Font*			m_font;

	float randomNumberOne;
	float randomNumberTwo;

	PhysicsScene* myPhysicsScene;
	/*Circle* myCircle;
	Circle* mySecondCircle;
	Circle* myThirdCircle;
	Circle* myFourthCircle;

	AABB* myAABB;
	AABB* mySecondAABB;
	AABB* myThirdAABB;
	AABB* myFourthAABB;*/

	//planes used for the four corners
	Plane* myPlane;
	Plane* mySecondPlane;
	Plane* myThirdPlane;
	Plane* myFourthPlane;

	//planes used for diagonals
	Plane* myDiagonalPlane;
	Plane* mySecondDiagonalPlane;
	Plane* myThirdDiagonalPlane;
	Plane* myFourthDiagonalPlane;
	

	
	Circle* myCircles[5];
	Circle* mySecondCircles[5];
	Circle* myThirdCircles[5];


	Spring* myTopHorizontalSprings[4];
	Spring* myMiddleHorizontalSprings[4];
	Spring* myBottomHorizontalSprings[4];

	Spring* myTopVerticalSprings[5];
	Spring* myBottomVerticalSprings[5];

	Spring* myTopLeftDiagonalSprings[4];
	Spring* myTopRightDiagonalSprings[4];

	Spring* myBottomLeftDiagonalSprings[4];
	Spring* myBottomRightDiagonalSprings[4];

	float m_timer;
	

};