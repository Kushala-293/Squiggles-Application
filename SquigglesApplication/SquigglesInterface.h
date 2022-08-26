#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "squiggles.h";
#include <Windows.h>
#include <fstream>
#include <filesystem>
#include <cmath>
#include <iomanip>
#include <Mmsystem.h>
#include <mciapi.h>

//these two headers are already included in the <Windows.h> header





namespace SquigglesApplication {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;
	using namespace squiggles;


	std::string pathName, fileName;
	std::vector<double> coordinates;
	bool hide, hideArrows;
	double maxVel, maxAccel, maxJerk, robotWidth, timeStep;
	constexpr double pi = 3.14159265358979323846;
	/// <summary>
	/// Summary for SquigglesInterface
	/// </summary>
	public ref class SquigglesInterface : public System::Windows::Forms::Form
	{
	public:
		SquigglesInterface(void)
		{
			InitializeComponent();
			loadWork();
			hide = false;
			hideArrows = false;
			poseXTextbox->Text = "0";
			poseYTextbox->Text = "0";
			poseThetaTextbox->Text = "0";
			poseVelocityTextbox->Text = "-";
			poseAccelTextbox->Text = "-";
			poseJerkTextbox->Text = "-";
			poseVelocityTextbox->ReadOnly = true;
			poseAccelTextbox->ReadOnly = true;
			poseJerkTextbox->ReadOnly = true;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SquigglesInterface()
		{
			if (components)
			{
				delete components;
			}
		}
	#pragma region Definitions
	private: System::Windows::Forms::Button^ ExportButton;
	protected:

	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ MaxVelocityTextbox;
	private: System::Windows::Forms::TextBox^ MaxAccelTextbox;
	private: System::Windows::Forms::TextBox^ MaxJerkTextbox;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ RobotWidthTextbox;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ TimeStepTextbox;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ PathNameTextbox;

	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;

	private: System::Windows::Forms::TextBox^ ExportLocationTextbox;
		   //private: System::Windows::Forms::Button^ FindFileButton;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DataGridView^ poseGrid;

	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::TextBox^ poseThetaTextbox;

	private: System::Windows::Forms::TextBox^ poseYTextbox;

	private: System::Windows::Forms::TextBox^ poseXTextbox;

	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::TextBox^ poseJerkTextbox;

	private: System::Windows::Forms::TextBox^ poseAccelTextbox;

	private: System::Windows::Forms::TextBox^ poseVelocityTextbox;

	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ UpdateRowButton;

	private: System::Windows::Forms::Button^ AddRowButton;
	private: System::Windows::Forms::Button^ InsertRowButton;

	private: System::Windows::Forms::CheckBox^ ControlVectorCheckBox;
	private: System::Windows::Forms::Button^ FindFileButton;
	private: System::Windows::Forms::CheckBox^ FastGenerationCheckbox;
	private: System::Windows::Forms::TextBox^ DataTypeTextbox;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::CheckBox^ arrayCheckBox;
	private: System::Windows::Forms::Button^ GenerateButton;
	private: System::Windows::Forms::TextBox^ FilePreviewTextbox;


	private: System::Windows::Forms::Button^ HideArrowButton;
	private: System::Windows::Forms::PictureBox^ startupAnimation;

	private: System::Windows::Forms::Timer^ startupTimer;
	private: System::Windows::Forms::ToolTip^ toolTip2;
	private: System::Windows::Forms::ToolTip^ toolTip3;
	private: System::Windows::Forms::ToolTip^ toolTip4;
	private: System::Windows::Forms::ToolTip^ toolTip5;
	private: System::Windows::Forms::ToolTip^ toolTip6;
	private: System::Windows::Forms::ToolTip^ toolTip7;
	private: System::Windows::Forms::ToolTip^ toolTip8;
	private: System::Windows::Forms::ToolTip^ toolTip24;
	private: System::Windows::Forms::ToolTip^ toolTip9;
	private: System::Windows::Forms::ToolTip^ toolTip13;
	private: System::Windows::Forms::ToolTip^ toolTip12;
	private: System::Windows::Forms::ToolTip^ toolTip11;
	private: System::Windows::Forms::ToolTip^ toolTip18;
	private: System::Windows::Forms::ToolTip^ toolTip17;
	private: System::Windows::Forms::ToolTip^ toolTip16;
	private: System::Windows::Forms::ToolTip^ toolTip22;
	private: System::Windows::Forms::ToolTip^ toolTip21;
	private: System::Windows::Forms::ToolTip^ toolTip19;
	private: System::Windows::Forms::ToolTip^ toolTip20;
	private: System::Windows::Forms::ToolTip^ toolTip14;
	private: System::Windows::Forms::ToolTip^ toolTip10;
	private: System::Windows::Forms::ToolTip^ toolTip15;
	private: System::Windows::Forms::ToolTip^ toolTip23;
	private: System::Windows::Forms::ToolTip^ toolTip25;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ JerkColumn;
	private: System::Windows::Forms::ToolTip^ toolTip1;
	private: System::Windows::Forms::TextBox^ HeaderLocationTextbox;

	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Button^ ToggleViewButton;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Button^ FindHeaderFileButton;
	private: System::Windows::Forms::ToolTip^ toolTip26;
	private: System::Windows::Forms::ToolTip^ toolTip27;
	private: System::Windows::Forms::ToolTip^ toolTip28;
	private: System::Windows::Forms::ToolTip^ toolTip29;
	private: System::Windows::Forms::ToolTip^ toolTip30;
	private: System::Windows::Forms::ToolTip^ toolTip31;






	private: System::ComponentModel::IContainer^ components;



#pragma endregion




	private:
		

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle15 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle16 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle17 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle18 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle19 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle20 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle21 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SquigglesInterface::typeid));
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->MaxVelocityTextbox = (gcnew System::Windows::Forms::TextBox());
			this->ExportButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->MaxAccelTextbox = (gcnew System::Windows::Forms::TextBox());
			this->MaxJerkTextbox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->RobotWidthTextbox = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->TimeStepTextbox = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->PathNameTextbox = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->ExportLocationTextbox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->poseGrid = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->JerkColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->poseThetaTextbox = (gcnew System::Windows::Forms::TextBox());
			this->poseYTextbox = (gcnew System::Windows::Forms::TextBox());
			this->poseXTextbox = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->poseJerkTextbox = (gcnew System::Windows::Forms::TextBox());
			this->poseAccelTextbox = (gcnew System::Windows::Forms::TextBox());
			this->poseVelocityTextbox = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->UpdateRowButton = (gcnew System::Windows::Forms::Button());
			this->AddRowButton = (gcnew System::Windows::Forms::Button());
			this->InsertRowButton = (gcnew System::Windows::Forms::Button());
			this->ControlVectorCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->FindFileButton = (gcnew System::Windows::Forms::Button());
			this->FastGenerationCheckbox = (gcnew System::Windows::Forms::CheckBox());
			this->DataTypeTextbox = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->arrayCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->GenerateButton = (gcnew System::Windows::Forms::Button());
			this->FilePreviewTextbox = (gcnew System::Windows::Forms::TextBox());
			this->HideArrowButton = (gcnew System::Windows::Forms::Button());
			this->startupAnimation = (gcnew System::Windows::Forms::PictureBox());
			this->startupTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->toolTip2 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip3 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip4 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip5 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip6 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip7 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip8 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip9 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->HeaderLocationTextbox = (gcnew System::Windows::Forms::TextBox());
			this->toolTip10 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->FindHeaderFileButton = (gcnew System::Windows::Forms::Button());
			this->toolTip11 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip12 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip13 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip14 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip15 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip16 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip17 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip18 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip19 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip20 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip21 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip22 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip23 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->ToggleViewButton = (gcnew System::Windows::Forms::Button());
			this->toolTip24 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip25 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->toolTip26 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip27 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip28 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip29 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip30 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip31 = (gcnew System::Windows::Forms::ToolTip(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->poseGrid))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->startupAnimation))->BeginInit();
			this->SuspendLayout();
			// 
			// MaxVelocityTextbox
			// 
			this->MaxVelocityTextbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->MaxVelocityTextbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->MaxVelocityTextbox->ForeColor = System::Drawing::SystemColors::Window;
			this->MaxVelocityTextbox->Location = System::Drawing::Point(15, 61);
			this->MaxVelocityTextbox->Name = L"MaxVelocityTextbox";
			this->MaxVelocityTextbox->Size = System::Drawing::Size(100, 20);
			this->MaxVelocityTextbox->TabIndex = 4;
			this->toolTip1->SetToolTip(this->MaxVelocityTextbox, L"Maximum Velocity of Robot in m/s\r\nPress Space to Convert from Customary(in) to Me"
				L"tric(m)");
			this->MaxVelocityTextbox->TextChanged += gcnew System::EventHandler(this, &SquigglesInterface::MaxVelocityTextbox_TextChanged);
			this->MaxVelocityTextbox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &SquigglesInterface::MaxVelocityTextbox_KeyDown);
			this->MaxVelocityTextbox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &SquigglesInterface::MaxVelocityTextbox_KeyPress);
			this->MaxVelocityTextbox->Leave += gcnew System::EventHandler(this, &SquigglesInterface::MaxVelocityTextbox_Leave);
			// 
			// ExportButton
			// 
			this->ExportButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->ExportButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ExportButton->FlatAppearance->BorderColor = System::Drawing::Color::LightGray;
			this->ExportButton->FlatAppearance->BorderSize = 2;
			this->ExportButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ExportButton->ForeColor = System::Drawing::Color::White;
			this->ExportButton->Location = System::Drawing::Point(885, 471);
			this->ExportButton->Name = L"ExportButton";
			this->ExportButton->Size = System::Drawing::Size(109, 40);
			this->ExportButton->TabIndex = 0;
			this->ExportButton->Text = L"Export";
			this->toolTip24->SetToolTip(this->ExportButton, L"Export Trajectory to Selected File");
			this->ExportButton->UseVisualStyleBackColor = false;
			this->ExportButton->Click += gcnew System::EventHandler(this, &SquigglesInterface::ExportButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Enabled = false;
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(12, 45);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(118, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Maximum Velocity (m/s)";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Enabled = false;
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(12, 84);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(137, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Maximum Accleration (m/s²)";
			// 
			// MaxAccelTextbox
			// 
			this->MaxAccelTextbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->MaxAccelTextbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->MaxAccelTextbox->ForeColor = System::Drawing::SystemColors::Window;
			this->MaxAccelTextbox->Location = System::Drawing::Point(15, 100);
			this->MaxAccelTextbox->Name = L"MaxAccelTextbox";
			this->MaxAccelTextbox->Size = System::Drawing::Size(100, 20);
			this->MaxAccelTextbox->TabIndex = 5;
			this->toolTip2->SetToolTip(this->MaxAccelTextbox, L"Maximum Acceleration of Robot in m/s²\r\nPress Space to Convert from Customary(in) "
				L"to Metric(m)\r\n");
			this->MaxAccelTextbox->TextChanged += gcnew System::EventHandler(this, &SquigglesInterface::MaxAccelTextbox_TextChanged);
			this->MaxAccelTextbox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &SquigglesInterface::MaxAccelTextbox_KeyDown);
			this->MaxAccelTextbox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &SquigglesInterface::MaxAccelTextbox_KeyPress);
			this->MaxAccelTextbox->Leave += gcnew System::EventHandler(this, &SquigglesInterface::MaxAccelTextbox_Leave);
			// 
			// MaxJerkTextbox
			// 
			this->MaxJerkTextbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->MaxJerkTextbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->MaxJerkTextbox->ForeColor = System::Drawing::SystemColors::Window;
			this->MaxJerkTextbox->Location = System::Drawing::Point(15, 139);
			this->MaxJerkTextbox->Name = L"MaxJerkTextbox";
			this->MaxJerkTextbox->Size = System::Drawing::Size(100, 20);
			this->MaxJerkTextbox->TabIndex = 6;
			this->toolTip3->SetToolTip(this->MaxJerkTextbox, L"Maximum Jerk of Robot in m/s³\r\nPress Space to Convert from Customary(in) to Metri"
				L"c(m)");
			this->MaxJerkTextbox->TextChanged += gcnew System::EventHandler(this, &SquigglesInterface::MaxJerkTextbox_TextChanged);
			this->MaxJerkTextbox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &SquigglesInterface::MaxJerkTextbox_KeyDown);
			this->MaxJerkTextbox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &SquigglesInterface::MaxJerkTextbox_KeyPress);
			this->MaxJerkTextbox->Leave += gcnew System::EventHandler(this, &SquigglesInterface::MaxJerkTextbox_Leave);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Enabled = false;
			this->label4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label4->ForeColor = System::Drawing::SystemColors::Window;
			this->label4->Location = System::Drawing::Point(10, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(122, 26);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Constraints";
			// 
			// RobotWidthTextbox
			// 
			this->RobotWidthTextbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->RobotWidthTextbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->RobotWidthTextbox->ForeColor = System::Drawing::SystemColors::Window;
			this->RobotWidthTextbox->Location = System::Drawing::Point(15, 224);
			this->RobotWidthTextbox->Name = L"RobotWidthTextbox";
			this->RobotWidthTextbox->Size = System::Drawing::Size(100, 20);
			this->RobotWidthTextbox->TabIndex = 9;
			this->toolTip4->SetToolTip(this->RobotWidthTextbox, L"Horizontal Distance Between Wheels(m)\r\nPress Space to Convert from Customary(in) "
				L"to Metric(m)\r\n");
			this->RobotWidthTextbox->TextChanged += gcnew System::EventHandler(this, &SquigglesInterface::RobotWidthTextbox_TextChanged);
			this->RobotWidthTextbox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &SquigglesInterface::RobotWidthTextbox_KeyDown);
			this->RobotWidthTextbox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &SquigglesInterface::RobotWidthTextbox_KeyPress);
			this->RobotWidthTextbox->Leave += gcnew System::EventHandler(this, &SquigglesInterface::RobotWidthTextbox_Leave);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Enabled = false;
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(12, 208);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(81, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Robot Width(m)";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Enabled = false;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(10, 172);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(71, 26);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Model";
			// 
			// label7
			// 
			this->label7->AccessibleRole = System::Windows::Forms::AccessibleRole::Client;
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Enabled = false;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label7->ForeColor = System::Drawing::Color::White;
			this->label7->Location = System::Drawing::Point(10, 257);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(91, 26);
			this->label7->TabIndex = 13;
			this->label7->Text = L"Settings";
			// 
			// TimeStepTextbox
			// 
			this->TimeStepTextbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->TimeStepTextbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->TimeStepTextbox->ForeColor = System::Drawing::SystemColors::Window;
			this->TimeStepTextbox->Location = System::Drawing::Point(15, 411);
			this->TimeStepTextbox->Name = L"TimeStepTextbox";
			this->TimeStepTextbox->Size = System::Drawing::Size(100, 20);
			this->TimeStepTextbox->TabIndex = 12;
			this->toolTip8->SetToolTip(this->TimeStepTextbox, L"Time Interval Between Each Pose Point in Trajectory");
			this->TimeStepTextbox->TextChanged += gcnew System::EventHandler(this, &SquigglesInterface::TimeStepTextbox_TextChanged);
			this->TimeStepTextbox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &SquigglesInterface::TimeStepTextbox_KeyPress);
			this->TimeStepTextbox->Leave += gcnew System::EventHandler(this, &SquigglesInterface::TimeStepTextbox_Leave);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Enabled = false;
			this->label8->ForeColor = System::Drawing::Color::White;
			this->label8->Location = System::Drawing::Point(12, 395);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(73, 13);
			this->label8->TabIndex = 11;
			this->label8->Text = L"Time Step (dt)";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Enabled = false;
			this->label9->ForeColor = System::Drawing::Color::White;
			this->label9->Location = System::Drawing::Point(12, 434);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(81, 13);
			this->label9->TabIndex = 14;
			this->label9->Text = L"Export Location";
			// 
			// PathNameTextbox
			// 
			this->PathNameTextbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->PathNameTextbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->PathNameTextbox->ForeColor = System::Drawing::SystemColors::Window;
			this->PathNameTextbox->Location = System::Drawing::Point(15, 309);
			this->PathNameTextbox->Name = L"PathNameTextbox";
			this->PathNameTextbox->Size = System::Drawing::Size(100, 20);
			this->PathNameTextbox->TabIndex = 16;
			this->toolTip5->SetToolTip(this->PathNameTextbox, L"Name Of Array on Export");
			this->PathNameTextbox->TextChanged += gcnew System::EventHandler(this, &SquigglesInterface::PathNameTextbox_TextChanged);
			this->PathNameTextbox->Leave += gcnew System::EventHandler(this, &SquigglesInterface::PathNameTextbox_Leave);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Enabled = false;
			this->label10->ForeColor = System::Drawing::Color::White;
			this->label10->Location = System::Drawing::Point(12, 293);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(60, 13);
			this->label10->TabIndex = 15;
			this->label10->Text = L"Path Name";
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"openFileDialog1";
			// 
			// ExportLocationTextbox
			// 
			this->ExportLocationTextbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ExportLocationTextbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ExportLocationTextbox->ForeColor = System::Drawing::SystemColors::Window;
			this->ExportLocationTextbox->Location = System::Drawing::Point(15, 450);
			this->ExportLocationTextbox->Name = L"ExportLocationTextbox";
			this->ExportLocationTextbox->Size = System::Drawing::Size(100, 20);
			this->ExportLocationTextbox->TabIndex = 17;
			this->toolTip9->SetToolTip(this->ExportLocationTextbox, L"Path to Export File (.txt, .c, .cpp)");
			this->ExportLocationTextbox->TextChanged += gcnew System::EventHandler(this, &SquigglesInterface::ExportLocationTextbox_TextChanged);
			this->ExportLocationTextbox->Leave += gcnew System::EventHandler(this, &SquigglesInterface::ExportLocationTextbox_Leave);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Enabled = false;
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(12, 123);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(104, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Maximum Jerk (m/s³)";
			// 
			// poseGrid
			// 
			this->poseGrid->AllowUserToAddRows = false;
			this->poseGrid->AllowUserToDeleteRows = false;
			this->poseGrid->AllowUserToResizeColumns = false;
			this->poseGrid->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->poseGrid->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			dataGridViewCellStyle15->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle15->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			dataGridViewCellStyle15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle15->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			dataGridViewCellStyle15->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle15->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle15->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->poseGrid->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle15;
			this->poseGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->poseGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->Column1, this->Column2,
					this->Column3, this->Column4, this->Column5, this->JerkColumn
			});
			this->poseGrid->GridColor = System::Drawing::SystemColors::ActiveCaption;
			this->poseGrid->Location = System::Drawing::Point(689, 239);
			this->poseGrid->MultiSelect = false;
			this->poseGrid->Name = L"poseGrid";
			this->poseGrid->ReadOnly = true;
			this->poseGrid->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->poseGrid->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->poseGrid->Size = System::Drawing::Size(343, 226);
			this->poseGrid->TabIndex = 19;
			this->poseGrid->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &SquigglesInterface::poseGrid_CellClick);
			this->poseGrid->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &SquigglesInterface::poseGrid_CellContentClick);
			this->poseGrid->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &SquigglesInterface::poseGrid_CellDoubleClick);
			// 
			// Column1
			// 
			dataGridViewCellStyle16->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			dataGridViewCellStyle16->SelectionBackColor = System::Drawing::Color::Silver;
			dataGridViewCellStyle16->SelectionForeColor = System::Drawing::Color::Black;
			this->Column1->DefaultCellStyle = dataGridViewCellStyle16;
			this->Column1->HeaderText = L"X";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column1->Width = 40;
			// 
			// Column2
			// 
			dataGridViewCellStyle17->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			dataGridViewCellStyle17->SelectionBackColor = System::Drawing::Color::Silver;
			dataGridViewCellStyle17->SelectionForeColor = System::Drawing::Color::Black;
			this->Column2->DefaultCellStyle = dataGridViewCellStyle17;
			this->Column2->HeaderText = L"Y";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column2->Width = 40;
			// 
			// Column3
			// 
			dataGridViewCellStyle18->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			dataGridViewCellStyle18->SelectionBackColor = System::Drawing::Color::Silver;
			dataGridViewCellStyle18->SelectionForeColor = System::Drawing::Color::Black;
			this->Column3->DefaultCellStyle = dataGridViewCellStyle18;
			this->Column3->HeaderText = L"θ";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column3->Width = 40;
			// 
			// Column4
			// 
			dataGridViewCellStyle19->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			dataGridViewCellStyle19->SelectionBackColor = System::Drawing::Color::Silver;
			dataGridViewCellStyle19->SelectionForeColor = System::Drawing::Color::Black;
			this->Column4->DefaultCellStyle = dataGridViewCellStyle19;
			this->Column4->HeaderText = L"Velocity";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			this->Column4->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column4->Width = 55;
			// 
			// Column5
			// 
			dataGridViewCellStyle20->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			dataGridViewCellStyle20->SelectionBackColor = System::Drawing::Color::Silver;
			dataGridViewCellStyle20->SelectionForeColor = System::Drawing::Color::Black;
			this->Column5->DefaultCellStyle = dataGridViewCellStyle20;
			this->Column5->HeaderText = L"Acceleration";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			this->Column5->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column5->Width = 75;
			// 
			// JerkColumn
			// 
			dataGridViewCellStyle21->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			dataGridViewCellStyle21->SelectionBackColor = System::Drawing::Color::Silver;
			dataGridViewCellStyle21->SelectionForeColor = System::Drawing::Color::Black;
			this->JerkColumn->DefaultCellStyle = dataGridViewCellStyle21;
			this->JerkColumn->HeaderText = L"Jerk";
			this->JerkColumn->Name = L"JerkColumn";
			this->JerkColumn->ReadOnly = true;
			this->JerkColumn->Width = 50;
			// 
			// label11
			// 
			this->label11->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::Color::Transparent;
			this->label11->Enabled = false;
			this->label11->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label11->ForeColor = System::Drawing::SystemColors::Window;
			this->label11->Location = System::Drawing::Point(805, 9);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(114, 26);
			this->label11->TabIndex = 20;
			this->label11->Text = L"Waypoints";
			// 
			// poseThetaTextbox
			// 
			this->poseThetaTextbox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->poseThetaTextbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->poseThetaTextbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->poseThetaTextbox->ForeColor = System::Drawing::SystemColors::Window;
			this->poseThetaTextbox->Location = System::Drawing::Point(746, 139);
			this->poseThetaTextbox->Name = L"poseThetaTextbox";
			this->poseThetaTextbox->Size = System::Drawing::Size(100, 20);
			this->poseThetaTextbox->TabIndex = 26;
			this->toolTip13->SetToolTip(this->poseThetaTextbox, L"Direction of Robot at Waypoint \r\nPress Space to Convert from Customary(in) to Met"
				L"ric(m)");
			this->poseThetaTextbox->TextChanged += gcnew System::EventHandler(this, &SquigglesInterface::poseThetaTextbox_TextChanged);
			this->poseThetaTextbox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &SquigglesInterface::poseThetaTextbox_KeyDown);
			this->poseThetaTextbox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &SquigglesInterface::poseThetaTextbox_KeyPress);
			this->poseThetaTextbox->Leave += gcnew System::EventHandler(this, &SquigglesInterface::poseThetaTextbox_Leave);
			// 
			// poseYTextbox
			// 
			this->poseYTextbox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->poseYTextbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->poseYTextbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->poseYTextbox->ForeColor = System::Drawing::SystemColors::Window;
			this->poseYTextbox->Location = System::Drawing::Point(746, 100);
			this->poseYTextbox->Name = L"poseYTextbox";
			this->poseYTextbox->Size = System::Drawing::Size(100, 20);
			this->poseYTextbox->TabIndex = 25;
			this->toolTip12->SetToolTip(this->poseYTextbox, L"Y Position of Robot at Waypoint\r\nPress Space to Convert from Customary(in) to Met"
				L"ric(m)");
			this->poseYTextbox->TextChanged += gcnew System::EventHandler(this, &SquigglesInterface::poseYTextbox_TextChanged);
			this->poseYTextbox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &SquigglesInterface::poseYTextbox_KeyDown);
			this->poseYTextbox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &SquigglesInterface::poseYTextbox_KeyPress);
			this->poseYTextbox->Leave += gcnew System::EventHandler(this, &SquigglesInterface::poseYTextbox_Leave);
			// 
			// poseXTextbox
			// 
			this->poseXTextbox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->poseXTextbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->poseXTextbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->poseXTextbox->ForeColor = System::Drawing::SystemColors::Window;
			this->poseXTextbox->Location = System::Drawing::Point(746, 61);
			this->poseXTextbox->Name = L"poseXTextbox";
			this->poseXTextbox->Size = System::Drawing::Size(100, 20);
			this->poseXTextbox->TabIndex = 24;
			this->toolTip11->SetToolTip(this->poseXTextbox, L"X Position of Robot at Waypoint\r\nPress Space to Convert from Customary(in) to Met"
				L"ric(m)\r\n");
			this->poseXTextbox->TextChanged += gcnew System::EventHandler(this, &SquigglesInterface::poseXTextbox_TextChanged);
			this->poseXTextbox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &SquigglesInterface::poseXTextbox_KeyDown);
			this->poseXTextbox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &SquigglesInterface::poseXTextbox_KeyPress);
			this->poseXTextbox->Leave += gcnew System::EventHandler(this, &SquigglesInterface::poseXTextbox_Leave);
			// 
			// label12
			// 
			this->label12->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label12->AutoSize = true;
			this->label12->BackColor = System::Drawing::Color::Transparent;
			this->label12->Enabled = false;
			this->label12->ForeColor = System::Drawing::Color::White;
			this->label12->Location = System::Drawing::Point(743, 84);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(47, 13);
			this->label12->TabIndex = 23;
			this->label12->Text = L"Pose - Y";
			// 
			// label13
			// 
			this->label13->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label13->AutoSize = true;
			this->label13->BackColor = System::Drawing::Color::Transparent;
			this->label13->Enabled = false;
			this->label13->ForeColor = System::Drawing::Color::White;
			this->label13->Location = System::Drawing::Point(743, 123);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(68, 13);
			this->label13->TabIndex = 22;
			this->label13->Text = L"Pose - Theta";
			// 
			// label14
			// 
			this->label14->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label14->AutoSize = true;
			this->label14->BackColor = System::Drawing::Color::Transparent;
			this->label14->Enabled = false;
			this->label14->ForeColor = System::Drawing::Color::White;
			this->label14->Location = System::Drawing::Point(743, 45);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(47, 13);
			this->label14->TabIndex = 21;
			this->label14->Text = L"Pose - X";
			// 
			// poseJerkTextbox
			// 
			this->poseJerkTextbox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->poseJerkTextbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->poseJerkTextbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->poseJerkTextbox->ForeColor = System::Drawing::SystemColors::Window;
			this->poseJerkTextbox->Location = System::Drawing::Point(875, 139);
			this->poseJerkTextbox->Name = L"poseJerkTextbox";
			this->poseJerkTextbox->Size = System::Drawing::Size(100, 20);
			this->poseJerkTextbox->TabIndex = 32;
			this->toolTip18->SetToolTip(this->poseJerkTextbox, L"Jerk of Robot at Waypoint\r\nPress Space to Convert from Customary(in) to Metric(m)"
				L"\r\n");
			this->poseJerkTextbox->TextChanged += gcnew System::EventHandler(this, &SquigglesInterface::poseJerkTextbox_TextChanged);
			this->poseJerkTextbox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &SquigglesInterface::poseJerkTextbox_KeyDown);
			this->poseJerkTextbox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &SquigglesInterface::poseJerkTextbox_KeyPress);
			this->poseJerkTextbox->Leave += gcnew System::EventHandler(this, &SquigglesInterface::poseJerkTextbox_Leave);
			// 
			// poseAccelTextbox
			// 
			this->poseAccelTextbox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->poseAccelTextbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->poseAccelTextbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->poseAccelTextbox->ForeColor = System::Drawing::SystemColors::Window;
			this->poseAccelTextbox->Location = System::Drawing::Point(875, 100);
			this->poseAccelTextbox->Name = L"poseAccelTextbox";
			this->poseAccelTextbox->Size = System::Drawing::Size(100, 20);
			this->poseAccelTextbox->TabIndex = 31;
			this->toolTip17->SetToolTip(this->poseAccelTextbox, L"Acceleration of Robot at Waypoint\r\nPress Space to Convert from Customary(in) to M"
				L"etric(m)\r\n");
			this->poseAccelTextbox->TextChanged += gcnew System::EventHandler(this, &SquigglesInterface::poseAccelTextbox_TextChanged);
			this->poseAccelTextbox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &SquigglesInterface::poseAccelTextbox_KeyDown);
			this->poseAccelTextbox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &SquigglesInterface::poseAccelTextbox_KeyPress);
			this->poseAccelTextbox->Leave += gcnew System::EventHandler(this, &SquigglesInterface::poseAccelTextbox_Leave);
			// 
			// poseVelocityTextbox
			// 
			this->poseVelocityTextbox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->poseVelocityTextbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->poseVelocityTextbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->poseVelocityTextbox->ForeColor = System::Drawing::SystemColors::Window;
			this->poseVelocityTextbox->Location = System::Drawing::Point(875, 61);
			this->poseVelocityTextbox->Name = L"poseVelocityTextbox";
			this->poseVelocityTextbox->Size = System::Drawing::Size(100, 20);
			this->poseVelocityTextbox->TabIndex = 30;
			this->toolTip16->SetToolTip(this->poseVelocityTextbox, L"Velocity of Robot at Waypoint\r\nPress Space to Convert from Customary(in) to Metri"
				L"c(m)\r\n");
			this->poseVelocityTextbox->TextChanged += gcnew System::EventHandler(this, &SquigglesInterface::poseVelocityTextbox_TextChanged);
			this->poseVelocityTextbox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &SquigglesInterface::poseVelocityTextbox_KeyDown);
			this->poseVelocityTextbox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &SquigglesInterface::poseVelocityTextbox_KeyPress);
			this->poseVelocityTextbox->Leave += gcnew System::EventHandler(this, &SquigglesInterface::poseVelocityTextbox_Leave);
			// 
			// label15
			// 
			this->label15->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label15->AutoSize = true;
			this->label15->BackColor = System::Drawing::Color::Transparent;
			this->label15->Enabled = false;
			this->label15->ForeColor = System::Drawing::Color::White;
			this->label15->Location = System::Drawing::Point(872, 84);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(90, 13);
			this->label15->TabIndex = 29;
			this->label15->Text = L"Accleration (m/s²)";
			// 
			// label16
			// 
			this->label16->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label16->AutoSize = true;
			this->label16->BackColor = System::Drawing::Color::Transparent;
			this->label16->Enabled = false;
			this->label16->ForeColor = System::Drawing::Color::White;
			this->label16->Location = System::Drawing::Point(872, 123);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(57, 13);
			this->label16->TabIndex = 28;
			this->label16->Text = L"Jerk (m/s³)";
			// 
			// label17
			// 
			this->label17->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label17->AutoSize = true;
			this->label17->BackColor = System::Drawing::Color::Transparent;
			this->label17->Enabled = false;
			this->label17->ForeColor = System::Drawing::Color::White;
			this->label17->Location = System::Drawing::Point(872, 45);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(71, 13);
			this->label17->TabIndex = 27;
			this->label17->Text = L"Velocity (m/s)";
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::LightGray;
			this->button1->FlatAppearance->BorderSize = 2;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(969, 199);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(63, 25);
			this->button1->TabIndex = 33;
			this->button1->Text = L"Delete";
			this->toolTip22->SetToolTip(this->button1, L"Delete Selected Waypoint");
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &SquigglesInterface::button1_Click);
			// 
			// UpdateRowButton
			// 
			this->UpdateRowButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->UpdateRowButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->UpdateRowButton->FlatAppearance->BorderColor = System::Drawing::Color::LightGray;
			this->UpdateRowButton->FlatAppearance->BorderSize = 2;
			this->UpdateRowButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->UpdateRowButton->ForeColor = System::Drawing::Color::White;
			this->UpdateRowButton->Location = System::Drawing::Point(875, 199);
			this->UpdateRowButton->Name = L"UpdateRowButton";
			this->UpdateRowButton->Size = System::Drawing::Size(63, 25);
			this->UpdateRowButton->TabIndex = 34;
			this->UpdateRowButton->Text = L"Update";
			this->toolTip21->SetToolTip(this->UpdateRowButton, L"Updated Selected Waypoint with Parameters Above");
			this->UpdateRowButton->UseVisualStyleBackColor = false;
			this->UpdateRowButton->Click += gcnew System::EventHandler(this, &SquigglesInterface::UpdateRowButton_Click);
			// 
			// AddRowButton
			// 
			this->AddRowButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->AddRowButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->AddRowButton->FlatAppearance->BorderColor = System::Drawing::Color::LightGray;
			this->AddRowButton->FlatAppearance->BorderSize = 2;
			this->AddRowButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->AddRowButton->ForeColor = System::Drawing::Color::White;
			this->AddRowButton->Location = System::Drawing::Point(689, 199);
			this->AddRowButton->Name = L"AddRowButton";
			this->AddRowButton->Size = System::Drawing::Size(63, 25);
			this->AddRowButton->TabIndex = 36;
			this->AddRowButton->Text = L"Add";
			this->toolTip19->SetToolTip(this->AddRowButton, L"Add Waypoint To End of List with Parameters Above");
			this->AddRowButton->UseVisualStyleBackColor = false;
			this->AddRowButton->Click += gcnew System::EventHandler(this, &SquigglesInterface::AddRowButton_Click);
			// 
			// InsertRowButton
			// 
			this->InsertRowButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->InsertRowButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->InsertRowButton->FlatAppearance->BorderColor = System::Drawing::Color::LightGray;
			this->InsertRowButton->FlatAppearance->BorderSize = 2;
			this->InsertRowButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->InsertRowButton->ForeColor = System::Drawing::Color::White;
			this->InsertRowButton->Location = System::Drawing::Point(783, 199);
			this->InsertRowButton->Name = L"InsertRowButton";
			this->InsertRowButton->Size = System::Drawing::Size(63, 25);
			this->InsertRowButton->TabIndex = 37;
			this->InsertRowButton->Text = L"Insert";
			this->toolTip20->SetToolTip(this->InsertRowButton, L"Insert Waypoint To List Below Selected Waypoint with Parameters Above");
			this->InsertRowButton->UseVisualStyleBackColor = false;
			this->InsertRowButton->Click += gcnew System::EventHandler(this, &SquigglesInterface::InsertRowButton_Click);
			// 
			// ControlVectorCheckBox
			// 
			this->ControlVectorCheckBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->ControlVectorCheckBox->AutoSize = true;
			this->ControlVectorCheckBox->ForeColor = System::Drawing::SystemColors::Window;
			this->ControlVectorCheckBox->Location = System::Drawing::Point(746, 172);
			this->ControlVectorCheckBox->Name = L"ControlVectorCheckBox";
			this->ControlVectorCheckBox->Size = System::Drawing::Size(98, 17);
			this->ControlVectorCheckBox->TabIndex = 38;
			this->ControlVectorCheckBox->Text = L"Control Vectors";
			this->toolTip14->SetToolTip(this->ControlVectorCheckBox, L"Enable Control Vector Constraints for Waypoints\r\nAllows for Wayoints to Have Disc"
				L"rete Velocity, Acceleration, and Jerk Values");
			this->ControlVectorCheckBox->UseVisualStyleBackColor = true;
			this->ControlVectorCheckBox->CheckedChanged += gcnew System::EventHandler(this, &SquigglesInterface::ControlVectorCheckBox_CheckedChanged);
			// 
			// FindFileButton
			// 
			this->FindFileButton->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(36)));
			this->FindFileButton->FlatAppearance->BorderSize = 0;
			this->FindFileButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->FindFileButton->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->FindFileButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"FindFileButton.Image")));
			this->FindFileButton->Location = System::Drawing::Point(119, 445);
			this->FindFileButton->Name = L"FindFileButton";
			this->FindFileButton->Size = System::Drawing::Size(33, 30);
			this->FindFileButton->TabIndex = 18;
			this->toolTip10->SetToolTip(this->FindFileButton, L"Find File in File Explorer");
			this->FindFileButton->UseVisualStyleBackColor = true;
			this->FindFileButton->Click += gcnew System::EventHandler(this, &SquigglesInterface::FindFileButton_Click);
			// 
			// FastGenerationCheckbox
			// 
			this->FastGenerationCheckbox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->FastGenerationCheckbox->AutoSize = true;
			this->FastGenerationCheckbox->ForeColor = System::Drawing::SystemColors::Window;
			this->FastGenerationCheckbox->Location = System::Drawing::Point(872, 172);
			this->FastGenerationCheckbox->Name = L"FastGenerationCheckbox";
			this->FastGenerationCheckbox->Size = System::Drawing::Size(101, 17);
			this->FastGenerationCheckbox->TabIndex = 39;
			this->FastGenerationCheckbox->Text = L"Fast Generation";
			this->toolTip15->SetToolTip(this->FastGenerationCheckbox, L"Sacrifices Smoothness of Curve for Faster Generation Times\r\nOnly Available if Con"
				L"trol Vectors are Disabled\r\n");
			this->FastGenerationCheckbox->UseVisualStyleBackColor = true;
			// 
			// DataTypeTextbox
			// 
			this->DataTypeTextbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->DataTypeTextbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->DataTypeTextbox->ForeColor = System::Drawing::SystemColors::Window;
			this->DataTypeTextbox->Location = System::Drawing::Point(15, 348);
			this->DataTypeTextbox->Name = L"DataTypeTextbox";
			this->DataTypeTextbox->Size = System::Drawing::Size(100, 20);
			this->DataTypeTextbox->TabIndex = 41;
			this->toolTip6->SetToolTip(this->DataTypeTextbox, L"Data Type of Array on Export");
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->BackColor = System::Drawing::Color::Transparent;
			this->label18->Enabled = false;
			this->label18->ForeColor = System::Drawing::Color::White;
			this->label18->Location = System::Drawing::Point(12, 332);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(57, 13);
			this->label18->TabIndex = 40;
			this->label18->Text = L"Data Type";
			// 
			// arrayCheckBox
			// 
			this->arrayCheckBox->AutoSize = true;
			this->arrayCheckBox->ForeColor = System::Drawing::SystemColors::Window;
			this->arrayCheckBox->Location = System::Drawing::Point(15, 375);
			this->arrayCheckBox->Name = L"arrayCheckBox";
			this->arrayCheckBox->Size = System::Drawing::Size(67, 17);
			this->arrayCheckBox->TabIndex = 42;
			this->arrayCheckBox->Text = L"2D Array";
			this->toolTip7->SetToolTip(this->arrayCheckBox, L"Save Array as 2D Array on Export");
			this->arrayCheckBox->UseVisualStyleBackColor = true;
			// 
			// GenerateButton
			// 
			this->GenerateButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->GenerateButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->GenerateButton->FlatAppearance->BorderColor = System::Drawing::Color::LightGray;
			this->GenerateButton->FlatAppearance->BorderSize = 2;
			this->GenerateButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->GenerateButton->ForeColor = System::Drawing::Color::White;
			this->GenerateButton->Location = System::Drawing::Point(735, 471);
			this->GenerateButton->Name = L"GenerateButton";
			this->GenerateButton->Size = System::Drawing::Size(109, 40);
			this->GenerateButton->TabIndex = 43;
			this->GenerateButton->Text = L"Generate";
			this->toolTip23->SetToolTip(this->GenerateButton, L"Generate Trajectory from Waypoints and Display Graphically\r\nGenerate File Preview"
				L" of Waypoints in CSV Form");
			this->GenerateButton->UseVisualStyleBackColor = false;
			this->GenerateButton->Click += gcnew System::EventHandler(this, &SquigglesInterface::GenerateButton_Click);
			// 
			// FilePreviewTextbox
			// 
			this->FilePreviewTextbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->FilePreviewTextbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->FilePreviewTextbox->Enabled = false;
			this->FilePreviewTextbox->ForeColor = System::Drawing::SystemColors::Window;
			this->FilePreviewTextbox->Location = System::Drawing::Point(200, 38);
			this->FilePreviewTextbox->Multiline = true;
			this->FilePreviewTextbox->Name = L"FilePreviewTextbox";
			this->FilePreviewTextbox->ReadOnly = true;
			this->FilePreviewTextbox->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->FilePreviewTextbox->Size = System::Drawing::Size(432, 432);
			this->FilePreviewTextbox->TabIndex = 44;
			this->FilePreviewTextbox->Visible = false;
			this->FilePreviewTextbox->WordWrap = false;
			// 
			// HideArrowButton
			// 
			this->HideArrowButton->BackColor = System::Drawing::Color::Transparent;
			this->HideArrowButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->HideArrowButton->Location = System::Drawing::Point(200, 38);
			this->HideArrowButton->Name = L"HideArrowButton";
			this->HideArrowButton->Size = System::Drawing::Size(432, 432);
			this->HideArrowButton->TabIndex = 46;
			this->HideArrowButton->UseVisualStyleBackColor = false;
			this->HideArrowButton->Visible = false;
			this->HideArrowButton->Click += gcnew System::EventHandler(this, &SquigglesInterface::HideArrowButton_Click);
			// 
			// startupAnimation
			// 
			this->startupAnimation->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"startupAnimation.Image")));
			this->startupAnimation->Location = System::Drawing::Point(-20, -69);
			this->startupAnimation->Name = L"startupAnimation";
			this->startupAnimation->Size = System::Drawing::Size(1084, 665);
			this->startupAnimation->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->startupAnimation->TabIndex = 47;
			this->startupAnimation->TabStop = false;
			// 
			// startupTimer
			// 
			this->startupTimer->Enabled = true;
			this->startupTimer->Interval = 13000;
			this->startupTimer->Tick += gcnew System::EventHandler(this, &SquigglesInterface::startupTimer_Tick);
			// 
			// HeaderLocationTextbox
			// 
			this->HeaderLocationTextbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->HeaderLocationTextbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->HeaderLocationTextbox->ForeColor = System::Drawing::SystemColors::Window;
			this->HeaderLocationTextbox->Location = System::Drawing::Point(15, 491);
			this->HeaderLocationTextbox->Name = L"HeaderLocationTextbox";
			this->HeaderLocationTextbox->Size = System::Drawing::Size(100, 20);
			this->HeaderLocationTextbox->TabIndex = 49;
			this->toolTip26->SetToolTip(this->HeaderLocationTextbox, L"Path to Export File (.h, .hpp)");
			this->toolTip9->SetToolTip(this->HeaderLocationTextbox, L"Path to Export File (.txt,.cpp.,.hpp,.h)");
			this->HeaderLocationTextbox->TextChanged += gcnew System::EventHandler(this, &SquigglesInterface::HeaderLocationTextbox_TextChanged);
			this->HeaderLocationTextbox->Leave += gcnew System::EventHandler(this, &SquigglesInterface::HeaderLocationTextbox_Leave);
			// 
			// FindHeaderFileButton
			// 
			this->FindHeaderFileButton->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(36)));
			this->FindHeaderFileButton->FlatAppearance->BorderSize = 0;
			this->FindHeaderFileButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->FindHeaderFileButton->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->FindHeaderFileButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"FindHeaderFileButton.Image")));
			this->FindHeaderFileButton->Location = System::Drawing::Point(119, 486);
			this->FindHeaderFileButton->Name = L"FindHeaderFileButton";
			this->FindHeaderFileButton->Size = System::Drawing::Size(33, 30);
			this->FindHeaderFileButton->TabIndex = 52;
			this->toolTip10->SetToolTip(this->FindHeaderFileButton, L"Find File in File Explorer");
			this->FindHeaderFileButton->UseVisualStyleBackColor = true;
			this->FindHeaderFileButton->Click += gcnew System::EventHandler(this, &SquigglesInterface::FindHeaderFileButton_Click);
			// 
			// ToggleViewButton
			// 
			this->ToggleViewButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->ToggleViewButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ToggleViewButton->FlatAppearance->BorderColor = System::Drawing::Color::LightGray;
			this->ToggleViewButton->FlatAppearance->BorderSize = 2;
			this->ToggleViewButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ToggleViewButton->ForeColor = System::Drawing::Color::White;
			this->ToggleViewButton->Location = System::Drawing::Point(362, 476);
			this->ToggleViewButton->Name = L"ToggleViewButton";
			this->ToggleViewButton->Size = System::Drawing::Size(106, 35);
			this->ToggleViewButton->TabIndex = 50;
			this->ToggleViewButton->Text = L"Toggle View";
			this->toolTip27->SetToolTip(this->ToggleViewButton, L"Toggle Betweem Graphical and Text Previews");
			this->ToggleViewButton->UseVisualStyleBackColor = false;
			this->ToggleViewButton->Click += gcnew System::EventHandler(this, &SquigglesInterface::ToggleViewButton_Click);
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->BackColor = System::Drawing::Color::Transparent;
			this->label19->Enabled = false;
			this->label19->ForeColor = System::Drawing::Color::White;
			this->label19->Location = System::Drawing::Point(12, 475);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(86, 13);
			this->label19->TabIndex = 48;
			this->label19->Text = L"Header Location";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->BackColor = System::Drawing::Color::Transparent;
			this->label20->Enabled = false;
			this->label20->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label20->ForeColor = System::Drawing::SystemColors::Window;
			this->label20->Location = System::Drawing::Point(362, 9);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(106, 26);
			this->label20->TabIndex = 51;
			this->label20->Text = L"〜波線!〜";
			// 
			// SquigglesInterface
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)));
			this->ClientSize = System::Drawing::Size(1044, 523);
			this->Controls->Add(this->startupAnimation);
			this->Controls->Add(this->FindHeaderFileButton);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->ToggleViewButton);
			this->Controls->Add(this->HeaderLocationTextbox);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->HideArrowButton);
			this->Controls->Add(this->FilePreviewTextbox);
			this->Controls->Add(this->GenerateButton);
			this->Controls->Add(this->arrayCheckBox);
			this->Controls->Add(this->DataTypeTextbox);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->FastGenerationCheckbox);
			this->Controls->Add(this->FindFileButton);
			this->Controls->Add(this->ControlVectorCheckBox);
			this->Controls->Add(this->InsertRowButton);
			this->Controls->Add(this->AddRowButton);
			this->Controls->Add(this->UpdateRowButton);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->poseJerkTextbox);
			this->Controls->Add(this->poseAccelTextbox);
			this->Controls->Add(this->poseVelocityTextbox);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->poseThetaTextbox);
			this->Controls->Add(this->poseYTextbox);
			this->Controls->Add(this->poseXTextbox);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->poseGrid);
			this->Controls->Add(this->ExportLocationTextbox);
			this->Controls->Add(this->PathNameTextbox);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->TimeStepTextbox);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->RobotWidthTextbox);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->MaxJerkTextbox);
			this->Controls->Add(this->MaxAccelTextbox);
			this->Controls->Add(this->MaxVelocityTextbox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ExportButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"SquigglesInterface";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"〜波線!〜";
			this->Load += gcnew System::EventHandler(this, &SquigglesInterface::SquigglesInterface_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &SquigglesInterface::SquigglesInterface_Paint);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->poseGrid))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->startupAnimation))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

#pragma region Textbox Events
	private: System::Void MaxVelocityTextbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			maxVel = std::stod(toStandardString(MaxVelocityTextbox->Text));
		}
		catch (...) {}
		/*std::string myText = "\n\n\n" + toStandardString(maxVel.ToString()) + "\n\n\n";
		std::wstring stemp = std::wstring(myText.begin(), myText.end());
		LPCWSTR sw = stemp.c_str();
		OutputDebugString(sw);*/
	}
	private: System::Void MaxAccelTextbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			maxAccel = std::stod(toStandardString(MaxAccelTextbox->Text));
		}
		catch (...) {}

	}
	private: System::Void MaxJerkTextbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			maxJerk = std::stod(toStandardString(MaxJerkTextbox->Text));
		}
		catch (...) {}

	}
	private: System::Void RobotWidthTextbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			robotWidth = std::stod(toStandardString(RobotWidthTextbox->Text));
		}
		catch (...) {}

	}
	private: System::Void TimeStepTextbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			timeStep = std::stod(toStandardString(TimeStepTextbox->Text));
		}
		catch (...) {}

	}
	private: System::Void poseXTextbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			timeStep = std::stod(toStandardString(poseXTextbox->Text));
		}
		catch (...) {}

	}
	private: System::Void poseYTextbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			timeStep = std::stod(toStandardString(poseYTextbox->Text));
		}
		catch (...) {}
	}
	private: System::Void poseThetaTextbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			timeStep = std::stod(toStandardString(poseThetaTextbox->Text));
		}
		catch (...) {}
	}
	private: System::Void poseVelocityTextbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			timeStep = std::stod(toStandardString(TimeStepTextbox->Text));
		}
		catch (...) {}

	}
	private: System::Void poseAccelTextbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			timeStep = std::stod(toStandardString(poseAccelTextbox->Text));
		}
		catch (...) {}

	}
	private: System::Void poseJerkTextbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			timeStep = std::stod(toStandardString(poseJerkTextbox->Text));
		}
		catch (...) {}

	}
	private: System::Void HeaderLocationTextbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {

		   }
	private: System::Void PathNameTextbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			   pathName = toStandardString(MaxVelocityTextbox->Text);
		   }
	private: System::Void ExportLocationTextbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		fileName = toStandardString(MaxVelocityTextbox->Text);
		std::string location = toStandardString(ExportLocationTextbox->Text);
		if (fileExists(location) && (location.substr(location.find_last_of(".") + 1) == "cpp" || location.substr(location.find_last_of(".") + 1) == "c")) {
			DataTypeTextbox->ReadOnly = false;
			HeaderLocationTextbox->ReadOnly = false;
			FindHeaderFileButton->Enabled = true;
			DataTypeTextbox->Text = "double";
			arrayCheckBox->Checked = true;
			arrayCheckBox->AutoCheck = true;
		}
		else {
			DataTypeTextbox->ReadOnly = true;
			HeaderLocationTextbox->ReadOnly = false;
			FindHeaderFileButton->Enabled = false;
			HeaderLocationTextbox->Text = "";
			DataTypeTextbox->Text = "";
			arrayCheckBox->Checked = false;
			arrayCheckBox->AutoCheck = false;
		}


	}

	private: System::Void MaxVelocityTextbox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar == '.') {
			if (this->MaxVelocityTextbox->Text->Contains(".") && !this->MaxVelocityTextbox->SelectedText->Contains("."))
				e->Handled = true;
		}
		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
	private: System::Void MaxAccelTextbox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar == '.') {
			if (this->MaxAccelTextbox->Text->Contains(".") && !this->MaxAccelTextbox->SelectedText->Contains("."))
				e->Handled = true;
		}
		else if (e->KeyChar == ' ') {
			MaxAccelTextbox->Text = gcnew String((ceil(inchToMeter(std::stod(toStandardString(MaxAccelTextbox->Text))) * 1000) / 1000).ToString());
		}
		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
	private: System::Void MaxJerkTextbox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar == '.') {
			if (this->MaxJerkTextbox->Text->Contains(".") && !this->MaxJerkTextbox->SelectedText->Contains("."))
				e->Handled = true;
		}
		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
	private: System::Void RobotWidthTextbox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar == '.') {
			if (this->RobotWidthTextbox->Text->Contains(".") && !this->RobotWidthTextbox->SelectedText->Contains("."))
				e->Handled = true;
		}
		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
	private: System::Void TimeStepTextbox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar == '.') {
			if (this->TimeStepTextbox->Text->Contains(".") && !this->TimeStepTextbox->SelectedText->Contains("."))
				e->Handled = true;
		}

		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
	private: System::Void poseXTextbox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar == '.') {
			if (this->poseXTextbox->Text->Contains(".") && !this->poseXTextbox->SelectedText->Contains("."))
				e->Handled = true;
		}
		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}


	}
	private: System::Void poseYTextbox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar == '.') {
			if (this->poseYTextbox->Text->Contains(".") && !this->poseYTextbox->SelectedText->Contains("."))
				e->Handled = true;
		}
		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
	private: System::Void poseThetaTextbox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar == '.') {
			if (this->poseThetaTextbox->Text->Contains(".") && !this->poseThetaTextbox->SelectedText->Contains("."))
				e->Handled = true;
		}
		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
	private: System::Void poseVelocityTextbox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar == '.') {
			if (this->poseVelocityTextbox->Text->Contains(".") && !this->poseVelocityTextbox->SelectedText->Contains("."))
				e->Handled = true;
		}
		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
	private: System::Void poseAccelTextbox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar == '.') {
			if (this->poseAccelTextbox->Text->Contains(".") && !this->poseAccelTextbox->SelectedText->Contains("."))
				e->Handled = true;
		}
		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
	private: System::Void poseJerkTextbox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar == '.') {
			if (this->poseJerkTextbox->Text->Contains(".") && !this->poseJerkTextbox->SelectedText->Contains("."))
				e->Handled = true;
		}
		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}

	private: System::Void MaxVelocityTextbox_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (MaxVelocityTextbox->Text->Equals("")) {
			MaxVelocityTextbox->Text = "0";
		}
	}
	private: System::Void MaxAccelTextbox_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (MaxAccelTextbox->Text->Equals("")) {
			MaxAccelTextbox->Text = "0";
		}
	}
	private: System::Void MaxJerkTextbox_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (MaxJerkTextbox->Text->Equals("")) {
			MaxJerkTextbox->Text = "0";
		}
	}
	private: System::Void RobotWidthTextbox_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (RobotWidthTextbox->Text->Equals("")) {
			RobotWidthTextbox->Text = "0";
		}
	}
	private: System::Void PathNameTextbox_Leave(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void TimeStepTextbox_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (TimeStepTextbox->Text->Equals("")) {
			TimeStepTextbox->Text = "0.1";
			TimeStepTextbox->SelectionStart = 1;
		}
	}
	private: System::Void ExportLocationTextbox_Leave(System::Object^ sender, System::EventArgs^ e) {
		std::string location = toStandardString(ExportLocationTextbox->Text);
		std::filesystem::path p(location);
		std::string ext = p.extension().string();
		if (ext == ".cpp" || ext == ".c" || ext == ".txt") {
			
		}else{
				ExportLocationTextbox->Text = "";
		}

		if (!fileExists(location)) {
			ExportLocationTextbox->Text = "";
		}
	}
	private: System::Void poseXTextbox_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (poseXTextbox->Text->Equals("")) {
			poseXTextbox->Text = "0";
		}
		if (meterToInch(std::stod(toStandardString(poseXTextbox->Text))) > 144) {
			poseXTextbox->Text = "3.658";
		}
	}
	private: System::Void poseYTextbox_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (poseYTextbox->Text->Equals("")) {
			poseYTextbox->Text = "0";
		}
		if (meterToInch(std::stod(toStandardString(poseYTextbox->Text))) > 144) {
			poseYTextbox->Text = "3.658";
		}
	}
	private: System::Void poseThetaTextbox_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (poseThetaTextbox->Text->Equals("")) {
			poseThetaTextbox->Text = "0";
		}
	}
	private: System::Void poseVelocityTextbox_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (poseVelocityTextbox->Text->Equals("")) {
			poseVelocityTextbox->Text = "0";
		}
	}
	private: System::Void poseAccelTextbox_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (poseAccelTextbox->Text->Equals("")) {
			poseAccelTextbox->Text = "0";
		}
	}
	private: System::Void poseJerkTextbox_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (poseJerkTextbox->Text->Equals("")) {
			poseJerkTextbox->Text = "0";
		}
	}
	private: System::Void HeaderLocationTextbox_Leave(System::Object^ sender, System::EventArgs^ e) {
		std::string location = toStandardString(HeaderLocationTextbox->Text);
		std::filesystem::path p(location);
		std::string ext = p.extension().string();
		if (ext == ".hpp" || ext == ".h") {

		}
		else {
			HeaderLocationTextbox->Text = "";
		}

		if (!fileExists(location)) {
			HeaderLocationTextbox->Text = "";
		}
	}

	private: System::Void MaxVelocityTextbox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			   if (e->KeyCode == System::Windows::Forms::Keys::Space) {
				   e->SuppressKeyPress = true;
				   if (MaxVelocityTextbox->Text != "")
					   MaxVelocityTextbox->Text = gcnew String((ceil(inchToMeter(std::stod(toStandardString(MaxVelocityTextbox->Text))) * 1000) / 1000).ToString());
			   }
		   }
	private: System::Void MaxAccelTextbox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == System::Windows::Forms::Keys::Space) {
			e->SuppressKeyPress = true;
			if (MaxAccelTextbox->Text != "")
				MaxAccelTextbox->Text = gcnew String((ceil(inchToMeter(std::stod(toStandardString(MaxAccelTextbox->Text))) * 1000) / 1000).ToString());
		}
	}
	private: System::Void MaxJerkTextbox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == System::Windows::Forms::Keys::Space) {
			e->SuppressKeyPress = true;
			if (MaxJerkTextbox->Text != "")
				MaxJerkTextbox->Text = gcnew String((ceil(inchToMeter(std::stod(toStandardString(MaxJerkTextbox->Text))) * 1000) / 1000).ToString());
		}
	}
	private: System::Void RobotWidthTextbox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == System::Windows::Forms::Keys::Space) {
			e->SuppressKeyPress = true;
			if (RobotWidthTextbox->Text != "")
				RobotWidthTextbox->Text = gcnew String((ceil(inchToMeter(std::stod(toStandardString(RobotWidthTextbox->Text))) * 1000) / 1000).ToString());
		}
	}
	private: System::Void poseXTextbox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == System::Windows::Forms::Keys::Space) {
			e->SuppressKeyPress = true;
			if (poseXTextbox->Text != "")
				poseXTextbox->Text = gcnew String((ceil(inchToMeter(std::stod(toStandardString(poseXTextbox->Text))) * 1000) / 1000).ToString());
		}
	}
	private: System::Void poseYTextbox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == System::Windows::Forms::Keys::Space) {
			e->SuppressKeyPress = true;
			if (poseYTextbox->Text != "")
				poseYTextbox->Text = gcnew String((ceil(inchToMeter(std::stod(toStandardString(poseYTextbox->Text))) * 1000) / 1000).ToString());
		}
	}
	private: System::Void poseThetaTextbox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == System::Windows::Forms::Keys::Space) {
			e->SuppressKeyPress = true;
			if (poseThetaTextbox->Text != "")
				poseThetaTextbox->Text = gcnew String((ceil(degToRad(std::stod(toStandardString(poseThetaTextbox->Text))) * 1000) / 1000).ToString());
		}
	}
	private: System::Void poseVelocityTextbox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == System::Windows::Forms::Keys::Space) {
			e->SuppressKeyPress = true;
			if (poseVelocityTextbox->Text != "" && poseVelocityTextbox->Text != "-")
				poseVelocityTextbox->Text = gcnew String((ceil(inchToMeter(std::stod(toStandardString(poseVelocityTextbox->Text))) * 1000) / 1000).ToString());
		}
	}
	private: System::Void poseAccelTextbox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == System::Windows::Forms::Keys::Space) {
			e->SuppressKeyPress = true;
			if (poseAccelTextbox->Text != "" && poseAccelTextbox->Text != "-")
				poseAccelTextbox->Text = gcnew String((ceil(inchToMeter(std::stod(toStandardString(poseAccelTextbox->Text))) * 1000) / 1000).ToString());
		}
	}
	private: System::Void poseJerkTextbox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == System::Windows::Forms::Keys::Space) {
			e->SuppressKeyPress = true;
			if (poseJerkTextbox->Text != "" && poseJerkTextbox->Text != "-")
				poseJerkTextbox->Text = gcnew String((ceil(inchToMeter(std::stod(toStandardString(poseJerkTextbox->Text))) * 1000) / 1000).ToString());
		}
	}
#pragma endregion
	
#pragma region Button Events
	private: System::Void FindFileButton_Click(System::Object^ sender, System::EventArgs^ e) {
		openFileDialog->ShowDialog();
		ExportLocationTextbox->Text = openFileDialog->FileName;

		std::string location = toStandardString(ExportLocationTextbox->Text);
		std::filesystem::path p(location);
		std::string ext = p.extension().string();
		if (ext == ".cpp" || ext == ".c" || ext == ".txt") {

		}
		else {
			ExportLocationTextbox->Text = "";
		}
	}
	private: System::Void ExportButton_Click(System::Object^ sender, System::EventArgs^ e) {
		saveWork();
		if (poseGrid->Rows->Count == 0) {
			MessageBox::Show("Path cannot be generated with 0 pose points", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		else if (poseGrid->Rows->Count == 1) {
			MessageBox::Show("Path cannot be generated with 1 pose point", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		else if (consecutivePointsOverlap()) {
			MessageBox::Show("Consecutive pose points overlap in path", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		else if (std::stod(toStandardString(MaxVelocityTextbox->Text)) <= 0) {
			MessageBox::Show("Path could not be generated with provided velocity constraints", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		else if (std::stod(toStandardString(MaxAccelTextbox->Text)) <= 0) {
			MessageBox::Show("Path could not be generated with provided acceleration constraints", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		else if (std::stod(toStandardString(RobotWidthTextbox->Text)) <= 0) {
			MessageBox::Show("Path could not be generated with provided robot width constraints", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		else if (std::stod(toStandardString(TimeStepTextbox->Text)) <= 0) {
			MessageBox::Show("Path could not be generated with provided time step interval", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		else if (PathNameTextbox->Text == "") {
			MessageBox::Show("Please provide a path name", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		else if (ExportLocationTextbox->Text == "") {
			MessageBox::Show("Please provide a file path", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		else if (DataTypeTextbox->Text == "" && (toStandardString(ExportLocationTextbox->Text).substr(toStandardString(ExportLocationTextbox->Text).find_last_of(".") + 1) == "cpp" || toStandardString(ExportLocationTextbox->Text).substr(toStandardString(ExportLocationTextbox->Text).find_last_of(".") + 1) == "hpp" || toStandardString(ExportLocationTextbox->Text).substr(toStandardString(ExportLocationTextbox->Text).find_last_of(".") + 1) == "h")) {
			MessageBox::Show("Please provide a data type", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		else if (!fileExists(toStandardString(ExportLocationTextbox->Text))) {
			MessageBox::Show("Please provide a valid export location", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		exportData();
		MessageBox::Show("File Exported", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	private: System::Void GenerateButton_Click(System::Object^ sender, System::EventArgs^ e) {
		saveWork();
		if (poseGrid->Rows->Count == 0) {
			MessageBox::Show("Path cannot be generated with 0 pose points", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		else if (poseGrid->Rows->Count == 1) {
			MessageBox::Show("Path cannot be generated with 1 pose point", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		else if (consecutivePointsOverlap()) {
			MessageBox::Show("Consecutive pose points overlap in path", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		else if (std::stod(toStandardString(MaxVelocityTextbox->Text)) <= 0) {
			MessageBox::Show("Path could not be generated with provided velocity constraints", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		else if (std::stod(toStandardString(MaxAccelTextbox->Text)) <= 0) {
			MessageBox::Show("Path could not be generated with provided acceleration constraints", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		else if (std::stod(toStandardString(RobotWidthTextbox->Text)) <= 0) {
			MessageBox::Show("Path could not be generated with provided robot width constraints", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		else if (std::stod(toStandardString(TimeStepTextbox->Text)) <= 0) {
			MessageBox::Show("Path could not be generated with provided time step interval", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		generateData();
	}

	private: System::Void poseGrid_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		int i = poseGrid->CurrentCell->RowIndex;
		poseXTextbox->Text = poseGrid->Rows[i]->Cells[0]->Value->ToString();
		poseYTextbox->Text = poseGrid->Rows[i]->Cells[1]->Value->ToString();
		poseThetaTextbox->Text = poseGrid->Rows[i]->Cells[2]->Value->ToString();
		poseVelocityTextbox->Text = poseGrid->Rows[i]->Cells[3]->Value->ToString();
		poseAccelTextbox->Text = poseGrid->Rows[i]->Cells[4]->Value->ToString();
		poseJerkTextbox->Text = poseGrid->Rows[i]->Cells[5]->Value->ToString();
	}
	private: System::Void poseGrid_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		int i = poseGrid->CurrentCell->RowIndex;
		poseXTextbox->Text = poseGrid->Rows[i]->Cells[0]->Value->ToString();
		poseYTextbox->Text = poseGrid->Rows[i]->Cells[1]->Value->ToString();
		poseThetaTextbox->Text = poseGrid->Rows[i]->Cells[2]->Value->ToString();
		poseVelocityTextbox->Text = poseGrid->Rows[i]->Cells[3]->Value->ToString();
		poseAccelTextbox->Text = poseGrid->Rows[i]->Cells[4]->Value->ToString();
		poseJerkTextbox->Text = poseGrid->Rows[i]->Cells[5]->Value->ToString();
	}
	private: System::Void poseGrid_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		int i = poseGrid->CurrentCell->RowIndex;
		poseXTextbox->Text = poseGrid->Rows[i]->Cells[0]->Value->ToString();
		poseYTextbox->Text = poseGrid->Rows[i]->Cells[1]->Value->ToString();
		poseThetaTextbox->Text = poseGrid->Rows[i]->Cells[2]->Value->ToString();
		poseVelocityTextbox->Text = poseGrid->Rows[i]->Cells[3]->Value->ToString();
		poseAccelTextbox->Text = poseGrid->Rows[i]->Cells[4]->Value->ToString();
		poseJerkTextbox->Text = poseGrid->Rows[i]->Cells[5]->Value->ToString();
	}

	private: System::Void AddRowButton_Click(System::Object^ sender, System::EventArgs^ e) {
		poseGrid->Rows->Add(poseXTextbox->Text, poseYTextbox->Text, poseThetaTextbox->Text, poseVelocityTextbox->Text, poseAccelTextbox->Text, poseJerkTextbox->Text);
		coordinates.clear();
		this->Refresh();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (poseGrid->Rows->Count > 0)
			poseGrid->Rows->RemoveAt(poseGrid->CurrentCell->RowIndex);
		coordinates.clear();
		this->Refresh();
	}
	private: System::Void UpdateRowButton_Click(System::Object^ sender, System::EventArgs^ e) {
		poseGrid->CurrentRow->SetValues(poseXTextbox->Text, poseYTextbox->Text, poseThetaTextbox->Text, poseVelocityTextbox->Text, poseAccelTextbox->Text, poseJerkTextbox->Text);
		coordinates.clear();
		this->Refresh();
	}
	private: System::Void InsertRowButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (poseGrid->Rows->Count == 0)
			poseGrid->Rows->Add(poseXTextbox->Text, poseYTextbox->Text, poseThetaTextbox->Text, poseVelocityTextbox->Text, poseAccelTextbox->Text, poseJerkTextbox->Text);
		else
			poseGrid->Rows->Insert(poseGrid->CurrentCell->RowIndex + 1, poseXTextbox->Text, poseYTextbox->Text, poseThetaTextbox->Text, poseVelocityTextbox->Text, poseAccelTextbox->Text, poseJerkTextbox->Text);
		coordinates.clear();
		this->Refresh();
	}
	private: System::Void ToggleViewButton_Click(System::Object^ sender, System::EventArgs^ e) {
	FilePreviewTextbox->Enabled = !FilePreviewTextbox->Enabled;
	FilePreviewTextbox->Visible = !FilePreviewTextbox->Visible;
	this->Refresh();
}
	private: System::Void HideArrowButton_Click(System::Object^ sender, System::EventArgs^ e) {
		hideArrows = !hideArrows;
		this->Refresh();
	}
	private: System::Void FindHeaderFileButton_Click(System::Object^ sender, System::EventArgs^ e) {
		openFileDialog->ShowDialog();
		HeaderLocationTextbox->Text = openFileDialog->FileName;

		std::string location = toStandardString(HeaderLocationTextbox->Text);
		std::filesystem::path p(location);
		std::string ext = p.extension().string();
		if (ext == ".hpp" || ext == ".h") {

		}
		else {
			HeaderLocationTextbox->Text = "";
		}
	}

	private: System::Void ControlVectorCheckBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			   if (ControlVectorCheckBox->Checked) {
				   poseVelocityTextbox->Text = "0";
				   poseAccelTextbox->Text = "0";
				   poseJerkTextbox->Text = "0";

				   poseVelocityTextbox->ReadOnly = false;
				   poseAccelTextbox->ReadOnly = false;
				   poseJerkTextbox->ReadOnly = false;

				   FastGenerationCheckbox->AutoCheck = false;
			   }
			   else {
				   poseVelocityTextbox->Text = "-";
				   poseAccelTextbox->Text = "-";
				   poseJerkTextbox->Text = "-";

				   poseVelocityTextbox->ReadOnly = true;
				   poseAccelTextbox->ReadOnly = true;
				   poseJerkTextbox->ReadOnly = true;

				   FastGenerationCheckbox->AutoCheck = true;
			   }
			   while (poseGrid->Rows->Count > 0) {

				   poseGrid->Rows->RemoveAt(poseGrid->Rows->Count - 1);

			   }
			   this->Refresh();

		   }
#pragma endregion

#pragma region Callbacks
	private: System::Void saveWork() {
		std::ofstream myfile;
		myfile.open("settings.txt");
		myfile << toStandardString(MaxVelocityTextbox->Text) + "\n"
			+ toStandardString(MaxAccelTextbox->Text) + "\n"
			+ toStandardString(MaxJerkTextbox->Text) + "\n"
			+ toStandardString(RobotWidthTextbox->Text) + "\n"
			+ toStandardString(PathNameTextbox->Text) + "\n"
			+ toStandardString(TimeStepTextbox->Text) + "\n"
			+ toStandardString(ExportLocationTextbox->Text) + "\n"
			+ toStandardString(HeaderLocationTextbox->Text) + "\n";
		myfile.close();
	}
	private: System::Void loadWork() {
		std::ifstream fileSource("settings.txt"); // Creates an input file stream

		if (!fileSource) {
			std::ofstream myfile;
			myfile.open("settings.txt");
			std::string defaultFile = "1\n1\n2\n0.4\nPath\n0.1\n\n";
			myfile << defaultFile;
			myfile.close();
			loadWork();
		}
		else {

			std::string myText;
			std::string total = "";

			// Read from the text file
			int index = 0;
			std::ifstream MyReadFile("settings.txt");

			// Use a while loop together with the getline() function to read the file line by line
			while (getline(MyReadFile, myText)) {
				if (index == 0)
					MaxVelocityTextbox->Text = gcnew String(myText.c_str());
				else if (index == 1)
					MaxAccelTextbox->Text = gcnew String(myText.c_str());
				else if (index == 2)
					MaxJerkTextbox->Text = gcnew String(myText.c_str());
				else if (index == 3)
					RobotWidthTextbox->Text = gcnew String(myText.c_str());
				else if (index == 4)
					PathNameTextbox->Text = gcnew String(myText.c_str());
				else if (index == 5)
					TimeStepTextbox->Text = gcnew String(myText.c_str());
				else if (index == 6)
					ExportLocationTextbox->Text = gcnew String(myText.c_str());
				else if (index == 7)
					HeaderLocationTextbox->Text = gcnew String(myText.c_str());
				index++;
			}
			// Intermediate myText

			fileName = toStandardString(MaxVelocityTextbox->Text);
			std::string location = toStandardString(ExportLocationTextbox->Text);
			if (fileExists(location) && (location.substr(location.find_last_of(".") + 1) == "cpp" || location.substr(location.find_last_of(".") + 1) == "c")) {
				DataTypeTextbox->ReadOnly = false;
				HeaderLocationTextbox->ReadOnly = false;
				FindHeaderFileButton->Enabled = true;
				DataTypeTextbox->Text = "double";
				arrayCheckBox->Checked = true;
				arrayCheckBox->AutoCheck = true;
			}
			else {
				DataTypeTextbox->ReadOnly = true;
				HeaderLocationTextbox->ReadOnly = false;
				FindHeaderFileButton->Enabled = false;
				HeaderLocationTextbox->Text = "";
				DataTypeTextbox->Text = "";
				arrayCheckBox->Checked = false;
				arrayCheckBox->AutoCheck = false;
			}
			

			// By default, the >> operator reads word by workd (till whitespace)
		}
	}
	private: System::Void exportData() {
		auto constraints = Constraints(std::stod(toStandardString(MaxVelocityTextbox->Text)), std::stod(toStandardString(MaxAccelTextbox->Text)), std::stod(toStandardString(MaxJerkTextbox->Text)));
		auto model = std::make_shared<TankModel>(std::stod(toStandardString(RobotWidthTextbox->Text)), constraints);
		auto spline = SplineGenerator(constraints, model, std::stod(toStandardString(TimeStepTextbox->Text)));
		std::vector<squiggles::ProfilePoint> path;
		if (ControlVectorCheckBox->Checked) {
			std::vector<ControlVector> waypoints;
			for (int i = 0; i < poseGrid->Rows->Count; i++) {
				auto pose = Pose(std::stod(toStandardString(poseGrid->Rows[i]->Cells[0]->Value->ToString())),
					std::stod(toStandardString(poseGrid->Rows[i]->Cells[1]->Value->ToString())),
					std::stod(toStandardString(poseGrid->Rows[i]->Cells[2]->Value->ToString())));
				auto controlVector = ControlVector(pose,
					std::stod(toStandardString(poseGrid->Rows[i]->Cells[3]->Value->ToString())),
					std::stod(toStandardString(poseGrid->Rows[i]->Cells[4]->Value->ToString())),
					std::stod(toStandardString(poseGrid->Rows[i]->Cells[5]->Value->ToString())));
				waypoints.push_back(controlVector);
			}
			try { path = spline.generate(waypoints); }
			catch (const std::runtime_error& ex) {
				MessageBox::Show(gcnew String(ex.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}

		}
		else {
			std::vector<Pose> waypoints;
			for (int i = 0; i < poseGrid->Rows->Count; i++) {
				auto pose = Pose(std::stod(toStandardString(poseGrid->Rows[i]->Cells[0]->Value->ToString())),
					std::stod(toStandardString(poseGrid->Rows[i]->Cells[1]->Value->ToString())),
					std::stod(toStandardString(poseGrid->Rows[i]->Cells[2]->Value->ToString())));
				waypoints.push_back(pose);
			}
			try { path = spline.generate(waypoints, FastGenerationCheckbox->Checked); }
			catch (...) {
				Application::Exit();
			}

		}
		std::string location = toStandardString(ExportLocationTextbox->Text);
		std::filesystem::path p(location);
		std::string ext = p.extension().string();

		std::ofstream myfile;
		if (ext == ".txt") {
			std::ofstream myfile;
			myfile.open(location, std::ios_base::app);
			serialize_path(myfile, path);
			myfile.close();
		}
		else if (ext == ".cpp" || ext== ".c") {
			std::ofstream myfile;
			myfile.open(location, std::ios_base::app);
			if (arrayCheckBox->Checked)
				serialize_path_array_formatDim(myfile, path, toStandardString(DataTypeTextbox->Text) + " " + toStandardString(PathNameTextbox->Text));
			else
				serialize_path_array_format(myfile, path, toStandardString(DataTypeTextbox->Text) + " " + toStandardString(PathNameTextbox->Text) + " = {");
			myfile.close();

			std::string hlocation = toStandardString(HeaderLocationTextbox->Text);
			std::filesystem::path hp(hlocation);
			std::string ext2 = hp.extension().string();

			if (ext2 == ".hpp" || ext2 == ".h") {
				std::ofstream afile;
				afile.open(hlocation, std::ios_base::app);
				if (arrayCheckBox->Checked)
					serialize_path_header2D(afile, path,"extern " + toStandardString(DataTypeTextbox->Text) + " " + toStandardString(PathNameTextbox->Text));
				else
					serialize_path_headerCustom(afile, path, "extern " + toStandardString(DataTypeTextbox->Text) + " " + toStandardString(PathNameTextbox->Text) + ";\n");
				afile.close();
			}
		}
		else if (ext == ".cpp" || ext== ".c") {
			std::ofstream myfile;
			myfile.open(location, std::ios_base::app);
			if (arrayCheckBox->Checked)
				serialize_path_array_formatDim(myfile, path, toStandardString(DataTypeTextbox->Text) + " " + toStandardString(PathNameTextbox->Text));
			else
				serialize_path_array_format(myfile, path, toStandardString(DataTypeTextbox->Text) + " " + toStandardString(PathNameTextbox->Text) + " = {");
			myfile.close();

			std::string hlocation = toStandardString(HeaderLocationTextbox->Text);
			std::filesystem::path hp(location);
			std::string hext = hp.extension().string();

			if (hext == ".hpp" || hext == ".h") {
				std::ofstream afile;
				afile.open(hlocation, std::ios_base::app);
				if (arrayCheckBox->Checked)
					serialize_path_header2D(afile, path,"extern " + toStandardString(DataTypeTextbox->Text) + " " + toStandardString(PathNameTextbox->Text));
				else
					serialize_path_headerCustom(afile, path, "extern " + toStandardString(DataTypeTextbox->Text) + " " + toStandardString(PathNameTextbox->Text) + ";");
				afile.close();
			}
		}
	}
	private: System::Void generateData() {
		auto constraints = Constraints(std::stod(toStandardString(MaxVelocityTextbox->Text)), std::stod(toStandardString(MaxAccelTextbox->Text)), std::stod(toStandardString(MaxJerkTextbox->Text)));
		auto model = std::make_shared<TankModel>(std::stod(toStandardString(RobotWidthTextbox->Text)), constraints);
		auto spline = SplineGenerator(constraints, model, std::stod(toStandardString(TimeStepTextbox->Text)));
		std::vector<squiggles::ProfilePoint> path;
		if (ControlVectorCheckBox->Checked) {
			std::vector<ControlVector> waypoints;
			for (int i = 0; i < poseGrid->Rows->Count; i++) {
				auto pose = Pose(std::stod(toStandardString(poseGrid->Rows[i]->Cells[0]->Value->ToString())),
					std::stod(toStandardString(poseGrid->Rows[i]->Cells[1]->Value->ToString())),
					std::stod(toStandardString(poseGrid->Rows[i]->Cells[2]->Value->ToString())));
				auto controlVector = ControlVector(pose,
					std::stod(toStandardString(poseGrid->Rows[i]->Cells[3]->Value->ToString())),
					std::stod(toStandardString(poseGrid->Rows[i]->Cells[4]->Value->ToString())),
					std::stod(toStandardString(poseGrid->Rows[i]->Cells[5]->Value->ToString())));
				waypoints.push_back(controlVector);
			}
			try { path = spline.generate(waypoints); }
			catch (const std::runtime_error& ex) {
				MessageBox::Show(gcnew String(ex.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}

		}
		else {
			std::vector<Pose> waypoints;
			for (int i = 0; i < poseGrid->Rows->Count; i++) {
				auto pose = Pose(std::stod(toStandardString(poseGrid->Rows[i]->Cells[0]->Value->ToString())),
					std::stod(toStandardString(poseGrid->Rows[i]->Cells[1]->Value->ToString())),
					std::stod(toStandardString(poseGrid->Rows[i]->Cells[2]->Value->ToString())));
				waypoints.push_back(pose);
			}
			try { path = spline.generate(waypoints, FastGenerationCheckbox->Checked); }
			catch (...) {
				Application::Exit();
			}

		}

		coordinates.clear();
		for (auto p : path) {
			coordinates.push_back(p.vector.pose.x);
			coordinates.push_back(p.vector.pose.y);
		}

		std::string location = "intermediate.txt";
		std::ofstream myfile;
		myfile.open(location);
		serialize_path(myfile, path);
		myfile.close();

		std::string myText;
		std::string total = "";

		// Read from the text file
		std::ifstream MyReadFile(location);

		// Use a while loop together with the getline() function to read the file line by line
		while (getline(MyReadFile, myText)) {
			// Output the text from the file
			total += myText + "\r\n";
		}

		// Close the file
		MyReadFile.close();
		FilePreviewTextbox->Text = gcnew String(total.c_str());
		this->Refresh();

	}
	private: System::Void SquigglesInterface_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			   if (!hide) {
				   Graphics^ g = e->Graphics;
				   g->SmoothingMode = Drawing2D::SmoothingMode::None;
				   g->FillRectangle(Brushes::SteelBlue, 200, 38, 432, 432);

				   double inc = 0;
				   double inc2 = 0;
				   for (int i = 0; i < 6; i++) {

					   for (int j = 0; j < 3; j++) {
						   if (i % 2) {
							   g->FillRectangle(Brushes::CadetBlue, 200 + inc, 38 + inc2, 72, 72);
						   }
						   else {
							   g->FillRectangle(Brushes::CadetBlue, 200 + inc, 110 + inc2, 72, 72);
						   }
						   inc2 += 144;
					   }
					   inc2 = 0;
					   inc += 72;
				   }

				   g->SmoothingMode = Drawing2D::SmoothingMode::HighQuality;

				   Pen^ greenPen = gcnew Pen(Color::Green, 3);
				   Pen^ purplePen = gcnew Pen(Color::Purple, 3);
				   System::Drawing::Drawing2D::AdjustableArrowCap^ bigArrow = gcnew System::Drawing::Drawing2D::AdjustableArrowCap(3, 3, true);
				   purplePen->CustomEndCap = bigArrow;

				   Point point1 = Point(-10, -10);
				   Point point2 = Point(-10, -19);

				   array<Point>^ curvePoints;
				   if (coordinates.size() > 2) {
					   curvePoints = gcnew array<Point>((coordinates.size() / 2) + 1);
					   int curveIndex = 0;
					   for (int i = 0; i < coordinates.size() - 1; i++) {
						   double xOffset = meterToInch(coordinates[i]) * 3;
						   double yOffset = 432 - meterToInch(coordinates[i + 1]) * 3;
						   Point p = Point(200 + xOffset, 38 + yOffset);
						   curvePoints[curveIndex] = p;
						   curveIndex++;
						   i++;
					   }

					   double xOffset = meterToInch(std::stod(toStandardString(poseGrid->Rows[poseGrid->Rows->Count - 1]->Cells[0]->Value->ToString()))) * 3 - 0;
					   double yOffset = 432 - meterToInch(std::stod(toStandardString(poseGrid->Rows[poseGrid->Rows->Count - 1]->Cells[1]->Value->ToString()))) * 3 - 0;
					   Point p = Point(200 + xOffset, 38 + yOffset);
					   curvePoints[curveIndex] = p;

					   //g->FillEllipse(Brushes::Purple, 200 + xOffset, 38 + yOffset, 3, 3);
				   }
				   else
					   curvePoints = gcnew array<Point>(2) { point1, point2 };

				   // Draw lines between original points to screen.
				   e->Graphics->DrawLines(greenPen, curvePoints);



				   for (int i = 0; i < poseGrid->Rows->Count; i++) {
					   double xOffset = meterToInch(std::stod(toStandardString(poseGrid->Rows[i]->Cells[0]->Value->ToString()))) * 3 - 5;
					   double yOffset = meterToInch(std::stod(toStandardString(poseGrid->Rows[i]->Cells[1]->Value->ToString()))) * 3 - 5;
					   double theta = (std::stod(toStandardString(poseGrid->Rows[i]->Cells[2]->Value->ToString())));
					   double scalar = 30;
					   g->FillEllipse(Brushes::Purple, 200 + xOffset, 460 - yOffset, 11, 11);
					   if (!hideArrows)
						   e->Graphics->DrawLine(purplePen, 205 + xOffset, 465 - yOffset, int(205 + xOffset + scalar * cos(theta)), int(465 - yOffset - scalar * sin(theta)));
				   }


			   }
			   // Draw curve to screen.
			   //e->Graphics->DrawCurve(greenPen, curvePoints);
		   }
#pragma endregion

#pragma region Util
	private: inline bool fileExists(const std::string& name) {
		struct stat myText;
		return (stat(name.c_str(), &myText) == 0);
	}
	static std::string toStandardString(System::String^ string)
		   {
			   using System::Runtime::InteropServices::Marshal;
			   System::IntPtr pointer = Marshal::StringToHGlobalAnsi(string);
			   char* charPointer = reinterpret_cast<char*>(pointer.ToPointer());
			   std::string returnString(charPointer, string->Length);
			   Marshal::FreeHGlobal(pointer);
			   return returnString;
		   }
	private: bool consecutivePointsOverlap() {
		//label4->Text = poseGrid->Rows[0]->Cells[0];
		for (int i = 0; i < poseGrid->Rows->Count - 1; i++) {

			if (std::stod(toStandardString(poseGrid->Rows[i]->Cells[0]->Value->ToString())) == std::stod(toStandardString(poseGrid->Rows[i + 1]->Cells[0]->Value->ToString()))) {
				if (std::stod(toStandardString(poseGrid->Rows[i]->Cells[1]->Value->ToString())) == std::stod(toStandardString(poseGrid->Rows[i + 1]->Cells[1]->Value->ToString()))) {
					return true;
				}
			}
		}
		return false;
	}
	private: double inchToMeter(double inch) {
		return inch / 39.37;
	}
	private: double meterToInch(double meter) {
		return meter * 39.37;
	}
	private: double degToRad(double deg) {
		return (deg * pi) / 180;
	}
#pragma endregion

#pragma region Startup
	private: System::Void startupTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		startupTimer->Stop();
		startupAnimation->Visible = false;
	}
	private: System::Void SquigglesInterface_Load(System::Object^ sender, System::EventArgs^ e) {
		startupTimer->Start();
	}
#pragma endregion
	
};
}
