/**
 * Copyright (c) 2006-2023 LOVE Development Team
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 **/

// LOVE
#include "sdl/Window.h"

const windowSettings DefaultWindowSettings = {
    false, FULLSCREEN_DESKTOP, 1, 0, TRUE, 0, FALSE, 1, 1, FALSE, TRUE, 0, FALSE, TRUE, 0, FALSE, 0, 0
};

#define instance() (love::Module::getInstance<love::window::Window>(love::Module::M_WINDOW))

LoveObject *windowNew(loveErrorHandler err, void *user) {
    LoveObject *ret = (LoveObject*)malloc(sizeof(LoveObject));

    love::window::Window *instance = instance();
    if (instance == nullptr)
        instance = new love::window::sdl::Window();
    else
        instance->retain();

    ret->type = instance()->type.getId();
    ret->obj = instance();
    ret->eHandle = err;
    ret->eMessage = NULL;
    ret->upointer = user;
    return ret;
}

void windowDelete(LoveObject *win) {
    free(win);
}

void windowSetDefaultSettings(windowSettings *settings) {
    memcpy(settings, &DefaultWindowSettings, sizeof(windowSettings));
}

int windowSetWindow(LoveObject *win, int width, int height, windowSettings *settings) {
    bool success = false;
    try {
        success = instance()->setWindow(width, height, settings);    
    } catch (love::Exception e) {
        win->eMessage = e.what();
        if (win->eHandle != NULL)
            win->eHandle(win, win->eMessage, win->upointer);
    }
    return success == true ? TRUE : FALSE;
}

void windowGetWindow(LoveObject *win, int *width, int *height, windowSettings *settings) {
    int w, h;
    windowSettings set;
    instance()->getWindow(w, h, set);
    memcpy(settings, &set, sizeof(windowSettings));
    *width = w;
    *height = h;
}

void windowClose(LoveObject *win) {
    try {
        instance()->close();    
    } catch (love::Exception e) {
        win->eMessage = e.what();
        if (win->eHandle != NULL)
            win->eHandle(win, win->eMessage, win->upointer);
    }
}

int windowSetFullscreenType(LoveObject *win, int fullscreen, windowFullscreenType fstype) {
    bool success = false;
    try {
        success = instance()->setFullscreen(fullscreen, fstype);
    } catch (love::Exception e) {
        win->eMessage = e.what();
        if (win->eHandle != NULL)
            win->eHandle(win, win->eMessage, win->upointer);
    }
    return success == true ? TRUE : FALSE;
}

int windowSetFullscreen(LoveObject *win, int fullscreen) {
    bool success = false;
    try {
        success = instance()->setFullscreen(fullscreen);
    } catch (love::Exception e) {
        win->eMessage = e.what();
        if (win->eHandle != NULL)
            win->eHandle(win, win->eMessage, win->upointer);
    }
    return success == true ? TRUE : FALSE;
}

// int onSizeChanged(int width, int height) ;
int windowGetDisplayCount(LoveObject *win) {
    return instance()->getDisplayCount();
}

const char *windowGetDisplayName(LoveObject *win, int displayindex) {
    const char *name = NULL;
    try {
        name = instance()->getDisplayName(displayindex);
    } catch (love::Exception e) {
        win->eMessage = e.what();
        if (win->eHandle != NULL)
            win->eHandle(win, win->eMessage, win->upointer);
    }
    return name;
}

windowDisplayOrientation windowGetDisplayOrientation(LoveObject *win, int displayindex) {
    return instance()->getDisplayOrientation(displayindex);
}

void windowGetFullscreenSizes(LoveObject *win, int displayindex, windowFullscreenSizeCallback callback, void *upointer) {
    std::vector<love::window::Window::WindowSize> modes = instance()->getFullscreenSizes(displayindex);
    windowSize lsz;
    int i = 0;
    for(love::window::Window::WindowSize sz : modes) {
        lsz.width = sz.width;
        lsz.height = sz.height;
        callback(i, lsz, upointer);
        i++;
    }
}

void windowGetDesktopDimensions(LoveObject *win, int displayindex, int *width, int *height) {
    int w = 0, h = 0;
    instance()->getDesktopDimensions(displayindex, w, h);
    *width = w;
    *height = h;
}

void windowSetPosition(LoveObject *win, int x, int y, int displayindex) {
    instance()->setPosition(x, y, displayindex);
}

void windowGetPosition(LoveObject *win, int *x, int *y, int *displayindex) {
    int ix, iy, d;
    instance()->getPosition(ix, iy, d);
    *x = ix;
    *y = iy;
    *displayindex = d;
}

// Rect windowGetSafeArea();
int windowIsOpen(LoveObject *win) {
    return instance()->isOpen() == true ? TRUE : FALSE;
}

void windowSetWindowTitle(LoveObject *win, const char *title) {
    instance()->setWindowTitle(title);
}

const char*windowGetWindowTitle(LoveObject *win) {
    return instance()->getWindowTitle().c_str();
}

// int windowSetIcon(love::image::ImageData *imgd);
// love::image::ImageData *getIcon() ;

void windowSetVSync(LoveObject *win, int vsync) {
    instance()->setVSync(vsync);
}

int windowGetVSync(LoveObject *win) {
    return instance()->getVSync() == true ? TRUE : FALSE;
}

void windowSetDisplaySleepEnabled(LoveObject *win, int enable) {
    instance()->setDisplaySleepEnabled(enable);
}

int windowIsDisplaySleepEnabled(LoveObject *win) {
    return instance()->isDisplaySleepEnabled() == true ? TRUE : FALSE;
}

void windowMinimize(LoveObject *win) {
    instance()->minimize();
}

void windowMaximize(LoveObject *win) {
    instance()->maximize();
}

void windowRestore(LoveObject *win) {
    instance()->restore();
}

int windowIsMaximized(LoveObject *win) {
    return instance()->isMaximized() == true ? TRUE : FALSE;

}

int windowIsMinimized(LoveObject *win) {
    return instance()->isMinimized() == true ? TRUE : FALSE;
}

int windowHasFocus(LoveObject *win) {
    return instance()->hasFocus() == true ? TRUE : FALSE;
}

int windowHasMouseFocus(LoveObject *win) {
    return instance()->hasMouseFocus() == true ? TRUE : FALSE;
}

int windowIsVisible(LoveObject *win) {
    return instance()->isVisible() == true ? TRUE : FALSE;
}

void windowSetMouseGrab(LoveObject *win, int grab) {
    instance()->setMouseGrab(grab);
}

int windowIsMouseGrabbed(LoveObject *win) {
    return instance()->isMouseGrabbed() == true ? TRUE : FALSE;
}

double windowGetDPIScale(LoveObject *win) {
    return instance()->getDPIScale();
}

double windowGetNativeDPIScale(LoveObject *win) {
    return instance()->getNativeDPIScale();
}

double windowToPixels(LoveObject *win, double x) {
    return instance()->toPixels(x);
}

void windowToPixelsXY(LoveObject *win, double wx, double wy, double *px, double *py) {
    double _px, _py;
    instance()->toPixels(wx, wy, _px, _py);
    *px = _px;
    *py = _py;
}

double windowFromPixels(LoveObject *win, double x) {
    return instance()->fromPixels(x);
}

void windowFromPixelsXY(LoveObject *win, double px, double py, double *wx, double *wy) {
    double _wx, _wy;
    instance()->fromPixels(px, py, _wx, _wy);
    *wx = _wx;
    *wy = _wy;
}

const void *windowGetHandle(LoveObject *win) {
    return instance()->getHandle();
}

int windowShowMessageBox(LoveObject *win, const char *title, const char *message, windowMessageBoxType type, int attachtowindow) {
    bool ret;
    ret = instance()->showMessageBox(title, message, type, attachtowindow);
    return ret == true ? TRUE : FALSE;
}

void windowRequestAttention(LoveObject *win, int continuous) {
    instance()->requestAttention(continuous);
}
