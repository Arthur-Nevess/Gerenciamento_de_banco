#define TAM 50
struct tipos_dados      
{
    char nome [TAM];
    char cpf  [TAM];
    char conta[TAM];
    char senha[TAM];
    char tipo [TAM];

};
typedef struct tipos_dados informações;

struct index
{
    int nome_a;
    int cpf_a;
    int conta_a;
    int senha_a;
    int tipo_a;
    
};
typedef struct index inde;


void contaExiste();
void separa (char file[10],char tipo[10]);
void valida_nome();
void valida_conta();
void cadastro();
void configurar_terminal();
void restaurar_terminal();
void valida_tipo(int valida);
void visual_cpf();
void valida_cpf();



