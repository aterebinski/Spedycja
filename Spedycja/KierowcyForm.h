#pragma once

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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewKierowcy))->BeginInit();
			this->SuspendLayout();
			// 
			// labelKierowcy
			// 
			this->labelKierowcy->AutoSize = true;
			this->labelKierowcy->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelKierowcy->Location = System::Drawing::Point(49, 44);
			this->labelKierowcy->Name = L"labelKierowcy";
			this->labelKierowcy->Size = System::Drawing::Size(87, 24);
			this->labelKierowcy->TabIndex = 7;
			this->labelKierowcy->Text = L"Kierowcy";
			// 
			// btnUsun
			// 
			this->btnUsun->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnUsun->Location = System::Drawing::Point(288, 368);
			this->btnUsun->Name = L"btnUsun";
			this->btnUsun->Size = System::Drawing::Size(87, 34);
			this->btnUsun->TabIndex = 4;
			this->btnUsun->Text = L"Usuń";
			this->btnUsun->UseVisualStyleBackColor = true;
			// 
			// btnEdytuj
			// 
			this->btnEdytuj->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnEdytuj->Location = System::Drawing::Point(173, 368);
			this->btnEdytuj->Name = L"btnEdytuj";
			this->btnEdytuj->Size = System::Drawing::Size(87, 34);
			this->btnEdytuj->TabIndex = 5;
			this->btnEdytuj->Text = L"Popraw";
			this->btnEdytuj->UseVisualStyleBackColor = true;
			// 
			// btnDodaj
			// 
			this->btnDodaj->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnDodaj->Location = System::Drawing::Point(49, 368);
			this->btnDodaj->Name = L"btnDodaj";
			this->btnDodaj->Size = System::Drawing::Size(87, 34);
			this->btnDodaj->TabIndex = 6;
			this->btnDodaj->Text = L"Dodaj";
			this->btnDodaj->UseVisualStyleBackColor = true;
			// 
			// dataGridViewKierowcy
			// 
			this->dataGridViewKierowcy->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewKierowcy->Location = System::Drawing::Point(49, 97);
			this->dataGridViewKierowcy->Name = L"dataGridViewKierowcy";
			this->dataGridViewKierowcy->Size = System::Drawing::Size(715, 228);
			this->dataGridViewKierowcy->TabIndex = 3;
			this->dataGridViewKierowcy->ReadOnly = true;
			this->dataGridViewKierowcy->RowHeadersVisible = false;
			this->dataGridViewKierowcy->AllowUserToAddRows = false;
			this->dataGridViewKierowcy->AllowUserToDeleteRows = false;
			// 
			// KierowcyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(819, 455);
			this->Controls->Add(this->labelKierowcy);
			this->Controls->Add(this->btnUsun);
			this->Controls->Add(this->btnEdytuj);
			this->Controls->Add(this->btnDodaj);
			this->Controls->Add(this->dataGridViewKierowcy);
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
	};
}
