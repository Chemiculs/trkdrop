#pragma once
#include "winsettings.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::Threading;
using namespace System::Drawing::Imaging;
using namespace System::Configuration;
using namespace Emgu::CV;
using namespace Emgu::CV::Structure;
using namespace Emgu::CV::Util;
using namespace System::Net::Http;
using namespace System::Collections::Generic;
using namespace System::Runtime::Serialization::Formatters::Binary;
using namespace extnet;
namespace trkdrop {

	public ref class winmain : public System::Windows::Forms::Form
	{
	public:
		winmain(void)
		{
			InitializeComponent();
		}

	protected:
		~winmain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::StatusStrip^ statusStrip1;
	protected:
	private: System::Windows::Forms::ToolStripStatusLabel^ tslbldummy;
	private: System::Windows::Forms::ToolStripStatusLabel^ tslblstat;
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	private: System::Windows::Forms::RichTextBox^ rtblog;
	private: System::Windows::Forms::SplitContainer^ splitContainer2;
	private: System::Windows::Forms::Button^ btnstop;
	private: System::Windows::Forms::Button^ btnstart;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ optionsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ mssettings;

	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;




	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(winmain::typeid));
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->tslbldummy = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->tslblstat = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->rtblog = (gcnew System::Windows::Forms::RichTextBox());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->btnstop = (gcnew System::Windows::Forms::Button());
			this->btnstart = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->optionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mssettings = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statusStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// statusStrip1
			// 
			this->statusStrip1->BackColor = System::Drawing::Color::Gainsboro;
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->tslbldummy, this->tslblstat });
			this->statusStrip1->Location = System::Drawing::Point(0, 385);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Padding = System::Windows::Forms::Padding(1, 0, 16, 0);
			this->statusStrip1->Size = System::Drawing::Size(706, 22);
			this->statusStrip1->TabIndex = 0;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// tslbldummy
			// 
			this->tslbldummy->Name = L"tslbldummy";
			this->tslbldummy->Size = System::Drawing::Size(136, 17);
			this->tslbldummy->Text = L"trkdrop v1.0.0.1 - status: ";
			// 
			// tslblstat
			// 
			this->tslblstat->Name = L"tslblstat";
			this->tslblstat->Size = System::Drawing::Size(136, 17);
			this->tslblstat->Text = L"game process not found";
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 24);
			this->splitContainer1->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->splitContainer1->Name = L"splitContainer1";
			this->splitContainer1->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->rtblog);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->splitContainer2);
			this->splitContainer1->Size = System::Drawing::Size(706, 361);
			this->splitContainer1->SplitterDistance = 328;
			this->splitContainer1->SplitterWidth = 5;
			this->splitContainer1->TabIndex = 1;
			// 
			// rtblog
			// 
			this->rtblog->BackColor = System::Drawing::Color::Gainsboro;
			this->rtblog->DetectUrls = false;
			this->rtblog->Dock = System::Windows::Forms::DockStyle::Fill;
			this->rtblog->ForeColor = System::Drawing::Color::DarkMagenta;
			this->rtblog->Location = System::Drawing::Point(0, 0);
			this->rtblog->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->rtblog->Name = L"rtblog";
			this->rtblog->ReadOnly = true;
			this->rtblog->Size = System::Drawing::Size(706, 328);
			this->rtblog->TabIndex = 0;
			this->rtblog->Text = L"welcome to trkdrop v1.0.0.1";
			// 
			// splitContainer2
			// 
			this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer2->Location = System::Drawing::Point(0, 0);
			this->splitContainer2->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->splitContainer2->Name = L"splitContainer2";
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->Controls->Add(this->btnstop);
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->btnstart);
			this->splitContainer2->Size = System::Drawing::Size(706, 28);
			this->splitContainer2->SplitterDistance = 322;
			this->splitContainer2->SplitterWidth = 5;
			this->splitContainer2->TabIndex = 0;
			// 
			// btnstop
			// 
			this->btnstop->BackColor = System::Drawing::Color::Gainsboro;
			this->btnstop->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnstop->Enabled = false;
			this->btnstop->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnstop.Image")));
			this->btnstop->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->btnstop->Location = System::Drawing::Point(0, 0);
			this->btnstop->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->btnstop->Name = L"btnstop";
			this->btnstop->Size = System::Drawing::Size(322, 28);
			this->btnstop->TabIndex = 0;
			this->btnstop->Text = L"&Stop";
			this->btnstop->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btnstop->UseVisualStyleBackColor = false;
			this->btnstop->Click += gcnew System::EventHandler(this, &winmain::btnstop_Click);
			// 
			// btnstart
			// 
			this->btnstart->BackColor = System::Drawing::Color::Gainsboro;
			this->btnstart->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnstart->Enabled = false;
			this->btnstart->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnstart.Image")));
			this->btnstart->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->btnstart->Location = System::Drawing::Point(0, 0);
			this->btnstart->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->btnstart->Name = L"btnstart";
			this->btnstart->Size = System::Drawing::Size(379, 28);
			this->btnstart->TabIndex = 0;
			this->btnstart->Text = L"&Start";
			this->btnstart->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btnstart->UseVisualStyleBackColor = false;
			this->btnstart->Click += gcnew System::EventHandler(this, &winmain::btnstart_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Courier New", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->optionsToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(706, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->exitToolStripMenuItem });
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(47, 20);
			this->fileToolStripMenuItem->Text = L"&File";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"exitToolStripMenuItem.Image")));
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->exitToolStripMenuItem->Text = L"&Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &winmain::exitToolStripMenuItem_Click);
			// 
			// optionsToolStripMenuItem
			// 
			this->optionsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->mssettings });
			this->optionsToolStripMenuItem->Name = L"optionsToolStripMenuItem";
			this->optionsToolStripMenuItem->Size = System::Drawing::Size(68, 20);
			this->optionsToolStripMenuItem->Text = L"&Options";
			// 
			// mssettings
			// 
			this->mssettings->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"mssettings.Image")));
			this->mssettings->Name = L"mssettings";
			this->mssettings->Size = System::Drawing::Size(180, 22);
			this->mssettings->Text = L"&Settings...";
			this->mssettings->Click += gcnew System::EventHandler(this, &winmain::mssettings_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutToolStripMenuItem });
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(47, 20);
			this->helpToolStripMenuItem->Text = L"&Help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"aboutToolStripMenuItem.Image")));
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->aboutToolStripMenuItem->Text = L"&About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &winmain::aboutToolStripMenuItem_Click);
			// 
			// winmain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(706, 407);
			this->Controls->Add(this->splitContainer1);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->menuStrip1);
			this->DoubleBuffered = true;
			this->Font = (gcnew System::Drawing::Font(L"Courier New", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->Name = L"winmain";
			this->Text = L"trkdrop";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &winmain::winmain_FormClosing);
			this->Load += gcnew System::EventHandler(this, &winmain::winmain_Load);
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->EndInit();
			this->splitContainer2->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
#pragma region Initialization
	void _initialize_bitmaps() {
#pragma region Initialize 1920x1080 templates
		_global::_main_window_template_1920_1080 = _functions::_bitmap_from_array(_global::_managed_main_menu_template_1920_1080);
		_global::_player_selection_template_1920_1080 = _functions::_bitmap_from_array(_global::_managed_player_selection_template_1920_1080);
		_global::_player_selection_bak_template_1920_1080 = _functions::_bitmap_from_array(_global::_managed_player_selection_bak_template_1920_1080);
		_global::_player_selection_next_template_1920_1080 = _functions::_bitmap_from_array(_global::_managed_player_selection_next_template_1920_1080);
		_global::_map_selection_factory_template_1920_1080 = _functions::_bitmap_from_array(_global::_managed_map_selection_factory_template_1920_1080);
		_global::_map_selection_customs_template_1920_1080 = _functions::_bitmap_from_array(_global::_managed_map_selection_customs_template_1920_1080);
		_global::_map_selection_reserve_template_1920_1080 = _functions::_bitmap_from_array(_global::_managed_map_selection_reserve_template_1920_1080);
		_global::_map_selection_woods_template_1920_1080 = _functions::_bitmap_from_array(_global::_managed_map_selection_woods_template_1920_1080);
		_global::_map_selection_shoreline_template_1920_1080 = _functions::_bitmap_from_array(_global::_managed_map_selection_shoreline_template_1920_1080);
		_global::_map_selection_lighthouse_template_1920_1080 = _functions::_bitmap_from_array(_global::_managed_map_selection_lighthouse_template_1920_1080);
		_global::_map_selection_ready_template_1920_1080 = _functions::_bitmap_from_array(_global::_managed_map_selection_ready_template_1920_1080);
		_global::_post_raid_screen_template_1920_1080 = _functions::_bitmap_from_array(_global::_managed_post_raid_screen_template_1920_1080);
		_global::_post_raid_screen_yes_template_1920_1080 = _functions::_bitmap_from_array(_global::_managed_post_raid_screen_yes_template_1920_1080);
#pragma endregion
#pragma region Initialize 1280x720 templates
		_global::_main_window_template_1280_720 = _functions::_bitmap_from_array(_global::_managed_main_menu_template_1280_720);
		_global::_player_selection_template_1280_720 = _functions::_bitmap_from_array(_global::_managed_player_selection_template_1280_720);
		_global::_player_selection_bak_template_1280_720 = _functions::_bitmap_from_array(_global::_managed_player_selection_template_bak_1280_720);
		_global::_player_selection_next_template_1280_720 = _functions::_bitmap_from_array(_global::_managed_player_selection_next_template_1280_720);
		_global::_map_selection_factory_template_1280_720 = _functions::_bitmap_from_array(_global::_managed_map_selection_factory_template_1280_720);
		_global::_map_selection_customs_template_1280_720 = _functions::_bitmap_from_array(_global::_managed_map_selection_customs_template_1280_720);
		_global::_map_selection_reserve_template_1280_720 = _functions::_bitmap_from_array(_global::_managed_map_selection_reserve_template_1280_720);
		_global::_map_selection_woods_template_1280_720 = _functions::_bitmap_from_array(_global::_managed_map_selection_woods_template_1280_720);
		_global::_map_selection_shoreline_template_1280_720 = _functions::_bitmap_from_array(_global::_managed_map_selection_shoreline_template_1280_720);
		_global::_map_selection_lighthouse_template_1280_720 = _functions::_bitmap_from_array(_global::_managed_map_selection_lighthouse_template_1280_720);
		_global::_map_selection_ready_template_1280_720 = _functions::_bitmap_from_array(_global::_managed_map_selection_ready_template_1280_720);
		_global::_post_raid_screen_template_1280_720 = _functions::_bitmap_from_array(_global::_managed_post_raid_screen_template_1280_720);
		_global::_post_raid_screen_yes_template_1280_720 = _functions::_bitmap_from_array(_global::_managed_post_raid_screen_yes_template_1280_720);
#pragma endregion
	}
	void _initialize_user_settings() {
		_global::_is_foreground = false;
		_global::_random_raid = true;
		_global::_random_raid_threshhold = _functions::_generate_random_uint8(static_cast<unsigned char>(2),static_cast<unsigned char>(10), gcnew Random());
		_global::_humanoid_mouse_movements = true;
		_global::_bitmap_resolution_selection = 0;
	}
#pragma endregion
#pragma region Thread callbacks
	void _log_append(String^ _log_data, bool _success) {
		rtblog->SelectionStart = rtblog->Text->Length;
		if (_success) {
			rtblog->SelectionColor = Color::Teal;
			rtblog->SelectionLength = 0;
			rtblog->AppendText("\r\n[+]");
		}
		else {
			rtblog->SelectionColor = Color::OrangeRed;
			rtblog->SelectionLength = 0;
			rtblog->AppendText("\r\n[-]");
		}
		rtblog->SelectionColor = Color::LimeGreen;
		rtblog->SelectionLength = 0;
		rtblog->AppendText(_log_data);
		rtblog->ScrollToCaret();
	}
	void _game_scan_handler() {
		//easier to simply create scoped bitmap instance at the start of the method and get the template selection done with one switch
		Bitmap^ _main_window_template = nullptr;
		Bitmap^ _player_selection_template = nullptr;
		Bitmap^ _player_selection_bak_template = nullptr;
		Bitmap^ _player_selection_next_template = nullptr;
		Bitmap^ _map_selection_factory_template = nullptr;
		Bitmap^ _map_selection_customs_template = nullptr;
		Bitmap^ _map_selection_reserve_template = nullptr;
		Bitmap^ _map_selection_woods_template = nullptr;
		Bitmap^ _map_selection_shoreline_template = nullptr;
		Bitmap^ _map_selection_lighthouse_template = nullptr;
		Bitmap^ _map_selection_ready_template = nullptr;
		Bitmap^ _post_raid_screen_template = nullptr;
		Bitmap^ _post_raid_screen_yes_template = nullptr;
		//assign scoped bitmaps to respective global bitmaps based on user resolution selection
		switch (_global::_bitmap_resolution_selection) {
		default: {
			//shouldnt ever happen
			break;
		}case 0: {
			//1920x1080
			 _main_window_template = _global::_main_window_template_1920_1080;
			 _player_selection_template = _global::_player_selection_template_1920_1080;
			 _player_selection_bak_template = _global::_player_selection_bak_template_1920_1080;
			 _player_selection_next_template = _global::_player_selection_next_template_1920_1080;
			 _map_selection_factory_template = _global::_map_selection_factory_template_1920_1080;
			 _map_selection_customs_template = _global::_map_selection_customs_template_1920_1080;
			 _map_selection_reserve_template = _global::_map_selection_reserve_template_1920_1080;
			 _map_selection_woods_template = _global::_map_selection_woods_template_1920_1080;
			 _map_selection_shoreline_template = _global::_map_selection_shoreline_template_1920_1080;
			 _map_selection_lighthouse_template = _global::_map_selection_lighthouse_template_1920_1080;
			 _map_selection_ready_template = _global::_map_selection_ready_template_1920_1080;
			 _post_raid_screen_template = _global::_post_raid_screen_template_1920_1080;
			 _post_raid_screen_yes_template = _global::_post_raid_screen_yes_template_1920_1080;
			break;
		}case 1: {
			//1280x720
			_main_window_template = _global::_main_window_template_1280_720;
			_player_selection_template = _global::_player_selection_template_1280_720;
			_player_selection_bak_template = _global::_player_selection_bak_template_1280_720;
			_player_selection_next_template = _global::_player_selection_next_template_1280_720;
			_map_selection_factory_template = _global::_map_selection_factory_template_1280_720;
			_map_selection_customs_template = _global::_map_selection_customs_template_1280_720;
			_map_selection_reserve_template = _global::_map_selection_reserve_template_1280_720;
			_map_selection_woods_template = _global::_map_selection_woods_template_1280_720;
			_map_selection_shoreline_template = _global::_map_selection_shoreline_template_1280_720;
			_map_selection_lighthouse_template = _global::_map_selection_lighthouse_template_1280_720;
			_map_selection_ready_template = _global::_map_selection_ready_template_1280_720;
			_post_raid_screen_template = _global::_post_raid_screen_template_1280_720;
			_post_raid_screen_yes_template = _global::_post_raid_screen_yes_template_1280_720;
		}
		}
		long long _match_counter = 0;
		while (true) {
			if (_global::_is_running) {
				if (_global::_random_raid) {
					++_match_counter;
				}
				//scan for main menu "escape from tarkov" button
				Rectangle^ _position;
				Rectangle^ _position_next;
				//reset cursor position  incase user is hovering over main window "escape from tarkov" button which will cause inability for us to find it given the template i am using
				Thread::Sleep(150);
				_functions::_reset_mouse(_global::_humanoid_mouse_movements);
				Thread::Sleep(50);
				while (!_functions::_find_screen_pattern(_main_window_template, _position)) {
					Thread::Sleep(1);
				}
				_log_append("main menu detected, sending mouse click...", true);
				_functions::_trigger_mouse(_position->Location, _global::_humanoid_mouse_movements);
				Thread::Sleep(500);
				_functions::_reset_mouse(_global::_humanoid_mouse_movements);
				Thread::Sleep(250);
				while (true) {
					if (_functions::_find_screen_pattern(_player_selection_template, _position)) {
						break;
					}
					if (_functions::_find_screen_pattern(_player_selection_bak_template, _position)) {
						break;
					}
					Thread::Sleep(1);
				}
				_log_append("player selection detected, sending mouse click...", true);
				_functions::_trigger_mouse(_position->Location, _global::_humanoid_mouse_movements);
				Thread::Sleep(250);
				_functions::_reset_mouse(_global::_humanoid_mouse_movements);
				Thread::Sleep(250);
				while (!_functions::_find_screen_pattern(_player_selection_next_template, _position_next)) {
					Thread::Sleep(1);
				}
				_functions::_trigger_mouse(_position_next->Location, _global::_humanoid_mouse_movements);
				Thread::Sleep(750);
				_functions::_reset_mouse(_global::_humanoid_mouse_movements);
				Thread::Sleep(500);
				if(_match_counter == _global::_random_raid_threshhold && _global::_random_raid){
					bool _found_random_template = false;
					auto _seed = gcnew Random();
					auto _random_map_index = _seed->Next(0, 4);
					Bitmap^ _random_map_template = nullptr;
					switch (_random_map_index) {
					default: {
						break;
					}case 0: {
						_random_map_template = _map_selection_customs_template;
						break;
					}case 1: {
						_random_map_template = _map_selection_reserve_template;
						break;
					}case 2: {
						_random_map_template = _map_selection_woods_template;
						break;
					}case 3: {
						_random_map_template = _map_selection_shoreline_template;
						break;
					}case 4: {
						_random_map_template = _map_selection_lighthouse_template;
						break;
					}
					}
					// loop 5 times to automatically go to next step incase issues finding the UNSELECTED template
					for (int i = 0; i < 5; i++) {
						if (_functions::_find_screen_pattern(_random_map_template, _position))
						{
							_found_random_template = true;
							i = 5; // blah
						}
						Thread::Sleep(25);
					}
					//incase our random map templates glitch or fail to locate - revert to spawning on factory as this 100% works
					if (!_found_random_template) {
						for (int i = 0; i < 5; i++) {
							if (_functions::_find_screen_pattern(_map_selection_factory_template, _position))
							{
								i = 5; // blah
							}
							Thread::Sleep(25);
						}
					}
					_match_counter = 0;
				}
				else {
					for (int i = 0; i < 5; i++) {
						if (_functions::_find_screen_pattern(_map_selection_factory_template, _position))
						{
							i = 5; // blah
						}
						Thread::Sleep(25);
					}
				}
				_log_append("map selection detected, sending mouse click...", true);
				_functions::_trigger_mouse(_position->Location, _global::_humanoid_mouse_movements);
				Thread::Sleep(250);
				_functions::_reset_mouse(_global::_humanoid_mouse_movements);
				Thread::Sleep(250);
				_log_append("in game...", true);
				while (!_functions::_find_screen_pattern(_map_selection_ready_template, _position)) {
					Thread::Sleep(1);
				}
				_functions::_trigger_mouse(_position->Location, _global::_humanoid_mouse_movements);
				Thread::Sleep(250);
				_functions::_reset_mouse(_global::_humanoid_mouse_movements);
				Thread::Sleep(250);
				while (!_functions::_find_screen_pattern(_post_raid_screen_template, _position)) {
					Thread::Sleep(100);
				}
				_functions::_trigger_mouse(_position->Location, _global::_humanoid_mouse_movements);
				Thread::Sleep(250);
				_functions::_reset_mouse(_global::_humanoid_mouse_movements);
				Thread::Sleep(250);
				while (!_functions::_find_screen_pattern(_post_raid_screen_yes_template, _position)) {
					Thread::Sleep(100);
				}
				_functions::_trigger_mouse(_position->Location, _global::_humanoid_mouse_movements);
			}
			Thread::Sleep(250);
		}
	}
	void _game_process_handler(){
		static bool _initial_iteration = true;
		while (true) {
			_global::_tarkov_handle = _functions::_get_game_process();
			if (_global::_tarkov_handle != nullptr && !_global::_is_running) {
				_global::_is_running = true;
				_log_append("game process found, process id: " + _global::_tarkov_handle->Id, true);
				tslblstat->Text = "game process found, process id: " + _global::_tarkov_handle->Id;
				btnstart->Enabled = true;
			}
			else if (_global::_tarkov_handle != nullptr && _global::_is_running && GetForegroundWindow() != _global::_tarkov_handle->MainWindowHandle) {
				//game is running but minimized 
				if (_global::_is_foreground) {
					SetForegroundWindow(_global::_tarkov_handle->MainWindowHandle);
					_log_append("window minimized, sending window to foreground...", true);
				}
			}
			else if (!_global::_tarkov_handle && _global::_is_running) {
				//game closed
				_log_append("game exited, listening again for process...", false);
				if (_global::_scan_game_thread != nullptr) {
					_global::_scan_game_thread->Abort();
					_global::_scan_game_thread = nullptr;
				}
				_global::_is_running = false;
				btnstart->Enabled = false;
			}
			if (_initial_iteration && !_global::_is_running) {
				// this is just for aesthetics to log that the game was not running at the time of program startup
				_log_append("game process not detected, waiting for launch...", false);
				tslblstat->Text = "game process not found";
				_initial_iteration = false;
			}
			Thread::Sleep(1500);
		}
	}
#pragma endregion
	private: System::Void _scan(){
		Thread::Sleep(1500); // make sure application has initialized 
	}
	private: System::Void winmain_Load(System::Object^ sender, System::EventArgs^ e) {
		this->Text = _functions::_generate_random_string(5, 50);
		this->CheckForIllegalCrossThreadCalls = false;
		_global::_is_running = false;
		_log_append("initializing program data...", true);
		//native array types likely not compatible with clr::pure
		_initialize_bitmaps();
		_log_append("initializing user settings...", true);
		_initialize_user_settings();
		_log_append("launching threads...", true);
		_log_append("Open the game and wait at the main menu, then press start to begin", true);
		_global::_get_game_thread = gcnew Thread(gcnew ThreadStart(this, &winmain::_game_process_handler));
		_global::_get_game_thread->Start();
	}
	private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void btnstart_Click(System::Object^ sender, System::EventArgs^ e) {
		//show tarkov
		if (_global::_is_running) {
			SetForegroundWindow(_global::_tarkov_handle->MainWindowHandle);
			//initialize pattern scanning thread
			_global::_scan_game_thread = gcnew Thread(gcnew ThreadStart(this, &winmain::_game_scan_handler));
			_global::_scan_game_thread->Start();
			btnstart->Enabled = false;
			btnstop->Enabled = true;
		}
	}
	private: System::Void btnstop_Click(System::Object^ sender, System::EventArgs^ e) {
		_log_append("aborting game scan...", false);
		if (_global::_scan_game_thread) {
			_global::_scan_game_thread->Abort();
			_global::_scan_game_thread = nullptr;
		}
		btnstop->Enabled = false;
		btnstart->Enabled = true;
		_log_append("thread handle closed, waiting for user start...", true);
	}
	private: System::Void mssettings_Click(System::Object^ sender, System::EventArgs^ e) {
		winsettings^ _settings_dialog = gcnew winsettings();
		_settings_dialog->ShowDialog();
	}
	private: System::Void aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("tarkov k/d dropper v1.0.0.2", "About", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	private: System::Void winmain_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		if (_global::_scan_game_thread) {
			_global::_scan_game_thread->Abort();
			_global::_scan_game_thread = nullptr;
		}
		if (_global::_get_game_thread) {
			_global::_get_game_thread->Abort();
			_global::_get_game_thread = nullptr;
		}
	}
};
}