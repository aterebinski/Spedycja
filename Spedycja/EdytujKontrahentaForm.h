#pragma once

namespace Spedycja {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o EditKontrahentForm
	/// </summary>
	public ref class EdytujKontrahentaForm : public System::Windows::Forms::Form
	{
	public:
		EdytujKontrahentaForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczy�� wszystkie u�ywane zasoby.
		/// </summary>
		~EdytujKontrahentaForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labelEditKontrahent;
	private: System::Windows::Forms::Label^ labelNazwa;
	private: System::Windows::Forms::Button^ btnZatwierdz;
	private: System::Windows::Forms::Button^ btnAnuluj;


	private: System::Windows::Forms::TextBox^ textBoxNazwa;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBoxUlica;

	private: System::Windows::Forms::TextBox^ textBoxMiejscowosc;


	private: System::Windows::Forms::TextBox^ textBoxKod;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBoxNIP;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBoxRegon;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBoxZAdluzenie;
	private: System::Windows::Forms::Label^ label8;
	protected:

	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs�ugi projektanta � nie nale�y modyfikowa�
		/// jej zawarto�ci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->labelEditKontrahent = (gcnew System::Windows::Forms::Label());
			this->labelNazwa = (gcnew System::Windows::Forms::Label());
			this->btnZatwierdz = (gcnew System::Windows::Forms::Button());
			this->btnAnuluj = (gcnew System::Windows::Forms::Button());
			this->textBoxNazwa = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBoxUlica = (gcnew System::Windows::Forms::TextBox());
			this->textBoxMiejscowosc = (gcnew System::Windows::Forms::TextBox());
			this->textBoxKod = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBoxNIP = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBoxRegon = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBoxZAdluzenie = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// labelEditKontrahent
			// 
			this->labelEditKontrahent->AutoSize = true;
			this->labelEditKontrahent->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->labelEditKontrahent->Location = System::Drawing::Point(168, 53);
			this->labelEditKontrahent->Name = L"labelEditKontrahent";
			this->labelEditKontrahent->Size = System::Drawing::Size(190, 24);
			this->labelEditKontrahent->TabIndex = 3;
			this->labelEditKontrahent->Text = L"Poprawa Kontrahenta";
			// 
			// labelNazwa
			// 
			this->labelNazwa->AutoSize = true;
			this->labelNazwa->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelNazwa->Location = System::Drawing::Point(68, 123);
			this->labelNazwa->Name = L"labelNazwa";
			this->labelNazwa->Size = System::Drawing::Size(57, 20);
			this->labelNazwa->TabIndex = 4;
			this->labelNazwa->Text = L"Nazwa";
			// 
			// btnZatwierdz
			// 
			this->btnZatwierdz->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnZatwierdz->Location = System::Drawing::Point(165, 532);
			this->btnZatwierdz->Name = L"btnZatwierdz";
			this->btnZatwierdz->Size = System::Drawing::Size(98, 34);
			this->btnZatwierdz->TabIndex = 5;
			this->btnZatwierdz->Text = L"Zatwierd�";
			this->btnZatwierdz->UseVisualStyleBackColor = true;
			this->btnZatwierdz->Click += gcnew System::EventHandler(this, &EdytujKontrahentaForm::btnZatwierdz_Click);
			// 
			// btnAnuluj
			// 
			this->btnAnuluj->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnAnuluj->Location = System::Drawing::Point(296, 532);
			this->btnAnuluj->Name = L"btnAnuluj";
			this->btnAnuluj->Size = System::Drawing::Size(87, 34);
			this->btnAnuluj->TabIndex = 6;
			this->btnAnuluj->Text = L"Anuluj";
			this->btnAnuluj->UseVisualStyleBackColor = true;
			this->btnAnuluj->Click += gcnew System::EventHandler(this, &EdytujKontrahentaForm::btnAnuluj_Click);
			// 
			// textBoxNazwa
			// 
			this->textBoxNazwa->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxNazwa->Location = System::Drawing::Point(131, 117);
			this->textBoxNazwa->Name = L"textBoxNazwa";
			this->textBoxNazwa->Size = System::Drawing::Size(361, 26);
			this->textBoxNazwa->TabIndex = 7;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(68, 184);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 20);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Adres";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(68, 288);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(98, 20);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Miejscowo��";
			// 
			// textBoxUlica
			// 
			this->textBoxUlica->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxUlica->Location = System::Drawing::Point(131, 178);
			this->textBoxUlica->Name = L"textBoxUlica";
			this->textBoxUlica->Size = System::Drawing::Size(361, 26);
			this->textBoxUlica->TabIndex = 11;
			// 
			// textBoxMiejscowosc
			// 
			this->textBoxMiejscowosc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxMiejscowosc->Location = System::Drawing::Point(186, 285);
			this->textBoxMiejscowosc->Name = L"textBoxMiejscowosc";
			this->textBoxMiejscowosc->Size = System::Drawing::Size(306, 26);
			this->textBoxMiejscowosc->TabIndex = 13;
			// 
			// textBoxKod
			// 
			this->textBoxKod->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxKod->Location = System::Drawing::Point(131, 232);
			this->textBoxKod->Name = L"textBoxKod";
			this->textBoxKod->Size = System::Drawing::Size(92, 26);
			this->textBoxKod->TabIndex = 17;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label5->Location = System::Drawing::Point(68, 238);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(37, 20);
			this->label5->TabIndex = 16;
			this->label5->Text = L"Kod";
			// 
			// textBoxNIP
			// 
			this->textBoxNIP->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxNIP->Location = System::Drawing::Point(143, 337);
			this->textBoxNIP->Name = L"textBoxNIP";
			this->textBoxNIP->Size = System::Drawing::Size(153, 26);
			this->textBoxNIP->TabIndex = 19;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label6->Location = System::Drawing::Point(68, 340);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(35, 20);
			this->label6->TabIndex = 18;
			this->label6->Text = L"NIP";
			// 
			// textBoxRegon
			// 
			this->textBoxRegon->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxRegon->Location = System::Drawing::Point(143, 384);
			this->textBoxRegon->Name = L"textBoxRegon";
			this->textBoxRegon->Size = System::Drawing::Size(153, 26);
			this->textBoxRegon->TabIndex = 21;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label7->Location = System::Drawing::Point(68, 387);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(68, 20);
			this->label7->TabIndex = 20;
			this->label7->Text = L"REGON";
			// 
			// textBoxZAdluzenie
			// 
			this->textBoxZAdluzenie->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxZAdluzenie->Location = System::Drawing::Point(163, 440);
			this->textBoxZAdluzenie->Name = L"textBoxZAdluzenie";
			this->textBoxZAdluzenie->Size = System::Drawing::Size(133, 26);
			this->textBoxZAdluzenie->TabIndex = 23;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label8->Location = System::Drawing::Point(68, 443);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(88, 20);
			this->label8->TabIndex = 22;
			this->label8->Text = L"Zad�u�enie";
			// 
			// EdytujKontrahentaForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(543, 605);
			this->Controls->Add(this->textBoxZAdluzenie);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBoxRegon);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBoxNIP);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBoxKod);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBoxMiejscowosc);
			this->Controls->Add(this->textBoxUlica);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBoxNazwa);
			this->Controls->Add(this->btnAnuluj);
			this->Controls->Add(this->btnZatwierdz);
			this->Controls->Add(this->labelNazwa);
			this->Controls->Add(this->labelEditKontrahent);
			this->Name = L"EdytujKontrahentaForm";
			this->Text = L"EditKontrahentForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	private: System::Void btnZatwierdz_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void btnAnuluj_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
#pragma endregion
	
