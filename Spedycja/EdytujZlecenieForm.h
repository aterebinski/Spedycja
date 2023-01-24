#pragma once
#include "ComboBoxItem.h"

namespace Spedycja {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::SqlClient;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for EdytujZlecenieForm
	/// </summary>
	public ref class EdytujZlecenieForm : public System::Windows::Forms::Form
	{
	private:
		int idZlecenia = 0;
		String^ connectionString;

		int idKontrahenta;
		String^ dataZamowienia;
		String^ skad;
		String^ dokad;
		int idLadunku;
		String^ opis;
		String^ dataRealizacji;
		int status;
		String^ naleznosc;

	public:
		EdytujZlecenieForm(int idZlecenia,int idKontrahenta, String^ connectionString)
		{
			InitializeComponent();

			this->idZlecenia = idZlecenia;
			this->idKontrahenta = idKontrahenta;
			this->connectionString = connectionString;
			SqlConnection^ sqlConnection = gcnew SqlConnection(connectionString);
			SqlCommand^ sqlCommand;
			SqlDataReader^ sqlDataReader;
			sqlConnection->Open();

			if (idZlecenia != 0) //jesli edytujemy dane to trzeba wyswietlic dane w odpowiednich polach
			{
				try {

					sqlCommand = gcnew SqlCommand("select * from dbo.Zlecenia where id = " + idZlecenia, sqlConnection);
					SqlDataReader^ sqlDataReader = sqlCommand->ExecuteReader();
					sqlDataReader->Read();

					dataZamowienia = sqlDataReader["data_zamowienia"]->ToString();
					this->dateTimeDataZlecenia->Text = dataZamowienia;
					dataRealizacji = sqlDataReader["data_realizacji"]->ToString();
					this->dateTimeDataRealizacji->Text = dataRealizacji;
					
					skad = sqlDataReader["skad"]->ToString();
					this->textBoxSkad->Text = skad;
					dokad = sqlDataReader["dokad"]->ToString();
					this->textBoxDokad->Text = dokad;

					opis = sqlDataReader["opis"]->ToString();
					this->textBoxOpis->Text = opis;

					naleznosc = sqlDataReader["naleznosc"]->ToString();
					this->textBoxNaleznosc->Text = naleznosc;
					



					idKontrahenta = (int)sqlDataReader["idKontrahenta"];
					idLadunku = (int)sqlDataReader["idLadunku"];
					status = (int)sqlDataReader["status"];


					sqlDataReader->Close();
				}
				catch (Exception^ ex)
				{
					MessageBox::Show(ex->Message);
				}

			}

			//uzupelnianie comboboxow
			try {

				ComboBoxItem^ tempComboBoxItem;
				int tempId;
				String^ tempValue;

				sqlCommand = gcnew SqlCommand("select * from dbo.Ladunki", sqlConnection);
				sqlDataReader = sqlCommand->ExecuteReader();
				while (sqlDataReader->Read()) {
					tempId = (int)sqlDataReader["ID"];
					tempValue = sqlDataReader["Nazwa"]->ToString();
					tempComboBoxItem = gcnew ComboBoxItem(tempId, tempValue);
					this->comboBoxLadunek->Items->Add(tempComboBoxItem);
					if ((idZlecenia != 0) && (idLadunku == tempId)) this->comboBoxLadunek->SelectedItem = tempComboBoxItem;
				}

				sqlDataReader->Close();

				sqlCommand = gcnew SqlCommand("select * from dbo.Kontrahenci", sqlConnection);
				sqlDataReader = sqlCommand->ExecuteReader();
				while (sqlDataReader->Read()) {
					tempId = (int)sqlDataReader["ID"];
					tempValue = sqlDataReader["Nazwa"]->ToString();
					tempComboBoxItem = gcnew ComboBoxItem(tempId, tempValue);
					this->comboBoxKontrahent->Items->Add(tempComboBoxItem);
					if ((idZlecenia != 0) && (idKontrahenta == tempId)) this->comboBoxKontrahent->SelectedItem = tempComboBoxItem;
				}

				sqlDataReader->Close();

				sqlCommand = gcnew SqlCommand("select * from dbo.Statusy", sqlConnection);
				sqlDataReader = sqlCommand->ExecuteReader();
				while (sqlDataReader->Read()) {
					tempId = (int)sqlDataReader["ID"];
					tempValue = sqlDataReader["status"]->ToString();
					tempComboBoxItem = gcnew ComboBoxItem(tempId, tempValue);
					this->comboBoxStatus->Items->Add(tempComboBoxItem);
					if ((idZlecenia != 0) && (status == tempId)) this->comboBoxStatus->SelectedItem = tempComboBoxItem;
				}


			}
			catch (Exception^ e) {
				MessageBox::Show(e->ToString());
			};

			sqlDataReader->Close();
			sqlConnection->Close();

		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EdytujZlecenieForm()
		{
			if (components)
			{
				delete components;
			}
		}
private: System::Windows::Forms::TextBox^  textBoxNaleznosc;
protected:

	protected:
	private: System::Windows::Forms::Label^  label10;
private: System::Windows::Forms::ComboBox^  comboBoxKontrahent;

	private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::TextBox^  textBoxDokad;

	private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::TextBox^  textBoxSkad;

	private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::TextBox^  textBoxOpis;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  btnAnuluj;
	private: System::Windows::Forms::Button^  btnZatwierdz;
	private: System::Windows::Forms::Label^  labelNazwa;
	private: System::Windows::Forms::Label^  labelEditKontrahent;
private: System::Windows::Forms::DateTimePicker^  dateTimeDataZlecenia;
private: System::Windows::Forms::DateTimePicker^  dateTimeDataRealizacji;
private: System::Windows::Forms::ComboBox^  comboBoxLadunek;



	private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::ComboBox^  comboBoxStatus;

	private: System::Windows::Forms::Label^  label4;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBoxNaleznosc = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->comboBoxKontrahent = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBoxDokad = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBoxSkad = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBoxOpis = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnAnuluj = (gcnew System::Windows::Forms::Button());
			this->btnZatwierdz = (gcnew System::Windows::Forms::Button());
			this->labelNazwa = (gcnew System::Windows::Forms::Label());
			this->labelEditKontrahent = (gcnew System::Windows::Forms::Label());
			this->dateTimeDataZlecenia = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimeDataRealizacji = (gcnew System::Windows::Forms::DateTimePicker());
			this->comboBoxLadunek = (gcnew System::Windows::Forms::ComboBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->comboBoxStatus = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBoxNaleznosc
			// 
			this->textBoxNaleznosc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxNaleznosc->Location = System::Drawing::Point(268, 460);
			this->textBoxNaleznosc->Margin = System::Windows::Forms::Padding(4);
			this->textBoxNaleznosc->Name = L"textBoxNaleznosc";
			this->textBoxNaleznosc->Size = System::Drawing::Size(179, 30);
			this->textBoxNaleznosc->TabIndex = 55;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label10->Location = System::Drawing::Point(117, 463);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(143, 25);
			this->label10->TabIndex = 71;
			this->label10->Text = L"Należność (zł):";
			// 
			// comboBoxKontrahent
			// 
			this->comboBoxKontrahent->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->comboBoxKontrahent->FormattingEnabled = true;
			this->comboBoxKontrahent->Location = System::Drawing::Point(239, 131);
			this->comboBoxKontrahent->Margin = System::Windows::Forms::Padding(4);
			this->comboBoxKontrahent->Name = L"comboBoxKontrahent";
			this->comboBoxKontrahent->Size = System::Drawing::Size(728, 33);
			this->comboBoxKontrahent->TabIndex = 52;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(117, 134);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(114, 25);
			this->label2->TabIndex = 69;
			this->label2->Text = L"Kontrahent:";
			// 
			// textBoxDokad
			// 
			this->textBoxDokad->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxDokad->Location = System::Drawing::Point(602, 387);
			this->textBoxDokad->Margin = System::Windows::Forms::Padding(4);
			this->textBoxDokad->Name = L"textBoxDokad";
			this->textBoxDokad->Size = System::Drawing::Size(365, 30);
			this->textBoxDokad->TabIndex = 51;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label6->Location = System::Drawing::Point(519, 392);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(75, 25);
			this->label6->TabIndex = 66;
			this->label6->Text = L"Dokąd:";
			// 
			// textBoxSkad
			// 
			this->textBoxSkad->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxSkad->Location = System::Drawing::Point(189, 389);
			this->textBoxSkad->Margin = System::Windows::Forms::Padding(4);
			this->textBoxSkad->Name = L"textBoxSkad";
			this->textBoxSkad->Size = System::Drawing::Size(308, 30);
			this->textBoxSkad->TabIndex = 50;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label5->Location = System::Drawing::Point(117, 391);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(64, 25);
			this->label5->TabIndex = 65;
			this->label5->Text = L"Skąd:";
			// 
			// textBoxOpis
			// 
			this->textBoxOpis->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxOpis->Location = System::Drawing::Point(239, 318);
			this->textBoxOpis->Margin = System::Windows::Forms::Padding(4);
			this->textBoxOpis->Name = L"textBoxOpis";
			this->textBoxOpis->Size = System::Drawing::Size(728, 30);
			this->textBoxOpis->TabIndex = 53;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(117, 322);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(59, 25);
			this->label3->TabIndex = 64;
			this->label3->Text = L"Opis:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(523, 203);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(243, 25);
			this->label1->TabIndex = 63;
			this->label1->Text = L"Data planowanej realizacji:";
			// 
			// btnAnuluj
			// 
			this->btnAnuluj->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnAnuluj->Location = System::Drawing::Point(575, 594);
			this->btnAnuluj->Margin = System::Windows::Forms::Padding(4);
			this->btnAnuluj->Name = L"btnAnuluj";
			this->btnAnuluj->Size = System::Drawing::Size(116, 42);
			this->btnAnuluj->TabIndex = 60;
			this->btnAnuluj->Text = L"Anuluj";
			this->btnAnuluj->UseVisualStyleBackColor = true;
			this->btnAnuluj->Click += gcnew System::EventHandler(this, &EdytujZlecenieForm::btnAnuluj_Click);
			// 
			// btnZatwierdz
			// 
			this->btnZatwierdz->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnZatwierdz->Location = System::Drawing::Point(417, 594);
			this->btnZatwierdz->Margin = System::Windows::Forms::Padding(4);
			this->btnZatwierdz->Name = L"btnZatwierdz";
			this->btnZatwierdz->Size = System::Drawing::Size(131, 42);
			this->btnZatwierdz->TabIndex = 59;
			this->btnZatwierdz->Text = L"Zatwierdź";
			this->btnZatwierdz->UseVisualStyleBackColor = true;
			this->btnZatwierdz->Click += gcnew System::EventHandler(this, &EdytujZlecenieForm::btnZatwierdz_Click);
			// 
			// labelNazwa
			// 
			this->labelNazwa->AutoSize = true;
			this->labelNazwa->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelNazwa->Location = System::Drawing::Point(117, 203);
			this->labelNazwa->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelNazwa->Name = L"labelNazwa";
			this->labelNazwa->Size = System::Drawing::Size(136, 25);
			this->labelNazwa->TabIndex = 62;
			this->labelNazwa->Text = L"Data zlecenia:";
			// 
			// labelEditKontrahent
			// 
			this->labelEditKontrahent->AutoSize = true;
			this->labelEditKontrahent->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->labelEditKontrahent->Location = System::Drawing::Point(461, 48);
			this->labelEditKontrahent->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelEditKontrahent->Name = L"labelEditKontrahent";
			this->labelEditKontrahent->Size = System::Drawing::Size(183, 29);
			this->labelEditKontrahent->TabIndex = 61;
			this->labelEditKontrahent->Text = L"Edycja Zlecenia";
			// 
			// dateTimeDataZlecenia
			// 
			this->dateTimeDataZlecenia->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->dateTimeDataZlecenia->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimeDataZlecenia->Location = System::Drawing::Point(260, 198);
			this->dateTimeDataZlecenia->Name = L"dateTimeDataZlecenia";
			this->dateTimeDataZlecenia->Size = System::Drawing::Size(200, 30);
			this->dateTimeDataZlecenia->TabIndex = 73;
			// 
			// dateTimeDataRealizacji
			// 
			this->dateTimeDataRealizacji->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->dateTimeDataRealizacji->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimeDataRealizacji->Location = System::Drawing::Point(767, 198);
			this->dateTimeDataRealizacji->Name = L"dateTimeDataRealizacji";
			this->dateTimeDataRealizacji->Size = System::Drawing::Size(200, 30);
			this->dateTimeDataRealizacji->TabIndex = 74;
			// 
			// comboBoxLadunek
			// 
			this->comboBoxLadunek->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->comboBoxLadunek->FormattingEnabled = true;
			this->comboBoxLadunek->Location = System::Drawing::Point(357, 262);
			this->comboBoxLadunek->Margin = System::Windows::Forms::Padding(4);
			this->comboBoxLadunek->Name = L"comboBoxLadunek";
			this->comboBoxLadunek->Size = System::Drawing::Size(409, 33);
			this->comboBoxLadunek->TabIndex = 75;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label11->Location = System::Drawing::Point(117, 265);
			this->label11->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(232, 25);
			this->label11->TabIndex = 76;
			this->label11->Text = L"Rodzaj ładunku/naczepy:";
			// 
			// comboBoxStatus
			// 
			this->comboBoxStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->comboBoxStatus->FormattingEnabled = true;
			this->comboBoxStatus->Location = System::Drawing::Point(730, 455);
			this->comboBoxStatus->Margin = System::Windows::Forms::Padding(4);
			this->comboBoxStatus->Name = L"comboBoxStatus";
			this->comboBoxStatus->Size = System::Drawing::Size(237, 33);
			this->comboBoxStatus->TabIndex = 77;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label4->Location = System::Drawing::Point(648, 458);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(74, 25);
			this->label4->TabIndex = 78;
			this->label4->Text = L"Status:";
			// 
			// EdytujZlecenieForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1064, 666);
			this->Controls->Add(this->comboBoxStatus);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->comboBoxLadunek);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->dateTimeDataRealizacji);
			this->Controls->Add(this->dateTimeDataZlecenia);
			this->Controls->Add(this->textBoxNaleznosc);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->comboBoxKontrahent);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBoxDokad);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBoxSkad);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBoxOpis);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnAnuluj);
			this->Controls->Add(this->btnZatwierdz);
			this->Controls->Add(this->labelNazwa);
			this->Controls->Add(this->labelEditKontrahent);
			this->Name = L"EdytujZlecenieForm";
			this->Text = L"EdytujZlecenieForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnZatwierdz_Click(System::Object^  sender, System::EventArgs^  e) {
		ComboBoxItem^ selectedLadunek = (ComboBoxItem^)this->comboBoxLadunek->SelectedItem;
		ComboBoxItem^ selectedKontrahent = (ComboBoxItem^)this->comboBoxKontrahent->SelectedItem;
		ComboBoxItem^ selectedStatus = (ComboBoxItem^)this->comboBoxStatus->SelectedItem;
		//MessageBox::Show(selectedLokalizacja->getId());

		int idKontrahenta;
		String^ dataZamowienia;
		String^ skad;
		String^ dokad;
		int idLadunku;
		String^ opis;
		String^ dataRealizacji;
		int status;
		String^ naleznosc;

		dataZamowienia = this->dateTimeDataZlecenia->Text;
		dataRealizacji = this->dateTimeDataRealizacji->Text;
		skad = this->textBoxSkad->Text;
		dokad = this->textBoxDokad->Text;
		opis = this->textBoxOpis->Text;
		naleznosc = this->textBoxNaleznosc->Text;
	

		idLadunku = selectedLadunek->getId();
		idKontrahenta = selectedKontrahent->getId();
		status = selectedStatus->getId();


		//int intIdLadunku;
		String^ sqlString;

		if ((dataZamowienia == "") || (dataRealizacji == "") || (skad == "") || (dokad == "") || (opis == "") || (naleznosc == "") || (idLadunku == 0) || (idKontrahenta == 0) || (status == 0))
		{
			MessageBox::Show("Wypełnij wszystkie pola");
		}
		else {
			//intIdLadunku = Convert::ToInt32(idLadunku);

			if (idZlecenia == 0) //dodanie nowego rekordu do tabeli Samochod
			{
				sqlString = "INSERT INTO dbo.Zlecenia (idKontrahenta,data_zamowienia, skad, dokad, idLadunku, opis, data_realizacji, status, naleznosc) " +
					"VALUES (@idKontrahenta,@data_zamowienia, @skad, @dokad, @idLadunku, @opis, @data_realizacji, @status, @naleznosc)  ";
			}
			else { //edycja rekordu tabeli Samochod
				sqlString = "UPDATE dbo.Zlecenia SET idKontrahenta = @idKontrahenta, data_zamowienia = @data_zamowienia, skad = @skad, dokad = @dokad, idLadunku = @idLadunku, opis = @opis, data_realizacji = @data_realizacji, status = @status, naleznosc = @naleznosc " +
					"WHERE id = @idZlecenia;";
			}

			try {
				SqlConnection^ sqlConnection = gcnew SqlConnection(connectionString);
				sqlConnection->Open();
				SqlCommand^ sqlCommand = gcnew SqlCommand(sqlString, sqlConnection);
				sqlCommand->Parameters->Add("@idKontrahenta", idKontrahenta);
				sqlCommand->Parameters->Add("@data_zamowienia", dataZamowienia);
				sqlCommand->Parameters->Add("@skad", skad);
				sqlCommand->Parameters->Add("@dokad", dokad);
				sqlCommand->Parameters->Add("@idLadunku", idLadunku);
				sqlCommand->Parameters->Add("@opis", opis);
				sqlCommand->Parameters->Add("@data_realizacji", dataRealizacji);
				sqlCommand->Parameters->Add("@status", status);
				sqlCommand->Parameters->Add("@naleznosc", naleznosc);

				if (idZlecenia != 0) sqlCommand->Parameters->Add("@idZlecenia", idZlecenia);

				sqlCommand->ExecuteNonQuery();

				sqlConnection->Close();
			}
			catch (Exception^ e) {
				MessageBox::Show(e->ToString());
			}

			this->Close();
	}
private: System::Void btnAnuluj_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}
};
}

