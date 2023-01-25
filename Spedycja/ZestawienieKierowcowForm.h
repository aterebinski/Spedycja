﻿#pragma once

namespace Spedycja {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::SqlClient;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o ZesatwienieKierowcówForm
	/// </summary>
	public ref class ZestawienieKierowcowForm : public System::Windows::Forms::Form
	{
	private:
		String^ connectionString;
	public:
		ZestawienieKierowcowForm(String^ connectionString)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//

			this->connectionString = connectionString;
		}

	protected:
		/// <summary>
		/// Wyczyść wszystkie używane zasoby.
		/// </summary>
		~ZestawienieKierowcowForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labelEditKontrahent;
	private: System::Windows::Forms::DateTimePicker^ dateTimeDataOd;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DateTimePicker^ dateTimeDataDo;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DataGridView^ dataGridZestawienie;

	private: System::Windows::Forms::Button^ btnSzukaj;
	protected:


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
			this->labelEditKontrahent = (gcnew System::Windows::Forms::Label());
			this->dateTimeDataOd = (gcnew System::Windows::Forms::DateTimePicker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dateTimeDataDo = (gcnew System::Windows::Forms::DateTimePicker());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridZestawienie = (gcnew System::Windows::Forms::DataGridView());
			this->btnSzukaj = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridZestawienie))->BeginInit();
			this->SuspendLayout();
			// 
			// labelEditKontrahent
			// 
			this->labelEditKontrahent->AutoSize = true;
			this->labelEditKontrahent->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->labelEditKontrahent->Location = System::Drawing::Point(306, 58);
			this->labelEditKontrahent->Name = L"labelEditKontrahent";
			this->labelEditKontrahent->Size = System::Drawing::Size(265, 29);
			this->labelEditKontrahent->TabIndex = 97;
			this->labelEditKontrahent->Text = L"Zestawienie kierowców";
			// 
			// dateTimeDataOd
			// 
			this->dateTimeDataOd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->dateTimeDataOd->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimeDataOd->Location = System::Drawing::Point(227, 123);
			this->dateTimeDataOd->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->dateTimeDataOd->Name = L"dateTimeDataOd";
			this->dateTimeDataOd->Size = System::Drawing::Size(151, 26);
			this->dateTimeDataOd->TabIndex = 98;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(148, 124);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 20);
			this->label1->TabIndex = 99;
			this->label1->Text = L"Okres od:";
			// 
			// dateTimeDataDo
			// 
			this->dateTimeDataDo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->dateTimeDataDo->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimeDataDo->Location = System::Drawing::Point(418, 124);
			this->dateTimeDataDo->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->dateTimeDataDo->Name = L"dateTimeDataDo";
			this->dateTimeDataDo->Size = System::Drawing::Size(151, 26);
			this->dateTimeDataDo->TabIndex = 100;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(382, 124);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(31, 20);
			this->label2->TabIndex = 101;
			this->label2->Text = L"do:";
			// 
			// dataGridZestawienie
			// 
			this->dataGridZestawienie->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridZestawienie->Location = System::Drawing::Point(46, 198);
			this->dataGridZestawienie->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->dataGridZestawienie->Name = L"dataGridZestawienie";
			this->dataGridZestawienie->RowHeadersWidth = 51;
			this->dataGridZestawienie->RowTemplate->Height = 24;
			this->dataGridZestawienie->Size = System::Drawing::Size(769, 346);
			this->dataGridZestawienie->TabIndex = 102;
			this->dataGridZestawienie->AllowUserToAddRows = false;
			this->dataGridZestawienie->AllowUserToDeleteRows = false;
			this->dataGridZestawienie->ReadOnly = true;
			this->dataGridZestawienie->RowHeadersVisible = false;
			// 
			// btnSzukaj
			// 
			this->btnSzukaj->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnSzukaj->Location = System::Drawing::Point(592, 119);
			this->btnSzukaj->Name = L"btnSzukaj";
			this->btnSzukaj->Size = System::Drawing::Size(87, 34);
			this->btnSzukaj->TabIndex = 103;
			this->btnSzukaj->Text = L"Szukaj";
			this->btnSzukaj->UseVisualStyleBackColor = true;
			this->btnSzukaj->Click += gcnew System::EventHandler(this, &ZestawienieKierowcowForm::btnSzukaj_Click);
			// 
			// ZestawienieKierowcowForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(854, 622);
			this->Controls->Add(this->btnSzukaj);
			this->Controls->Add(this->dataGridZestawienie);
			this->Controls->Add(this->dateTimeDataDo);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dateTimeDataOd);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->labelEditKontrahent);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"ZestawienieKierowcowForm";
			this->Text = L"ZesatwienieKierowcówForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridZestawienie))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void btnSzukaj_Click(System::Object^ sender, System::EventArgs^ e) {

	String^ dataOd = this->dateTimeDataOd->Text;
	String^ dataDo = this->dateTimeDataDo->Text;

	try
	{
		SqlConnection^ sqlConnection = gcnew SqlConnection(connectionString);
		String^ sqlString = "select concat(k.imie,' ',k.nazwisko) as Kierowca, k.Pensja, sum(t.kilometry) as Kilometry,k.wsp_premii as 'Współczynnik premii', sum(k.wsp_premii * t.kilometry) as Premia " +
			"from dbo.Kierowcy k, dbo.Trasy t " +
			"where t.idKierowcy = k.ID " +
			"and t.data_wykonania >= @dataOd " + 
			"and t.data_wykonania <= @dataDo " +
			"group by k.imie, k.nazwisko, k.Pensja, k.wsp_premii; ";
		SqlCommand^ sqlCommand = gcnew SqlCommand(sqlString, sqlConnection);
		sqlCommand->Parameters->Add("@dataOd", dataOd);
		sqlCommand->Parameters->Add("@dataDo", dataDo);

		SqlDataAdapter^ sqlDataAdapter = gcnew SqlDataAdapter();
		sqlDataAdapter->SelectCommand = sqlCommand;
		DataTable^ dataTable = gcnew DataTable();
		sqlDataAdapter->Fill(dataTable);
		BindingSource^ bindingSource = gcnew BindingSource();

		//bindingSource->DataSource = dataTable;
		//PracownicyDataGridView->DataSource = bindingSource;


		dataGridZestawienie->DataSource = dataTable;
		sqlDataAdapter->Update(dataTable);

		//chowa kolumne ID w dataGridView
		//this->dataGridZestawienie->Columns["ID"]->Visible = false;
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message);
	}
}
};
}
