#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Gizmos.h"
#include "glm/glm.hpp"
#include "glm/ext.hpp"
#include "PhysicsScene.h"
#include "Spring.h"
#include "Circle.h"
#include <ctime>


Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	setVSync(true);
	// increase the 2d line count to maximize the number of objects we can draw
	aie::Gizmos::create(255U, 255U, 65535U, 65535U);

	m_2dRenderer = new aie::Renderer2D();

	//m_texture = new aie::Texture("./textures/numbered_grid.tga");
	m_shipTexture = new aie::Texture("./textures/ship.png");

	m_font = new aie::Font("./font/consolas.ttf", 32);
	
	srand(time(nullptr));

	m_timer = 0;

	myPhysicsScene = new PhysicsScene();
	myPhysicsScene->setTimeStep(0.016f);
	//myPhysicsScene->setGravity(glm::vec2(0, 1));

	//add the circles
	/*myCircle = new Circle(glm::vec2(10, 0), glm::vec2(0, 0), 0.1f, 5, 0.1f, 1,glm::vec4(1, 1, 0, 1));
	mySecondCircle = new Circle(glm::vec2(30, 1), glm::vec2(0, 0), 1, 3, 0, 1, glm::vec4(0.5f, 0, 1, 1));
	myThirdCircle = new Circle(glm::vec2(-60, 1), glm::vec2(0, 0), 1, 6, 1, 1, glm::vec4(0.9f, 0, 0.4f, 1));
	myFourthCircle = new Circle(glm::vec2(0, 0), glm::vec2(40, 0), 1, 6, 0, 0.9f, glm::vec4(1, 0, 1, 1));

	//add the AABBs
	myAABB = new AABB(glm::vec2(-30, 5), glm::vec2(5, 5), glm::vec2(0), 1, 0.5f, 0.3f, glm::vec4(1, 0.3f, 0, 1));
	mySecondAABB = new AABB(glm::vec2(0, 20), glm::vec2(10, 10), glm::vec2(0), 1, 0.5f, 1, glm::vec4(0, 0.7f, 1, 1));
	myThirdAABB = new AABB(glm::vec2(-10, 60), glm::vec2(7, 7), glm::vec2(0), 3, 2, 0.3f, glm::vec4(0.1f, 0.3f, 1, 1));
	myFourthAABB = new AABB(glm::vec2(-30, -30), glm::vec2(11, 11), glm::vec2(0), 1, 1, 0.5f, glm::vec4(0.1f, 0.9f, 0, 1));*/

	//add the planes
	myPlane = new Plane(glm::vec2(0, 100), -50.0f, 1, glm::vec4(1, 0.3f, 1, 1));
	mySecondPlane = new Plane(glm::vec2(10, 0), -80.0f, 1, glm::vec4(1, 0.3f, 1, 1));
	myThirdPlane = new Plane(glm::vec2(-10, 0), -80.0f, 1, glm::vec4(1, 0.3f, 1, 1));
	myFourthPlane = new Plane(glm::vec2(0, -100), -50.0f, 1, glm::vec4(1, 0.3f, 1, 1));

	/*myDiagonalPlane = new Plane(glm::vec2(0.5f,0.5f), -50.0f, 1, glm::vec4(1, 0.3f, 1, 1));
	mySecondDiagonalPlane = new Plane(glm::vec2(-0.5f, 0.5f), -50.0f, 1, glm::vec4(1, 0.3f, 1, 1));
	myThirdDiagonalPlane = new Plane(glm::vec2(0.5f, -0.5f), -50.0f, 1, glm::vec4(1, 0.3f, 1, 1));
	myFourthDiagonalPlane = new Plane(glm::vec2(-0.5f, -0.5f), -50.0f, 1, glm::vec4(1, 0.3f, 1, 1));*/

	/*mySpring = new Spring((RigidBody*)myThirdCircle, (RigidBody*)myFourthCircle, 4, 2, 0.1f/*, myThirdCircle->getPosition(), myFourthCircle->getPosition()*///);
	/*mySecondSpring = new Spring((RigidBody*)myThirdAABB, (RigidBody*)myThirdCircle, 4, 2, 0.1f/*, myThirdAABB->getPosition(), myThirdCircle->getPosition()*///);
	

	//add the circles
	for (int i = 0; i <= 4; ++i)
	{
		//if it is less than 5 stay on first row
		//if (i < 5)
		//{
			//						//position					velocity	mass, radius, drag, elasticity, colour
			myCircles[i] = new Circle(glm::vec2((i * 5), 20), glm::vec2(0, 0), 25, 5, 1.5f, 1, glm::vec4(1, 0.8f, 1, 1));
		//}

		//if i is greater than 4 and less than 9 go to second row
		//if (i >= 5 && i <= 9)
		//{
			//circle is made in row 2
			//						//position					velocity	mass, radius, drag, elasticity, colour
			mySecondCircles[i] = new Circle(glm::vec2((i * 5), 10), glm::vec2(0, 0), 25, 5, 1.5f, 1, glm::vec4(1, 0.8f, 1, 1));
		//}
		//if i is greater than 9 go to third row
		//if (i >= 10)
		//{
			//						//position					velocity	mass, radius, drag, elasticity, colour
			myThirdCircles[i] = new Circle(glm::vec2((i * 5), 0), glm::vec2(0, 0), 25, 5, 1.5f, 1, glm::vec4(1, 0.8f, 1, 1));
		//}
		//add the circle to the physics scene
		myPhysicsScene->addObject(myCircles[i]);
		myPhysicsScene->addObject(mySecondCircles[i]);
		myPhysicsScene->addObject(myThirdCircles[i]);
	}	

	//add the springs
	//horizontal
	if (true)
	{
		//top row horizontal
		myTopHorizontalSprings[0] = SpringAdder((Spring*)myTopHorizontalSprings[0], (RigidBody*)myCircles[0], (RigidBody*)myCircles[1]);
		myPhysicsScene->addObject(myTopHorizontalSprings[0]);

		myTopHorizontalSprings[1] = SpringAdder((Spring*)myTopHorizontalSprings[1], (RigidBody*)myCircles[1], (RigidBody*)myCircles[2]);
		myPhysicsScene->addObject(myTopHorizontalSprings[1]);

		myTopHorizontalSprings[2] = SpringAdder((Spring*)myTopHorizontalSprings[2], (RigidBody*)myCircles[2], (RigidBody*)myCircles[3]);
		myPhysicsScene->addObject(myTopHorizontalSprings[2]);

		myTopHorizontalSprings[3] = SpringAdder((Spring*)myTopHorizontalSprings[3], (RigidBody*)myCircles[3], (RigidBody*)myCircles[4]);
		myPhysicsScene->addObject(myTopHorizontalSprings[3]);


		//middle row horizontal
		myMiddleHorizontalSprings[0] = SpringAdder((Spring*)myMiddleHorizontalSprings[0], (RigidBody*)mySecondCircles[0], (RigidBody*)mySecondCircles[1]);
		myPhysicsScene->addObject(myMiddleHorizontalSprings[0]);

		myMiddleHorizontalSprings[1] = SpringAdder((Spring*)myMiddleHorizontalSprings[1], (RigidBody*)mySecondCircles[1], (RigidBody*)mySecondCircles[2]);
		myPhysicsScene->addObject(myMiddleHorizontalSprings[1]);

		myMiddleHorizontalSprings[2] = SpringAdder((Spring*)myMiddleHorizontalSprings[2], (RigidBody*)mySecondCircles[2], (RigidBody*)mySecondCircles[3]);
		myPhysicsScene->addObject(myMiddleHorizontalSprings[2]);

		myMiddleHorizontalSprings[3] = SpringAdder((Spring*)myMiddleHorizontalSprings[3], (RigidBody*)mySecondCircles[3], (RigidBody*)mySecondCircles[4]);
		myPhysicsScene->addObject(myMiddleHorizontalSprings[3]);


		//bottom row horizontal
		myBottomHorizontalSprings[0] = SpringAdder((Spring*)myBottomHorizontalSprings[0], (RigidBody*)myThirdCircles[0], (RigidBody*)myThirdCircles[1]);
		myPhysicsScene->addObject(myBottomHorizontalSprings[0]);

		myBottomHorizontalSprings[1] = SpringAdder((Spring*)myBottomHorizontalSprings[1], (RigidBody*)myThirdCircles[1], (RigidBody*)myThirdCircles[2]);
		myPhysicsScene->addObject(myBottomHorizontalSprings[1]);

		myBottomHorizontalSprings[2] = SpringAdder((Spring*)myBottomHorizontalSprings[2], (RigidBody*)myThirdCircles[2], (RigidBody*)myThirdCircles[3]);
		myPhysicsScene->addObject(myBottomHorizontalSprings[2]);

		myBottomHorizontalSprings[3] = SpringAdder((Spring*)myBottomHorizontalSprings[3], (RigidBody*)myThirdCircles[3], (RigidBody*)myThirdCircles[4]);
		myPhysicsScene->addObject(myBottomHorizontalSprings[3]);

	} 

	//vertical
	if (true)
	{
		//top vertical
		myTopVerticalSprings[0] = SpringAdder((Spring*)myTopVerticalSprings[0], (RigidBody*)myCircles[0], (RigidBody*)mySecondCircles[0]);
		myPhysicsScene->addObject(myTopVerticalSprings[0]);

		myTopVerticalSprings[1] = SpringAdder((Spring*)myTopVerticalSprings[1], (RigidBody*)myCircles[1], (RigidBody*)mySecondCircles[1]);
		myPhysicsScene->addObject(myTopVerticalSprings[1]);

		myTopVerticalSprings[2] = SpringAdder((Spring*)myTopVerticalSprings[2], (RigidBody*)myCircles[2], (RigidBody*)mySecondCircles[2]);
		myPhysicsScene->addObject(myTopVerticalSprings[2]);

		myTopVerticalSprings[3] = SpringAdder((Spring*)myTopVerticalSprings[3], (RigidBody*)myCircles[3], (RigidBody*)mySecondCircles[3]);
		myPhysicsScene->addObject(myTopVerticalSprings[3]);

		myTopVerticalSprings[4] = SpringAdder((Spring*)myTopVerticalSprings[4], (RigidBody*)myCircles[4], (RigidBody*)mySecondCircles[4]);
		myPhysicsScene->addObject(myTopVerticalSprings[4]);


		//bottom vertical
		myBottomVerticalSprings[0] = SpringAdder((Spring*)myBottomVerticalSprings[0], (RigidBody*)myThirdCircles[0], (RigidBody*)mySecondCircles[0]);
		myPhysicsScene->addObject(myBottomVerticalSprings[0]);

		myBottomVerticalSprings[1] = SpringAdder((Spring*)myBottomVerticalSprings[1], (RigidBody*)myThirdCircles[1], (RigidBody*)mySecondCircles[1]);
		myPhysicsScene->addObject(myBottomVerticalSprings[1]);

		myBottomVerticalSprings[2] = SpringAdder((Spring*)myBottomVerticalSprings[2], (RigidBody*)myThirdCircles[2], (RigidBody*)mySecondCircles[2]);
		myPhysicsScene->addObject(myBottomVerticalSprings[2]);

		myBottomVerticalSprings[3] = SpringAdder((Spring*)myBottomVerticalSprings[3], (RigidBody*)myThirdCircles[3], (RigidBody*)mySecondCircles[3]);
		myPhysicsScene->addObject(myBottomVerticalSprings[3]);

		myBottomVerticalSprings[4] = SpringAdder((Spring*)myBottomVerticalSprings[4], (RigidBody*)myThirdCircles[4], (RigidBody*)mySecondCircles[4]);
		myPhysicsScene->addObject(myBottomVerticalSprings[4]);
	}

	//diagonal
	if (true)
	{
		//top left
		myTopLeftDiagonalSprings[0] = SpringAdder((Spring*)myTopLeftDiagonalSprings[0], (RigidBody*)myCircles[0], (RigidBody*)mySecondCircles[1]);
		myPhysicsScene->addObject(myTopLeftDiagonalSprings[0]);

		myTopLeftDiagonalSprings[1] = SpringAdder((Spring*)myTopLeftDiagonalSprings[1], (RigidBody*)myCircles[1], (RigidBody*)mySecondCircles[2]);
		myPhysicsScene->addObject(myTopLeftDiagonalSprings[1]);

		myTopLeftDiagonalSprings[2] = SpringAdder((Spring*)myTopLeftDiagonalSprings[2], (RigidBody*)myCircles[2], (RigidBody*)mySecondCircles[3]);
		myPhysicsScene->addObject(myTopLeftDiagonalSprings[2]);

		myTopLeftDiagonalSprings[3] = SpringAdder((Spring*)myTopLeftDiagonalSprings[3], (RigidBody*)myCircles[3], (RigidBody*)mySecondCircles[4]);
		myPhysicsScene->addObject(myTopLeftDiagonalSprings[3]);

		//top right
		myTopRightDiagonalSprings[0] = SpringAdder((Spring*)myTopRightDiagonalSprings[0], (RigidBody*)mySecondCircles[0], (RigidBody*)myCircles[1]);
		myPhysicsScene->addObject(myTopRightDiagonalSprings[0]);

		myTopRightDiagonalSprings[1] = SpringAdder((Spring*)myTopRightDiagonalSprings[1], (RigidBody*)mySecondCircles[1], (RigidBody*)myCircles[2]);
		myPhysicsScene->addObject(myTopRightDiagonalSprings[1]);

		myTopRightDiagonalSprings[2] = SpringAdder((Spring*)myTopRightDiagonalSprings[2], (RigidBody*)mySecondCircles[2], (RigidBody*)myCircles[3]);
		myPhysicsScene->addObject(myTopRightDiagonalSprings[2]);

		myTopRightDiagonalSprings[3] = SpringAdder((Spring*)myTopRightDiagonalSprings[3], (RigidBody*)mySecondCircles[3], (RigidBody*)myCircles[4]);
		myPhysicsScene->addObject(myTopRightDiagonalSprings[3]);

		//bottom left
		myBottomLeftDiagonalSprings[0] = SpringAdder((Spring*)myBottomLeftDiagonalSprings[0], (RigidBody*)mySecondCircles[0], (RigidBody*)myThirdCircles[1]);
		myPhysicsScene->addObject(myBottomLeftDiagonalSprings[0]);

		myBottomLeftDiagonalSprings[1] = SpringAdder((Spring*)myBottomLeftDiagonalSprings[1], (RigidBody*)mySecondCircles[1], (RigidBody*)myThirdCircles[2]);
		myPhysicsScene->addObject(myBottomLeftDiagonalSprings[1]);

		myBottomLeftDiagonalSprings[2] = SpringAdder((Spring*)myBottomLeftDiagonalSprings[2], (RigidBody*)mySecondCircles[2], (RigidBody*)myThirdCircles[3]);
		myPhysicsScene->addObject(myBottomLeftDiagonalSprings[2]);

		myBottomLeftDiagonalSprings[3] = SpringAdder((Spring*)myBottomLeftDiagonalSprings[3], (RigidBody*)mySecondCircles[3], (RigidBody*)myThirdCircles[4]);
		myPhysicsScene->addObject(myBottomLeftDiagonalSprings[3]);

		//bottom right
		myBottomRightDiagonalSprings[0] = SpringAdder((Spring*)myBottomRightDiagonalSprings[0], (RigidBody*)myThirdCircles[0], (RigidBody*)mySecondCircles[1]);
		myPhysicsScene->addObject(myBottomRightDiagonalSprings[0]);

		myBottomRightDiagonalSprings[1] = SpringAdder((Spring*)myBottomRightDiagonalSprings[1], (RigidBody*)myThirdCircles[1], (RigidBody*)mySecondCircles[2]);
		myPhysicsScene->addObject(myBottomRightDiagonalSprings[1]);

		myBottomRightDiagonalSprings[2] = SpringAdder((Spring*)myBottomRightDiagonalSprings[2], (RigidBody*)myThirdCircles[2], (RigidBody*)mySecondCircles[3]);
		myPhysicsScene->addObject(myBottomRightDiagonalSprings[2]);

		myBottomRightDiagonalSprings[3] = SpringAdder((Spring*)myBottomRightDiagonalSprings[3], (RigidBody*)myThirdCircles[3], (RigidBody*)mySecondCircles[4]);
		myPhysicsScene->addObject(myBottomRightDiagonalSprings[3]);

	}
	

	//mySprings[0] = new Spring((RigidBody*)myCircles[1], (RigidBody*)myFourthCircle, 4, 2, 0.1f, myThirdCircle->getPosition(), myFourthCircle->getPosition());
	//add the planes to the physicsScene
	myPhysicsScene->addObject(myPlane);
	myPhysicsScene->addObject(mySecondPlane);
	myPhysicsScene->addObject(myThirdPlane);
	myPhysicsScene->addObject(myFourthPlane);

	/*myPhysicsScene->addObject(myDiagonalPlane);
	myPhysicsScene->addObject(mySecondDiagonalPlane);
	myPhysicsScene->addObject(myThirdDiagonalPlane);
	myPhysicsScene->addObject(myFourthDiagonalPlane);*/

	myPhysicsScene->setGravity(glm::vec2(0, -1));
	return true;
}

void Application2D::shutdown() {
	
	delete m_font;
	//delete m_texture;
	delete m_shipTexture;
	delete m_2dRenderer;
	//deleting the physicsScene takes care of deleting the objects added to it
	delete myPhysicsScene;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;

	//update the random numbers
	//randomNumberOne = rand() % 50;
	//randomNumberTwo = rand() % 50;

	//clear gizmos
	aie::Gizmos::clear();

	//update the physicsScene and the Gizmos
	myPhysicsScene->update(deltaTime);
	myPhysicsScene->updateGizmos();

	//myCircle->makeGizmo();


	// input example
	aie::Input* input = aie::Input::getInstance();

	// Update the camera position using the arrow keys
	float camPosX;
	float camPosY;
	m_2dRenderer->getCameraPos(camPosX, camPosY);

	/*if (input->isKeyDown(aie::INPUT_KEY_UP))
		camPosY += 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		camPosY -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		camPosX -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		camPosX += 500.0f * deltaTime;*/

	//when space is pressed, make corner circles kinematic (or toggle it)
	if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
	{
		//get the status of if the top left circle is kinematic and update accordingly
		bool temp = myCircles[0]->getKinematic();

		myCircles[0]->UpdateStartPosition();
		myCircles[0]->setKinematic(!temp);		 		
		myCircles[0]->setColour(temp ? glm::vec4(1, 0.8f, 1, 1) : glm::vec4(1, 0, 1, 1));

		//repeat for top middle
		/*temp = myCircles[2]->getKinematic();

		myCircles[2]->UpdateStartPosition();
		myCircles[2]->setKinematic(!temp);
		myCircles[2]->setColour(temp ? glm::vec4(1, 0.8f, 1, 1) : glm::vec4(1, 0, 1, 1));*/

		//repeat for the top right
		temp = myCircles[4]->getKinematic();

		myCircles[4]->UpdateStartPosition();
		myCircles[4]->setKinematic(!temp);
		myCircles[4]->setColour(temp ? glm::vec4(1, 0.8f, 1, 1) : glm::vec4(1, 0, 1, 1));



		//also repeat for bottom left
		temp = myThirdCircles[0]->getKinematic();

		myThirdCircles[0]->UpdateStartPosition();
		myThirdCircles[0]->setKinematic(!temp);
		myThirdCircles[0]->setColour(temp ? glm::vec4(1, 0.8f, 1, 1) : glm::vec4(1, 0, 1, 1));

		//bottom middle
		/*temp = myThirdCircles[2]->getKinematic();

		myThirdCircles[2]->UpdateStartPosition();
		myThirdCircles[2]->setKinematic(!temp);
		myThirdCircles[2]->setColour(temp ? glm::vec4(1, 0.8f, 1, 1) : glm::vec4(1, 0, 1, 1));*/

		//annndddd also bottom right
		temp = myThirdCircles[4]->getKinematic();

		myThirdCircles[4]->UpdateStartPosition();
		myThirdCircles[4]->setKinematic(!temp);
		myThirdCircles[4]->setColour(temp ? glm::vec4(1, 0.8f, 1, 1) : glm::vec4(1, 0, 1, 1));
		

	}

	//when Q is pressed make top left kinematic (or toggle it)
	if (input->wasKeyPressed(aie::INPUT_KEY_Q))
	{
		bool temp = myCircles[0]->getKinematic();

		myCircles[0]->UpdateStartPosition();
		myCircles[0]->setKinematic(!temp);
		myCircles[0]->setColour(temp ? glm::vec4(1, 0.8f, 1, 1) : glm::vec4(1, 0, 1, 1));
	}

	//when W is pressed make top right kinematic (or toggle it)
	if (input->wasKeyPressed(aie::INPUT_KEY_W))
	{
		bool temp = myCircles[4]->getKinematic();

		myCircles[4]->UpdateStartPosition();
		myCircles[4]->setKinematic(!temp);
		myCircles[4]->setColour(temp ? glm::vec4(1, 0.8f, 1, 1) : glm::vec4(1, 0, 1, 1));
	}

	//when A is pressed make bottom left kinematic (or toggle it) 
	if (input->wasKeyPressed(aie::INPUT_KEY_A))
	{
		bool temp = myThirdCircles[0]->getKinematic();

		myThirdCircles[0]->UpdateStartPosition();
		myThirdCircles[0]->setKinematic(!temp);
		myThirdCircles[0]->setColour(temp ? glm::vec4(1, 0.8f, 1, 1) : glm::vec4(1, 0, 1, 1));
	}

	//when S is pressed make bottom right kinematic (or toggle it)
	if (input->wasKeyPressed(aie::INPUT_KEY_S))
	{
		bool temp = myThirdCircles[4]->getKinematic();

		myThirdCircles[4]->UpdateStartPosition();
		myThirdCircles[4]->setKinematic(!temp);
		myThirdCircles[4]->setColour(temp ? glm::vec4(1, 0.8f, 1, 1) : glm::vec4(1, 0, 1, 1));
	}

	//makes gravity go up
	if (input->wasKeyPressed(aie::INPUT_KEY_UP))
	{
		myPhysicsScene->setGravity(glm::vec2(0, 1));
	}

	//makes gravity go down
	if (input->wasKeyPressed(aie::INPUT_KEY_DOWN))
	{
		myPhysicsScene->setGravity(glm::vec2(0, -1));
	}

	//makes gravity go left
	if (input->wasKeyPressed(aie::INPUT_KEY_LEFT))
	{
		myPhysicsScene->setGravity(glm::vec2(-1, 0));
	}

	//makes gravity go right
	if (input->wasKeyPressed(aie::INPUT_KEY_RIGHT))
	{
		myPhysicsScene->setGravity(glm::vec2(1, 0));
	}

	if (input->wasKeyPressed(aie::INPUT_KEY_Z))
	{
		myPhysicsScene->setGravity(glm::vec2(0, 0));
	}

	//m_2dRenderer->setCameraPos(camPosX, camPosY);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// demonstrate animation
	//m_2dRenderer->setUVRect(int(m_timer) % 8 / 8.0f, 0, 1.f / 8, 1.f / 8);
	//m_2dRenderer->drawSprite(m_texture, 200, 200, 100, 100);

	//m_2dRenderer->setRenderColour(0.5f, 0, 1, 1);
	//m_2dRenderer->drawCircle(30, 30, 5, 1);

	//m_2dRenderer->drawLine(0, 20, 2000, 20, 5);

	//// demonstrate spinning sprite
	//m_2dRenderer->setUVRect(0,0,1,1);
	//m_2dRenderer->drawSprite(m_shipTexture, 600, 400, 0, 0, m_timer, 1);

	//// draw a thin line
	//m_2dRenderer->drawLine(300, 300, 600, 400, 2, 1);

	//// draw a moving purple circle
	//m_2dRenderer->setRenderColour(1, 0, 1, 1);
	//m_2dRenderer->drawCircle(sin(m_timer) * 100 + 600, 150, 50);

	//// draw a rotating red box
	//m_2dRenderer->setRenderColour(1, 0, 0, 1);
	//m_2dRenderer->drawBox(600, 500, 60, 20, m_timer);

	// draw a slightly rotated sprite with no texture, coloured yellow
	//m_2dRenderer->setRenderColour(1, 1, 0, 1);
	//m_2dRenderer->drawSprite(nullptr, 400, 400, 50, 50, 3.14159f * 0.25f, 1);


	//GIZMOS RELATED DRAWING STUFFS
	static float aspectRatio = 16 / 9.f;
	aie::Gizmos::draw2D(glm::ortho<float>(-100, 100, -100 / aspectRatio, 100 / aspectRatio, -1.0f, 1.0f));



	
	// output some text, uses the last used colour
	/*char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);*/

	// done drawing sprites
	m_2dRenderer->end();
}



Spring* Application2D::SpringAdder(Spring* spring, RigidBody* bodyOne, RigidBody* bodyTwo)
{
	
	spring = new Spring((RigidBody*)bodyOne, (RigidBody*)bodyTwo, 5, 20, 0.1f/*, bodyOne->getPosition(), bodyTwo->getPosition()*/);
	return spring;
}