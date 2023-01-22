#pragma once

namespace Spedycja {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o KonfiguracjaForm
	/// </summary>
	public ref class KonfiguracjaForm : public System::Windows::Forms::Form
	{
	private:
		String^ connectionString;
	public:
		KonfiguracjaForm(String^ connectionString)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
			this->connectionString = connectionString;
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~KonfiguracjaForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labelKonfiguracja;
	private: System::Windows::Forms::Button^ btnZapisz;
	private: System::Windows::Forms::Button^ btnWyjdz;
	private: System::Windows::Forms::TextBox^ textBoxNrLokalu;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label1;
	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->labelKonfiguracja = (gcnew System::Windows::Forms::Label());
			this->btnZapisz = (gcnew System::Windows::Forms::Button());
			this->btnWyjdz = (gcnew System::Windows::Forms::Button());
			this->textBoxNrLokalu = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// labelKonfiguracja
			// 
			this->labelKonfiguracja->AutoSize = true;
			this->labelKonfiguracja->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelKonfiguracja->Location = System::Drawing::Point(56, 55);
			this->labelKonfiguracja->Name = L"labelKonfiguracja";
			this->labelKonfiguracja->Size = System::Drawing::Size(114, 24);
			this->labelKonfiguracja->TabIndex = 13;
			this->labelKonfiguracja->Text = L"Konfiguracja";
			// 
			// btnZapisz
			// 
			this->btnZapisz->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnZapisz->Location = System::Drawing::Point(60, 384);
			this->btnZapisz->Name = L"btnZapisz";
			this->btnZapisz->Size = System::Drawing::Size(87, 34);
			this->btnZapisz->TabIndex = 14;
			this->btnZapisz->Text = L"Zapisz";
			this->btnZapisz->UseVisualStyleBackColor = true;
			// 
			// btnWyjdz
			// 
			this->btnWyjdz->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnWyjdz->Location = System::Drawing::Point(249, 384);
			this->btnWyjdz->Name = L"btnWyjdz";
			this->btnWyjdz->Size = System::Drawing::Size(87, 34);
			this->btnWyjdz->TabIndex = 15;
			this->btnWyjdz->Text = L"WyjdŸ";
			this->btnWyjdz->UseVisualStyleBackColor = true;
			// 
			// textBoxNrLokalu
			// 
			this->textBoxNrLokalu->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxNrLokalu->Location = System::Drawing::Point(161, 120);
			this->textBoxNrLokalu->Name = L"textBoxNrLokalu";
			this->textBoxNrLokalu->Size = System::Drawing::Size(76, 26);
			this->textBoxNrLokalu->TabIndex = 17;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label4->Location = System::Drawing::Point(56, 123);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(99, 20);
			this->label4->TabIndex = 16;
			this->label4->Text = L"Cena paliwa:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(245, 123);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(28, 20);
			this->label1->TabIndex = 18;
			this->label1->Text = L"z³/l";
			// 
			// KonfiguracjaForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(402, 455);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBoxNrLokalu);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->btnWyjdz);
			this->Controls->Add(this->btnZapisz);
			this->Controls->Add(this->labelKonfiguracja);
			this->Name = L"KonfiguracjaForm";
			this->Text = L"KonfiguracjaForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
