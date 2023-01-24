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
		return value;
	}

	public: int getId() {
		return id;
	}

	};
}