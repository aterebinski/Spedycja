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
	/// Podsumowanie informacji o EditKontrahentForm
	/// </summary>
	public ref class EdytujKontrahentaForm : public System::Windows::Forms::Form
	{
	private:
		String^ connectionString;
		String^ nazwa;
		String^ skrot;
		String^ adres;
		String^ kod;
		String^ miejscowosc;
		String^ NIP;
		String^ REGON;
		String^ zadluzenie;
	private: System::Windows::Forms::TextBox^ textBoxSkrot;
	private: System::Windows::Forms::Label^ label2;
		   int idKontrahenta;
	public:
		EdytujKontrahentaForm(int idKontrahenta, String^ connectionString)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
			this->idKontrahenta = idKontrahenta;
			this->connectionString = connectionString;


			SqlConnection^ sqlConnection = gcnew SqlConnection(connectionString);
			SqlCommand^ sqlCommand;
			SqlDataReader^ sqlDataReader;
			sqlConnection->Open();



			//https://www.functionx.com/vccli/controls/combobox.htm


			if (idKontrahenta != 0) //jesli edytujemy dane to trzeba wyswietlic dane w odpowiednich polach
			{
				try {

					sqlCommand = gcnew SqlCommand("select * from dbo.Kontrahenci where id = " + idKontrahenta, sqlConnection);
					SqlDataReader^ sqlDataReader = sqlCommand->ExecuteReader();
					sqlDataReader->Read();
					nazwa = sqlDataReader["nazwa"]->ToString();
					this->textBoxNazwa->Text = nazwa;
					skrot = sqlDataReader["skrot"]->ToString();
					this->textBoxSkrot->Text = skrot;
					adres = sqlDataReader["adres"]->ToString();
					this->textBoxAdres->Text = adres;
					kod = sqlDataReader["kod"]->ToString();
					this->textBoxKod->Text = kod;
					miejscowosc = sqlDataReader["miejscowosc"]->ToString();
					this->textBoxMiejscowosc->Text = miejscowosc;
					NIP = sqlDataReader["NIP"]->ToString();
					this->textBoxNIP->Text = NIP;
					REGON = sqlDataReader["REGON"]->ToString();
					this->textBoxREGON->Text = REGON;
					zadluzenie = sqlDataReader["zadluzenie"]->ToString();
					this->textBoxZadluzenie->Text = Convert::ToString(zadluzenie);
					nazwa = sqlDataReader["nazwa"]->ToString();
					this->textBoxNazwa->Text = nazwa;
					
					//idStanowiska = sqlDataReader["idStanowiska"]->ToString();
					//idLokalizacji = sqlDataReader["idLokalizacji"]->ToString();

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
		/// Wyczyść wszystkie używane zasoby.
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
private: System::Windows::Forms::TextBox^ textBoxAdres;


	private: System::Windows::Forms::TextBox^ textBoxMiejscowosc;


	private: System::Windows::Forms::TextBox^ textBoxKod;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBoxNIP;
	private: System::Windows::Forms::Label^ label6;
private: System::Windows::Forms::TextBox^ textBoxREGON;

	private: System::Windows::Forms::Label^ label7;
private: System::Windows::Forms::TextBox^ textBoxZadluzenie;

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
		/// Metoda wymagana do obsługi projektanta — nie należy modyfikować
		/// jej zawartości w edytorze kodu.
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
			this->textBoxAdres = (gcnew System::Windows::Forms::TextBox());
			this->textBoxMiejscowosc = (gcnew System::Windows::Forms::TextBox());
			this->textBoxKod = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBoxNIP = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBoxREGON = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBoxZadluzenie = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBoxSkrot = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
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
			this->labelNazwa->Location = System::Drawing::Point(68, 114);
			this->labelNazwa->Name = L"labelNazwa";
			this->labelNazwa->Size = System::Drawing::Size(57, 20);
			this->labelNazwa->TabIndex = 4;
			this->labelNazwa->Text = L"Nazwa";
			// 
			// btnZatwierdz
			// 
			this->btnZatwierdz->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnZatwierdz->Location = System::Drawing::Point(165, 578);
			this->btnZatwierdz->Name = L"btnZatwierdz";
			this->btnZatwierdz->Size = System::Drawing::Size(98, 34);
			this->btnZatwierdz->TabIndex = 9;
			this->btnZatwierdz->Text = L"Zatwierdź";
			this->btnZatwierdz->UseVisualStyleBackColor = true;
			this->btnZatwierdz->Click += gcnew System::EventHandler(this, &EdytujKontrahentaForm::btnZatwierdz_Click);
			// 
			// btnAnuluj
			// 
			this->btnAnuluj->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnAnuluj->Location = System::Drawing::Point(296, 578);
			this->btnAnuluj->Name = L"btnAnuluj";
			this->btnAnuluj->Size = System::Drawing::Size(87, 34);
			this->btnAnuluj->TabIndex = 10;
			this->btnAnuluj->Text = L"Anuluj";
			this->btnAnuluj->UseVisualStyleBackColor = true;
			this->btnAnuluj->Click += gcnew System::EventHandler(this, &EdytujKontrahentaForm::btnAnuluj_Click);
			// 
			// textBoxNazwa
			// 
			this->textBoxNazwa->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxNazwa->Location = System::Drawing::Point(131, 108);
			this->textBoxNazwa->Name = L"textBoxNazwa";
			this->textBoxNazwa->Size = System::Drawing::Size(361, 26);
			this->textBoxNazwa->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(68, 230);
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
			this->label3->Location = System::Drawing::Point(68, 334);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(98, 20);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Miejscowość";
			// 
			// textBoxAdres
			// 
			this->textBoxAdres->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxAdres->Location = System::Drawing::Point(131, 224);
			this->textBoxAdres->Name = L"textBoxAdres";
			this->textBoxAdres->Size = System::Drawing::Size(361, 26);
			this->textBoxAdres->TabIndex = 3;
			// 
			// textBoxMiejscowosc
			// 
			this->textBoxMiejscowosc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxMiejscowosc->Location = System::Drawing::Point(186, 331);
			this->textBoxMiejscowosc->Name = L"textBoxMiejscowosc";
			this->textBoxMiejscowosc->Size = System::Drawing::Size(306, 26);
			this->textBoxMiejscowosc->TabIndex = 5;
			// 
			// textBoxKod
			// 
			this->textBoxKod->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxKod->Location = System::Drawing::Point(131, 278);
			this->textBoxKod->Name = L"textBoxKod";
			this->textBoxKod->Size = System::Drawing::Size(92, 26);
			this->textBoxKod->TabIndex = 4;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label5->Location = System::Drawing::Point(68, 284);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(37, 20);
			this->label5->TabIndex = 16;
			this->label5->Text = L"Kod";
			// 
			// textBoxNIP
			// 
			this->textBoxNIP->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxNIP->Location = System::Drawing::Point(143, 383);
			this->textBoxNIP->Name = L"textBoxNIP";
			this->textBoxNIP->Size = System::Drawing::Size(153, 26);
			this->textBoxNIP->TabIndex = 6;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label6->Location = System::Drawing::Point(68, 386);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(35, 20);
			this->label6->TabIndex = 18;
			this->label6->Text = L"NIP";
			// 
			// textBoxREGON
			// 
			this->textBoxREGON->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxREGON->Location = System::Drawing::Point(143, 430);
			this->textBoxREGON->Name = L"textBoxREGON";
			this->textBoxREGON->Size = System::Drawing::Size(153, 26);
			this->textBoxREGON->TabIndex = 7;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label7->Location = System::Drawing::Point(68, 433);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(68, 20);
			this->label7->TabIndex = 20;
			this->label7->Text = L"REGON";
			// 
			// textBoxZadluzenie
			// 
			this->textBoxZadluzenie->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxZadluzenie->Location = System::Drawing::Point(163, 486);
			this->textBoxZadluzenie->Name = L"textBoxZadluzenie";
			this->textBoxZadluzenie->Size = System::Drawing::Size(133, 26);
			this->textBoxZadluzenie->TabIndex = 8;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label8->Location = System::Drawing::Point(68, 489);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(88, 20);
			this->label8->TabIndex = 22;
			this->label8->Text = L"Zadłużenie";
			// 
			// textBoxSkrot
			// 
			this->textBoxSkrot->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxSkrot->Location = System::Drawing::Point(131, 163);
			this->textBoxSkrot->Name = L"textBoxSkrot";
			this->textBoxSkrot->Size = System::Drawing::Size(165, 26);
			this->textBoxSkrot->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(68, 169);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(47, 20);
			this->label2->TabIndex = 24;
			this->label2->Text = L"Skrót";
			// 
			// EdytujKontrahentaForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(543, 648);
			this->Controls->Add(this->textBoxSkrot);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBoxZadluzenie);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBoxREGON);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBoxNIP);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBoxKod);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBoxMiejscowosc);
			this->Controls->Add(this->textBoxAdres);
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
		nazwa = this->textBoxNazwa->Text;
		skrot = this->textBoxSkrot->Text;
		adres = this->textBoxAdres->Text;
		kod = this->textBoxKod->Text;
		miejscowosc = this->textBoxMiejscowosc->Text;
		NIP = this->textBoxNIP->Text;
		REGON = this->textBoxREGON->Text;
		zadluzenie = this->textBoxZadluzenie->Text;
		
		String^ sqlString;

		if ((nazwa == "") || (skrot == "") || (adres == "") || (kod == "") || (miejscowosc == "") || (NIP == "") || (REGON == ""))
		{
			MessageBox::Show("Wypełnij wszystkie pola");
		}
		else {
			
			if (idKontrahenta == 0) //dodanie nowego rekordu do tabeli Kontrahenci
			{
				sqlString = "insert into dbo.Kontrahenci(nazwa,skrot,adres,kod,miejscowosc,NIP, REGON, zadluzenie) values (@nazwa,@skrot,@adres,@kod,@miejscowosc,@NIP, @REGON, @zadluzenie);";
			}
			else { //edycja rekordu tabeli Pracownicy
				sqlString = "update dbo.Kontrahenci set nazwa = @nazwa, skrot = @skrot, adres = @adres, kod = @kod, miejscowosc = @miejscowosc, NIP = @NIP, REGON = @REGON, zadluzenie = @zadluzenie " +
					"where ID = @idKontrahenta ;";
			}

			try {
				SqlConnection^ sqlConnection = gcnew SqlConnection(connectionString);
				sqlConnection->Open();
				SqlCommand^ sqlCommand = gcnew SqlCommand(sqlString, sqlConnection);
				sqlCommand->Parameters->Add("@nazwa", nazwa);
				sqlCommand->Parameters->Add("@skrot", skrot);
				sqlCommand->Parameters->Add("@adres", adres);
				sqlCommand->Parameters->Add("@kod", kod);
				sqlCommand->Parameters->Add("@miejscowosc", miejscowosc);
				sqlCommand->Parameters->Add("@NIP", NIP);
				sqlCommand->Parameters->Add("@REGON", REGON);
				sqlCommand->Parameters->Add("@zadluzenie", zadluzenie);
				if (idKontrahenta != 0) sqlCommand->Parameters->Add("@idKontrahenta", idKontrahenta);

				sqlCommand->ExecuteNonQuery();

				sqlConnection->Close();
			}
			catch (Exception^ e) {
				MessageBox::Show(e->ToString());
			}

			this->Close();



		}
	}
private: System::Void btnAnuluj_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
#pragma endregion
	
