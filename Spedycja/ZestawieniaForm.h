#pragma once
#include "ZestawienieKierowcowForm.h"
#include "ZestawienieKontrahentowForm.h"
#include "ZestawienieSamochodowForm.h"
#include "ZestawienieZlecenForm.h"

namespace Spedycja {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ZestawieniaForm
	/// </summary>
	public ref class ZestawieniaForm : public System::Windows::Forms::Form
	{
	private:
		String^ connectionString;
	public:
		ZestawieniaForm(String^ connectionString)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->connectionString = connectionString;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ZestawieniaForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnZestawianiaKierowcow;
	private: System::Windows::Forms::Button^ btnZestawieniaSamochodow;
	private: System::Windows::Forms::Button^ btnZestawieniaZlecen;
	protected:


	protected:



	private: System::Windows::Forms::Label^ labelEditKontrahent;
	private: System::Windows::Forms::Button^  btnZestawienieKontrahentow;



	protected:

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
			this->btnZestawianiaKierowcow = (gcnew System::Windows::Forms::Button());
			this->btnZestawieniaSamochodow = (gcnew System::Windows::Forms::Button());
			this->btnZestawieniaZlecen = (gcnew System::Windows::Forms::Button());
			this->labelEditKontrahent = (gcnew System::Windows::Forms::Label());
			this->btnZestawienieKontrahentow = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnZestawianiaKierowcow
			// 
			this->btnZestawianiaKierowcow->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->btnZestawianiaKierowcow->Location = System::Drawing::Point(79, 149);
			this->btnZestawianiaKierowcow->Margin = System::Windows::Forms::Padding(4);
			this->btnZestawianiaKierowcow->Name = L"btnZestawianiaKierowcow";
			this->btnZestawianiaKierowcow->Size = System::Drawing::Size(437, 42);
			this->btnZestawianiaKierowcow->TabIndex = 92;
			this->btnZestawianiaKierowcow->Text = L"Kierowcy - pensje i przejechane kilometry";
			this->btnZestawianiaKierowcow->UseVisualStyleBackColor = true;
			this->btnZestawianiaKierowcow->Click += gcnew System::EventHandler(this, &ZestawieniaForm::btnZestawianiaKierowcow_Click);
			// 
			// btnZestawieniaSamochodow
			// 
			this->btnZestawieniaSamochodow->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->btnZestawieniaSamochodow->Location = System::Drawing::Point(79, 244);
			this->btnZestawieniaSamochodow->Margin = System::Windows::Forms::Padding(4);
			this->btnZestawieniaSamochodow->Name = L"btnZestawieniaSamochodow";
			this->btnZestawieniaSamochodow->Size = System::Drawing::Size(437, 42);
			this->btnZestawieniaSamochodow->TabIndex = 93;
			this->btnZestawieniaSamochodow->Text = L"Samochody - przejechane kilometry i koszty";
			this->btnZestawieniaSamochodow->UseVisualStyleBackColor = true;
			this->btnZestawieniaSamochodow->Click += gcnew System::EventHandler(this, &ZestawieniaForm::btnZestawieniaSamochodow_Click);
			// 
			// btnZestawieniaZlecen
			// 
			this->btnZestawieniaZlecen->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->btnZestawieniaZlecen->Location = System::Drawing::Point(79, 345);
			this->btnZestawieniaZlecen->Margin = System::Windows::Forms::Padding(4);
			this->btnZestawieniaZlecen->Name = L"btnZestawieniaZlecen";
			this->btnZestawieniaZlecen->Size = System::Drawing::Size(437, 42);
			this->btnZestawieniaZlecen->TabIndex = 94;
			this->btnZestawieniaZlecen->Text = L"Zlecenia - przychody, koszty i zyski";
			this->btnZestawieniaZlecen->UseVisualStyleBackColor = true;
			this->btnZestawieniaZlecen->Click += gcnew System::EventHandler(this, &ZestawieniaForm::btnZestawieniaZlecen_Click);
			// 
			// labelEditKontrahent
			// 
			this->labelEditKontrahent->AutoSize = true;
			this->labelEditKontrahent->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->labelEditKontrahent->Location = System::Drawing::Point(231, 37);
			this->labelEditKontrahent->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelEditKontrahent->Name = L"labelEditKontrahent";
			this->labelEditKontrahent->Size = System::Drawing::Size(142, 29);
			this->labelEditKontrahent->TabIndex = 96;
			this->labelEditKontrahent->Text = L"Zestawienia";
			// 
			// btnZestawienieKontrahentow
			// 
			this->btnZestawienieKontrahentow->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->btnZestawienieKontrahentow->Location = System::Drawing::Point(79, 446);
			this->btnZestawienieKontrahentow->Margin = System::Windows::Forms::Padding(4);
			this->btnZestawienieKontrahentow->Name = L"btnZestawienieKontrahentow";
			this->btnZestawienieKontrahentow->Size = System::Drawing::Size(437, 42);
			this->btnZestawienieKontrahentow->TabIndex = 97;
			this->btnZestawienieKontrahentow->Text = L"Kontrahenci - przejechane kilometry i zyski";
			this->btnZestawienieKontrahentow->UseVisualStyleBackColor = true;
			this->btnZestawienieKontrahentow->Click += gcnew System::EventHandler(this, &ZestawieniaForm::btnZestawienieKontrahentow_Click);
			// 
			// ZestawieniaForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(602, 621);
			this->Controls->Add(this->btnZestawienieKontrahentow);
			this->Controls->Add(this->labelEditKontrahent);
			this->Controls->Add(this->btnZestawieniaZlecen);
			this->Controls->Add(this->btnZestawieniaSamochodow);
			this->Controls->Add(this->btnZestawianiaKierowcow);
			this->Name = L"ZestawieniaForm";
			this->Text = L"ZestawieniaForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void btnZestawianiaKierowcow_Click(System::Object^ sender, System::EventArgs^ e) {
	ZestawienieKierowcowForm^ zestawienieKierowcowForm = gcnew ZestawienieKierowcowForm(connectionString);
	zestawienieKierowcowForm->ShowDialog();
}
private: System::Void btnZestawieniaSamochodow_Click(System::Object^ sender, System::EventArgs^ e) {
	ZestawienieSamochodowForm^ zestawienieSamochodowForm = gcnew ZestawienieSamochodowForm(connectionString);
	zestawienieSamochodowForm->ShowDialog();
}
private: System::Void btnZestawieniaZlecen_Click(System::Object^ sender, System::EventArgs^ e) {
	ZestawienieZlecenForm^ zestawienieZlecenForm = gcnew ZestawienieZlecenForm(connectionString);
	zestawienieZlecenForm->ShowDialog();
}
private: System::Void btnZestawienieKontrahentow_Click(System::Object^  sender, System::EventArgs^  e) {
	ZestawienieKontrahentowForm^ zestawienieKontrahentowForm = gcnew ZestawienieKontrahentowForm(connectionString);
	zestawienieKontrahentowForm->ShowDialog();
}
};
}
