# GardianAI

Grupo: 
- João José Domingues Silva,
- Laís Kondo Claus,
- Lucas Alves Ladeira,
- Murilo Santana e
- Willian Augusto Ferreira.

# Introdução ao Projeto
Este projeto foi desenvolvido como parte do desafio proposto pela Hermes Reply, focado na aplicação de soluções digitais para a Indústria 4.0. O objetivo principal é simular um sistema de monitoramento inteligente de equipamentos, replicando o processo de coleta e análise de dados em um ambiente industrial.
No contexto da Indústria 4.0, a capacidade de monitorar variáveis ambientais como temperatura e umidade em tempo real é fundamental. Variações nesses parâmetros podem indicar desde a degradação da performance de um maquinário até um risco iminente de falha, que pode levar a paradas não programadas e custos elevados de manutenção.
Para simular este cenário, utilizamos uma abordagem de prototipagem virtual, que permite validar o hardware, o software e o fluxo de dados sem a necessidade de componentes físicos. Este trabalho abrange a criação de um circuito com o microcontrolador ESP32, a programação para leitura de um sensor, a coleta dos dados gerados e uma análise exploratória inicial para extrair insights.

# Ferramentas e Sensores Utilizados
# Plataforma de Simulação: Wokwi
Para a realização deste projeto, a plataforma escolhida foi o Wokwi. A justificativa para essa escolha se baseia nos seguintes pontos:
Acessibilidade e Facilidade de Uso: O Wokwi é uma plataforma online e gratuita que não exige a instalação de nenhum software complexo. Basta um navegador web para começar a projetar circuitos e codificar.
Simulação em Tempo Real: Ele oferece uma simulação fiel e em tempo real do comportamento do ESP32 e dos componentes conectados, incluindo um Monitor Serial funcional, essencial para a coleta de dados.
Foco no Desafio: Como o objetivo do desafio é entender o fluxo de dados (coleta, leitura e análise), o Wokwi permite focar na lógica de programação e na integração dos componentes, abstraindo as complexidades de uma montagem física.
# Sensor Virtual: DHT22 - Sensor de Temperatura e Umidade
O sensor escolhido para esta simulação foi o DHT22 (ou seu similar DHT11). A escolha é justificada por sua relevância direta com o cenário industrial proposto:
Relevância Industrial: O controle de temperatura e umidade é crítico em diversos contextos industriais. O superaquecimento de motores, painéis elétricos ou servidores pode ser um indicador precoce de falha. Da mesma forma, a umidade elevada pode causar corrosão e danificar componentes eletrônicos sensíveis.
Simplicidade de Integração: O sensor é fácil de programar e integrar com o ESP32, possuindo bibliotecas amplamente disponíveis e documentadas, o que facilita o desenvolvimento.
Simulação de Dados Realistas: Monitorar a temperatura e a umidade permite simular um cenário prático e gerar dados que variam ao longo do tempo, tornando a análise exploratória mais rica e representativa de um caso de uso real. Através deste sensor, é possível, por exemplo, simular o aquecimento de uma máquina durante seu ciclo de operação.

# Imagens da simulação do circuito (prints da plataforma usada):
![image](https://github.com/user-attachments/assets/5ec60588-c90e-460a-87be-1c46f369342b)

![image](https://github.com/user-attachments/assets/1cc44006-5de3-4a9a-900a-c49d6ef60427)

# Código-Fonte Comentado
O código abaixo foi desenvolvido para o microcontrolador ESP32 e tem como função realizar leituras contínuas de temperatura e umidade a partir de um sensor DHT22. Os dados são formatados em CSV e enviados pela comunicação serial para que possam ser facilmente capturados e analisados.
// --- Bibliotecas ---
// Importa a biblioteca DHTesp.h, que é otimizada para a família de microcontroladores ESP
// e facilita a comunicação com sensores da linha DHT (DHT11, DHT22).
#include "DHTesp.h"

// --- Constantes e Variáveis Globais ---
// Define a constante 'DHT_PIN' para o pino GPIO 15, onde o pino de dados 
// do nosso sensor DHT22 está fisicamente conectado.
const int DHT_PIN = 15;

// Inicializa uma variável para servir como contador e identificador único (ID) para cada leitura.
int IdLeitura = 0;

// Cria uma instância (objeto) da classe DHTesp. Este objeto, chamado 'dhtSensor', 
// será usado para interagir com o sensor físico.
DHTesp dhtSensor;

// --- Função de Configuração Inicial (executada uma vez) ---
void setup() {
  // Inicia a comunicação serial a uma velocidade de 115200 bps. 
  // Esta é a "ponte" para enviar os dados do ESP32 para o computador.
  Serial.begin(115200);

  // Inicializa o sensor, informando ao objeto qual pino ele deve usar (DHT_PIN)
  // e qual o tipo de sensor (neste caso, DHT22).
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);

  // Imprime o cabeçalho no Monitor Serial. Este formato (CSV) define as colunas
  // para facilitar a importação dos dados em planilhas ou softwares de análise.
  Serial.println("ID,Timestamp_s,Temperature_C,Humidity_%");
}

// --- Função de Loop (executada continuamente) ---
void loop() {
  // Solicita ao sensor uma nova leitura de temperatura e umidade.
  // O resultado é armazenado na estrutura 'data', que contém os dois valores.
  TempAndHumidity data = dhtSensor.getTempAndHumidity();

  // A linha abaixo formata os dados lidos em uma única string no formato CSV e a imprime no Monitor Serial.
  // A saída gerada é: ID,Temperatura,Umidade
  // Nota: O campo 'Timestamp_s' (timestamp em segundos) definido no cabeçalho não é gerado nesta versão.
  // Para implementá-lo, poderíamos usar a função millis() / 1000.
  Serial.println(String(IdLeitura) + "," + String(data.temperature, 2) + "," + String(data.humidity, 1));
  
  // Incrementa o contador de ID para a próxima leitura.
  IdLeitura++;

  // Pausa a execução do código por 2 segundos (2000 milissegundos).
  // Isso cria um intervalo entre as leituras, evitando sobrecarregar o sensor,
  // já que o DHT22 tem uma taxa de amostragem de aproximadamente 0.5Hz (uma leitura a cada 2 segundos).
  delay(2000); 
}

Link para acesso ao Wokwik do grupo: https://wokwi.com/projects/433502439922852865

# Comportamento da Simulação (Monitor Serial)

Para documentar o funcionamento do sistema, foi capturado o resultado da simulação na plataforma Wokwi. A imagem abaixo ilustra o Monitor Serial após o início da execução do código no ESP32.
O monitor exibe, na primeira linha, o cabeçalho no formato CSV (ID,Timestamp_s,Temperature_C,Humidity_%) que foi definido na função setup(). Em seguida, a cada 2 segundos, uma nova linha de dados é impressa, contendo o ID da leitura, o valor da temperatura em Graus Celsius (°C) e a umidade relativa do ar (%).
Exemplo de Saída do Monitor Serial:

![image](https://github.com/user-attachments/assets/27d0a4b1-6c5c-4017-9a8d-1c17445c1eb7)

# Gráficos e Insights da Análise Exploratória
A partir dos dados coletados do Monitor Serial e salvos em formato CSV, foi realizada uma análise exploratória inicial. O objetivo é visualizar o comportamento das variáveis monitoradas ao longo do tempo para identificar padrões ou anomalias.
Tipo de Gráfico Gerado: Gráfico de Linhas
Foi gerado um gráfico de linhas para visualizar a variação da Temperatura (°C) e da Umidade (%) ao longo das leituras. Este tipo de gráfico é ideal para dados de séries temporais, pois permite observar tendências, picos e vales de forma clara e intuitiva. O eixo X representa o ID da Leitura (que funciona como uma linha do tempo), e o eixo Y representa os valores medidos.
![image](https://github.com/user-attachments/assets/058ba52e-52b0-4ad6-a22d-5c7bed49afa0)

Link: https://colab.research.google.com/drive/17IyiR4rtvAjrFtwomTX8NzhjeQLSC6kw?usp=sharing

Conclusão da Análise: A simulação, mesmo que simples, demonstra o poder do monitoramento contínuo. A capacidade de visualizar dados em tempo real permite a transição de uma manutenção reativa (consertar após a quebra) para uma manutenção preditiva, onde é possível agir antes que a falha ocorra, com base nas tendências observadas.

# Explicações sobre o Funcionamento do Sistema
Este projeto simula um sistema de monitoramento de condições ambientais para aplicações na Indústria 4.0, utilizando um microcontrolador ESP32 e um sensor de temperatura e umidade DHT22. O funcionamento do sistema segue um fluxo lógico, desde a montagem virtual até a coleta de dados.

1. Montagem do Circuito Virtual
O sistema foi montado na plataforma de simulação Wokwi. O circuito consiste em:

Um ESP32, o cérebro do sistema, responsável por executar o código.
Um sensor DHT22, conectado ao pino GPIO 15 do ESP32 para fornecer as leituras de temperatura e umidade.
2. Execução do Software Embarcado
O código-fonte, escrito em C++ com o framework Arduino, executa duas funções principais:

setup(): É executada uma única vez quando o ESP32 é ligado. Ela inicializa a comunicação serial (para enviar dados ao computador) e configura o sensor DHT22. Crucialmente, ela imprime o cabeçalho do nosso arquivo de dados (ID,Timestamp_s,Temperature_C,Humidity_%), preparando o terreno para a coleta em formato CSV.
loop(): É executada continuamente. A cada ciclo, ela:
Solicita ao sensor uma nova leitura de temperatura e umidade.
Formata os dados recebidos em uma string separada por vírgulas.
Imprime essa string no Monitor Serial.
Aguarda por 2 segundos (delay(2000)) antes de iniciar um novo ciclo.
3. Coleta e Análise dos Dados
O fluxo de dados gerado no Monitor Serial é a saída final do nosso sistema de coleta. Para a análise:

Os dados do Monitor Serial são selecionados, copiados e colados em um arquivo de texto.
Este arquivo é salvo com a extensão .csv.
O arquivo .csv é importado em uma ferramenta de análise (como Microsoft Excel, Google Sheets ou um script Python com as bibliotecas Pandas e Matplotlib) para a geração de gráficos e a extração de insights.

# Conclusão
A conclusão deste projeto demonstra a validação bem-sucedida de uma Prova de Conceito (PoC) para o monitoramento de ativos industriais, atendendo plenamente aos objetivos propostos pela Hermes Reply. Foi simulado com sucesso o fluxo de dados completo — da coleta com sensores virtuais (DHT22) e um sistema embarcado (ESP32) até a análise exploratória inicial. Este protótipo funcional serve como uma base sólida e de baixo custo para o desenvolvimento de soluções de manutenção preditiva mais complexas e escaláveis, prontas para integração com plataformas de nuvem e algoritmos de Inteligência Artificial.
