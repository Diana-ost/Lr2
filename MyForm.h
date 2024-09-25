#pragma once

namespace Lr2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


	private: System::Windows::Forms::ListBox^ listBox1;

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
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Лінія", L"Прямокутник", L"Зафарбований прямокутник",
					L"Еліпс", L"Зафарбований еліпс", L"Сектор", L"Зірка"
			});
			this->listBox1->Location = System::Drawing::Point(32, 12);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(164, 95);
			this->listBox1->TabIndex = 0;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(551, 418);
			this->Controls->Add(this->listBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		Graphics^graf = CreateGraphics();
		Pen^ pn = gcnew System::Drawing::Pen(Color::Purple,2);
		Brush^ br = gcnew System::Drawing::SolidBrush(Color::Purple);
		graf->Clear(SystemColors::Control);

		switch(listBox1->SelectedIndex) 
		{
		case 0:graf->DrawLine(pn, 150, 150, 450, 300); break;
		case 1:graf->DrawRectangle(pn, 150, 150, 300, 125); break;
		case 2:graf->FillRectangle(br, 150, 150, 300, 125); break;
		case 3:graf->DrawEllipse(pn, 150, 150, 300, 125); break;
		case 4:graf->FillEllipse(br, 150, 150, 300, 125); break;
		case 5:graf->FillPie(br,200,150,200,170,50,130); break;
		case 6:
			array<Point> ^ star;
			star = gcnew array<Point>(11);
			star[0].X = 290; star[0].Y = 50;
			star[1].X = 250; star[1].Y = 140;
			star[2].X = 140; star[2].Y = 150;
			star[3].X = 220; star[3].Y = 220;
			star[4].X = 190; star[4].Y = 320;
			star[5].X = 290; star[5].Y = 270;
			star[6].X = 390; star[6].Y = 320;
			star[7].X = 360; star[7].Y = 220;
			star[8].X = 440; star[8].Y = 150;
			star[9].X = 330; star[9].Y = 140;
			star[10].X = 290; star[10].Y = 50;
			graf->FillPolygon(br, star); break;
		}
	}
};
}
