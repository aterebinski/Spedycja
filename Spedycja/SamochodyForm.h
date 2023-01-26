#pragma once
#include "EdytujSamochodForm.h"
#include "ZestawienieSamochodowForm.h"

namespace Spedycja {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::SqlClient;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o SamochodyForm
	/// </summary>
	public ref class SamochodyForm : public System::Windows::Forms::Form
	{
	private:
		String^ connectionString;
	public:
		SamochodyForm(String^ connectionString)
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
		~SamochodyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labelSamochody;
	protected:
	private: System::Windows::Forms::Button^ btnUsun;
	private: System::Windows::Forms::Button^ btnEdytuj;
	private: System::Windows::Forms::Button^ btnDodaj;
	private: System::Windows::Forms::DataGridView^ dataGridViewSamochody;
	private: System::Windows::Forms::Button^  btnZestawienie;

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
			this->labelSamochody = (gcnew System::Windows::Forms::Label());
			this->btnUsun = (gcnew System::Windows::Forms::Button());
			this->btnEdytuj = (gcnew System::Windows::Forms::Button());
			this->btnDodaj = (gcnew System::Windows::Forms::Button());
			this->dataGridViewSamochody = (gcnew System::Windows::Forms::DataGridView());
			this->btnZestawienie = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewSamochody))->BeginInit();
			this->SuspendLayout();
			// 
			// labelSamochody
			// 
			this->labelSamochody->AutoSize = true;
			this->labelSamochody->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelSamochody->Location = System::Drawing::Point(53, 81);
			this->labelSamochody->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelSamochody->Name = L"labelSamochody";
			this->labelSamochody->Size = System::Drawing::Size(140, 29);
			this->labelSamochody->TabIndex = 12;
			this->labelSamochody->Text = L"Samochody";
			// 
			// btnUsun
			// 
			this->btnUsun->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnUsun->Location = System::Drawing::Point(392, 489);
			this->btnUsun->Margin = System::Windows::Forms::Padding(4);
			this->btnUsun->Name = L"btnUsun";
			this->btnUsun->Size = System::Drawing::Size(116, 42);
			this->btnUsun->TabIndex = 9;
			this->btnUsun->Text = L"Usuń";
			this->btnUsun->UseVisualStyleBackColor = true;
			this->btnUsun->Click += gcnew System::EventHandler(this, &SamochodyForm::btnUsun_Click);
			// 
			// btnEdytuj
			// 
			this->btnEdytuj->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnEdytuj->Location = System::Drawing::Point(239, 489);
			this->btnEdytuj->Margin = System::Windows::Forms::Padding(4);
			this->btnEdytuj->Name = L"btnEdytuj";
			this->btnEdytuj->Size = System::Drawing::Size(116, 42);
			this->btnEdytuj->TabIndex = 10;
			this->btnEdytuj->Text = L"Popraw";
			this->btnEdytuj->UseVisualStyleBackColor = true;
			this->btnEdytuj->Click += gcnew System::EventHandler(this, &SamochodyForm::btnEdytuj_Click);
			// 
			// btnDodaj
			// 
			this->btnDodaj->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnDodaj->Location = System::Drawing::Point(73, 489);
			this->btnDodaj->Margin = System::Windows::Forms::Padding(4);
			this->btnDodaj->Name = L"btnDodaj";
			this->btnDodaj->Size = System::Drawing::Size(116, 42);
			this->btnDodaj->TabIndex = 11;
			this->btnDodaj->Text = L"Dodaj";
			this->btnDodaj->UseVisualStyleBackColor = true;
			this->btnDodaj->Click += gcnew System::EventHandler(this, &SamochodyForm::btnDodaj_Click);
			// 
			// dataGridViewSamochody
			// 
			this->dataGridViewSamochody->AllowUserToAddRows = false;
			this->dataGridViewSamochody->AllowUserToDeleteRows = false;
			this->dataGridViewSamochody->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridViewSamochody->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewSamochody->Location = System::Drawing::Point(41, 153);
			this->dataGridViewSamochody->Margin = System::Windows::Forms::Padding(4);
			this->dataGridViewSamochody->Name = L"dataGridViewSamochody";
			this->dataGridViewSamochody->ReadOnly = true;
			this->dataGridViewSamochody->RowHeadersVisible = false;
			this->dataGridViewSamochody->Size = System::Drawing::Size(1481, 281);
			this->dataGridViewSamochody->TabIndex = 8;
			// 
			// btnZestawienie
			// 
			this->btnZestawienie->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnZestawienie->Location = System::Drawing::Point(1278, 489);
			this->btnZestawienie->Margin = System::Windows::Forms::Padding(4);
			this->btnZestawienie->Name = L"btnZestawienie";
			this->btnZestawienie->Size = System::Drawing::Size(244, 42);
			this->btnZestawienie->TabIndex = 13;
			this->btnZestawienie->Text = L"Zestawienie";
			this->btnZestawienie->UseVisualStyleBackColor = true;
			this->btnZestawienie->Click += gcnew System::EventHandler(this, &SamochodyForm::btnZestawienie_Click);
			// 
			// SamochodyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1671, 636);
			this->Controls->Add(this->btnZestawienie);
			this->Controls->Add(this->labelSamochody);
			this->Controls->Add(this->btnUsun);
			this->Controls->Add(this->btnEdytuj);
			this->Controls->Add(this->btnDodaj);
			this->Controls->Add(this->dataGridViewSamochody);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"SamochodyForm";
			this->Text = L"SamochodyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewSamochody))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		System::Void generateView() {



			//SqlDataReader^ sqlDataReader;
			try
			{
				SqlConnection^ sqlConnection = gcnew SqlConnection(connectionString);
				String^ sqlString = "select s.ID, s.Marka, s.Model, s.Nr_rejestracyjny as 'Numer rejestracyjny', l.Nazwa, s.Ladownosc, s.Przebieg,  s.Spalanie, s.Ilosc_palet as 'Ilość palet', s.Objetosc " +
					"from dbo.Samochody s, dbo.Ladunki l where s.idLadunku = l.id; ";
				SqlCommand^ sqlCommand = gcnew SqlCommand(sqlString, sqlConnection);

				SqlDataAdapter^ sqlDataAdapter = gcnew SqlDataAdapter();
				sqlDataAdapter->SelectCommand = sqlCommand;
				DataTable^ dataTable = gcnew DataTable();
				sqlDataAdapter->Fill(dataTable);
				BindingSource^ bindingSource = gcnew BindingSource();

				//bindingSource->DataSource = dataTable;
				//PracownicyDataGridView->DataSource = bindingSource;


				dataGridViewSamochody->DataSource = dataTable;
				sqlDataAdapter->Update(dataTable);

				//chowa kolumne ID w dataGridView
				this->dataGridViewSamochody->Columns["ID"]->Visible = false;
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}



			//https://www.youtube.com/watch?v=r_cj1uhs9-c
		};
#pragma endregion
	private: System::Void btnDodaj_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void btnEdytuj_Click(System::Object^ sender, System::EventArgs^ e) {
	int idSamochodu = 0;
	idSamochodu = (int)dataGridViewSamochody->CurrentRow->Cells[0]->Value;

	EdytujSamochodForm^ EditForm = gcnew EdytujSamochodForm(idSamochodu, connectionString);
	EditForm->ShowDialog();
	this->generateView();
}
private: System::Void btnUsun_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show("Usunąć samochód?", "Usuwanie samochodu", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {

		int idSamochodu = (int)dataGridViewSamochody->CurrentRow->Cells[0]->Value;
		if (idSamochodu) {
			try {

				SqlConnection^ sqlConnection = gcnew SqlConnection(connectionString);
				sqlConnection->Open();
				SqlCommand^ sqlCommand = gcnew SqlCommand("select count(*) as liczba from dbo.Trasy where idSamochodu = " + idSamochodu, sqlConnection);
				SqlDataReader^ sqlDataReader = sqlCommand->ExecuteReader();
				sqlDataReader->Read();
				int liczba = (int)sqlDataReader["liczba"];
				sqlDataReader->Close();
				if (liczba > 0) { //jeśli istnieją jakieś trasy dla samochodu
					MessageBox::Show("Nie można usunąć kierowcy który wykonał już zlecenie.");
				}
				else {
					sqlCommand = gcnew SqlCommand("delete from dbo.Samochody where id = @id", sqlConnection);
					sqlCommand->Parameters->Add("@id", idSamochodu);
					sqlCommand->ExecuteNonQuery();
				}
				sqlConnection->Close();
			}
			catch (Exception^ e) {
				MessageBox::Show(e->ToString());
			}

			this->generateView();
		}
	}
}
private: System::Void btnZestawienie_Click(System::Object^  sender, System::EventArgs^  e) {
	ZestawienieSamochodowForm^ zestawienieSamochodowForm = gcnew ZestawienieSamochodowForm(connectionString);
	zestawienieSamochodowForm->ShowDialog();
}
};
}
