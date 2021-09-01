#pragma once
#include <windows.h>
#include <stdlib.h>
#include <iostream>


#define Log(format, ...) _Log(__FILE__, __LINE__, format, __VA_ARGS__)
#define Info(format, ...) _Info(__FILE__, __LINE__, format, __VA_ARGS__)
#define Warning(format, ...) _Warning(__FILE__, __LINE__, format, __VA_ARGS__)
#define Error(format, ...) _Error(__FILE__, __LINE__, format, __VA_ARGS__)


namespace Bdv
{
	namespace Logger
	{
		void _Log(const char* filename, int line, const char* format, ...);
		void _Info(const char* filename, int line, const char* format, ...);
		void _Warning(const char* filename, int line, const char* format, ...);
		void _Error(const char* filename, int line, const char* format, ...);
	};
}
