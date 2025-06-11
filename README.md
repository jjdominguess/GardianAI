# GardianAI
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

![image](https://github.com/user-attachments/assets/5ec60588-c90e-460a-87be-1c46f369342b)
