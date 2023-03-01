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
#include "Window.h"

namespace love
{
namespace window
{


static bool highDPIAllowed = false;

// TODO: find a cleaner way to do this...
// The window backend (e.g. love.window.sdl) is expected to implement this.
void setHighDPIAllowedImplementation(bool enable);

void setHighDPIAllowed(bool enable)
{
	setHighDPIAllowedImplementation(enable);
	highDPIAllowed = enable;
}

bool isHighDPIAllowed()
{
	return highDPIAllowed;
}

Window::~Window()
{
}

void Window::swapBuffers()
{
}

bool Window::getConstant(const char *in, loveWindowFullscreenType &out)
{
	return fullscreenTypes.find(in, out);
}

bool Window::getConstant(loveWindowFullscreenType in, const char *&out)
{
	return fullscreenTypes.find(in, out);
}

std::vector<std::string> Window::getConstants(loveWindowFullscreenType)
{
	return fullscreenTypes.getNames();
}

bool Window::getConstant(const char *in, loveWindowSetting &out)
{
	return settings.find(in, out);
}

bool Window::getConstant(loveWindowSetting in, const char *&out)
{
	return settings.find(in, out);
}

bool Window::getConstant(const char *in, loveWindowMessageBoxType &out)
{
	return messageBoxTypes.find(in, out);
}

bool Window::getConstant(loveWindowMessageBoxType in, const char *&out)
{
	return messageBoxTypes.find(in, out);
}

std::vector<std::string> Window::getConstants(loveWindowMessageBoxType)
{
	return messageBoxTypes.getNames();
}

bool Window::getConstant(const char *in, loveWindowDisplayOrientation &out)
{
	return orientations.find(in, out);
}

bool Window::getConstant(loveWindowDisplayOrientation in, const char *&out)
{
	return orientations.find(in, out);
}

std::vector<std::string> Window::getConstants(loveWindowDisplayOrientation)
{
	return orientations.getNames();
}

StringMap<loveWindowSetting, SETTING_MAX_ENUM>::Entry Window::settingEntries[] =
{
	{"fullscreen", SETTING_FULLSCREEN},
	{"fullscreentype", SETTING_FULLSCREEN_TYPE},
	{"vsync", SETTING_VSYNC},
	{"msaa", SETTING_MSAA},
	{"stencil", SETTING_STENCIL},
	{"depth", SETTING_DEPTH},
	{"resizable", SETTING_RESIZABLE},
	{"minwidth", SETTING_MIN_WIDTH},
	{"minheight", SETTING_MIN_HEIGHT},
	{"borderless", SETTING_BORDERLESS},
	{"centered", SETTING_CENTERED},
	{"display", SETTING_DISPLAY},
	{"highdpi", SETTING_HIGHDPI},
	{"usedpiscale", SETTING_USE_DPISCALE},
	{"refreshrate", SETTING_REFRESHRATE},
	{"x", SETTING_X},
	{"y", SETTING_Y},
};

StringMap<loveWindowSetting, SETTING_MAX_ENUM> Window::settings(Window::settingEntries, sizeof(Window::settingEntries));

StringMap<loveWindowFullscreenType, FULLSCREEN_MAX_ENUM>::Entry Window::fullscreenTypeEntries[] =
{
	{"exclusive", FULLSCREEN_EXCLUSIVE},
	{"desktop", FULLSCREEN_DESKTOP},
};

StringMap<loveWindowFullscreenType, FULLSCREEN_MAX_ENUM> Window::fullscreenTypes(Window::fullscreenTypeEntries, sizeof(Window::fullscreenTypeEntries));

StringMap<loveWindowMessageBoxType, MESSAGEBOX_MAX_ENUM>::Entry Window::messageBoxTypeEntries[] =
{
	{"error", MESSAGEBOX_ERROR},
	{"warning", MESSAGEBOX_WARNING},
	{"info", MESSAGEBOX_INFO},
};

StringMap<loveWindowMessageBoxType, MESSAGEBOX_MAX_ENUM> Window::messageBoxTypes(Window::messageBoxTypeEntries, sizeof(Window::messageBoxTypeEntries));

StringMap<loveWindowDisplayOrientation, ORIENTATION_MAX_ENUM>::Entry Window::orientationEntries[] =
{
	{"unknown", ORIENTATION_UNKNOWN},
	{"landscape", ORIENTATION_LANDSCAPE},
	{"landscapeflipped", ORIENTATION_LANDSCAPE_FLIPPED},
	{"portrait", ORIENTATION_PORTRAIT},
	{"portraitflipped", ORIENTATION_PORTRAIT_FLIPPED},
};

StringMap<loveWindowDisplayOrientation, ORIENTATION_MAX_ENUM> Window::orientations(Window::orientationEntries, sizeof(Window::orientationEntries));

} // window
} // love
