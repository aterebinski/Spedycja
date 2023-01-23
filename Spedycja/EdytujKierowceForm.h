#pragma once

namespace Spedycja {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::SqlClient;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o EdytujKierowceForm
	/// </summary>
	public ref class EdytujKierowceForm : public System::Windows::Forms::Form
	{
	private:
		String^ connectionString;
		String^ imie;
		String^ nazwisko;
		String^ pensja;
		String^ wspPremii;
		int idKierowcy;
	public:
		EdytujKierowceForm(int idKierowcy, String^ connectionString)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
			this->idKierowcy = idKierowcy;
			this->connectionString = connectionString;


			SqlConnection^ sqlConnection = gcnew SqlConnection(connectionString);
			SqlCommand^ sqlCommand;
			SqlDataReader^ sqlDataReader;
			sqlConnection->Open();


			if (idKierowcy != 0) //jesli edytujemy dane to trzeba wyswietlic dane w odpowiednich polach
			{
				try {

					sqlCommand = gcnew SqlCommand("select * from dbo.Kierowcy where id = " + idKierowcy, sqlConnection);
					SqlDataReader^ sqlDataReader = sqlCommand->ExecuteReader();
					sqlDataReader->Read();
					imie = sqlDataReader["imie"]->ToString();
					this->textBoxImie->Text = imie;
					nazwisko = sqlDataReader["nazwisko"]->ToString();
					this->textBoxNazwisko->Text = nazwisko;
					pensja = sqlDataReader["pensja"]->ToString();
					this->textBoxPensja->Text = pensja;
					wspPremii = sqlDataReader["wsp_premii"]->ToString();
					this->textBoxPremia->Text = wspPremii;

					sqlDataReader->Close();
				}
				catch (Exception^ ex)
				{
					MessageBox::Show(ex->Message);
				}

			}


		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~EdytujKierowceForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBoxPensja;
	protected:

	protected:






	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBoxPremia;

	private: System::Windows::Forms::TextBox^ textBoxNazwisko;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBoxImie;

	private: System::Windows::Forms::Button^ btnAnuluj;
	private: System::Windows::Forms::Button^ btnZatwierdz;
	private: System::Windows::Forms::Label^ labelNazwa;
	private: System::Windows::Forms::Label^ labelEditKierowce;

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
			this->textBoxPensja = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBoxPremia = (gcnew System::Windows::Forms::TextBox());
			this->textBoxNazwisko = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxImie = (gcnew System::Windows::Forms::TextBox());
			this->btnAnuluj = (gcnew System::Windows::Forms::Button());
			this->btnZatwierdz = (gcnew System::Windows::Forms::Button());
			this->labelNazwa = (gcnew System::Windows::Forms::Label());
			this->labelEditKierowce = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBoxPensja
			// 
			this->textBoxPensja->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxPensja->Location = System::Drawing::Point(120, 220);
			this->textBoxPensja->Name = L"textBoxPensja";
			this->textBoxPensja->Size = System::Drawing::Size(92, 26);
			this->textBoxPensja->TabIndex = 3;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label5->Location = System::Drawing::Point(38, 223);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(61, 20);
			this->label5->TabIndex = 33;
			this->label5->Text = L"Pensja:";
			// 
			// textBoxPremia
			// 
			this->textBoxPremia->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxPremia->Location = System::Drawing::Point(157, 270);
			this->textBoxPremia->Name = L"textBoxPremia";
			this->textBoxPremia->Size = System::Drawing::Size(213, 26);
			this->textBoxPremia->TabIndex = 4;
			// 
			// textBoxNazwisko
			// 
			this->textBoxNazwisko->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxNazwisko->Location = System::Drawing::Point(120, 166);
			this->textBoxNazwisko->Name = L"textBoxNazwisko";
			this->textBoxNazwisko->Size = System::Drawing::Size(361, 26);
			this->textBoxNazwisko->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(38, 273);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(113, 20);
			this->label3->TabIndex = 30;
			this->label3->Text = L"Premia za 1km";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(38, 169);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(80, 20);
			this->label1->TabIndex = 29;
			this->label1->Text = L"Nazwisko:";
			// 
			// textBoxImie
			// 
			this->textBoxImie->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxImie->Location = System::Drawing::Point(120, 108);
			this->textBoxImie->Name = L"textBoxImie";
			this->textBoxImie->Size = System::Drawing::Size(361, 26);
			this->textBoxImie->TabIndex = 1;
			// 
			// btnAnuluj
			// 
			this->btnAnuluj->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnAnuluj->Location = System::Drawing::Point(270, 360);
			this->btnAnuluj->Name = L"btnAnuluj";
			this->btnAnuluj->Size = System::Drawing::Size(87, 34);
			this->btnAnuluj->TabIndex = 6;
			this->btnAnuluj->Text = L"Anuluj";
			this->btnAnuluj->UseVisualStyleBackColor = true;
			this->btnAnuluj->Click += gcnew System::EventHandler(this, &EdytujKierowceForm::btnAnuluj_Click);
			// 
			// btnZatwierdz
			// 
			this->btnZatwierdz->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnZatwierdz->Location = System::Drawing::Point(139, 360);
			this->btnZatwierdz->Name = L"btnZatwierdz";
			this->btnZatwierdz->Size = System::Drawing::Size(98, 34);
			this->btnZatwierdz->TabIndex = 5;
			this->btnZatwierdz->Text = L"ZatwierdŸ";
			this->btnZatwierdz->UseVisualStyleBackColor = true;
			this->btnZatwierdz->Click += gcnew System::EventHandler(this, &EdytujKierowceForm::btnZatwierdz_Click);
			// 
			// labelNazwa
			// 
			this->labelNazwa->AutoSize = true;
			this->labelNazwa->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelNazwa->Location = System::Drawing::Point(38, 108);
			this->labelNazwa->Name = L"labelNazwa";
			this->labelNazwa->Size = System::Drawing::Size(43, 20);
			this->labelNazwa->TabIndex = 25;
			this->labelNazwa->Text = L"Imie:";
			this->labelNazwa->Click += gcnew System::EventHandler(this, &EdytujKierowceForm::labelNazwa_Click);
			// 
			// labelEditKierowce
			// 
			this->labelEditKierowce->AutoSize = true;
			this->labelEditKierowce->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelEditKierowce->Location = System::Drawing::Point(171, 36);
			this->labelEditKierowce->Name = L"labelEditKierowce";
			this->labelEditKierowce->Size = System::Drawing::Size(166, 24);
			this->labelEditKierowce->TabIndex = 24;
			this->labelEditKierowce->Text = L"Poprawa Kierowcy";
			// 
			// EdytujKierowceForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(529, 443);
			this->Controls->Add(this->textBoxPensja);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBoxPremia);
			this->Controls->Add(this->textBoxNazwisko);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBoxImie);
			this->Controls->Add(this->btnAnuluj);
			this->Controls->Add(this->btnZatwierdz);
			this->Controls->Add(this->labelNazwa);
			this->Controls->Add(this->labelEditKierowce);
			this->Name = L"EdytujKierowceForm";
			this->Text = L"EdytujKierowceForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void btnAnuluj_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void btnZatwierdz_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
