#pragma once
namespace Spedycja {
	using namespace System;

	public ref class ComboBoxItem
	{
	public:
		ComboBoxItem(String^ id, String^ value)
		{
			this->id = id;
			this->value = value;
		}
	private:
		String^ id = "";
		String^ value;

	public:  String^ ToString() override
	{
		return value;
	}



	public: String^ getValue() {
		return value;
	}

	public: String^ getId() {
		return id;
	}

	};
}