#pragma once
#include "KontrahenciForm.h"
#include "KierowcyForm.h"
#include "SamochodyForm.h"
#include "ZleceniaForm.h"
#include "KonfiguracjaForm.h"
#include "TrasyForm.h"

namespace Spedycja {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o MenuForm
	/// </summary>
	public ref class MenuForm : public System::Windows::Forms::Form
	{
	private:
		String^ connectionString = L"Server=(localdb)\\MSSQLLocalDB;Database=SpedycjaDB;Trusted_Connection=True;";
	public:
		MenuForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~MenuForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ konfiguracjaBtn;
	private: System::Windows::Forms::Button^ exitBtn;
	private: System::Windows::Forms::Button^ zleceniaBtn;
	private: System::Windows::Forms::Button^ trasyBtn;
	private: System::Windows::Forms::Button^ kontrahenciBtn;
	private: System::Windows::Forms::Button^ kierowcyBtn;
	private: System::Windows::Forms::Button^ samochodyBtn;
	private: System::Windows::Forms::Button^  buttonZestawienia;

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->konfiguracjaBtn = (gcnew System::Windows::Forms::Button());
			this->exitBtn = (gcnew System::Windows::Forms::Button());
			this->zleceniaBtn = (gcnew System::Windows::Forms::Button());
			this->trasyBtn = (gcnew System::Windows::Forms::Button());
			this->kontrahenciBtn = (gcnew System::Windows::Forms::Button());
			this->kierowcyBtn = (gcnew System::Windows::Forms::Button());
			this->samochodyBtn = (gcnew System::Windows::Forms::Button());
			this->buttonZestawienia = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(375, 53);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(232, 46);
			this->label1->TabIndex = 0;
			this->label1->Text = L"SPEDYCJA";
			// 
			// konfiguracjaBtn
			// 
			this->konfiguracjaBtn->Location = System::Drawing::Point(75, 693);
			this->konfiguracjaBtn->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->konfiguracjaBtn->Name = L"konfiguracjaBtn";
			this->konfiguracjaBtn->Size = System::Drawing::Size(100, 28);
			this->konfiguracjaBtn->TabIndex = 1;
			this->konfiguracjaBtn->Text = L"Konfiguracja";
			this->konfiguracjaBtn->UseVisualStyleBackColor = true;
			this->konfiguracjaBtn->Click += gcnew System::EventHandler(this, &MenuForm::konfiguracjaBtn_Click);
			// 
			// exitBtn
			// 
			this->exitBtn->Location = System::Drawing::Point(833, 693);
			this->exitBtn->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->exitBtn->Name = L"exitBtn";
			this->exitBtn->Size = System::Drawing::Size(100, 28);
			this->exitBtn->TabIndex = 2;
			this->exitBtn->Text = L"Wyjœcie";
			this->exitBtn->UseVisualStyleBackColor = true;
			this->exitBtn->Click += gcnew System::EventHandler(this, &MenuForm::exitBtn_Click);
			// 
			// zleceniaBtn
			// 
			this->zleceniaBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->zleceniaBtn->Location = System::Drawing::Point(384, 196);
			this->zleceniaBtn->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->zleceniaBtn->Name = L"zleceniaBtn";
			this->zleceniaBtn->Size = System::Drawing::Size(239, 46);
			this->zleceniaBtn->TabIndex = 3;
			this->zleceniaBtn->Text = L"Zlecenia";
			this->zleceniaBtn->UseVisualStyleBackColor = true;
			this->zleceniaBtn->Click += gcnew System::EventHandler(this, &MenuForm::zleceniaBtn_Click);
			// 
			// trasyBtn
			// 
			this->trasyBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->trasyBtn->Location = System::Drawing::Point(384, 273);
			this->trasyBtn->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->trasyBtn->Name = L"trasyBtn";
			this->trasyBtn->Size = System::Drawing::Size(239, 46);
			this->trasyBtn->TabIndex = 3;
			this->trasyBtn->Text = L"Trasy";
			this->trasyBtn->UseVisualStyleBackColor = true;
			this->trasyBtn->Click += gcnew System::EventHandler(this, &MenuForm::trasyBtn_Click);
			// 
			// kontrahenciBtn
			// 
			this->kontrahenciBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->kontrahenciBtn->Location = System::Drawing::Point(384, 351);
			this->kontrahenciBtn->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->kontrahenciBtn->Name = L"kontrahenciBtn";
			this->kontrahenciBtn->Size = System::Drawing::Size(239, 46);
			this->kontrahenciBtn->TabIndex = 3;
			this->kontrahenciBtn->Text = L"Kontrahenci";
			this->kontrahenciBtn->UseVisualStyleBackColor = true;
			this->kontrahenciBtn->Click += gcnew System::EventHandler(this, &MenuForm::kontrahenciBtn_Click);
			// 
			// kierowcyBtn
			// 
			this->kierowcyBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->kierowcyBtn->Location = System::Drawing::Point(384, 431);
			this->kierowcyBtn->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->kierowcyBtn->Name = L"kierowcyBtn";
			this->kierowcyBtn->Size = System::Drawing::Size(239, 46);
			this->kierowcyBtn->TabIndex = 3;
			this->kierowcyBtn->Text = L"Kierowcy";
			this->kierowcyBtn->UseVisualStyleBackColor = true;
			this->kierowcyBtn->Click += gcnew System::EventHandler(this, &MenuForm::kierowcyBtn_Click);
			// 
			// samochodyBtn
			// 
			this->samochodyBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->samochodyBtn->Location = System::Drawing::Point(384, 503);
			this->samochodyBtn->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->samochodyBtn->Name = L"samochodyBtn";
			this->samochodyBtn->Size = System::Drawing::Size(239, 46);
			this->samochodyBtn->TabIndex = 3;
			this->samochodyBtn->Text = L"Samochody";
			this->samochodyBtn->UseVisualStyleBackColor = true;
			this->samochodyBtn->Click += gcnew System::EventHandler(this, &MenuForm::samochodyBtn_Click);
			// 
			// buttonZestawienia
			// 
			this->buttonZestawienia->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonZestawienia->Location = System::Drawing::Point(383, 675);
			this->buttonZestawienia->Margin = System::Windows::Forms::Padding(4);
			this->buttonZestawienia->Name = L"buttonZestawienia";
			this->buttonZestawienia->Size = System::Drawing::Size(239, 46);
			this->buttonZestawienia->TabIndex = 4;
			this->buttonZestawienia->Text = L"Zestawienia";
			this->buttonZestawienia->UseVisualStyleBackColor = true;
			// 
			// MenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1012, 794);
			this->Controls->Add(this->buttonZestawienia);
			this->Controls->Add(this->samochodyBtn);
			this->Controls->Add(this->kierowcyBtn);
			this->Controls->Add(this->kontrahenciBtn);
			this->Controls->Add(this->trasyBtn);
			this->Controls->Add(this->zleceniaBtn);
			this->Controls->Add(this->exitBtn);
			this->Controls->Add(this->konfiguracjaBtn);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"MenuForm";
			this->Text = L"MenuForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void kontrahenciBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		KontrahenciForm^ kontrahenciForm = gcnew KontrahenciForm(connectionString);
		kontrahenciForm->ShowDialog();
	}
	private: System::Void kierowcyBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		KierowcyForm^ kierowcyForm = gcnew KierowcyForm(connectionString);
		kierowcyForm->ShowDialog();
	}
	private: System::Void samochodyBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		SamochodyForm^ samochodyForm = gcnew SamochodyForm(connectionString);
		samochodyForm->ShowDialog();
	}
	private: System::Void zleceniaBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		ZleceniaForm^ zleceniaForm = gcnew ZleceniaForm(connectionString);
		zleceniaForm->ShowDialog();
	}
	private: System::Void konfiguracjaBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		KonfiguracjaForm^ konfiguracjaForm = gcnew KonfiguracjaForm(connectionString);
		konfiguracjaForm->ShowDialog();
	}
private: System::Void exitBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
private: System::Void trasyBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	TrasyForm^ trasyForm = gcnew TrasyForm(connectionString);
	trasyForm->ShowDialog();
}
};
}
