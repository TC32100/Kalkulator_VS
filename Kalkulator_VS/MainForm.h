#pragma once

namespace KalkulatorVS {

	// Importieren der nötigen Namensräume 
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	// Deklarationen für Benutzeroberfläche, Log-Verarbeitung, serielle Kommunikation und Speicherverwaltung
	private: System::IO::StreamWriter^ logFileWriter;
	private: System::Text::StringBuilder^ receiveBuffer;
	private: System::Windows::Forms::Button^ initializeButton;
	private: System::Windows::Forms::Button^ abortButton;
	private: System::Windows::Forms::Button^ sendButton;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::IO::Ports::SerialPort^ serialPort1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::ComponentModel::IContainer^ components;


	private:
	#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->initializeButton = (gcnew System::Windows::Forms::Button());
			this->abortButton = (gcnew System::Windows::Forms::Button());
			this->sendButton = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// initializeButton
			// 
			this->initializeButton->Location = System::Drawing::Point(239, 74);
			this->initializeButton->Name = L"initializeButton";
			this->initializeButton->Size = System::Drawing::Size(101, 38);
			this->initializeButton->TabIndex = 0;
			this->initializeButton->Text = L"Initialisieren";
			this->initializeButton->UseVisualStyleBackColor = true;
			this->initializeButton->Click += gcnew System::EventHandler(this, &MainForm::initializeButton_Click);
			// 
			// abortButton
			// 
			this->abortButton->Location = System::Drawing::Point(383, 74);
			this->abortButton->Name = L"abortButton";
			this->abortButton->Size = System::Drawing::Size(101, 38);
			this->abortButton->TabIndex = 1;
			this->abortButton->Text = L"Abbruch";
			this->abortButton->UseVisualStyleBackColor = true;
			this->abortButton->Click += gcnew System::EventHandler(this, &MainForm::abortButton_Click);
			// 
			// sendButton
			// 
			this->sendButton->Location = System::Drawing::Point(310, 202);
			this->sendButton->Name = L"sendButton";
			this->sendButton->Size = System::Drawing::Size(101, 38);
			this->sendButton->TabIndex = 2;
			this->sendButton->Text = L"Senden";
			this->sendButton->UseVisualStyleBackColor = true;
			this->sendButton->Click += gcnew System::EventHandler(this, &MainForm::sendButton_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(33, 212);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(224, 20);
			this->textBox1->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(33, 307);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(224, 20);
			this->textBox2->TabIndex = 4;
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::SystemColors::Menu;
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Location = System::Drawing::Point(33, 193);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(53, 13);
			this->textBox3->TabIndex = 5;
			this->textBox3->Text = L"Eingabe:";
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::SystemColors::Menu;
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox4->Location = System::Drawing::Point(33, 288);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(53, 13);
			this->textBox4->TabIndex = 6;
			this->textBox4->Text = L" Ausgabe:";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(534, 483);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->sendButton);
			this->Controls->Add(this->abortButton);
			this->Controls->Add(this->initializeButton);
			this->Name = L"MainForm";
			this->Text = L"Kalkulator";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	// Starten der Anwendung 
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {

		// Deaktivieren der "Senden" Taste
		this->sendButton->Enabled = false;
	}

	// Betätigen der "Initialisieren" Taste 
	private: System::Void initializeButton_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			// Konfigurieren der Einstellungen des seriellen Ports
			this->serialPort1->PortName = "COM5"; // Auswahl des Ports
			this->serialPort1->BaudRate = 9600;
			this->serialPort1->Open(); // Öffnen des Ports 
			this->sendButton->Enabled = true; // Aktivieren der "Senden" Taste

			// Initialisieren des Puffers für die empfangenen Daten
			this->receiveBuffer = gcnew System::Text::StringBuilder();

			// Registrieren des Event-Handlers für den Empfang von Daten über den seriellen Port.
			this->serialPort1->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &MainForm::serialPort1_DataReceived);

			// Öffnen der Logdatei
			this->logFileWriter = gcnew System::IO::StreamWriter("KalkulatorLog.txt", true);
		}
		catch (Exception^ ex) {
			// Zeigen einer Fehlermeldung, wenn das Öffnen des Ports fehlschlägt 
			MessageBox::Show("Fehler beim Öffnen des Ports: " + ex->Message);
		}
	}	

	// Betätigen der "Abbruch" Taste 
	private: System::Void abortButton_Click(System::Object^ sender, System::EventArgs^ e) {

		// Schließen des seriellen Ports
		this->serialPort1->Close();
		this->sendButton->Enabled = false; // Deaktivieren des "Senden" Buttons

		// Schließen der Logdatei, wenn sie geöffnet ist
		if (this->logFileWriter != nullptr) 
		{
			this->logFileWriter->Close();
			this->logFileWriter = nullptr;
		}
	}

	// Betätigen der "Senden" Taste 
	private: System::Void sendButton_Click(System::Object^ sender, System::EventArgs^ e) {

		// Extrahieren des Ausdrucks aus dem Eingabefeld (textBox1)
		String^ sendMessage = this->textBox1->Text;
		
		// Bereinigen des Ausgabefeldes (textBox2)
		this->textBox2->Clear();

		// Senden des Ausdrucks über den seriellen Port, wenn er geöfffnet ist
		if (this->serialPort1->IsOpen) 
		{
			this->serialPort1->WriteLine(sendMessage);
		}

		// Schreiben des gesendeten Ausdrucks in die Logdatei, wenn das Logging aktiv ist
		if (this->logFileWriter != nullptr) 
		{
			this->logFileWriter->WriteLine("[Gesendet]: " + sendMessage);
			this->logFileWriter->Flush(); // Sicherstellen, dass die Daten direkt geschrieben werden
		}
	}
	private: System::Void serialPort1_DataReceived(System::Object^ sender, System::IO::Ports::SerialDataReceivedEventArgs^ e) {
		// Lesen der empfangenen Daten
		String^ receivedData = this->serialPort1->ReadExisting();

		// Anhängen an den Puffer
		this->receiveBuffer->Append(receivedData);

		// Prüfen, ob die Nachricht im Puffer vollständig ist 
		while (this->receiveBuffer->ToString()->Contains("\n")) 
		{
			// Suchen nach dem Index des Zeilenumbruchs
			int newlineIndex = this->receiveBuffer->ToString()->IndexOf("\n");

			// Extrahieren der vollständigen Nachricht
			String^ receivedMessage = this->receiveBuffer->ToString()->Substring(0, newlineIndex + 1);

			// Entfernen der Nachricht aus dem Puffer
			this->receiveBuffer->Remove(0, newlineIndex + 1);

			// Schreiben der empfangenen Nachricht in die Logdatei, wenn das Logging aktiv ist
			if (this->logFileWriter != nullptr) 
			{
				this->logFileWriter->WriteLine("[Empfangen]: " + receivedMessage->Trim());
				this->logFileWriter->Flush();
			}

			// Aufrufen der Methode zum aktualisieren des Ausgabefeldes (textBox2) und Leerzeichen entfernen.
			this->Invoke(gcnew Action<String^>(this, &MainForm::UpdateTextBox2), receivedMessage->Trim());
		}
	}

	private: System::Void UpdateTextBox2(String^ data) {
		// Einfügen der empfangenen Nachricht in das Ausgabefeld (textBox2)
		this->textBox2->AppendText(data + Environment::NewLine);
	}
	};
}
