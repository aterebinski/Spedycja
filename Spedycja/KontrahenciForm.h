﻿#pragma once
#include <EdytujKontrahentaForm.h>

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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewKontrahenci))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridViewKontrahenci
			// 
			this->dataGridViewKontrahenci->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewKontrahenci->Location = System::Drawing::Point(59, 84);
			this->dataGridViewKontrahenci->Name = L"dataGridViewKontrahenci";
			this->dataGridViewKontrahenci->Size = System::Drawing::Size(715, 228);
			this->dataGridViewKontrahenci->TabIndex = 0;
			this->dataGridViewKontrahenci->ReadOnly = true;
			this->dataGridViewKontrahenci->RowHeadersVisible = false;
			this->dataGridViewKontrahenci->AllowUserToAddRows = false;
			this->dataGridViewKontrahenci->AllowUserToDeleteRows = false;
			// 
			// btnDodajKontrahenta
			// 
			this->btnDodajKontrahenta->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->btnDodajKontrahenta->Location = System::Drawing::Point(59, 355);
			this->btnDodajKontrahenta->Name = L"btnDodajKontrahenta";
			this->btnDodajKontrahenta->Size = System::Drawing::Size(87, 34);
			this->btnDodajKontrahenta->TabIndex = 1;
			this->btnDodajKontrahenta->Text = L"Dodaj";
			this->btnDodajKontrahenta->UseVisualStyleBackColor = true;
			// 
			// labelKontrahenci
			// 
			this->labelKontrahenci->AutoSize = true;
			this->labelKontrahenci->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelKontrahenci->Location = System::Drawing::Point(59, 31);
			this->labelKontrahenci->Name = L"labelKontrahenci";
			this->labelKontrahenci->Size = System::Drawing::Size(111, 24);
			this->labelKontrahenci->TabIndex = 2;
			this->labelKontrahenci->Text = L"Kontrahenci";
			// 
			// btnEdytujKontrahenta
			// 
			this->btnEdytujKontrahenta->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->btnEdytujKontrahenta->Location = System::Drawing::Point(183, 355);
			this->btnEdytujKontrahenta->Name = L"btnEdytujKontrahenta";
			this->btnEdytujKontrahenta->Size = System::Drawing::Size(87, 34);
			this->btnEdytujKontrahenta->TabIndex = 1;
			this->btnEdytujKontrahenta->Text = L"Popraw";
			this->btnEdytujKontrahenta->UseVisualStyleBackColor = true;
			this->btnEdytujKontrahenta->Click += gcnew System::EventHandler(this, &KontrahenciForm::btnEdytujKontrahenta_Click);
			// 
			// btnUsunKontrahenta
			// 
			this->btnUsunKontrahenta->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnUsunKontrahenta->Location = System::Drawing::Point(298, 355);
			this->btnUsunKontrahenta->Name = L"btnUsunKontrahenta";
			this->btnUsunKontrahenta->Size = System::Drawing::Size(87, 34);
			this->btnUsunKontrahenta->TabIndex = 1;
			this->btnUsunKontrahenta->Text = L"Usuń";
			this->btnUsunKontrahenta->UseVisualStyleBackColor = true;
			// 
			// ListKontrahenciForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(821, 553);
			this->Controls->Add(this->labelKontrahenci);
			this->Controls->Add(this->btnUsunKontrahenta);
			this->Controls->Add(this->btnEdytujKontrahenta);
			this->Controls->Add(this->btnDodajKontrahenta);
			this->Controls->Add(this->dataGridViewKontrahenci);
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
		//MessageBox::Show(idPracownika.ToString());
		EdytujKontrahentaForm^ EditForm = gcnew EdytujKontrahentaForm(idKontrahenta, connectionString);
		EditForm->ShowDialog();
		this->generateView();
	}
};
}
