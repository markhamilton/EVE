/*
 * Ork: a small object-oriented OpenGL Rendering Kernel.
 * Copyright (c) 2008-2010 INRIA
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or (at
 * your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA.
 */

/*
 * Authors: Eric Bruneton, Antoine Begault, Guillaume Piolat.
 */

#include "ork/ui/GlutWindow.h"

#include "ork/core/Logger.h"

#include <GL/glew.h>

#ifdef USEFREEGLUT
#include <GL/freeglut.h>
#else
#include <GL/glut.h>
#endif

#include <assert.h>

#ifndef GLUT_WHEEL_UP
#define GLUT_WHEEL_UP_BUTTON 0x0003
#endif

#ifndef GLUT_WHEEL_DOWN
#define GLUT_WHEEL_DOWN_BUTTON 0x0004
#endif

#ifndef CALLBACK
#define CALLBACK
#endif

using namespace std;

namespace ork
{

void CALLBACK debugCallback(unsigned int source, unsigned int type,
    unsigned int id, unsigned int severity,
    int length, const char* message, void* userParam)
{
    char debSource[16];
    switch (source) {
    case GL_DEBUG_SOURCE_API_ARB:
        strcpy(debSource, "OPENGL");
        break;
    case GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB:
        strcpy(debSource, "WINDOWS");
        break;
    case GL_DEBUG_SOURCE_SHADER_COMPILER_ARB:
        strcpy(debSource, "COMPILER");
        break;
    case GL_DEBUG_SOURCE_THIRD_PARTY_ARB:
        strcpy(debSource, "LIBRARY");
        break;
    case GL_DEBUG_SOURCE_APPLICATION_ARB:
        strcpy(debSource, "APPLICATION");
        break;
    //case GL_DEBUG_SOURCE_OTHER_ARB:
    default:
        strcpy(debSource, "UNKNOWN");
    }

    char debType[20];
    switch (type) {
    case GL_DEBUG_TYPE_ERROR_ARB:
        strcpy(debType, "Error");
        break;
    case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB:
        strcpy(debType, "Deprecated behavior");
        break;
    case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB:
        strcpy(debType, "Undefined behavior");
        break;
    case GL_DEBUG_TYPE_PORTABILITY_ARB:
        strcpy(debType, "Portability");
        break;
    case GL_DEBUG_TYPE_PERFORMANCE_ARB:
        strcpy(debType, "Performance");
        break;
    //case GL_DEBUG_TYPE_OTHER_ARB:
    default:
        strcpy(debType, "Other");
    }

    if (severity == GL_DEBUG_SEVERITY_HIGH_ARB && Logger::ERROR_LOGGER != NULL) {
        Logger::ERROR_LOGGER->logf(debSource, "%s: %s", debType, message);
    }
    if (severity == GL_DEBUG_SEVERITY_MEDIUM_ARB && Logger::WARNING_LOGGER != NULL) {
        Logger::WARNING_LOGGER->logf(debSource, "%s: %s", debType, message);
    }
    if (severity == GL_DEBUG_SEVERITY_LOW_ARB && Logger::INFO_LOGGER != NULL) {
        Logger::INFO_LOGGER->logf(debSource, "%s: %s", debType, message);
    }
}

map<int, GlutWindow*> GlutWindow::INSTANCES;

GlutWindow::GlutWindow(const Parameters &params) : Window(params)
{
    int argc = 1;
    char *argv[1] = { (char*) "dummy" };
    if (INSTANCES.size() == 0) {
        glutInit(&argc, argv);
    }
    glutInitDisplayMode(GLUT_DOUBLE |
        (params.alpha() ? GLUT_ALPHA : 0) |
        (params.depth() ? GLUT_DEPTH : 0) |
        (params.stencil() ? GLUT_STENCIL : 0) |
        (params.multiSample() ? GLUT_MULTISAMPLE : 0));

#ifdef USEFREEGLUT
    //Init OpenGL context
    glutInitContextVersion(params.version().x, params.version().y);
    glutInitContextProfile(GLUT_CORE_PROFILE);
    glutInitContextFlags(GLUT_FORWARD_COMPATIBLE | (params.debug() ? GLUT_DEBUG : 0));
#endif

    glutInitWindowSize(params.width(), params.height());
    windowId = glutCreateWindow(params.name().c_str());
    size = vec2i(params.width(), params.height());
    damaged = false;
    timer.start();
    t = 0.0;
    dt = 0.0;

    if (params.width() == 0 && params.height() == 0) {
        glutFullScreen();
    }
    if (false) {
        glutCreateMenu(NULL);//do nothing, only used to avoid a warning
    }

    INSTANCES[windowId] = this;
    glutDisplayFunc(redisplayFunc);
    glutReshapeFunc(reshapeFunc);
    glutIdleFunc(idleFunc);
    glutMouseFunc(mouseClickFunc);
    glutMotionFunc(mouseMotionFunc);
    glutPassiveMotionFunc(mousePassiveMotionFunc);
    glutKeyboardFunc(keyboardFunc);
    glutKeyboardUpFunc(keyboardUpFunc);
    glutSpecialFunc(specialKeyFunc);
    glutSpecialUpFunc(specialKeyUpFunc);
    glutIgnoreKeyRepeat(1);

    // should be mouse enter/leave events,
    // but implemented in freeglut with get/loose focus
    glutEntryFunc(focusFunc);

    assert(glGetError() == 0);
    glewExperimental = GL_TRUE;
    glewInit();
    glGetError();

#ifdef USEFREEGLUT
    if (params.debug()) {
        assert(glDebugMessageCallbackARB != NULL);
        glDebugMessageCallbackARB(debugCallback, NULL);
    }
#endif
}

GlutWindow::~GlutWindow()
{
#ifdef USEFREEGLUT
    glutDestroyWindow(windowId);
    glutLeaveMainLoop();
#endif
    INSTANCES.erase(windowId);
}

int GlutWindow::getWidth() const
{
    return size.x;
}

int GlutWindow::getHeight() const
{
    return size.y;
}

void GlutWindow::start()
{
    glutMainLoop();
}

void GlutWindow::redisplay(double t, double dt)
{
    glutSwapBuffers();
    double newT = timer.end();
    this->dt = newT - this->t;
    this->t = newT;
}

void GlutWindow::reshape(int x, int y)
{
    size = vec2i(x, y);
}

void GlutWindow::idle(bool damaged)
{
    glutPostRedisplay();
}

void GlutWindow::redisplayFunc()
{
    GlutWindow* window = INSTANCES[glutGetWindow()];
    window->redisplay(window->t, window->dt);
}

void GlutWindow::reshapeFunc(int x, int y)
{
    INSTANCES[glutGetWindow()]->reshape(x, y);
}

void GlutWindow::idleFunc()
{
    GlutWindow *window = INSTANCES[glutGetWindow()];
    // glutLayerGet(GLUT_NORMAL_DAMAGED) is not implemented in freeglut
    //window->idle(glutLayerGet(GLUT_NORMAL_DAMAGED) == 1);
    window->idle(window->damaged);
    window->damaged = false;
}

void GlutWindow::mouseClickFunc(int b, int s, int x, int y)
{
    int m = glutGetModifiers();

#ifdef GLUT_WHEEL_UP
    if (b == GLUT_WHEEL_UP) {
#else
    if (b == GLUT_WHEEL_UP_BUTTON) {
        if (s == 0)
#endif
        INSTANCES[glutGetWindow()]->mouseWheel(WHEEL_UP, (modifier) m, x, y);
        return;
    }

#ifdef GLUT_WHEEL_DOWN
    if (b == GLUT_WHEEL_DOWN) {
#else
    if (b == GLUT_WHEEL_DOWN_BUTTON) {
        if (s == 0)
#endif
        INSTANCES[glutGetWindow()]->mouseWheel(WHEEL_DOWN, (modifier) m, x, y);
        return;
    }

    INSTANCES[glutGetWindow()]->mouseClick((button) b, (state) s, (modifier) m, x, y);
}

void GlutWindow::mouseMotionFunc(int x, int y)
{
    INSTANCES[glutGetWindow()]->mouseMotion(x, y);
}

void GlutWindow::mousePassiveMotionFunc(int x, int y)
{
    INSTANCES[glutGetWindow()]->mousePassiveMotion(x, y);
}

void GlutWindow::keyboardFunc(unsigned char c, int x, int y)
{
    int m = glutGetModifiers();
    INSTANCES[glutGetWindow()]->keyTyped(c, (modifier) m, x, y);
}

void GlutWindow::keyboardUpFunc(unsigned char c, int x, int y)
{
    int m = glutGetModifiers();
    INSTANCES[glutGetWindow()]->keyReleased(c, (modifier) m, x, y);
}

void GlutWindow::specialKeyFunc(int k, int x, int y)
{
    int m = glutGetModifiers();
    INSTANCES[glutGetWindow()]->specialKey((key) k, (modifier) m, x, y);
}

void GlutWindow::specialKeyUpFunc(int k, int x, int y)
{
    int m = glutGetModifiers();
    INSTANCES[glutGetWindow()]->specialKeyReleased((key) k, (modifier) m, x, y);
}

void GlutWindow::focusFunc(int focus)
{
    INSTANCES[glutGetWindow()]->damaged = (focus != 0);
}

}
