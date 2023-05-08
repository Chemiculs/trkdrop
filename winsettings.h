#pragma once
#include "global.hpp"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Configuration;
namespace trkdrop {
	public ref class winsettings : public System::Windows::Forms::Form
	{
	bool _is_foreground;
	public:
		winsettings(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~winsettings()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	private: System::Windows::Forms::CheckBox^ cbfg;
	protected:

	private: System::Windows::Forms::Button^ btnok;
	private: System::Windows::Forms::NumericUpDown^ txtraidcount;

	private: System::Windows::Forms::CheckBox^ cbrandraid;
	private: System::Windows::Forms::CheckBox^ cbhuman;
	private: System::Windows::Forms::ComboBox^ cbresolution;
	private: System::Windows::Forms::Label^ label1;


	protected:
	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->cbresolution = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cbhuman = (gcnew System::Windows::Forms::CheckBox());
			this->txtraidcount = (gcnew System::Windows::Forms::NumericUpDown());
			this->cbrandraid = (gcnew System::Windows::Forms::CheckBox());
			this->cbfg = (gcnew System::Windows::Forms::CheckBox());
			this->btnok = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtraidcount))->BeginInit();
			this->SuspendLayout();
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 0);
			this->splitContainer1->Name = L"splitContainer1";
			this->splitContainer1->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->cbresolution);
			this->splitContainer1->Panel1->Controls->Add(this->label1);
			this->splitContainer1->Panel1->Controls->Add(this->cbhuman);
			this->splitContainer1->Panel1->Controls->Add(this->txtraidcount);
			this->splitContainer1->Panel1->Controls->Add(this->cbrandraid);
			this->splitContainer1->Panel1->Controls->Add(this->cbfg);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->btnok);
			this->splitContainer1->Size = System::Drawing::Size(292, 136);
			this->splitContainer1->SplitterDistance = 107;
			this->splitContainer1->TabIndex = 0;
			// 
			// cbresolution
			// 
			this->cbresolution->FormattingEnabled = true;
			this->cbresolution->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"1920x1080", L"1280x720" });
			this->cbresolution->Location = System::Drawing::Point(152, 78);
			this->cbresolution->Name = L"cbresolution";
			this->cbresolution->Size = System::Drawing::Size(98, 23);
			this->cbresolution->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 81);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(140, 15);
			this->label1->TabIndex = 4;
			this->label1->Text = L"display resolution:";
			// 
			// cbhuman
			// 
			this->cbhuman->AutoSize = true;
			this->cbhuman->Location = System::Drawing::Point(9, 58);
			this->cbhuman->Name = L"cbhuman";
			this->cbhuman->Size = System::Drawing::Size(222, 19);
			this->cbhuman->TabIndex = 3;
			this->cbhuman->Text = L"use humanoid mouse movements";
			this->cbhuman->UseVisualStyleBackColor = true;
			// 
			// txtraidcount
			// 
			this->txtraidcount->Location = System::Drawing::Point(210, 34);
			this->txtraidcount->Name = L"txtraidcount";
			this->txtraidcount->Size = System::Drawing::Size(40, 21);
			this->txtraidcount->TabIndex = 2;
			// 
			// cbrandraid
			// 
			this->cbrandraid->AutoSize = true;
			this->cbrandraid->Checked = true;
			this->cbrandraid->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbrandraid->Location = System::Drawing::Point(9, 36);
			this->cbrandraid->Name = L"cbrandraid";
			this->cbrandraid->Size = System::Drawing::Size(194, 19);
			this->cbrandraid->TabIndex = 1;
			this->cbrandraid->Text = L"random map every X raids";
			this->cbrandraid->UseVisualStyleBackColor = true;
			// 
			// cbfg
			// 
			this->cbfg->AutoSize = true;
			this->cbfg->Location = System::Drawing::Point(9, 12);
			this->cbfg->Name = L"cbfg";
			this->cbfg->Size = System::Drawing::Size(173, 19);
			this->cbfg->TabIndex = 0;
			this->cbfg->Text = L"force game foreground";
			this->cbfg->UseVisualStyleBackColor = true;
			// 
			// btnok
			// 
			this->btnok->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnok->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnok->Location = System::Drawing::Point(0, 0);
			this->btnok->Name = L"btnok";
			this->btnok->Size = System::Drawing::Size(292, 25);
			this->btnok->TabIndex = 0;
			this->btnok->Text = L"Accept";
			this->btnok->UseVisualStyleBackColor = true;
			this->btnok->Click += gcnew System::EventHandler(this, &winsettings::btnok_Click);
			// 
			// winsettings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Gainsboro;
			this->ClientSize = System::Drawing::Size(292, 136);
			this->Controls->Add(this->splitContainer1);
			this->DoubleBuffered = true;
			this->Font = (gcnew System::Drawing::Font(L"Courier New", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"winsettings";
			this->Text = L"settings";
			this->Load += gcnew System::EventHandler(this, &winsettings::winsettings_Load);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->PerformLayout();
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtraidcount))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnok_Click(System::Object^ sender, System::EventArgs^ e) {
		_global::_is_foreground = cbfg->Checked;
		_global::_random_raid = cbrandraid->Checked;
		if (_global::_random_raid) {
			_global::_random_raid_threshhold = static_cast<unsigned char>(txtraidcount->Value);
		}
		_global::_humanoid_mouse_movements = cbhuman->Checked;
		if (cbresolution->SelectedIndex < 0) {
			cbresolution->SelectedIndex = 0;
		}
		_global::_bitmap_resolution_selection = cbresolution->SelectedIndex;
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
	}
	private: System::Void winsettings_Load(System::Object^ sender, System::EventArgs^ e) {
		txtraidcount->Minimum = System::Byte::MinValue + 1;
		txtraidcount->Maximum = System::Byte::MaxValue;
		cbfg->Checked = _global::_is_foreground;
		cbrandraid->Checked = _global::_random_raid;
		if (cbrandraid->Checked) {
			txtraidcount->Value = _global::_random_raid_threshhold;
		}
		cbhuman->Checked = _global::_humanoid_mouse_movements;
		cbresolution->SelectedIndex = _global::_bitmap_resolution_selection;
	}
};
}
