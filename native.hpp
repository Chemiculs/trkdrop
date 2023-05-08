#pragma once
using namespace System;
using namespace System::Runtime::InteropServices;
#ifndef NATIVE_H
#define NATIVE_H
#pragma region Native Structures
[StructLayout(LayoutKind::Sequential)]
value struct POINT
{
public:
    Int32 X;
    Int32 Y;
};
#pragma endregion
[DllImport("user32.dll")]
extern bool SetCursorPos(int X, int Y);
[DllImport("user32.dll")]
extern bool SetForegroundWindow(IntPtr hWnd);
[DllImport("user32.dll")]
extern IntPtr GetForegroundWindow();
[DllImport("user32.dll")]
extern void mouse_event(unsigned int dwFlags, unsigned int dx, unsigned int dy, unsigned int dwData, int dwExtraInfo);
[DllImport("user32.dll")]
extern bool GetCursorPos([Out] POINT% point);
#endif