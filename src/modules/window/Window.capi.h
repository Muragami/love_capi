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

#ifndef TRUE 
#define TRUE 1
#endif

#ifndef FALSE 
#define FALSE 0
#endif

// Different window settings.
enum loveWindowSetting
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

enum loveWindowFullscreenType
{
    FULLSCREEN_EXCLUSIVE,
    FULLSCREEN_DESKTOP,
    FULLSCREEN_MAX_ENUM
};

enum loveWindowMessageBoxType
{
    MESSAGEBOX_ERROR,
    MESSAGEBOX_WARNING,
    MESSAGEBOX_INFO,
    MESSAGEBOX_MAX_ENUM
};

enum loveWindowDisplayOrientation
{
    ORIENTATION_UNKNOWN,
    ORIENTATION_LANDSCAPE,
    ORIENTATION_LANDSCAPE_FLIPPED,
    ORIENTATION_PORTRAIT,
    ORIENTATION_PORTRAIT_FLIPPED,
    ORIENTATION_MAX_ENUM
};

typedef struct _loveWindowSize {
    int width;
    int height;
} loveWindowSize;

typedef struct _WindowSettings
{
    int fullscreen;
    loveWindowFullscreenType fstype;
    int vsync;
    int msaa;
    int stencil;
    int depth;
    int resizable;
    int minwidth;
    int minheight;
    int borderless;
    int centered;
    int display;
    int highdpi;
    int usedpiscale;
    double refreshrate;
    int useposition;
    int x;
    int y;
} WindowSettings;

extern const WindowSettings DefaultWindowSettings;

void *loveWindowNew();
void loveWindowDelete(void *win);
int loveWindowSetWindow(void *win, int width, int height, WindowSettings *settings);
void loveWindowGetWindow(void *win, int &width, int &height, WindowSettings &settings);
void loveWindowClose(void *win);
int loveWindowSetFullscreenType(void *win, int fullscreen, loveWindowFullscreenType fstype);
int loveWindowSetFullscreen(void *win, int fullscreen);
// int onSizeChanged(int width, int height) ;
int loveWindowGetDisplayCount(void *win);
 char *loveWindowGetDisplayName(void *win, int displayindex);
loveWindowDisplayOrientation loveWindowGetDisplayOrientation(void *win, int displayindex);
// wrap the C++ STL for this one
typedef void (*loveWindowFullscreenSizeCallback)(int i, loveWindowSize sz, void *upointer);
void loveWindowGetFullscreenSizes(void *win, int displayindex, loveWindowFullscreenSizeCallback callback, void *upointer);
void loveWindowGetDesktopDimensions(void *win, int displayindex, int &width, int &height);
void loveWindowSetPosition(void *win, int x, int y, int displayindex);
void loveWindowGetPosition(void *win, int &x, int &y, int &displayindex);
// Rect loveWindowGetSafeArea();
int loveWindowIsOpen(void *win);
void loveWindowSetWindowTitle(void *win, const char *title);
const char*loveWindowGetWindowTitle(void *win);
// int loveWindowSetIcon(love::image::ImageData *imgd);
// love::image::ImageData *getIcon() ;
void loveWindowSetVSync(void *win, int vsync);
int loveWindowGetVSync(void *win);
void loveWindowSetDisplaySleepEnabled(void *win, int enable);
int loveWindowIsDisplaySleepEnabled(void *win);
void loveWindowMinimize(void *win);
void loveWindowMaximize(void *win);
void loveWindowRestore(void *win);
int loveWindowIsMaximized(void *win);
int loveWindowIsMinimized(void *win);
int loveWindowHasFocus(void *win);
int loveWindowHasMouseFocus(void *win);
int loveWindowIsVisible(void *win);
void loveWindowSetMouseGrab(void *win, int grab);
int loveWindowIsMouseGrabbed(void *win);
int loveWindowGetWidth(void *win);
int loveWindowGetHeight(void *win);
int loveWindowGetPixelWidth(void *win);
int loveWindowGetPixelHeight(void *win);
// Note: window-space coordinates are not necessarily the same as
// density-independent units (which toPixels and fromPixels use.)
void loveWindowWindowToPixelCoords(void *win, double *x, double *y);
void loveWindowPixelToWindowCoords(void *win, double *x, double *y);
void loveWindowWindowToDPICoords(void *win, double *x, double *y);
void loveWindowDPIToWindowCoords(void *win, double *x, double *y);
double loveWindowGetDPIScale(void *win);
double loveWindowGetNativeDPIScale(void *win);
double loveWindowToPixels(void *win, double x);
void loveWindowToPixelsXY(void *win, double wx, double wy, double &px, double &py);
double loveWindowFromPixels(void *win, double x);
void loveWindowFromPixelsXY(void *win, double px, double py, double &wx, double &wy);
void *loveWindowGetHandle(void *win);
int loveWindowShowMessageBox(void *win, const char *title, const char *message, loveWindowMessageBoxType type, int attachtowindow);
void loveWindowRequestAttention(void *win, int continuous);