#pragma once
#include <iostream>
#include <fstream>
#include <msclr/marshal_cppstd.h>
#include <string>
#include <vector>
#include <list>
#include <math.h>
namespace SimPag {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System::IO;
	using namespace System::Collections::Generic;

	




	/// <summary>
	/// Sumário para TelaSim
	/// </summary>
	public ref class TelaSim : public System::Windows::Forms::Form
	{
	public:

		ref struct Processo {
			String^ ID;
			int tempo_cria;
			int tempo_remove;
			double tam;
			int tempo_na_fila = 0;
		};
		ref struct Pagina {
			bool ocupado;
			Processo ^processo;
			int listbox;
		};

		TelaSim(void)
		{
			InitializeComponent();
			//
			//TODO: Adicione o código do construtor aqui
			//
		}
		TelaSim(String^ diretorio, String^ pag, String^ mem, int ordem_fila) {

			this->diretorio = diretorio;
			InitializeComponent();
			InitializaVariaveis(diretorio, pag, mem, ordem_fila);

			
		}

	protected:
		/// <summary>
		/// Limpar os recursos que estão sendo usados.
		/// </summary>
		~TelaSim()
		{
			if (components)
			{
				delete components;
			}
		}
	private: String ^ logSaida;
	private: int mem_usado = 0;
	private: int frag_inter = 0;
	private: int qtd_proc;
	private: double total_tempo_fila= 0;
	private: int proc_esperaram = 0;
	private: int proc_sem_esperar = 0;
	private: int maximo_proc = 0;
	private: List<Processo ^>^ lista_proce_mapa;
	private: String ^ diretorio;
	private: int aux_timer = 1;
	private: int qtd_pag_ocu = 0;
	private: int qtd_listBox;
	private: int tam_mem;
	private: int tam_pag;
	private: List <Pagina^>^ pag_mem;
	private: List<Processo^>^ lista_proc;
	private: int unidade_tempo = 0;
	private: int modo_fila;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label99;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::ListBox^  listBox_logSaida;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ListBox^  listbox_lista_proc;
	private: System::Windows::Forms::Label^  label1;


	private: System::Windows::Forms::Label^  lb_qtd_lista_proc;
	private: System::Windows::Forms::Label^  lb_qtd_log;

	private: System::Windows::Forms::Label^  lb_unidade_tempo;
	private: System::Windows::Forms::Label^  lb_pag_livre;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  lb_tam_pag;
	private: System::Windows::Forms::Label^  lb_tam_mem;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ListBox^  listBox3;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::ListBox^  listBox2;
	private: System::Windows::Forms::Label^  lb_qtd_mapa;
	private: System::Windows::Forms::ListBox^  listBox4;
	private: System::Windows::Forms::ListBox^  listBox6;
	private: System::Windows::Forms::ListBox^  listBox5;
	private: System::Windows::Forms::ListBox^  listBox7;
	private: System::Windows::Forms::ListBox^  listBox8;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  lb_precisam_esperar;

	private: System::Windows::Forms::Label^  lb_nao_espera;

	private: System::Windows::Forms::Label^  lb_maximo_proc;

	private: System::Windows::Forms::Label^  lb_qtd_proc;


	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::Label^  lb_frag_externa;

private: System::Windows::Forms::Label^  lb_frag_interna;

private: System::Windows::Forms::Label^  lb_tempo_espera_parcial;

private: System::Windows::Forms::Label^  lb_tempo_de_espera_geral;


private: System::Windows::Forms::Label^  label19;
private: System::Windows::Forms::Label^  label18;
	private: System::ComponentModel::IContainer^  components;




	protected:

	private:
		/// <summary>
		/// Variável de designer necessária.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necessário para suporte ao Designer - não modifique 
		/// o conteúdo deste método com o editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label99 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->listBox_logSaida = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->listbox_lista_proc = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lb_qtd_lista_proc = (gcnew System::Windows::Forms::Label());
			this->lb_qtd_log = (gcnew System::Windows::Forms::Label());
			this->lb_unidade_tempo = (gcnew System::Windows::Forms::Label());
			this->lb_pag_livre = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->lb_tam_pag = (gcnew System::Windows::Forms::Label());
			this->lb_tam_mem = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->listBox3 = (gcnew System::Windows::Forms::ListBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->lb_qtd_mapa = (gcnew System::Windows::Forms::Label());
			this->listBox4 = (gcnew System::Windows::Forms::ListBox());
			this->listBox6 = (gcnew System::Windows::Forms::ListBox());
			this->listBox5 = (gcnew System::Windows::Forms::ListBox());
			this->listBox7 = (gcnew System::Windows::Forms::ListBox());
			this->listBox8 = (gcnew System::Windows::Forms::ListBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->lb_frag_externa = (gcnew System::Windows::Forms::Label());
			this->lb_frag_interna = (gcnew System::Windows::Forms::Label());
			this->lb_tempo_espera_parcial = (gcnew System::Windows::Forms::Label());
			this->lb_tempo_de_espera_geral = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->lb_precisam_esperar = (gcnew System::Windows::Forms::Label());
			this->lb_nao_espera = (gcnew System::Windows::Forms::Label());
			this->lb_maximo_proc = (gcnew System::Windows::Forms::Label());
			this->lb_qtd_proc = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(195, 443);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Iniciar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &TelaSim::button2_Click_1);
			// 
			// label99
			// 
			this->label99->AutoSize = true;
			this->label99->Location = System::Drawing::Point(8, 104);
			this->label99->Name = L"label99";
			this->label99->Size = System::Drawing::Size(97, 13);
			this->label99->TabIndex = 5;
			this->label99->Text = L"Unidade de tempo:";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(284, 443);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Reiniciar";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &TelaSim::button3_Click);
			// 
			// listBox_logSaida
			// 
			this->listBox_logSaida->FormattingEnabled = true;
			this->listBox_logSaida->Location = System::Drawing::Point(157, 37);
			this->listBox_logSaida->Name = L"listBox_logSaida";
			this->listBox_logSaida->Size = System::Drawing::Size(124, 212);
			this->listBox_logSaida->TabIndex = 6;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(183, 21);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(70, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Log de saída";
			// 
			// listbox_lista_proc
			// 
			this->listbox_lista_proc->FormattingEnabled = true;
			this->listbox_lista_proc->Location = System::Drawing::Point(19, 37);
			this->listbox_lista_proc->Name = L"listbox_lista_proc";
			this->listbox_lista_proc->Size = System::Drawing::Size(116, 212);
			this->listbox_lista_proc->TabIndex = 13;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(30, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(95, 13);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Lista de processos";
			// 
			// lb_qtd_lista_proc
			// 
			this->lb_qtd_lista_proc->AutoSize = true;
			this->lb_qtd_lista_proc->Location = System::Drawing::Point(66, 252);
			this->lb_qtd_lista_proc->Name = L"lb_qtd_lista_proc";
			this->lb_qtd_lista_proc->Size = System::Drawing::Size(19, 13);
			this->lb_qtd_lista_proc->TabIndex = 18;
			this->lb_qtd_lista_proc->Text = L"23";
			// 
			// lb_qtd_log
			// 
			this->lb_qtd_log->AutoSize = true;
			this->lb_qtd_log->Location = System::Drawing::Point(209, 252);
			this->lb_qtd_log->Name = L"lb_qtd_log";
			this->lb_qtd_log->Size = System::Drawing::Size(19, 13);
			this->lb_qtd_log->TabIndex = 19;
			this->lb_qtd_log->Text = L"23";
			// 
			// lb_unidade_tempo
			// 
			this->lb_unidade_tempo->AutoSize = true;
			this->lb_unidade_tempo->Location = System::Drawing::Point(180, 104);
			this->lb_unidade_tempo->Name = L"lb_unidade_tempo";
			this->lb_unidade_tempo->Size = System::Drawing::Size(19, 13);
			this->lb_unidade_tempo->TabIndex = 22;
			this->lb_unidade_tempo->Text = L"23";
			// 
			// lb_pag_livre
			// 
			this->lb_pag_livre->AutoSize = true;
			this->lb_pag_livre->Location = System::Drawing::Point(180, 73);
			this->lb_pag_livre->Name = L"lb_pag_livre";
			this->lb_pag_livre->Size = System::Drawing::Size(19, 13);
			this->lb_pag_livre->TabIndex = 24;
			this->lb_pag_livre->Text = L"23";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(8, 73);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(145, 13);
			this->label8->TabIndex = 23;
			this->label8->Text = L"Quantidade de páginas livre: ";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(8, 13);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(118, 13);
			this->label9->TabIndex = 25;
			this->label9->Text = L"Tamanho das páginas: ";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(8, 42);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(156, 13);
			this->label10->TabIndex = 26;
			this->label10->Text = L"Tamanho do mapa de memória:";
			// 
			// lb_tam_pag
			// 
			this->lb_tam_pag->AutoSize = true;
			this->lb_tam_pag->Location = System::Drawing::Point(180, 13);
			this->lb_tam_pag->Name = L"lb_tam_pag";
			this->lb_tam_pag->Size = System::Drawing::Size(19, 13);
			this->lb_tam_pag->TabIndex = 27;
			this->lb_tam_pag->Text = L"23";
			// 
			// lb_tam_mem
			// 
			this->lb_tam_mem->AutoSize = true;
			this->lb_tam_mem->Location = System::Drawing::Point(180, 42);
			this->lb_tam_mem->Name = L"lb_tam_mem";
			this->lb_tam_mem->Size = System::Drawing::Size(19, 13);
			this->lb_tam_mem->TabIndex = 28;
			this->lb_tam_mem->Text = L"23";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(378, 443);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 29;
			this->button1->Text = L"Sair";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &TelaSim::button1_Click);
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->label10);
			this->panel1->Controls->Add(this->label99);
			this->panel1->Controls->Add(this->lb_tam_mem);
			this->panel1->Controls->Add(this->lb_unidade_tempo);
			this->panel1->Controls->Add(this->lb_tam_pag);
			this->panel1->Controls->Add(this->label8);
			this->panel1->Controls->Add(this->lb_pag_livre);
			this->panel1->Controls->Add(this->label9);
			this->panel1->Location = System::Drawing::Point(19, 284);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(225, 141);
			this->panel1->TabIndex = 30;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(453, 21);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(120, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Mapa de memória física";
			// 
			// listBox3
			// 
			this->listBox3->FormattingEnabled = true;
			this->listBox3->Location = System::Drawing::Point(408, 37);
			this->listBox3->Name = L"listBox3";
			this->listBox3->Size = System::Drawing::Size(52, 212);
			this->listBox3->TabIndex = 8;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(460, 37);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(52, 212);
			this->listBox1->TabIndex = 9;
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->Location = System::Drawing::Point(512, 37);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(52, 212);
			this->listBox2->TabIndex = 10;
			// 
			// lb_qtd_mapa
			// 
			this->lb_qtd_mapa->AutoSize = true;
			this->lb_qtd_mapa->Location = System::Drawing::Point(502, 252);
			this->lb_qtd_mapa->Name = L"lb_qtd_mapa";
			this->lb_qtd_mapa->Size = System::Drawing::Size(19, 13);
			this->lb_qtd_mapa->TabIndex = 20;
			this->lb_qtd_mapa->Tag = L"Quantidade de processos";
			this->lb_qtd_mapa->Text = L"23";
			// 
			// listBox4
			// 
			this->listBox4->FormattingEnabled = true;
			this->listBox4->Location = System::Drawing::Point(564, 37);
			this->listBox4->Name = L"listBox4";
			this->listBox4->Size = System::Drawing::Size(52, 212);
			this->listBox4->TabIndex = 11;
			// 
			// listBox6
			// 
			this->listBox6->FormattingEnabled = true;
			this->listBox6->Location = System::Drawing::Point(616, 37);
			this->listBox6->Name = L"listBox6";
			this->listBox6->Size = System::Drawing::Size(52, 212);
			this->listBox6->TabIndex = 12;
			// 
			// listBox5
			// 
			this->listBox5->FormattingEnabled = true;
			this->listBox5->Location = System::Drawing::Point(356, 37);
			this->listBox5->Name = L"listBox5";
			this->listBox5->Size = System::Drawing::Size(52, 212);
			this->listBox5->TabIndex = 31;
			// 
			// listBox7
			// 
			this->listBox7->FormattingEnabled = true;
			this->listBox7->Location = System::Drawing::Point(301, 37);
			this->listBox7->Name = L"listBox7";
			this->listBox7->Size = System::Drawing::Size(55, 212);
			this->listBox7->TabIndex = 32;
			// 
			// listBox8
			// 
			this->listBox8->FormattingEnabled = true;
			this->listBox8->Location = System::Drawing::Point(668, 37);
			this->listBox8->Name = L"listBox8";
			this->listBox8->Size = System::Drawing::Size(52, 212);
			this->listBox8->TabIndex = 33;
			// 
			// timer1
			// 
			this->timer1->Interval = 2000;
			this->timer1->Tick += gcnew System::EventHandler(this, &TelaSim::timer1_Tick);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(668, 443);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->ReadOnly = true;
			this->numericUpDown1->Size = System::Drawing::Size(52, 20);
			this->numericUpDown1->TabIndex = 34;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(534, 445);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(128, 13);
			this->label4->TabIndex = 29;
			this->label4->Text = L"Velocidade da simulação:";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->lb_frag_externa);
			this->groupBox1->Controls->Add(this->lb_frag_interna);
			this->groupBox1->Controls->Add(this->lb_tempo_espera_parcial);
			this->groupBox1->Controls->Add(this->lb_tempo_de_espera_geral);
			this->groupBox1->Controls->Add(this->label19);
			this->groupBox1->Controls->Add(this->label18);
			this->groupBox1->Controls->Add(this->label17);
			this->groupBox1->Controls->Add(this->label16);
			this->groupBox1->Controls->Add(this->lb_precisam_esperar);
			this->groupBox1->Controls->Add(this->lb_nao_espera);
			this->groupBox1->Controls->Add(this->lb_maximo_proc);
			this->groupBox1->Controls->Add(this->lb_qtd_proc);
			this->groupBox1->Controls->Add(this->label11);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Location = System::Drawing::Point(301, 284);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(419, 141);
			this->groupBox1->TabIndex = 35;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Resultado da simulação";
			this->groupBox1->Visible = false;
			// 
			// lb_frag_externa
			// 
			this->lb_frag_externa->AutoSize = true;
			this->lb_frag_externa->Location = System::Drawing::Point(388, 101);
			this->lb_frag_externa->Name = L"lb_frag_externa";
			this->lb_frag_externa->Size = System::Drawing::Size(13, 13);
			this->lb_frag_externa->TabIndex = 41;
			this->lb_frag_externa->Text = L"0";
			// 
			// lb_frag_interna
			// 
			this->lb_frag_interna->AutoSize = true;
			this->lb_frag_interna->Location = System::Drawing::Point(388, 76);
			this->lb_frag_interna->Name = L"lb_frag_interna";
			this->lb_frag_interna->Size = System::Drawing::Size(13, 13);
			this->lb_frag_interna->TabIndex = 40;
			this->lb_frag_interna->Text = L"0";
			// 
			// lb_tempo_espera_parcial
			// 
			this->lb_tempo_espera_parcial->AutoSize = true;
			this->lb_tempo_espera_parcial->Location = System::Drawing::Point(388, 52);
			this->lb_tempo_espera_parcial->Name = L"lb_tempo_espera_parcial";
			this->lb_tempo_espera_parcial->Size = System::Drawing::Size(13, 13);
			this->lb_tempo_espera_parcial->TabIndex = 39;
			this->lb_tempo_espera_parcial->Text = L"0";
			// 
			// lb_tempo_de_espera_geral
			// 
			this->lb_tempo_de_espera_geral->AutoSize = true;
			this->lb_tempo_de_espera_geral->Location = System::Drawing::Point(388, 26);
			this->lb_tempo_de_espera_geral->Name = L"lb_tempo_de_espera_geral";
			this->lb_tempo_de_espera_geral->Size = System::Drawing::Size(13, 13);
			this->lb_tempo_de_espera_geral->TabIndex = 38;
			this->lb_tempo_de_espera_geral->Text = L"0";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(217, 101);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(119, 13);
			this->label19->TabIndex = 37;
			this->label19->Text = L"Fragmentação externa: ";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(217, 74);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(116, 13);
			this->label18->TabIndex = 36;
			this->label18->Text = L"Fragmentação interna: ";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(217, 52);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(161, 13);
			this->label17->TabIndex = 35;
			this->label17->Text = L"Tempo médio de esperar parcial:";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(217, 26);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(153, 13);
			this->label16->TabIndex = 34;
			this->label16->Text = L"Tempo médio de espera geral: ";
			// 
			// lb_precisam_esperar
			// 
			this->lb_precisam_esperar->AutoSize = true;
			this->lb_precisam_esperar->Location = System::Drawing::Point(172, 101);
			this->lb_precisam_esperar->Name = L"lb_precisam_esperar";
			this->lb_precisam_esperar->Size = System::Drawing::Size(13, 13);
			this->lb_precisam_esperar->TabIndex = 33;
			this->lb_precisam_esperar->Text = L"0";
			// 
			// lb_nao_espera
			// 
			this->lb_nao_espera->AutoSize = true;
			this->lb_nao_espera->Location = System::Drawing::Point(172, 76);
			this->lb_nao_espera->Name = L"lb_nao_espera";
			this->lb_nao_espera->Size = System::Drawing::Size(13, 13);
			this->lb_nao_espera->TabIndex = 32;
			this->lb_nao_espera->Text = L"0";
			// 
			// lb_maximo_proc
			// 
			this->lb_maximo_proc->AutoSize = true;
			this->lb_maximo_proc->Location = System::Drawing::Point(172, 52);
			this->lb_maximo_proc->Name = L"lb_maximo_proc";
			this->lb_maximo_proc->Size = System::Drawing::Size(13, 13);
			this->lb_maximo_proc->TabIndex = 31;
			this->lb_maximo_proc->Text = L"0";
			// 
			// lb_qtd_proc
			// 
			this->lb_qtd_proc->AutoSize = true;
			this->lb_qtd_proc->Location = System::Drawing::Point(172, 26);
			this->lb_qtd_proc->Name = L"lb_qtd_proc";
			this->lb_qtd_proc->Size = System::Drawing::Size(13, 13);
			this->lb_qtd_proc->TabIndex = 30;
			this->lb_qtd_proc->Text = L"0";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(8, 101);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(103, 13);
			this->label11->TabIndex = 29;
			this->label11->Text = L"Precisaram esperar: ";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(7, 76);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(122, 13);
			this->label7->TabIndex = 28;
			this->label7->Text = L"Não precisaram esperar:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 52);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(144, 13);
			this->label6->TabIndex = 27;
			this->label6->Text = L"Máximo de proc. simultâneo: ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 26);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(82, 13);
			this->label5->TabIndex = 26;
			this->label5->Text = L"Qntd processo: ";
			// 
			// TelaSim
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(742, 478);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->listBox8);
			this->Controls->Add(this->listBox7);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->listBox5);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listBox6);
			this->Controls->Add(this->lb_qtd_log);
			this->Controls->Add(this->listBox4);
			this->Controls->Add(this->lb_qtd_mapa);
			this->Controls->Add(this->lb_qtd_lista_proc);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->listBox3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->listbox_lista_proc);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->listBox_logSaida);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(758, 516);
			this->MinimumSize = System::Drawing::Size(758, 516);
			this->Name = L"TelaSim";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"TelaSim";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		public: void InitializaVariaveis(String^ diretorio, String^ pag, String^ mem, int ordem_fila) {
			// Inicializa listas e afins
			this->modo_fila = ordem_fila;
			try {
				StreamReader^ arq = gcnew StreamReader(diretorio);
				try {
					String^ line;
					line = arq->ReadLine();
					string aux;
					vector <string> linha;
					lista_proc = gcnew List<Processo^>();

					while (line = arq->ReadLine())
					{
						
						aux = msclr::interop::marshal_as< std::string >(line);
						linha = explode(aux, ',');
						String ^linha1 = msclr::interop::marshal_as< System::String^ >(" " + linha[0] + " - " + linha[1] + " - " + linha[2] + " - " + linha[3]);
						listbox_lista_proc->Items->Add(linha1);
						Processo^ processo = gcnew Processo();
						processo->ID = msclr::interop::marshal_as< System::String^ >(linha[0]);
						processo->tempo_cria = std::stoi(linha[1]);
						processo->tempo_remove = std::stoi(linha[2]) - processo->tempo_cria - 1;
						processo->tam = std::stoi(linha[3]);
						lista_proc->Add(processo);
					}

					lb_qtd_lista_proc->Text = listbox_lista_proc->Items->Count.ToString();
					lb_qtd_proc->Text = lista_proc->Count.ToString();
					this->qtd_proc = lista_proc->Count;
					arq->Close();
				}
				finally
				{
					if (arq)
					delete (IDisposable^)arq;
				}

			}
			catch (Exception^ e)
			{
				// Let the user know what went wrong.
				MessageBox::Show("Erro ao processar o arquivo " + diretorio + "\n" + e->Message);

			}




			tam_mem = System::Convert::ToInt32(mem);
			tam_pag = System::Convert::ToInt32(pag);
			double paginas = tam_mem / tam_pag;			// numero de páginas na memoria fisica

			Pagina ^bloco_mem;
			pag_mem = gcnew List<Pagina^>();
			int colun = ceil(paginas / 16.0);	// qtd de colunas
			qtd_listBox = colun;
			if (paginas == 4) {
				this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
					L" ", L" ", L" ", L" "
				});
				for (int j = 0; j < 4; j++) {
					bloco_mem = gcnew Pagina();
					bloco_mem->ocupado = false;
					pag_mem->Add(bloco_mem);
				}
			}
			else if (paginas == 8) {
				this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
					L" ", L" ", L" ", L" ", L" ", L" ", L" ", L" "
				});
				for (int j = 0; j < 8; j++) {
					bloco_mem = gcnew Pagina();
					bloco_mem->ocupado = false;
					pag_mem->Add(bloco_mem);
				}
			}
			else {
				this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(16) {
					L" ", L" ", L" ", L" ", L" ", L" ", L" ", L" ",
						L" ", L" ", L" ", L" ", L" ", L" ", L" ", L" "
				});
				for (int i = 0; i < colun; i++) {
					for (int j = 0; j < 16; j++) {
						bloco_mem = gcnew Pagina();
						bloco_mem->ocupado = false;
						pag_mem->Add(bloco_mem);
					}
				}
			}

			lista_proce_mapa = gcnew List<Processo^>();

			lb_unidade_tempo->Text = "0";
			lb_tam_mem->Text = mem;
			lb_tam_pag->Text = pag;
			lb_pag_livre->Text = paginas.ToString();
			lb_qtd_log->Text = "0";
			lb_qtd_mapa->Text = "0";

			this->listBox2->Items->AddRange(gcnew cli::array< System::Object^  >(16) {
				L" ", L" ", L" ", L" ", L" ", L" ", L" ", L" ",
					L" ", L" ", L" ", L" ", L" ", L" ", L" ", L" "
			});
			this->listBox3->Items->AddRange(gcnew cli::array< System::Object^  >(16) {
				L" ", L" ", L" ", L" ", L" ", L" ", L" ", L" ",
					L" ", L" ", L" ", L" ", L" ", L" ", L" ", L" "
			});
			this->listBox4->Items->AddRange(gcnew cli::array< System::Object^  >(16) {
				L" ", L" ", L" ", L" ", L" ", L" ", L" ", L" ",
					L" ", L" ", L" ", L" ", L" ", L" ", L" ", L" "
			});
			this->listBox5->Items->AddRange(gcnew cli::array< System::Object^  >(16) {
				L" ", L" ", L" ", L" ", L" ", L" ", L" ", L" ",
					L" ", L" ", L" ", L" ", L" ", L" ", L" ", L" "
			});
			this->listBox6->Items->AddRange(gcnew cli::array< System::Object^  >(16) {
				L" ", L" ", L" ", L" ", L" ", L" ", L" ", L" ",
					L" ", L" ", L" ", L" ", L" ", L" ", L" ", L" "
			});
			this->listBox7->Items->AddRange(gcnew cli::array< System::Object^  >(16) {
				L" ", L" ", L" ", L" ", L" ", L" ", L" ", L" ",
					L" ", L" ", L" ", L" ", L" ", L" ", L" ", L" "
			});
			this->listBox8->Items->AddRange(gcnew cli::array< System::Object^  >(16) {
				L" ", L" ", L" ", L" ", L" ", L" ", L" ", L" ",
					L" ", L" ", L" ", L" ", L" ", L" ", L" ", L" "
			});
			


			switch (colun)
			{
			case 1:
				this->lb_qtd_mapa->Location = System::Drawing::Point(479, 252);
				this->lb_qtd_mapa->Size = System::Drawing::Size(19, 13);	
				this->label3->Location = System::Drawing::Point(423, 21);
				this->label3->Size = System::Drawing::Size(120, 13);
				listBox2->Visible = false;
				listBox3->Visible = false;
				listBox4->Visible = false;
				listBox5->Visible = false;
				listBox6->Visible = false;
				listBox7->Visible = false;
				listBox8->Visible = false;
				break;
			case 2:
				listBox3->Visible = false;
				listBox4->Visible = false;
				listBox5->Visible = false;
				listBox6->Visible = false;
				listBox7->Visible = false;
				listBox8->Visible = false;
				break;
			case 4:
				listBox5->Visible = false;
				listBox6->Visible = false;
				listBox7->Visible = false;
				listBox8->Visible = false;
				break;

			default:
				break;
			}



		}
	public: vector<int> verifica_listbox(ListBox ^listbox) {
		vector <int> pos;
		int aux;
		while ((aux = listbox->FindString(" ")) != -1) {
			pos.push_back(aux);
		}
		return pos;
	}
	public: void insere_mapa(Processo^ processo) {

		int qtd_paginas = ceil(processo->tam / tam_pag);
		int tamanho_processo = processo->tam;
		int aux = 0, aux2 = 0, pos;
		for (int i = 0; i < qtd_paginas; i++) {
			for (int j = aux; j < pag_mem->Count; j++) {
				if (pag_mem[j]->ocupado != true) {
					pag_mem[j]->ocupado = true;
					Processo ^proc = gcnew Processo();
					proc->ID = processo->ID;
					proc->tempo_cria = processo->tempo_cria;
					proc->tempo_remove = processo->tempo_remove;
					pag_mem[j]->processo = proc;
					if (i == (qtd_paginas - 1)) {
						pag_mem[j]->processo->tam = tamanho_processo;
						mem_usado += tamanho_processo;
					}
					else {
						pag_mem[j]->processo->tam = tam_pag;
						mem_usado += tam_pag;
						tamanho_processo -= tam_pag;
					}
					listBox_logSaida->Items->Insert(0, unidade_tempo + "," + processo->ID + "," + j + ",ENTROU");
					logSaida += (unidade_tempo + "," + processo->ID + "," + j + ",ENTROU\n");
					aux = j;
					qtd_pag_ocu++;
					break;
				}

			}


			switch (qtd_listBox)
			{
			case 8:
				pos = listBox7->FindString(" ");
				if (pos != -1) {
					listBox7->Items[pos] = (pos, "P " + processo->ID + " - " + pag_mem[aux]->processo->tam.ToString());
					pag_mem[aux]->listbox = 7;
					break;
				}
				pos = listBox5->FindString(" ");
				if (pos != -1) {
					listBox5->Items[pos] = (pos, "P " + processo->ID + " - " + pag_mem[aux]->processo->tam.ToString());
					pag_mem[aux]->listbox = 5;
					break;
				}
				pos = listBox3->FindString(" ");
				if (pos != -1) {
					listBox3->Items[pos] = (pos, "P " + processo->ID + " - " + pag_mem[aux]->processo->tam.ToString());
					pag_mem[aux]->listbox = 3;
					break;
				}
				pos = listBox1->FindString(" ");
				if (pos != -1) {
					listBox1->Items[pos] = (pos, "P " + processo->ID + " - " + pag_mem[aux]->processo->tam.ToString());
					pag_mem[aux]->listbox = 1;
					break;
				}
				pos = listBox2->FindString(" ");
				if (pos != -1) {
					listBox2->Items[pos] = (pos, "P " + processo->ID + " - " + pag_mem[aux]->processo->tam.ToString());
					pag_mem[aux]->listbox = 2;
					break;
				}
				pos = listBox4->FindString(" ");
				if (pos != -1) {
					listBox4->Items[pos] = (pos, "P " + processo->ID + " - " + pag_mem[aux]->processo->tam.ToString());
					pag_mem[aux]->listbox = 4;
					break;
				}
				pos = listBox6->FindString(" ");
				if (pos != -1) {
					listBox6->Items[pos] = (pos, "P " + processo->ID + " - " + pag_mem[aux]->processo->tam.ToString());
					pag_mem[aux]->listbox = 6;
					break;
				}
				pos = listBox8->FindString(" ");
				if (pos != -1) {
					listBox8->Items[pos] = (pos, "P " + processo->ID + " - " + pag_mem[aux]->processo->tam.ToString());
					pag_mem[aux]->listbox = 8;
					break;
				}
				
			case 4:
				pos = listBox3->FindString(" ");
				if (pos != -1) {
					listBox3->Items[pos] = (pos, "P " + processo->ID + " - " + pag_mem[aux]->processo->tam.ToString());
					pag_mem[aux]->listbox = 3;
					break;
				}
				pos = listBox1->FindString(" ");
				if (pos != -1) {
					listBox1->Items[pos] = (pos, "P " + processo->ID + " - " + pag_mem[aux]->processo->tam.ToString());
					pag_mem[aux]->listbox = 1;
					break;
				}
				pos = listBox2->FindString(" ");
				if (pos != -1) {
					listBox2->Items[pos] = (pos, "P " + processo->ID + " - " + pag_mem[aux]->processo->tam.ToString());
					pag_mem[aux]->listbox = 2;
					break;
				}
				pos = listBox4->FindString(" ");
				if (pos != -1) {
					listBox4->Items[pos] = (pos, "P " + processo->ID + " - " + pag_mem[aux]->processo->tam.ToString());
					pag_mem[aux]->listbox = 4;
					break;
				}

			case 2:
				pos = listBox1->FindString(" ");
				if (pos != -1) {
					listBox1->Items[pos] = (pos, "P " + processo->ID + " - " + pag_mem[aux]->processo->tam.ToString());
					pag_mem[aux]->listbox = 1;
					break;
				}
				pos = listBox2->FindString(" ");
				if (pos != -1) {
					listBox2->Items[pos] = (pos, "P " + processo->ID + " - " + pag_mem[aux]->processo->tam.ToString());
					pag_mem[aux]->listbox = 2;
					break;
				}
			case 1:
				pos = listBox1->FindString(" ");
				if (pos != -1) {
					listBox1->Items[pos] = (pos, "P " + processo->ID + " - " + pag_mem[aux]->processo->tam.ToString());
					pag_mem[aux]->listbox = 1;
					break;
				}
			default:
				break;
			}

		}


	}

	public: void limpa_mem(Pagina ^pagina) {
		int pos;

		switch (qtd_listBox)
		{
		case 8:
			if (pagina->listbox == 7) {
				pos = listBox7->FindString("P " + pagina->processo->ID + " - " + pagina->processo->tam.ToString());
				listBox7->Items->RemoveAt(pos);
				listBox7->Items->Insert(pos, " ");
				break;
			}
			if (pagina->listbox == 6) {
				pos = listBox6->FindString("P " + pagina->processo->ID + " - " + pagina->processo->tam.ToString());
				listBox6->Items->RemoveAt(pos);
				listBox6->Items->Insert(pos, " ");
				break;
			}
			if (pagina->listbox == 8) {
				pos = listBox8->FindString("P " + pagina->processo->ID + " - " + pagina->processo->tam.ToString());
				listBox8->Items->RemoveAt(pos);
				listBox8->Items->Insert(pos, " ");
				break;
			}
			if (pagina->listbox == 5) {
				pos = listBox5->FindString("P " + pagina->processo->ID + " - " + pagina->processo->tam.ToString());
				listBox5->Items->RemoveAt(pos);
				listBox5->Items->Insert(pos, " ");
				break;
			}
			if (pagina->listbox == 4) {
				pos = listBox4->FindString("P " + pagina->processo->ID + " - " + pagina->processo->tam.ToString());
				listBox4->Items->RemoveAt(pos);
				listBox4->Items->Insert(pos, " ");
				break;
			}
			if (pagina->listbox == 3) {
				pos = listBox3->FindString("P " + pagina->processo->ID + " - " + pagina->processo->tam.ToString());
				listBox3->Items->RemoveAt(pos);
				listBox3->Items->Insert(pos, " ");
				break;
			}
			if (pagina->listbox == 2) {
				pos = listBox2->FindString("P " + pagina->processo->ID + " - " + pagina->processo->tam.ToString());
				listBox2->Items->RemoveAt(pos);
				listBox2->Items->Insert(pos, " ");
				break;
			}
			if (pagina->listbox == 1) {
				pos = listBox1->FindString("P " + pagina->processo->ID + " - " + pagina->processo->tam.ToString());
				listBox1->Items->RemoveAt(pos);
				listBox1->Items->Insert(pos, " ");
				break;
			}
		case 4:
			if (pagina->listbox == 3) {
				pos = listBox3->FindString("P " + pagina->processo->ID + " - " + pagina->processo->tam.ToString());
				listBox3->Items->RemoveAt(pos);
				listBox3->Items->Insert(pos, " ");
				break;
			}if (pagina->listbox == 1) {
				pos = listBox1->FindString("P " + pagina->processo->ID + " - " + pagina->processo->tam.ToString());
				listBox1->Items->RemoveAt(pos);
				listBox1->Items->Insert(pos, " ");
				break;
			}if (pagina->listbox == 2) {
				pos = listBox2->FindString("P " + pagina->processo->ID + " - " + pagina->processo->tam.ToString());
				listBox2->Items->RemoveAt(pos);
				listBox2->Items->Insert(pos, " ");
				break;
			}if (pagina->listbox == 4) {
				pos = listBox4->FindString("P " + pagina->processo->ID + " - " + pagina->processo->tam.ToString());
				listBox4->Items->RemoveAt(pos);
				listBox4->Items->Insert(pos, " ");
				break;
			}
		case 2:
			if (pagina->listbox == 1) {
				pos = listBox1->FindString("P " + pagina->processo->ID + " - " + pagina->processo->tam.ToString());
				listBox1->Items->RemoveAt(pos);
				listBox1->Items->Insert(pos, " ");
				break;
			}
			if (pagina->listbox == 2) {
				pos = listBox2->FindString("P " + pagina->processo->ID + " - " + pagina->processo->tam.ToString());
				listBox2->Items->RemoveAt(pos);
				listBox2->Items->Insert(pos, " ");
				break;
			}
		case 1:
			if (pagina->listbox == 1) {
				pos = listBox1->FindString("P " + pagina->processo->ID + " - " + pagina->processo->tam.ToString());
				listBox1->Items->RemoveAt(pos);
				listBox1->Items->Insert(pos, " ");
				break;
			}
		default:
			break;
		}
	}

	public: bool verifica_tamanho(Processo^ processo) {
		double tam_processo = System::Convert::ToDouble(processo->tam);
		int paginas = ceil(tam_processo / tam_pag);
		if ((pag_mem->Count - qtd_pag_ocu) >= paginas) {
			return true;
		}
		else
		{
			if ((tam_mem - mem_usado) >= tam_processo)
				frag_inter++;
			return false;
		}
	}

	public: void simulacao() {
		
		if (lista_proc->Count != 0 || qtd_pag_ocu != 0) {
			aux_timer = 0;
			Processo ^processo;
			unidade_tempo++;
			lb_unidade_tempo->Text = Convert::ToString(unidade_tempo);
			for (int i = 0; i < pag_mem->Count; i++) {
				if (pag_mem[i]->ocupado == true) {
					if (pag_mem[i]->processo->tempo_remove == 0) {
						pag_mem[i]->ocupado = false;
						if (pag_mem[i]->processo->tam != tam_pag)
							mem_usado -= pag_mem[i]->processo->tam;
						else
							mem_usado -= tam_pag;
						limpa_mem(pag_mem[i]);
						listBox_logSaida->Items->Insert(0, unidade_tempo + "," + pag_mem[i]->processo->ID + "," + i + ",SAIU");
						logSaida += (unidade_tempo + "," + pag_mem[i]->processo->ID + "," + i + ",SAIU\n");
						qtd_pag_ocu--;
					}
					else
					{
						pag_mem[i]->processo->tempo_remove--;
					}
				}
			}
			

			for (int i = 0; i < lista_proce_mapa->Count; i++) {
				if (lista_proce_mapa[i]->tempo_remove == 0) {
					if (lista_proce_mapa[i]->tempo_na_fila > 0)
						proc_esperaram++;
					total_tempo_fila += lista_proce_mapa[i]->tempo_na_fila;
					lista_proce_mapa->RemoveAt(i);
					i--;
				}
				else {
					lista_proce_mapa[i]->tempo_remove--;
				}
			}

			

			if (!(lista_proc->Count == 0)) {
				int aux = 0;
				Processo ^processo;
				if (modo_fila == 1) {       // se for FIFO
					while (lista_proc->Count != 0
						&& verifica_tamanho(lista_proc[0])
						&& lista_proc[0]->tempo_cria <= unidade_tempo) {

						if (lista_proc[0]->tempo_cria == unidade_tempo)
							proc_sem_esperar++;
						processo = lista_proc[0];
						
						Processo ^processo_aux = gcnew Processo();
						processo_aux->ID = processo->ID;
						processo_aux->tam = processo->tam;
						processo_aux->tempo_cria = processo->tempo_cria;
						processo_aux->tempo_remove = processo->tempo_remove;
						processo_aux->tempo_na_fila = processo->tempo_na_fila;
						lista_proce_mapa->Add(processo_aux);
						lista_proc->RemoveAt(0);
						listbox_lista_proc->Items->RemoveAt(0);
						insere_mapa(processo);
					}
				}
				else {								// se for FFit
					for (int i = 0; i < lista_proc->Count; i++) {
						if (lista_proc[i]->tempo_cria <= unidade_tempo) {
							if (verifica_tamanho(lista_proc[i])) {
								if (lista_proc[i]->tempo_cria == unidade_tempo)
									proc_sem_esperar++;
								processo = lista_proc[i];
								Processo ^processo_aux = gcnew Processo();
								processo_aux->ID = processo->ID;
								processo_aux->tam = processo->tam;
								processo_aux->tempo_cria = processo->tempo_cria;
								processo_aux->tempo_remove = processo->tempo_remove;
								processo_aux->tempo_na_fila = processo->tempo_na_fila;
								lista_proce_mapa->Add(processo_aux);
								lista_proc->RemoveAt(i);
								listbox_lista_proc->Items->RemoveAt(i);
								insere_mapa(processo);
								i--;
							}
						}
						else {
							break;
						}
					}
				}

				
				if (lista_proce_mapa->Count > maximo_proc) {
					maximo_proc = lista_proce_mapa->Count;
				}

				lb_qtd_lista_proc->Text = lista_proc->Count.ToString();


				// Media de tempo na fila
				for (int i = 0; i < lista_proc->Count; i++) {
					if (lista_proc[i]->tempo_cria <= unidade_tempo) {
						lista_proc[i]->tempo_na_fila++;
					}
					else {
						break;
					}
				}
			}



			for (int i = 0; i < pag_mem->Count; i++) {
				if (pag_mem[i]->ocupado == true) {
					if (pag_mem[i]->processo->tempo_remove == -1) {
						pag_mem[i]->ocupado = false;
						if (pag_mem[i]->processo->tam != tam_pag)
							mem_usado -= pag_mem[i]->processo->tam;
						else
							mem_usado -= tam_pag;
						listBox_logSaida->Items->Insert(0, unidade_tempo + "," + pag_mem[i]->processo->ID + "," + i + ",SAIU");
						logSaida += ( unidade_tempo + "," + pag_mem[i]->processo->ID + "," + i + ",SAIU\n");
						limpa_mem(pag_mem[i]);
						qtd_pag_ocu--;
					}
				}
			}
			for (int i = 0; i < lista_proce_mapa->Count; i++) {
				if (lista_proce_mapa[i]->tempo_remove == -1) {
					if (lista_proce_mapa[i]->tempo_na_fila > 0)
						proc_esperaram++;
					total_tempo_fila += lista_proce_mapa[i]->tempo_na_fila;
					lista_proce_mapa->RemoveAt(i);
					i--;
				}
			}
			lb_pag_livre->Text = (pag_mem->Count - qtd_pag_ocu).ToString();
			lb_qtd_mapa->Text = lista_proce_mapa->Count.ToString();

			aux_timer = 1;
		}
		else
		{
			timer1->Enabled = false;
			MessageBox::Show("Simulação concluida.");
			String^ dir;
			FolderBrowserDialog ^folderBrowserDialog1 = gcnew FolderBrowserDialog();
			if ((folderBrowserDialog1->ShowDialog()) == System::Windows::Forms::DialogResult::OK) {
				dir = folderBrowserDialog1->SelectedPath;
				try {
					StreamWriter ^arq = gcnew StreamWriter(dir + "\\resultado da simulação.csv");
					arq->Write(logSaida, false);
					arq->Close();
				}
				catch (Exception ^e) {
					MessageBox::Show(e->Message);
				}
				
			}
			lb_precisam_esperar->Text = proc_esperaram.ToString();
			lb_nao_espera->Text = proc_sem_esperar.ToString();
			lb_maximo_proc->Text = maximo_proc.ToString();
			float aux = total_tempo_fila / this->qtd_proc;
			lb_tempo_de_espera_geral->Text = floorf((aux * 100) / 100).ToString();
			if (proc_esperaram != 0) {
				aux = total_tempo_fila / this->proc_esperaram;
				lb_tempo_espera_parcial->Text = floorf((aux * 100) / 100).ToString();
			} 
			else
				lb_tempo_espera_parcial->Text = "0";

			lb_frag_interna->Text = frag_inter.ToString();

			
			groupBox1->Visible = true;
			button2->Enabled = false;
			button2->Text = "Iniciar";
			button3->Enabled = true;
		}
	}


	private:  vector<string> explode(string s, char c)
	{
		string buff{ "" };
		vector<string> v;

		for (auto n : s)
		{
			if (n != c) buff += n; else
				if (n == c && buff != "") { v.push_back(buff); buff = ""; }
		}
		if (buff != "") v.push_back(buff);

		return v;
	}



	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		if (aux_timer == 1) {
			timer1->Interval = 5000 / System::Convert::ToInt32(numericUpDown1->Value);
			simulacao();
		}
	}
	private: System::Void button2_Click_1(System::Object^  sender, System::EventArgs^  e) {
		if (button2->Text == "Iniciar" || button2->Text == "Continuar") {
			button2->Text = "pausar";
			button3->Enabled = false;
			timer1->Enabled = true;

		}
		else {
			button2->Text = "Continuar";
			button3->Enabled = true;
			timer1->Enabled = false;
		}
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		timer1->Enabled = false;
		pag_mem->Clear();
		lista_proc->Clear();
		lista_proce_mapa->Clear();
		listbox_lista_proc->Items->Clear();
		listBox1->Items->Clear();
		listBox2->Items->Clear();
		listBox3->Items->Clear();
		listBox4->Items->Clear();
		listBox5->Items->Clear();
		listBox6->Items->Clear();
		listBox7->Items->Clear();
		listBox8->Items->Clear();
		aux_timer = 1;
		qtd_pag_ocu = 0;
		unidade_tempo = 0;
		qtd_listBox = 0;
		maximo_proc = 0;
		proc_esperaram = 0;
		proc_sem_esperar = 0;
		button2->Enabled = true;
		groupBox1->Visible = false;
		qtd_proc = 0;
		total_tempo_fila = 0;
		mem_usado = 0;
		frag_inter = 0;
		logSaida = "";

		this->InitializaVariaveis(diretorio, tam_pag.ToString(), tam_mem.ToString(), modo_fila);
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		timer1->Enabled = false;
		this->Close();
	}
};
}