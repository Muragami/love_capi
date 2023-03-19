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

#ifndef LOVE_WINDOW_WINDOW_H
#define LOVE_WINDOW_WINDOW_H

// LOVE
#include "common/Module.h"
#include "common/StringMap.h"
#include "common/math.h"
#include "common/Optional.h"
#include "image/ImageData.h"

// C++
#include <string>
#include <vector>

// CAPI
extern "C" {
#include "Window.capi.h"	
}

namespace love
{

namespace graphics
{
class Graphics;
}

namespace window
{

// Applied when the window is first created.
void setHighDPIAllowed(bool enable);
bool isHighDPIAllowed();

class Window : public Module
{
public:

	struct WindowSize
	{
		int width;
		int height;

		bool operator == (const WindowSize &w) const
		{
			return w.width == width && w.height == height;
		}
	};

	struct MessageBoxData
	{
		windowMessageBoxType type;

		std::string title;
		std::string message;

		std::vector<std::string> buttons;
		int enterButtonIndex;
		int escapeButtonIndex;

		bool attachToWindow;
	};

	virtual ~Window();

	// Implements Module.
	virtual ModuleType getModuleType() const { return M_WINDOW; }

	virtual void setGraphics(graphics::Graphics *graphics) = 0;

	virtual bool setWindow(int width = 800, int height = 600, windowSettings *settings = nullptr) = 0;
	virtual void getWindow(int &width, int &height, windowSettings &settings) = 0;

	virtual void close() = 0;

	virtual bool setFullscreen(bool fullscreen, windowFullscreenType fstype) = 0;
	virtual bool setFullscreen(bool fullscreen) = 0;

	virtual bool onSizeChanged(int width, int height) = 0;

	virtual int getDisplayCount() const = 0;

	virtual const char *getDisplayName(int displayindex) const = 0;

	virtual windowDisplayOrientation getDisplayOrientation(int displayindex) const = 0;

	virtual std::vector<WindowSize> getFullscreenSizes(int displayindex) const = 0;

	virtual void getDesktopDimensions(int displayindex, int &width, int &height) const = 0;

	virtual void setPosition(int x, int y, int displayindex) = 0;
	virtual void getPosition(int &x, int &y, int &displayindex) = 0;

	virtual Rect getSafeArea() const = 0;

	virtual bool isOpen() const = 0;

	virtual void setWindowTitle(const std::string &title) = 0;
	virtual const std::string &getWindowTitle() const = 0;

	virtual bool setIcon(love::image::ImageData *imgd) = 0;
	virtual love::image::ImageData *getIcon() = 0;

	virtual void setVSync(int vsync) = 0;
	virtual int getVSync() const = 0;

	virtual void setDisplaySleepEnabled(bool enable) = 0;
	virtual bool isDisplaySleepEnabled() const = 0;

	virtual void minimize() = 0;
	virtual void maximize() = 0;
	virtual void restore() = 0;

	virtual bool isMaximized() const = 0;
	virtual bool isMinimized() const = 0;

	// default no-op implementation
	virtual void swapBuffers();

	virtual bool hasFocus() const = 0;
	virtual bool hasMouseFocus() const = 0;

	virtual bool isVisible() const = 0;

	virtual void setMouseGrab(bool grab) = 0;
	virtual bool isMouseGrabbed() const = 0;

	virtual int getWidth() const = 0;
	virtual int getHeight() const = 0;
	virtual int getPixelWidth() const = 0;
	virtual int getPixelHeight() const = 0;

	// Note: window-space coordinates are not necessarily the same as
	// density-independent units (which toPixels and fromPixels use.)
	virtual void windowToPixelCoords(double *x, double *y) const = 0;
	virtual void pixelToWindowCoords(double *x, double *y) const = 0;

	virtual void windowToDPICoords(double *x, double *y) const = 0;
	virtual void DPIToWindowCoords(double *x, double *y) const = 0;

	virtual double getDPIScale() const = 0;
	virtual double getNativeDPIScale() const = 0;

	virtual double toPixels(double x) const = 0;
	virtual void toPixels(double wx, double wy, double &px, double &py) const = 0;
	virtual double fromPixels(double x) const = 0;
	virtual void fromPixels(double px, double py, double &wx, double &wy) const = 0;

	virtual const void *getHandle() const = 0;

	virtual bool showMessageBox(const std::string &title, const std::string &message, windowMessageBoxType type, bool attachtowindow) = 0;
	virtual int showMessageBox(const MessageBoxData &data) = 0;

	virtual void requestAttention(bool continuous) = 0;

	static bool getConstant(const char *in, windowSetting &out);
	static bool getConstant(windowSetting in, const char *&out);

	static bool getConstant(const char *in, windowFullscreenType &out);
	static bool getConstant(windowFullscreenType in, const char *&out);
	static std::vector<std::string> getConstants(windowFullscreenType);

	static bool getConstant(const char *in, windowMessageBoxType &out);
	static bool getConstant(windowMessageBoxType in, const char *&out);
	static std::vector<std::string> getConstants(windowMessageBoxType);

	static bool getConstant(const char *in, windowDisplayOrientation &out);
	static bool getConstant(windowDisplayOrientation in, const char *&out);
	static std::vector<std::string> getConstants(windowDisplayOrientation);

private:

	static StringMap<windowSetting, SETTING_MAX_ENUM>::Entry settingEntries[];
	static StringMap<windowSetting, SETTING_MAX_ENUM> settings;

	static StringMap<windowFullscreenType, FULLSCREEN_MAX_ENUM>::Entry fullscreenTypeEntries[];
	static StringMap<windowFullscreenType, FULLSCREEN_MAX_ENUM> fullscreenTypes;

	static StringMap<windowMessageBoxType, MESSAGEBOX_MAX_ENUM>::Entry messageBoxTypeEntries[];
	static StringMap<windowMessageBoxType, MESSAGEBOX_MAX_ENUM> messageBoxTypes;

	static StringMap<windowDisplayOrientation, ORIENTATION_MAX_ENUM>::Entry orientationEntries[];
	static StringMap<windowDisplayOrientation, ORIENTATION_MAX_ENUM> orientations;

}; // Window


} // window
} // love

#endif // LOVE_WINDOW_WINDOW_H
