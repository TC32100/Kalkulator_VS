#include "MainForm.h" 

// Importieren der ben�tigten Namensr�ume aus.NET
using namespace System;
using namespace System::Windows::Forms;

// Notwendiges Attribut f�r Windows-Forms-Anwendungen wenn COM verwendet wird
[STAThread]

void main()
{
	//Aktivieren visueller Stile f�r die Anwendung
	Application::EnableVisualStyles();	

	// Setzten des Text-Rendering-Modus
	Application::SetCompatibleTextRenderingDefault(false);	
	KalkulatorVS::MainForm calculatorForm;

	// Starten der Standardnachrichtenschleife und Anzeigen der Form 
	Application::Run(% calculatorForm); 
}