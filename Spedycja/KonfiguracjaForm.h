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

			try {
				SqlConnection^ sqlConnection = gcnew SqlConnection(connectionString);
				sqlConnection->Open();
				SqlCommand^ sqlCommand = gcnew SqlCommand("select * from dbo.Konfiguracja", sqlConnection);
				SqlDataReader^ sqlDataReader = sqlCommand->ExecuteReader();
				sqlDataReader->Read();
				String^ cenaPaliwa = sqlDataReader["cena_paliwa"]->ToString();
				this->textBoxCenaPaliwa->Text = cenaPaliwa;
				sqlDataReader->Close();
				sqlConnection->Close();
			}
			catch (Exception^ e) {
				MessageBox::Show(e->ToString());
			};
			
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
	private: System::Windows::Forms::TextBox^ textBoxCenaPaliwa;

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
			this->textBoxCenaPaliwa = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// labelKonfiguracja
			// 
			this->labelKonfiguracja->AutoSize = true;
			this->labelKonfiguracja->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelKonfiguracja->Location = System::Drawing::Point(75, 68);
			this->labelKonfiguracja->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelKonfiguracja->Name = L"labelKonfiguracja";
			this->labelKonfiguracja->Size = System::Drawing::Size(147, 29);
			this->labelKonfiguracja->TabIndex = 13;
			this->labelKonfiguracja->Text = L"Konfiguracja";
			// 
			// btnZapisz
			// 
			this->btnZapisz->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnZapisz->Location = System::Drawing::Point(80, 473);
			this->btnZapisz->Margin = System::Windows::Forms::Padding(4);
			this->btnZapisz->Name = L"btnZapisz";
			this->btnZapisz->Size = System::Drawing::Size(116, 42);
			this->btnZapisz->TabIndex = 14;
			this->btnZapisz->Text = L"Zapisz";
			this->btnZapisz->UseVisualStyleBackColor = true;
			this->btnZapisz->Click += gcnew System::EventHandler(this, &KonfiguracjaForm::btnZapisz_Click);
			// 
			// btnWyjdz
			// 
			this->btnWyjdz->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnWyjdz->Location = System::Drawing::Point(332, 473);
			this->btnWyjdz->Margin = System::Windows::Forms::Padding(4);
			this->btnWyjdz->Name = L"btnWyjdz";
			this->btnWyjdz->Size = System::Drawing::Size(116, 42);
			this->btnWyjdz->TabIndex = 15;
			this->btnWyjdz->Text = L"WyjdŸ";
			this->btnWyjdz->UseVisualStyleBackColor = true;
			this->btnWyjdz->Click += gcnew System::EventHandler(this, &KonfiguracjaForm::btnWyjdz_Click);
			// 
			// textBoxCenaPaliwa
			// 
			this->textBoxCenaPaliwa->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxCenaPaliwa->Location = System::Drawing::Point(215, 148);
			this->textBoxCenaPaliwa->Margin = System::Windows::Forms::Padding(4);
			this->textBoxCenaPaliwa->Name = L"textBoxCenaPaliwa";
			this->textBoxCenaPaliwa->Size = System::Drawing::Size(100, 30);
			this->textBoxCenaPaliwa->TabIndex = 17;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label4->Location = System::Drawing::Point(75, 151);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(126, 25);
			this->label4->TabIndex = 16;
			this->label4->Text = L"Cena paliwa:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(327, 151);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(36, 25);
			this->label1->TabIndex = 18;
			this->label1->Text = L"z³/l";
			// 
			// KonfiguracjaForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(536, 560);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBoxCenaPaliwa);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->btnWyjdz);
			this->Controls->Add(this->btnZapisz);
			this->Controls->Add(this->labelKonfiguracja);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"KonfiguracjaForm";
			this->Text = L"KonfiguracjaForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnZapisz_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			SqlConnection^ sqlConnection = gcnew SqlConnection(connectionString);
			sqlConnection->Open();
			double CenaPaliwa = Convert::ToDouble(this->textBoxCenaPaliwa->Text);

			SqlCommand^ sqlCommand = gcnew SqlCommand("update dbo.Konfiguracja set cena_paliwa = @cena_paliwa", sqlConnection);
			sqlCommand->Parameters->Add("@cena_paliwa", CenaPaliwa);
			sqlCommand->ExecuteNonQuery();

			sqlConnection->Close();
		}
		catch (Exception^ e) {
			MessageBox::Show(e->ToString());
		};
		
	}
private: System::Void btnWyjdz_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
