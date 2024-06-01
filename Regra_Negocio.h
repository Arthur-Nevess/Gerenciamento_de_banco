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
void separa(char dados[120]);
void valida_nome();
void valida_conta();
void cadastro();
void configurar_terminal();
void restaurar_terminal();



