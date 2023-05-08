#pragma once
#include "native.hpp"
using namespace System;
using namespace System::IO;
using namespace System::Text;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;
using namespace System::Diagnostics;
using namespace Emgu::CV;
using namespace Emgu::CV::Structure;
using namespace Emgu::CV::Util;
using namespace System::Collections::Generic;
using namespace System::Threading;
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

static ref class _functions {
public:
#pragma region Halfass Obfuscation
	static unsigned char _generate_random_uint8(unsigned char _minimum, unsigned char _maximum, Random^ _generator) {
		return static_cast<unsigned char>(_generator->Next(_minimum, _maximum));
	}
	static String^ _generate_random_string(unsigned char _minimum, unsigned char _maximum) {
		String^ _alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
		auto _generator = gcnew Random();
		auto _return_length = _generate_random_uint8(_minimum, _maximum, _generator);
		auto _return_string = gcnew StringBuilder();
		for (int i = 0; i < _return_length; i++) {
			_return_string->Append(_alphabet[_generate_random_uint8(0, _alphabet->Length, _generator)]);
		}
		return _return_string->ToString();
	}
#pragma endregion
#pragma region Process functions
	static Process^ _get_game_process() {
		array<Process^>^ _ret = Process::GetProcessesByName("EscapeFromTarkov");
		if (_ret->Length > 0) {
			return _ret[0];
		}
		else {
			return nullptr;
		}
	}
#pragma endregion
#pragma region Binary data bullshit
	template<typename T>
	static T _convert_from_array(array<unsigned char>^ _in) {
		MemoryStream^ _stream = gcnew MemoryStream(_in);
		BinaryReader^ _reader = gcnew BinaryReader(_stream);
		switch (_stream->Length) {
		default: {
			break;
		}case 0: {
			break;
		}case 1: {
			break;
		}case 2: {
			return (T)_reader->ReadUInt16();
			break;
		}case 4: {
			return (T)_reader->ReadUInt32();
			break;
		}case 8: {
			return (T)_reader->ReadUInt64();
			break;
		}
		}
	}
#pragma endregion
#pragma region System functions
	static List<POINT>^ _get_line_points(POINT p1, POINT p2)
	{
		List<POINT>^ points = gcnew List<POINT>();

		int dx = Math::Abs(p2.X - p1.X);
		int dy = Math::Abs(p2.Y - p1.Y);
		int sx = p1.X < p2.X ? 1 : -1;
		int sy = p1.Y < p2.Y ? 1 : -1;
		int err = dx - dy;

		while (true)
		{
			POINT^ _point_temp = gcnew POINT();
			_point_temp->X = p1.X;
			_point_temp->Y = p1.Y;
			points->Add((POINT)_point_temp);

			if (p1.X == p2.X && p1.Y == p2.Y)
			{
				break;
			}

			int e2 = 2 * err;
			if (e2 > -dy)
			{
				err -= dy;
				p1.X += sx;
			}
			if (e2 < dx)
			{
				err += dx;
				p1.Y += sy;
			}
		}

		return points;
	}
	static void _trigger_mouse(Point^ _location, bool _is_humanoid) {
		if (_is_humanoid) {
			//move mouse to the location
			POINT^ _cast = gcnew POINT();
			_cast->X = _location->X;
			_cast->Y = _location->Y;
			_humanoid_mouse_drag((POINT)_cast, 24);
		}
		else {
			SetCursorPos(_location->X, _location->Y);
		}
		//trigger MOUSEEVENTF_LEFTDOWN
		mouse_event((unsigned int)0x0002, 0, 0, 0, 0);
		//trigger MOUSEEVENTF_LEFTUP
		mouse_event((unsigned int)0x0004, 0, 0, 0, 0);
	}
	static void _reset_mouse(bool _is_humanoid) {
		if (_is_humanoid) {
			POINT^ _cast = gcnew POINT();
			_cast->X = 1;
			_cast->Y = 1;
			_humanoid_mouse_drag((POINT)_cast, 24);
		}
		else {
			SetCursorPos(1, 1);
		}
	}
	static void _humanoid_mouse_drag(POINT _destination, unsigned char _speed) {
		POINT _current_position;
		auto _api_return = GetCursorPos(_current_position);
		if (_api_return) {
			auto _line_points = _get_line_points(_current_position, _destination);
			for (int i = 0; i < _line_points->Count; i += _speed) {
				if (_line_points->Count - 1 >= i) {
					SetCursorPos(_line_points[i].X, _line_points[i].Y);
					Thread::Sleep(1);
				}
				else {
					break;
				}
			}
			//ensure we reach the destination if the length of the list is not divisible by our speed
			SetCursorPos(_destination.X, _destination.Y);
		}
	}
#pragma endregion
#pragma region Bitmap / Image recognition functions
	static Bitmap^ _resize_bitmap(Bitmap^ _in, Size _size) {
		return reinterpret_cast<Bitmap^>(_in->GetThumbnailImage(_size.Width, _size.Height, nullptr, IntPtr::Zero));
	}
	static Bitmap^ _convert_format(Bitmap^ in) {
		Bitmap^ _ret = gcnew Bitmap(in->Width, in->Height, PixelFormat::Format24bppRgb);
		Graphics^ _tmp_graphics = Graphics::FromImage(_ret);
		_tmp_graphics->DrawImage(in, (Rectangle)gcnew Rectangle(0, 0, _ret->Width, _ret->Height));
		return _ret;
	}
	static Bitmap^ _get_screenshot(Screen^ _scr) {
		Bitmap^ _template = gcnew Bitmap(_scr->Bounds.Width, _scr->Bounds.Height);
		Graphics^ _tmp_graphics = Graphics::FromImage(_template);
		_tmp_graphics->CopyFromScreen((System::Drawing::Point)gcnew System::Drawing::Point(_scr->Bounds.Left, _scr->Bounds.Top), System::Drawing::Point::Empty, _scr->Bounds.Size);
		return _convert_format(_template);
	}
	static Bitmap^ _bitmap_from_array(array<unsigned char>^ _in) {
		return (Bitmap^)Bitmap::FromStream(gcnew MemoryStream(_in));
	}
	static bool _find_screen_pattern(Bitmap^ _pattern_in, Rectangle^% _rect_in) {
		//clone to prevent .net glitch where calling UnlockBits() doesn't actually unlock them
		Bitmap^ _pattern = dynamic_cast<Bitmap^>(_pattern_in->Clone());
		Mat^ _out = gcnew Mat();
		auto _scr = _get_screenshot(Screen::PrimaryScreen);
		BitmapData^ bits;
		BitmapData^ bits2;
		bits = _scr->LockBits((Rectangle)gcnew Rectangle(0, 0, _scr->Width, _scr->Height), ImageLockMode::ReadOnly, _scr->PixelFormat);
		bits2 = _pattern->LockBits((Rectangle)gcnew Rectangle(0, 0, _pattern->Width, _pattern->Height), ImageLockMode::ReadOnly, _pattern->PixelFormat);
		Emgu::CV::Image<Bgr, Byte>^ _imgnew = gcnew Emgu::CV::Image<Bgr, Byte>(_scr->Width, _scr->Height, bits->Stride, System::IntPtr(bits->Scan0));
		Emgu::CV::Image<Bgr, Byte>^ _imgnew2 = gcnew Emgu::CV::Image<Bgr, Byte>(_pattern->Width, _pattern->Height, bits2->Stride, System::IntPtr(bits2->Scan0));
		Emgu::CV::CvInvoke::MatchTemplate(_imgnew, _imgnew2, _out, Emgu::CV::CvEnum::TemplateMatchingType::CcorrNormed, nullptr);
		double min, _max;
		Point^ _minp = gcnew Point();
		auto _maxp = gcnew Point();
		Emgu::CV::CvInvoke::MinMaxLoc(_out, min, _max, (Point)_minp, (Point)_maxp, nullptr);
		_pattern->UnlockBits(bits2);
		_scr->UnlockBits(bits);
		if (_max >= 0.9f) {
			_rect_in = gcnew Rectangle((Point)_maxp, _imgnew2->Size);
			return true;
		}
		return false;
	}
#pragma endregion
};
#endif