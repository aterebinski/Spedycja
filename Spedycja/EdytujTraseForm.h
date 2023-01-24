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
	/// Podsumowanie informacji o EdytujTraseForm
	/// </summary>
	public ref class EdytujTraseForm : public System::Windows::Forms::Form
	{
	private:
		int idTrasy = 0;
		String^ connectionString;

		int idZlecenia;
		int idKierowcy;
		int idSamochodu;
		int status;
		String^ kilometry;
		String^ dataWykonania;
		String^ kosztPaliwa;

	public:
		EdytujTraseForm(int idTrasy, int idZlecenia, String^ connectionString)
		{
			InitializeComponent();

			this->idZlecenia = idZlecenia;
			this->idTrasy = idTrasy;
			this->connectionString = connectionString;
			SqlConnection^ sqlConnection = gcnew SqlConnection(connectionString);
			SqlCommand^ sqlCommand;
			SqlDataReader^ sqlDataReader;
			sqlConnection->Open();


			if (idTrasy != 0) //jesli edytujemy dane to trzeba wyswietlic dane w odpowiednich polach
			{
				try {

					sqlCommand = gcnew SqlCommand("select * from dbo.Trasy where id = " + idTrasy, sqlConnection);
					SqlDataReader^ sqlDataReader = sqlCommand->ExecuteReader();
					sqlDataReader->Read();

					kilometry = sqlDataReader["kilometry"]->ToString();
					this->textBoxKilometry->Text = kilometry;

					dataWykonania = sqlDataReader["data_wykonania"]->ToString();
					this->dateTimeDataWykonania->Text = dataWykonania;


					kosztPaliwa = sqlDataReader["koszt_paliwa"]->ToString();
					this->textBoxKosztPaliwa->Text = kosztPaliwa;

					idZlecenia = (int)sqlDataReader["idZlecenia"];
					idKierowcy = (int)sqlDataReader["idKierowcy"];
					idSamochodu = (int)sqlDataReader["idSamochodu"];
					status = (int)sqlDataReader["status"];


					sqlDataReader->Close();
				}
				catch (Exception^ ex)
				{
					MessageBox::Show(ex->Message);
				}

			}
			else {
				status = 2;

				//DateTime^ DateTimeNow = gcnew DateTime;
				//DateTimeNow = DateTime::Now;

				//String^ currentDate = String::Format(L"{0:D4}-{1:D2}-{2:D2}", DateTimeNow->Year, DateTimeNow->Month, DateTimeNow->Day);

				//String^ currentDate = "" + DateTimeNow->Year +"-" + DateTimeNow->Month + "-" + DateTimeNow->Day;
				
				dateTimeDataWykonania->Text = "";
			}

			//uzupelnianie comboboxow
			try {

				ComboBoxItem^ tempComboBoxItem;
				int tempId;
				String^ tempValue;

				sqlCommand = gcnew SqlCommand("select z.id, concat(z.nrZlecenia,' -- ',k.Nazwa,' -- ',z.data_zamowienia) as Zlecenie from dbo.Zlecenia z, dbo.Kontrahenci k where z.idKontrahenta = k.id", sqlConnection);
				sqlDataReader = sqlCommand->ExecuteReader();
				while (sqlDataReader->Read()) {
					tempId = (int)sqlDataReader["id"];
					tempValue = sqlDataReader["Zlecenie"]->ToString();
					tempComboBoxItem = gcnew ComboBoxItem(tempId, tempValue);
					this->comboBoxZlecenie->Items->Add(tempComboBoxItem);
					if ((idTrasy != 0) && (idZlecenia == tempId)) this->comboBoxZlecenie->SelectedItem = tempComboBoxItem;
				}

				sqlDataReader->Close();

				sqlCommand = gcnew SqlCommand("select id, concat(imie,' ', nazwisko) as Kierowca from dbo.Kierowcy", sqlConnection);
				sqlDataReader = sqlCommand->ExecuteReader();
				while (sqlDataReader->Read()) {
					tempId = (int)sqlDataReader["ID"];
					tempValue = sqlDataReader["Kierowca"]->ToString();
					tempComboBoxItem = gcnew ComboBoxItem(tempId, tempValue);
					this->comboBoxKierowca->Items->Add(tempComboBoxItem);
					if ((idTrasy != 0) && (idKierowcy == tempId)) this->comboBoxKierowca->SelectedItem = tempComboBoxItem;
				}

				sqlDataReader->Close();

				sqlCommand = gcnew SqlCommand("select id, concat(marka,' ',model,' -- ', nr_rejestracyjny) as Samochod from dbo.Samochody", sqlConnection);
				sqlDataReader = sqlCommand->ExecuteReader();
				while (sqlDataReader->Read()) {
					tempId = (int)sqlDataReader["ID"];
					tempValue = sqlDataReader["Samochod"]->ToString();
					tempComboBoxItem = gcnew ComboBoxItem(tempId, tempValue);
					this->comboBoxSamochod->Items->Add(tempComboBoxItem);
					if ((idTrasy != 0) && (idKierowcy == tempId)) this->comboBoxSamochod->SelectedItem = tempComboBoxItem;
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
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~EdytujTraseForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::ComboBox^ comboBoxStatus;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ comboBoxSamochod;

	private: System::Windows::Forms::Label^ label11;
private: System::Windows::Forms::DateTimePicker^ dateTimeDataWykonania;

	private: System::Windows::Forms::TextBox^ textBoxKilometry;


	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::ComboBox^ comboBoxZlecenie;
	private: System::Windows::Forms::Label^ label2;






	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnAnuluj;
	private: System::Windows::Forms::Button^ btnZatwierdz;

	private: System::Windows::Forms::Label^ labelEditKontrahent;
	private: System::Windows::Forms::ComboBox^ comboBoxKierowca;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBoxKosztPaliwa;

	private: System::Windows::Forms::Label^ label9;

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
			this->comboBoxStatus = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBoxSamochod = (gcnew System::Windows::Forms::ComboBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->dateTimeDataWykonania = (gcnew System::Windows::Forms::DateTimePicker());
			this->textBoxKilometry = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->comboBoxZlecenie = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnAnuluj = (gcnew System::Windows::Forms::Button());
			this->btnZatwierdz = (gcnew System::Windows::Forms::Button());
			this->labelEditKontrahent = (gcnew System::Windows::Forms::Label());
			this->comboBoxKierowca = (gcnew System::Windows::Forms::ComboBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBoxKosztPaliwa = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// comboBoxStatus
			// 
			this->comboBoxStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->comboBoxStatus->FormattingEnabled = true;
			this->comboBoxStatus->Location = System::Drawing::Point(174, 313);
			this->comboBoxStatus->Name = L"comboBoxStatus";
			this->comboBoxStatus->Size = System::Drawing::Size(179, 28);
			this->comboBoxStatus->TabIndex = 90;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label4->Location = System::Drawing::Point(82, 316);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(60, 20);
			this->label4->TabIndex = 102;
			this->label4->Text = L"Status:";
			// 
			// comboBoxSamochod
			// 
			this->comboBoxSamochod->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->comboBoxSamochod->FormattingEnabled = true;
			this->comboBoxSamochod->Location = System::Drawing::Point(174, 244);
			this->comboBoxSamochod->Name = L"comboBoxSamochod";
			this->comboBoxSamochod->Size = System::Drawing::Size(397, 28);
			this->comboBoxSamochod->TabIndex = 85;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label11->Location = System::Drawing::Point(82, 247);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(90, 20);
			this->label11->TabIndex = 101;
			this->label11->Text = L"Samochód:";
			// 
			// dateTimeDataWykonania
			// 
			this->dateTimeDataWykonania->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->dateTimeDataWykonania->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimeDataWykonania->Location = System::Drawing::Point(213, 368);
			this->dateTimeDataWykonania->Margin = System::Windows::Forms::Padding(2);
			this->dateTimeDataWykonania->Name = L"dateTimeDataWykonania";
			this->dateTimeDataWykonania->Size = System::Drawing::Size(151, 26);
			this->dateTimeDataWykonania->TabIndex = 84;
			// 
			// textBoxKilometry
			// 
			this->textBoxKilometry->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxKilometry->Location = System::Drawing::Point(174, 422);
			this->textBoxKilometry->Name = L"textBoxKilometry";
			this->textBoxKilometry->Size = System::Drawing::Size(179, 26);
			this->textBoxKilometry->TabIndex = 89;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label10->Location = System::Drawing::Point(82, 425);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(77, 20);
			this->label10->TabIndex = 100;
			this->label10->Text = L"Kilometry:";
			// 
			// comboBoxZlecenie
			// 
			this->comboBoxZlecenie->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->comboBoxZlecenie->FormattingEnabled = true;
			this->comboBoxZlecenie->Location = System::Drawing::Point(174, 124);
			this->comboBoxZlecenie->Name = L"comboBoxZlecenie";
			this->comboBoxZlecenie->Size = System::Drawing::Size(547, 28);
			this->comboBoxZlecenie->TabIndex = 81;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(82, 127);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 20);
			this->label2->TabIndex = 99;
			this->label2->Text = L"Zlecenie:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(82, 373);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(126, 20);
			this->label1->TabIndex = 95;
			this->label1->Text = L"Data wykonania:";
			// 
			// btnAnuluj
			// 
			this->btnAnuluj->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnAnuluj->Location = System::Drawing::Point(434, 573);
			this->btnAnuluj->Name = L"btnAnuluj";
			this->btnAnuluj->Size = System::Drawing::Size(87, 34);
			this->btnAnuluj->TabIndex = 92;
			this->btnAnuluj->Text = L"Anuluj";
			this->btnAnuluj->UseVisualStyleBackColor = true;
			this->btnAnuluj->Click += gcnew System::EventHandler(this, &EdytujTraseForm::btnAnuluj_Click);
			// 
			// btnZatwierdz
			// 
			this->btnZatwierdz->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnZatwierdz->Location = System::Drawing::Point(316, 573);
			this->btnZatwierdz->Name = L"btnZatwierdz";
			this->btnZatwierdz->Size = System::Drawing::Size(98, 34);
			this->btnZatwierdz->TabIndex = 91;
			this->btnZatwierdz->Text = L"ZatwierdŸ";
			this->btnZatwierdz->UseVisualStyleBackColor = true;
			this->btnZatwierdz->Click += gcnew System::EventHandler(this, &EdytujTraseForm::btnZatwierdz_Click);
			// 
			// labelEditKontrahent
			// 
			this->labelEditKontrahent->AutoSize = true;
			this->labelEditKontrahent->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->labelEditKontrahent->Location = System::Drawing::Point(385, 47);
			this->labelEditKontrahent->Name = L"labelEditKontrahent";
			this->labelEditKontrahent->Size = System::Drawing::Size(57, 24);
			this->labelEditKontrahent->TabIndex = 93;
			this->labelEditKontrahent->Text = L"Trasa";
			// 
			// comboBoxKierowca
			// 
			this->comboBoxKierowca->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->comboBoxKierowca->FormattingEnabled = true;
			this->comboBoxKierowca->Location = System::Drawing::Point(174, 181);
			this->comboBoxKierowca->Name = L"comboBoxKierowca";
			this->comboBoxKierowca->Size = System::Drawing::Size(397, 28);
			this->comboBoxKierowca->TabIndex = 104;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label8->Location = System::Drawing::Point(82, 184);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(77, 20);
			this->label8->TabIndex = 105;
			this->label8->Text = L"Kierowca:";
			// 
			// textBoxKosztPaliwa
			// 
			this->textBoxKosztPaliwa->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxKosztPaliwa->Location = System::Drawing::Point(189, 477);
			this->textBoxKosztPaliwa->Name = L"textBoxKosztPaliwa";
			this->textBoxKosztPaliwa->Size = System::Drawing::Size(164, 26);
			this->textBoxKosztPaliwa->TabIndex = 106;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label9->Location = System::Drawing::Point(82, 480);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(101, 20);
			this->label9->TabIndex = 107;
			this->label9->Text = L"Koszt paliwa:";
			// 
			// EdytujTraseForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(825, 665);
			this->Controls->Add(this->textBoxKosztPaliwa);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->comboBoxKierowca);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->comboBoxStatus);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->comboBoxSamochod);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->dateTimeDataWykonania);
			this->Controls->Add(this->textBoxKilometry);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->comboBoxZlecenie);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnAnuluj);
			this->Controls->Add(this->btnZatwierdz);
			this->Controls->Add(this->labelEditKontrahent);
			this->Name = L"EdytujTraseForm";
			this->Text = L"EdytujTraseForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnZatwierdz_Click(System::Object^ sender, System::EventArgs^ e) {
		ComboBoxItem^ selectedKierowca = (ComboBoxItem^)this->comboBoxKierowca->SelectedItem;
		ComboBoxItem^ selectedSamochod = (ComboBoxItem^)this->comboBoxSamochod->SelectedItem;
		ComboBoxItem^ selectedZlecenie = (ComboBoxItem^)this->comboBoxZlecenie->SelectedItem;
		ComboBoxItem^ selectedStatus = (ComboBoxItem^)this->comboBoxStatus->SelectedItem;

		/*int idZlecenia;
		int idKierowcy;
		int idSamochodu;
		int status;
		int kilometry = 0;
		String^ dataWykonania;
		double kosztPaliwa = 0;*/

		kilometry = textBoxKilometry->Text;
		
		dataWykonania = this->dateTimeDataWykonania->Text;

		kosztPaliwa = this->textBoxKosztPaliwa->Text;
		

		idZlecenia = selectedZlecenie->getId();
		idKierowcy = selectedKierowca->getId();
		idSamochodu = selectedSamochod->getId();
		status = selectedStatus->getId();


		//int intIdLadunku;
		String^ sqlString;

		if ((idZlecenia == 0) || (status == 0))
		{
			MessageBox::Show("Wype³nij podstawowe pola");
		}
		else {
			//intIdLadunku = Convert::ToInt32(idLadunku);

			if (idTrasy == 0) //dodanie nowego rekordu do tabeli Samochod
			{
				sqlString = "INSERT INTO dbo.Trasy (idZlecenia, idKierowcy, idSamochodu, status, kilometry, data_wykonania, koszt_paliwa) " +
					"VALUES(@idZlecenia, @idKierowcy, @idSamochodu, @status, @kilometry, @data_wykonania, @koszt_paliwa)";
					
			}
			else { //edycja rekordu tabeli Samochod
				sqlString = "UPDATE dbo.Trasy SET idZlecenia = @idZlecenia, idKierowcy = @idKierowcy, idSamochodu = @idSamochodu, status = @status, kilometry = @kilometry, data_wykonania = @data_wykonania, koszt_paliwa = @koszt_paliwa " +
					"WHERE id = @idTrasy;";
			}

			try {
				SqlConnection^ sqlConnection = gcnew SqlConnection(connectionString);
				sqlConnection->Open();
				SqlCommand^ sqlCommand = gcnew SqlCommand(sqlString, sqlConnection);
				sqlCommand->Parameters->Add("@idZlecenia", idZlecenia);
				sqlCommand->Parameters->Add("@idKierowcy", idKierowcy);
				sqlCommand->Parameters->Add("@idSamochodu", idSamochodu);
				sqlCommand->Parameters->Add("@status", status);
				sqlCommand->Parameters->Add("@kilometry", kilometry);
				sqlCommand->Parameters->Add("@data_wykonania", dataWykonania);
				sqlCommand->Parameters->Add("@koszt_paliwa", kosztPaliwa);

				if (idTrasy != 0) sqlCommand->Parameters->Add("@idTrasy", idTrasy);

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
