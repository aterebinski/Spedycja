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
	/// Summary for ZestawienieZlecenForm
	/// </summary>
	public ref class ZestawienieZlecenForm : public System::Windows::Forms::Form
	{
	private:
		String^ connectionString;
	public:
		ZestawienieZlecenForm(String^ connectionString)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//

			this->connectionString = connectionString;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ZestawienieZlecenForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label3;
	protected:
	private: System::Windows::Forms::Button^  btnSzukaj;
	private: System::Windows::Forms::DataGridView^  dataGridZestawienie;
	private: System::Windows::Forms::DateTimePicker^  dateTimeDataDo;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::DateTimePicker^  dateTimeDataOd;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  labelEditKontrahent;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnSzukaj = (gcnew System::Windows::Forms::Button());
			this->dataGridZestawienie = (gcnew System::Windows::Forms::DataGridView());
			this->dateTimeDataDo = (gcnew System::Windows::Forms::DateTimePicker());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dateTimeDataOd = (gcnew System::Windows::Forms::DateTimePicker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->labelEditKontrahent = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridZestawienie))->BeginInit();
			this->SuspendLayout();
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(587, 106);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(317, 25);
			this->label3->TabIndex = 112;
			this->label3->Text = L"Zlecenia - przychody, koszty i zyski";
			// 
			// btnSzukaj
			// 
			this->btnSzukaj->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnSzukaj->Location = System::Drawing::Point(998, 175);
			this->btnSzukaj->Margin = System::Windows::Forms::Padding(4);
			this->btnSzukaj->Name = L"btnSzukaj";
			this->btnSzukaj->Size = System::Drawing::Size(116, 42);
			this->btnSzukaj->TabIndex = 111;
			this->btnSzukaj->Text = L"Szukaj";
			this->btnSzukaj->UseVisualStyleBackColor = true;
			this->btnSzukaj->Click += gcnew System::EventHandler(this, &ZestawienieZlecenForm::btnSzukaj_Click);
			// 
			// dataGridZestawienie
			// 
			this->dataGridZestawienie->AllowUserToAddRows = false;
			this->dataGridZestawienie->AllowUserToDeleteRows = false;
			this->dataGridZestawienie->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridZestawienie->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridZestawienie->Location = System::Drawing::Point(49, 241);
			this->dataGridZestawienie->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dataGridZestawienie->Name = L"dataGridZestawienie";
			this->dataGridZestawienie->ReadOnly = true;
			this->dataGridZestawienie->RowHeadersVisible = false;
			this->dataGridZestawienie->RowHeadersWidth = 51;
			this->dataGridZestawienie->RowTemplate->Height = 24;
			this->dataGridZestawienie->Size = System::Drawing::Size(1407, 454);
			this->dataGridZestawienie->TabIndex = 110;
			// 
			// dateTimeDataDo
			// 
			this->dateTimeDataDo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->dateTimeDataDo->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimeDataDo->Location = System::Drawing::Point(766, 182);
			this->dateTimeDataDo->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dateTimeDataDo->Name = L"dateTimeDataDo";
			this->dateTimeDataDo->Size = System::Drawing::Size(200, 30);
			this->dateTimeDataDo->TabIndex = 108;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(718, 182);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(40, 25);
			this->label2->TabIndex = 109;
			this->label2->Text = L"do:";
			// 
			// dateTimeDataOd
			// 
			this->dateTimeDataOd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->dateTimeDataOd->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimeDataOd->Location = System::Drawing::Point(512, 180);
			this->dateTimeDataOd->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dateTimeDataOd->Name = L"dateTimeDataOd";
			this->dateTimeDataOd->Size = System::Drawing::Size(200, 30);
			this->dateTimeDataOd->TabIndex = 106;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(406, 182);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(98, 25);
			this->label1->TabIndex = 107;
			this->label1->Text = L"Okres od:";
			// 
			// labelEditKontrahent
			// 
			this->labelEditKontrahent->AutoSize = true;
			this->labelEditKontrahent->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelEditKontrahent->Location = System::Drawing::Point(605, 42);
			this->labelEditKontrahent->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelEditKontrahent->Name = L"labelEditKontrahent";
			this->labelEditKontrahent->Size = System::Drawing::Size(285, 36);
			this->labelEditKontrahent->TabIndex = 105;
			this->labelEditKontrahent->Text = L"Zestawienie zleceñ";
			// 
			// ZestawienieZlecenForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1530, 734);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->btnSzukaj);
			this->Controls->Add(this->dataGridZestawienie);
			this->Controls->Add(this->dateTimeDataDo);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dateTimeDataOd);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->labelEditKontrahent);
			this->Name = L"ZestawienieZlecenForm";
			this->Text = L"ZestawienieZlecenForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridZestawienie))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnSzukaj_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ dataOd = this->dateTimeDataOd->Text;
		String^ dataDo = this->dateTimeDataDo->Text;

		try
		{
			SqlConnection^ sqlConnection = gcnew SqlConnection(connectionString);
			String^ sqlString = "select z.nrZlecenia, ko.Nazwa as Kontrahent, l.nazwa as £adunek, z.Skad as Sk¹d, z.Dokad as Dok¹d, z.Opis, " +
				"sum(t.kilometry) as 'Przejechane km',sum(t.koszt_paliwa) as 'Koszty Paliwa', sum(z.naleznosc) as Przychód, sum(z.naleznosc) - sum(t.koszt_paliwa) as Zysk " +
				"from dbo.Zlecenia z, dbo.Trasy t, dbo.Kontrahenci ko, dbo.Ladunki l " +
				"where t.idZlecenia = z.ID " +
				"and z.idKontrahenta = ko.id " +
				"and z.idLadunku = l.id " +
				"and t.data_wykonania >= @dataOd " +
				"and t.data_wykonania <= @dataDo " +
				"and t.status = 4 " +
				"and z.status = 4 " +
				"group by z.nrZlecenia, ko.Nazwa, l.nazwa, z.Skad, z.Dokad, z.Opis; ";
			SqlCommand^ sqlCommand = gcnew SqlCommand(sqlString, sqlConnection);
			sqlCommand->Parameters->Add("@dataOd", dataOd);
			sqlCommand->Parameters->Add("@dataDo", dataDo);

			SqlDataAdapter^ sqlDataAdapter = gcnew SqlDataAdapter();
			sqlDataAdapter->SelectCommand = sqlCommand;
			DataTable^ dataTable = gcnew DataTable();
			sqlDataAdapter->Fill(dataTable);
			BindingSource^ bindingSource = gcnew BindingSource();

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
