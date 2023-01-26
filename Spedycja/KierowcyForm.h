#pragma once
#include "EdytujKierowceForm.h"
#include "ZestawienieKierowcowForm.h"

namespace Spedycja {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::SqlClient;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o KierowcyForm
	/// </summary>
	public ref class KierowcyForm : public System::Windows::Forms::Form
	{
	private:
		String^ connectionString;
	public:
		KierowcyForm(String^ connectionString)
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
		~KierowcyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labelKierowcy;
	protected:
	private: System::Windows::Forms::Button^ btnUsun;
	private: System::Windows::Forms::Button^ btnEdytuj;
	private: System::Windows::Forms::Button^ btnDodaj;
	private: System::Windows::Forms::DataGridView^ dataGridViewKierowcy;
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
			this->labelKierowcy = (gcnew System::Windows::Forms::Label());
			this->btnUsun = (gcnew System::Windows::Forms::Button());
			this->btnEdytuj = (gcnew System::Windows::Forms::Button());
			this->btnDodaj = (gcnew System::Windows::Forms::Button());
			this->dataGridViewKierowcy = (gcnew System::Windows::Forms::DataGridView());
			this->btnZestawienie = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewKierowcy))->BeginInit();
			this->SuspendLayout();
			// 
			// labelKierowcy
			// 
			this->labelKierowcy->AutoSize = true;
			this->labelKierowcy->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelKierowcy->Location = System::Drawing::Point(65, 54);
			this->labelKierowcy->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelKierowcy->Name = L"labelKierowcy";
			this->labelKierowcy->Size = System::Drawing::Size(112, 29);
			this->labelKierowcy->TabIndex = 7;
			this->labelKierowcy->Text = L"Kierowcy";
			// 
			// btnUsun
			// 
			this->btnUsun->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnUsun->Location = System::Drawing::Point(384, 453);
			this->btnUsun->Margin = System::Windows::Forms::Padding(4);
			this->btnUsun->Name = L"btnUsun";
			this->btnUsun->Size = System::Drawing::Size(116, 42);
			this->btnUsun->TabIndex = 4;
			this->btnUsun->Text = L"Usuń";
			this->btnUsun->UseVisualStyleBackColor = true;
			this->btnUsun->Click += gcnew System::EventHandler(this, &KierowcyForm::btnUsun_Click);
			// 
			// btnEdytuj
			// 
			this->btnEdytuj->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnEdytuj->Location = System::Drawing::Point(231, 453);
			this->btnEdytuj->Margin = System::Windows::Forms::Padding(4);
			this->btnEdytuj->Name = L"btnEdytuj";
			this->btnEdytuj->Size = System::Drawing::Size(116, 42);
			this->btnEdytuj->TabIndex = 5;
			this->btnEdytuj->Text = L"Popraw";
			this->btnEdytuj->UseVisualStyleBackColor = true;
			this->btnEdytuj->Click += gcnew System::EventHandler(this, &KierowcyForm::btnEdytuj_Click);
			// 
			// btnDodaj
			// 
			this->btnDodaj->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnDodaj->Location = System::Drawing::Point(65, 453);
			this->btnDodaj->Margin = System::Windows::Forms::Padding(4);
			this->btnDodaj->Name = L"btnDodaj";
			this->btnDodaj->Size = System::Drawing::Size(116, 42);
			this->btnDodaj->TabIndex = 6;
			this->btnDodaj->Text = L"Dodaj";
			this->btnDodaj->UseVisualStyleBackColor = true;
			this->btnDodaj->Click += gcnew System::EventHandler(this, &KierowcyForm::btnDodaj_Click);
			// 
			// dataGridViewKierowcy
			// 
			this->dataGridViewKierowcy->AllowUserToAddRows = false;
			this->dataGridViewKierowcy->AllowUserToDeleteRows = false;
			this->dataGridViewKierowcy->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridViewKierowcy->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewKierowcy->Location = System::Drawing::Point(65, 119);
			this->dataGridViewKierowcy->Margin = System::Windows::Forms::Padding(4);
			this->dataGridViewKierowcy->Name = L"dataGridViewKierowcy";
			this->dataGridViewKierowcy->ReadOnly = true;
			this->dataGridViewKierowcy->RowHeadersVisible = false;
			this->dataGridViewKierowcy->Size = System::Drawing::Size(953, 281);
			this->dataGridViewKierowcy->TabIndex = 3;
			// 
			// btnZestawienie
			// 
			this->btnZestawienie->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnZestawienie->Location = System::Drawing::Point(829, 453);
			this->btnZestawienie->Margin = System::Windows::Forms::Padding(4);
			this->btnZestawienie->Name = L"btnZestawienie";
			this->btnZestawienie->Size = System::Drawing::Size(189, 42);
			this->btnZestawienie->TabIndex = 8;
			this->btnZestawienie->Text = L"Zestawienie";
			this->btnZestawienie->UseVisualStyleBackColor = true;
			this->btnZestawienie->Click += gcnew System::EventHandler(this, &KierowcyForm::btnZestawienie_Click);
			// 
			// KierowcyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1092, 560);
			this->Controls->Add(this->btnZestawienie);
			this->Controls->Add(this->labelKierowcy);
			this->Controls->Add(this->btnUsun);
			this->Controls->Add(this->btnEdytuj);
			this->Controls->Add(this->btnDodaj);
			this->Controls->Add(this->dataGridViewKierowcy);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"KierowcyForm";
			this->Text = L"KierowcyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewKierowcy))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		System::Void generateView() {



			//SqlDataReader^ sqlDataReader;
			try
			{
				SqlConnection^ sqlConnection = gcnew SqlConnection(connectionString);
				String^ sqlString = "select * from dbo.Kierowcy k; ";
				SqlCommand^ sqlCommand = gcnew SqlCommand(sqlString, sqlConnection);

				SqlDataAdapter^ sqlDataAdapter = gcnew SqlDataAdapter();
				sqlDataAdapter->SelectCommand = sqlCommand;
				DataTable^ dataTable = gcnew DataTable();
				sqlDataAdapter->Fill(dataTable);
				BindingSource^ bindingSource = gcnew BindingSource();

				//bindingSource->DataSource = dataTable;
				//PracownicyDataGridView->DataSource = bindingSource;


				dataGridViewKierowcy->DataSource = dataTable;
				sqlDataAdapter->Update(dataTable);

				//chowa kolumn� ID w dataGridView
				this->dataGridViewKierowcy->Columns["ID"]->Visible = false;
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}



			//https://www.youtube.com/watch?v=r_cj1uhs9-c
		};
#pragma endregion
	private: System::Void btnDodaj_Click(System::Object^ sender, System::EventArgs^ e) {
		EdytujKierowceForm^ EditForm = gcnew EdytujKierowceForm(0, connectionString);
		EditForm->ShowDialog();
		this->generateView();
	}
private: System::Void btnEdytuj_Click(System::Object^ sender, System::EventArgs^ e) {
	int idKierowcy = 0;
	idKierowcy = (int)dataGridViewKierowcy->CurrentRow->Cells[0]->Value;

	EdytujKierowceForm^ EditForm = gcnew EdytujKierowceForm(idKierowcy, connectionString);
	EditForm->ShowDialog();
	this->generateView();
}
private: System::Void btnUsun_Click(System::Object^  sender, System::EventArgs^  e) {
	if (MessageBox::Show("Usunąć kierowcę?", "Usuwanie kierowcy", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {

		int idKierowcy = (int)dataGridViewKierowcy->CurrentRow->Cells[0]->Value;
		if (idKierowcy) {
			try {

				SqlConnection^ sqlConnection = gcnew SqlConnection(connectionString);
				sqlConnection->Open();
				SqlCommand^ sqlCommand = gcnew SqlCommand("select count(*) as liczba from dbo.Trasy where idKierowcy = " + idKierowcy, sqlConnection);
				SqlDataReader^ sqlDataReader = sqlCommand->ExecuteReader();
				sqlDataReader->Read();
				int liczba = (int)sqlDataReader["liczba"];
				sqlDataReader->Close();
				if (liczba > 0) { //jeśli istnieją jakieś trasy dla kierowcy
					MessageBox::Show("Nie można usunąć kierowcy który wykonał już zlecenie.");
				}
				else {
					sqlCommand = gcnew SqlCommand("delete from dbo.Kierowcy where id = @id", sqlConnection);
					sqlCommand->Parameters->Add("@id", idKierowcy);
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
	ZestawienieKierowcowForm^ zestawienieKierowcowForm = gcnew ZestawienieKierowcowForm(connectionString);
	zestawienieKierowcowForm->ShowDialog();
}
};
}
