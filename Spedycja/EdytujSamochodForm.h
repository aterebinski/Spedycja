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
		int idLadunku;
		String^ ladownosc;
		String^ przebieg;
		String^ spalanie;
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
					spalanie = sqlDataReader["spalanie"]->ToString();
					this->textBoxSpalanie->Text = spalanie;
					

					DMC = sqlDataReader["DMC"]->ToString();
					this->textBoxDMC->Text = DMC;
					iloscPalet = sqlDataReader["ilosc_palet"]->ToString();
					this->textBoxIloscPalet->Text = iloscPalet;

					objetosc = sqlDataReader["Objetosc"]->ToString();
					this->textBoxObjetosc->Text = objetosc;

					

					idLadunku = (int)sqlDataReader["idLadunku"];
					

					sqlDataReader->Close();
				}
				catch (Exception^ ex)
				{
					MessageBox::Show(ex->Message);
				}

			}

			//uzupelnianie comboboxow
			try {


				sqlCommand = gcnew SqlCommand("select * from dbo.Ladunki", sqlConnection);

				ComboBoxItem^ tempComboBoxItem;
				int tempId;
				String^ tempValue;

				sqlDataReader = sqlCommand->ExecuteReader();
				while (sqlDataReader->Read()) {
					tempId = (int)sqlDataReader["ID"];
					tempValue = sqlDataReader["Nazwa"]->ToString();
					tempComboBoxItem = gcnew ComboBoxItem(tempId, tempValue);
					this->comboBoxLadunek->Items->Add(tempComboBoxItem);
					if ((idSamochodu != 0) && (idLadunku == tempId)) this->comboBoxLadunek->SelectedItem = tempComboBoxItem;
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
		/// Wyczyść wszystkie używane zasoby.
		/// </summary>
		~EdytujSamochodForm()
		{
			if (components)
			{
				delete components;
			}
		}
private: System::Windows::Forms::TextBox^  textBoxSpalanie;
protected:

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
			this->textBoxSpalanie = (gcnew System::Windows::Forms::TextBox());
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
			this->textBoxObjetosc = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBoxIloscPalet = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBoxSpalanie
			// 
			this->textBoxSpalanie->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxSpalanie->Location = System::Drawing::Point(264, 262);
			this->textBoxSpalanie->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBoxSpalanie->Name = L"textBoxSpalanie";
			this->textBoxSpalanie->Size = System::Drawing::Size(135, 30);
			this->textBoxSpalanie->TabIndex = 10;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label8->Location = System::Drawing::Point(92, 267);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(164, 25);
			this->label8->TabIndex = 39;
			this->label8->Text = L"Średnie spalanie:";
			// 
			// textBoxDMC
			// 
			this->textBoxDMC->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxDMC->Location = System::Drawing::Point(667, 406);
			this->textBoxDMC->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBoxDMC->Name = L"textBoxDMC";
			this->textBoxDMC->Size = System::Drawing::Size(176, 30);
			this->textBoxDMC->TabIndex = 7;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label7->Location = System::Drawing::Point(552, 410);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(96, 25);
			this->label7->TabIndex = 37;
			this->label7->Text = L"DMC (T):";
			// 
			// textBoxPrzebieg
			// 
			this->textBoxPrzebieg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxPrzebieg->Location = System::Drawing::Point(667, 199);
			this->textBoxPrzebieg->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBoxPrzebieg->Name = L"textBoxPrzebieg";
			this->textBoxPrzebieg->Size = System::Drawing::Size(275, 30);
			this->textBoxPrzebieg->TabIndex = 4;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label6->Location = System::Drawing::Point(559, 203);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(95, 25);
			this->label6->TabIndex = 35;
			this->label6->Text = L"Przebieg:";
			// 
			// textBoxNrRej
			// 
			this->textBoxNrRej->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxNrRej->Location = System::Drawing::Point(264, 199);
			this->textBoxNrRej->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBoxNrRej->Name = L"textBoxNrRej";
			this->textBoxNrRej->Size = System::Drawing::Size(187, 30);
			this->textBoxNrRej->TabIndex = 3;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label5->Location = System::Drawing::Point(92, 203);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(152, 25);
			this->label5->TabIndex = 33;
			this->label5->Text = L"Nr rejestracyjny:";
			// 
			// textBoxLadownosc
			// 
			this->textBoxLadownosc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxLadownosc->Location = System::Drawing::Point(272, 402);
			this->textBoxLadownosc->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBoxLadownosc->Name = L"textBoxLadownosc";
			this->textBoxLadownosc->Size = System::Drawing::Size(179, 30);
			this->textBoxLadownosc->TabIndex = 6;
			// 
			// textBoxModel
			// 
			this->textBoxModel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxModel->Location = System::Drawing::Point(667, 142);
			this->textBoxModel->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBoxModel->Name = L"textBoxModel";
			this->textBoxModel->Size = System::Drawing::Size(275, 30);
			this->textBoxModel->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(92, 406);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(150, 25);
			this->label3->TabIndex = 30;
			this->label3->Text = L"Ładowność (T):";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(584, 145);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(72, 25);
			this->label1->TabIndex = 29;
			this->label1->Text = L"Model:";
			// 
			// textBoxMarka
			// 
			this->textBoxMarka->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxMarka->Location = System::Drawing::Point(176, 142);
			this->textBoxMarka->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBoxMarka->Name = L"textBoxMarka";
			this->textBoxMarka->Size = System::Drawing::Size(275, 30);
			this->textBoxMarka->TabIndex = 1;
			// 
			// btnAnuluj
			// 
			this->btnAnuluj->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnAnuluj->Location = System::Drawing::Point(564, 595);
			this->btnAnuluj->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnAnuluj->Name = L"btnAnuluj";
			this->btnAnuluj->Size = System::Drawing::Size(116, 42);
			this->btnAnuluj->TabIndex = 13;
			this->btnAnuluj->Text = L"Anuluj";
			this->btnAnuluj->UseVisualStyleBackColor = true;
			this->btnAnuluj->Click += gcnew System::EventHandler(this, &EdytujSamochodForm::btnAnuluj_Click);
			// 
			// btnZatwierdz
			// 
			this->btnZatwierdz->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnZatwierdz->Location = System::Drawing::Point(406, 595);
			this->btnZatwierdz->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnZatwierdz->Name = L"btnZatwierdz";
			this->btnZatwierdz->Size = System::Drawing::Size(131, 42);
			this->btnZatwierdz->TabIndex = 12;
			this->btnZatwierdz->Text = L"Zatwierdź";
			this->btnZatwierdz->UseVisualStyleBackColor = true;
			this->btnZatwierdz->Click += gcnew System::EventHandler(this, &EdytujSamochodForm::btnZatwierdz_Click);
			// 
			// labelNazwa
			// 
			this->labelNazwa->AutoSize = true;
			this->labelNazwa->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelNazwa->Location = System::Drawing::Point(92, 145);
			this->labelNazwa->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelNazwa->Name = L"labelNazwa";
			this->labelNazwa->Size = System::Drawing::Size(73, 25);
			this->labelNazwa->TabIndex = 25;
			this->labelNazwa->Text = L"Marka:";
			// 
			// labelEditKontrahent
			// 
			this->labelEditKontrahent->AutoSize = true;
			this->labelEditKontrahent->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->labelEditKontrahent->Location = System::Drawing::Point(409, 43);
			this->labelEditKontrahent->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelEditKontrahent->Name = L"labelEditKontrahent";
			this->labelEditKontrahent->Size = System::Drawing::Size(244, 29);
			this->labelEditKontrahent->TabIndex = 24;
			this->labelEditKontrahent->Text = L"Poprawa Samochodu";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(92, 341);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(264, 25);
			this->label2->TabIndex = 41;
			this->label2->Text = L"Typ ładunku/rodzaj naczepy:";
			// 
			// comboBoxLadunek
			// 
			this->comboBoxLadunek->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->comboBoxLadunek->FormattingEnabled = true;
			this->comboBoxLadunek->Location = System::Drawing::Point(391, 341);
			this->comboBoxLadunek->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->comboBoxLadunek->Name = L"comboBoxLadunek";
			this->comboBoxLadunek->Size = System::Drawing::Size(389, 33);
			this->comboBoxLadunek->TabIndex = 5;
			// 
			// textBoxObjetosc
			// 
			this->textBoxObjetosc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxObjetosc->Location = System::Drawing::Point(667, 473);
			this->textBoxObjetosc->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBoxObjetosc->Name = L"textBoxObjetosc";
			this->textBoxObjetosc->Size = System::Drawing::Size(176, 30);
			this->textBoxObjetosc->TabIndex = 9;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label9->Location = System::Drawing::Point(547, 480);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(96, 25);
			this->label9->TabIndex = 47;
			this->label9->Text = L"Objętość:";
			// 
			// textBoxIloscPalet
			// 
			this->textBoxIloscPalet->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxIloscPalet->Location = System::Drawing::Point(272, 476);
			this->textBoxIloscPalet->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBoxIloscPalet->Name = L"textBoxIloscPalet";
			this->textBoxIloscPalet->Size = System::Drawing::Size(179, 30);
			this->textBoxIloscPalet->TabIndex = 8;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label10->Location = System::Drawing::Point(92, 480);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(105, 25);
			this->label10->TabIndex = 45;
			this->label10->Text = L"Ilość palet:";
			// 
			// EdytujSamochodForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1083, 663);
			this->Controls->Add(this->textBoxObjetosc);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->textBoxIloscPalet);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->comboBoxLadunek);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBoxSpalanie);
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
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"EdytujSamochodForm";
			this->Text = L"EdytujSamochodForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void btnZatwierdz_Click(System::Object^ sender, System::EventArgs^ e) {
	ComboBoxItem^ selectedLadunek = (ComboBoxItem^)this->comboBoxLadunek->SelectedItem;
	//MessageBox::Show(selectedLokalizacja->getId());

	marka = this->textBoxMarka->Text;
	model = this->textBoxModel->Text;
	nrRejestracyjny = this->textBoxNrRej->Text;
	ladownosc = this->textBoxLadownosc->Text;
	przebieg = this->textBoxPrzebieg->Text;
	spalanie = this->textBoxSpalanie->Text;
	DMC = this->textBoxDMC->Text;
	iloscPalet = this->textBoxIloscPalet->Text;
	objetosc = this->textBoxObjetosc->Text;

	idLadunku = (int)selectedLadunek->getId();


	//int intIdLadunku;
	String^ sqlString;

	if ((marka == "") || (model == "") || (nrRejestracyjny == "") || (ladownosc == "") || (przebieg == "") || (spalanie == "") ||  (DMC == "") || (iloscPalet == "") || (objetosc == "") || (idLadunku == 0))
	{
		MessageBox::Show("Wypełnij wszystkie pola");
	}
	else {
		//intIdLadunku = Convert::ToInt32(idLadunku);

		if (idSamochodu == 0) //dodanie nowego rekordu do tabeli Samochod
		{
			sqlString = "insert into dbo.Samochody(marka,model,nr_rejestracyjny,ladownosc,przebieg,spalanie,DMC,ilosc_palet,objetosc,idLadunku) " +
				"values(@marka, @model, @nrRejestracyjny, @ladownosc, @przebieg, @spalanie,@DMC,@iloscPalet,@objetosc,@idLadunku); ";
		}
		else { //edycja rekordu tabeli Samochod
			sqlString = "update dbo.Samochody set marka = @marka, model = @model, nr_rejestracyjny = @nrRejestracyjny, ladownosc = @ladownosc, przebieg = @przebieg, " +
				"spalanie = @spalanie,  DMC = @DMC, ilosc_palet = @iloscPalet,objetosc=@objetosc,idLadunku=@idLadunku " +
				"where ID = @idSamochodu ;";
		}

		try {
			SqlConnection^ sqlConnection = gcnew SqlConnection(connectionString);
			sqlConnection->Open();
			SqlCommand^ sqlCommand = gcnew SqlCommand(sqlString, sqlConnection);
			sqlCommand->Parameters->Add("@marka", marka);
			sqlCommand->Parameters->Add("@model", model);
			sqlCommand->Parameters->Add("@nr_rejestracyjny", nrRejestracyjny);
			sqlCommand->Parameters->Add("@ladownosc", ladownosc);
			sqlCommand->Parameters->Add("@przebieg", przebieg);
			sqlCommand->Parameters->Add("@spalanie", spalanie);
			sqlCommand->Parameters->Add("@DMC", DMC);
			sqlCommand->Parameters->Add("@iloscPalet", iloscPalet);
			sqlCommand->Parameters->Add("@objetosc", objetosc);
			sqlCommand->Parameters->Add("@idLadunku", idLadunku);

			if (idSamochodu != 0) sqlCommand->Parameters->Add("@idSamochodu", idSamochodu);

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
