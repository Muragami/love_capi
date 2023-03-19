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

#include "capi.h"

// Different window settings.
enum windowSetting
{
    SETTING_FULLSCREEN,
    SETTING_FULLSCREEN_TYPE,
    SETTING_VSYNC,
    SETTING_MSAA,
    SETTING_STENCIL,
    SETTING_DEPTH,
    SETTING_RESIZABLE,
    SETTING_MIN_WIDTH,
    SETTING_MIN_HEIGHT,
    SETTING_BORDERLESS,
    SETTING_CENTERED,
    SETTING_DISPLAY,
    SETTING_HIGHDPI,
    SETTING_USE_DPISCALE,
    SETTING_REFRESHRATE,
    SETTING_X,
    SETTING_Y,
    SETTING_MAX_ENUM
};

enum windowFullscreenType
{
    FULLSCREEN_EXCLUSIVE,
    FULLSCREEN_DESKTOP,
    FULLSCREEN_MAX_ENUM
};

enum windowMessageBoxType
{
    MESSAGEBOX_ERROR,
    MESSAGEBOX_WARNING,
    MESSAGEBOX_INFO,
    MESSAGEBOX_MAX_ENUM
};

enum windowDisplayOrientation
{
    ORIENTATION_UNKNOWN,
    ORIENTATION_LANDSCAPE,
    ORIENTATION_LANDSCAPE_FLIPPED,
    ORIENTATION_PORTRAIT,
    ORIENTATION_PORTRAIT_FLIPPED,
    ORIENTATION_MAX_ENUM
};

typedef struct _windowSize {
    int width;
    int height;
} windowSize;

typedef struct _windowSettings
{
    int fullscreen;
    enum windowFullscreenType fstype;
    int vsync;
    int msaa;
    int stencil;
    int depth;
    int resizable;
    int minwidth;
    int minheight;
    int borderless;
    int centered;
    int displayindex;
    int highdpi;
    int usedpiscale;
    double refreshrate;
    int useposition;
    int x;
    int y;
} windowSettings;

extern const windowSettings DefaultWindowSettings;

LoveObject *windowNew(loveErrorHandler err, void *user);
void windowDelete(LoveObject *win);
void windowSetDefaultSettings(windowSettings *settings);
int windowSetWindow(LoveObject *win, int width, int height, windowSettings *settings);
void windowGetWindow(LoveObject *win, int *width, int *height, windowSettings *settings);
void windowClose(LoveObject *win);
int windowSetFullscreenType(LoveObject *win, int fullscreen, enum windowFullscreenType fstype);
int windowSetFullscreen(LoveObject *win, int fullscreen);
// int onSizeChanged(int width, int height) ;
int windowGetDisplayCount(LoveObject *win);
const char *windowGetDisplayName(LoveObject *win, int displayindex);
enum windowDisplayOrientation windowGetDisplayOrientation(LoveObject *win, int displayindex);
// wrap the C++ STL for this one
typedef void (*windowFullscreenSizeCallback)(int i, windowSize sz, void *upointer);
void windowGetFullscreenSizes(LoveObject *win, int displayindex, windowFullscreenSizeCallback callback, void *upointer);
void windowGetDesktopDimensions(LoveObject *win, int displayindex, int *width, int *height);
void windowSetPosition(LoveObject *win, int x, int y, int displayindex);
void windowGetPosition(LoveObject *win, int *x, int *y, int *displayindex);
// Rect windowGetSafeArea();
int windowIsOpen(LoveObject *win);
void windowSetWindowTitle(LoveObject *win, const char *title);
const char*windowGetWindowTitle(LoveObject *win);
// int windowSetIcon(love::image::ImageData *imgd);
// love::image::ImageData *getIcon() ;
void windowSetVSync(LoveObject *win, int vsync);
int windowGetVSync(LoveObject *win);
void windowSetDisplaySleepEnabled(LoveObject *win, int enable);
int windowIsDisplaySleepEnabled(LoveObject *win);
void windowMinimize(LoveObject *win);
void windowMaximize(LoveObject *win);
void windowRestore(LoveObject *win);
int windowIsMaximized(LoveObject *win);
int windowIsMinimized(LoveObject *win);
int windowHasFocus(LoveObject *win);
int windowHasMouseFocus(LoveObject *win);
int windowIsVisible(LoveObject *win);
void windowSetMouseGrab(LoveObject *win, int grab);
int windowIsMouseGrabbed(LoveObject *win);
// Note: window-space coordinates are not necessarily the same as
// density-independent units (which toPixels and fromPixels use.)
void windowWindowToPixelCoords(LoveObject *win, double *x, double *y);
void windowPixelToWindowCoords(LoveObject *win, double *x, double *y);
void windowWindowToDPICoords(LoveObject *win, double *x, double *y);
void windowDPIToWindowCoords(LoveObject *win, double *x, double *y);
double windowGetDPIScale(LoveObject *win);
double windowGetNativeDPIScale(LoveObject *win);
double windowToPixels(LoveObject *win, double x);
void windowToPixelsXY(LoveObject *win, double wx, double wy, double *px, double *py);
double windowFromPixels(LoveObject *win, double x);
void windowFromPixelsXY(LoveObject *win, double px, double py, double *wx, double *wy);
void *windowGetHandle(LoveObject *win);
int windowShowMessageBox(LoveObject *win, const char *title, const char *message, enum windowMessageBoxType type, int attachtowindow);
void windowRequestAttention(LoveObject *win, int continuous);
