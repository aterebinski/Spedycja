#pragma once
namespace Spedycja {
	using namespace System;

	public ref class ComboBoxItem
	{
	public:
		ComboBoxItem(int id, String^ value)
		{
			this->id = id;
			this->value = value;
		}
	private:
		int id;
		String^ value;

	public:  String^ ToString() override
	{
		return value;
	}



	public: String^ getValue() {
		if (value) {
			return value;
		}
		else return "";
		
	}

	public: int getId() {
		return id;
	}

	};
}