#include <Windows.h>
#include <gl/GL.h>

#pragma comment (lib, "OpenGL32.lib")

#define WINDOW_TITLE "Practical 4"

float lowerUp = 0.0;
float leftUp = 0.0;
int displayKey = 1;
LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
			PostQuitMessage(0);
		else if (wParam == '1')
			displayKey = 1;
		else if (wParam == '2')
			displayKey = 2;
		else if (wParam == '3')
			displayKey = 3;
		else if (wParam == 'X')
			glRotatef(5, 1, 0, 0);
		else if (wParam == 'Y')
			glRotatef(5, 0, 1, 0);
		else if (wParam == 'Z')
			glRotatef(5, 0, 0, 1);
		else if (wParam == 0x26)
			lowerUp += 1;
		else if (wParam == 0x28)
			lowerUp -= 1;
		else if (wParam == 0x25)
			leftUp += 1;
		else if (wParam == 0x27)
			leftUp -= 1;
		else if (wParam == VK_SPACE) {
			leftUp = 0;
			lowerUp = 0;
			glLoadIdentity();
		}

		break;
	default:
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
//--------------------------------------------------------------------

bool initPixelFormat(HDC hdc)
{
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

	pfd.cAlphaBits = 8;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.cStencilBits = 0;

	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;

	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;

	// choose pixel format returns the number most similar pixel format available
	int n = ChoosePixelFormat(hdc, &pfd);

	// set pixel format returns whether it sucessfully set the pixel format
	if (SetPixelFormat(hdc, n, &pfd))
	{
		return true;
	}
	else
	{
		return false;
	}
}
//--------------------------------------------------------------------

void question1()
{

	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	glScalef(0.5, 0.5, 1.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0, 1, 0);
	glVertex3f(1, 1, 0);
	glVertex3f(1, 0, 0);
	glVertex3f(0, 0, 0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0, 0, 0);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0, 1, 0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0, 1, 0);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(1, 1, 0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1, 1, 0);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(1, 0, 0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1, 0, 0);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0, 0, 0);
	glEnd();

	glPopMatrix();

	glRotatef(0.01, 1, 1, 1);
}

void question2()
{

	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	glScalef(0.5, 0.5, 1.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0, 1, 0);
	glVertex3f(1, 1, 0);
	glVertex3f(1, 0, 0);
	glVertex3f(0, 0, 0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0, 0, 0);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0, 1, 0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0, 1, 0);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(1, 1, 0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1, 1, 0);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(1, 0, 0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1, 0, 0);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0, 0, 0);
	glEnd();

	glPopMatrix();


}

void question3() {
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	glScalef(0.5, 0.5, 1.0);

	//LOWER ARM 
	glRotatef(leftUp, 0.5, 0.5, 0);

	glPushMatrix();
	glRotatef(lowerUp, 0.0, 1.0, 0.0);

	glBegin(GL_LINE_LOOP);
	glVertex3f(-1, 0, 0.5);
	glVertex3f(0, 0, 0.5);
	glVertex3f(0, 0, 0);
	glVertex3f(-1, 0, 0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(-1, 0, 0);
	glVertex3f(-1, 0.5, 0.0);
	glVertex3f(-1, 0.5, 0.5);
	glVertex3f(-1, 0, 0.5);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(-1, 0, 0.5);
	glVertex3f(-1, 0.5, 0.5);
	glVertex3f(0, 0.5, 0.5);
	glVertex3f(0, 0.0, 0.5);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(0, 0, 0.5);
	glVertex3f(0, 0.5, 0.5);
	glVertex3f(0, 0.5, 0);
	glVertex3f(0, 0, 0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(0, 0, 0);
	glVertex3f(-1, 0, 0);
	glVertex3f(-1, 0.5, 0);
	glVertex3f(0, 0.5, 0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(0, 0.5, 0);
	glVertex3f(-1, 0.5, 0);
	glVertex3f(-1, 0.5, 0.5);
	glVertex3f(0, 0.5, 0.5);
	glEnd();

	glPopMatrix();

	//Upper Arm

	glBegin(GL_LINE_LOOP);
	glVertex3f(0, 0, 0.5);
	glVertex3f(1, 0, 0.5);
	glVertex3f(1, 0, 0);
	glVertex3f(0, 0, 0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0.5, 0.0);
	glVertex3f(0, 0.5, 0.5);
	glVertex3f(0, 0, 0.5);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(0, 0, 0.5);
	glVertex3f(0, 0.5, 0.5);
	glVertex3f(1, 0.5, 0.5);
	glVertex3f(1, 0.0, 0.5);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(1, 0, 0.5);
	glVertex3f(1, 0.5, 0.5);
	glVertex3f(1, 0.5, 0);
	glVertex3f(1, 0, 0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(1, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0.5, 0);
	glVertex3f(1, 0.5, 0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(1, 0.5, 0);
	glVertex3f(0, 0.5, 0);
	glVertex3f(0, 0.5, 0.5);
	glVertex3f(1, 0.5, 0.5);
	glEnd();

	glPopMatrix();


}
//--------------------------------------------------------------------

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow)
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpfnWndProc = WindowProcedure;
	wc.lpszClassName = WINDOW_TITLE;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc)) return false;

	HWND hWnd = CreateWindow(WINDOW_TITLE, WINDOW_TITLE, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
		NULL, NULL, wc.hInstance, NULL);

	//--------------------------------
	//	Initialize window for OpenGL
	//--------------------------------

	HDC hdc = GetDC(hWnd);

	//	initialize pixel format for the window
	initPixelFormat(hdc);

	//	get an openGL context
	HGLRC hglrc = wglCreateContext(hdc);

	//	make context current
	if (!wglMakeCurrent(hdc, hglrc)) return false;

	//--------------------------------
	//	End initialization
	//--------------------------------

	ShowWindow(hWnd, nCmdShow);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if (displayKey == 1) {
			question1();
		}
		else if (displayKey == 2) {
			question2();
		}
		else if (displayKey == 3) {
			question3();
		}


		SwapBuffers(hdc);
	}

	UnregisterClass(WINDOW_TITLE, wc.hInstance);

	return true;
}
//--------------------------------------------------------------------