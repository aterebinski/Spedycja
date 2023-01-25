#pragma once
#include "EdytujTraseForm.h"

namespace Spedycja {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::SqlClient;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o TrasyForm
	/// </summary>
	public ref class TrasyForm : public System::Windows::Forms::Form
	{
	private:
		String^ connectionString;
	public:
		TrasyForm(String^ connectionString)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
			this->connectionString = connectionString;
			this->generateView();
		}

	protected:
		/// <summary>
		/// Wyczyść wszystkie używane zasoby.
		/// </summary>
		~TrasyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnWykonaj;
	protected:
	private: System::Windows::Forms::Button^ btnRezerwuj;
	private: System::Windows::Forms::Label^ labelZlecenia;
	private: System::Windows::Forms::Button^ btnUsun;
	private: System::Windows::Forms::Button^ btnEdytuj;
	private: System::Windows::Forms::Button^ btnDodaj;
	private: System::Windows::Forms::DataGridView^ dataGridViewTrasy;


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
			this->btnWykonaj = (gcnew System::Windows::Forms::Button());
			this->btnRezerwuj = (gcnew System::Windows::Forms::Button());
			this->labelZlecenia = (gcnew System::Windows::Forms::Label());
			this->btnUsun = (gcnew System::Windows::Forms::Button());
			this->btnEdytuj = (gcnew System::Windows::Forms::Button());
			this->btnDodaj = (gcnew System::Windows::Forms::Button());
			this->dataGridViewTrasy = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewTrasy))->BeginInit();
			this->SuspendLayout();
			// 
			// btnWykonaj
			// 
			this->btnWykonaj->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnWykonaj->Location = System::Drawing::Point(682, 505);
			this->btnWykonaj->Name = L"btnWykonaj";
			this->btnWykonaj->Size = System::Drawing::Size(87, 34);
			this->btnWykonaj->TabIndex = 26;
			this->btnWykonaj->Text = L"Usuń";
			this->btnWykonaj->UseVisualStyleBackColor = true;
			// 
			// btnRezerwuj
			// 
			this->btnRezerwuj->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnRezerwuj->Location = System::Drawing::Point(436, 505);
			this->btnRezerwuj->Name = L"btnRezerwuj";
			this->btnRezerwuj->Size = System::Drawing::Size(241, 34);
			this->btnRezerwuj->TabIndex = 25;
			this->btnRezerwuj->Text = L"Rezerwuj kierowcę/samochód";
			this->btnRezerwuj->UseVisualStyleBackColor = true;
			// 
			// labelZlecenia
			// 
			this->labelZlecenia->AutoSize = true;
			this->labelZlecenia->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelZlecenia->Location = System::Drawing::Point(37, 38);
			this->labelZlecenia->Name = L"labelZlecenia";
			this->labelZlecenia->Size = System::Drawing::Size(56, 24);
			this->labelZlecenia->TabIndex = 24;
			this->labelZlecenia->Text = L"Trasy";
			// 
			// btnUsun
			// 
			this->btnUsun->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnUsun->Location = System::Drawing::Point(227, 505);
			this->btnUsun->Name = L"btnUsun";
			this->btnUsun->Size = System::Drawing::Size(87, 34);
			this->btnUsun->TabIndex = 21;
			this->btnUsun->Text = L"Usuń";
			this->btnUsun->UseVisualStyleBackColor = true;
			this->btnUsun->Click += gcnew System::EventHandler(this, &TrasyForm::btnUsun_Click);
			// 
			// btnEdytuj
			// 
			this->btnEdytuj->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnEdytuj->Location = System::Drawing::Point(134, 505);
			this->btnEdytuj->Name = L"btnEdytuj";
			this->btnEdytuj->Size = System::Drawing::Size(87, 34);
			this->btnEdytuj->TabIndex = 22;
			this->btnEdytuj->Text = L"Popraw";
			this->btnEdytuj->UseVisualStyleBackColor = true;
			this->btnEdytuj->Click += gcnew System::EventHandler(this, &TrasyForm::btnEdytuj_Click);
			// 
			// btnDodaj
			// 
			this->btnDodaj->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnDodaj->Location = System::Drawing::Point(41, 505);
			this->btnDodaj->Name = L"btnDodaj";
			this->btnDodaj->Size = System::Drawing::Size(87, 34);
			this->btnDodaj->TabIndex = 23;
			this->btnDodaj->Text = L"Dodaj";
			this->btnDodaj->UseVisualStyleBackColor = true;
			this->btnDodaj->Click += gcnew System::EventHandler(this, &TrasyForm::btnDodaj_Click);
			// 
			// dataGridViewTrasy
			// 
			this->dataGridViewTrasy->AllowUserToAddRows = false;
			this->dataGridViewTrasy->AllowUserToDeleteRows = false;
			this->dataGridViewTrasy->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewTrasy->Location = System::Drawing::Point(41, 91);
			this->dataGridViewTrasy->Name = L"dataGridViewTrasy";
			this->dataGridViewTrasy->ReadOnly = true;
			this->dataGridViewTrasy->RowHeadersVisible = false;
			this->dataGridViewTrasy->Size = System::Drawing::Size(1041, 374);
			this->dataGridViewTrasy->TabIndex = 20;
			// 
			// TrasyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1130, 571);
			this->Controls->Add(this->btnWykonaj);
			this->Controls->Add(this->btnRezerwuj);
			this->Controls->Add(this->labelZlecenia);
			this->Controls->Add(this->btnUsun);
			this->Controls->Add(this->btnEdytuj);
			this->Controls->Add(this->btnDodaj);
			this->Controls->Add(this->dataGridViewTrasy);
			this->Name = L"TrasyForm";
			this->Text = L"TrasyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewTrasy))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		System::Void generateView() {
			//SqlDataReader^ sqlDataReader;
			try
			{
				SqlConnection^ sqlConnection = gcnew SqlConnection(connectionString);
				/*String^ sqlString = "select t.id, z.nrZlecenia as 'Numer zlecenia', k.Nazwa as Kontrahent, z.data_zamowienia as 'Data zamówienia', z.Skad, z.Dokad, l.Nazwa as Ładunek, z.Opis, z.data_realizacji as 'Data realizacji', s.status, z.naleznosc as Należność " +
					"from dbo.Trasy t, dbo.Zlecenia z, dbo.Kontrahenci ko, dbo.Kierowcy k, dbo.Samochody l, dbo.Statusy st " +
					"where t.idZlecenia =  and z.idKontrahenta = ko.id and z.idLadunku = l.id and z.status = s.id; ";
				*/

				String^ sqlString = "select t.id, z.nrZlecenia as 'Nr zlecenia', z.data_zamowienia as 'Data zamówienia',ko.Nazwa, z.Opis,concat(k.imie,' ',k.nazwisko) as Kierowca, concat(s.Marka,' ',s.Model,' -- ',s.Nr_rejestracyjny) as Samochod, t.Kilometry, t.koszt_paliwa as 'Koszt paliwa', t.data_wykonania as 'Data wykonania', st.status  " +
					"from dbo.Trasy t " +
					"join dbo.Zlecenia z on t.idZlecenia = z.id " +
					"join dbo.Statusy st on t.status = st.id " +
					"join dbo.Kontrahenci ko on z.idKontrahenta = ko.ID " +
					"left join dbo.Samochody s on t.idSamochodu = s.id " +
					"left join dbo.Kierowcy k on t.idKierowcy = k.ID ";
					
				SqlCommand^ sqlCommand = gcnew SqlCommand(sqlString, sqlConnection);

				SqlDataAdapter^ sqlDataAdapter = gcnew SqlDataAdapter();
				sqlDataAdapter->SelectCommand = sqlCommand;
				DataTable^ dataTable = gcnew DataTable();
				sqlDataAdapter->Fill(dataTable);
				BindingSource^ bindingSource = gcnew BindingSource();

				//bindingSource->DataSource = dataTable;
				//PracownicyDataGridView->DataSource = bindingSource;


				dataGridViewTrasy->DataSource = dataTable;
				sqlDataAdapter->Update(dataTable);

				//chowa kolumn� ID w dataGridView
				this->dataGridViewTrasy->Columns["ID"]->Visible = false;
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}



			//https://www.youtube.com/watch?v=r_cj1uhs9-c
		};

#pragma endregion
	private: System::Void btnDodaj_Click(System::Object^ sender, System::EventArgs^ e) {
		
		EdytujTraseForm^ EditForm = gcnew EdytujTraseForm(0, 0, connectionString);
		EditForm->ShowDialog();
		this->generateView();
	}
private: System::Void btnEdytuj_Click(System::Object^ sender, System::EventArgs^ e) {
	int idTrasy = 0;
	idTrasy = (int)dataGridViewTrasy->CurrentRow->Cells[0]->Value;

	EdytujTraseForm^ EditForm = gcnew EdytujTraseForm(idTrasy, 0, connectionString);
	EditForm->ShowDialog();
	this->generateView();
}
private: System::Void btnUsun_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("Usunąć trasę?", "Usuwanie trasy", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {

		int idTrasy = (int)dataGridViewTrasy->CurrentRow->Cells[0]->Value;
		if (idTrasy) {
			try {

				SqlConnection^ sqlConnection = gcnew SqlConnection(connectionString);
				sqlConnection->Open();

				SqlCommand^ sqlCommand = gcnew SqlCommand("delete from dbo.Trasy where id = @id", sqlConnection);
				sqlCommand->Parameters->Add("@id", idTrasy);
				sqlCommand->ExecuteNonQuery();

				sqlConnection->Close();
			}
			catch (Exception^ e) {
				MessageBox::Show(e->ToString());
			}

			this->generateView();
		}
	}
}
};
}
