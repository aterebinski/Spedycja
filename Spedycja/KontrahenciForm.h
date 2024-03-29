﻿#pragma once
#include "EdytujKontrahentaForm.h"
#include "ZestawienieKontrahentowForm.h"

namespace Spedycja {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::SqlClient;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o ListKontrahenciForm
	/// </summary>
	public ref class KontrahenciForm : public System::Windows::Forms::Form
	{
	private:
		String^ connectionString;

	public:
		KontrahenciForm(String^ connectionString)
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
		~KontrahenciForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridViewKontrahenci;
	protected:

	private: System::Windows::Forms::Button^ btnDodajKontrahenta;
	protected:

	private: System::Windows::Forms::Label^ labelKontrahenci;
	private: System::Windows::Forms::Button^ btnEdytujKontrahenta;
	private: System::Windows::Forms::Button^ btnUsunKontrahenta;
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
			this->dataGridViewKontrahenci = (gcnew System::Windows::Forms::DataGridView());
			this->btnDodajKontrahenta = (gcnew System::Windows::Forms::Button());
			this->labelKontrahenci = (gcnew System::Windows::Forms::Label());
			this->btnEdytujKontrahenta = (gcnew System::Windows::Forms::Button());
			this->btnUsunKontrahenta = (gcnew System::Windows::Forms::Button());
			this->btnZestawienie = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewKontrahenci))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridViewKontrahenci
			// 
			this->dataGridViewKontrahenci->AllowUserToAddRows = false;
			this->dataGridViewKontrahenci->AllowUserToDeleteRows = false;
			this->dataGridViewKontrahenci->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridViewKontrahenci->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewKontrahenci->Location = System::Drawing::Point(79, 103);
			this->dataGridViewKontrahenci->Margin = System::Windows::Forms::Padding(4);
			this->dataGridViewKontrahenci->Name = L"dataGridViewKontrahenci";
			this->dataGridViewKontrahenci->ReadOnly = true;
			this->dataGridViewKontrahenci->RowHeadersVisible = false;
			this->dataGridViewKontrahenci->Size = System::Drawing::Size(1140, 281);
			this->dataGridViewKontrahenci->TabIndex = 0;
			// 
			// btnDodajKontrahenta
			// 
			this->btnDodajKontrahenta->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->btnDodajKontrahenta->Location = System::Drawing::Point(79, 437);
			this->btnDodajKontrahenta->Margin = System::Windows::Forms::Padding(4);
			this->btnDodajKontrahenta->Name = L"btnDodajKontrahenta";
			this->btnDodajKontrahenta->Size = System::Drawing::Size(116, 42);
			this->btnDodajKontrahenta->TabIndex = 1;
			this->btnDodajKontrahenta->Text = L"Dodaj";
			this->btnDodajKontrahenta->UseVisualStyleBackColor = true;
			this->btnDodajKontrahenta->Click += gcnew System::EventHandler(this, &KontrahenciForm::btnDodajKontrahenta_Click);
			// 
			// labelKontrahenci
			// 
			this->labelKontrahenci->AutoSize = true;
			this->labelKontrahenci->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelKontrahenci->Location = System::Drawing::Point(79, 38);
			this->labelKontrahenci->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelKontrahenci->Name = L"labelKontrahenci";
			this->labelKontrahenci->Size = System::Drawing::Size(141, 29);
			this->labelKontrahenci->TabIndex = 2;
			this->labelKontrahenci->Text = L"Kontrahenci";
			// 
			// btnEdytujKontrahenta
			// 
			this->btnEdytujKontrahenta->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->btnEdytujKontrahenta->Location = System::Drawing::Point(244, 437);
			this->btnEdytujKontrahenta->Margin = System::Windows::Forms::Padding(4);
			this->btnEdytujKontrahenta->Name = L"btnEdytujKontrahenta";
			this->btnEdytujKontrahenta->Size = System::Drawing::Size(116, 42);
			this->btnEdytujKontrahenta->TabIndex = 1;
			this->btnEdytujKontrahenta->Text = L"Popraw";
			this->btnEdytujKontrahenta->UseVisualStyleBackColor = true;
			this->btnEdytujKontrahenta->Click += gcnew System::EventHandler(this, &KontrahenciForm::btnEdytujKontrahenta_Click);
			// 
			// btnUsunKontrahenta
			// 
			this->btnUsunKontrahenta->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnUsunKontrahenta->Location = System::Drawing::Point(397, 437);
			this->btnUsunKontrahenta->Margin = System::Windows::Forms::Padding(4);
			this->btnUsunKontrahenta->Name = L"btnUsunKontrahenta";
			this->btnUsunKontrahenta->Size = System::Drawing::Size(116, 42);
			this->btnUsunKontrahenta->TabIndex = 1;
			this->btnUsunKontrahenta->Text = L"Usuń";
			this->btnUsunKontrahenta->UseVisualStyleBackColor = true;
			this->btnUsunKontrahenta->Click += gcnew System::EventHandler(this, &KontrahenciForm::btnUsunKontrahenta_Click);
			// 
			// btnZestawienie
			// 
			this->btnZestawienie->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnZestawienie->Location = System::Drawing::Point(975, 437);
			this->btnZestawienie->Margin = System::Windows::Forms::Padding(4);
			this->btnZestawienie->Name = L"btnZestawienie";
			this->btnZestawienie->Size = System::Drawing::Size(244, 42);
			this->btnZestawienie->TabIndex = 3;
			this->btnZestawienie->Text = L"Zestawienie";
			this->btnZestawienie->UseVisualStyleBackColor = true;
			this->btnZestawienie->Click += gcnew System::EventHandler(this, &KontrahenciForm::btnZestawienie_Click);
			// 
			// KontrahenciForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1301, 516);
			this->Controls->Add(this->btnZestawienie);
			this->Controls->Add(this->labelKontrahenci);
			this->Controls->Add(this->btnUsunKontrahenta);
			this->Controls->Add(this->btnEdytujKontrahenta);
			this->Controls->Add(this->btnDodajKontrahenta);
			this->Controls->Add(this->dataGridViewKontrahenci);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"KontrahenciForm";
			this->Text = L"Kontrahenci";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewKontrahenci))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		System::Void generateView() {



			//SqlDataReader^ sqlDataReader;
			try
			{
				SqlConnection^ sqlConnection = gcnew SqlConnection(connectionString);
				String^ sqlString = "select * from dbo.Kontrahenci k; ";
				SqlCommand^ sqlCommand = gcnew SqlCommand(sqlString, sqlConnection);

				SqlDataAdapter^ sqlDataAdapter = gcnew SqlDataAdapter();
				sqlDataAdapter->SelectCommand = sqlCommand;
				DataTable^ dataTable = gcnew DataTable();
				sqlDataAdapter->Fill(dataTable);
				BindingSource^ bindingSource = gcnew BindingSource();

				//bindingSource->DataSource = dataTable;
				//PracownicyDataGridView->DataSource = bindingSource;


				dataGridViewKontrahenci->DataSource = dataTable;
				sqlDataAdapter->Update(dataTable);

				//chowa kolumn� ID w dataGridView
				this->dataGridViewKontrahenci->Columns["ID"]->Visible = false;
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}



			//https://www.youtube.com/watch?v=r_cj1uhs9-c
		};

#pragma endregion
	private: System::Void btnEdytujKontrahenta_Click(System::Object^ sender, System::EventArgs^ e) {
		int idKontrahenta = 0;
		idKontrahenta = (int)dataGridViewKontrahenci->CurrentRow->Cells[0]->Value;

		EdytujKontrahentaForm^ EditForm = gcnew EdytujKontrahentaForm(idKontrahenta, connectionString);
		EditForm->ShowDialog();
		this->generateView();
	}
private: System::Void btnDodajKontrahenta_Click(System::Object^ sender, System::EventArgs^ e) {
	EdytujKontrahentaForm^ EditForm = gcnew EdytujKontrahentaForm(0, connectionString);
	EditForm->ShowDialog();
	this->generateView();
}
private: System::Void btnUsunKontrahenta_Click(System::Object^ sender, System::EventArgs^ e) {

	if (MessageBox::Show("Usunąć kontrahenta?", "Usuwanie kontrahenta", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {

		int idKontrahenta = (int)dataGridViewKontrahenci->CurrentRow->Cells[0]->Value;
		if (idKontrahenta) {
			try {

				SqlConnection^ sqlConnection = gcnew SqlConnection(connectionString);
				sqlConnection->Open();
				SqlCommand^ sqlCommand = gcnew SqlCommand("select count(*) as liczba from dbo.Zlecenia where idKontrahenta = " + idKontrahenta, sqlConnection);
				SqlDataReader^ sqlDataReader = sqlCommand->ExecuteReader();
				sqlDataReader->Read();
				int liczba = (int)sqlDataReader["liczba"];
				sqlDataReader->Close();
				if (liczba > 0) { //jeśli istnieją jakieś zlecdenia dla danego kontrahenta
					MessageBox::Show("Nie można usunąć kontrahenta który złożył już zlecenie.");
				}
				else {
					sqlCommand = gcnew SqlCommand("delete from dbo.Kontrahenci where id = @id", sqlConnection);
					sqlCommand->Parameters->Add("@id", idKontrahenta);
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
	ZestawienieKontrahentowForm^ zestawienieKontrahentowForm = gcnew ZestawienieKontrahentowForm(connectionString);
	zestawienieKontrahentowForm->ShowDialog();
}
};
}
