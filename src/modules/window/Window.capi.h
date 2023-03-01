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
    bool fullscreen = false;
    loveWindowFullscreenType fstype = FULLSCREEN_DESKTOP;
    int vsync = 1;
    int msaa;
    bool stencil = true;
    int depth;
    bool resizable = false;
    int minwidth = 1;
    int minheight = 1;
    bool borderless = false;
    bool centered = true;
    int display;
    bool highdpi = false;
    bool usedpiscale = true;
    double refreshrate = 0;
    bool useposition = false;
    int x;
    int y;
} WindowSettings;

void *loveWindowNew();
void loveWindowDelete();
bool loveWindowSetWindow(int width = 800, int height = 600, WindowSettings *settings = nullptr);
void loveWindowGetWindow(int &width, int &height, WindowSettings &settings);
void loveWindowClose();
bool loveWindowSetFullscreenType(bool fullscreen, loveWindowFullscreenType fstype);
bool loveWindowSetFullscreen(bool fullscreen);
// bool onSizeChanged(int width, int height) ;
int loveWindowGetDisplayCount();
 char *loveWindowGetDisplayName(int displayindex);
loveWindowDisplayOrientation loveWindowGetDisplayOrientation(int displayindex);
// wrap the C++ STL for this one
typedef void (*loveWindowFullscreenSizeCallback)(int i, loveWindowSize sz);
void loveWindowGetFullscreenSizes(int displayindex, loveWindowFullscreenSizeCallback callback);
void loveWindowGetDesktopDimensions(int displayindex, int &width, int &height)  ;
void loveWindowSetPosition(int x, int y, int displayindex) ;
void loveWindowGetPosition(int &x, int &y, int &displayindex) ;
// Rect loveWindowGetSafeArea();
bool loveWindowIsOpen();
void loveWindowSetWindowTitle(const char *title);
const char*loveWindowGetWindowTitle();
// bool loveWindowSetIcon(love::image::ImageData *imgd);
// love::image::ImageData *getIcon() ;
void loveWindowSetVSync(int vsync);
int loveWindowGetVSync();
void loveWindowSetDisplaySleepEnabled(bool enable);
bool loveWindowIsDisplaySleepEnabled();
void loveWindowMinimize();
void loveWindowMaximize();
void loveWindowRestore();
bool loveWindowIsMaximized();
bool loveWindowIsMinimized();
bool loveWindowHasFocus();
bool loveWindowHasMouseFocus();
bool loveWindowIsVisible();
void loveWindowSetMouseGrab(bool grab);
bool loveWindowIsMouseGrabbed();
int loveWindowGetWidth();
int loveWindowGetHeight();
int loveWindowGetPixelWidth();
int loveWindowGetPixelHeight();
// Note: window-space coordinates are not necessarily the same as
// density-independent units (which toPixels and fromPixels use.)
void loveWindowWindowToPixelCoords(double *x, double *y);
void loveWindowPixelToWindowCoords(double *x, double *y);
void loveWindowWindowToDPICoords(double *x, double *y);
void loveWindowDPIToWindowCoords(double *x, double *y);
double loveWindowGetDPIScale();
double loveWindowGetNativeDPIScale();
double loveWindowToPixels(double x);
void loveWindowToPixelsXY(double wx, double wy, double &px, double &py);
double loveWindowFromPixels(double x);
void loveWindowFromPixelsXY(double px, double py, double &wx, double &wy);
void *loveWindowGetHandle();
bool loveWindowShowMessageBox(const char *title, const char *message, loveWindowMessageBoxType type, bool attachtowindow);
void loveWindowRequestAttention(bool continuous);