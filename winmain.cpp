#include "winmain.h"

[STAThreadAttribute]
int main() {
	_global::_main_window = gcnew trkdrop::winmain();
	Application::Run(_global::_main_window);
}