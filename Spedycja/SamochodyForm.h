#pragma once
#include "EdytujSamochodForm.h"

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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewSamochody))->BeginInit();
			this->SuspendLayout();
			// 
			// labelSamochody
			// 
			this->labelSamochody->AutoSize = true;
			this->labelSamochody->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelSamochody->Location = System::Drawing::Point(40, 66);
			this->labelSamochody->Name = L"labelSamochody";
			this->labelSamochody->Size = System::Drawing::Size(111, 24);
			this->labelSamochody->TabIndex = 12;
			this->labelSamochody->Text = L"Samochody";
			// 
			// btnUsun
			// 
			this->btnUsun->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnUsun->Location = System::Drawing::Point(294, 397);
			this->btnUsun->Name = L"btnUsun";
			this->btnUsun->Size = System::Drawing::Size(87, 34);
			this->btnUsun->TabIndex = 9;
			this->btnUsun->Text = L"Usuń";
			this->btnUsun->UseVisualStyleBackColor = true;
			this->btnUsun->Click += gcnew System::EventHandler(this, &SamochodyForm::btnUsun_Click);
			// 
			// btnEdytuj
			// 
			this->btnEdytuj->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnEdytuj->Location = System::Drawing::Point(179, 397);
			this->btnEdytuj->Name = L"btnEdytuj";
			this->btnEdytuj->Size = System::Drawing::Size(87, 34);
			this->btnEdytuj->TabIndex = 10;
			this->btnEdytuj->Text = L"Popraw";
			this->btnEdytuj->UseVisualStyleBackColor = true;
			this->btnEdytuj->Click += gcnew System::EventHandler(this, &SamochodyForm::btnEdytuj_Click);
			// 
			// btnDodaj
			// 
			this->btnDodaj->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnDodaj->Location = System::Drawing::Point(55, 397);
			this->btnDodaj->Name = L"btnDodaj";
			this->btnDodaj->Size = System::Drawing::Size(87, 34);
			this->btnDodaj->TabIndex = 11;
			this->btnDodaj->Text = L"Dodaj";
			this->btnDodaj->UseVisualStyleBackColor = true;
			this->btnDodaj->Click += gcnew System::EventHandler(this, &SamochodyForm::btnDodaj_Click);
			// 
			// dataGridViewSamochody
			// 
			this->dataGridViewSamochody->AllowUserToAddRows = false;
			this->dataGridViewSamochody->AllowUserToDeleteRows = false;
			this->dataGridViewSamochody->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewSamochody->Location = System::Drawing::Point(31, 124);
			this->dataGridViewSamochody->Name = L"dataGridViewSamochody";
			this->dataGridViewSamochody->ReadOnly = true;
			this->dataGridViewSamochody->RowHeadersVisible = false;
			this->dataGridViewSamochody->Size = System::Drawing::Size(1111, 228);
			this->dataGridViewSamochody->TabIndex = 8;
			// 
			// SamochodyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1253, 517);
			this->Controls->Add(this->labelSamochody);
			this->Controls->Add(this->btnUsun);
			this->Controls->Add(this->btnEdytuj);
			this->Controls->Add(this->btnDodaj);
			this->Controls->Add(this->dataGridViewSamochody);
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
				String^ sqlString = "select * from dbo.Samochody s; ";
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

				//chowa kolumn� ID w dataGridView
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
}
};
}
