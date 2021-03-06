// OpenGL test.cpp 

#include "Lab1.h"
#include "imageLoad.h"

bool Window::_entered = false;
int Window::xPosition = 0;
int Window::yPosition = 0;

float Window::Eye[3]{ 0.0f, 0.0f, 20.0f };
float Window::Center[3]{ 0.0f, 0.0f, 0.0f };
float Window::Up[3]{ 0.0f, 1.0f, 0.0f };
float Window::scrollModification = 1.0f;

bool Window::keyRelease = true;
unsigned char Window::keyStatus[350];
unsigned char Window::textWindow[128];



int main()
{
	GLfloat projectionMatrix[] = { 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat matrixView[] = { 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat matrixRotate[] = { 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f };
	Matrix mainMatrixes;


	mainMatrixes.pushMatrix(projectionMatrix, sizeof(projectionMatrix));
	mainMatrixes.pushMatrix(matrixView, sizeof(matrixView));
	mainMatrixes.pushMatrix(matrixRotate, sizeof(matrixRotate));
	Window window((int32_t)1280, (int32_t)720, (uint8_t*) "test OpenGL", &mainMatrixes);
	window.setupOpenGL();
	lab1 firstLab;
	firstLab.Start(&window, &mainMatrixes);
	window.makeLoop();
}