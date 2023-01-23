#pragma once
#include "ComboBoxItem.h"

namespace Spedycja {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o EdytujSamochodForm
	/// </summary>
	public ref class EdytujSamochodForm : public System::Windows::Forms::Form
	{
	private:
		int idSamochodu = 0;
		String^ connectionString;

		String^ marka;
		String^ model;
		String^ nrRejestracyjny;
		String^ idLadunku;
		String^ ladownosc;
		String^ przebieg;
		String^ spalanieNaPusto;
		String^ spalanieZLadunkiem;
		String^ DMC;
		String^ iloscPalet;
		String^ objetosc;

	public:
		EdytujSamochodForm(int idSamochodu, String^ connectionString)
		{
			InitializeComponent();

			this->idSamochodu = idSamochodu;
			this->connectionString = connectionString;
			SqlConnection^ sqlConnection = gcnew SqlConnection(connectionString);
			SqlCommand^ sqlCommand;
			SqlDataReader^ sqlDataReader;
			sqlConnection->Open();

			if (idSamochodu != 0) //jesli edytujemy dane to trzeba wyswietlic dane w odpowiednich polach
			{
				try {

					sqlCommand = gcnew SqlCommand("select * from dbo.Samochody where id = " + idSamochodu, sqlConnection);
					SqlDataReader^ sqlDataReader = sqlCommand->ExecuteReader();
					sqlDataReader->Read();
					marka = sqlDataReader["Marka"]->ToString();
					this->textBoxMarka->Text = marka;
					model = sqlDataReader["Model"]->ToString();
					this->textBoxModel->Text = model;
					nrRejestracyjny = sqlDataReader["nr_rejestracyjny"]->ToString();
					this->textBoxNrRej->Text = nrRejestracyjny;
					ladownosc = sqlDataReader["Ladownosc"]->ToString();
					this->textBoxLadownosc->Text = ladownosc;

					przebieg = sqlDataReader["Przebieg"]->ToString();
					this->textBoxPrzebieg->Text = przebieg;
					spalanieNaPusto = sqlDataReader["spalanie_na_pusto"]->ToString();
					this->textBoxSpalanieBezLadunku->Text = spalanieNaPusto;
					spalanieZLadunkiem = sqlDataReader["spalanie_z_ladunkiem"]->ToString();
					this->textBoxSpalanieZLadunkiem->Text = spalanieZLadunkiem;

					DMC = sqlDataReader["DMC"]->ToString();
					this->textBoxMarka->Text = DMC;
					iloscPalet = sqlDataReader["ilosc_palet"]->ToString();
					this->textBoxMarka->Text = iloscPalet;

					objetosc = sqlDataReader["Objetosc"]->ToString();
					this->textBoxMarka->Text = objetosc;

					

					idLadunku = sqlDataReader["idLadunku"]->ToString();
					

					sqlDataReader->Close();
				}
				catch (Exception^ ex)
				{
					MessageBox::Show(ex->Message);
				}

			}

			//uzupe�nianie combobox�w
			try {


				sqlCommand = gcnew SqlCommand("select * from dbo.Stanowiska", sqlConnection);

				ComboBoxItem^ tempComboBoxItem;
				String^ tempId;
				String^ tempValue;

				sqlDataReader = sqlCommand->ExecuteReader();
				while (sqlDataReader->Read()) {
					tempId = sqlDataReader["id"]->ToString();
					tempValue = sqlDataReader["stanowisko"]->ToString();
					tempComboBoxItem = gcnew ComboBoxItem(tempId, tempValue);
					this->StanowiskoCBox->Items->Add(tempComboBoxItem);
					if ((idPracownika != 0) && (idStanowiska == tempId)) this->StanowiskoCBox->SelectedItem = tempComboBoxItem;
				}
				sqlDataReader->Close();

				sqlCommand = gcnew SqlCommand("select * from dbo.Lokalizacje", sqlConnection);

				sqlDataReader = sqlCommand->ExecuteReader();
				while (sqlDataReader->Read()) {
					tempId = sqlDataReader["id"]->ToString();
					tempValue = sqlDataReader["miasto"]->ToString();
					tempComboBoxItem = gcnew ComboBoxItem(tempId, tempValue);
					this->LokalizacjaCBox->Items->Add(tempComboBoxItem);
					if ((idPracownika != 0) && (idLokalizacji == tempId)) this->LokalizacjaCBox->SelectedItem = tempComboBoxItem;
				}
				//MessageBox::Show(this->LokalizacjaCBox->SelectedValue->ToString());

			}
			catch (Exception^ e) {
				MessageBox::Show(e->ToString());
			};

			sqlDataReader->Close();
			sqlConnection->Close();

		}

	protected:
		/// <summary>
		/// Wyczyść wszystkie używane zasoby.
		/// </summary>
		~EdytujSamochodForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBoxSpalanieBezLadunku;
	protected:

	protected:
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBoxDMC;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBoxPrzebieg;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBoxNrRej;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBoxLadownosc;

	private: System::Windows::Forms::TextBox^ textBoxModel;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBoxMarka;

	private: System::Windows::Forms::Button^ btnAnuluj;
	private: System::Windows::Forms::Button^ btnZatwierdz;
	private: System::Windows::Forms::Label^ labelNazwa;
	private: System::Windows::Forms::Label^ labelEditKontrahent;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBoxLadunek;
	private: System::Windows::Forms::TextBox^ textBoxSpalanieZLadunkiem;


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBoxObjetosc;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBoxIloscPalet;

	private: System::Windows::Forms::Label^ label10;

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obsługi projektanta — nie należy modyfikować
		/// jej zawartości w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBoxSpalanieBezLadunku = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBoxDMC = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBoxPrzebieg = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBoxNrRej = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBoxLadownosc = (gcnew System::Windows::Forms::TextBox());
			this->textBoxModel = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxMarka = (gcnew System::Windows::Forms::TextBox());
			this->btnAnuluj = (gcnew System::Windows::Forms::Button());
			this->btnZatwierdz = (gcnew System::Windows::Forms::Button());
			this->labelNazwa = (gcnew System::Windows::Forms::Label());
			this->labelEditKontrahent = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBoxLadunek = (gcnew System::Windows::Forms::ComboBox());
			this->textBoxSpalanieZLadunkiem = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBoxObjetosc = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBoxIloscPalet = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBoxSpalanieBezLadunku
			// 
			this->textBoxSpalanieBezLadunku->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->textBoxSpalanieBezLadunku->Location = System::Drawing::Point(237, 489);
			this->textBoxSpalanieBezLadunku->Name = L"textBoxSpalanieBezLadunku";
			this->textBoxSpalanieBezLadunku->Size = System::Drawing::Size(102, 26);
			this->textBoxSpalanieBezLadunku->TabIndex = 10;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label8->Location = System::Drawing::Point(69, 492);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(166, 20);
			this->label8->TabIndex = 39;
			this->label8->Text = L"Spalanie bez ładunku:";
			// 
			// textBoxDMC
			// 
			this->textBoxDMC->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxDMC->Location = System::Drawing::Point(500, 330);
			this->textBoxDMC->Name = L"textBoxDMC";
			this->textBoxDMC->Size = System::Drawing::Size(133, 26);
			this->textBoxDMC->TabIndex = 7;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label7->Location = System::Drawing::Point(414, 333);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(72, 20);
			this->label7->TabIndex = 37;
			this->label7->Text = L"DMC (T):";
			// 
			// textBoxPrzebieg
			// 
			this->textBoxPrzebieg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxPrzebieg->Location = System::Drawing::Point(500, 162);
			this->textBoxPrzebieg->Name = L"textBoxPrzebieg";
			this->textBoxPrzebieg->Size = System::Drawing::Size(207, 26);
			this->textBoxPrzebieg->TabIndex = 4;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label6->Location = System::Drawing::Point(419, 165);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(75, 20);
			this->label6->TabIndex = 35;
			this->label6->Text = L"Przebieg:";
			// 
			// textBoxNrRej
			// 
			this->textBoxNrRej->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxNrRej->Location = System::Drawing::Point(204, 162);
			this->textBoxNrRej->Name = L"textBoxNrRej";
			this->textBoxNrRej->Size = System::Drawing::Size(135, 26);
			this->textBoxNrRej->TabIndex = 3;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label5->Location = System::Drawing::Point(69, 165);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(120, 20);
			this->label5->TabIndex = 33;
			this->label5->Text = L"Nr rejestracyjny:";
			// 
			// textBoxLadownosc
			// 
			this->textBoxLadownosc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxLadownosc->Location = System::Drawing::Point(204, 327);
			this->textBoxLadownosc->Name = L"textBoxLadownosc";
			this->textBoxLadownosc->Size = System::Drawing::Size(135, 26);
			this->textBoxLadownosc->TabIndex = 6;
			// 
			// textBoxModel
			// 
			this->textBoxModel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxModel->Location = System::Drawing::Point(500, 115);
			this->textBoxModel->Name = L"textBoxModel";
			this->textBoxModel->Size = System::Drawing::Size(207, 26);
			this->textBoxModel->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(69, 330);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(117, 20);
			this->label3->TabIndex = 30;
			this->label3->Text = L"Ładowność (T):";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(438, 118);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 20);
			this->label1->TabIndex = 29;
			this->label1->Text = L"Model:";
			// 
			// textBoxMarka
			// 
			this->textBoxMarka->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxMarka->Location = System::Drawing::Point(132, 115);
			this->textBoxMarka->Name = L"textBoxMarka";
			this->textBoxMarka->Size = System::Drawing::Size(207, 26);
			this->textBoxMarka->TabIndex = 1;
			// 
			// btnAnuluj
			// 
			this->btnAnuluj->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnAnuluj->Location = System::Drawing::Point(423, 613);
			this->btnAnuluj->Name = L"btnAnuluj";
			this->btnAnuluj->Size = System::Drawing::Size(87, 34);
			this->btnAnuluj->TabIndex = 13;
			this->btnAnuluj->Text = L"Anuluj";
			this->btnAnuluj->UseVisualStyleBackColor = true;
			// 
			// btnZatwierdz
			// 
			this->btnZatwierdz->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnZatwierdz->Location = System::Drawing::Point(292, 613);
			this->btnZatwierdz->Name = L"btnZatwierdz";
			this->btnZatwierdz->Size = System::Drawing::Size(98, 34);
			this->btnZatwierdz->TabIndex = 12;
			this->btnZatwierdz->Text = L"Zatwierdź";
			this->btnZatwierdz->UseVisualStyleBackColor = true;
			// 
			// labelNazwa
			// 
			this->labelNazwa->AutoSize = true;
			this->labelNazwa->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelNazwa->Location = System::Drawing::Point(69, 118);
			this->labelNazwa->Name = L"labelNazwa";
			this->labelNazwa->Size = System::Drawing::Size(57, 20);
			this->labelNazwa->TabIndex = 25;
			this->labelNazwa->Text = L"Marka:";
			// 
			// labelEditKontrahent
			// 
			this->labelEditKontrahent->AutoSize = true;
			this->labelEditKontrahent->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->labelEditKontrahent->Location = System::Drawing::Point(307, 35);
			this->labelEditKontrahent->Name = L"labelEditKontrahent";
			this->labelEditKontrahent->Size = System::Drawing::Size(192, 24);
			this->labelEditKontrahent->TabIndex = 24;
			this->labelEditKontrahent->Text = L"Poprawa Samochodu";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(69, 277);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(209, 20);
			this->label2->TabIndex = 41;
			this->label2->Text = L"Typ ładunku/rodzaj naczepy:";
			this->label2->Click += gcnew System::EventHandler(this, &EdytujSamochodForm::label2_Click);
			// 
			// comboBoxLadunek
			// 
			this->comboBoxLadunek->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->comboBoxLadunek->FormattingEnabled = true;
			this->comboBoxLadunek->Location = System::Drawing::Point(293, 277);
			this->comboBoxLadunek->Name = L"comboBoxLadunek";
			this->comboBoxLadunek->Size = System::Drawing::Size(293, 28);
			this->comboBoxLadunek->TabIndex = 5;
			// 
			// textBoxSpalanieZLadunkiem
			// 
			this->textBoxSpalanieZLadunkiem->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->textBoxSpalanieZLadunkiem->Location = System::Drawing::Point(564, 489);
			this->textBoxSpalanieZLadunkiem->Name = L"textBoxSpalanieZLadunkiem";
			this->textBoxSpalanieZLadunkiem->Size = System::Drawing::Size(133, 26);
			this->textBoxSpalanieZLadunkiem->TabIndex = 11;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label4->Location = System::Drawing::Point(396, 492);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(164, 20);
			this->label4->TabIndex = 43;
			this->label4->Text = L"Spalanie z ładunkiem:";
			// 
			// textBoxObjetosc
			// 
			this->textBoxObjetosc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxObjetosc->Location = System::Drawing::Point(500, 384);
			this->textBoxObjetosc->Name = L"textBoxObjetosc";
			this->textBoxObjetosc->Size = System::Drawing::Size(133, 26);
			this->textBoxObjetosc->TabIndex = 9;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label9->Location = System::Drawing::Point(410, 390);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(76, 20);
			this->label9->TabIndex = 47;
			this->label9->Text = L"Objętość:";
			// 
			// textBoxIloscPalet
			// 
			this->textBoxIloscPalet->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxIloscPalet->Location = System::Drawing::Point(204, 387);
			this->textBoxIloscPalet->Name = L"textBoxIloscPalet";
			this->textBoxIloscPalet->Size = System::Drawing::Size(135, 26);
			this->textBoxIloscPalet->TabIndex = 8;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label10->Location = System::Drawing::Point(69, 390);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(85, 20);
			this->label10->TabIndex = 45;
			this->label10->Text = L"Ilość palet:";
			// 
			// EdytujSamochodForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(812, 678);
			this->Controls->Add(this->textBoxObjetosc);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->textBoxIloscPalet);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->textBoxSpalanieZLadunkiem);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->comboBoxLadunek);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBoxSpalanieBezLadunku);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBoxDMC);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBoxPrzebieg);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBoxNrRej);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBoxLadownosc);
			this->Controls->Add(this->textBoxModel);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBoxMarka);
			this->Controls->Add(this->btnAnuluj);
			this->Controls->Add(this->btnZatwierdz);
			this->Controls->Add(this->labelNazwa);
			this->Controls->Add(this->labelEditKontrahent);
			this->Name = L"EdytujSamochodForm";
			this->Text = L"EdytujSamochodForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
