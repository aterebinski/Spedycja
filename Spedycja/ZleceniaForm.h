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
	private: System::Windows::Forms::Button^ btnRezerwuj;
	private: System::Windows::Forms::Button^ btnWykonaj;

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
			this->btnRezerwuj = (gcnew System::Windows::Forms::Button());
			this->btnWykonaj = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewZlecenia))->BeginInit();
			this->SuspendLayout();
			// 
			// labelZlecenia
			// 
			this->labelZlecenia->AutoSize = true;
			this->labelZlecenia->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelZlecenia->Location = System::Drawing::Point(65, 49);
			this->labelZlecenia->Name = L"labelZlecenia";
			this->labelZlecenia->Size = System::Drawing::Size(88, 24);
			this->labelZlecenia->TabIndex = 17;
			this->labelZlecenia->Text = L" Zlecenia";
			// 
			// btnUsun
			// 
			this->btnUsun->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnUsun->Location = System::Drawing::Point(308, 516);
			this->btnUsun->Name = L"btnUsun";
			this->btnUsun->Size = System::Drawing::Size(87, 34);
			this->btnUsun->TabIndex = 14;
			this->btnUsun->Text = L"Usuń";
			this->btnUsun->UseVisualStyleBackColor = true;
			// 
			// btnEdytuj
			// 
			this->btnEdytuj->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnEdytuj->Location = System::Drawing::Point(193, 516);
			this->btnEdytuj->Name = L"btnEdytuj";
			this->btnEdytuj->Size = System::Drawing::Size(87, 34);
			this->btnEdytuj->TabIndex = 15;
			this->btnEdytuj->Text = L"Popraw";
			this->btnEdytuj->UseVisualStyleBackColor = true;
			// 
			// btnDodaj
			// 
			this->btnDodaj->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnDodaj->Location = System::Drawing::Point(69, 516);
			this->btnDodaj->Name = L"btnDodaj";
			this->btnDodaj->Size = System::Drawing::Size(87, 34);
			this->btnDodaj->TabIndex = 16;
			this->btnDodaj->Text = L"Dodaj";
			this->btnDodaj->UseVisualStyleBackColor = true;
			// 
			// dataGridViewZlecenia
			// 
			this->dataGridViewZlecenia->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewZlecenia->Location = System::Drawing::Point(45, 243);
			this->dataGridViewZlecenia->Name = L"dataGridViewZlecenia";
			this->dataGridViewZlecenia->Size = System::Drawing::Size(715, 228);
			this->dataGridViewZlecenia->TabIndex = 13;
			this->dataGridViewZlecenia->ReadOnly = true;
			this->dataGridViewZlecenia->RowHeadersVisible = false;
			this->dataGridViewZlecenia->AllowUserToAddRows = false;
			this->dataGridViewZlecenia->AllowUserToDeleteRows = false;
			// 
			// btnRezerwuj
			// 
			this->btnRezerwuj->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnRezerwuj->Location = System::Drawing::Point(69, 578);
			this->btnRezerwuj->Name = L"btnRezerwuj";
			this->btnRezerwuj->Size = System::Drawing::Size(241, 34);
			this->btnRezerwuj->TabIndex = 18;
			this->btnRezerwuj->Text = L"Rezerwuj kierowcę/samochód";
			this->btnRezerwuj->UseVisualStyleBackColor = true;
			// 
			// btnWykonaj
			// 
			this->btnWykonaj->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnWykonaj->Location = System::Drawing::Point(341, 578);
			this->btnWykonaj->Name = L"btnWykonaj";
			this->btnWykonaj->Size = System::Drawing::Size(87, 34);
			this->btnWykonaj->TabIndex = 19;
			this->btnWykonaj->Text = L"Usuń";
			this->btnWykonaj->UseVisualStyleBackColor = true;
			// 
			// ZleceniaForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(818, 636);
			this->Controls->Add(this->btnWykonaj);
			this->Controls->Add(this->btnRezerwuj);
			this->Controls->Add(this->labelZlecenia);
			this->Controls->Add(this->btnUsun);
			this->Controls->Add(this->btnEdytuj);
			this->Controls->Add(this->btnDodaj);
			this->Controls->Add(this->dataGridViewZlecenia);
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
				String^ sqlString = "select * from dbo.Zlecenia z; ";
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
	};
}
