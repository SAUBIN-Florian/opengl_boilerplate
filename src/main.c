#include <stdio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define WIDTH 800
#define HEIGHT 600


void error_callback(int code, const char* msg) {
	(void) code;
	fprintf(stderr, "ERROR: %s\n", msg);
}

void key_callback(GLFWwindow* w, int key, int scancode, int action, int mods) {
	(void) key;
	(void) scancode;
	(void) mods;
	if (GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(w, GLFW_TRUE);
	}
}

void framebuffer_callback(GLFWwindow* w, int width, int height) {
	glViewport(0, 0, width, height);
}

int main() {
	printf("Open Gl Basic...\n");

	//SETUP
	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) {
		perror("ERROR: cannot initialize glfw");
		goto defer;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Open GL basic", NULL, NULL);
	if (!window) {
		perror("ERROR: cannot create window\n");
		goto defer;
	}
	
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_callback);
	if (glewInit() != GLEW_OK) {
		perror("ERROR: cannot initialize glew\n");
		goto defer;
	}

	// INIT
	

	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//DRAW


		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);

defer:
	glfwTerminate();

	return 0;
}
