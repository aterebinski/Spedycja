﻿#pragma once
#include "EdytujZlecenieForm.h"
#include "ZestawienieZlecenForm.h"



namespace Spedycja {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::SqlClient;
	using namespace System::Drawing;


	/// <summary>
	/// Podsumowanie informacji o ZleceniaForm
	/// </summary>
	public ref class ZleceniaForm : public System::Windows::Forms::Form
	{
	private:
		String^ connectionString;
	public:
		ZleceniaForm(String^ connectionString)
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
		~ZleceniaForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labelZlecenia;
	protected:
	private: System::Windows::Forms::Button^ btnUsun;
	private: System::Windows::Forms::Button^ btnEdytuj;
	private: System::Windows::Forms::Button^ btnDodaj;
	private: System::Windows::Forms::DataGridView^ dataGridViewZlecenia;
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
			this->labelZlecenia = (gcnew System::Windows::Forms::Label());
			this->btnUsun = (gcnew System::Windows::Forms::Button());
			this->btnEdytuj = (gcnew System::Windows::Forms::Button());
			this->btnDodaj = (gcnew System::Windows::Forms::Button());
			this->dataGridViewZlecenia = (gcnew System::Windows::Forms::DataGridView());
			this->btnZestawienie = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewZlecenia))->BeginInit();
			this->SuspendLayout();
			// 
			// labelZlecenia
			// 
			this->labelZlecenia->AutoSize = true;
			this->labelZlecenia->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelZlecenia->Location = System::Drawing::Point(87, 60);
			this->labelZlecenia->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelZlecenia->Name = L"labelZlecenia";
			this->labelZlecenia->Size = System::Drawing::Size(111, 29);
			this->labelZlecenia->TabIndex = 17;
			this->labelZlecenia->Text = L" Zlecenia";
			// 
			// btnUsun
			// 
			this->btnUsun->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnUsun->Location = System::Drawing::Point(340, 635);
			this->btnUsun->Margin = System::Windows::Forms::Padding(4);
			this->btnUsun->Name = L"btnUsun";
			this->btnUsun->Size = System::Drawing::Size(116, 42);
			this->btnUsun->TabIndex = 14;
			this->btnUsun->Text = L"Usuń";
			this->btnUsun->UseVisualStyleBackColor = true;
			this->btnUsun->Click += gcnew System::EventHandler(this, &ZleceniaForm::btnUsun_Click);
			// 
			// btnEdytuj
			// 
			this->btnEdytuj->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnEdytuj->Location = System::Drawing::Point(216, 635);
			this->btnEdytuj->Margin = System::Windows::Forms::Padding(4);
			this->btnEdytuj->Name = L"btnEdytuj";
			this->btnEdytuj->Size = System::Drawing::Size(116, 42);
			this->btnEdytuj->TabIndex = 15;
			this->btnEdytuj->Text = L"Popraw";
			this->btnEdytuj->UseVisualStyleBackColor = true;
			this->btnEdytuj->Click += gcnew System::EventHandler(this, &ZleceniaForm::btnEdytuj_Click);
			// 
			// btnDodaj
			// 
			this->btnDodaj->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnDodaj->Location = System::Drawing::Point(92, 635);
			this->btnDodaj->Margin = System::Windows::Forms::Padding(4);
			this->btnDodaj->Name = L"btnDodaj";
			this->btnDodaj->Size = System::Drawing::Size(116, 42);
			this->btnDodaj->TabIndex = 16;
			this->btnDodaj->Text = L"Dodaj";
			this->btnDodaj->UseVisualStyleBackColor = true;
			this->btnDodaj->Click += gcnew System::EventHandler(this, &ZleceniaForm::btnDodaj_Click);
			// 
			// dataGridViewZlecenia
			// 
			this->dataGridViewZlecenia->AllowUserToAddRows = false;
			this->dataGridViewZlecenia->AllowUserToDeleteRows = false;
			this->dataGridViewZlecenia->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridViewZlecenia->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewZlecenia->Location = System::Drawing::Point(92, 125);
			this->dataGridViewZlecenia->Margin = System::Windows::Forms::Padding(4);
			this->dataGridViewZlecenia->Name = L"dataGridViewZlecenia";
			this->dataGridViewZlecenia->ReadOnly = true;
			this->dataGridViewZlecenia->RowHeadersVisible = false;
			this->dataGridViewZlecenia->Size = System::Drawing::Size(1388, 460);
			this->dataGridViewZlecenia->TabIndex = 13;
			// 
			// btnZestawienie
			// 
			this->btnZestawienie->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnZestawienie->Location = System::Drawing::Point(1236, 635);
			this->btnZestawienie->Margin = System::Windows::Forms::Padding(4);
			this->btnZestawienie->Name = L"btnZestawienie";
			this->btnZestawienie->Size = System::Drawing::Size(244, 42);
			this->btnZestawienie->TabIndex = 18;
			this->btnZestawienie->Text = L"Zestawienie";
			this->btnZestawienie->UseVisualStyleBackColor = true;
			this->btnZestawienie->Click += gcnew System::EventHandler(this, &ZleceniaForm::btnZestawienie_Click);
			// 
			// ZleceniaForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1587, 783);
			this->Controls->Add(this->btnZestawienie);
			this->Controls->Add(this->labelZlecenia);
			this->Controls->Add(this->btnUsun);
			this->Controls->Add(this->btnEdytuj);
			this->Controls->Add(this->btnDodaj);
			this->Controls->Add(this->dataGridViewZlecenia);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"ZleceniaForm";
			this->Text = L"ZleceniaForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewZlecenia))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		System::Void generateView() {



			//SqlDataReader^ sqlDataReader;
			try
			{
				SqlConnection^ sqlConnection = gcnew SqlConnection(connectionString);
				String^ sqlString = "select z.id, z.nrZlecenia as 'Numer zlecenia', k.Nazwa as Kontrahent, z.data_zamowienia as 'Data zamówienia', z.Skad, z.Dokad, l.Nazwa as Ładunek, z.Opis, z.data_realizacji as 'Data realizacji', s.status, z.naleznosc as Należność " +
					"from dbo.Zlecenia z, dbo.Kontrahenci k, dbo.Ladunki l, dbo.Statusy s " +
					"where z.idKontrahenta = k.id and z.idLadunku = l.id and z.status = s.id; ";
				SqlCommand^ sqlCommand = gcnew SqlCommand(sqlString, sqlConnection);

				SqlDataAdapter^ sqlDataAdapter = gcnew SqlDataAdapter();
				sqlDataAdapter->SelectCommand = sqlCommand;
				DataTable^ dataTable = gcnew DataTable();
				sqlDataAdapter->Fill(dataTable);
				BindingSource^ bindingSource = gcnew BindingSource();

				//bindingSource->DataSource = dataTable;
				//PracownicyDataGridView->DataSource = bindingSource;


				dataGridViewZlecenia->DataSource = dataTable;
				sqlDataAdapter->Update(dataTable);

				//chowa kolumn� ID w dataGridView
				this->dataGridViewZlecenia->Columns["ID"]->Visible = false;
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}



			//https://www.youtube.com/watch?v=r_cj1uhs9-c
		};
#pragma endregion
	private: System::Void btnDodaj_Click(System::Object^  sender, System::EventArgs^  e) {
		EdytujZlecenieForm^ EditForm = gcnew EdytujZlecenieForm(0, 0, connectionString);
		EditForm->ShowDialog();
		this->generateView();
	}
private: System::Void btnEdytuj_Click(System::Object^  sender, System::EventArgs^  e) {
	int idZlecenia = 0;
	idZlecenia = (int)dataGridViewZlecenia->CurrentRow->Cells[0]->Value;

	EdytujZlecenieForm^ EditForm = gcnew EdytujZlecenieForm(idZlecenia, 0 , connectionString);
	EditForm->ShowDialog();
	this->generateView();
}
private: System::Void btnUsun_Click(System::Object^  sender, System::EventArgs^  e) {
	if (MessageBox::Show("Usunąć zlecenie?", "Usuwanie zlecenia", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {

		int idZlecenia= (int)dataGridViewZlecenia->CurrentRow->Cells[0]->Value;
		if (idZlecenia) {
			try {

				SqlConnection^ sqlConnection = gcnew SqlConnection(connectionString);
				sqlConnection->Open();
				SqlCommand^ sqlCommand = gcnew SqlCommand("select count(*) as liczba from dbo.Trasy where idZlecenia = " + idZlecenia, sqlConnection);
				SqlDataReader^ sqlDataReader = sqlCommand->ExecuteReader();
				sqlDataReader->Read();
				int liczba = (int)sqlDataReader["liczba"];
				sqlDataReader->Close();
				if (liczba > 0) { //jeśli istnieją jakieś trasy dla samochodu
					MessageBox::Show("Nie można usunąć zlecenia dla którego wykonano trasę.");
				}
				else {
					sqlCommand = gcnew SqlCommand("delete from dbo.Zlecenia where id = @id", sqlConnection);
					sqlCommand->Parameters->Add("@id", idZlecenia);
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
	ZestawienieZlecenForm^ zestawienieZlecenForm = gcnew ZestawienieZlecenForm(connectionString);
	zestawienieZlecenForm->ShowDialog();
}
};
}
