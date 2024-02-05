#pragma once
#include "Controlador.h"
#include "Datos.h"
#include<ctime>

namespace PracticaFinal1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			srand(time(NULL));
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			//buffer
			canvas = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(canvas, panel1->ClientRectangle);

			//bitmaps
			bmpAmbulancia = gcnew Bitmap("astronauta.png");
			bmpPersonas = gcnew Bitmap("Personajes.png");
			//bmpMap = gcnew Bitmap("mapa_ambiente.png");

			//dato

			dato = new Dato();
			dato->leerDatos();

			// controlador
			control = new Controlador(bmpAmbulancia, dato->getTiempo());
		}

	private:
		//buffer
		Graphics^ canvas;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		//Bitmaps
		Bitmap^ bmpAmbulancia;
		Bitmap^ bmpPersonas;
		Bitmap^ bmpMap;
		
		//controlador
		Controlador* control;
	private: System::Windows::Forms::Timer^ timerTiempo;
	private: System::Windows::Forms::Timer^ timerPersonas;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lblPA;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ lblTiempo;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ lblPuntaje;

		//datos
		Dato* dato;

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Timer^ timerMain;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->timerMain = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerTiempo = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerPersonas = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblPA = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblTiempo = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lblPuntaje = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(-1, 34);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(686, 480);
			this->panel1->TabIndex = 0;
			// 
			// timerMain
			// 
			this->timerMain->Enabled = true;
			this->timerMain->Tick += gcnew System::EventHandler(this, &MyForm::timerMain_Tick);
			// 
			// timerTiempo
			// 
			this->timerTiempo->Enabled = true;
			this->timerTiempo->Interval = 1000;
			this->timerTiempo->Tick += gcnew System::EventHandler(this, &MyForm::timerTiempo_Tick);
			// 
			// timerPersonas
			// 
			this->timerPersonas->Enabled = true;
			this->timerPersonas->Interval = 1000;
			this->timerPersonas->Tick += gcnew System::EventHandler(this, &MyForm::timerPersonas_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(76, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Per. Ayudadas";
			// 
			// lblPA
			// 
			this->lblPA->AutoSize = true;
			this->lblPA->Location = System::Drawing::Point(96, 14);
			this->lblPA->Name = L"lblPA";
			this->lblPA->Size = System::Drawing::Size(13, 13);
			this->lblPA->TabIndex = 2;
			this->lblPA->Text = L"0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(394, 14);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Tiempo";
			// 
			// lblTiempo
			// 
			this->lblTiempo->AutoSize = true;
			this->lblTiempo->Location = System::Drawing::Point(443, 15);
			this->lblTiempo->Name = L"lblTiempo";
			this->lblTiempo->Size = System::Drawing::Size(13, 13);
			this->lblTiempo->TabIndex = 4;
			this->lblTiempo->Text = L"0";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(183, 15);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(43, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Puntaje";
			// 
			// lblPuntaje
			// 
			this->lblPuntaje->AutoSize = true;
			this->lblPuntaje->Location = System::Drawing::Point(233, 14);
			this->lblPuntaje->Name = L"lblPuntaje";
			this->lblPuntaje->Size = System::Drawing::Size(13, 13);
			this->lblPuntaje->TabIndex = 6;
			this->lblPuntaje->Text = L"0";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(688, 513);
			this->Controls->Add(this->lblPuntaje);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->lblTiempo);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lblPA);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
private: System::Void timerMain_Tick(System::Object^ sender, System::EventArgs^ e) {
	//clear
	buffer->Graphics->Clear(Color::White);

	// colision
	control->colision();
	
	//mover
	control->moverTodo(buffer->Graphics);
	//dibujar
	lblPA->Text = "" + control->getAmbulancia()->getAyuda();
	lblTiempo->Text = "" + control->getTiempo();
	lblPuntaje->Text = "" + control->getPuntaje();
	//buffer->Graphics->DrawImage(bmpMap, 0, 0, panel1->Width, panel1->Height);
	control->dibujarTodo(buffer->Graphics, bmpAmbulancia, bmpPersonas);

	//render
	//condiciones
	if (control->getAmbulancia()->getAyuda() == 500)
	{
		timerMain->Enabled = false;
		MessageBox::Show("You win");
		this->Close();
	}
	else if (control->getTiempo() == 0)
	{
		timerMain->Enabled = false;
		MessageBox::Show("You lose");
		this->Close();
	}
	else
	{
		buffer->Render(canvas);
	}

}
private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	switch (e->KeyCode)
	{
	case Keys::A: case Keys::Left:
		control->getAmbulancia()->mover(buffer->Graphics, 'A'); break;
	case Keys::D: case Keys::Right:
		control->getAmbulancia()->mover(buffer->Graphics, 'D'); break;
	case Keys::W: case Keys::Up:
		control->getAmbulancia()->mover(buffer->Graphics, 'W'); break;
	case Keys::S: case Keys::Down:
		control->getAmbulancia()->mover(buffer->Graphics, 'S'); break;
	}
}
private: System::Void timerPersonas_Tick(System::Object^ sender, System::EventArgs^ e) {
	Personaje* p = new Personaje(bmpPersonas->Width / 7, bmpPersonas->Height / 2);
	control->agregarPersona(p);
}
private: System::Void timerTiempo_Tick(System::Object^ sender, System::EventArgs^ e) {
	control->decreceTiempo();
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	timerPersonas->Interval = 1000 * dato->getsegundosPersona();
	timerPersonas->Enabled = true;
}
};
}
