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
		String^ nrZlecenia;
		String^ dataZamowienia;
		String^ skad;
		String^ dokad;
		int idLadunku;
		String^ opis;
		String^ dataRealizacji;
		int status;
	private: System::Windows::Forms::TextBox^ textBoxNrZlecenia;

	private: System::Windows::Forms::Label^ label7;
		   double naleznosc;

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

					nrZlecenia = sqlDataReader["nrZlecenia"]->ToString();
					this->textBoxNrZlecenia->Text = nrZlecenia;

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

					naleznosc = Convert::ToDouble(sqlDataReader["naleznosc"]);
					this->textBoxNaleznosc->Text = naleznosc.ToString();
					
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
			else {
				this->textBoxNaleznosc->Text = "0";
				status = 1;

				DateTime^ DateTimeNow = gcnew DateTime;
				DateTimeNow = DateTime::Now;

				String^ currentDate = String::Format(L"{0:D4}-{1:D2}-{2:D2}", DateTimeNow->Year, DateTimeNow->Month, DateTimeNow->Day);

				//String^ currentDate = "" + DateTimeNow->Year +"-" + DateTimeNow->Month + "-" + DateTimeNow->Day;
				dateTimeDataZlecenia->Text = currentDate;
				dateTimeDataRealizacji->Text = currentDate;
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
					tempValue = sqlDataReader["Skrot"]->ToString();
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
					if (status == tempId) this->comboBoxStatus->SelectedItem = tempComboBoxItem;
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
			this->textBoxNrZlecenia = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBoxNaleznosc
			// 
			this->textBoxNaleznosc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxNaleznosc->Location = System::Drawing::Point(200, 424);
			this->textBoxNaleznosc->Name = L"textBoxNaleznosc";
			this->textBoxNaleznosc->Size = System::Drawing::Size(135, 26);
			this->textBoxNaleznosc->TabIndex = 9;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label10->Location = System::Drawing::Point(87, 426);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(113, 20);
			this->label10->TabIndex = 71;
			this->label10->Text = L"Należność (zł):";
			// 
			// comboBoxKontrahent
			// 
			this->comboBoxKontrahent->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->comboBoxKontrahent->FormattingEnabled = true;
			this->comboBoxKontrahent->Location = System::Drawing::Point(179, 106);
			this->comboBoxKontrahent->Name = L"comboBoxKontrahent";
			this->comboBoxKontrahent->Size = System::Drawing::Size(547, 28);
			this->comboBoxKontrahent->TabIndex = 1;
			this->comboBoxKontrahent->SelectedIndexChanged += gcnew System::EventHandler(this, &EdytujZlecenieForm::comboBoxKontrahent_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(88, 109);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(92, 20);
			this->label2->TabIndex = 69;
			this->label2->Text = L"Kontrahent:";
			// 
			// textBoxDokad
			// 
			this->textBoxDokad->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxDokad->Location = System::Drawing::Point(451, 364);
			this->textBoxDokad->Name = L"textBoxDokad";
			this->textBoxDokad->Size = System::Drawing::Size(275, 26);
			this->textBoxDokad->TabIndex = 8;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label6->Location = System::Drawing::Point(388, 368);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(60, 20);
			this->label6->TabIndex = 66;
			this->label6->Text = L"Dokąd:";
			// 
			// textBoxSkad
			// 
			this->textBoxSkad->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxSkad->Location = System::Drawing::Point(141, 366);
			this->textBoxSkad->Name = L"textBoxSkad";
			this->textBoxSkad->Size = System::Drawing::Size(232, 26);
			this->textBoxSkad->TabIndex = 7;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label5->Location = System::Drawing::Point(87, 368);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(50, 20);
			this->label5->TabIndex = 65;
			this->label5->Text = L"Skąd:";
			// 
			// textBoxOpis
			// 
			this->textBoxOpis->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxOpis->Location = System::Drawing::Point(178, 308);
			this->textBoxOpis->Name = L"textBoxOpis";
			this->textBoxOpis->Size = System::Drawing::Size(547, 26);
			this->textBoxOpis->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(87, 312);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(45, 20);
			this->label3->TabIndex = 64;
			this->label3->Text = L"Opis:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(391, 215);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(196, 20);
			this->label1->TabIndex = 63;
			this->label1->Text = L"Data planowanej realizacji:";
			// 
			// btnAnuluj
			// 
			this->btnAnuluj->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnAnuluj->Location = System::Drawing::Point(423, 537);
			this->btnAnuluj->Name = L"btnAnuluj";
			this->btnAnuluj->Size = System::Drawing::Size(87, 34);
			this->btnAnuluj->TabIndex = 12;
			this->btnAnuluj->Text = L"Anuluj";
			this->btnAnuluj->UseVisualStyleBackColor = true;
			this->btnAnuluj->Click += gcnew System::EventHandler(this, &EdytujZlecenieForm::btnAnuluj_Click);
			// 
			// btnZatwierdz
			// 
			this->btnZatwierdz->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnZatwierdz->Location = System::Drawing::Point(305, 537);
			this->btnZatwierdz->Name = L"btnZatwierdz";
			this->btnZatwierdz->Size = System::Drawing::Size(98, 34);
			this->btnZatwierdz->TabIndex = 11;
			this->btnZatwierdz->Text = L"Zatwierdź";
			this->btnZatwierdz->UseVisualStyleBackColor = true;
			this->btnZatwierdz->Click += gcnew System::EventHandler(this, &EdytujZlecenieForm::btnZatwierdz_Click);
			// 
			// labelNazwa
			// 
			this->labelNazwa->AutoSize = true;
			this->labelNazwa->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelNazwa->Location = System::Drawing::Point(87, 215);
			this->labelNazwa->Name = L"labelNazwa";
			this->labelNazwa->Size = System::Drawing::Size(110, 20);
			this->labelNazwa->TabIndex = 62;
			this->labelNazwa->Text = L"Data zlecenia:";
			// 
			// labelEditKontrahent
			// 
			this->labelEditKontrahent->AutoSize = true;
			this->labelEditKontrahent->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->labelEditKontrahent->Location = System::Drawing::Point(346, 39);
			this->labelEditKontrahent->Name = L"labelEditKontrahent";
			this->labelEditKontrahent->Size = System::Drawing::Size(145, 24);
			this->labelEditKontrahent->TabIndex = 61;
			this->labelEditKontrahent->Text = L"Edycja Zlecenia";
			// 
			// dateTimeDataZlecenia
			// 
			this->dateTimeDataZlecenia->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->dateTimeDataZlecenia->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimeDataZlecenia->Location = System::Drawing::Point(194, 211);
			this->dateTimeDataZlecenia->Margin = System::Windows::Forms::Padding(2);
			this->dateTimeDataZlecenia->Name = L"dateTimeDataZlecenia";
			this->dateTimeDataZlecenia->Size = System::Drawing::Size(151, 26);
			this->dateTimeDataZlecenia->TabIndex = 3;
			this->dateTimeDataZlecenia->ValueChanged += gcnew System::EventHandler(this, &EdytujZlecenieForm::dateTimeDataZlecenia_ValueChanged);
			// 
			// dateTimeDataRealizacji
			// 
			this->dateTimeDataRealizacji->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->dateTimeDataRealizacji->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimeDataRealizacji->Location = System::Drawing::Point(574, 211);
			this->dateTimeDataRealizacji->Margin = System::Windows::Forms::Padding(2);
			this->dateTimeDataRealizacji->Name = L"dateTimeDataRealizacji";
			this->dateTimeDataRealizacji->Size = System::Drawing::Size(151, 26);
			this->dateTimeDataRealizacji->TabIndex = 4;
			// 
			// comboBoxLadunek
			// 
			this->comboBoxLadunek->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->comboBoxLadunek->FormattingEnabled = true;
			this->comboBoxLadunek->Location = System::Drawing::Point(267, 263);
			this->comboBoxLadunek->Name = L"comboBoxLadunek";
			this->comboBoxLadunek->Size = System::Drawing::Size(308, 28);
			this->comboBoxLadunek->TabIndex = 5;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label11->Location = System::Drawing::Point(87, 265);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(187, 20);
			this->label11->TabIndex = 76;
			this->label11->Text = L"Rodzaj ładunku/naczepy:";
			// 
			// comboBoxStatus
			// 
			this->comboBoxStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->comboBoxStatus->FormattingEnabled = true;
			this->comboBoxStatus->Location = System::Drawing::Point(547, 420);
			this->comboBoxStatus->Name = L"comboBoxStatus";
			this->comboBoxStatus->Size = System::Drawing::Size(179, 28);
			this->comboBoxStatus->TabIndex = 10;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label4->Location = System::Drawing::Point(485, 422);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(60, 20);
			this->label4->TabIndex = 78;
			this->label4->Text = L"Status:";
			// 
			// textBoxNrZlecenia
			// 
			this->textBoxNrZlecenia->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxNrZlecenia->Location = System::Drawing::Point(212, 157);
			this->textBoxNrZlecenia->Name = L"textBoxNrZlecenia";
			this->textBoxNrZlecenia->Size = System::Drawing::Size(298, 26);
			this->textBoxNrZlecenia->TabIndex = 2;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label7->Location = System::Drawing::Point(88, 160);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(118, 20);
			this->label7->TabIndex = 80;
			this->label7->Text = L"Numer zlecenia";
			// 
			// EdytujZlecenieForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(798, 629);
			this->Controls->Add(this->textBoxNrZlecenia);
			this->Controls->Add(this->label7);
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
			this->Margin = System::Windows::Forms::Padding(2);
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
		String^ nrZlecenia;
		String^ dataZamowienia;
		String^ skad;
		String^ dokad;
		int idLadunku;
		String^ opis;
		String^ dataRealizacji;
		int status;
		String^ naleznosc;

		nrZlecenia = this->textBoxNrZlecenia->Text;
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

		if ((nrZlecenia == "") || (dataZamowienia == "") || (dataRealizacji == "") || (skad == "") || (dokad == "") || (opis == "") || (naleznosc == "") || (idLadunku == 0) || (idKontrahenta == 0) || (status == 0))
		{
			MessageBox::Show("Wypełnij wszystkie pola");
		}
		else {
			//intIdLadunku = Convert::ToInt32(idLadunku);

			if (idZlecenia == 0) //dodanie nowego rekordu do tabeli Samochod
			{
				sqlString = "INSERT INTO dbo.Zlecenia (idKontrahenta,nrZlecenia,data_zamowienia, skad, dokad, idLadunku, opis, data_realizacji, status, naleznosc) " +
					"VALUES (@idKontrahenta,@nrZlecenia,@data_zamowienia, @skad, @dokad, @idLadunku, @opis, @data_realizacji, @status, @naleznosc)  ";
			}
			else { //edycja rekordu tabeli Samochod
				sqlString = "UPDATE dbo.Zlecenia SET idKontrahenta = @idKontrahenta, nrZlecenia=@nrZlecenia, data_zamowienia = @data_zamowienia, skad = @skad, dokad = @dokad, idLadunku = @idLadunku, opis = @opis, data_realizacji = @data_realizacji, status = @status, naleznosc = @naleznosc " +
					"WHERE id = @idZlecenia;";
			}

			try {
				SqlConnection^ sqlConnection = gcnew SqlConnection(connectionString);
				sqlConnection->Open();
				SqlCommand^ sqlCommand = gcnew SqlCommand(sqlString, sqlConnection);
				sqlCommand->Parameters->Add("@nrZlecenia", nrZlecenia);
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
	}
private: System::Void btnAnuluj_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}
private: System::Void comboBoxKontrahent_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	zmienNumerZlecenia();
}
private: System::Void dateTimeDataZlecenia_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	zmienNumerZlecenia();
}

	   private: System::Void zmienNumerZlecenia() {
		   if (this->comboBoxKontrahent->SelectedItem) { //jesli cos jest wybrane w comboboxie
			   ComboBoxItem^ comboBoxItem = (ComboBoxItem^)this->comboBoxKontrahent->SelectedItem;
			   textBoxNrZlecenia->Text = comboBoxItem->getValue() + "/" + dateTimeDataZlecenia->Text;
		   }
	   };
};
}

